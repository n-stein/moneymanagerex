// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      CurrencyTable.h
 *
 *      Interface to database table CURRENCYFORMATS_V1
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

// Columns in database table CURRENCYFORMATS_V1
struct CurrencyCol
{
    enum COL_ID
    {
        COL_ID_CURRENCYID = 0,
        COL_ID_CURRENCYNAME,
        COL_ID_PFX_SYMBOL,
        COL_ID_SFX_SYMBOL,
        COL_ID_DECIMAL_POINT,
        COL_ID_GROUP_SEPARATOR,
        COL_ID_UNIT_NAME,
        COL_ID_CENT_NAME,
        COL_ID_SCALE,
        COL_ID_BASECONVRATE,
        COL_ID_CURRENCY_SYMBOL,
        COL_ID_CURRENCY_TYPE,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct CURRENCYID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_CURRENCYID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRENCYID]; }
        explicit CURRENCYID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit CURRENCYID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct CURRENCYNAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_CURRENCYNAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRENCYNAME]; }
        explicit CURRENCYNAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit CURRENCYNAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct PFX_SYMBOL : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_PFX_SYMBOL; }
        static wxString col_name() { return COL_NAME_A[COL_ID_PFX_SYMBOL]; }
        explicit PFX_SYMBOL(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit PFX_SYMBOL(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct SFX_SYMBOL : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_SFX_SYMBOL; }
        static wxString col_name() { return COL_NAME_A[COL_ID_SFX_SYMBOL]; }
        explicit SFX_SYMBOL(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit SFX_SYMBOL(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct DECIMAL_POINT : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_DECIMAL_POINT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_DECIMAL_POINT]; }
        explicit DECIMAL_POINT(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit DECIMAL_POINT(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct GROUP_SEPARATOR : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_GROUP_SEPARATOR; }
        static wxString col_name() { return COL_NAME_A[COL_ID_GROUP_SEPARATOR]; }
        explicit GROUP_SEPARATOR(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit GROUP_SEPARATOR(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct UNIT_NAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_UNIT_NAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_UNIT_NAME]; }
        explicit UNIT_NAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit UNIT_NAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct CENT_NAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_CENT_NAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CENT_NAME]; }
        explicit CENT_NAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit CENT_NAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct SCALE : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_SCALE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_SCALE]; }
        explicit SCALE(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit SCALE(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct BASECONVRATE : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_BASECONVRATE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_BASECONVRATE]; }
        explicit BASECONVRATE(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit BASECONVRATE(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct CURRENCY_SYMBOL : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_CURRENCY_SYMBOL; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRENCY_SYMBOL]; }
        explicit CURRENCY_SYMBOL(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit CURRENCY_SYMBOL(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct CURRENCY_TYPE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_CURRENCY_TYPE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRENCY_TYPE]; }
        explicit CURRENCY_TYPE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit CURRENCY_TYPE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };
};

// A single record in database table CURRENCYFORMATS_V1
struct CurrencyRow
{
    using Col = CurrencyCol;
    using COL_ID = Col::COL_ID;

    int64 CURRENCYID; // primary key
    wxString CURRENCYNAME;
    wxString PFX_SYMBOL;
    wxString SFX_SYMBOL;
    wxString DECIMAL_POINT;
    wxString GROUP_SEPARATOR;
    wxString UNIT_NAME;
    wxString CENT_NAME;
    int64 SCALE;
    double BASECONVRATE;
    wxString CURRENCY_SYMBOL;
    wxString CURRENCY_TYPE;

    explicit CurrencyRow();
    explicit CurrencyRow(wxSQLite3ResultSet& q);
    CurrencyRow(const CurrencyRow& other) = default;

    int64 id() const { return CURRENCYID; }
    void id(const int64 id) { CURRENCYID = id; }
    void destroy() { delete this; }

    bool equals(const CurrencyRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    CurrencyRow& operator=(const CurrencyRow& other);
    bool operator< (const CurrencyRow& other) const { return id() < other.id(); }
    bool operator< (const CurrencyRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::CURRENCYID& col)
    {
        return CURRENCYID == col.m_value;
    }

    bool match(const Col::CURRENCYNAME& col)
    {
        return CURRENCYNAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::PFX_SYMBOL& col)
    {
        return PFX_SYMBOL.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::SFX_SYMBOL& col)
    {
        return SFX_SYMBOL.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::DECIMAL_POINT& col)
    {
        return DECIMAL_POINT.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::GROUP_SEPARATOR& col)
    {
        return GROUP_SEPARATOR.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::UNIT_NAME& col)
    {
        return UNIT_NAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::CENT_NAME& col)
    {
        return CENT_NAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::SCALE& col)
    {
        return SCALE == col.m_value;
    }

    bool match(const Col::BASECONVRATE& col)
    {
        return BASECONVRATE == col.m_value;
    }

    bool match(const Col::CURRENCY_SYMBOL& col)
    {
        return CURRENCY_SYMBOL.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::CURRENCY_TYPE& col)
    {
        return CURRENCY_TYPE.CmpNoCase(col.m_value) == 0;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByCURRENCYID
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.CURRENCYID < y.CURRENCYID;
        }
    };

    struct SorterByCURRENCYNAME
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return wxGetTranslation(x.CURRENCYNAME) < wxGetTranslation(y.CURRENCYNAME);
        }
    };

    struct SorterByPFX_SYMBOL
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.PFX_SYMBOL < y.PFX_SYMBOL;
        }
    };

    struct SorterBySFX_SYMBOL
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.SFX_SYMBOL < y.SFX_SYMBOL;
        }
    };

    struct SorterByDECIMAL_POINT
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.DECIMAL_POINT < y.DECIMAL_POINT;
        }
    };

    struct SorterByGROUP_SEPARATOR
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.GROUP_SEPARATOR < y.GROUP_SEPARATOR;
        }
    };

    struct SorterByUNIT_NAME
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.UNIT_NAME < y.UNIT_NAME;
        }
    };

    struct SorterByCENT_NAME
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.CENT_NAME < y.CENT_NAME;
        }
    };

    struct SorterBySCALE
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.SCALE < y.SCALE;
        }
    };

    struct SorterByBASECONVRATE
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.BASECONVRATE < y.BASECONVRATE;
        }
    };

    struct SorterByCURRENCY_SYMBOL
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.CURRENCY_SYMBOL < y.CURRENCY_SYMBOL;
        }
    };

    struct SorterByCURRENCY_TYPE
    {
        bool operator()(const CurrencyRow& x, const CurrencyRow& y)
        {
            return x.CURRENCY_TYPE < y.CURRENCY_TYPE;
        }
    };
};

// Interface to database table CURRENCYFORMATS_V1
struct CurrencyTable : public TableFactory<CurrencyRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using CURRENCYID = Col::CURRENCYID;
    using CURRENCYNAME = Col::CURRENCYNAME;
    using PFX_SYMBOL = Col::PFX_SYMBOL;
    using SFX_SYMBOL = Col::SFX_SYMBOL;
    using DECIMAL_POINT = Col::DECIMAL_POINT;
    using GROUP_SEPARATOR = Col::GROUP_SEPARATOR;
    using UNIT_NAME = Col::UNIT_NAME;
    using CENT_NAME = Col::CENT_NAME;
    using SCALE = Col::SCALE;
    using BASECONVRATE = Col::BASECONVRATE;
    using CURRENCY_SYMBOL = Col::CURRENCY_SYMBOL;
    using CURRENCY_TYPE = Col::CURRENCY_TYPE;

    CurrencyTable();
    ~CurrencyTable();

    void ensure_data() override;
};
