// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      StockHistoryTable.cpp
 *
 *      Implementation of the interface to database table STOCKHISTORY_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "StockHistoryTable.h"

template class TableFactory<StockHistoryRow>;

// List of column names in database table STOCKHISTORY_V1,
// in the order of StockHistoryCol::COL_ID.
const wxArrayString StockHistoryCol::COL_NAME_A = {
    "HISTID",
    "SYMBOL",
    "DATE",
    "VALUE",
    "UPDTYPE"
};

const StockHistoryCol::COL_ID StockHistoryCol::PRIMARY_ID = COL_ID_HISTID;
const wxString StockHistoryCol::PRIMARY_NAME = COL_NAME_A[COL_ID_HISTID];

StockHistoryRow::StockHistoryRow()
{
    HISTID = -1;
    VALUE = 0.0;
    UPDTYPE = -1;
}

StockHistoryRow::StockHistoryRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool StockHistoryRow::equals(const StockHistoryRow* r) const
{
    if ( HISTID != r->HISTID) return false;
    if (!SYMBOL.IsSameAs(r->SYMBOL)) return false;
    if (!DATE.IsSameAs(r->DATE)) return false;
    if ( VALUE != r->VALUE) return false;
    if ( UPDTYPE != r->UPDTYPE) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void StockHistoryRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, SYMBOL);
    stmt.Bind(2, DATE);
    stmt.Bind(3, VALUE);
    stmt.Bind(4, UPDTYPE);
    stmt.Bind(5, id);
}

void StockHistoryRow::from_select_result(wxSQLite3ResultSet& q)
{
    HISTID = q.GetInt64(0);
    SYMBOL = q.GetString(1);
    DATE = q.GetString(2);
    VALUE = q.GetDouble(3);
    UPDTYPE = q.GetInt64(4);
}

// Return the data record as a json string
wxString StockHistoryRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void StockHistoryRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("HISTID");
    json_writer.Int64(HISTID.GetValue());

    json_writer.Key("SYMBOL");
    json_writer.String(SYMBOL.utf8_str());

    json_writer.Key("DATE");
    json_writer.String(DATE.utf8_str());

    json_writer.Key("VALUE");
    json_writer.Double(VALUE);

    json_writer.Key("UPDTYPE");
    json_writer.Int64(UPDTYPE.GetValue());
}

row_t StockHistoryRow::to_row_t() const
{
    row_t row;

    row(L"HISTID") = HISTID.GetValue();
    row(L"SYMBOL") = SYMBOL;
    row(L"DATE") = DATE;
    row(L"VALUE") = VALUE;
    row(L"UPDTYPE") = UPDTYPE.GetValue();

    return row;
}

void StockHistoryRow::to_template(html_template& t) const
{
    t(L"HISTID") = HISTID.GetValue();
    t(L"SYMBOL") = SYMBOL;
    t(L"DATE") = DATE;
    t(L"VALUE") = VALUE;
    t(L"UPDTYPE") = UPDTYPE.GetValue();
}

StockHistoryRow& StockHistoryRow::operator=(const StockHistoryRow& other)
{
    if (this == &other) return *this;

    HISTID = other.HISTID;
    SYMBOL = other.SYMBOL;
    DATE = other.DATE;
    VALUE = other.VALUE;
    UPDTYPE = other.UPDTYPE;

    return *this;
}

StockHistoryTable::StockHistoryTable()
{
    m_table_name = "STOCKHISTORY_V1";

    m_create_query = "CREATE TABLE STOCKHISTORY_V1(HISTID integer primary key, SYMBOL TEXT NOT NULL, DATE TEXT NOT NULL, VALUE numeric NOT NULL, UPDTYPE integer, UNIQUE(SYMBOL, DATE))";

    m_drop_query = "DROP TABLE IF EXISTS STOCKHISTORY_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_STOCKHISTORY_SYMBOL ON STOCKHISTORY_V1(SYMBOL)"
    };

    m_insert_query = "INSERT INTO STOCKHISTORY_V1(SYMBOL, DATE, VALUE, UPDTYPE, HISTID) VALUES(?, ?, ?, ?, ?)";

    m_update_query = "UPDATE STOCKHISTORY_V1 SET SYMBOL = ?, DATE = ?, VALUE = ?, UPDTYPE = ? WHERE HISTID = ?";

    m_delete_query = "DELETE FROM STOCKHISTORY_V1 WHERE HISTID = ?";

    m_select_query = "SELECT HISTID, SYMBOL, DATE, VALUE, UPDTYPE FROM STOCKHISTORY_V1";
}

// Destructor: clears any data records stored in memory
StockHistoryTable::~StockHistoryTable()
{
    delete fake_;
    destroy_cache();
}

void StockHistoryTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
