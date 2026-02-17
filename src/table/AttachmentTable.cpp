// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      AttachmentTable.cpp
 *
 *      Implementation of the interface to database table ATTACHMENT_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "AttachmentTable.h"

template class TableFactory<AttachmentRow>;

// List of column names in database table ATTACHMENT_V1,
// in the order of AttachmentCol::COL_ID.
const wxArrayString AttachmentCol::COL_NAME_A = {
    "ATTACHMENTID",
    "REFTYPE",
    "REFID",
    "DESCRIPTION",
    "FILENAME"
};

const AttachmentCol::COL_ID AttachmentCol::PRIMARY_ID = COL_ID_ATTACHMENTID;
const wxString AttachmentCol::PRIMARY_NAME = COL_NAME_A[COL_ID_ATTACHMENTID];

AttachmentRow::AttachmentRow()
{
    ATTACHMENTID = -1;
    REFID = -1;
}

AttachmentRow::AttachmentRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool AttachmentRow::equals(const AttachmentRow* r) const
{
    if ( ATTACHMENTID != r->ATTACHMENTID) return false;
    if (!REFTYPE.IsSameAs(r->REFTYPE)) return false;
    if ( REFID != r->REFID) return false;
    if (!DESCRIPTION.IsSameAs(r->DESCRIPTION)) return false;
    if (!FILENAME.IsSameAs(r->FILENAME)) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void AttachmentRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, REFTYPE);
    stmt.Bind(2, REFID);
    stmt.Bind(3, DESCRIPTION);
    stmt.Bind(4, FILENAME);
    stmt.Bind(5, id);
}

void AttachmentRow::from_select_result(wxSQLite3ResultSet& q)
{
    ATTACHMENTID = q.GetInt64(0);
    REFTYPE = q.GetString(1);
    REFID = q.GetInt64(2);
    DESCRIPTION = q.GetString(3);
    FILENAME = q.GetString(4);
}

// Return the data record as a json string
wxString AttachmentRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void AttachmentRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("ATTACHMENTID");
    json_writer.Int64(ATTACHMENTID.GetValue());

    json_writer.Key("REFTYPE");
    json_writer.String(REFTYPE.utf8_str());

    json_writer.Key("REFID");
    json_writer.Int64(REFID.GetValue());

    json_writer.Key("DESCRIPTION");
    json_writer.String(DESCRIPTION.utf8_str());

    json_writer.Key("FILENAME");
    json_writer.String(FILENAME.utf8_str());
}

row_t AttachmentRow::to_row_t() const
{
    row_t row;

    row(L"ATTACHMENTID") = ATTACHMENTID.GetValue();
    row(L"REFTYPE") = REFTYPE;
    row(L"REFID") = REFID.GetValue();
    row(L"DESCRIPTION") = DESCRIPTION;
    row(L"FILENAME") = FILENAME;

    return row;
}

void AttachmentRow::to_template(html_template& t) const
{
    t(L"ATTACHMENTID") = ATTACHMENTID.GetValue();
    t(L"REFTYPE") = REFTYPE;
    t(L"REFID") = REFID.GetValue();
    t(L"DESCRIPTION") = DESCRIPTION;
    t(L"FILENAME") = FILENAME;
}

AttachmentRow& AttachmentRow::operator=(const AttachmentRow& other)
{
    if (this == &other) return *this;

    ATTACHMENTID = other.ATTACHMENTID;
    REFTYPE = other.REFTYPE;
    REFID = other.REFID;
    DESCRIPTION = other.DESCRIPTION;
    FILENAME = other.FILENAME;

    return *this;
}

AttachmentTable::AttachmentTable()
{
    m_table_name = "ATTACHMENT_V1";

    m_create_query = "CREATE TABLE ATTACHMENT_V1 (ATTACHMENTID INTEGER NOT NULL PRIMARY KEY, REFTYPE TEXT NOT NULL /* Transaction, Stock, Asset, Bank Account, Repeating Transaction, Payee */, REFID INTEGER NOT NULL, DESCRIPTION TEXT COLLATE NOCASE, FILENAME TEXT NOT NULL COLLATE NOCASE)";

    m_drop_query = "DROP TABLE IF EXISTS ATTACHMENT_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_ATTACHMENT_REF ON ATTACHMENT_V1 (REFTYPE, REFID)"
    };

    m_insert_query = "INSERT INTO ATTACHMENT_V1(REFTYPE, REFID, DESCRIPTION, FILENAME, ATTACHMENTID) VALUES(?, ?, ?, ?, ?)";

    m_update_query = "UPDATE ATTACHMENT_V1 SET REFTYPE = ?, REFID = ?, DESCRIPTION = ?, FILENAME = ? WHERE ATTACHMENTID = ?";

    m_delete_query = "DELETE FROM ATTACHMENT_V1 WHERE ATTACHMENTID = ?";

    m_select_query = "SELECT ATTACHMENTID, REFTYPE, REFID, DESCRIPTION, FILENAME FROM ATTACHMENT_V1";
}

// Destructor: clears any data records stored in memory
AttachmentTable::~AttachmentTable()
{
    delete fake_;
    destroy_cache();
}

void AttachmentTable::ensure_data()
{
    m_db->Begin();
    m_db->Commit();
}
