// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      PayeeTable.cpp
 *
 *      Implementation of the interface to database table PAYEE_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "PayeeTable.h"

template class TableFactory<PayeeRow>;

// List of column names in database table PAYEE_V1,
// in the order of PayeeCol::COL_ID.
const wxArrayString PayeeCol::COL_NAME_A = {
    "PAYEEID",
    "PAYEENAME",
    "CATEGID",
    "NUMBER",
    "WEBSITE",
    "NOTES",
    "ACTIVE",
    "PATTERN"
};

const PayeeCol::COL_ID PayeeCol::PRIMARY_ID = COL_ID_PAYEEID;
const wxString PayeeCol::PRIMARY_NAME = COL_NAME_A[COL_ID_PAYEEID];

PayeeRow::PayeeRow()
{
    PAYEEID = -1;
    CATEGID = -1;
    ACTIVE = -1;
}

PayeeRow::PayeeRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool PayeeRow::equals(const PayeeRow* r) const
{
    if ( PAYEEID != r->PAYEEID) return false;
    if (!PAYEENAME.IsSameAs(r->PAYEENAME)) return false;
    if ( CATEGID != r->CATEGID) return false;
    if (!NUMBER.IsSameAs(r->NUMBER)) return false;
    if (!WEBSITE.IsSameAs(r->WEBSITE)) return false;
    if (!NOTES.IsSameAs(r->NOTES)) return false;
    if ( ACTIVE != r->ACTIVE) return false;
    if (!PATTERN.IsSameAs(r->PATTERN)) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void PayeeRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, PAYEENAME);
    stmt.Bind(2, CATEGID);
    stmt.Bind(3, NUMBER);
    stmt.Bind(4, WEBSITE);
    stmt.Bind(5, NOTES);
    stmt.Bind(6, ACTIVE);
    stmt.Bind(7, PATTERN);
    stmt.Bind(8, id);
}

void PayeeRow::from_select_result(wxSQLite3ResultSet& q)
{
    PAYEEID = q.GetInt64(0);
    PAYEENAME = q.GetString(1);
    CATEGID = q.GetInt64(2);
    NUMBER = q.GetString(3);
    WEBSITE = q.GetString(4);
    NOTES = q.GetString(5);
    ACTIVE = q.GetInt64(6);
    PATTERN = q.GetString(7);
}

// Return the data record as a json string
wxString PayeeRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void PayeeRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("PAYEEID");
    json_writer.Int64(PAYEEID.GetValue());

    json_writer.Key("PAYEENAME");
    json_writer.String(PAYEENAME.utf8_str());

    json_writer.Key("CATEGID");
    json_writer.Int64(CATEGID.GetValue());

    json_writer.Key("NUMBER");
    json_writer.String(NUMBER.utf8_str());

    json_writer.Key("WEBSITE");
    json_writer.String(WEBSITE.utf8_str());

    json_writer.Key("NOTES");
    json_writer.String(NOTES.utf8_str());

    json_writer.Key("ACTIVE");
    json_writer.Int64(ACTIVE.GetValue());

    json_writer.Key("PATTERN");
    json_writer.String(PATTERN.utf8_str());
}

row_t PayeeRow::to_row_t() const
{
    row_t row;

    row(L"PAYEEID") = PAYEEID.GetValue();
    row(L"PAYEENAME") = PAYEENAME;
    row(L"CATEGID") = CATEGID.GetValue();
    row(L"NUMBER") = NUMBER;
    row(L"WEBSITE") = WEBSITE;
    row(L"NOTES") = NOTES;
    row(L"ACTIVE") = ACTIVE.GetValue();
    row(L"PATTERN") = PATTERN;

    return row;
}

void PayeeRow::to_template(html_template& t) const
{
    t(L"PAYEEID") = PAYEEID.GetValue();
    t(L"PAYEENAME") = PAYEENAME;
    t(L"CATEGID") = CATEGID.GetValue();
    t(L"NUMBER") = NUMBER;
    t(L"WEBSITE") = WEBSITE;
    t(L"NOTES") = NOTES;
    t(L"ACTIVE") = ACTIVE.GetValue();
    t(L"PATTERN") = PATTERN;
}

PayeeRow& PayeeRow::operator=(const PayeeRow& other)
{
    if (this == &other) return *this;

    PAYEEID = other.PAYEEID;
    PAYEENAME = other.PAYEENAME;
    CATEGID = other.CATEGID;
    NUMBER = other.NUMBER;
    WEBSITE = other.WEBSITE;
    NOTES = other.NOTES;
    ACTIVE = other.ACTIVE;
    PATTERN = other.PATTERN;

    return *this;
}

PayeeTable::PayeeTable()
{
    m_table_name = "PAYEE_V1";

    m_create_query = "CREATE TABLE PAYEE_V1(PAYEEID integer primary key, PAYEENAME TEXT COLLATE NOCASE NOT NULL UNIQUE, CATEGID integer, NUMBER TEXT, WEBSITE TEXT, NOTES TEXT, ACTIVE integer, PATTERN TEXT DEFAULT '')";

    m_drop_query = "DROP TABLE IF EXISTS PAYEE_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_PAYEE_INFONAME ON PAYEE_V1(PAYEENAME)"
    };

    m_insert_query = "INSERT INTO PAYEE_V1(PAYEENAME, CATEGID, NUMBER, WEBSITE, NOTES, ACTIVE, PATTERN, PAYEEID) VALUES(?, ?, ?, ?, ?, ?, ?, ?)";

    m_update_query = "UPDATE PAYEE_V1 SET PAYEENAME = ?, CATEGID = ?, NUMBER = ?, WEBSITE = ?, NOTES = ?, ACTIVE = ?, PATTERN = ? WHERE PAYEEID = ?";

    m_delete_query = "DELETE FROM PAYEE_V1 WHERE PAYEEID = ?";

    m_select_query = "SELECT PAYEEID, PAYEENAME, CATEGID, NUMBER, WEBSITE, NOTES, ACTIVE, PATTERN FROM PAYEE_V1";
}

// Destructor: clears any data records stored in memory
PayeeTable::~PayeeTable()
{
    delete fake_;
    destroy_cache();
}

void PayeeTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
