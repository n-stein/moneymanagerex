// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      UsageTable.h
 *
 *      Interface to database table USAGE_V1
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

// Columns in database table USAGE_V1
struct UsageCol
{
    enum COL_ID
    {
        COL_ID_USAGEID = 0,
        COL_ID_USAGEDATE,
        COL_ID_JSONCONTENT,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct USAGEID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_USAGEID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_USAGEID]; }
        explicit USAGEID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit USAGEID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct USAGEDATE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_USAGEDATE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_USAGEDATE]; }
        explicit USAGEDATE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit USAGEDATE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct JSONCONTENT : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_JSONCONTENT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_JSONCONTENT]; }
        explicit JSONCONTENT(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit JSONCONTENT(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };
};

// A single record in database table USAGE_V1
struct UsageRow
{
    using Col = UsageCol;
    using COL_ID = Col::COL_ID;

    int64 USAGEID; // primary key
    wxString USAGEDATE;
    wxString JSONCONTENT;

    explicit UsageRow();
    explicit UsageRow(wxSQLite3ResultSet& q);
    UsageRow(const UsageRow& other) = default;

    int64 id() const { return USAGEID; }
    void id(const int64 id) { USAGEID = id; }
    void destroy() { delete this; }

    bool equals(const UsageRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    UsageRow& operator=(const UsageRow& other);
    bool operator< (const UsageRow& other) const { return id() < other.id(); }
    bool operator< (const UsageRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::USAGEID& col)
    {
        return USAGEID == col.m_value;
    }

    bool match(const Col::USAGEDATE& col)
    {
        return USAGEDATE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::JSONCONTENT& col)
    {
        return JSONCONTENT.CmpNoCase(col.m_value) == 0;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByUSAGEID
    {
        bool operator()(const UsageRow& x, const UsageRow& y)
        {
            return x.USAGEID < y.USAGEID;
        }
    };

    struct SorterByUSAGEDATE
    {
        bool operator()(const UsageRow& x, const UsageRow& y)
        {
            return x.USAGEDATE < y.USAGEDATE;
        }
    };

    struct SorterByJSONCONTENT
    {
        bool operator()(const UsageRow& x, const UsageRow& y)
        {
            return x.JSONCONTENT < y.JSONCONTENT;
        }
    };
};

// Interface to database table USAGE_V1
struct UsageTable : public TableFactory<UsageRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using USAGEID = Col::USAGEID;
    using USAGEDATE = Col::USAGEDATE;
    using JSONCONTENT = Col::JSONCONTENT;

    UsageTable();
    ~UsageTable();

    void ensure_data() override;
};
