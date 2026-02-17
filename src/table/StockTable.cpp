// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      StockTable.cpp
 *
 *      Implementation of the interface to database table STOCK_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "StockTable.h"

template class TableFactory<StockRow>;

// List of column names in database table STOCK_V1,
// in the order of StockCol::COL_ID.
const wxArrayString StockCol::COL_NAME_A = {
    "STOCKID",
    "HELDAT",
    "PURCHASEDATE",
    "STOCKNAME",
    "SYMBOL",
    "NUMSHARES",
    "PURCHASEPRICE",
    "NOTES",
    "CURRENTPRICE",
    "VALUE",
    "COMMISSION"
};

const StockCol::COL_ID StockCol::PRIMARY_ID = COL_ID_STOCKID;
const wxString StockCol::PRIMARY_NAME = COL_NAME_A[COL_ID_STOCKID];

StockRow::StockRow()
{
    STOCKID = -1;
    HELDAT = -1;
    NUMSHARES = 0.0;
    PURCHASEPRICE = 0.0;
    CURRENTPRICE = 0.0;
    VALUE = 0.0;
    COMMISSION = 0.0;
}

StockRow::StockRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool StockRow::equals(const StockRow* r) const
{
    if ( STOCKID != r->STOCKID) return false;
    if ( HELDAT != r->HELDAT) return false;
    if (!PURCHASEDATE.IsSameAs(r->PURCHASEDATE)) return false;
    if (!STOCKNAME.IsSameAs(r->STOCKNAME)) return false;
    if (!SYMBOL.IsSameAs(r->SYMBOL)) return false;
    if ( NUMSHARES != r->NUMSHARES) return false;
    if ( PURCHASEPRICE != r->PURCHASEPRICE) return false;
    if (!NOTES.IsSameAs(r->NOTES)) return false;
    if ( CURRENTPRICE != r->CURRENTPRICE) return false;
    if ( VALUE != r->VALUE) return false;
    if ( COMMISSION != r->COMMISSION) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void StockRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, HELDAT);
    stmt.Bind(2, PURCHASEDATE);
    stmt.Bind(3, STOCKNAME);
    stmt.Bind(4, SYMBOL);
    stmt.Bind(5, NUMSHARES);
    stmt.Bind(6, PURCHASEPRICE);
    stmt.Bind(7, NOTES);
    stmt.Bind(8, CURRENTPRICE);
    stmt.Bind(9, VALUE);
    stmt.Bind(10, COMMISSION);
    stmt.Bind(11, id);
}

void StockRow::from_select_result(wxSQLite3ResultSet& q)
{
    STOCKID = q.GetInt64(0);
    HELDAT = q.GetInt64(1);
    PURCHASEDATE = q.GetString(2);
    STOCKNAME = q.GetString(3);
    SYMBOL = q.GetString(4);
    NUMSHARES = q.GetDouble(5);
    PURCHASEPRICE = q.GetDouble(6);
    NOTES = q.GetString(7);
    CURRENTPRICE = q.GetDouble(8);
    VALUE = q.GetDouble(9);
    COMMISSION = q.GetDouble(10);
}

// Return the data record as a json string
wxString StockRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void StockRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("STOCKID");
    json_writer.Int64(STOCKID.GetValue());

    json_writer.Key("HELDAT");
    json_writer.Int64(HELDAT.GetValue());

    json_writer.Key("PURCHASEDATE");
    json_writer.String(PURCHASEDATE.utf8_str());

    json_writer.Key("STOCKNAME");
    json_writer.String(STOCKNAME.utf8_str());

    json_writer.Key("SYMBOL");
    json_writer.String(SYMBOL.utf8_str());

    json_writer.Key("NUMSHARES");
    json_writer.Double(NUMSHARES);

    json_writer.Key("PURCHASEPRICE");
    json_writer.Double(PURCHASEPRICE);

    json_writer.Key("NOTES");
    json_writer.String(NOTES.utf8_str());

    json_writer.Key("CURRENTPRICE");
    json_writer.Double(CURRENTPRICE);

    json_writer.Key("VALUE");
    json_writer.Double(VALUE);

    json_writer.Key("COMMISSION");
    json_writer.Double(COMMISSION);
}

row_t StockRow::to_row_t() const
{
    row_t row;

    row(L"STOCKID") = STOCKID.GetValue();
    row(L"HELDAT") = HELDAT.GetValue();
    row(L"PURCHASEDATE") = PURCHASEDATE;
    row(L"STOCKNAME") = STOCKNAME;
    row(L"SYMBOL") = SYMBOL;
    row(L"NUMSHARES") = NUMSHARES;
    row(L"PURCHASEPRICE") = PURCHASEPRICE;
    row(L"NOTES") = NOTES;
    row(L"CURRENTPRICE") = CURRENTPRICE;
    row(L"VALUE") = VALUE;
    row(L"COMMISSION") = COMMISSION;

    return row;
}

void StockRow::to_template(html_template& t) const
{
    t(L"STOCKID") = STOCKID.GetValue();
    t(L"HELDAT") = HELDAT.GetValue();
    t(L"PURCHASEDATE") = PURCHASEDATE;
    t(L"STOCKNAME") = STOCKNAME;
    t(L"SYMBOL") = SYMBOL;
    t(L"NUMSHARES") = NUMSHARES;
    t(L"PURCHASEPRICE") = PURCHASEPRICE;
    t(L"NOTES") = NOTES;
    t(L"CURRENTPRICE") = CURRENTPRICE;
    t(L"VALUE") = VALUE;
    t(L"COMMISSION") = COMMISSION;
}

StockRow& StockRow::operator=(const StockRow& other)
{
    if (this == &other) return *this;

    STOCKID = other.STOCKID;
    HELDAT = other.HELDAT;
    PURCHASEDATE = other.PURCHASEDATE;
    STOCKNAME = other.STOCKNAME;
    SYMBOL = other.SYMBOL;
    NUMSHARES = other.NUMSHARES;
    PURCHASEPRICE = other.PURCHASEPRICE;
    NOTES = other.NOTES;
    CURRENTPRICE = other.CURRENTPRICE;
    VALUE = other.VALUE;
    COMMISSION = other.COMMISSION;

    return *this;
}

StockTable::StockTable()
{
    m_table_name = "STOCK_V1";

    m_create_query = "CREATE TABLE STOCK_V1(STOCKID integer primary key, HELDAT integer, PURCHASEDATE TEXT NOT NULL, STOCKNAME TEXT COLLATE NOCASE NOT NULL, SYMBOL TEXT, NUMSHARES numeric, PURCHASEPRICE numeric NOT NULL, NOTES TEXT, CURRENTPRICE numeric NOT NULL, VALUE numeric, COMMISSION numeric)";

    m_drop_query = "DROP TABLE IF EXISTS STOCK_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_STOCK_HELDAT ON STOCK_V1(HELDAT)"
    };

    m_insert_query = "INSERT INTO STOCK_V1(HELDAT, PURCHASEDATE, STOCKNAME, SYMBOL, NUMSHARES, PURCHASEPRICE, NOTES, CURRENTPRICE, VALUE, COMMISSION, STOCKID) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

    m_update_query = "UPDATE STOCK_V1 SET HELDAT = ?, PURCHASEDATE = ?, STOCKNAME = ?, SYMBOL = ?, NUMSHARES = ?, PURCHASEPRICE = ?, NOTES = ?, CURRENTPRICE = ?, VALUE = ?, COMMISSION = ? WHERE STOCKID = ?";

    m_delete_query = "DELETE FROM STOCK_V1 WHERE STOCKID = ?";

    m_select_query = "SELECT STOCKID, HELDAT, PURCHASEDATE, STOCKNAME, SYMBOL, NUMSHARES, PURCHASEPRICE, NOTES, CURRENTPRICE, VALUE, COMMISSION FROM STOCK_V1";
}

// Destructor: clears any data records stored in memory
StockTable::~StockTable()
{
    delete fake_;
    destroy_cache();
}

void StockTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
