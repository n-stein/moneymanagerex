// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      TagTable.cpp
 *
 *      Implementation of the interface to database table TAG_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "TagTable.h"

template class TableFactory<TagRow>;

// List of column names in database table TAG_V1,
// in the order of TagCol::COL_ID.
const wxArrayString TagCol::COL_NAME_A = {
    "TAGID",
    "TAGNAME",
    "ACTIVE"
};

const TagCol::COL_ID TagCol::PRIMARY_ID = COL_ID_TAGID;
const wxString TagCol::PRIMARY_NAME = COL_NAME_A[COL_ID_TAGID];

TagRow::TagRow()
{
    TAGID = -1;
    ACTIVE = -1;
}

TagRow::TagRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool TagRow::equals(const TagRow* r) const
{
    if ( TAGID != r->TAGID) return false;
    if (!TAGNAME.IsSameAs(r->TAGNAME)) return false;
    if ( ACTIVE != r->ACTIVE) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void TagRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, TAGNAME);
    stmt.Bind(2, ACTIVE);
    stmt.Bind(3, id);
}

void TagRow::from_select_result(wxSQLite3ResultSet& q)
{
    TAGID = q.GetInt64(0);
    TAGNAME = q.GetString(1);
    ACTIVE = q.GetInt64(2);
}

// Return the data record as a json string
wxString TagRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void TagRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("TAGID");
    json_writer.Int64(TAGID.GetValue());

    json_writer.Key("TAGNAME");
    json_writer.String(TAGNAME.utf8_str());

    json_writer.Key("ACTIVE");
    json_writer.Int64(ACTIVE.GetValue());
}

row_t TagRow::to_row_t() const
{
    row_t row;

    row(L"TAGID") = TAGID.GetValue();
    row(L"TAGNAME") = TAGNAME;
    row(L"ACTIVE") = ACTIVE.GetValue();

    return row;
}

void TagRow::to_template(html_template& t) const
{
    t(L"TAGID") = TAGID.GetValue();
    t(L"TAGNAME") = TAGNAME;
    t(L"ACTIVE") = ACTIVE.GetValue();
}

TagRow& TagRow::operator=(const TagRow& other)
{
    if (this == &other) return *this;

    TAGID = other.TAGID;
    TAGNAME = other.TAGNAME;
    ACTIVE = other.ACTIVE;

    return *this;
}

TagTable::TagTable()
{
    m_table_name = "TAG_V1";

    m_create_query = "CREATE TABLE TAG_V1(TAGID INTEGER PRIMARY KEY, TAGNAME TEXT COLLATE NOCASE NOT NULL UNIQUE, ACTIVE INTEGER)";

    m_drop_query = "DROP TABLE IF EXISTS TAG_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_TAGNAME ON TAG_V1 (TAGNAME)"
    };

    m_insert_query = "INSERT INTO TAG_V1(TAGNAME, ACTIVE, TAGID) VALUES(?, ?, ?)";

    m_update_query = "UPDATE TAG_V1 SET TAGNAME = ?, ACTIVE = ? WHERE TAGID = ?";

    m_delete_query = "DELETE FROM TAG_V1 WHERE TAGID = ?";

    m_select_query = "SELECT TAGID, TAGNAME, ACTIVE FROM TAG_V1";
}

// Destructor: clears any data records stored in memory
TagTable::~TagTable()
{
    delete fake_;
    destroy_cache();
}

void TagTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
