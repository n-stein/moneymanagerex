/*******************************************************
 Copyright (C) 2013,2014 Guan Lisheng (guanlisheng@gmail.com)
 Copyright (C) 2022 Mark Whalley (mark@ipx.co.uk)

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

#include "Model_Stock.h"
#include "Model_StockHistory.h"
#include "Model_Translink.h"
#include "Model_Shareinfo.h"
#include "Model_CurrencyHistory.h"

Model_Stock::Model_Stock()
: Model<DB_Table_STOCK_V1>()
{
}

Model_Stock::~Model_Stock()
{
}

/**
* Initialize the global Model_Stock table.
* Reset the Model_Stock table or create the table if it does not exist.
*/
Model_Stock& Model_Stock::instance(wxSQLite3Database* db)
{
    Model_Stock& ins = Singleton<Model_Stock>::instance();
    ins.db_ = db;
    ins.destroy_cache();
    ins.ensure(db);

    return ins;
}

wxString Model_Stock::get_stock_name(int64 stock_id)
{
    Data* stock = instance().get(stock_id);
    Model_Ticker::Data* ticker = Model_Ticker::instance().get(stock->TICKERID);
    if (ticker)
        return ticker->NAME;
    else
        return _("Stock Error");
}

/** Return the static instance of Model_Stock table */
Model_Stock& Model_Stock::instance()
{
    return Singleton<Model_Stock>::instance();
}

wxDate Model_Stock::PURCHASEDATE(const Data* stock)
{
    return Model::to_date(stock->PURCHASEDATE);
}

wxDate Model_Stock::PURCHASEDATE(const Data& stock)
{
    return Model::to_date(stock.PURCHASEDATE);
}

/** Original value of Stocks */
double Model_Stock::InvestmentValue(const Data* r)
{
    Model_StockStat s = Model_StockStat(r->TICKERID, r->HELDAT);
    return s.get_cost_ticker_curr();
}

/** Original value of Stocks */
double Model_Stock::InvestmentValue(const Data& r)
{
    return InvestmentValue(&r);
}

double Model_Stock::CurrentValue(const Data* r)
{
    Model_StockStat s = Model_StockStat(r->TICKERID, r->HELDAT);
    Model_Ticker::Data* t = Model_Ticker::instance().get(r->TICKERID);
    return s.get_total_shares() * t->CURRENTPRICE;
}

double Model_Stock::CurrentValue(const Data& r)
{
    return CurrentValue(&r);
}

/**
Returns the last price date of a given stock
*/
wxString Model_Stock::lastPriceDate(const Self::Data* entity)
{
    wxString dtStr = entity->PURCHASEDATE;
    Model_StockHistory::Data_Set histData = Model_StockHistory::instance().find(Model_StockHistory::SYMBOL(Model_Ticker::get_ticker_symbol(entity->TICKERID)));

    std::sort(histData.begin(), histData.end(), SorterByDATE());
    if (!histData.empty())
        dtStr = histData.back().DATE;

    return dtStr;
}

/**
Returns the total stock balance at a given date
*/
double Model_Stock::getDailyBalanceAt(const Model_Account::Data *account, const wxDate& date)
{
    wxString strDate = date.FormatISODate();
    std::map<int64, double> totBalance;

    std::map<int64, Model_StockHistory::Data_Set> tickers; 
    for (const auto & tickerId : Model_Account::getTickerIds(account->ACCOUNTID))
    {
        Model_StockStat s = Model_StockStat(tickerId, account->ACCOUNTID, account->CURRENCYID, date);

        if (strDate < s.get_init_date())
            continue;

        Model_StockHistory::Data_Set stock_hist;
        if (tickers.find(tickerId) != tickers.end())
            stock_hist = tickers[tickerId];
        else
        {
            stock_hist = Model_StockHistory::instance().find(Model_StockHistory::SYMBOL(Model_Ticker::get_ticker_symbol(tickerId)));
            std::stable_sort(stock_hist.begin(), stock_hist.end(), SorterByDATE());
            std::reverse(stock_hist.begin(), stock_hist.end());
            tickers[tickerId] = stock_hist;
        }

        wxString precValueDate, nextValueDate;

        double valueAtDate = 0.0,  precValue = 0.0, nextValue = 0.0;

        for (const auto & hist : stock_hist)
        {
            // test for the date requested
            if (hist.DATE == strDate)
            {
                valueAtDate = hist.VALUE;
                break;
            }
            // if not found, search for previous and next date
            if (precValue == 0.0 && hist.DATE < strDate)
            {
                precValue = hist.VALUE;
                precValueDate = hist.DATE;
            }
            if (hist.DATE > strDate)
            {
                nextValue = hist.VALUE;
                nextValueDate = hist.DATE;
            }
            // end conditions: prec value assigned and price date < requested date
            if (precValue != 0.0 && hist.DATE < strDate)
                break;
        }

        if (valueAtDate == 0.0)
        {
            //  if previous not found but if the given date is after purchase date, takes purchase price
            if (precValue == 0.0 && strDate >= s.get_init_date())
            {
                precValue = s.get_avg_price_ticker_curr();
                precValueDate = s.get_init_date();
            }
            //  if next not found and the accoung is open, takes previous date
            if (nextValue == 0.0 && Model_Account::status_id(account) == Model_Account::STATUS_ID_OPEN)
            {
                nextValue = precValue;
                nextValueDate = precValueDate;
            }
            if (precValue > 0.0 && nextValue > 0.0 && precValueDate >= s.get_init_date() && nextValueDate >= s.get_init_date())
                valueAtDate = precValue;
        }

        double numShares = s.get_total_shares();
        double conv_rate = Model_CurrencyHistory::getDayRate(Model_Ticker::instance().get(tickerId)->CURRENCYID, date) /
                           Model_CurrencyHistory::getDayRate(account->CURRENCYID, date);
        totBalance[tickerId] += numShares * valueAtDate * conv_rate;
    }

    double balance = 0.0;
    for (const auto& it : totBalance)
        balance += it.second;

    return balance;
}

/**
Returns the realized gain/loss of the stock due to sold shares.
If the optional parameter to_base_curr = true is passed values are converted
to base currency.
*/
double Model_Stock::RealGainLoss(const Data* r, bool to_base_curr)
{
    Model_StockStat s = Model_StockStat(r->TICKERID, r->HELDAT);
    return (to_base_curr ? s.get_real_gain_target_curr() : s.get_real_gain_ticker_curr());
}

/**
Returns the realized gain/loss of the stock due to sold shares.
If the optional parameter to_base_curr = true is passed values are converted
to base currency.
*/
double Model_Stock::RealGainLoss(const Data& r, bool to_base_curr)
{
    return RealGainLoss(&r, to_base_curr);
}

/**
Returns the current unrealized gain/loss.
If the optional parameter to_base_curr = true is passed values are converted
to base currency.
*/
double Model_Stock::UnrealGainLoss(const Data& r, bool to_base_curr)
{
    return UnrealGainLoss(&r, to_base_curr);
}

/**
Returns the current unrealized gain/loss.
If the optional parameter to_base_curr = true is passed values are converted
to base currency.
*/
double Model_Stock::UnrealGainLoss(const Data* r, bool to_base_curr)
{
    Model_StockStat s = Model_StockStat(r->TICKERID, r->HELDAT);
    return (to_base_curr ? s.get_unreal_gain_target_curr() : s.get_unreal_gain_ticker_curr());
}

// ------------------------------------------

Model_StockStat::~Model_StockStat()
{
}

Model_StockStat::Model_StockStat(int64 ticker_id, int64 accountID, int64 currencyID, wxDate date)
{
    if (currencyID < 0)
        currencyID = Model_Currency::GetBaseCurrency()->CURRENCYID;

    Model_Account::Data* a = Model_Account::instance().get(accountID);
    Model_Ticker::Data* t = Model_Ticker::instance().get(ticker_id);
    Model_Stock::Data_Set s = Model_Stock::instance().find(Model_Stock::HELDAT(a ? a->ACCOUNTID : -1), Model_Stock::TICKERID(t ? t->TICKERID : -1));
    std::stable_sort(s.begin(), s.end(), SorterByPURCHASEDATE());

    m_total_cost = 0.0;
    m_average_price = 0.0;
    m_real_gain = 0.0;
    m_unreal_gain = 0.0;
    m_real_gain_tgt_curr = 0.0;
    m_unreal_gain_tgt_curr = 0.0;
    m_total_shares = 0.0;
    m_total_cost_tgt_curr = 0.0;
    m_commission = 0.0;
    m_init_date = wxDate::Today().FormatISODate();

    std::vector<std::pair<double, double>> fx_rate_factors;
    double target_conv_rate = 1;

    for (const auto& item : s)
    {
        if (item.PURCHASEDATE > date.FormatISODate())
            break;

        if (m_init_date >= item.PURCHASEDATE)
        {
            m_init_date = item.PURCHASEDATE;
        }

        if (t->CURRENCYID != currencyID)
            target_conv_rate = Model_CurrencyHistory::getDayRate(t->CURRENCYID, item.PURCHASEDATE) / Model_CurrencyHistory::getDayRate(currencyID, item.PURCHASEDATE);

        if (m_total_shares < 0)
            m_total_shares = 0;

        double txnPrice = 0.0;
        if (item.NUMSHARES > 0)
        {
            txnPrice = (item.NUMSHARES * item.PURCHASEPRICE + item.COMMISSION);
            m_total_cost += txnPrice;
            m_total_cost_tgt_curr += txnPrice * target_conv_rate;
            m_total_shares += item.NUMSHARES;
            m_average_price = (m_total_cost / m_total_shares);
        }
        else
        {
            if (!item.LOT.IsEmpty())
            {
                Data_Set lot_txns = instance().find(LOT(item.LOT));
                std::sort(lot_txns.begin(), lot_txns.end(), SorterByPURCHASEDATE());
                if (!lot_txns.empty() && lot_txns[0].NUMSHARES > 0)
                {
                    txnPrice = item.NUMSHARES * lot_txns[0].PURCHASEPRICE;
                    m_real_gain += -item.NUMSHARES * (item.PURCHASEPRICE - lot_txns[0].PURCHASEPRICE);
                }

            }
            else
            {
                m_average_price = (m_total_cost / m_total_shares);
                txnPrice = item.NUMSHARES * m_average_price;
                m_real_gain += -item.NUMSHARES * (item.PURCHASEPRICE - m_average_price) - item.COMMISSION;
                m_real_gain_tgt_curr += (-item.NUMSHARES * (item.PURCHASEPRICE - m_average_price) - item.COMMISSION) * target_conv_rate;
            }
            m_total_cost += txnPrice;
            m_total_cost_tgt_curr += txnPrice * target_conv_rate;
            m_total_shares += item.NUMSHARES;
        }
        
        m_commission += item.COMMISSION;

    }

    double current_conv_rate = (t->CURRENCYID == currencyID) ? 1 : Model_CurrencyHistory::getDayRate(t->CURRENCYID) / Model_CurrencyHistory::getDayRate(currencyID);

    m_unreal_gain_tgt_curr = m_total_shares * t->CURRENTPRICE * current_conv_rate - m_total_cost_tgt_curr;
    m_unreal_gain = m_total_shares * t->CURRENTPRICE - m_total_cost;

    return;
}