/*******************************************************
 Copyright (C) 2006 Madhan Kanagavel
 Copyright (C) 2021,2024 Mark Whalley (mark@ipx.co.uk)

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

#include "summarystocks.h"
#include "reports/htmlbuilder.h"

#include "constants.h"
#include "stockspanel.h"
#include "budget.h"
#include "util.h"
#include "reports/mmDateRange.h"
#include "model/Model_Account.h"
#include "model/Model_Currency.h"
#include "model/Model_CurrencyHistory.h"
#include "model/Model_StockHistory.h"

#include <algorithm>

mmReportSummaryStocks::mmReportSummaryStocks()
    : mmPrintableBase(wxTRANSLATE("Summary of Stocks"))
{
    setReportParameters(Reports::StocksReportSummary);
}

void  mmReportSummaryStocks::RefreshData()
{
    m_stocks.clear();
    m_real_gain_loss_sum_total = 0.0;
    m_unreal_gain_loss_sum_total = 0.0;
    m_real_gain_loss_excl_forex = 0.0;
    m_unreal_gain_loss_excl_forex = 0.0;
    m_stock_balance = 0.0;

    data_holder line;
    account_holder account;
    const wxDate today = wxDate::Today();

    for (const auto& a : Model_Account::instance().all(Model_Account::COL_ACCOUNTNAME))
    {
        if (Model_Account::type_id(a) != Model_Account::TYPE_ID_INVESTMENT) continue;
        if (Model_Account::status_id(a) != Model_Account::STATUS_ID_OPEN) continue;

        account.id = a.id();
        account.name = a.ACCOUNTNAME;
        account.realgainloss = 0.0;
        account.unrealgainloss = 0.0;
        account.total = Model_Account::investment_balance(a).second;
        account.data.clear();

        for (const auto& ticker : Model_Account::getTickerIds(a.ACCOUNTID))
        {
            Model_StockStat s_acct = Model_StockStat(ticker, a.ACCOUNTID, a.CURRENCYID);
            Model_StockStat s_base = Model_StockStat(ticker, a.ACCOUNTID);
            Model_Ticker::Data* t = Model_Ticker::instance().get(ticker);
            const Model_Currency::Data* currency = Model_Account::currency(a);
            const double acct_rate = Model_CurrencyHistory::getDayRate(currency->CURRENCYID);
            const double ticker_rate = Model_CurrencyHistory::getDayRate(t->CURRENCYID);
            m_stock_balance += (s_base.get_cost_target_curr() + s_base.get_unreal_gain_target_curr());
            line.realgainloss = s_acct.get_real_gain_ticker_curr();
            account.realgainloss += s_acct.get_real_gain_target_curr();
            line.unrealgainloss = s_acct.get_unreal_gain_ticker_curr();
            account.unrealgainloss += s_acct.get_unreal_gain_ticker_curr() * ticker_rate / acct_rate;
            m_unreal_gain_loss_sum_total += s_base.get_unreal_gain_target_curr();
            m_real_gain_loss_sum_total += s_base.get_real_gain_target_curr();
            m_real_gain_loss_excl_forex += s_acct.get_real_gain_ticker_curr() * ticker_rate;
            m_unreal_gain_loss_excl_forex += s_acct.get_unreal_gain_ticker_curr() * ticker_rate;
            line.name = t->NAME;
            line.symbol = t->SYMBOL;
            line.date = s_acct.get_init_date();
            line.qty = s_acct.get_total_shares();
            line.purchase = s_acct.get_cost_ticker_curr();
            line.current = t->CURRENTPRICE;
            line.commission = s_acct.get_commission_ticker_curr();
            line.value = s_acct.get_total_shares() * t->CURRENTPRICE;
            line.currency = t->CURRENCYID;
            account.data.push_back(line);
        }
        m_stocks.push_back(account);
    }
}

wxString mmReportSummaryStocks::getHTMLText()
{
    // Grab the data  
    RefreshData();

    // Build the report
    mmHTMLBuilder hb;
    hb.init();
    hb.addReportHeader(getReportTitle());

    hb.addDivContainer("shadow");
    {
        hb.startTable();
        {
            hb.startThead();
            {
                hb.startTableRow();
                {
                    hb.addTableHeaderCell(_("Name"));
                    hb.addTableHeaderCell(_("Symbol"));
                    hb.addTableHeaderCell(_("Purchase Date"));
                    hb.addTableHeaderCell(_("Quantity"), "text-right");
                    hb.addTableHeaderCell(_("Initial Value"), "text-right");
                    hb.addTableHeaderCell(_("Current Price"), "text-right");
                    hb.addTableHeaderCell(_("Commission"), "text-right");
                    hb.addTableHeaderCell(_("Realized Gain/Loss"), "text-right");
                    hb.addTableHeaderCell(_("Unrealized Gain/Loss"), "text-right");
                    hb.addTableHeaderCell(_("Current Value"), "text-right");
                }
                hb.endTableRow();
            }
            hb.endThead();

            for (const auto& acct : m_stocks)
            {
                const Model_Account::Data* account = Model_Account::instance().get(acct.id);
                const Model_Currency::Data* acct_currency = Model_Account::currency(account);

                hb.startThead();
                {
                    hb.startTableRow();
                    {
                        hb.addTableHeaderCell(acct.name, "text-left", 10);
                    }
                    hb.endTableRow();
                }
                hb.endThead();

                hb.startTbody();
                {
                    for (const auto& entry : acct.data)
                    {
                        const Model_Currency::Data* currency = Model_Currency::instance().get(entry.currency);
                        hb.startTableRow();
                        {
                            hb.addTableCell(entry.name);
                            hb.addTableCell(entry.symbol);
                            hb.addTableCellDate(entry.date);
                            hb.addTableCell(Model_Account::toString(entry.qty, account, trunc(entry.qty) == entry.qty ? 0 : 4), "text-right");
                            hb.addCurrencyCell(entry.purchase, currency, 4);
                            hb.addCurrencyCell(entry.current, currency, 4);
                            hb.addCurrencyCell(entry.commission, currency, 4);
                            hb.addCurrencyCell(entry.realgainloss, currency);
                            hb.addCurrencyCell(entry.unrealgainloss, currency);
                            hb.addCurrencyCell(entry.value, currency);
                        }
                        hb.endTableRow();
                    }
                    hb.startTotalTableRow();
                    {
                        hb.addTableCell(_("Total:"));
                        hb.addEmptyTableCell(6);
                        hb.addCurrencyCell(acct.realgainloss, acct_currency);
                        hb.addCurrencyCell(acct.unrealgainloss, acct_currency);
                        hb.addCurrencyCell(acct.total, acct_currency);
                    }
                    hb.endTableRow();
                    hb.addEmptyTableRow(9);
                }
                hb.endTbody();
            }

            hb.startTfoot();
            {
                // Round FX gain/loss to the scale of the base currency for display
                int scale = pow(10, log10(Model_Currency::instance().GetBaseCurrency()->SCALE.GetValue()));
                double forex_real_gain_loss = std::round((m_real_gain_loss_sum_total - m_real_gain_loss_excl_forex) * scale) / scale;
                double forex_unreal_gain_loss = std::round((m_unreal_gain_loss_sum_total - m_unreal_gain_loss_excl_forex) * scale) / scale;

                hb.startTotalTableRow();
                hb.addTableCell(_("Grand Total:"));
                hb.addEmptyTableCell(6);

                hb.startTableCell(" style='text-align:right;' nowrap");
                if (forex_real_gain_loss != 0) {
                    hb.startSpan(Model_Currency::toCurrency(m_real_gain_loss_excl_forex), wxString::Format(" style='text-align:right;%s' nowrap"
                        , m_real_gain_loss_excl_forex < 0 ? "color:red;" : ""));
                    hb.endSpan();
                    hb.startSpan(" + ", "");
                    hb.endSpan();
                    hb.startSpan(Model_Currency::toCurrency(forex_real_gain_loss), wxString::Format(" style='text-align:right;%s' nowrap"
                        , forex_real_gain_loss < 0 ? "color:red;" : ""));
                    hb.endSpan();
                    hb.startSpan(" FX", "");
                    hb.endSpan();
                    hb.addLineBreak();
                }
                hb.startSpan(Model_Currency::toCurrency(m_real_gain_loss_sum_total), wxString::Format(" style='text-align:right;%s' nowrap"
                    , m_real_gain_loss_sum_total < 0 ? "color:red;" : ""));
                hb.endSpan();

                hb.endTableCell();

                hb.startTableCell(" style='text-align:right;' nowrap");
                if (forex_unreal_gain_loss != 0) {
                    hb.startSpan(Model_Currency::toCurrency(m_unreal_gain_loss_excl_forex), wxString::Format(" style='text-align:right;%s' nowrap"
                        , m_unreal_gain_loss_excl_forex < 0 ? "color:red;" : ""));
                    hb.endSpan();
                    hb.startSpan(" + ", "");
                    hb.endSpan();
                    hb.startSpan(Model_Currency::toCurrency(forex_unreal_gain_loss), wxString::Format(" style='text-align:right;%s' nowrap"
                        , forex_unreal_gain_loss < 0 ? "color:red;" : ""));
                    hb.endSpan();
                    hb.startSpan(" FX", "");
                    hb.endSpan();
                    hb.addLineBreak();
                }
                hb.startSpan(Model_Currency::toCurrency(m_unreal_gain_loss_sum_total), wxString::Format(" style='text-align:right;%s' nowrap"
                    , m_unreal_gain_loss_sum_total < 0 ? "color:red;" : ""));
                hb.endSpan();

                hb.endTableCell();
                
                hb.startTableCell(" style='text-align:right;' nowrap");
                hb.startSpan(Model_Currency::toCurrency(m_stock_balance), "");
                hb.endSpan();

                hb.endTableCell();
            }
            hb.endTfoot();
        }
        hb.endTable();
    }
    hb.endDiv();

    hb.end();

    return hb.getHTMLText();
}

mmReportChartStocks::mmReportChartStocks()
    : mmPrintableBase(wxTRANSLATE("Stocks Performance Charts"))
{
    setReportParameters(Reports::StocksReportPerformance);
}

mmReportChartStocks::~mmReportChartStocks()
{
}

wxString mmReportChartStocks::getHTMLText()
{
    // Build the report
    mmHTMLBuilder hb;
    hb.init();
    hb.addReportHeader(getReportTitle(), m_date_range->startDay(), m_date_range->isFutureIgnored());
    wxTimeSpan dtDiff = m_date_range->end_date() - m_date_range->start_date();
    if (m_date_range->is_with_date() && dtDiff.GetDays() <= 366)
        hb.DisplayDateHeading(m_date_range->start_date(), m_date_range->end_date(), true);

    wxTimeSpan dist;
    wxDate precDateDt = wxInvalidDateTime;
    wxArrayString symbols;
    for (const auto& stock : Model_Stock::instance().all(Model_Stock::COL_TICKERID))
    {
        Model_Account::Data* account = Model_Account::instance().get(stock.HELDAT);
        Model_Ticker::Data* ticker = Model_Ticker::instance().get(stock.TICKERID);
        if (Model_Account::status_id(account) != Model_Account::STATUS_ID_OPEN) continue;
        if (symbols.Index(ticker->SYMBOL) != wxNOT_FOUND) continue;

        symbols.Add(ticker->SYMBOL);
        int dataCount = 0, freq = 1;
        auto histData = Model_StockHistory::instance().find(Model_StockHistory::SYMBOL(ticker->SYMBOL),
            Model_StockHistory::DATE(m_date_range->start_date(), GREATER_OR_EQUAL),
            Model_StockHistory::DATE(m_date_range->end_date(), LESS_OR_EQUAL));
        std::stable_sort(histData.begin(), histData.end(), SorterByDATE());

        //bool showGridLines = (histData.size() <= 366);
        //bool pointDot = (histData.size() <= 30);
        if (histData.size() > 366) {
            freq = histData.size() / 366;
        }

        GraphData gd;
        GraphSeries data;

        for (const auto& hist : histData)
        {
            if (dataCount % freq == 0)
            {
                const wxDate d = Model_StockHistory::DATE(hist);
                gd.labels.push_back(d.FormatISODate());
                data.values.push_back(hist.VALUE);
            }
            dataCount++;
        }
        gd.series.push_back(data);

        if (!gd.series.empty())
        {
            hb.addHeader(1, wxString::Format("%s / %s - (%s)", ticker->SYMBOL, ticker->NAME, account->ACCOUNTNAME));
            gd.type = GraphData::LINE_DATETIME;
            hb.addChart(gd);
        }
    }
    hb.endDiv();
    
    hb.end();

    wxLogDebug("======= mmReportChartStocks:getHTMLText =======");
    wxLogDebug("%s", hb.getHTMLText());    

    return hb.getHTMLText();
}
