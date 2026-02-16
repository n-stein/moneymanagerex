// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      FieldValueTable.h
 *
 *      Interface to database table CUSTOMFIELDDATA_V1
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

// Columns in database table CUSTOMFIELDDATA_V1
struct FieldValueCol
{
    enum COL_ID
    {
        COL_ID_FIELDATADID = 0,
        COL_ID_FIELDID,
        COL_ID_REFID,
        COL_ID_CONTENT,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct FIELDATADID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_FIELDATADID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_FIELDATADID]; }
        explicit FIELDATADID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit FIELDATADID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct FIELDID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_FIELDID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_FIELDID]; }
        explicit FIELDID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit FIELDID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct REFID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_REFID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_REFID]; }
        explicit REFID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit REFID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct CONTENT : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_CONTENT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CONTENT]; }
        explicit CONTENT(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit CONTENT(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };
};

// A single record in database table CUSTOMFIELDDATA_V1
struct FieldValueRow
{
    using Col = FieldValueCol;
    using COL_ID = Col::COL_ID;

    int64 FIELDATADID; // primary key
    int64 FIELDID;
    int64 REFID;
    wxString CONTENT;

    explicit FieldValueRow();
    explicit FieldValueRow(wxSQLite3ResultSet& q);
    FieldValueRow(const FieldValueRow& other) = default;

    int64 id() const { return FIELDATADID; }
    void id(const int64 id) { FIELDATADID = id; }
    void destroy() { delete this; }

    bool equals(const FieldValueRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    FieldValueRow& operator=(const FieldValueRow& other);
    bool operator< (const FieldValueRow& other) const { return id() < other.id(); }
    bool operator< (const FieldValueRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::FIELDATADID& col)
    {
        return FIELDATADID == col.m_value;
    }

    bool match(const Col::FIELDID& col)
    {
        return FIELDID == col.m_value;
    }

    bool match(const Col::REFID& col)
    {
        return REFID == col.m_value;
    }

    bool match(const Col::CONTENT& col)
    {
        return CONTENT.CmpNoCase(col.m_value) == 0;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByFIELDATADID
    {
        bool operator()(const FieldValueRow& x, const FieldValueRow& y)
        {
            return x.FIELDATADID < y.FIELDATADID;
        }
    };

    struct SorterByFIELDID
    {
        bool operator()(const FieldValueRow& x, const FieldValueRow& y)
        {
            return x.FIELDID < y.FIELDID;
        }
    };

    struct SorterByREFID
    {
        bool operator()(const FieldValueRow& x, const FieldValueRow& y)
        {
            return x.REFID < y.REFID;
        }
    };

    struct SorterByCONTENT
    {
        bool operator()(const FieldValueRow& x, const FieldValueRow& y)
        {
            return x.CONTENT < y.CONTENT;
        }
    };
};

// Interface to database table CUSTOMFIELDDATA_V1
struct FieldValueTable : public TableFactory<FieldValueRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using FIELDATADID = Col::FIELDATADID;
    using FIELDID = Col::FIELDID;
    using REFID = Col::REFID;
    using CONTENT = Col::CONTENT;

    FieldValueTable();
    ~FieldValueTable();

    void ensure_data() override;
};
