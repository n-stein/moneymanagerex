// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      CategoryTable.h
 *
 *      Interface to database table CATEGORY_V1
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

// Columns in database table CATEGORY_V1
struct CategoryCol
{
    enum COL_ID
    {
        COL_ID_CATEGID = 0,
        COL_ID_CATEGNAME,
        COL_ID_ACTIVE,
        COL_ID_PARENTID,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct CATEGID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_CATEGID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CATEGID]; }
        explicit CATEGID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit CATEGID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct CATEGNAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_CATEGNAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CATEGNAME]; }
        explicit CATEGNAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit CATEGNAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct ACTIVE : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_ACTIVE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_ACTIVE]; }
        explicit ACTIVE(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit ACTIVE(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct PARENTID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_PARENTID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_PARENTID]; }
        explicit PARENTID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit PARENTID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };
};

// A single record in database table CATEGORY_V1
struct CategoryRow
{
    using Col = CategoryCol;
    using COL_ID = Col::COL_ID;

    int64 CATEGID; // primary key
    wxString CATEGNAME;
    int64 ACTIVE;
    int64 PARENTID;

    explicit CategoryRow();
    explicit CategoryRow(wxSQLite3ResultSet& q);
    CategoryRow(const CategoryRow& other) = default;

    int64 id() const { return CATEGID; }
    void id(const int64 id) { CATEGID = id; }
    void destroy() { delete this; }

    bool equals(const CategoryRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    CategoryRow& operator=(const CategoryRow& other);
    bool operator< (const CategoryRow& other) const { return id() < other.id(); }
    bool operator< (const CategoryRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::CATEGID& col)
    {
        return CATEGID == col.m_value;
    }

    bool match(const Col::CATEGNAME& col)
    {
        return CATEGNAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::ACTIVE& col)
    {
        return ACTIVE == col.m_value;
    }

    bool match(const Col::PARENTID& col)
    {
        return PARENTID == col.m_value;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByCATEGID
    {
        bool operator()(const CategoryRow& x, const CategoryRow& y)
        {
            return x.CATEGID < y.CATEGID;
        }
    };

    struct SorterByCATEGNAME
    {
        bool operator()(const CategoryRow& x, const CategoryRow& y)
        {
            // Locale case-insensitive
            return std::wcscoll(x.CATEGNAME.Lower().wc_str(), y.CATEGNAME.Lower().wc_str()) < 0;
        }
    };

    struct SorterByACTIVE
    {
        bool operator()(const CategoryRow& x, const CategoryRow& y)
        {
            return x.ACTIVE < y.ACTIVE;
        }
    };

    struct SorterByPARENTID
    {
        bool operator()(const CategoryRow& x, const CategoryRow& y)
        {
            return x.PARENTID < y.PARENTID;
        }
    };
};

// Interface to database table CATEGORY_V1
struct CategoryTable : public TableFactory<CategoryRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using CATEGID = Col::CATEGID;
    using CATEGNAME = Col::CATEGNAME;
    using ACTIVE = Col::ACTIVE;
    using PARENTID = Col::PARENTID;

    CategoryTable();
    ~CategoryTable();

    void ensure_data() override;
};
