// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      AccountTable.h
 *
 *      Interface to database table ACCOUNTLIST_V1
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

// Columns in database table ACCOUNTLIST_V1
struct AccountCol
{
    enum COL_ID
    {
        COL_ID_ACCOUNTID = 0,
        COL_ID_ACCOUNTNAME,
        COL_ID_ACCOUNTTYPE,
        COL_ID_ACCOUNTNUM,
        COL_ID_STATUS,
        COL_ID_NOTES,
        COL_ID_HELDAT,
        COL_ID_WEBSITE,
        COL_ID_CONTACTINFO,
        COL_ID_ACCESSINFO,
        COL_ID_INITIALBAL,
        COL_ID_INITIALDATE,
        COL_ID_FAVORITEACCT,
        COL_ID_CURRENCYID,
        COL_ID_STATEMENTLOCKED,
        COL_ID_STATEMENTDATE,
        COL_ID_MINIMUMBALANCE,
        COL_ID_CREDITLIMIT,
        COL_ID_INTERESTRATE,
        COL_ID_PAYMENTDUEDATE,
        COL_ID_MINIMUMPAYMENT,
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }

    struct ACCOUNTID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_ACCOUNTID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_ACCOUNTID]; }
        explicit ACCOUNTID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit ACCOUNTID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct ACCOUNTNAME : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_ACCOUNTNAME; }
        static wxString col_name() { return COL_NAME_A[COL_ID_ACCOUNTNAME]; }
        explicit ACCOUNTNAME(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit ACCOUNTNAME(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct ACCOUNTTYPE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_ACCOUNTTYPE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_ACCOUNTTYPE]; }
        explicit ACCOUNTTYPE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit ACCOUNTTYPE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct ACCOUNTNUM : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_ACCOUNTNUM; }
        static wxString col_name() { return COL_NAME_A[COL_ID_ACCOUNTNUM]; }
        explicit ACCOUNTNUM(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit ACCOUNTNUM(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct STATUS : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_STATUS; }
        static wxString col_name() { return COL_NAME_A[COL_ID_STATUS]; }
        explicit STATUS(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit STATUS(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct NOTES : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_NOTES; }
        static wxString col_name() { return COL_NAME_A[COL_ID_NOTES]; }
        explicit NOTES(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit NOTES(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct HELDAT : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_HELDAT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_HELDAT]; }
        explicit HELDAT(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit HELDAT(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct WEBSITE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_WEBSITE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_WEBSITE]; }
        explicit WEBSITE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit WEBSITE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct CONTACTINFO : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_CONTACTINFO; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CONTACTINFO]; }
        explicit CONTACTINFO(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit CONTACTINFO(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct ACCESSINFO : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_ACCESSINFO; }
        static wxString col_name() { return COL_NAME_A[COL_ID_ACCESSINFO]; }
        explicit ACCESSINFO(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit ACCESSINFO(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct INITIALBAL : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_INITIALBAL; }
        static wxString col_name() { return COL_NAME_A[COL_ID_INITIALBAL]; }
        explicit INITIALBAL(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit INITIALBAL(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct INITIALDATE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_INITIALDATE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_INITIALDATE]; }
        explicit INITIALDATE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit INITIALDATE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct FAVORITEACCT : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_FAVORITEACCT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_FAVORITEACCT]; }
        explicit FAVORITEACCT(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit FAVORITEACCT(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct CURRENCYID : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_CURRENCYID; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CURRENCYID]; }
        explicit CURRENCYID(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit CURRENCYID(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct STATEMENTLOCKED : public TableOpV<int64>
    {
        static COL_ID col_id() { return COL_ID_STATEMENTLOCKED; }
        static wxString col_name() { return COL_NAME_A[COL_ID_STATEMENTLOCKED]; }
        explicit STATEMENTLOCKED(const int64 &v): TableOpV<int64>(OP_EQ, v) {}
        explicit STATEMENTLOCKED(OP op, const int64 &v): TableOpV<int64>(op, v) {}
    };

    struct STATEMENTDATE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_STATEMENTDATE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_STATEMENTDATE]; }
        explicit STATEMENTDATE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit STATEMENTDATE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct MINIMUMBALANCE : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_MINIMUMBALANCE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_MINIMUMBALANCE]; }
        explicit MINIMUMBALANCE(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit MINIMUMBALANCE(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct CREDITLIMIT : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_CREDITLIMIT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_CREDITLIMIT]; }
        explicit CREDITLIMIT(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit CREDITLIMIT(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct INTERESTRATE : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_INTERESTRATE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_INTERESTRATE]; }
        explicit INTERESTRATE(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit INTERESTRATE(OP op, const double &v): TableOpV<double>(op, v) {}
    };

    struct PAYMENTDUEDATE : public TableOpV<wxString>
    {
        static COL_ID col_id() { return COL_ID_PAYMENTDUEDATE; }
        static wxString col_name() { return COL_NAME_A[COL_ID_PAYMENTDUEDATE]; }
        explicit PAYMENTDUEDATE(const wxString &v): TableOpV<wxString>(OP_EQ, v) {}
        explicit PAYMENTDUEDATE(OP op, const wxString &v): TableOpV<wxString>(op, v) {}
    };

    struct MINIMUMPAYMENT : public TableOpV<double>
    {
        static COL_ID col_id() { return COL_ID_MINIMUMPAYMENT; }
        static wxString col_name() { return COL_NAME_A[COL_ID_MINIMUMPAYMENT]; }
        explicit MINIMUMPAYMENT(const double &v): TableOpV<double>(OP_EQ, v) {}
        explicit MINIMUMPAYMENT(OP op, const double &v): TableOpV<double>(op, v) {}
    };
};

// A single record in database table ACCOUNTLIST_V1
struct AccountRow
{
    using Col = AccountCol;
    using COL_ID = Col::COL_ID;

    int64 ACCOUNTID; // primary key
    wxString ACCOUNTNAME;
    wxString ACCOUNTTYPE;
    wxString ACCOUNTNUM;
    wxString STATUS;
    wxString NOTES;
    wxString HELDAT;
    wxString WEBSITE;
    wxString CONTACTINFO;
    wxString ACCESSINFO;
    double INITIALBAL;
    wxString INITIALDATE;
    wxString FAVORITEACCT;
    int64 CURRENCYID;
    int64 STATEMENTLOCKED;
    wxString STATEMENTDATE;
    double MINIMUMBALANCE;
    double CREDITLIMIT;
    double INTERESTRATE;
    wxString PAYMENTDUEDATE;
    double MINIMUMPAYMENT;

    explicit AccountRow();
    explicit AccountRow(wxSQLite3ResultSet& q);
    AccountRow(const AccountRow& other) = default;

    int64 id() const { return ACCOUNTID; }
    void id(const int64 id) { ACCOUNTID = id; }
    void destroy() { delete this; }

    bool equals(const AccountRow* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;

    AccountRow& operator=(const AccountRow& other);
    bool operator< (const AccountRow& other) const { return id() < other.id(); }
    bool operator< (const AccountRow* other) const { return id() < other->id(); }

    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ

    bool match(const Col::ACCOUNTID& col)
    {
        return ACCOUNTID == col.m_value;
    }

    bool match(const Col::ACCOUNTNAME& col)
    {
        return ACCOUNTNAME.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::ACCOUNTTYPE& col)
    {
        return ACCOUNTTYPE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::ACCOUNTNUM& col)
    {
        return ACCOUNTNUM.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::STATUS& col)
    {
        return STATUS.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::NOTES& col)
    {
        return NOTES.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::HELDAT& col)
    {
        return HELDAT.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::WEBSITE& col)
    {
        return WEBSITE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::CONTACTINFO& col)
    {
        return CONTACTINFO.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::ACCESSINFO& col)
    {
        return ACCESSINFO.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::INITIALBAL& col)
    {
        return INITIALBAL == col.m_value;
    }

    bool match(const Col::INITIALDATE& col)
    {
        return INITIALDATE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::FAVORITEACCT& col)
    {
        return FAVORITEACCT.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::CURRENCYID& col)
    {
        return CURRENCYID == col.m_value;
    }

    bool match(const Col::STATEMENTLOCKED& col)
    {
        return STATEMENTLOCKED == col.m_value;
    }

    bool match(const Col::STATEMENTDATE& col)
    {
        return STATEMENTDATE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::MINIMUMBALANCE& col)
    {
        return MINIMUMBALANCE == col.m_value;
    }

    bool match(const Col::CREDITLIMIT& col)
    {
        return CREDITLIMIT == col.m_value;
    }

    bool match(const Col::INTERESTRATE& col)
    {
        return INTERESTRATE == col.m_value;
    }

    bool match(const Col::PAYMENTDUEDATE& col)
    {
        return PAYMENTDUEDATE.CmpNoCase(col.m_value) == 0;
    }

    bool match(const Col::MINIMUMPAYMENT& col)
    {
        return MINIMUMPAYMENT == col.m_value;
    }

    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }

    struct SorterByACCOUNTID
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.ACCOUNTID < y.ACCOUNTID;
        }
    };

    struct SorterByACCOUNTNAME
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            // Locale case-insensitive
            return std::wcscoll(x.ACCOUNTNAME.Lower().wc_str(), y.ACCOUNTNAME.Lower().wc_str()) < 0;
        }
    };

    struct SorterByACCOUNTTYPE
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.ACCOUNTTYPE < y.ACCOUNTTYPE;
        }
    };

    struct SorterByACCOUNTNUM
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.ACCOUNTNUM < y.ACCOUNTNUM;
        }
    };

    struct SorterBySTATUS
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.STATUS < y.STATUS;
        }
    };

    struct SorterByNOTES
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.NOTES < y.NOTES;
        }
    };

    struct SorterByHELDAT
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.HELDAT < y.HELDAT;
        }
    };

    struct SorterByWEBSITE
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.WEBSITE < y.WEBSITE;
        }
    };

    struct SorterByCONTACTINFO
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.CONTACTINFO < y.CONTACTINFO;
        }
    };

    struct SorterByACCESSINFO
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.ACCESSINFO < y.ACCESSINFO;
        }
    };

    struct SorterByINITIALBAL
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.INITIALBAL < y.INITIALBAL;
        }
    };

    struct SorterByINITIALDATE
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.INITIALDATE < y.INITIALDATE;
        }
    };

    struct SorterByFAVORITEACCT
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.FAVORITEACCT < y.FAVORITEACCT;
        }
    };

    struct SorterByCURRENCYID
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.CURRENCYID < y.CURRENCYID;
        }
    };

    struct SorterBySTATEMENTLOCKED
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.STATEMENTLOCKED < y.STATEMENTLOCKED;
        }
    };

    struct SorterBySTATEMENTDATE
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.STATEMENTDATE < y.STATEMENTDATE;
        }
    };

    struct SorterByMINIMUMBALANCE
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.MINIMUMBALANCE < y.MINIMUMBALANCE;
        }
    };

    struct SorterByCREDITLIMIT
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.CREDITLIMIT < y.CREDITLIMIT;
        }
    };

    struct SorterByINTERESTRATE
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.INTERESTRATE < y.INTERESTRATE;
        }
    };

    struct SorterByPAYMENTDUEDATE
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.PAYMENTDUEDATE < y.PAYMENTDUEDATE;
        }
    };

    struct SorterByMINIMUMPAYMENT
    {
        bool operator()(const AccountRow& x, const AccountRow& y)
        {
            return x.MINIMUMPAYMENT < y.MINIMUMPAYMENT;
        }
    };
};

// Interface to database table ACCOUNTLIST_V1
struct AccountTable : public TableFactory<AccountRow>
{
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.
    using ACCOUNTID = Col::ACCOUNTID;
    using ACCOUNTNAME = Col::ACCOUNTNAME;
    using ACCOUNTTYPE = Col::ACCOUNTTYPE;
    using ACCOUNTNUM = Col::ACCOUNTNUM;
    using STATUS = Col::STATUS;
    using NOTES = Col::NOTES;
    using HELDAT = Col::HELDAT;
    using WEBSITE = Col::WEBSITE;
    using CONTACTINFO = Col::CONTACTINFO;
    using ACCESSINFO = Col::ACCESSINFO;
    using INITIALBAL = Col::INITIALBAL;
    using INITIALDATE = Col::INITIALDATE;
    using FAVORITEACCT = Col::FAVORITEACCT;
    using CURRENCYID = Col::CURRENCYID;
    using STATEMENTLOCKED = Col::STATEMENTLOCKED;
    using STATEMENTDATE = Col::STATEMENTDATE;
    using MINIMUMBALANCE = Col::MINIMUMBALANCE;
    using CREDITLIMIT = Col::CREDITLIMIT;
    using INTERESTRATE = Col::INTERESTRATE;
    using PAYMENTDUEDATE = Col::PAYMENTDUEDATE;
    using MINIMUMPAYMENT = Col::MINIMUMPAYMENT;

    AccountTable();
    ~AccountTable();

    void ensure_data() override;
};
