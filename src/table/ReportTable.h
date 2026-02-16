// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      ReportTable.h
 *
 *      Interface to database table REPORT_V1
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

// Columns in database table REPORT_V1
struct ReportCol
{
    enum COL_ID
    {
        COL_ID_REPORTID = 0,
        COL_ID_REPORTNAME,
        COL_ID_GROUPNAME,
        COL_ID_ACTIVE,
        COL_ID_SQLCONTENT,
        COL_ID_LUACONTENT,
        COL_ID_TEMPLATECONTENT,
        COL_ID_DESCRIPTION,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct REPORTID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_REPORTID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_REPORTID]; }
        explicit REPORTID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit REPORTID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct REPORTNAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_REPORTNAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_REPORTNAME]; }
        explicit REPORTNAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit REPORTNAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct GROUPNAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_GROUPNAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_GROUPNAME]; }
        explicit GROUPNAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit GROUPNAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct ACTIVE : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_ACTIVE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_ACTIVE]; }
        explicit ACTIVE(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit ACTIVE(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct SQLCONTENT : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_SQLCONTENT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_SQLCONTENT]; }
        explicit SQLCONTENT(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit SQLCONTENT(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct LUACONTENT : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_LUACONTENT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_LUACONTENT]; }
        explicit LUACONTENT(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit LUACONTENT(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct TEMPLATECONTENT : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_TEMPLATECONTENT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_TEMPLATECONTENT]; }
        explicit TEMPLATECONTENT(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit TEMPLATECONTENT(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct DESCRIPTION : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_DESCRIPTION; }
        static wxString col_name() { return COL_NAME_A[COL_ID_DESCRIPTION]; }
        explicit DESCRIPTION(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit DESCRIPTION(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };
};

// A single record in database table REPORT_V1
struct ReportRow
{
    using Col = ReportCol;
    using COL_ID = Col::COL_ID;

    int64 REPORTID; // primary key
    wxString REPORTNAME;
    wxString GROUPNAME;
    int64 ACTIVE;
    wxString SQLCONTENT;
    wxString LUACONTENT;
    wxString TEMPLATECONTENT;
    wxString DESCRIPTION;

    explicit ReportRow();
    explicit ReportRow(wxSQLite3ResultSet& q);
    ReportRow(const ReportRow& other) = default;

    int64 id() const { return REPORTID; }
    void id(const int64 id) { REPORTID = id; }
    void destroy() { delete this; }

    bool equals(const ReportRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    ReportRow& operator=(const ReportRow& other);
    bool operator< (const ReportRow& other) const { return id() < other.id(); }
    bool operator< (const ReportRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::REPORTID& col)
    {
        return REPORTID == col.m_value;
    }

    bool match(const Col::REPORTNAME& col)
    {
        return REPORTNAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::GROUPNAME& col)
    {
        return GROUPNAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::ACTIVE& col)
    {
        return ACTIVE == col.m_value;
    }

    bool match(const Col::SQLCONTENT& col)
    {
        return SQLCONTENT.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::LUACONTENT& col)
    {
        return LUACONTENT.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::TEMPLATECONTENT& col)
    {
        return TEMPLATECONTENT.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::DESCRIPTION& col)
    {
        return DESCRIPTION.CmpNoCase(col.m_value) == 0;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByREPORTID
    {
        bool operator()(const ReportRow& x, const ReportRow& y)
        {
            return x.REPORTID < y.REPORTID;
        }
    };

    struct SorterByREPORTNAME
    {
        bool operator()(const ReportRow& x, const ReportRow& y)
        {
            return x.REPORTNAME < y.REPORTNAME;
        }
    };

    struct SorterByGROUPNAME
    {
        bool operator()(const ReportRow& x, const ReportRow& y)
        {
            return x.GROUPNAME < y.GROUPNAME;
        }
    };

    struct SorterByACTIVE
    {
        bool operator()(const ReportRow& x, const ReportRow& y)
        {
            return x.ACTIVE < y.ACTIVE;
        }
    };

    struct SorterBySQLCONTENT
    {
        bool operator()(const ReportRow& x, const ReportRow& y)
        {
            return x.SQLCONTENT < y.SQLCONTENT;
        }
    };

    struct SorterByLUACONTENT
    {
        bool operator()(const ReportRow& x, const ReportRow& y)
        {
            return x.LUACONTENT < y.LUACONTENT;
        }
    };

    struct SorterByTEMPLATECONTENT
    {
        bool operator()(const ReportRow& x, const ReportRow& y)
        {
            return x.TEMPLATECONTENT < y.TEMPLATECONTENT;
        }
    };

    struct SorterByDESCRIPTION
    {
        bool operator()(const ReportRow& x, const ReportRow& y)
        {
            return x.DESCRIPTION < y.DESCRIPTION;
        }
    };
};

// Interface to database table REPORT_V1
struct ReportTable : public TableFactory<ReportRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using REPORTID = Col::REPORTID;
    using REPORTNAME = Col::REPORTNAME;
    using GROUPNAME = Col::GROUPNAME;
    using ACTIVE = Col::ACTIVE;
    using SQLCONTENT = Col::SQLCONTENT;
    using LUACONTENT = Col::LUACONTENT;
    using TEMPLATECONTENT = Col::TEMPLATECONTENT;
    using DESCRIPTION = Col::DESCRIPTION;

    ReportTable();
    ~ReportTable();

    void ensure_data() override;
};
