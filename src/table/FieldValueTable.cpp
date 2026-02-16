// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      FieldValueTable.cpp
 *
 *      Implementation of the interface to database table CUSTOMFIELDDATA_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "FieldValueTable.h"

template class TableFactory<FieldValueRow>;

// List of column names in database table CUSTOMFIELDDATA_V1,
// in the order of FieldValueCol::COL_ID.
const wxArrayString FieldValueCol::COL_NAME_A = {
    "FIELDATADID",
    "FIELDID",
    "REFID",
    "CONTENT"
};

const FieldValueCol::COL_ID FieldValueCol::PRIMARY_ID = COL_ID_FIELDATADID;
const wxString FieldValueCol::PRIMARY_NAME = COL_NAME_A[COL_ID_FIELDATADID];

FieldValueRow::FieldValueRow()
{
    FIELDATADID = -1;
    FIELDID = -1;
    REFID = -1;
}

FieldValueRow::FieldValueRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool FieldValueRow::equals(const FieldValueRow* r) const
{
    if ( FIELDATADID != r->FIELDATADID) return false;
    if ( FIELDID != r->FIELDID) return false;
    if ( REFID != r->REFID) return false;
    if (!CONTENT.IsSameAs(r->CONTENT)) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void FieldValueRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, FIELDID);
    stmt.Bind(2, REFID);
    stmt.Bind(3, CONTENT);
    stmt.Bind(4, id);
}

void FieldValueRow::from_select_result(wxSQLite3ResultSet& q)
{
    FIELDATADID = q.GetInt64(0);
    FIELDID = q.GetInt64(1);
    REFID = q.GetInt64(2);
    CONTENT = q.GetString(3);
}

// Return the data record as a json string
wxString FieldValueRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void FieldValueRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("FIELDATADID");
    json_writer.Int64(FIELDATADID.GetValue());

    json_writer.Key("FIELDID");
    json_writer.Int64(FIELDID.GetValue());

    json_writer.Key("REFID");
    json_writer.Int64(REFID.GetValue());

    json_writer.Key("CONTENT");
    json_writer.String(CONTENT.utf8_str());
}

row_t FieldValueRow::to_row_t() const
{
    row_t row;

    row(L"FIELDATADID") = FIELDATADID.GetValue();
    row(L"FIELDID") = FIELDID.GetValue();
    row(L"REFID") = REFID.GetValue();
    row(L"CONTENT") = CONTENT;

    return row;
}

void FieldValueRow::to_template(html_template& t) const
{
    t(L"FIELDATADID") = FIELDATADID.GetValue();
    t(L"FIELDID") = FIELDID.GetValue();
    t(L"REFID") = REFID.GetValue();
    t(L"CONTENT") = CONTENT;
}

FieldValueRow& FieldValueRow::operator=(const FieldValueRow& other)
{
    if (this == &other) return *this;

    FIELDATADID = other.FIELDATADID;
    FIELDID = other.FIELDID;
    REFID = other.REFID;
    CONTENT = other.CONTENT;

    return *this;
}

FieldValueTable::FieldValueTable()
{
    m_table_name = "CUSTOMFIELDDATA_V1";

    m_create_query = "CREATE TABLE CUSTOMFIELDDATA_V1 (FIELDATADID INTEGER NOT NULL PRIMARY KEY, FIELDID INTEGER NOT NULL, REFID INTEGER NOT NULL, CONTENT TEXT, UNIQUE(FIELDID, REFID))";

    m_drop_query = "DROP TABLE IF EXISTS CUSTOMFIELDDATA_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_CUSTOMFIELDDATA_REF ON CUSTOMFIELDDATA_V1 (FIELDID, REFID)"
    };

    m_insert_query = "INSERT INTO CUSTOMFIELDDATA_V1(FIELDID, REFID, CONTENT, FIELDATADID) VALUES(?, ?, ?, ?)";

    m_update_query = "UPDATE CUSTOMFIELDDATA_V1 SET FIELDID = ?, REFID = ?, CONTENT = ? WHERE FIELDATADID = ?";

    m_delete_query = "DELETE FROM CUSTOMFIELDDATA_V1 WHERE FIELDATADID = ?";

    m_select_query = "SELECT FIELDATADID, FIELDID, REFID, CONTENT FROM CUSTOMFIELDDATA_V1";
}

// Destructor: clears any data records stored in memory
FieldValueTable::~FieldValueTable()
{
    delete fake_;
    destroy_cache();
}

void FieldValueTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
