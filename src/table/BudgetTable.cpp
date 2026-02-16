// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      BudgetTable.cpp
 *
 *      Implementation of the interface to database table BUDGETTABLE_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "BudgetTable.h"

template class TableFactory<BudgetRow>;

// List of column names in database table BUDGETTABLE_V1,
// in the order of BudgetCol::COL_ID.
const wxArrayString BudgetCol::COL_NAME_A = {
    "BUDGETENTRYID",
    "BUDGETYEARID",
    "CATEGID",
    "PERIOD",
    "AMOUNT",
    "NOTES",
    "ACTIVE"
};

const BudgetCol::COL_ID BudgetCol::PRIMARY_ID = COL_ID_BUDGETENTRYID;
const wxString BudgetCol::PRIMARY_NAME = COL_NAME_A[COL_ID_BUDGETENTRYID];

BudgetRow::BudgetRow()
{
    BUDGETENTRYID = -1;
    BUDGETYEARID = -1;
    CATEGID = -1;
    AMOUNT = 0.0;
    ACTIVE = -1;
}

BudgetRow::BudgetRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool BudgetRow::equals(const BudgetRow* r) const
{
    if ( BUDGETENTRYID != r->BUDGETENTRYID) return false;
    if ( BUDGETYEARID != r->BUDGETYEARID) return false;
    if ( CATEGID != r->CATEGID) return false;
    if (!PERIOD.IsSameAs(r->PERIOD)) return false;
    if ( AMOUNT != r->AMOUNT) return false;
    if (!NOTES.IsSameAs(r->NOTES)) return false;
    if ( ACTIVE != r->ACTIVE) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void BudgetRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, BUDGETYEARID);
    stmt.Bind(2, CATEGID);
    stmt.Bind(3, PERIOD);
    stmt.Bind(4, AMOUNT);
    stmt.Bind(5, NOTES);
    stmt.Bind(6, ACTIVE);
    stmt.Bind(7, id);
}

void BudgetRow::from_select_result(wxSQLite3ResultSet& q)
{
    BUDGETENTRYID = q.GetInt64(0);
    BUDGETYEARID = q.GetInt64(1);
    CATEGID = q.GetInt64(2);
    PERIOD = q.GetString(3);
    AMOUNT = q.GetDouble(4);
    NOTES = q.GetString(5);
    ACTIVE = q.GetInt64(6);
}

// Return the data record as a json string
wxString BudgetRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void BudgetRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("BUDGETENTRYID");
    json_writer.Int64(BUDGETENTRYID.GetValue());

    json_writer.Key("BUDGETYEARID");
    json_writer.Int64(BUDGETYEARID.GetValue());

    json_writer.Key("CATEGID");
    json_writer.Int64(CATEGID.GetValue());

    json_writer.Key("PERIOD");
    json_writer.String(PERIOD.utf8_str());

    json_writer.Key("AMOUNT");
    json_writer.Double(AMOUNT);

    json_writer.Key("NOTES");
    json_writer.String(NOTES.utf8_str());

    json_writer.Key("ACTIVE");
    json_writer.Int64(ACTIVE.GetValue());
}

row_t BudgetRow::to_row_t() const
{
    row_t row;

    row(L"BUDGETENTRYID") = BUDGETENTRYID.GetValue();
    row(L"BUDGETYEARID") = BUDGETYEARID.GetValue();
    row(L"CATEGID") = CATEGID.GetValue();
    row(L"PERIOD") = PERIOD;
    row(L"AMOUNT") = AMOUNT;
    row(L"NOTES") = NOTES;
    row(L"ACTIVE") = ACTIVE.GetValue();

    return row;
}

void BudgetRow::to_template(html_template& t) const
{
    t(L"BUDGETENTRYID") = BUDGETENTRYID.GetValue();
    t(L"BUDGETYEARID") = BUDGETYEARID.GetValue();
    t(L"CATEGID") = CATEGID.GetValue();
    t(L"PERIOD") = PERIOD;
    t(L"AMOUNT") = AMOUNT;
    t(L"NOTES") = NOTES;
    t(L"ACTIVE") = ACTIVE.GetValue();
}

BudgetRow& BudgetRow::operator=(const BudgetRow& other)
{
    if (this == &other) return *this;

    BUDGETENTRYID = other.BUDGETENTRYID;
    BUDGETYEARID = other.BUDGETYEARID;
    CATEGID = other.CATEGID;
    PERIOD = other.PERIOD;
    AMOUNT = other.AMOUNT;
    NOTES = other.NOTES;
    ACTIVE = other.ACTIVE;

    return *this;
}

BudgetTable::BudgetTable()
{
    m_table_name = "BUDGETTABLE_V1";

    m_create_query = "CREATE TABLE BUDGETTABLE_V1(BUDGETENTRYID integer primary key, BUDGETYEARID integer, CATEGID integer, PERIOD TEXT NOT NULL /* None, Weekly, Bi-Weekly, Monthly, Monthly, Bi-Monthly, Quarterly, Half-Yearly, Yearly, Daily*/, AMOUNT numeric NOT NULL, NOTES TEXT, ACTIVE integer)";

    m_drop_query = "DROP TABLE IF EXISTS BUDGETTABLE_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_BUDGETTABLE_BUDGETYEARID ON BUDGETTABLE_V1(BUDGETYEARID)"
    };

    m_insert_query = "INSERT INTO BUDGETTABLE_V1(BUDGETYEARID, CATEGID, PERIOD, AMOUNT, NOTES, ACTIVE, BUDGETENTRYID) VALUES(?, ?, ?, ?, ?, ?, ?)";

    m_update_query = "UPDATE BUDGETTABLE_V1 SET BUDGETYEARID = ?, CATEGID = ?, PERIOD = ?, AMOUNT = ?, NOTES = ?, ACTIVE = ? WHERE BUDGETENTRYID = ?";

    m_delete_query = "DELETE FROM BUDGETTABLE_V1 WHERE BUDGETENTRYID = ?";

    m_select_query = "SELECT BUDGETENTRYID, BUDGETYEARID, CATEGID, PERIOD, AMOUNT, NOTES, ACTIVE FROM BUDGETTABLE_V1";
}

// Destructor: clears any data records stored in memory
BudgetTable::~BudgetTable()
{
    delete fake_;
    destroy_cache();
}

void BudgetTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
