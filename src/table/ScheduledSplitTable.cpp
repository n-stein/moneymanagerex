// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      ScheduledSplitTable.cpp
 *
 *      Implementation of the interface to database table BUDGETSPLITTRANSACTIONS_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "ScheduledSplitTable.h"

template class TableFactory<ScheduledSplitRow>;

// List of column names in database table BUDGETSPLITTRANSACTIONS_V1,
// in the order of ScheduledSplitCol::COL_ID.
const wxArrayString ScheduledSplitCol::COL_NAME_A = {
    "SPLITTRANSID",
    "TRANSID",
    "CATEGID",
    "SPLITTRANSAMOUNT",
    "NOTES"
};

const ScheduledSplitCol::COL_ID ScheduledSplitCol::PRIMARY_ID = COL_ID_SPLITTRANSID;
const wxString ScheduledSplitCol::PRIMARY_NAME = COL_NAME_A[COL_ID_SPLITTRANSID];

ScheduledSplitRow::ScheduledSplitRow()
{
    SPLITTRANSID = -1;
    TRANSID = -1;
    CATEGID = -1;
    SPLITTRANSAMOUNT = 0.0;
}

ScheduledSplitRow::ScheduledSplitRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool ScheduledSplitRow::equals(const ScheduledSplitRow* r) const
{
    if ( SPLITTRANSID != r->SPLITTRANSID) return false;
    if ( TRANSID != r->TRANSID) return false;
    if ( CATEGID != r->CATEGID) return false;
    if ( SPLITTRANSAMOUNT != r->SPLITTRANSAMOUNT) return false;
    if (!NOTES.IsSameAs(r->NOTES)) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void ScheduledSplitRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, TRANSID);
    stmt.Bind(2, CATEGID);
    stmt.Bind(3, SPLITTRANSAMOUNT);
    stmt.Bind(4, NOTES);
    stmt.Bind(5, id);
}

void ScheduledSplitRow::from_select_result(wxSQLite3ResultSet& q)
{
    SPLITTRANSID = q.GetInt64(0);
    TRANSID = q.GetInt64(1);
    CATEGID = q.GetInt64(2);
    SPLITTRANSAMOUNT = q.GetDouble(3);
    NOTES = q.GetString(4);
}

// Return the data record as a json string
wxString ScheduledSplitRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void ScheduledSplitRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("SPLITTRANSID");
    json_writer.Int64(SPLITTRANSID.GetValue());

    json_writer.Key("TRANSID");
    json_writer.Int64(TRANSID.GetValue());

    json_writer.Key("CATEGID");
    json_writer.Int64(CATEGID.GetValue());

    json_writer.Key("SPLITTRANSAMOUNT");
    json_writer.Double(SPLITTRANSAMOUNT);

    json_writer.Key("NOTES");
    json_writer.String(NOTES.utf8_str());
}

row_t ScheduledSplitRow::to_row_t() const
{
    row_t row;

    row(L"SPLITTRANSID") = SPLITTRANSID.GetValue();
    row(L"TRANSID") = TRANSID.GetValue();
    row(L"CATEGID") = CATEGID.GetValue();
    row(L"SPLITTRANSAMOUNT") = SPLITTRANSAMOUNT;
    row(L"NOTES") = NOTES;

    return row;
}

void ScheduledSplitRow::to_template(html_template& t) const
{
    t(L"SPLITTRANSID") = SPLITTRANSID.GetValue();
    t(L"TRANSID") = TRANSID.GetValue();
    t(L"CATEGID") = CATEGID.GetValue();
    t(L"SPLITTRANSAMOUNT") = SPLITTRANSAMOUNT;
    t(L"NOTES") = NOTES;
}

ScheduledSplitRow& ScheduledSplitRow::operator=(const ScheduledSplitRow& other)
{
    if (this == &other) return *this;

    SPLITTRANSID = other.SPLITTRANSID;
    TRANSID = other.TRANSID;
    CATEGID = other.CATEGID;
    SPLITTRANSAMOUNT = other.SPLITTRANSAMOUNT;
    NOTES = other.NOTES;

    return *this;
}

ScheduledSplitTable::ScheduledSplitTable()
{
    m_table_name = "BUDGETSPLITTRANSACTIONS_V1";

    m_create_query = "CREATE TABLE BUDGETSPLITTRANSACTIONS_V1(SPLITTRANSID integer primary key, TRANSID integer NOT NULL, CATEGID integer, SPLITTRANSAMOUNT numeric, NOTES TEXT)";

    m_drop_query = "DROP TABLE IF EXISTS BUDGETSPLITTRANSACTIONS_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_BUDGETSPLITTRANSACTIONS_TRANSID ON BUDGETSPLITTRANSACTIONS_V1(TRANSID)"
    };

    m_insert_query = "INSERT INTO BUDGETSPLITTRANSACTIONS_V1(TRANSID, CATEGID, SPLITTRANSAMOUNT, NOTES, SPLITTRANSID) VALUES(?, ?, ?, ?, ?)";

    m_update_query = "UPDATE BUDGETSPLITTRANSACTIONS_V1 SET TRANSID = ?, CATEGID = ?, SPLITTRANSAMOUNT = ?, NOTES = ? WHERE SPLITTRANSID = ?";

    m_delete_query = "DELETE FROM BUDGETSPLITTRANSACTIONS_V1 WHERE SPLITTRANSID = ?";

    m_select_query = "SELECT SPLITTRANSID, TRANSID, CATEGID, SPLITTRANSAMOUNT, NOTES FROM BUDGETSPLITTRANSACTIONS_V1";
}

// Destructor: clears any data records stored in memory
ScheduledSplitTable::~ScheduledSplitTable()
{
    delete fake_;
    destroy_cache();
}

void ScheduledSplitTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
