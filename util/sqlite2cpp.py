#!/usr/bin/env python
# vim: tabstop=4 shiftwidth=4 softtabstop=4 expandtab autoindent smarttab foldmethod=marker
'''
Usage: python sqlite2cpp.py path_to_sql_file
'''

# {{{ import

import sys
import os
import datetime
import sqlite3
import codecs

# }}}
# {{{ const

# existing files
base_basename = '_TableBase'
factory_basename = '_TableFactory'

# generated files
tables_sql_filename = 'tables_en.sql'
patch_currency_filename = 'patch_currency.sql'
patch_currency_utf8_filename = 'patch_currency_utf8.sql'

# convert DB table name to C++ class basename
table_class_basename = {
    'ACCOUNTLIST_V1'             : 'Account',
    'ASSETS_V1'                  : 'Asset',
    'ATTACHMENT_V1'              : 'Attachment',
    'BILLSDEPOSITS_V1'           : 'Scheduled',
    'BUDGETSPLITTRANSACTIONS_V1' : 'ScheduledSplit',
    'BUDGETTABLE_V1'             : 'Budget',
    'BUDGETYEAR_V1'              : 'BudgetPeriod',
    'CATEGORY_V1'                : 'Category',
    'CHECKINGACCOUNT_V1'         : 'Transaction',
    'CURRENCYFORMATS_V1'         : 'Currency',
    'CURRENCYHISTORY_V1'         : 'CurrencyHistory',
    'CUSTOMFIELDDATA_V1'         : 'FieldValue',
    'CUSTOMFIELD_V1'             : 'Field',
    'INFOTABLE_V1'               : 'Info',
    'PAYEE_V1'                   : 'Payee',
    'REPORT_V1'                  : 'Report',
    'SETTING_V1'                 : 'Setting',
    'SHAREINFO_V1'               : 'TransactionShare',
    'SPLITTRANSACTIONS_V1'       : 'TransactionSplit',
    'STOCKHISTORY_V1'            : 'StockHistory',
    'STOCK_V1'                   : 'Stock',
    'TAGLINK_V1'                 : 'TagLink',
    'TAG_V1'                     : 'Tag',
    'TRANSLINK_V1'               : 'TransactionLink',
    'USAGE_V1'                   : 'Usage',
}

# convert DB type to C++ type
dbtype_ctype = {
    'TEXT'    : 'wxString',
    'NUMERIC' : 'double',
    'INTEGER' : 'int64',
    'REAL'    : 'double',
    'BLOB'    : 'wxString',
    'DATE'    : 'wxDateTime',
}

# convert DB type to C++ function
dbtype_function = {
    'TEXT'    : 'GetString',
    'NUMERIC' : 'GetDouble',
    'INTEGER' : 'GetInt64',
    'REAL'    : 'GetDouble',
}

# }}}

# {{{ def is_ascii(s)

# http://stackoverflow.com/questions/196345/how-to-check-if-a-string-in-python-is-in-ascii
def is_ascii(s):
    """Class: Check for Ascii String"""
    if isinstance(s, str):
        return all(ord(c) < 128 for c in s)
    return False

# }}}
# {{{ def is_trans(s)

def is_trans(s):
    """Check translation requirements for cpp"""
    if isinstance(s, int):
        return False

    if not is_ascii(s): # it is unicode string
        return True

    if len(s) > 4 and s[0:4] == "_tr_": # requires wxTRANSLATE for cpp
        return True

    return False

# }}}
# {{{ def adjust_translate(s)

def adjust_translate(s):
    """Return the correct translated syntax for c++"""
    trans_str = s.replace("_tr_", "").replace('"','')
    trans_str = '_("' + trans_str + '")'

    return trans_str

# }}}
# {{{ def translation_for(s)

def translation_for(s):
    """Return the correct translated syntax for c++"""
    trans_str = ''
    if not is_ascii(s):  # it is unicode string
        if len(s) > 4 and s[0:4] == "_tr_": # requires wxTRANSLATE for cpp
            trans_str = adjust_translate(s)
        else:
            trans_str = 'L"%s"' % s
    else:
        trans_str = adjust_translate(s)

    return trans_str

# }}}

# {{{ def get_table_a(cursor)

# https://github.com/django/django/blob/master/django/db/backends/sqlite3/introspection.py
def get_table_a(cursor):
    "Return a list of table (name, sql) in a database."
    # Skip the sqlite_sequence system table used for key autoincrement.
    cursor.execute("""
        SELECT name, sql FROM sqlite_master
        WHERE type='table' AND NOT name='sqlite_sequence'
        ORDER BY name""")
    return [(row[0], row[1]) for row in cursor.fetchall()]


# }}}
# {{{ def get_index_a(cursor, table_name)

def get_index_a(cursor, table_name):
    "Return a list of index (name, sql) for a table."
    # Skip the sqlite_autoindex_* system index.
    cursor.execute("""
        SELECT name, sql FROM sqlite_master
        WHERE type='index' AND name NOT LIKE 'sqlite_autoindex_%%' AND tbl_name = '%s'
        ORDER BY name""" % table_name)
    return [(row[0], row[1]) for row in cursor.fetchall()]

# }}}
# {{{ def get_field_a(cursor, table_name)

def get_field_a(cursor, table_name):
    "Return a list of field (cid, name, type, null_ok, pk) for a table."
    cursor.execute('PRAGMA table_info(%s)' % table_name)
    # cid, name, type, notnull, dflt_value, pk
    return [{
        'cid'     : field[0],
        'name'    : field[1],
        'type'    : field[2].upper(),
        'null_ok' : not field[3],
        'pk'      : field[5],     # undocumented
    } for field in cursor.fetchall()]

# }}}
# {{{ def get_data_a(cursor, table_name)

def get_data_a(cursor, table_name):
    "Return a list of row data in a table."
    cursor.execute("select * from %s" % table_name)
    return cursor.fetchall()

# }}}

# {{{ class Table

class Table:
    """ Defines a database table in SQLite3"""
    # {{{ def __init__(self, cursor, table_name_, table_sql_)

    def __init__(self, cursor, table_name_, table_sql_):
        self.table_name = table_name_
        self.table_sql = table_sql_

        #self.class_name = 'DB_Table_' + self.table_name
        #self.file_basename = 'DB_Table_' + self.table_name.title()
        self.class_basename = table_class_basename.get(self.table_name, self.table_name + '_')
        self.class_name = self.class_basename + 'Table'
        self.file_basename = self.class_name

        self.index_a = get_index_a(cursor, self.table_name)
        self.field_a = get_field_a(cursor, self.table_name)
        self.data_a = get_data_a(cursor, self.table_name)

        self.field_pk = [f for f in self.field_a if f['pk']][0]
        self.field_other_a = [f for f in self.field_a if not f['pk']]

    # }}}
    # {{{ def generate_table_h(self, header)

    def generate_table_h(self, header):
        """ Generate .h file for the table class"""

        # short names
        dt = self.table_name
        cb = self.class_basename
        cc = self.class_basename + 'Col'
        cr = self.class_basename + 'Row'
        ct = self.class_name
        fa = self.field_a
        fp = self.field_pk
        fo = self.field_other_a

        # {{{ include

        code = '''
#pragma once

#include "%s.h"
''' % factory_basename

        # }}}
        # {{{ struct *Col ...

        code += '''
// Columns in database table %s
struct %s
{''' % (dt, cc)

        # }}}
        # {{{ enum COL_ID

        code += '''
    enum COL_ID
    {
        COL_ID_%s = 0''' % fp['name'].upper()

        for f in fo:
            code += ''',
        COL_ID_%s''' % f['name'].upper()

        code += ''',
        COL_ID_size
    };

    static const wxArrayString COL_NAME_A;
    static const COL_ID PRIMARY_ID;
    static const wxString PRIMARY_NAME;

    static wxString col_name(COL_ID col_id) { return COL_NAME_A[col_id]; }
'''

        # }}}
        # {{{ struct (COLUMN_NAME)

        for f in fa:
            code += '''
    struct %s : public TableOpV<%s>
    {
        static COL_ID col_id() { return COL_ID_%s; }
        static wxString col_name() { return COL_NAME_A[COL_ID_%s]; }
        explicit %s(const %s &v): TableOpV<%s>(OP_EQ, v) {}
        explicit %s(OP op, const %s &v): TableOpV<%s>(op, v) {}
    };
''' % (
                f['name'].upper(), dbtype_ctype[f['type']],
                f['name'].upper(),
                f['name'].upper(),
                f['name'], dbtype_ctype[f['type']], dbtype_ctype[f['type']],
                f['name'], dbtype_ctype[f['type']], dbtype_ctype[f['type']]
            )

        # }}}
        # {{{ ... struct *Col

        code += '''};
'''
        # }}}

        # {{{ struct *Row ...

        code += '''
// A single record in database table %s
struct %s
{
    using Col = %s;
    using COL_ID = Col::COL_ID;
''' % (dt, cr, cc)

        # }}}
        # {{{ member variables

        code += '''
    %s %s; // primary key''' % (dbtype_ctype[fp['type']], fp['name'])

        for f in fo:
            code += '''
    %s %s;''' % (
                dbtype_ctype[f['type']], f['name']
            )

        code += '''
'''

        # }}}
        # {{{ instance methods

        code += '''
    explicit %s();
    explicit %s(wxSQLite3ResultSet& q);
    %s(const %s& other) = default;
''' % (cr, cr, cr, cr)

        code += '''
    int64 id() const { return %s; }
    void id(const int64 id) { %s = id; }
    void destroy() { delete this; }

    bool equals(const %s* r) const;
    void to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const;
    void from_select_result(wxSQLite3ResultSet& q);
    wxString to_json() const;
    void as_json(PrettyWriter<StringBuffer>& json_writer) const;
    row_t to_row_t() const;
    void to_template(html_template& t) const;
''' % (fp['name'], fp['name'], cr)

        code += '''
    %s& operator=(const %s& other);
    bool operator< (const %s& other) const { return id() < other.id(); }
    bool operator< (const %s* other) const { return id() < other->id(); }
''' % (cr, cr, cr, cr)

        # }}}
        # {{{ match

        code += '''
    template<typename C>
    bool match(const C&)
    {
        return false;
    }

    // TODO: check if col.m_operator == OP_EQ
'''

        for f in fa:
            ftype = dbtype_ctype[f['type']]
            if ftype == 'wxString':
                code += '''
    bool match(const Col::%s& col)
    {
        return %s.CmpNoCase(col.m_value) == 0;
    }
''' % (f['name'], f['name'])
            else:
                code += '''
    bool match(const Col::%s& col)
    {
        return %s == col.m_value;
    }
''' % (f['name'], f['name'])

        code += '''
    template<typename Arg1, typename... Args>
    bool match(const Arg1& arg1, const Args&... args)
    {
        return (match(arg1) && ... && match(args));
    }
'''

        # }}}
        # {{{ SorterBy

        for f in fa:
            code += '''
    struct SorterBy%s
    {
        bool operator()(const %s& x, const %s& y)
        {''' % (f['name'], cr, cr)

            if f['name'] in ['ACCOUNTNAME', 'CATEGNAME', 'PAYEENAME', 'SUBCATEGNAME']:
                code += '''
            // Locale case-insensitive
            return std::wcscoll(x.%s.Lower().wc_str(), y.%s.Lower().wc_str()) < 0;
''' % (f['name'], f['name'])

            elif f['name'] in ['CURRENCYNAME']:
                code += '''
            return wxGetTranslation(x.%s) < wxGetTranslation(y.%s);
''' % (f['name'], f['name'])

            else:
                code += '''
            return x.%s < y.%s;
''' % (f['name'], f['name'])

            code += '''        }
    };
'''

        # }}}
        # {{{ ... struct *Row

        code += '''};
'''
        # }}}

        # {{{ struct *Table ...

        code += '''
// Interface to database table %s
struct %s : public TableFactory<%s>
{''' % (dt, ct, cr)

        # }}}
        # {{{ using (COLUMN_NAME)

        code += '''
    // Use Col::(COLUMN_NAME) until model provides similar functionality based on Data.'''

        for f in fa:
            code += '''
    using %s = Col::%s;''' % (f['name'].upper(), f['name'].upper())

        code += '''
'''

        # }}}
        # {{{ instance methods

        code += '''
    %s();
    ~%s();

    void ensure_data() override;
''' % (ct, ct)

        # }}}
        # {{{ ... struct *Table

        code += '''};
'''
        # }}}

        file_name = self.file_basename + '.h'
        print ('Generate %s (source code for %s)' % (file_name, dt))
        rfp = codecs.open(file_name, 'w', 'utf-8-sig')
        rfp.write(header
            .replace('@file', file_name)
            .replace('@brief', 'Interface to database table %s' % dt)
        )
        rfp.write(code)
        rfp.close()

    # }}}
    # {{{ def generate_table_cpp(self, header)

    def generate_table_cpp(self, header):
        """ Generate .cpp file for the table class"""

        # short names
        dt = self.table_name
        cb = self.class_basename
        cc = self.class_basename + 'Col'
        cr = self.class_basename + 'Row'
        ct = self.class_name
        fa = self.field_a
        fp = self.field_pk
        fo = self.field_other_a

        # {{{ include

        code = '''
#include "%s.tpp"
#include "%s.h"
''' % (factory_basename, self.file_basename)

        code += '''
template class TableFactory<%s>;
''' % cr

        # }}}
        # {{{ *Col

        code += '''
// List of column names in database table %s,
// in the order of %s::COL_ID.
const wxArrayString %s::COL_NAME_A = {
    "%s"%s
};

const %s::COL_ID %s::PRIMARY_ID = COL_ID_%s;
const wxString %s::PRIMARY_NAME = COL_NAME_A[COL_ID_%s];
''' % (
            dt, cc,
            cc,
            fp['name'], ''.join([',\n    "' + f['name'] + '"' for f in fo]),
            cc, cc, fp['name'].upper(),
            cc, fp['name'].upper()
        )

        # }}}

        # {{{ *Row::*Row

        code += '''
%s::%s()
{''' % (cr, cr)

        for f in fa:
            ftype = dbtype_ctype[f['type']]
            if ftype == 'wxString':
                continue
            elif ftype == 'double':
                code += '''
    %s = 0.0;''' % f['name']
            elif ftype == 'int64':
                code += '''
    %s = -1;''' % f['name']

        code += '''
}

%s::%s(wxSQLite3ResultSet& q)
{
    from_select_result(q);
}
''' % (cr, cr)

        # }}}
        # {{{ *Row::equals

        code += '''
bool %s::equals(const %s* r) const
{''' % (cr, cr)

        for f in fa:
            ftype = dbtype_ctype[f['type']]
            if ftype == 'int64' or ftype == 'double':
                code += '''
    if ( %s != r->%s) return false;''' % (f['name'], f['name'])
            elif ftype == 'wxString':
                code += '''
    if (!%s.IsSameAs(r->%s)) return false;''' % (f['name'], f['name'])

        code += '''

    return true;
}
'''

        # }}}
        # {{{ *Row::to_insert_stmt, *Row::from_select_result

        code += '''
// Bind a Row record to database statement.
// Use the id argument instead of the row id.
void %s::to_insert_stmt(wxSQLite3Statement& stmt, int64 id) const
{''' % cr

        for i, f in enumerate(fo):
            code += '''
    stmt.Bind(%d, %s);''' % (i+1, f['name'])

        code += '''
    stmt.Bind(%d, id);
}
''' % len(fa)

        code += '''
void %s::from_select_result(wxSQLite3ResultSet& q)
{''' % cr

        for f in fa:
            code += '''
    %s = q.%s(%d);''' % (f['name'], dbtype_function[f['type']], f['cid'])

        code += '''
}
'''

        # }}}
        # {{{ *Row::to_json, *Row::as_json

        code += '''
// Return the data record as a json string
wxString %s::to_json() const
{
    StringBuffer json_buffer;
    PrettyWriter<StringBuffer> json_writer(json_buffer);

    json_writer.StartObject();			
    as_json(json_writer);
    json_writer.EndObject();

    return json_buffer.GetString();
}
''' % cr

        code += '''
// Add the field data as json key:value pairs
void %s::as_json(PrettyWriter<StringBuffer>& json_writer) const
{''' % cr

        for f in fa:
            type = dbtype_ctype[f['type']]
            if type == 'int64':
                code += '''
    json_writer.Key("%s");
    json_writer.Int64(%s.GetValue());
''' % (f['name'], f['name'])
            elif type == 'double':
                code += '''
    json_writer.Key("%s");
    json_writer.Double(%s);
''' % (f['name'], f['name'])
            elif type == 'wxString':
                code += '''
    json_writer.Key("%s");
    json_writer.String(%s.utf8_str());
''' % (f['name'], f['name'])
            else:
                assert "Field type Error"

        code += '''}
'''

        # }}}
        # {{{ *Row::to_row_t, *Row::to_template

        code += '''
row_t %s::to_row_t() const
{
    row_t row;
''' % cr

        for f in fa:
            code += '''
    row(L"%s") = %s%s;''' % (
            f['name'],
            f['name'], '.GetValue()' if f['type'] == 'INTEGER' else ''
        )

        code += '''

    return row;
}
'''

        code += '''
void %s::to_template(html_template& t) const
{''' % cr

        for f in fa:
            code += '''
    t(L"%s") = %s%s;''' % (
            f['name'],
            f['name'], '.GetValue()' if f['type'] == 'INTEGER' else ''
        )

        code += '''
}
'''

        # }}}
        # {{{ *Row::operator=

        code += '''
%s& %s::operator=(const %s& other)
{
    if (this == &other) return *this;
''' % (cr, cr, cr)

        for f in fa:
            code += '''
    %s = other.%s;''' % (f['name'], f['name'])

        code += '''

    return *this;
}
'''

        # }}}

        # {{{ *Table:*Table

        create_query = self.table_sql.replace('\n', '')
        drop_query = 'DROP TABLE IF EXISTS %s' % dt

        index_query_a = ''
        for index_name, index_sql in self.index_a:
            index_sql_tokens = index_sql.split()
            index_sql_tokens.insert(2, 'IF')
            index_sql_tokens.insert(3, 'NOT')
            index_sql_tokens.insert(4, 'EXISTS')
            index_ensure_sql = ' '.join(index_sql_tokens)
            if index_query_a:
                index_query_a += ','
            index_query_a += '''
        "''' + index_ensure_sql.replace('\n', '') + '"'

        insert_query = 'INSERT INTO %s(%s, %s) VALUES(%s)' % (
            dt,
            ', '.join([f['name'] for f in fo]), fp['name'],
            ', '.join(['?' for f in fa])
        )
        update_query = 'UPDATE %s SET %s WHERE %s = ?' % (
            dt,
            ', '.join([f['name'] + ' = ?' for f in fo]),
            fp['name']
        )
        delete_query = 'DELETE FROM %s WHERE %s = ?' % (
            dt, fp['name']
        )
        select_query = 'SELECT %s FROM %s' % (
            ', '.join([f['name'] for f in fa]), dt
        )

        code += '''
%s::%s()
{
    m_table_name = "%s";

    m_create_query = "%s";

    m_drop_query = "%s";

    m_index_query_a = {%s
    };

    m_insert_query = "%s";

    m_update_query = "%s";

    m_delete_query = "%s";

    m_select_query = "%s";
}
''' % (
            ct, ct,
            dt,
            create_query,
            drop_query,
            index_query_a,
            insert_query,
            update_query,
            delete_query,
            select_query
        )

        code += '''
// Destructor: clears any data records stored in memory
%s::~%s()
{
    delete fake_;
    destroy_cache();
}
''' % (ct, ct)

        # }}}
        # {{{ ensure_data

        code += '''
void %s::ensure_data()
{
    m_db->Begin();''' % ct

        rf1, rf2, rf3 = '', '', ''
        for r in self.data_a:
            rf2 = ', '.join(["'%s'" if is_trans(i) else "'%s'" % i for i in r])
            rf3 = ', '.join([translation_for(i) for i in r if is_trans(i)])
            if rf2.find('%s') >= 0:
                rf3 = ', ' + rf3
            rf1 = '"INSERT INTO %s VALUES (%s)"%s' % (dt, rf2, rf3)
            if rf2.find('%s') >= 0:
                rf1 = 'wxString::Format(' + rf1 + ')'
            code += '''
    m_db->ExecuteUpdate(%s);''' % (rf1)

        code += '''
    m_db->Commit();
}
'''

        # }}}

        file_name = self.file_basename + '.cpp'
        print ('Generate %s (source code for %s)' % (file_name, dt))
        rfp = codecs.open(file_name, 'w', 'utf-8-sig')
        rfp.write(header
            .replace('@file', file_name)
            .replace('@brief', 'Implementation of the interface to database table %s' % dt)
        )
        rfp.write(code)
        rfp.close()

    # }}}
    # {{{ def generate_patch_currency(self)

    def generate_patch_currency(self, patch_filename, only_unicode=False):
        """Generate patch for CURRENCYFORMATS_V1"""
        code = '''-- MMEX Debug SQL - Update --
-- Required MMEX db version: 10
-- This script adds missing currencies and overwrites currency parameterss.'''
        if only_unicode:
            code += '''
-- Only currencies with unicode text are affected.'''

        for row in self.data_a:
            values = ', '.join(["%s='%s'" % (k, row[k]) for k in row.keys() if k.upper() != 'CURRENCYID' and k.upper() != 'CURRENCY_SYMBOL'])
            values = values.replace('_tr_', '')

            if not only_unicode or not is_ascii(values):
                code += '''
INSERT OR IGNORE INTO %s (CURRENCYNAME, CURRENCY_SYMBOL) VALUES ('%s', '%s');
UPDATE OR IGNORE %s SET %s WHERE CURRENCY_SYMBOL='%s';''' % (
    self.table_name, row['CURRENCYNAME'].replace('_tr_', ''), row['CURRENCY_SYMBOL'],
    self.table_name, values, row['CURRENCY_SYMBOL']
)

        code += '''
'''

        print ('Generate %s (patch for CURRENCYFORMATS_V1)' % patch_filename)
        rfp = codecs.open(patch_filename, 'w', 'utf-8')
        rfp.write(code)
        rfp.close()

    # }}}
# }}}
# {{{ __main__

if __name__ == '__main__':
    # {{{ header

    header = '''// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013-%s Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017-2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022      Mark Whalley (mark@ipx.co.uk)
 *      Copyright: (c) 2026      George Ef (george.a.ef@gmail.com)
 *
 *      @file
 *
 *      @brief
 *
 *      @author [%s]
 *
 *      Revision History:
 *          AUTO GENERATED at %s.
 *          DO NOT EDIT!
 */
//=============================================================================
'''% (datetime.date.today().year, os.path.basename(__file__), str(datetime.datetime.now()))

    # }}}
    sql_file, conn, cursor = None, None, None
    try:
        sql_file = sys.argv[1]
        conn = sqlite3.connect(":memory:")
        conn.row_factory = sqlite3.Row
        cursor = conn.cursor()
    except:
        print (__doc__)
        sys.exit(1)

    sql = ""
    sql_txt = '''-- NOTE:
-- This file has been AUTO GENERATED from database/tables.sql
-- All translation markers "_tr_" have been removed.
-- This file can be used to manually generate a database.

'''

    for line_bytes in open(sql_file, 'rb'):
        line = line_bytes.decode('utf-8')
        sql = sql + line

        if line.find('_tr_') > 0: # Remove _tr_ identifyer for wxTRANSLATE
            line = line.replace('_tr_', '')

        sql_txt = sql_txt + line

    print ('Generate %s (clean database without translation)' % tables_sql_filename)
    file_data = codecs.open(tables_sql_filename, 'w', 'utf-8')
    file_data.write(sql_txt)
    file_data.close()

    cursor.executescript(sql)

    for table_name, table_sql in get_table_a(cursor):
        table = Table(cursor, table_name, table_sql)
        table.generate_table_h(header)
        table.generate_table_cpp(header)
        if table_name.upper() == 'CURRENCYFORMATS_V1':
            table.generate_patch_currency(patch_currency_filename, False)
            table.generate_patch_currency(patch_currency_utf8_filename, True)

    conn.close()
    print ('Done')

# }}}
