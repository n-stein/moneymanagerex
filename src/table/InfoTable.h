// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      InfoTable.h
 *
 *      Interface to database table INFOTABLE_V1
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

// Columns in database table INFOTABLE_V1
struct InfoCol
{
    enum COL_ID
    {
        COL_ID_INFOID = 0,
        COL_ID_INFONAME,
        COL_ID_INFOVALUE,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct INFOID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_INFOID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_INFOID]; }
        explicit INFOID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit INFOID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct INFONAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_INFONAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_INFONAME]; }
        explicit INFONAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit INFONAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct INFOVALUE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_INFOVALUE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_INFOVALUE]; }
        explicit INFOVALUE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit INFOVALUE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };
};

// A single record in database table INFOTABLE_V1
struct InfoRow
{
    using Col = InfoCol;
    using COL_ID = Col::COL_ID;

    int64 INFOID; // primary key
    wxString INFONAME;
    wxString INFOVALUE;

    explicit InfoRow();
    explicit InfoRow(wxSQLite3ResultSet& q);
    InfoRow(const InfoRow& other) = default;

    int64 id() const { return INFOID; }
    void id(const int64 id) { INFOID = id; }
    void destroy() { delete this; }

    bool equals(const InfoRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    InfoRow& operator=(const InfoRow& other);
    bool operator< (const InfoRow& other) const { return id() < other.id(); }
    bool operator< (const InfoRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::INFOID& col)
    {
        return INFOID == col.m_value;
    }

    bool match(const Col::INFONAME& col)
    {
        return INFONAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::INFOVALUE& col)
    {
        return INFOVALUE.CmpNoCase(col.m_value) == 0;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByINFOID
    {
        bool operator()(const InfoRow& x, const InfoRow& y)
        {
            return x.INFOID < y.INFOID;
        }
    };

    struct SorterByINFONAME
    {
        bool operator()(const InfoRow& x, const InfoRow& y)
        {
            return x.INFONAME < y.INFONAME;
        }
    };

    struct SorterByINFOVALUE
    {
        bool operator()(const InfoRow& x, const InfoRow& y)
        {
            return x.INFOVALUE < y.INFOVALUE;
        }
    };
};

// Interface to database table INFOTABLE_V1
struct InfoTable : public TableFactory<InfoRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using INFOID = Col::INFOID;
    using INFONAME = Col::INFONAME;
    using INFOVALUE = Col::INFOVALUE;

    InfoTable();
    ~InfoTable();

    void ensure_data() override;
};
