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

#ifndef MODEL_STOCK_H
#define MODEL_STOCK_H

#include "Model.h"
#include "db/DB_Table_Stock_V1.h"
#include "Model_Account.h"
#include "Model_Ticker.h"

class Model_Stock : public Model<DB_Table_STOCK_V1>
{
public:
    Model_Stock();
    ~Model_Stock();

public:
    /**
    Initialize the global Model_Stock table on initial call.
    Resets the global table on subsequent calls.
    * Return the static instance address for Model_Stock table
    * Note: Assigning the address to a local variable can destroy the instance.
    */
    static Model_Stock& instance(wxSQLite3Database* db);

    /**
    * Return the static instance address for Model_Stock table
    * Note: Assigning the address to a local variable can destroy the instance.
    */
    static Model_Stock& instance();

public:

    struct SorterBySTOCKNAME
    {
        bool operator()(const Model_Stock::Data& x, const Model_Stock::Data& y)
        {
            Model_Ticker::Data* tickerx = Model_Ticker::instance().get(x.TICKERID);
            Model_Ticker::Data* tickery = Model_Ticker::instance().get(y.TICKERID);
            return (tickerx->NAME) < (tickery->NAME);
        }
    };

    static wxString get_stock_name(int64 stock_id);

    static wxDate PURCHASEDATE(const Data* stock);
    static wxDate PURCHASEDATE(const Data& stock);

    /** Original value of Stocks */
    static double InvestmentValue(const Data* r);
    /** Original value of Stocks */
    static double InvestmentValue(const Data& r);

    static double CurrentValue(const Data* r);
    static double CurrentValue(const Data& r);

    /** Realized gain/loss from sales, optionally converted to base currency */
    static double RealGainLoss(const Data* r, bool base_curr = false);
    /** Realized gain/loss from sales, optionally converted to base currency */
    static double RealGainLoss(const Data& r, bool base_curr = false);

    /** The current unrealized gain/loss, optionally converted to base currency */
    static double UnrealGainLoss(const Data* r, bool base_curr = false);
    /** The current unrealized gain/loss, optionally converted to base currency */
    static double UnrealGainLoss(const Data& r, bool base_curr = false);


public:

    /**
    Returns the last price date of a given stock
    */
    wxString lastPriceDate(const Self::Data* entity);

    /**
    Returns the total stock balance at a given date
    */
    double getDailyBalanceAt(const Model_Account::Data *account, const wxDate& date);

};

class Model_StockStat : public Model_Stock
{
public:
    Model_StockStat(int64 ticker_id, int64 accountID, int64 target_currencyID = -1, wxDate date = wxDate::Today());
    ~Model_StockStat();

    double get_cost_ticker_curr() const;
    double get_avg_price_ticker_curr() const;
    double get_real_gain_ticker_curr() const;
    double get_unreal_gain_ticker_curr() const;
    double get_real_gain_target_curr() const;
    double get_unreal_gain_target_curr() const;
    double get_total_shares() const;
    double get_cost_target_curr() const;
    double get_commission_ticker_curr() const;
    wxString get_init_date() const;

private:
    double m_total_cost;
    double m_average_price;
    double m_real_gain;
    double m_unreal_gain;
    double m_real_gain_tgt_curr;
    double m_unreal_gain_tgt_curr;
    double m_total_shares;
    double m_total_cost_tgt_curr;
    double m_commission;;
    wxString m_init_date;
};

inline double Model_StockStat::get_cost_ticker_curr() const
{
    return m_total_cost;
}

inline double Model_StockStat::get_avg_price_ticker_curr() const
{
    return m_average_price;
}
inline double Model_StockStat::get_real_gain_ticker_curr() const
{
    return m_real_gain;
}

inline double Model_StockStat::get_unreal_gain_ticker_curr() const
{
    return m_unreal_gain;
}
inline double Model_StockStat::get_real_gain_target_curr() const
{
    return m_real_gain_tgt_curr;
}

inline double Model_StockStat::get_unreal_gain_target_curr() const
{
    return m_unreal_gain_tgt_curr;
}
inline double Model_StockStat::get_total_shares() const
{
    return m_total_shares;
}
inline double Model_StockStat::get_commission_ticker_curr() const
{
    return m_commission;
}
inline wxString Model_StockStat::get_init_date() const
{
    return m_init_date;
}

inline double Model_StockStat::get_cost_target_curr() const
{
    return m_total_cost_tgt_curr;
}

#endif // 
