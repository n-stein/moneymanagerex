// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      AccountTable.cpp
 *
 *      Implementation of the interface to database table ACCOUNTLIST_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "AccountTable.h"

template class TableFactory<AccountRow>;

// List of column names in database table ACCOUNTLIST_V1,
// in the order of AccountCol::COL_ID.
const wxArrayString AccountCol::COL_NAME_A = {
    "ACCOUNTID",
    "ACCOUNTNAME",
    "ACCOUNTTYPE",
    "ACCOUNTNUM",
    "STATUS",
    "NOTES",
    "HELDAT",
    "WEBSITE",
    "CONTACTINFO",
    "ACCESSINFO",
    "INITIALBAL",
    "INITIALDATE",
    "FAVORITEACCT",
    "CURRENCYID",
    "STATEMENTLOCKED",
    "STATEMENTDATE",
    "MINIMUMBALANCE",
    "CREDITLIMIT",
    "INTERESTRATE",
    "PAYMENTDUEDATE",
    "MINIMUMPAYMENT"
};

const AccountCol::COL_ID AccountCol::PRIMARY_ID = COL_ID_ACCOUNTID;
const wxString AccountCol::PRIMARY_NAME = COL_NAME_A[COL_ID_ACCOUNTID];

AccountRow::AccountRow()
{
    ACCOUNTID = -1;
    INITIALBAL = 0.0;
    CURRENCYID = -1;
    STATEMENTLOCKED = -1;
    MINIMUMBALANCE = 0.0;
    CREDITLIMIT = 0.0;
    INTERESTRATE = 0.0;
    MINIMUMPAYMENT = 0.0;
}

AccountRow::AccountRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool AccountRow::equals(const AccountRow* r) const
{
    if ( ACCOUNTID != r->ACCOUNTID) return false;
    if (!ACCOUNTNAME.IsSameAs(r->ACCOUNTNAME)) return false;
    if (!ACCOUNTTYPE.IsSameAs(r->ACCOUNTTYPE)) return false;
    if (!ACCOUNTNUM.IsSameAs(r->ACCOUNTNUM)) return false;
    if (!STATUS.IsSameAs(r->STATUS)) return false;
    if (!NOTES.IsSameAs(r->NOTES)) return false;
    if (!HELDAT.IsSameAs(r->HELDAT)) return false;
    if (!WEBSITE.IsSameAs(r->WEBSITE)) return false;
    if (!CONTACTINFO.IsSameAs(r->CONTACTINFO)) return false;
    if (!ACCESSINFO.IsSameAs(r->ACCESSINFO)) return false;
    if ( INITIALBAL != r->INITIALBAL) return false;
    if (!INITIALDATE.IsSameAs(r->INITIALDATE)) return false;
    if (!FAVORITEACCT.IsSameAs(r->FAVORITEACCT)) return false;
    if ( CURRENCYID != r->CURRENCYID) return false;
    if ( STATEMENTLOCKED != r->STATEMENTLOCKED) return false;
    if (!STATEMENTDATE.IsSameAs(r->STATEMENTDATE)) return false;
    if ( MINIMUMBALANCE != r->MINIMUMBALANCE) return false;
    if ( CREDITLIMIT != r->CREDITLIMIT) return false;
    if ( INTERESTRATE != r->INTERESTRATE) return false;
    if (!PAYMENTDUEDATE.IsSameAs(r->PAYMENTDUEDATE)) return false;
    if ( MINIMUMPAYMENT != r->MINIMUMPAYMENT) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void AccountRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, ACCOUNTNAME);
    stmt.Bind(2, ACCOUNTTYPE);
    stmt.Bind(3, ACCOUNTNUM);
    stmt.Bind(4, STATUS);
    stmt.Bind(5, NOTES);
    stmt.Bind(6, HELDAT);
    stmt.Bind(7, WEBSITE);
    stmt.Bind(8, CONTACTINFO);
    stmt.Bind(9, ACCESSINFO);
    stmt.Bind(10, INITIALBAL);
    stmt.Bind(11, INITIALDATE);
    stmt.Bind(12, FAVORITEACCT);
    stmt.Bind(13, CURRENCYID);
    stmt.Bind(14, STATEMENTLOCKED);
    stmt.Bind(15, STATEMENTDATE);
    stmt.Bind(16, MINIMUMBALANCE);
    stmt.Bind(17, CREDITLIMIT);
    stmt.Bind(18, INTERESTRATE);
    stmt.Bind(19, PAYMENTDUEDATE);
    stmt.Bind(20, MINIMUMPAYMENT);
    stmt.Bind(21, id);
}

void AccountRow::from_select_result(wxSQLite3ResultSet& q)
{
    ACCOUNTID = q.GetInt64(0);
    ACCOUNTNAME = q.GetString(1);
    ACCOUNTTYPE = q.GetString(2);
    ACCOUNTNUM = q.GetString(3);
    STATUS = q.GetString(4);
    NOTES = q.GetString(5);
    HELDAT = q.GetString(6);
    WEBSITE = q.GetString(7);
    CONTACTINFO = q.GetString(8);
    ACCESSINFO = q.GetString(9);
    INITIALBAL = q.GetDouble(10);
    INITIALDATE = q.GetString(11);
    FAVORITEACCT = q.GetString(12);
    CURRENCYID = q.GetInt64(13);
    STATEMENTLOCKED = q.GetInt64(14);
    STATEMENTDATE = q.GetString(15);
    MINIMUMBALANCE = q.GetDouble(16);
    CREDITLIMIT = q.GetDouble(17);
    INTERESTRATE = q.GetDouble(18);
    PAYMENTDUEDATE = q.GetString(19);
    MINIMUMPAYMENT = q.GetDouble(20);
}

// Return the data record as a json string
wxString AccountRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void AccountRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("ACCOUNTID");
    json_writer.Int64(ACCOUNTID.GetValue());

    json_writer.Key("ACCOUNTNAME");
    json_writer.String(ACCOUNTNAME.utf8_str());

    json_writer.Key("ACCOUNTTYPE");
    json_writer.String(ACCOUNTTYPE.utf8_str());

    json_writer.Key("ACCOUNTNUM");
    json_writer.String(ACCOUNTNUM.utf8_str());

    json_writer.Key("STATUS");
    json_writer.String(STATUS.utf8_str());

    json_writer.Key("NOTES");
    json_writer.String(NOTES.utf8_str());

    json_writer.Key("HELDAT");
    json_writer.String(HELDAT.utf8_str());

    json_writer.Key("WEBSITE");
    json_writer.String(WEBSITE.utf8_str());

    json_writer.Key("CONTACTINFO");
    json_writer.String(CONTACTINFO.utf8_str());

    json_writer.Key("ACCESSINFO");
    json_writer.String(ACCESSINFO.utf8_str());

    json_writer.Key("INITIALBAL");
    json_writer.Double(INITIALBAL);

    json_writer.Key("INITIALDATE");
    json_writer.String(INITIALDATE.utf8_str());

    json_writer.Key("FAVORITEACCT");
    json_writer.String(FAVORITEACCT.utf8_str());

    json_writer.Key("CURRENCYID");
    json_writer.Int64(CURRENCYID.GetValue());

    json_writer.Key("STATEMENTLOCKED");
    json_writer.Int64(STATEMENTLOCKED.GetValue());

    json_writer.Key("STATEMENTDATE");
    json_writer.String(STATEMENTDATE.utf8_str());

    json_writer.Key("MINIMUMBALANCE");
    json_writer.Double(MINIMUMBALANCE);

    json_writer.Key("CREDITLIMIT");
    json_writer.Double(CREDITLIMIT);

    json_writer.Key("INTERESTRATE");
    json_writer.Double(INTERESTRATE);

    json_writer.Key("PAYMENTDUEDATE");
    json_writer.String(PAYMENTDUEDATE.utf8_str());

    json_writer.Key("MINIMUMPAYMENT");
    json_writer.Double(MINIMUMPAYMENT);
}

row_t AccountRow::to_row_t() const
{
    row_t row;

    row(L"ACCOUNTID") = ACCOUNTID.GetValue();
    row(L"ACCOUNTNAME") = ACCOUNTNAME;
    row(L"ACCOUNTTYPE") = ACCOUNTTYPE;
    row(L"ACCOUNTNUM") = ACCOUNTNUM;
    row(L"STATUS") = STATUS;
    row(L"NOTES") = NOTES;
    row(L"HELDAT") = HELDAT;
    row(L"WEBSITE") = WEBSITE;
    row(L"CONTACTINFO") = CONTACTINFO;
    row(L"ACCESSINFO") = ACCESSINFO;
    row(L"INITIALBAL") = INITIALBAL;
    row(L"INITIALDATE") = INITIALDATE;
    row(L"FAVORITEACCT") = FAVORITEACCT;
    row(L"CURRENCYID") = CURRENCYID.GetValue();
    row(L"STATEMENTLOCKED") = STATEMENTLOCKED.GetValue();
    row(L"STATEMENTDATE") = STATEMENTDATE;
    row(L"MINIMUMBALANCE") = MINIMUMBALANCE;
    row(L"CREDITLIMIT") = CREDITLIMIT;
    row(L"INTERESTRATE") = INTERESTRATE;
    row(L"PAYMENTDUEDATE") = PAYMENTDUEDATE;
    row(L"MINIMUMPAYMENT") = MINIMUMPAYMENT;

    return row;
}

void AccountRow::to_template(html_template& t) const
{
    t(L"ACCOUNTID") = ACCOUNTID.GetValue();
    t(L"ACCOUNTNAME") = ACCOUNTNAME;
    t(L"ACCOUNTTYPE") = ACCOUNTTYPE;
    t(L"ACCOUNTNUM") = ACCOUNTNUM;
    t(L"STATUS") = STATUS;
    t(L"NOTES") = NOTES;
    t(L"HELDAT") = HELDAT;
    t(L"WEBSITE") = WEBSITE;
    t(L"CONTACTINFO") = CONTACTINFO;
    t(L"ACCESSINFO") = ACCESSINFO;
    t(L"INITIALBAL") = INITIALBAL;
    t(L"INITIALDATE") = INITIALDATE;
    t(L"FAVORITEACCT") = FAVORITEACCT;
    t(L"CURRENCYID") = CURRENCYID.GetValue();
    t(L"STATEMENTLOCKED") = STATEMENTLOCKED.GetValue();
    t(L"STATEMENTDATE") = STATEMENTDATE;
    t(L"MINIMUMBALANCE") = MINIMUMBALANCE;
    t(L"CREDITLIMIT") = CREDITLIMIT;
    t(L"INTERESTRATE") = INTERESTRATE;
    t(L"PAYMENTDUEDATE") = PAYMENTDUEDATE;
    t(L"MINIMUMPAYMENT") = MINIMUMPAYMENT;
}

AccountRow& AccountRow::operator=(const AccountRow& other)
{
    if (this == &other) return *this;

    ACCOUNTID = other.ACCOUNTID;
    ACCOUNTNAME = other.ACCOUNTNAME;
    ACCOUNTTYPE = other.ACCOUNTTYPE;
    ACCOUNTNUM = other.ACCOUNTNUM;
    STATUS = other.STATUS;
    NOTES = other.NOTES;
    HELDAT = other.HELDAT;
    WEBSITE = other.WEBSITE;
    CONTACTINFO = other.CONTACTINFO;
    ACCESSINFO = other.ACCESSINFO;
    INITIALBAL = other.INITIALBAL;
    INITIALDATE = other.INITIALDATE;
    FAVORITEACCT = other.FAVORITEACCT;
    CURRENCYID = other.CURRENCYID;
    STATEMENTLOCKED = other.STATEMENTLOCKED;
    STATEMENTDATE = other.STATEMENTDATE;
    MINIMUMBALANCE = other.MINIMUMBALANCE;
    CREDITLIMIT = other.CREDITLIMIT;
    INTERESTRATE = other.INTERESTRATE;
    PAYMENTDUEDATE = other.PAYMENTDUEDATE;
    MINIMUMPAYMENT = other.MINIMUMPAYMENT;

    return *this;
}

AccountTable::AccountTable()
{
    m_table_name = "ACCOUNTLIST_V1";

    m_create_query = "CREATE TABLE ACCOUNTLIST_V1(ACCOUNTID integer primary key, ACCOUNTNAME TEXT COLLATE NOCASE NOT NULL UNIQUE, ACCOUNTTYPE TEXT NOT NULL /* Cash, Checking, Term, Investment, Credit Card, Loan, Asset, Shares */, ACCOUNTNUM TEXT, STATUS TEXT NOT NULL /* Open, Closed */, NOTES TEXT, HELDAT TEXT, WEBSITE TEXT, CONTACTINFO TEXT, ACCESSINFO TEXT, INITIALBAL numeric, INITIALDATE TEXT, FAVORITEACCT TEXT NOT NULL, CURRENCYID integer NOT NULL, STATEMENTLOCKED integer, STATEMENTDATE TEXT, MINIMUMBALANCE numeric, CREDITLIMIT numeric, INTERESTRATE numeric, PAYMENTDUEDATE text, MINIMUMPAYMENT numeric)";

    m_drop_query = "DROP TABLE IF EXISTS ACCOUNTLIST_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_ACCOUNTLIST_ACCOUNTTYPE ON ACCOUNTLIST_V1(ACCOUNTTYPE)"
    };

    m_insert_query = "INSERT INTO ACCOUNTLIST_V1(ACCOUNTNAME, ACCOUNTTYPE, ACCOUNTNUM, STATUS, NOTES, HELDAT, WEBSITE, CONTACTINFO, ACCESSINFO, INITIALBAL, INITIALDATE, FAVORITEACCT, CURRENCYID, STATEMENTLOCKED, STATEMENTDATE, MINIMUMBALANCE, CREDITLIMIT, INTERESTRATE, PAYMENTDUEDATE, MINIMUMPAYMENT, ACCOUNTID) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    m_update_query = "UPDATE ACCOUNTLIST_V1 SET ACCOUNTNAME = ?, ACCOUNTTYPE = ?, ACCOUNTNUM = ?, STATUS = ?, NOTES = ?, HELDAT = ?, WEBSITE = ?, CONTACTINFO = ?, ACCESSINFO = ?, INITIALBAL = ?, INITIALDATE = ?, FAVORITEACCT = ?, CURRENCYID = ?, STATEMENTLOCKED = ?, STATEMENTDATE = ?, MINIMUMBALANCE = ?, CREDITLIMIT = ?, INTERESTRATE = ?, PAYMENTDUEDATE = ?, MINIMUMPAYMENT = ? WHERE ACCOUNTID = ?";

    m_delete_query = "DELETE FROM ACCOUNTLIST_V1 WHERE ACCOUNTID = ?";

    m_select_query = "SELECT ACCOUNTID, ACCOUNTNAME, ACCOUNTTYPE, ACCOUNTNUM, STATUS, NOTES, HELDAT, WEBSITE, CONTACTINFO, ACCESSINFO, INITIALBAL, INITIALDATE, FAVORITEACCT, CURRENCYID, STATEMENTLOCKED, STATEMENTDATE, MINIMUMBALANCE, CREDITLIMIT, INTERESTRATE, PAYMENTDUEDATE, MINIMUMPAYMENT FROM ACCOUNTLIST_V1";
}

// Destructor: clears any data records stored in memory
AccountTable::~AccountTable()
{
    delete fake_;
    destroy_cache();
}

void AccountTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
