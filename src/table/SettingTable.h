// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      SettingTable.h
 *
 *      Interface to database table SETTING_V1
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

// Columns in database table SETTING_V1
struct SettingCol
{
    enum COL_ID
    {
        COL_ID_SETTINGID = 0,
        COL_ID_SETTINGNAME,
        COL_ID_SETTINGVALUE,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct SETTINGID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_SETTINGID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_SETTINGID]; }
        explicit SETTINGID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit SETTINGID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct SETTINGNAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_SETTINGNAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_SETTINGNAME]; }
        explicit SETTINGNAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit SETTINGNAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct SETTINGVALUE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_SETTINGVALUE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_SETTINGVALUE]; }
        explicit SETTINGVALUE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit SETTINGVALUE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };
};

// A single record in database table SETTING_V1
struct SettingRow
{
    using Col = SettingCol;
    using COL_ID = Col::COL_ID;

    int64 SETTINGID; // primary key
    wxString SETTINGNAME;
    wxString SETTINGVALUE;

    explicit SettingRow();
    explicit SettingRow(wxSQLite3ResultSet& q);
    SettingRow(const SettingRow& other) = default;

    int64 id() const { return SETTINGID; }
    void id(const int64 id) { SETTINGID = id; }
    void destroy() { delete this; }

    bool equals(const SettingRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    SettingRow& operator=(const SettingRow& other);
    bool operator< (const SettingRow& other) const { return id() < other.id(); }
    bool operator< (const SettingRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::SETTINGID& col)
    {
        return SETTINGID == col.m_value;
    }

    bool match(const Col::SETTINGNAME& col)
    {
        return SETTINGNAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::SETTINGVALUE& col)
    {
        return SETTINGVALUE.CmpNoCase(col.m_value) == 0;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterBySETTINGID
    {
        bool operator()(const SettingRow& x, const SettingRow& y)
        {
            return x.SETTINGID < y.SETTINGID;
        }
    };

    struct SorterBySETTINGNAME
    {
        bool operator()(const SettingRow& x, const SettingRow& y)
        {
            return x.SETTINGNAME < y.SETTINGNAME;
        }
    };

    struct SorterBySETTINGVALUE
    {
        bool operator()(const SettingRow& x, const SettingRow& y)
        {
            return x.SETTINGVALUE < y.SETTINGVALUE;
        }
    };
};

// Interface to database table SETTING_V1
struct SettingTable : public TableFactory<SettingRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using SETTINGID = Col::SETTINGID;
    using SETTINGNAME = Col::SETTINGNAME;
    using SETTINGVALUE = Col::SETTINGVALUE;

    SettingTable();
    ~SettingTable();

    void ensure_data() override;
};
