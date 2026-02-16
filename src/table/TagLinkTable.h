// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      TagLinkTable.h
 *
 *      Interface to database table TAGLINK_V1
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

// Columns in database table TAGLINK_V1
struct TagLinkCol
{
    enum COL_ID
    {
        COL_ID_TAGLINKID = 0,
        COL_ID_REFTYPE,
        COL_ID_REFID,
        COL_ID_TAGID,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct TAGLINKID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_TAGLINKID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_TAGLINKID]; }
        explicit TAGLINKID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit TAGLINKID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct REFTYPE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_REFTYPE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_REFTYPE]; }
        explicit REFTYPE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit REFTYPE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct REFID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_REFID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_REFID]; }
        explicit REFID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit REFID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct TAGID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_TAGID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_TAGID]; }
        explicit TAGID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit TAGID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };
};

// A single record in database table TAGLINK_V1
struct TagLinkRow
{
    using Col = TagLinkCol;
    using COL_ID = Col::COL_ID;

    int64 TAGLINKID; // primary key
    wxString REFTYPE;
    int64 REFID;
    int64 TAGID;

    explicit TagLinkRow();
    explicit TagLinkRow(wxSQLite3ResultSet& q);
    TagLinkRow(const TagLinkRow& other) = default;

    int64 id() const { return TAGLINKID; }
    void id(const int64 id) { TAGLINKID = id; }
    void destroy() { delete this; }

    bool equals(const TagLinkRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    TagLinkRow& operator=(const TagLinkRow& other);
    bool operator< (const TagLinkRow& other) const { return id() < other.id(); }
    bool operator< (const TagLinkRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::TAGLINKID& col)
    {
        return TAGLINKID == col.m_value;
    }

    bool match(const Col::REFTYPE& col)
    {
        return REFTYPE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::REFID& col)
    {
        return REFID == col.m_value;
    }

    bool match(const Col::TAGID& col)
    {
        return TAGID == col.m_value;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByTAGLINKID
    {
        bool operator()(const TagLinkRow& x, const TagLinkRow& y)
        {
            return x.TAGLINKID < y.TAGLINKID;
        }
    };

    struct SorterByREFTYPE
    {
        bool operator()(const TagLinkRow& x, const TagLinkRow& y)
        {
            return x.REFTYPE < y.REFTYPE;
        }
    };

    struct SorterByREFID
    {
        bool operator()(const TagLinkRow& x, const TagLinkRow& y)
        {
            return x.REFID < y.REFID;
        }
    };

    struct SorterByTAGID
    {
        bool operator()(const TagLinkRow& x, const TagLinkRow& y)
        {
            return x.TAGID < y.TAGID;
        }
    };
};

// Interface to database table TAGLINK_V1
struct TagLinkTable : public TableFactory<TagLinkRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using TAGLINKID = Col::TAGLINKID;
    using REFTYPE = Col::REFTYPE;
    using REFID = Col::REFID;
    using TAGID = Col::TAGID;

    TagLinkTable();
    ~TagLinkTable();

    void ensure_data() override;
};
