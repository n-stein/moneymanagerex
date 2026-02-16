// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      FieldTable.h
 *
 *      Interface to database table CUSTOMFIELD_V1
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

// Columns in database table CUSTOMFIELD_V1
struct FieldCol
{
    enum COL_ID
    {
        COL_ID_FIELDID = 0,
        COL_ID_REFTYPE,
        COL_ID_DESCRIPTION,
        COL_ID_TYPE,
        COL_ID_PROPERTIES,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct FIELDID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_FIELDID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_FIELDID]; }
        explicit FIELDID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit FIELDID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct REFTYPE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_REFTYPE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_REFTYPE]; }
        explicit REFTYPE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit REFTYPE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct DESCRIPTION : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_DESCRIPTION; }
        static wxString col_name() { return COL_NAME_A[COL_ID_DESCRIPTION]; }
        explicit DESCRIPTION(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit DESCRIPTION(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct TYPE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_TYPE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_TYPE]; }
        explicit TYPE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit TYPE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct PROPERTIES : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_PROPERTIES; }
        static wxString col_name() { return COL_NAME_A[COL_ID_PROPERTIES]; }
        explicit PROPERTIES(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit PROPERTIES(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };
};

// A single record in database table CUSTOMFIELD_V1
struct FieldRow
{
    using Col = FieldCol;
    using COL_ID = Col::COL_ID;

    int64 FIELDID; // primary key
    wxString REFTYPE;
    wxString DESCRIPTION;
    wxString TYPE;
    wxString PROPERTIES;

    explicit FieldRow();
    explicit FieldRow(wxSQLite3ResultSet& q);
    FieldRow(const FieldRow& other) = default;

    int64 id() const { return FIELDID; }
    void id(const int64 id) { FIELDID = id; }
    void destroy() { delete this; }

    bool equals(const FieldRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    FieldRow& operator=(const FieldRow& other);
    bool operator< (const FieldRow& other) const { return id() < other.id(); }
    bool operator< (const FieldRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::FIELDID& col)
    {
        return FIELDID == col.m_value;
    }

    bool match(const Col::REFTYPE& col)
    {
        return REFTYPE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::DESCRIPTION& col)
    {
        return DESCRIPTION.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::TYPE& col)
    {
        return TYPE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::PROPERTIES& col)
    {
        return PROPERTIES.CmpNoCase(col.m_value) == 0;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByFIELDID
    {
        bool operator()(const FieldRow& x, const FieldRow& y)
        {
            return x.FIELDID < y.FIELDID;
        }
    };

    struct SorterByREFTYPE
    {
        bool operator()(const FieldRow& x, const FieldRow& y)
        {
            return x.REFTYPE < y.REFTYPE;
        }
    };

    struct SorterByDESCRIPTION
    {
        bool operator()(const FieldRow& x, const FieldRow& y)
        {
            return x.DESCRIPTION < y.DESCRIPTION;
        }
    };

    struct SorterByTYPE
    {
        bool operator()(const FieldRow& x, const FieldRow& y)
        {
            return x.TYPE < y.TYPE;
        }
    };

    struct SorterByPROPERTIES
    {
        bool operator()(const FieldRow& x, const FieldRow& y)
        {
            return x.PROPERTIES < y.PROPERTIES;
        }
    };
};

// Interface to database table CUSTOMFIELD_V1
struct FieldTable : public TableFactory<FieldRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using FIELDID = Col::FIELDID;
    using REFTYPE = Col::REFTYPE;
    using DESCRIPTION = Col::DESCRIPTION;
    using TYPE = Col::TYPE;
    using PROPERTIES = Col::PROPERTIES;

    FieldTable();
    ~FieldTable();

    void ensure_data() override;
};
