// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      AttachmentTable.h
 *
 *      Interface to database table ATTACHMENT_V1
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

// Columns in database table ATTACHMENT_V1
struct AttachmentCol
{
    enum COL_ID
    {
        COL_ID_ATTACHMENTID = 0,
        COL_ID_REFTYPE,
        COL_ID_REFID,
        COL_ID_DESCRIPTION,
        COL_ID_FILENAME,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct ATTACHMENTID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_ATTACHMENTID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_ATTACHMENTID]; }
        explicit ATTACHMENTID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit ATTACHMENTID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
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

    struct DESCRIPTION : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_DESCRIPTION; }
        static wxString col_name() { return COL_NAME_A[COL_ID_DESCRIPTION]; }
        explicit DESCRIPTION(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit DESCRIPTION(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct FILENAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_FILENAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_FILENAME]; }
        explicit FILENAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit FILENAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };
};

// A single record in database table ATTACHMENT_V1
struct AttachmentRow
{
    using Col = AttachmentCol;
    using COL_ID = Col::COL_ID;

    int64 ATTACHMENTID; // primary key
    wxString REFTYPE;
    int64 REFID;
    wxString DESCRIPTION;
    wxString FILENAME;

    explicit AttachmentRow();
    explicit AttachmentRow(wxSQLite3ResultSet& q);
    AttachmentRow(const AttachmentRow& other) = default;

    int64 id() const { return ATTACHMENTID; }
    void id(const int64 id) { ATTACHMENTID = id; }
    void destroy() { delete this; }

    bool equals(const AttachmentRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    AttachmentRow& operator=(const AttachmentRow& other);
    bool operator< (const AttachmentRow& other) const { return id() < other.id(); }
    bool operator< (const AttachmentRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::ATTACHMENTID& col)
    {
        return ATTACHMENTID == col.m_value;
    }

    bool match(const Col::REFTYPE& col)
    {
        return REFTYPE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::REFID& col)
    {
        return REFID == col.m_value;
    }

    bool match(const Col::DESCRIPTION& col)
    {
        return DESCRIPTION.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::FILENAME& col)
    {
        return FILENAME.CmpNoCase(col.m_value) == 0;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByATTACHMENTID
    {
        bool operator()(const AttachmentRow& x, const AttachmentRow& y)
        {
            return x.ATTACHMENTID < y.ATTACHMENTID;
        }
    };

    struct SorterByREFTYPE
    {
        bool operator()(const AttachmentRow& x, const AttachmentRow& y)
        {
            return x.REFTYPE < y.REFTYPE;
        }
    };

    struct SorterByREFID
    {
        bool operator()(const AttachmentRow& x, const AttachmentRow& y)
        {
            return x.REFID < y.REFID;
        }
    };

    struct SorterByDESCRIPTION
    {
        bool operator()(const AttachmentRow& x, const AttachmentRow& y)
        {
            return x.DESCRIPTION < y.DESCRIPTION;
        }
    };

    struct SorterByFILENAME
    {
        bool operator()(const AttachmentRow& x, const AttachmentRow& y)
        {
            return x.FILENAME < y.FILENAME;
        }
    };
};

// Interface to database table ATTACHMENT_V1
struct AttachmentTable : public TableFactory<AttachmentRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using ATTACHMENTID = Col::ATTACHMENTID;
    using REFTYPE = Col::REFTYPE;
    using REFID = Col::REFID;
    using DESCRIPTION = Col::DESCRIPTION;
    using FILENAME = Col::FILENAME;

    AttachmentTable();
    ~AttachmentTable();

    void ensure_data() override;
};
