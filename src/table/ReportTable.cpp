// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      ReportTable.cpp
 *
 *      Implementation of the interface to database table REPORT_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "ReportTable.h"

template class TableFactory<ReportRow>;

// List of column names in database table REPORT_V1,
// in the order of ReportCol::COL_ID.
const wxArrayString ReportCol::COL_NAME_A = {
    "REPORTID",
    "REPORTNAME",
    "GROUPNAME",
    "ACTIVE",
    "SQLCONTENT",
    "LUACONTENT",
    "TEMPLATECONTENT",
    "DESCRIPTION"
};

const ReportCol::COL_ID ReportCol::PRIMARY_ID = COL_ID_REPORTID;
const wxString ReportCol::PRIMARY_NAME = COL_NAME_A[COL_ID_REPORTID];

ReportRow::ReportRow()
{
    REPORTID = -1;
    ACTIVE = -1;
}

ReportRow::ReportRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool ReportRow::equals(const ReportRow* r) const
{
    if ( REPORTID != r->REPORTID) return false;
    if (!REPORTNAME.IsSameAs(r->REPORTNAME)) return false;
    if (!GROUPNAME.IsSameAs(r->GROUPNAME)) return false;
    if ( ACTIVE != r->ACTIVE) return false;
    if (!SQLCONTENT.IsSameAs(r->SQLCONTENT)) return false;
    if (!LUACONTENT.IsSameAs(r->LUACONTENT)) return false;
    if (!TEMPLATECONTENT.IsSameAs(r->TEMPLATECONTENT)) return false;
    if (!DESCRIPTION.IsSameAs(r->DESCRIPTION)) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void ReportRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, REPORTNAME);
    stmt.Bind(2, GROUPNAME);
    stmt.Bind(3, ACTIVE);
    stmt.Bind(4, SQLCONTENT);
    stmt.Bind(5, LUACONTENT);
    stmt.Bind(6, TEMPLATECONTENT);
    stmt.Bind(7, DESCRIPTION);
    stmt.Bind(8, id);
}

void ReportRow::from_select_result(wxSQLite3ResultSet& q)
{
    REPORTID = q.GetInt64(0);
    REPORTNAME = q.GetString(1);
    GROUPNAME = q.GetString(2);
    ACTIVE = q.GetInt64(3);
    SQLCONTENT = q.GetString(4);
    LUACONTENT = q.GetString(5);
    TEMPLATECONTENT = q.GetString(6);
    DESCRIPTION = q.GetString(7);
}

// Return the data record as a json string
wxString ReportRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void ReportRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("REPORTID");
    json_writer.Int64(REPORTID.GetValue());

    json_writer.Key("REPORTNAME");
    json_writer.String(REPORTNAME.utf8_str());

    json_writer.Key("GROUPNAME");
    json_writer.String(GROUPNAME.utf8_str());

    json_writer.Key("ACTIVE");
    json_writer.Int64(ACTIVE.GetValue());

    json_writer.Key("SQLCONTENT");
    json_writer.String(SQLCONTENT.utf8_str());

    json_writer.Key("LUACONTENT");
    json_writer.String(LUACONTENT.utf8_str());

    json_writer.Key("TEMPLATECONTENT");
    json_writer.String(TEMPLATECONTENT.utf8_str());

    json_writer.Key("DESCRIPTION");
    json_writer.String(DESCRIPTION.utf8_str());
}

row_t ReportRow::to_row_t() const
{
    row_t row;

    row(L"REPORTID") = REPORTID.GetValue();
    row(L"REPORTNAME") = REPORTNAME;
    row(L"GROUPNAME") = GROUPNAME;
    row(L"ACTIVE") = ACTIVE.GetValue();
    row(L"SQLCONTENT") = SQLCONTENT;
    row(L"LUACONTENT") = LUACONTENT;
    row(L"TEMPLATECONTENT") = TEMPLATECONTENT;
    row(L"DESCRIPTION") = DESCRIPTION;

    return row;
}

void ReportRow::to_template(html_template& t) const
{
    t(L"REPORTID") = REPORTID.GetValue();
    t(L"REPORTNAME") = REPORTNAME;
    t(L"GROUPNAME") = GROUPNAME;
    t(L"ACTIVE") = ACTIVE.GetValue();
    t(L"SQLCONTENT") = SQLCONTENT;
    t(L"LUACONTENT") = LUACONTENT;
    t(L"TEMPLATECONTENT") = TEMPLATECONTENT;
    t(L"DESCRIPTION") = DESCRIPTION;
}

ReportRow& ReportRow::operator=(const ReportRow& other)
{
    if (this == &other) return *this;

    REPORTID = other.REPORTID;
    REPORTNAME = other.REPORTNAME;
    GROUPNAME = other.GROUPNAME;
    ACTIVE = other.ACTIVE;
    SQLCONTENT = other.SQLCONTENT;
    LUACONTENT = other.LUACONTENT;
    TEMPLATECONTENT = other.TEMPLATECONTENT;
    DESCRIPTION = other.DESCRIPTION;

    return *this;
}

ReportTable::ReportTable()
{
    m_table_name = "REPORT_V1";

    m_create_query = "CREATE TABLE REPORT_V1(REPORTID integer not null primary key, REPORTNAME TEXT COLLATE NOCASE NOT NULL UNIQUE, GROUPNAME TEXT COLLATE NOCASE, ACTIVE integer, SQLCONTENT TEXT, LUACONTENT TEXT, TEMPLATECONTENT TEXT, DESCRIPTION TEXT)";

    m_drop_query = "DROP TABLE IF EXISTS REPORT_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS INDEX_REPORT_NAME ON REPORT_V1(REPORTNAME)"
    };

    m_insert_query = "INSERT INTO REPORT_V1(REPORTNAME, GROUPNAME, ACTIVE, SQLCONTENT, LUACONTENT, TEMPLATECONTENT, DESCRIPTION, REPORTID) VALUES(?, ?, ?, ?, ?, ?, ?, ?)";

    m_update_query = "UPDATE REPORT_V1 SET REPORTNAME = ?, GROUPNAME = ?, ACTIVE = ?, SQLCONTENT = ?, LUACONTENT = ?, TEMPLATECONTENT = ?, DESCRIPTION = ? WHERE REPORTID = ?";

    m_delete_query = "DELETE FROM REPORT_V1 WHERE REPORTID = ?";

    m_select_query = "SELECT REPORTID, REPORTNAME, GROUPNAME, ACTIVE, SQLCONTENT, LUACONTENT, TEMPLATECONTENT, DESCRIPTION FROM REPORT_V1";
}

// Destructor: clears any data records stored in memory
ReportTable::~ReportTable()
{
    delete fake_;
    destroy_cache();
}

void ReportTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
