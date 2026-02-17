// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      SettingTable.cpp
 *
 *      Implementation of the interface to database table SETTING_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "SettingTable.h"

template class TableFactory<SettingRow>;

// List of column names in database table SETTING_V1,
// in the order of SettingCol::COL_ID.
const wxArrayString SettingCol::COL_NAME_A = {
    "SETTINGID",
    "SETTINGNAME",
    "SETTINGVALUE"
};

const SettingCol::COL_ID SettingCol::PRIMARY_ID = COL_ID_SETTINGID;
const wxString SettingCol::PRIMARY_NAME = COL_NAME_A[COL_ID_SETTINGID];

SettingRow::SettingRow()
{
    SETTINGID = -1;
}

SettingRow::SettingRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool SettingRow::equals(const SettingRow* r) const
{
    if ( SETTINGID != r->SETTINGID) return false;
    if (!SETTINGNAME.IsSameAs(r->SETTINGNAME)) return false;
    if (!SETTINGVALUE.IsSameAs(r->SETTINGVALUE)) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void SettingRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, SETTINGNAME);
    stmt.Bind(2, SETTINGVALUE);
    stmt.Bind(3, id);
}

void SettingRow::from_select_result(wxSQLite3ResultSet& q)
{
    SETTINGID = q.GetInt64(0);
    SETTINGNAME = q.GetString(1);
    SETTINGVALUE = q.GetString(2);
}

// Return the data record as a json string
wxString SettingRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void SettingRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("SETTINGID");
    json_writer.Int64(SETTINGID.GetValue());

    json_writer.Key("SETTINGNAME");
    json_writer.String(SETTINGNAME.utf8_str());

    json_writer.Key("SETTINGVALUE");
    json_writer.String(SETTINGVALUE.utf8_str());
}

row_t SettingRow::to_row_t() const
{
    row_t row;

    row(L"SETTINGID") = SETTINGID.GetValue();
    row(L"SETTINGNAME") = SETTINGNAME;
    row(L"SETTINGVALUE") = SETTINGVALUE;

    return row;
}

void SettingRow::to_template(html_template& t) const
{
    t(L"SETTINGID") = SETTINGID.GetValue();
    t(L"SETTINGNAME") = SETTINGNAME;
    t(L"SETTINGVALUE") = SETTINGVALUE;
}

SettingRow& SettingRow::operator=(const SettingRow& other)
{
    if (this == &other) return *this;

    SETTINGID = other.SETTINGID;
    SETTINGNAME = other.SETTINGNAME;
    SETTINGVALUE = other.SETTINGVALUE;

    return *this;
}

SettingTable::SettingTable()
{
    m_table_name = "SETTING_V1";

    m_create_query = "CREATE TABLE SETTING_V1(SETTINGID integer not null primary key, SETTINGNAME TEXT COLLATE NOCASE NOT NULL UNIQUE, SETTINGVALUE TEXT)";

    m_drop_query = "DROP TABLE IF EXISTS SETTING_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_SETTING_SETTINGNAME ON SETTING_V1(SETTINGNAME)"
    };

    m_insert_query = "INSERT INTO SETTING_V1(SETTINGNAME, SETTINGVALUE, SETTINGID) VALUES(?, ?, ?)";

    m_update_query = "UPDATE SETTING_V1 SET SETTINGNAME = ?, SETTINGVALUE = ? WHERE SETTINGID = ?";

    m_delete_query = "DELETE FROM SETTING_V1 WHERE SETTINGID = ?";

    m_select_query = "SELECT SETTINGID, SETTINGNAME, SETTINGVALUE FROM SETTING_V1";
}

// Destructor: clears any data records stored in memory
SettingTable::~SettingTable()
{
    delete fake_;
    destroy_cache();
}

void SettingTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
