// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      StockHistoryTable.h
 *
 *      Interface to database table STOCKHISTORY_V1
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

// Columns in database table STOCKHISTORY_V1
struct StockHistoryCol
{
    enum COL_ID
    {
        COL_ID_HISTID = 0,
        COL_ID_SYMBOL,
        COL_ID_DATE,
        COL_ID_VALUE,
        COL_ID_UPDTYPE,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct HISTID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_HISTID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_HISTID]; }
        explicit HISTID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit HISTID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct SYMBOL : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_SYMBOL; }
        static wxString col_name() { return COL_NAME_A[COL_ID_SYMBOL]; }
        explicit SYMBOL(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit SYMBOL(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct DATE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_DATE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_DATE]; }
        explicit DATE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit DATE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct VALUE : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_VALUE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_VALUE]; }
        explicit VALUE(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit VALUE(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct UPDTYPE : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_UPDTYPE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_UPDTYPE]; }
        explicit UPDTYPE(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit UPDTYPE(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };
};

// A single record in database table STOCKHISTORY_V1
struct StockHistoryRow
{
    using Col = StockHistoryCol;
    using COL_ID = Col::COL_ID;

    int64 HISTID; // primary key
    wxString SYMBOL;
    wxString DATE;
    double VALUE;
    int64 UPDTYPE;

    explicit StockHistoryRow();
    explicit StockHistoryRow(wxSQLite3ResultSet& q);
    StockHistoryRow(const StockHistoryRow& other) = default;

    int64 id() const { return HISTID; }
    void id(const int64 id) { HISTID = id; }
    void destroy() { delete this; }

    bool equals(const StockHistoryRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    StockHistoryRow& operator=(const StockHistoryRow& other);
    bool operator< (const StockHistoryRow& other) const { return id() < other.id(); }
    bool operator< (const StockHistoryRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::HISTID& col)
    {
        return HISTID == col.m_value;
    }

    bool match(const Col::SYMBOL& col)
    {
        return SYMBOL.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::DATE& col)
    {
        return DATE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::VALUE& col)
    {
        return VALUE == col.m_value;
    }

    bool match(const Col::UPDTYPE& col)
    {
        return UPDTYPE == col.m_value;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByHISTID
    {
        bool operator()(const StockHistoryRow& x, const StockHistoryRow& y)
        {
            return x.HISTID < y.HISTID;
        }
    };

    struct SorterBySYMBOL
    {
        bool operator()(const StockHistoryRow& x, const StockHistoryRow& y)
        {
            return x.SYMBOL < y.SYMBOL;
        }
    };

    struct SorterByDATE
    {
        bool operator()(const StockHistoryRow& x, const StockHistoryRow& y)
        {
            return x.DATE < y.DATE;
        }
    };

    struct SorterByVALUE
    {
        bool operator()(const StockHistoryRow& x, const StockHistoryRow& y)
        {
            return x.VALUE < y.VALUE;
        }
    };

    struct SorterByUPDTYPE
    {
        bool operator()(const StockHistoryRow& x, const StockHistoryRow& y)
        {
            return x.UPDTYPE < y.UPDTYPE;
        }
    };
};

// Interface to database table STOCKHISTORY_V1
struct StockHistoryTable : public TableFactory<StockHistoryRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using HISTID = Col::HISTID;
    using SYMBOL = Col::SYMBOL;
    using DATE = Col::DATE;
    using VALUE = Col::VALUE;
    using UPDTYPE = Col::UPDTYPE;

    StockHistoryTable();
    ~StockHistoryTable();

    void ensure_data() override;
};
