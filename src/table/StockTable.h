// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      StockTable.h
 *
 *      Interface to database table STOCK_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#pragma once

#include "_TableFactory.h"

// Columns in database table STOCK_V1
struct StockCol
{
    enum COL_ID
    {
        COL_ID_STOCKID = 0,
        COL_ID_HELDAT,
        COL_ID_PURCHASEDATE,
        COL_ID_STOCKNAME,
        COL_ID_SYMBOL,
        COL_ID_NUMSHARES,
        COL_ID_PURCHASEPRICE,
        COL_ID_NOTES,
        COL_ID_CURRENTPRICE,
        COL_ID_VALUE,
        COL_ID_COMMISSION,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct STOCKID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_STOCKID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_STOCKID]; }
        explicit STOCKID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit STOCKID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct HELDAT : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_HELDAT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_HELDAT]; }
        explicit HELDAT(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit HELDAT(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct PURCHASEDATE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_PURCHASEDATE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_PURCHASEDATE]; }
        explicit PURCHASEDATE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit PURCHASEDATE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct STOCKNAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_STOCKNAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_STOCKNAME]; }
        explicit STOCKNAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit STOCKNAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct SYMBOL : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_SYMBOL; }
        static wxString col_name() { return COL_NAME_A[COL_ID_SYMBOL]; }
        explicit SYMBOL(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit SYMBOL(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct NUMSHARES : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_NUMSHARES; }
        static wxString col_name() { return COL_NAME_A[COL_ID_NUMSHARES]; }
        explicit NUMSHARES(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit NUMSHARES(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct PURCHASEPRICE : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_PURCHASEPRICE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_PURCHASEPRICE]; }
        explicit PURCHASEPRICE(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit PURCHASEPRICE(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct NOTES : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_NOTES; }
        static wxString col_name() { return COL_NAME_A[COL_ID_NOTES]; }
        explicit NOTES(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit NOTES(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct CURRENTPRICE : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_CURRENTPRICE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRENTPRICE]; }
        explicit CURRENTPRICE(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit CURRENTPRICE(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct VALUE : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_VALUE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_VALUE]; }
        explicit VALUE(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit VALUE(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct COMMISSION : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_COMMISSION; }
        static wxString col_name() { return COL_NAME_A[COL_ID_COMMISSION]; }
        explicit COMMISSION(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit COMMISSION(OP op, const double &v): TableOpV<double>(op, v) {}
    };
};

// A single record in database table STOCK_V1
struct StockRow
{
    using Col = StockCol;
    using COL_ID = Col::COL_ID;

    int64 STOCKID; // primary key
    int64 HELDAT;
    wxString PURCHASEDATE;
    wxString STOCKNAME;
    wxString SYMBOL;
    double NUMSHARES;
    double PURCHASEPRICE;
    wxString NOTES;
    double CURRENTPRICE;
    double VALUE;
    double COMMISSION;

    explicit StockRow();
    explicit StockRow(wxSQLite3ResultSet& q);
    StockRow(const StockRow& other) = default;

    int64 id() const { return STOCKID; }
    void id(const int64 id) { STOCKID = id; }
    void destroy() { delete this; }

    bool equals(const StockRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    StockRow& operator=(const StockRow& other);
    bool operator< (const StockRow& other) const { return id() < other.id(); }
    bool operator< (const StockRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::STOCKID& col)
    {
        return STOCKID == col.m_value;
    }

    bool match(const Col::HELDAT& col)
    {
        return HELDAT == col.m_value;
    }

    bool match(const Col::PURCHASEDATE& col)
    {
        return PURCHASEDATE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::STOCKNAME& col)
    {
        return STOCKNAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::SYMBOL& col)
    {
        return SYMBOL.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::NUMSHARES& col)
    {
        return NUMSHARES == col.m_value;
    }

    bool match(const Col::PURCHASEPRICE& col)
    {
        return PURCHASEPRICE == col.m_value;
    }

    bool match(const Col::NOTES& col)
    {
        return NOTES.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::CURRENTPRICE& col)
    {
        return CURRENTPRICE == col.m_value;
    }

    bool match(const Col::VALUE& col)
    {
        return VALUE == col.m_value;
    }

    bool match(const Col::COMMISSION& col)
    {
        return COMMISSION == col.m_value;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterBySTOCKID
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.STOCKID < y.STOCKID;
        }
    };

    struct SorterByHELDAT
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.HELDAT < y.HELDAT;
        }
    };

    struct SorterByPURCHASEDATE
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.PURCHASEDATE < y.PURCHASEDATE;
        }
    };

    struct SorterBySTOCKNAME
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.STOCKNAME < y.STOCKNAME;
        }
    };

    struct SorterBySYMBOL
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.SYMBOL < y.SYMBOL;
        }
    };

    struct SorterByNUMSHARES
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.NUMSHARES < y.NUMSHARES;
        }
    };

    struct SorterByPURCHASEPRICE
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.PURCHASEPRICE < y.PURCHASEPRICE;
        }
    };

    struct SorterByNOTES
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.NOTES < y.NOTES;
        }
    };

    struct SorterByCURRENTPRICE
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.CURRENTPRICE < y.CURRENTPRICE;
        }
    };

    struct SorterByVALUE
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.VALUE < y.VALUE;
        }
    };

    struct SorterByCOMMISSION
    {
        bool operator()(const StockRow& x, const StockRow& y)
        {
            return x.COMMISSION < y.COMMISSION;
        }
    };
};

// Interface to database table STOCK_V1
struct StockTable : public TableFactory<StockRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using STOCKID = Col::STOCKID;
    using HELDAT = Col::HELDAT;
    using PURCHASEDATE = Col::PURCHASEDATE;
    using STOCKNAME = Col::STOCKNAME;
    using SYMBOL = Col::SYMBOL;
    using NUMSHARES = Col::NUMSHARES;
    using PURCHASEPRICE = Col::PURCHASEPRICE;
    using NOTES = Col::NOTES;
    using CURRENTPRICE = Col::CURRENTPRICE;
    using VALUE = Col::VALUE;
    using COMMISSION = Col::COMMISSION;

    StockTable();
    ~StockTable();

    void ensure_data() override;
};
