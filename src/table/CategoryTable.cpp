// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-2026 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      CategoryTable.cpp
 *
 *      Implementation of the interface to database table CATEGORY_V1
 *
 *      @author [sqlite2cpp.py]
 *
 *      Revision History:
 *          AUTO GENERATED at 2026-02-16 15:07:22.405413.
 *          DO NOT EDIT!
 */
//=============================================================================

#include "_TableFactory.tpp"
#include "CategoryTable.h"

template class TableFactory<CategoryRow>;

// List of column names in database table CATEGORY_V1,
// in the order of CategoryCol::COL_ID.
const wxArrayString CategoryCol::COL_NAME_A = {
    "CATEGID",
    "CATEGNAME",
    "ACTIVE",
    "PARENTID"
};

const CategoryCol::COL_ID CategoryCol::PRIMARY_ID = COL_ID_CATEGID;
const wxString CategoryCol::PRIMARY_NAME = COL_NAME_A[COL_ID_CATEGID];

CategoryRow::CategoryRow()
{
    CATEGID = -1;
    ACTIVE = -1;
    PARENTID = -1;
}

CategoryRow::CategoryRow(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}

bool CategoryRow::equals(const CategoryRow* r) const
{
    if ( CATEGID != r->CATEGID) return false;
    if (!CATEGNAME.IsSameAs(r->CATEGNAME)) return false;
    if ( ACTIVE != r->ACTIVE) return false;
    if ( PARENTID != r->PARENTID) return false;

    return true;
}

// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void CategoryRow::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{
    stmt.Bind(1, CATEGNAME);
    stmt.Bind(2, ACTIVE);
    stmt.Bind(3, PARENTID);
    stmt.Bind(4, id);
}

void CategoryRow::from_select_result(wxSQLite3ResultSet& q)
{
    CATEGID = q.GetInt64(0);
    CATEGNAME = q.GetString(1);
    ACTIVE = q.GetInt64(2);
    PARENTID = q.GetInt64(3);
}

// Return the data record as a json string
wxString CategoryRow::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}

// Add the field data as json key:value pairs
void CategoryRow::as_json(PrettyWriter<StringBuffer>& json_writer) const
{
    json_writer.Key("CATEGID");
    json_writer.Int64(CATEGID.GetValue());

    json_writer.Key("CATEGNAME");
    json_writer.String(CATEGNAME.utf8_str());

    json_writer.Key("ACTIVE");
    json_writer.Int64(ACTIVE.GetValue());

    json_writer.Key("PARENTID");
    json_writer.Int64(PARENTID.GetValue());
}

row_t CategoryRow::to_row_t() const
{
    row_t row;

    row(L"CATEGID") = CATEGID.GetValue();
    row(L"CATEGNAME") = CATEGNAME;
    row(L"ACTIVE") = ACTIVE.GetValue();
    row(L"PARENTID") = PARENTID.GetValue();

    return row;
}

void CategoryRow::to_template(html_template& t) const
{
    t(L"CATEGID") = CATEGID.GetValue();
    t(L"CATEGNAME") = CATEGNAME;
    t(L"ACTIVE") = ACTIVE.GetValue();
    t(L"PARENTID") = PARENTID.GetValue();
}

CategoryRow& CategoryRow::operator=(const CategoryRow& other)
{
    if (this == &other) return *this;

    CATEGID = other.CATEGID;
    CATEGNAME = other.CATEGNAME;
    ACTIVE = other.ACTIVE;
    PARENTID = other.PARENTID;

    return *this;
}

CategoryTable::CategoryTable()
{
    m_table_name = "CATEGORY_V1";

    m_create_query = "CREATE TABLE CATEGORY_V1( CATEGID INTEGER PRIMARY KEY,  CATEGNAME TEXT NOT NULL COLLATE NOCASE,  ACTIVE INTEGER,  PARENTID INTEGER,  UNIQUE(CATEGNAME, PARENTID))";

    m_drop_query = "DROP TABLE IF EXISTS CATEGORY_V1";

    m_index_query_a = {
        "CREATE INDEX IF NOT EXISTS IDX_CATEGORY_CATEGNAME ON CATEGORY_V1(CATEGNAME)",
        "CREATE INDEX IF NOT EXISTS IDX_CATEGORY_CATEGNAME_PARENTID ON CATEGORY_V1(CATEGNAME, PARENTID)"
    };

    m_insert_query = "INSERT INTO CATEGORY_V1(CATEGNAME, ACTIVE, PARENTID, CATEGID) VALUES(?, ?, ?, ?)";

    m_update_query = "UPDATE CATEGORY_V1 SET CATEGNAME = ?, ACTIVE = ?, PARENTID = ? WHERE CATEGID = ?";

    m_delete_query = "DELETE FROM CATEGORY_V1 WHERE CATEGID = ?";

    m_select_query = "SELECT CATEGID, CATEGNAME, ACTIVE, PARENTID FROM CATEGORY_V1";
}

// Destructor: clears any data records stored in memory
CategoryTable::~CategoryTable()
{
    delete fake_;
    destroy_cache();
}

void CategoryTable::ensure_data()
{
    m_db->Begin();
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('1', '%s', '1', '-1')", _("Bills")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('2', '%s', '1', '1')", _("Telephone")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('3', '%s', '1', '1')", _("Electricity")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('4', '%s', '1', '1')", _("Gas")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('5', '%s', '1', '1')", _("Internet")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('6', '%s', '1', '1')", _("Rent")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('7', '%s', '1', '1')", _("Cable TV")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('8', '%s', '1', '1')", _("Water")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('9', '%s', '1', '-1')", _("Food")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('10', '%s', '1', '9')", _("Groceries")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('11', '%s', '1', '9')", _("Dining out")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('12', '%s', '1', '-1')", _("Leisure")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('13', '%s', '1', '12')", _("Movies")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('14', '%s', '1', '12')", _("Video Rental")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('15', '%s', '1', '12')", _("Magazines")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('16', '%s', '1', '-1')", _("Automobile")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('17', '%s', '1', '16')", _("Maintenance")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('18', '%s', '1', '16')", _("Gas")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('19', '%s', '1', '16')", _("Parking")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('20', '%s', '1', '16')", _("Registration")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('21', '%s', '1', '-1')", _("Education")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('22', '%s', '1', '21')", _("Books")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('23', '%s', '1', '21')", _("Tuition")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('24', '%s', '1', '21')", _("Others")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('25', '%s', '1', '-1')", _("Homeneeds")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('26', '%s', '1', '25')", _("Clothing")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('27', '%s', '1', '25')", _("Furnishing")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('28', '%s', '1', '25')", _("Others")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('29', '%s', '1', '-1')", _("Healthcare")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('30', '%s', '1', '29')", _("Health")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('31', '%s', '1', '29')", _("Dental")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('32', '%s', '1', '29')", _("Eyecare")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('33', '%s', '1', '29')", _("Physician")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('34', '%s', '1', '29')", _("Prescriptions")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('35', '%s', '1', '-1')", _("Insurance")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('36', '%s', '1', '35')", _("Auto")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('37', '%s', '1', '35')", _("Life")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('38', '%s', '1', '35')", _("Home")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('39', '%s', '1', '35')", _("Health")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('40', '%s', '1', '-1')", _("Vacation")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('41', '%s', '1', '40')", _("Travel")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('42', '%s', '1', '40')", _("Lodging")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('43', '%s', '1', '40')", _("Sightseeing")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('44', '%s', '1', '-1')", _("Taxes")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('45', '%s', '1', '44')", _("Income Tax")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('46', '%s', '1', '44')", _("House Tax")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('47', '%s', '1', '44')", _("Water Tax")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('48', '%s', '1', '44')", _("Others")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('49', '%s', '1', '-1')", _("Miscellaneous")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('50', '%s', '1', '-1')", _("Gifts")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('51', '%s', '1', '-1')", _("Income")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('52', '%s', '1', '51')", _("Salary")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('53', '%s', '1', '51')", _("Reimbursement/Refunds")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('54', '%s', '1', '51')", _("Investment Income")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('55', '%s', '1', '-1')", _("Other Income")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('56', '%s', '1', '-1')", _("Other Expenses")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('57', '%s', '1', '-1')", _("Transfer")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('58', '%s', '1', '-1')", _("Investment")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('59', '%s', '1', '58')", _("Purchase")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('60', '%s', '1', '58')", _("Sale")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('61', '%s', '1', '58')", _("Dividend")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('62', '%s', '1', '58')", _("Capital Gains")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('63', '%s', '1', '58')", _("Brokerage Fees")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('64', '%s', '1', '58')", _("Interest")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('65', '%s', '1', '58')", _("Taxes")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('66', '%s', '1', '58')", _("Split")));
    m_db->ExecuteUpdate(wxString::Format("INSERT INTO CATEGORY_V1 VALUES ('67', '%s', '1', '58')", _("Merger")));
    m_db->Commit();
}
