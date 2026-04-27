/*******************************************************
 Copyright (C) 2013,2014 Guan Lisheng (guanlisheng@gmail.com)
 Copyright (C) 2022,2025 Mark Whalley (mark@ipx.co.uk)
 Copyright (C) 2026 George Ef (george.a.ef@gmail.com)

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 ********************************************************/

#include "StockModel.h"

#include "StockHistoryModel.h"
#include "TrxLinkModel.h"
#include "TrxShareModel.h"
#include "CurrencyHistoryModel.h"

// -- static

const RefTypeN StockModel::s_ref_type = RefTypeN(RefTypeN::e_stock);

// -- constructor

// Initialize the global StockModel table.
// Reset the StockModel table or create the table if it does not exist.
StockModel& StockModel::instance(wxSQLite3Database* db)
{
    StockModel& ins = Singleton<StockModel>::instance();
    ins.reset_cache();
    ins.m_db = db;
    ins.ensure_table();

    return ins;
}

// Return the static instance of StockModel table
StockModel& StockModel::instance()
{
    return Singleton<StockModel>::instance();
}

// -- override

// FIXME
bool StockModel::find_id_isUsed(int64 stock_id, [[maybe_unused]] bool ignore_deleted)
{
    // FIXME: use ignore_deleted
    return TrxLinkModel::instance().find_count(
        TrxLinkCol::WHERE_LINKTYPE(OP_EQ, s_ref_type.key_n()),
        TrxLinkCol::WHERE_LINKRECORDID(OP_EQ, stock_id)
    );
}

bool StockModel::purge_id(int64 stock_id)
{
    bool ok = true;
    db_savepoint();

    const wxString symbol = get_id_symbol(stock_id);

    ok = ok && AttachmentModel::instance().purge_ref_all(s_ref_type, stock_id);
    ok = ok && unsafe_remove_id(stock_id);

    if (find_count(
        StockCol::WHERE_SYMBOL(OP_EQ, symbol)
    ) == 0) {
        ok = ok && StockHistoryModel::instance().purge_symbol_all(symbol);
    }

    db_release_savepoint();
    return ok;
}

// -- methods

bool StockModel::purge_id_dep(int64 stock_id)
{
    bool ok = true;
    db_savepoint();

    for (const TrxLinkData& tl_d : TrxLinkModel::instance().find_data_a(
        TrxLinkCol::WHERE_LINKTYPE(OP_EQ, StockModel::s_ref_type.key_n()),
        TrxLinkCol::WHERE_LINKRECORDID(OP_EQ, stock_id)
    )) {
        // Remove the link before the transaction,
        // otherwise update_data_position() is called.
        ok = ok && TrxLinkModel::instance().purge_id(tl_d.m_id);
        // TODO: check if transaction is_foreign()
        // TrxShareData records are removed together with the transaction
        ok = ok && TrxModel::instance().purge_id(tl_d.m_trx_id);
    }

    db_release_savepoint();
    return ok;
}

const wxString StockModel::get_id_name(int64 stock_id)
{
    const Data* stock_n = get_idN_data_n(stock_id);
    return stock_n ? stock_n->m_name : _t("Stock Error");
}

const wxString StockModel::get_id_symbol(int64 stock_id)
{
    const Data* stock_n = get_idN_data_n(stock_id);
    return stock_n ? stock_n->m_symbol : "";
}

// Return the last price date of a given stock
mmDate StockModel::find_last_hist_date(const Data& stock_d)
{
    mmDate date = stock_d.m_purchase_date;
    for (const StockHistoryData& sh_d : StockHistoryModel::instance().find_data_a(
        StockCol::WHERE_SYMBOL(OP_EQ, stock_d.m_symbol),
        TableClause::ORDERBY(StockHistoryCol::NAME_DATE, true),
        TableClause::LIMIT(1)
    )) {
        date = sh_d.m_date;
        break;
    }

    return date;
}

// Return the total stock balance at a given date
double StockModel::calculate_account_balance(const AccountData& account_d, const mmDate& date)
{
    double balance = 0.0;

    for (const Data& stock_d : find_data_a(
        StockCol::WHERE_HELDAT(OP_EQ, account_d.m_id)
    )) {
        mmDateN prev_date; double prev_price = 0.0;
        mmDateN next_date; //double next_price = 0.0;
        for (const StockHistoryData& sh_d : StockHistoryModel::instance().find_data_a(
            StockCol::WHERE_SYMBOL(OP_EQ, stock_d.m_symbol),
            TableClause::ORDERBY(StockHistoryCol::NAME_DATE, true)
        )) {
            // stop if the exact date is found
            if (sh_d.m_date == date) {
                prev_date = sh_d.m_date; prev_price = sh_d.m_price;
                next_date = sh_d.m_date; //next_price = sh_d.m_price;
                break;
            }
            // stop at the first past date
            if (sh_d.m_date < date) {
                prev_date = sh_d.m_date; prev_price = sh_d.m_price;
                break;
            }
            // scan all future dates
            if (sh_d.m_date > date) {
                next_date = sh_d.m_date; //next_price = sh_d.m_price;
            }
        }
        // if no previous date is found, fallback to purchase date and price
        if (!prev_date.has_value() && stock_d.m_purchase_date <= date) {
            prev_date = stock_d.m_purchase_date;
            prev_price = stock_d.m_purchase_price;
        }
        //  if no next date is found and the account is open, fallback to previous
        if (!next_date.has_value() && account_d.is_open()) {
            next_date = prev_date; //next_price = prev_price;
        }
        // if previous and next date is still not found, skip this stock
        if (!prev_date.has_value() || prev_date.value() < stock_d.m_purchase_date ||
            !next_date.has_value() || next_date.value() < stock_d.m_purchase_date
        ) {
            continue;
        }
        // take the previous price
        double price = prev_price;

        double num_shares = 0.0;
        TrxLinkModel::DataA tl_a = TrxLinkModel::instance().find_ref_data_a(
            s_ref_type, stock_d.m_id
        );
        for (const TrxLinkModel::Data& tl_d : tl_a) {
            const TrxData* trx_n = TrxModel::instance().get_idN_data_n(
                tl_d.m_trx_id
            );
            if (trx_n && trx_n->m_id > 0 &&
                // CHECK: ignore Void transactions
                !trx_n->is_deleted() &&
                trx_n->m_date() <= date
            ) {
                const TrxShareData* ts_n = TrxShareModel::instance().get_trxId_data_n(
                    tl_d.m_trx_id
                );
                if (ts_n)
                    num_shares += ts_n->m_number;
            }
        }
        if (tl_a.empty() && stock_d.m_purchase_date <= date)
            num_shares = stock_d.m_num_shares;

        balance += num_shares * price;
    }

    return balance;
}

// Returns the realized gain/loss of the stock due to sold shares.
// If the optional parameter to_base_curr = true is passed values are converted
// to base currency.
double StockModel::calculate_realized_gain(const Data& stock_d, bool to_base_curr)
{
    // retrieve currency data only if needed
    const CurrencyData* currency_n = nullptr;
    if (to_base_curr)
        currency_n = AccountModel::instance().get_id_currency_p(stock_d.m_account_id_n);

    double realized_gain = 0;  // positive means gain, negative means loss
    double total_shares = 0;
    double total_initial_value = 0;
    double avg_share_price = 0;
    double conv_rate = 1;

    TrxModel::DataA trx_a;
    for (const auto& tl_d : TrxLinkModel::instance().find_ref_data_a(
        s_ref_type, stock_d.m_id
    )) {
        const TrxData* trx_n = TrxModel::instance().get_idN_data_n(
            tl_d.m_trx_id
        );
        if (trx_n && trx_n->m_id > 0 &&
            // FIXME: ignore void transactions
            !trx_n->is_deleted()
        )
            trx_a.push_back(*trx_n);
    }
    if (PrefModel::instance().getUseTransDateTime())
        std::sort(trx_a.begin(), trx_a.end(), TrxData::SorterByDateTimeId());
    else
        std::sort(trx_a.begin(), trx_a.end(), TrxData::SorterByDateId());

    for (const TrxData& trx_d : trx_a) {
        const TrxShareData* ts_n = TrxShareModel::instance().get_trxId_data_n(
            trx_d.m_id
        );
        if (!ts_n)
            continue;

        // only long positions are supported
        // TODO: support short positions
        total_shares += ts_n->m_number;
        if (total_shares < 0)
            total_shares = 0;

        if (to_base_curr) {
            conv_rate = CurrencyHistoryModel::instance().get_id_date_rate(
                currency_n->m_id,
                trx_d.m_date()
            );
        }
        if (ts_n->m_number > 0) {
            // BUY
            total_initial_value += (
                ts_n->m_number * ts_n->m_price + ts_n->m_commission
            ) * conv_rate;
        }
        else {
            // SELL
            total_initial_value += ts_n->m_number * avg_share_price;
            realized_gain +=
                (-ts_n->m_number) * (ts_n->m_price * conv_rate - avg_share_price) -
                ts_n->m_commission * conv_rate;
        }

        if (total_initial_value < 0)
            total_initial_value = 0;

        avg_share_price = (total_shares > 0)
            ? total_initial_value / total_shares
            : 0.0;
    }

    return realized_gain;
}

// Returns the current unrealized gain/loss.
// If the optional parameter to_base_curr = true is passed values are converted
// to base currency.
double StockModel::calculate_unrealiazed_gain(const Data& stock_d, bool to_base_curr)
{
    if (!to_base_curr)
        return stock_d.current_value() - stock_d.m_purchase_value;

    const CurrencyData* currency_n = AccountModel::instance().get_id_currency_p(
        stock_d.m_account_id_n
    );
    double conv_rate = CurrencyHistoryModel::instance().get_id_date_rate(
        currency_n->m_id
    );
    TrxLinkModel::DataA tl_a = TrxLinkModel::instance().find_ref_data_a(
        s_ref_type, stock_d.m_id
    );
    if (!tl_a.empty()) {
        double total_shares = 0;
        double total_initial_value = 0;
        double avg_share_price = 0;

        TrxModel::DataA trx_a;
        for (const auto& tl_d : tl_a) {
            const TrxData* trx_d = TrxModel::instance().get_idN_data_n(
                tl_d.m_trx_id
            );
            if (trx_d && trx_d->m_id > 0 &&
                // FIXME: ignore void transactions
                !trx_d->is_deleted()
            )
                trx_a.push_back(*trx_d);
        }
        if (PrefModel::instance().getUseTransDateTime())
            std::sort(trx_a.begin(), trx_a.end(), TrxData::SorterByDateTimeId());
        else
            std::sort(trx_a.begin(), trx_a.end(), TrxData::SorterByDateId());

        for (const auto& trx_d : trx_a) {
            const TrxShareData* ts_d = TrxShareModel::instance().get_trxId_data_n(
                trx_d.m_id
            );
            conv_rate = CurrencyHistoryModel::instance().get_id_date_rate(
                currency_n->m_id,
                trx_d.m_date()
            );
            total_shares += ts_d->m_number;
            if (total_shares < 0) total_shares = 0;

            if (ts_d->m_number > 0) {
                total_initial_value += (
                    ts_d->m_number * ts_d->m_price + ts_d->m_commission
                ) * conv_rate;
            }
            else {
                total_initial_value += ts_d->m_number * avg_share_price;
            }

            if (total_initial_value < 0) total_initial_value = 0;
            if (total_shares > 0) avg_share_price = total_initial_value / total_shares;
        }
        conv_rate = CurrencyHistoryModel::instance().get_id_date_rate(
            currency_n->m_id
        );
        return stock_d.current_value() * conv_rate - total_initial_value;
    }
    else {
        return (stock_d.current_value() - stock_d.m_purchase_value) * conv_rate;
    }
}

// Updates the current price across all accounts which hold the stock
// TODO: use std::optional<double> price
void StockModel::update_symbol_current_price(const wxString& symbol, double price)
{
    double current_price = price;
    if (current_price == -1) {
        for (const StockHistoryData& sh_d : StockHistoryModel::instance().find_data_a(
            StockHistoryCol::WHERE_SYMBOL(OP_EQ, symbol),
            TableClause::ORDERBY(StockHistoryCol::NAME_DATE, true),
            TableClause::LIMIT(1)
        )) {
            current_price = sh_d.m_price;
            break;
        }
    }
    if (current_price == -1)
        return;

    for (Data& stock_d : find_data_a(
        StockCol::WHERE_SYMBOL(OP_EQ, symbol)
    )) {
        stock_d.m_current_price = current_price;
        update_data_n(stock_d);
    }
}

// stock_entry.m_purchase_price = avg price of shares purchased.
// stock_entry.m_num_shares = total amount of shares purchased.
// stock_entry.VALUE     = value of shares based on:
// ... share_entry.SHARENUMBER * share_entry.SHAREPRICE
void StockModel::update_data_position(StockData* stock_n)
{
    TrxLinkModel::DataA tl_a = TrxLinkModel::instance().find_ref_data_a(
        s_ref_type, stock_n->m_id
    );
    double total_shares = 0;
    double total_initial_value = 0;
    double total_commission = 0;
    double avg_share_price = 0;
    mmDate min_trx_date = mmDate::today();
    TrxModel::DataA trx_a;
    for (const auto& tl_d : tl_a) {
        const TrxData* trx_n = TrxModel::instance().get_idN_data_n(tl_d.m_trx_id);
        if (trx_n && trx_n->m_id > 0 && trx_n->is_valid()) {
            trx_a.push_back(*trx_n);
        }
    }
    if (PrefModel::instance().getUseTransDateTime())
        std::sort(trx_a.begin(), trx_a.end(), TrxData::SorterByDateTimeId());
    else
        std::sort(trx_a.begin(), trx_a.end(), TrxData::SorterByDateId());

    for (const auto& trx_d : trx_a) {
        const TrxShareData* ts_n = TrxShareModel::instance().get_trxId_data_n(
            trx_d.m_id
        );

        total_shares += ts_n->m_number;
        if (total_shares < 0)
            total_shares = 0;

        if (ts_n->m_number > 0)
            total_initial_value += ts_n->m_number * ts_n->m_price + ts_n->m_commission;
        else
            total_initial_value += ts_n->m_number * avg_share_price;

        if (total_initial_value < 0)
            total_initial_value = 0;
        if (total_shares > 0)
            avg_share_price = total_initial_value / total_shares;

        total_commission += ts_n->m_commission;

        mmDate trx_date = trx_d.m_date();
        if (trx_date < min_trx_date)
            min_trx_date = trx_date;
    }

    // The stock record contains the total of share transactions.
    if (tl_a.empty()) {
        stock_n->m_purchase_price = stock_n->m_current_price;
    }
    else {
        //wxDateTime purchasedate;
        stock_n->m_purchase_date  = min_trx_date;
        stock_n->m_purchase_price = avg_share_price;
        stock_n->m_num_shares     = total_shares;
        stock_n->m_purchase_value = total_initial_value;
        stock_n->m_commission     = total_commission;
    }
    unsafe_save_data_n(stock_n);
}
