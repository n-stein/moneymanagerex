// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      TagLinkTable.cpp
 *
 *      Implementation of the interface to database table TAGLINK_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "TagLinkTable.h"

template class TableFactory<TagLinkRow>;

// List of column names in database table TAGLINK_V1,
// in the order of TagLinkCol::COL_ID.
const wxArrayString TagLinkCol::COL_NAME_A = {
    "TAGLINKID",
    "REFTYPE",
    "REFID",
    "TAGID"
};

const TagLinkCol::COL_ID TagLinkCol::PRIMARY_ID = COL_ID_TAGLINKID;
const wxString TagLinkCol::PRIMARY_NAME = COL_NAME_A[COL_ID_TAGLINKID];

TagLinkRow::TagLinkRow()
{
    TAGLINKID = -1;
    REFID = -1;
    TAGID = -1;
}

TagLinkRow::TagLinkRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool TagLinkRow::equals(const TagLinkRow* r) const
{
    if ( TAGLINKID != r->TAGLINKID) return false;
    if (!REFTYPE.IsSameAs(r->REFTYPE)) return false;
    if ( REFID != r->REFID) return false;
    if ( TAGID != r->TAGID) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void TagLinkRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, REFTYPE);
    stmt.Bind(2, REFID);
    stmt.Bind(3, TAGID);
    stmt.Bind(4, id);
}

void TagLinkRow::from_select_result(wxSQLite3ResultSet& q)
{
    TAGLINKID = q.GetInt64(0);
    REFTYPE = q.GetString(1);
    REFID = q.GetInt64(2);
    TAGID = q.GetInt64(3);
}

// Return the data record as a json string
wxString TagLinkRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void TagLinkRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("TAGLINKID");
    json_writer.Int64(TAGLINKID.GetValue());

    json_writer.Key("REFTYPE");
    json_writer.String(REFTYPE.utf8_str());

    json_writer.Key("REFID");
    json_writer.Int64(REFID.GetValue());

    json_writer.Key("TAGID");
    json_writer.Int64(TAGID.GetValue());
}

row_t TagLinkRow::to_row_t() const
{
    row_t row;

    row(L"TAGLINKID") = TAGLINKID.GetValue();
    row(L"REFTYPE") = REFTYPE;
    row(L"REFID") = REFID.GetValue();
    row(L"TAGID") = TAGID.GetValue();

    return row;
}

void TagLinkRow::to_template(html_template& t) const
{
    t(L"TAGLINKID") = TAGLINKID.GetValue();
    t(L"REFTYPE") = REFTYPE;
    t(L"REFID") = REFID.GetValue();
    t(L"TAGID") = TAGID.GetValue();
}

TagLinkRow& TagLinkRow::operator=(const TagLinkRow& other)
{
    if (this == &other) return *this;

    TAGLINKID = other.TAGLINKID;
    REFTYPE = other.REFTYPE;
    REFID = other.REFID;
    TAGID = other.TAGID;

    return *this;
}

TagLinkTable::TagLinkTable()
{
    m_table_name = "TAGLINK_V1";

    m_create_query = "CREATE TABLE TAGLINK_V1(TAGLINKID INTEGER PRIMARY KEY, REFTYPE TEXT NOT NULL, REFID INTEGER NOT NULL, TAGID INTEGER NOT NULL, FOREIGN KEY (TAGID) REFERENCES TAG_V1 (TAGID), UNIQUE(REFTYPE, REFID, TAGID))";

    m_drop_query = "DROP TABLE IF EXISTS TAGLINK_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_TAGLINK ON TAGLINK_V1 (REFTYPE, REFID, TAGID)"
    };

    m_insert_query = "INSERT INTO TAGLINK_V1(REFTYPE, REFID, TAGID, TAGLINKID) VALUES(?, ?, ?, ?)";

    m_update_query = "UPDATE TAGLINK_V1 SET REFTYPE = ?, REFID = ?, TAGID = ? WHERE TAGLINKID = ?";

    m_delete_query = "DELETE FROM TAGLINK_V1 WHERE TAGLINKID = ?";

    m_select_query = "SELECT TAGLINKID, REFTYPE, REFID, TAGID FROM TAGLINK_V1";
}

// Destructor: clears any data records stored in memory
TagLinkTable::~TagLinkTable()
{
    delete fake_;
    destroy_cache();
}

void TagLinkTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
