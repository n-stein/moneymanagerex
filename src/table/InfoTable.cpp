// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      InfoTable.cpp
 *
 *      Implementation of the interface to database table INFOTABLE_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "InfoTable.h"

template class TableFactory<InfoRow>;

// List of column names in database table INFOTABLE_V1,
// in the order of InfoCol::COL_ID.
const wxArrayString InfoCol::COL_NAME_A = {
    "INFOID",
    "INFONAME",
    "INFOVALUE"
};

const InfoCol::COL_ID InfoCol::PRIMARY_ID = COL_ID_INFOID;
const wxString InfoCol::PRIMARY_NAME = COL_NAME_A[COL_ID_INFOID];

InfoRow::InfoRow()
{
    INFOID = -1;
}

InfoRow::InfoRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool InfoRow::equals(const InfoRow* r) const
{
    if ( INFOID != r->INFOID) return false;
    if (!INFONAME.IsSameAs(r->INFONAME)) return false;
    if (!INFOVALUE.IsSameAs(r->INFOVALUE)) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void InfoRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, INFONAME);
    stmt.Bind(2, INFOVALUE);
    stmt.Bind(3, id);
}

void InfoRow::from_select_result(wxSQLite3ResultSet& q)
{
    INFOID = q.GetInt64(0);
    INFONAME = q.GetString(1);
    INFOVALUE = q.GetString(2);
}

// Return the data record as a json string
wxString InfoRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void InfoRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("INFOID");
    json_writer.Int64(INFOID.GetValue());

    json_writer.Key("INFONAME");
    json_writer.String(INFONAME.utf8_str());

    json_writer.Key("INFOVALUE");
    json_writer.String(INFOVALUE.utf8_str());
}

row_t InfoRow::to_row_t() const
{
    row_t row;

    row(L"INFOID") = INFOID.GetValue();
    row(L"INFONAME") = INFONAME;
    row(L"INFOVALUE") = INFOVALUE;

    return row;
}

void InfoRow::to_template(html_template& t) const
{
    t(L"INFOID") = INFOID.GetValue();
    t(L"INFONAME") = INFONAME;
    t(L"INFOVALUE") = INFOVALUE;
}

InfoRow& InfoRow::operator=(const InfoRow& other)
{
    if (this == &other) return *this;

    INFOID = other.INFOID;
    INFONAME = other.INFONAME;
    INFOVALUE = other.INFOVALUE;

    return *this;
}

InfoTable::InfoTable()
{
    m_table_name = "INFOTABLE_V1";

    m_create_query = "CREATE TABLE INFOTABLE_V1(INFOID integer not null primary key, INFONAME TEXT COLLATE NOCASE NOT NULL UNIQUE, INFOVALUE TEXT NOT NULL)";

    m_drop_query = "DROP TABLE IF EXISTS INFOTABLE_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_INFOTABLE_INFONAME ON INFOTABLE_V1(INFONAME)"
    };

    m_insert_query = "INSERT INTO INFOTABLE_V1(INFONAME, INFOVALUE, INFOID) VALUES(?, ?, ?)";

    m_update_query = "UPDATE INFOTABLE_V1 SET INFONAME = ?, INFOVALUE = ? WHERE INFOID = ?";

    m_delete_query = "DELETE FROM INFOTABLE_V1 WHERE INFOID = ?";

    m_select_query = "SELECT INFOID, INFONAME, INFOVALUE FROM INFOTABLE_V1";
}

// Destructor: clears any data records stored in memory
InfoTable::~InfoTable()
{
    delete fake_;
    destroy_cache();
}

void InfoTable::ensure_data()
{
    m_db->Begin();
    m_db->ExecuteUpdate("INSERT INTO INFOTABLE_V1 VALUES ('1', 'DATAVERSION', '3')");
    m_db->Commit();
}
