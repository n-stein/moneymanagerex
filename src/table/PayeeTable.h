// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      PayeeTable.h
 *
 *      Interface to database table PAYEE_V1
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

// Columns in database table PAYEE_V1
struct PayeeCol
{
    enum COL_ID
    {
        COL_ID_PAYEEID = 0,
        COL_ID_PAYEENAME,
        COL_ID_CATEGID,
        COL_ID_NUMBER,
        COL_ID_WEBSITE,
        COL_ID_NOTES,
        COL_ID_ACTIVE,
        COL_ID_PATTERN,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct PAYEEID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_PAYEEID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_PAYEEID]; }
        explicit PAYEEID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit PAYEEID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct PAYEENAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_PAYEENAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_PAYEENAME]; }
        explicit PAYEENAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit PAYEENAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct CATEGID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_CATEGID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CATEGID]; }
        explicit CATEGID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit CATEGID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct NUMBER : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_NUMBER; }
        static wxString col_name() { return COL_NAME_A[COL_ID_NUMBER]; }
        explicit NUMBER(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit NUMBER(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct WEBSITE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_WEBSITE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_WEBSITE]; }
        explicit WEBSITE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit WEBSITE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
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

    struct PATTERN : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_PATTERN; }
        static wxString col_name() { return COL_NAME_A[COL_ID_PATTERN]; }
        explicit PATTERN(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit PATTERN(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };
};

// A single record in database table PAYEE_V1
struct PayeeRow
{
    using Col = PayeeCol;
    using COL_ID = Col::COL_ID;

    int64 PAYEEID; // primary key
    wxString PAYEENAME;
    int64 CATEGID;
    wxString NUMBER;
    wxString WEBSITE;
    wxString NOTES;
    int64 ACTIVE;
    wxString PATTERN;

    explicit PayeeRow();
    explicit PayeeRow(wxSQLite3ResultSet& q);
    PayeeRow(const PayeeRow& other) = default;

    int64 id() const { return PAYEEID; }
    void id(const int64 id) { PAYEEID = id; }
    void destroy() { delete this; }

    bool equals(const PayeeRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    PayeeRow& operator=(const PayeeRow& other);
    bool operator< (const PayeeRow& other) const { return id() < other.id(); }
    bool operator< (const PayeeRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::PAYEEID& col)
    {
        return PAYEEID == col.m_value;
    }

    bool match(const Col::PAYEENAME& col)
    {
        return PAYEENAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::CATEGID& col)
    {
        return CATEGID == col.m_value;
    }

    bool match(const Col::NUMBER& col)
    {
        return NUMBER.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::WEBSITE& col)
    {
        return WEBSITE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::NOTES& col)
    {
        return NOTES.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::ACTIVE& col)
    {
        return ACTIVE == col.m_value;
    }

    bool match(const Col::PATTERN& col)
    {
        return PATTERN.CmpNoCase(col.m_value) == 0;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByPAYEEID
    {
        bool operator()(const PayeeRow& x, const PayeeRow& y)
        {
            return x.PAYEEID < y.PAYEEID;
        }
    };

    struct SorterByPAYEENAME
    {
        bool operator()(const PayeeRow& x, const PayeeRow& y)
        {
            // Locale case-insensitive
            return std::wcscoll(x.PAYEENAME.Lower().wc_str(), y.PAYEENAME.Lower().wc_str()) < 0;
        }
    };

    struct SorterByCATEGID
    {
        bool operator()(const PayeeRow& x, const PayeeRow& y)
        {
            return x.CATEGID < y.CATEGID;
        }
    };

    struct SorterByNUMBER
    {
        bool operator()(const PayeeRow& x, const PayeeRow& y)
        {
            return x.NUMBER < y.NUMBER;
        }
    };

    struct SorterByWEBSITE
    {
        bool operator()(const PayeeRow& x, const PayeeRow& y)
        {
            return x.WEBSITE < y.WEBSITE;
        }
    };

    struct SorterByNOTES
    {
        bool operator()(const PayeeRow& x, const PayeeRow& y)
        {
            return x.NOTES < y.NOTES;
        }
    };

    struct SorterByACTIVE
    {
        bool operator()(const PayeeRow& x, const PayeeRow& y)
        {
            return x.ACTIVE < y.ACTIVE;
        }
    };

    struct SorterByPATTERN
    {
        bool operator()(const PayeeRow& x, const PayeeRow& y)
        {
            return x.PATTERN < y.PATTERN;
        }
    };
};

// Interface to database table PAYEE_V1
struct PayeeTable : public TableFactory<PayeeRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using PAYEEID = Col::PAYEEID;
    using PAYEENAME = Col::PAYEENAME;
    using CATEGID = Col::CATEGID;
    using NUMBER = Col::NUMBER;
    using WEBSITE = Col::WEBSITE;
    using NOTES = Col::NOTES;
    using ACTIVE = Col::ACTIVE;
    using PATTERN = Col::PATTERN;

    PayeeTable();
    ~PayeeTable();

    void ensure_data() override;
};
