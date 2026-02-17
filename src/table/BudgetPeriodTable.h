// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      BudgetPeriodTable.h
 *
 *      Interface to database table BUDGETYEAR_V1
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

// Columns in database table BUDGETYEAR_V1
struct BudgetPeriodCol
{
    enum COL_ID
    {
        COL_ID_BUDGETYEARID = 0,
        COL_ID_BUDGETYEARNAME,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct BUDGETYEARID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_BUDGETYEARID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_BUDGETYEARID]; }
        explicit BUDGETYEARID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit BUDGETYEARID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct BUDGETYEARNAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_BUDGETYEARNAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_BUDGETYEARNAME]; }
        explicit BUDGETYEARNAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit BUDGETYEARNAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };
};

// A single record in database table BUDGETYEAR_V1
struct BudgetPeriodRow
{
    using Col = BudgetPeriodCol;
    using COL_ID = Col::COL_ID;

    int64 BUDGETYEARID; // primary key
    wxString BUDGETYEARNAME;

    explicit BudgetPeriodRow();
    explicit BudgetPeriodRow(wxSQLite3ResultSet& q);
    BudgetPeriodRow(const BudgetPeriodRow& other) = default;

    int64 id() const { return BUDGETYEARID; }
    void id(const int64 id) { BUDGETYEARID = id; }
    void destroy() { delete this; }

    bool equals(const BudgetPeriodRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    BudgetPeriodRow& operator=(const BudgetPeriodRow& other);
    bool operator< (const BudgetPeriodRow& other) const { return id() < other.id(); }
    bool operator< (const BudgetPeriodRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::BUDGETYEARID& col)
    {
        return BUDGETYEARID == col.m_value;
    }

    bool match(const Col::BUDGETYEARNAME& col)
    {
        return BUDGETYEARNAME.CmpNoCase(col.m_value) == 0;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByBUDGETYEARID
    {
        bool operator()(const BudgetPeriodRow& x, const BudgetPeriodRow& y)
        {
            return x.BUDGETYEARID < y.BUDGETYEARID;
        }
    };

    struct SorterByBUDGETYEARNAME
    {
        bool operator()(const BudgetPeriodRow& x, const BudgetPeriodRow& y)
        {
            return x.BUDGETYEARNAME < y.BUDGETYEARNAME;
        }
    };
};

// Interface to database table BUDGETYEAR_V1
struct BudgetPeriodTable : public TableFactory<BudgetPeriodRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using BUDGETYEARID = Col::BUDGETYEARID;
    using BUDGETYEARNAME = Col::BUDGETYEARNAME;

    BudgetPeriodTable();
    ~BudgetPeriodTable();

    void ensure_data() override;
};
