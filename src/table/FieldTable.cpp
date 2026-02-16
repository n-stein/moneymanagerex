// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      FieldTable.cpp
 *
 *      Implementation of the interface to database table CUSTOMFIELD_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "FieldTable.h"

template class TableFactory<FieldRow>;

// List of column names in database table CUSTOMFIELD_V1,
// in the order of FieldCol::COL_ID.
const wxArrayString FieldCol::COL_NAME_A = {
    "FIELDID",
    "REFTYPE",
    "DESCRIPTION",
    "TYPE",
    "PROPERTIES"
};

const FieldCol::COL_ID FieldCol::PRIMARY_ID = COL_ID_FIELDID;
const wxString FieldCol::PRIMARY_NAME = COL_NAME_A[COL_ID_FIELDID];

FieldRow::FieldRow()
{
    FIELDID = -1;
}

FieldRow::FieldRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool FieldRow::equals(const FieldRow* r) const
{
    if ( FIELDID != r->FIELDID) return false;
    if (!REFTYPE.IsSameAs(r->REFTYPE)) return false;
    if (!DESCRIPTION.IsSameAs(r->DESCRIPTION)) return false;
    if (!TYPE.IsSameAs(r->TYPE)) return false;
    if (!PROPERTIES.IsSameAs(r->PROPERTIES)) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void FieldRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, REFTYPE);
    stmt.Bind(2, DESCRIPTION);
    stmt.Bind(3, TYPE);
    stmt.Bind(4, PROPERTIES);
    stmt.Bind(5, id);
}

void FieldRow::from_select_result(wxSQLite3ResultSet& q)
{
    FIELDID = q.GetInt64(0);
    REFTYPE = q.GetString(1);
    DESCRIPTION = q.GetString(2);
    TYPE = q.GetString(3);
    PROPERTIES = q.GetString(4);
}

// Return the data record as a json string
wxString FieldRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void FieldRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("FIELDID");
    json_writer.Int64(FIELDID.GetValue());

    json_writer.Key("REFTYPE");
    json_writer.String(REFTYPE.utf8_str());

    json_writer.Key("DESCRIPTION");
    json_writer.String(DESCRIPTION.utf8_str());

    json_writer.Key("TYPE");
    json_writer.String(TYPE.utf8_str());

    json_writer.Key("PROPERTIES");
    json_writer.String(PROPERTIES.utf8_str());
}

row_t FieldRow::to_row_t() const
{
    row_t row;

    row(L"FIELDID") = FIELDID.GetValue();
    row(L"REFTYPE") = REFTYPE;
    row(L"DESCRIPTION") = DESCRIPTION;
    row(L"TYPE") = TYPE;
    row(L"PROPERTIES") = PROPERTIES;

    return row;
}

void FieldRow::to_template(html_template& t) const
{
    t(L"FIELDID") = FIELDID.GetValue();
    t(L"REFTYPE") = REFTYPE;
    t(L"DESCRIPTION") = DESCRIPTION;
    t(L"TYPE") = TYPE;
    t(L"PROPERTIES") = PROPERTIES;
}

FieldRow& FieldRow::operator=(const FieldRow& other)
{
    if (this == &other) return *this;

    FIELDID = other.FIELDID;
    REFTYPE = other.REFTYPE;
    DESCRIPTION = other.DESCRIPTION;
    TYPE = other.TYPE;
    PROPERTIES = other.PROPERTIES;

    return *this;
}

FieldTable::FieldTable()
{
    m_table_name = "CUSTOMFIELD_V1";

    m_create_query = "CREATE TABLE CUSTOMFIELD_V1 (FIELDID INTEGER NOT NULL PRIMARY KEY, REFTYPE TEXT NOT NULL /* Transaction, Stock, Asset, Bank Account, Repeating Transaction, Payee */, DESCRIPTION TEXT COLLATE NOCASE, TYPE TEXT NOT NULL /* String, Integer, Decimal, Boolean, Date, Time, SingleChoice, MultiChoice */, PROPERTIES TEXT NOT NULL)";

    m_drop_query = "DROP TABLE IF EXISTS CUSTOMFIELD_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_CUSTOMFIELD_REF ON CUSTOMFIELD_V1 (REFTYPE)"
    };

    m_insert_query = "INSERT INTO CUSTOMFIELD_V1(REFTYPE, DESCRIPTION, TYPE, PROPERTIES, FIELDID) VALUES(?, ?, ?, ?, ?)";

    m_update_query = "UPDATE CUSTOMFIELD_V1 SET REFTYPE = ?, DESCRIPTION = ?, TYPE = ?, PROPERTIES = ? WHERE FIELDID = ?";

    m_delete_query = "DELETE FROM CUSTOMFIELD_V1 WHERE FIELDID = ?";

    m_select_query = "SELECT FIELDID, REFTYPE, DESCRIPTION, TYPE, PROPERTIES FROM CUSTOMFIELD_V1";
}

// Destructor: clears any data records stored in memory
FieldTable::~FieldTable()
{
    delete fake_;
    destroy_cache();
}

void FieldTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
