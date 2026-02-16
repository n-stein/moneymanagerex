// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      TransactionLinkTable.h
 *
 *      Interface to database table TRANSLINK_V1
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

// Columns in database table TRANSLINK_V1
struct TransactionLinkCol
{
    enum COL_ID
    {
        COL_ID_TRANSLINKID = 0,
        COL_ID_CHECKINGACCOUNTID,
        COL_ID_LINKTYPE,
        COL_ID_LINKRECORDID,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct TRANSLINKID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_TRANSLINKID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_TRANSLINKID]; }
        explicit TRANSLINKID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit TRANSLINKID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct CHECKINGACCOUNTID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_CHECKINGACCOUNTID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CHECKINGACCOUNTID]; }
        explicit CHECKINGACCOUNTID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit CHECKINGACCOUNTID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct LINKTYPE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_LINKTYPE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_LINKTYPE]; }
        explicit LINKTYPE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit LINKTYPE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct LINKRECORDID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_LINKRECORDID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_LINKRECORDID]; }
        explicit LINKRECORDID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit LINKRECORDID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };
};

// A single record in database table TRANSLINK_V1
struct TransactionLinkRow
{
    using Col = TransactionLinkCol;
    using COL_ID = Col::COL_ID;

    int64 TRANSLINKID; // primary key
    int64 CHECKINGACCOUNTID;
    wxString LINKTYPE;
    int64 LINKRECORDID;

    explicit TransactionLinkRow();
    explicit TransactionLinkRow(wxSQLite3ResultSet& q);
    TransactionLinkRow(const TransactionLinkRow& other) = default;

    int64 id() const { return TRANSLINKID; }
    void id(const int64 id) { TRANSLINKID = id; }
    void destroy() { delete this; }

    bool equals(const TransactionLinkRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    TransactionLinkRow& operator=(const TransactionLinkRow& other);
    bool operator< (const TransactionLinkRow& other) const { return id() < other.id(); }
    bool operator< (const TransactionLinkRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::TRANSLINKID& col)
    {
        return TRANSLINKID == col.m_value;
    }

    bool match(const Col::CHECKINGACCOUNTID& col)
    {
        return CHECKINGACCOUNTID == col.m_value;
    }

    bool match(const Col::LINKTYPE& col)
    {
        return LINKTYPE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::LINKRECORDID& col)
    {
        return LINKRECORDID == col.m_value;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByTRANSLINKID
    {
        bool operator()(const TransactionLinkRow& x, const TransactionLinkRow& y)
        {
            return x.TRANSLINKID < y.TRANSLINKID;
        }
    };

    struct SorterByCHECKINGACCOUNTID
    {
        bool operator()(const TransactionLinkRow& x, const TransactionLinkRow& y)
        {
            return x.CHECKINGACCOUNTID < y.CHECKINGACCOUNTID;
        }
    };

    struct SorterByLINKTYPE
    {
        bool operator()(const TransactionLinkRow& x, const TransactionLinkRow& y)
        {
            return x.LINKTYPE < y.LINKTYPE;
        }
    };

    struct SorterByLINKRECORDID
    {
        bool operator()(const TransactionLinkRow& x, const TransactionLinkRow& y)
        {
            return x.LINKRECORDID < y.LINKRECORDID;
        }
    };
};

// Interface to database table TRANSLINK_V1
struct TransactionLinkTable : public TableFactory<TransactionLinkRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using TRANSLINKID = Col::TRANSLINKID;
    using CHECKINGACCOUNTID = Col::CHECKINGACCOUNTID;
    using LINKTYPE = Col::LINKTYPE;
    using LINKRECORDID = Col::LINKRECORDID;

    TransactionLinkTable();
    ~TransactionLinkTable();

    void ensure_data() override;
};
