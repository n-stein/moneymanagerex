// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      AssetTable.cpp
 *
 *      Implementation of the interface to database table ASSETS_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "AssetTable.h"

template class TableFactory<AssetRow>;

// List of column names in database table ASSETS_V1,
// in the order of AssetCol::COL_ID.
const wxArrayString AssetCol::COL_NAME_A = {
    "ASSETID",
    "STARTDATE",
    "ASSETNAME",
    "ASSETSTATUS",
    "CURRENCYID",
    "VALUECHANGEMODE",
    "VALUE",
    "VALUECHANGE",
    "NOTES",
    "VALUECHANGERATE",
    "ASSETTYPE"
};

const AssetCol::COL_ID AssetCol::PRIMARY_ID = COL_ID_ASSETID;
const wxString AssetCol::PRIMARY_NAME = COL_NAME_A[COL_ID_ASSETID];

AssetRow::AssetRow()
{
    ASSETID = -1;
    CURRENCYID = -1;
    VALUE = 0.0;
    VALUECHANGERATE = 0.0;
}

AssetRow::AssetRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool AssetRow::equals(const AssetRow* r) const
{
    if ( ASSETID != r->ASSETID) return false;
    if (!STARTDATE.IsSameAs(r->STARTDATE)) return false;
    if (!ASSETNAME.IsSameAs(r->ASSETNAME)) return false;
    if (!ASSETSTATUS.IsSameAs(r->ASSETSTATUS)) return false;
    if ( CURRENCYID != r->CURRENCYID) return false;
    if (!VALUECHANGEMODE.IsSameAs(r->VALUECHANGEMODE)) return false;
    if ( VALUE != r->VALUE) return false;
    if (!VALUECHANGE.IsSameAs(r->VALUECHANGE)) return false;
    if (!NOTES.IsSameAs(r->NOTES)) return false;
    if ( VALUECHANGERATE != r->VALUECHANGERATE) return false;
    if (!ASSETTYPE.IsSameAs(r->ASSETTYPE)) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void AssetRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, STARTDATE);
    stmt.Bind(2, ASSETNAME);
    stmt.Bind(3, ASSETSTATUS);
    stmt.Bind(4, CURRENCYID);
    stmt.Bind(5, VALUECHANGEMODE);
    stmt.Bind(6, VALUE);
    stmt.Bind(7, VALUECHANGE);
    stmt.Bind(8, NOTES);
    stmt.Bind(9, VALUECHANGERATE);
    stmt.Bind(10, ASSETTYPE);
    stmt.Bind(11, id);
}

void AssetRow::from_select_result(wxSQLite3ResultSet& q)
{
    ASSETID = q.GetInt64(0);
    STARTDATE = q.GetString(1);
    ASSETNAME = q.GetString(2);
    ASSETSTATUS = q.GetString(3);
    CURRENCYID = q.GetInt64(4);
    VALUECHANGEMODE = q.GetString(5);
    VALUE = q.GetDouble(6);
    VALUECHANGE = q.GetString(7);
    NOTES = q.GetString(8);
    VALUECHANGERATE = q.GetDouble(9);
    ASSETTYPE = q.GetString(10);
}

// Return the data record as a json string
wxString AssetRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void AssetRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("ASSETID");
    json_writer.Int64(ASSETID.GetValue());

    json_writer.Key("STARTDATE");
    json_writer.String(STARTDATE.utf8_str());

    json_writer.Key("ASSETNAME");
    json_writer.String(ASSETNAME.utf8_str());

    json_writer.Key("ASSETSTATUS");
    json_writer.String(ASSETSTATUS.utf8_str());

    json_writer.Key("CURRENCYID");
    json_writer.Int64(CURRENCYID.GetValue());

    json_writer.Key("VALUECHANGEMODE");
    json_writer.String(VALUECHANGEMODE.utf8_str());

    json_writer.Key("VALUE");
    json_writer.Double(VALUE);

    json_writer.Key("VALUECHANGE");
    json_writer.String(VALUECHANGE.utf8_str());

    json_writer.Key("NOTES");
    json_writer.String(NOTES.utf8_str());

    json_writer.Key("VALUECHANGERATE");
    json_writer.Double(VALUECHANGERATE);

    json_writer.Key("ASSETTYPE");
    json_writer.String(ASSETTYPE.utf8_str());
}

row_t AssetRow::to_row_t() const
{
    row_t row;

    row(L"ASSETID") = ASSETID.GetValue();
    row(L"STARTDATE") = STARTDATE;
    row(L"ASSETNAME") = ASSETNAME;
    row(L"ASSETSTATUS") = ASSETSTATUS;
    row(L"CURRENCYID") = CURRENCYID.GetValue();
    row(L"VALUECHANGEMODE") = VALUECHANGEMODE;
    row(L"VALUE") = VALUE;
    row(L"VALUECHANGE") = VALUECHANGE;
    row(L"NOTES") = NOTES;
    row(L"VALUECHANGERATE") = VALUECHANGERATE;
    row(L"ASSETTYPE") = ASSETTYPE;

    return row;
}

void AssetRow::to_template(html_template& t) const
{
    t(L"ASSETID") = ASSETID.GetValue();
    t(L"STARTDATE") = STARTDATE;
    t(L"ASSETNAME") = ASSETNAME;
    t(L"ASSETSTATUS") = ASSETSTATUS;
    t(L"CURRENCYID") = CURRENCYID.GetValue();
    t(L"VALUECHANGEMODE") = VALUECHANGEMODE;
    t(L"VALUE") = VALUE;
    t(L"VALUECHANGE") = VALUECHANGE;
    t(L"NOTES") = NOTES;
    t(L"VALUECHANGERATE") = VALUECHANGERATE;
    t(L"ASSETTYPE") = ASSETTYPE;
}

AssetRow& AssetRow::operator=(const AssetRow& other)
{
    if (this == &other) return *this;

    ASSETID = other.ASSETID;
    STARTDATE = other.STARTDATE;
    ASSETNAME = other.ASSETNAME;
    ASSETSTATUS = other.ASSETSTATUS;
    CURRENCYID = other.CURRENCYID;
    VALUECHANGEMODE = other.VALUECHANGEMODE;
    VALUE = other.VALUE;
    VALUECHANGE = other.VALUECHANGE;
    NOTES = other.NOTES;
    VALUECHANGERATE = other.VALUECHANGERATE;
    ASSETTYPE = other.ASSETTYPE;

    return *this;
}

AssetTable::AssetTable()
{
    m_table_name = "ASSETS_V1";

    m_create_query = "CREATE TABLE ASSETS_V1(ASSETID integer primary key, STARTDATE TEXT NOT NULL, ASSETNAME TEXT COLLATE NOCASE NOT NULL, ASSETSTATUS TEXT /* Open, Closed */, CURRENCYID integer, VALUECHANGEMODE TEXT /* Percentage, Linear */, VALUE numeric, VALUECHANGE TEXT /* None, Appreciates, Depreciates */, NOTES TEXT, VALUECHANGERATE numeric, ASSETTYPE TEXT /* Property, Automobile, Household Object, Art, Jewellery, Cash, Other */)";

    m_drop_query = "DROP TABLE IF EXISTS ASSETS_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_ASSETS_ASSETTYPE ON ASSETS_V1(ASSETTYPE)"
    };

    m_insert_query = "INSERT INTO ASSETS_V1(STARTDATE, ASSETNAME, ASSETSTATUS, CURRENCYID, VALUECHANGEMODE, VALUE, VALUECHANGE, NOTES, VALUECHANGERATE, ASSETTYPE, ASSETID) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    m_update_query = "UPDATE ASSETS_V1 SET STARTDATE = ?, ASSETNAME = ?, ASSETSTATUS = ?, CURRENCYID = ?, VALUECHANGEMODE = ?, VALUE = ?, VALUECHANGE = ?, NOTES = ?, VALUECHANGERATE = ?, ASSETTYPE = ? WHERE ASSETID = ?";

    m_delete_query = "DELETE FROM ASSETS_V1 WHERE ASSETID = ?";

    m_select_query = "SELECT ASSETID, STARTDATE, ASSETNAME, ASSETSTATUS, CURRENCYID, VALUECHANGEMODE, VALUE, VALUECHANGE, NOTES, VALUECHANGERATE, ASSETTYPE FROM ASSETS_V1";
}

// Destructor: clears any data records stored in memory
AssetTable::~AssetTable()
{
    delete fake_;
    destroy_cache();
}

void AssetTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
