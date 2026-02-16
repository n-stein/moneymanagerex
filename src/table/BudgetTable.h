// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      BudgetTable.h
 *
 *      Interface to database table BUDGETTABLE_V1
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

// Columns in database table BUDGETTABLE_V1
struct BudgetCol
{
    enum COL_ID
    {
        COL_ID_BUDGETENTRYID = 0,
        COL_ID_BUDGETYEARID,
        COL_ID_CATEGID,
        COL_ID_PERIOD,
        COL_ID_AMOUNT,
        COL_ID_NOTES,
        COL_ID_ACTIVE,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct BUDGETENTRYID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_BUDGETENTRYID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_BUDGETENTRYID]; }
        explicit BUDGETENTRYID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit BUDGETENTRYID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct BUDGETYEARID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_BUDGETYEARID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_BUDGETYEARID]; }
        explicit BUDGETYEARID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit BUDGETYEARID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct CATEGID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_CATEGID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CATEGID]; }
        explicit CATEGID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit CATEGID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct PERIOD : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_PERIOD; }
        static wxString col_name() { return COL_NAME_A[COL_ID_PERIOD]; }
        explicit PERIOD(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit PERIOD(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct AMOUNT : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_AMOUNT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_AMOUNT]; }
        explicit AMOUNT(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit AMOUNT(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct NOTES : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_NOTES; }
        static wxString col_name() { return COL_NAME_A[COL_ID_NOTES]; }
        explicit NOTES(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit NOTES(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct ACTIVE : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_ACTIVE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_ACTIVE]; }
        explicit ACTIVE(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit ACTIVE(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };
};

// A single record in database table BUDGETTABLE_V1
struct BudgetRow
{
    using Col = BudgetCol;
    using COL_ID = Col::COL_ID;

    int64 BUDGETENTRYID; // primary key
    int64 BUDGETYEARID;
    int64 CATEGID;
    wxString PERIOD;
    double AMOUNT;
    wxString NOTES;
    int64 ACTIVE;

    explicit BudgetRow();
    explicit BudgetRow(wxSQLite3ResultSet& q);
    BudgetRow(const BudgetRow& other) = default;

    int64 id() const { return BUDGETENTRYID; }
    void id(const int64 id) { BUDGETENTRYID = id; }
    void destroy() { delete this; }

    bool equals(const BudgetRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    BudgetRow& operator=(const BudgetRow& other);
    bool operator< (const BudgetRow& other) const { return id() < other.id(); }
    bool operator< (const BudgetRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::BUDGETENTRYID& col)
    {
        return BUDGETENTRYID == col.m_value;
    }

    bool match(const Col::BUDGETYEARID& col)
    {
        return BUDGETYEARID == col.m_value;
    }

    bool match(const Col::CATEGID& col)
    {
        return CATEGID == col.m_value;
    }

    bool match(const Col::PERIOD& col)
    {
        return PERIOD.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::AMOUNT& col)
    {
        return AMOUNT == col.m_value;
    }

    bool match(const Col::NOTES& col)
    {
        return NOTES.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::ACTIVE& col)
    {
        return ACTIVE == col.m_value;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByBUDGETENTRYID
    {
        bool operator()(const BudgetRow& x, const BudgetRow& y)
        {
            return x.BUDGETENTRYID < y.BUDGETENTRYID;
        }
    };

    struct SorterByBUDGETYEARID
    {
        bool operator()(const BudgetRow& x, const BudgetRow& y)
        {
            return x.BUDGETYEARID < y.BUDGETYEARID;
        }
    };

    struct SorterByCATEGID
    {
        bool operator()(const BudgetRow& x, const BudgetRow& y)
        {
            return x.CATEGID < y.CATEGID;
        }
    };

    struct SorterByPERIOD
    {
        bool operator()(const BudgetRow& x, const BudgetRow& y)
        {
            return x.PERIOD < y.PERIOD;
        }
    };

    struct SorterByAMOUNT
    {
        bool operator()(const BudgetRow& x, const BudgetRow& y)
        {
            return x.AMOUNT < y.AMOUNT;
        }
    };

    struct SorterByNOTES
    {
        bool operator()(const BudgetRow& x, const BudgetRow& y)
        {
            return x.NOTES < y.NOTES;
        }
    };

    struct SorterByACTIVE
    {
        bool operator()(const BudgetRow& x, const BudgetRow& y)
        {
            return x.ACTIVE < y.ACTIVE;
        }
    };
};

// Interface to database table BUDGETTABLE_V1
struct BudgetTable : public TableFactory<BudgetRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using BUDGETENTRYID = Col::BUDGETENTRYID;
    using BUDGETYEARID = Col::BUDGETYEARID;
    using CATEGID = Col::CATEGID;
    using PERIOD = Col::PERIOD;
    using AMOUNT = Col::AMOUNT;
    using NOTES = Col::NOTES;
    using ACTIVE = Col::ACTIVE;

    BudgetTable();
    ~BudgetTable();

    void ensure_data() override;
};
