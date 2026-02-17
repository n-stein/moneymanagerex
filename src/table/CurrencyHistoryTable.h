// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      CurrencyHistoryTable.h
 *
 *      Interface to database table CURRENCYHISTORY_V1
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

// Columns in database table CURRENCYHISTORY_V1
struct CurrencyHistoryCol
{
    enum COL_ID
    {
        COL_ID_CURRHISTID = 0,
        COL_ID_CURRENCYID,
        COL_ID_CURRDATE,
        COL_ID_CURRVALUE,
        COL_ID_CURRUPDTYPE,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct CURRHISTID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_CURRHISTID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRHISTID]; }
        explicit CURRHISTID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit CURRHISTID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct CURRENCYID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_CURRENCYID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRENCYID]; }
        explicit CURRENCYID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit CURRENCYID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct CURRDATE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_CURRDATE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRDATE]; }
        explicit CURRDATE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit CURRDATE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct CURRVALUE : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_CURRVALUE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRVALUE]; }
        explicit CURRVALUE(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit CURRVALUE(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct CURRUPDTYPE : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_CURRUPDTYPE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRUPDTYPE]; }
        explicit CURRUPDTYPE(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit CURRUPDTYPE(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };
};

// A single record in database table CURRENCYHISTORY_V1
struct CurrencyHistoryRow
{
    using Col = CurrencyHistoryCol;
    using COL_ID = Col::COL_ID;

    int64 CURRHISTID; // primary key
    int64 CURRENCYID;
    wxString CURRDATE;
    double CURRVALUE;
    int64 CURRUPDTYPE;

    explicit CurrencyHistoryRow();
    explicit CurrencyHistoryRow(wxSQLite3ResultSet& q);
    CurrencyHistoryRow(const CurrencyHistoryRow& other) = default;

    int64 id() const { return CURRHISTID; }
    void id(const int64 id) { CURRHISTID = id; }
    void destroy() { delete this; }

    bool equals(const CurrencyHistoryRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    CurrencyHistoryRow& operator=(const CurrencyHistoryRow& other);
    bool operator< (const CurrencyHistoryRow& other) const { return id() < other.id(); }
    bool operator< (const CurrencyHistoryRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::CURRHISTID& col)
    {
        return CURRHISTID == col.m_value;
    }

    bool match(const Col::CURRENCYID& col)
    {
        return CURRENCYID == col.m_value;
    }

    bool match(const Col::CURRDATE& col)
    {
        return CURRDATE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::CURRVALUE& col)
    {
        return CURRVALUE == col.m_value;
    }

    bool match(const Col::CURRUPDTYPE& col)
    {
        return CURRUPDTYPE == col.m_value;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByCURRHISTID
    {
        bool operator()(const CurrencyHistoryRow& x, const CurrencyHistoryRow& y)
        {
            return x.CURRHISTID < y.CURRHISTID;
        }
    };

    struct SorterByCURRENCYID
    {
        bool operator()(const CurrencyHistoryRow& x, const CurrencyHistoryRow& y)
        {
            return x.CURRENCYID < y.CURRENCYID;
        }
    };

    struct SorterByCURRDATE
    {
        bool operator()(const CurrencyHistoryRow& x, const CurrencyHistoryRow& y)
        {
            return x.CURRDATE < y.CURRDATE;
        }
    };

    struct SorterByCURRVALUE
    {
        bool operator()(const CurrencyHistoryRow& x, const CurrencyHistoryRow& y)
        {
            return x.CURRVALUE < y.CURRVALUE;
        }
    };

    struct SorterByCURRUPDTYPE
    {
        bool operator()(const CurrencyHistoryRow& x, const CurrencyHistoryRow& y)
        {
            return x.CURRUPDTYPE < y.CURRUPDTYPE;
        }
    };
};

// Interface to database table CURRENCYHISTORY_V1
struct CurrencyHistoryTable : public TableFactory<CurrencyHistoryRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using CURRHISTID = Col::CURRHISTID;
    using CURRENCYID = Col::CURRENCYID;
    using CURRDATE = Col::CURRDATE;
    using CURRVALUE = Col::CURRVALUE;
    using CURRUPDTYPE = Col::CURRUPDTYPE;

    CurrencyHistoryTable();
    ~CurrencyHistoryTable();

    void ensure_data() override;
};
