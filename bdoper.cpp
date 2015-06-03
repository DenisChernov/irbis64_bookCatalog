/* 
 * File:   bdoper.cpp
 * Author: demiin
 * 
 * Created on February 27, 2015, 2:32 PM
 */

#include "bdoper.h"
#include "parser.h"

bdoper::bdoper() {
    f = new fOper("errors.log");
    
}

bdoper::bdoper(const bdoper& orig) {
}

bdoper::~bdoper() {
}

bool bdoper::connectToBD()
{

    string connStr = boost::str(boost::format("user=%s password=%s dbname=%s hostaddr=%s") % DBLOGIN_BOOKBASE % DBPASS_BOOKBASE % DBNAME_BOOKBASE % HOSTBD);
    //string connStr = boost::str(boost::format("user=%s password=%s dbname=%s hostaddr=%s") % login % pass % dbname % HOSTBD);
    db = PQconnectdb(connStr.c_str());

    if (PQstatus(db) == CONNECTION_BAD)
    {
        cout << "Unable connect to DB: " << DBNAME_BOOKBASE << endl;
        _online = false;
        return false;
    }
    else
    {
        cout << "connected to " << HOSTBD << " % " << DBNAME_BOOKBASE << endl;
        _online = true;
        return true;
    }
}

void bdoper::disconnect()
{
    _online = false;
    PQfinish(db);
}

void bdoper::clearTable(string table) 
{
    string query = boost::str(boost::format("TRUNCATE TABLE %s; ALTER SEQUENCE %s_id_seq RESTART WITH 1;") % table % table);
    sendQuery(&query);
}

bool bdoper::sendQuery(string* query) 
{
    PGresult *result = PQexec(db, (*query).c_str());
    if (PQresultStatus(result) != PGRES_COMMAND_OK)
    {
        queryError(result);
        return false;
    }
    else
    {
        //cout << "...inserted!!" << endl;
        return true;
    }   
}

void bdoper::queryError(PGresult* result)
{
#ifdef DEBUG    
    cerr << PQresultErrorMessage(result) << endl;
#endif
}

string bdoper::insertRow(tables table, string data) 
{
    vector<string> list;
    string tbl;
    switch (table)
    {
        case SERIES:
        {
            tbl = "series";
            break;
        }
        case AUTOR:
        {
            tbl = "autor";
            break;
        }
    }
    
    parser pars;
    //pars.remove
    
    string query = boost::str(boost::format("INSERT INTO %s VALUES('%s')") % tbl % data);
    sendQuery(&query);
    
    query = boost::str(boost::format("SELECT id FROM %s WHERE name = '%s'") % tbl % data);
    PGresult* result = PQexec(db, query.c_str());
    getResult(&result, 1, &list);
    
    return list.front();
}

void bdoper::insertRow(tables table, vector<string> data) 
{
   

}

void bdoper::getResult(PGresult** result, unsigned short int items, vector<string>* container)
{
    if (PQresultStatus(*result) != PGRES_TUPLES_OK)
    {
        queryError(*result);
    }
    else
    {
        for (unsigned short int i = 0; i < PQntuples(*result); i++)
        {
            for (unsigned short int j = 0; j < items; j++)
    			(*container).push_back(boost::lexical_cast<string>(PQgetvalue(*result, i, j)));
        }
    }
}

string bdoper::insertBook(tables table, string bookname, int series, int autor, vector<where> locate) 
{
    vector<string> list;
    string filials_locate;
    string tbl;
    switch (table)
    {
        case SERIES:
        {
            tbl = "series";
            break;
        }
        case AUTOR:
        {
            tbl = "autor";
            break;
        }
        case BOOKNAME:
        {
            tbl = "books";
            break;
        }
    }
    
    vector<where>::const_iterator it = locate.begin();
    while (it != locate.end())
    {
        filials_locate += it->filial;
        if (it +1 != locate.end())
            filials_locate += ", ";
        it++;
    }
    
    string query = boost::str(boost::format("INSERT INTO %s VALUES('%s', %d, %d, '%s')") % tbl % bookname % series % autor % filials_locate);
    if (!sendQuery(&query))
    {
        f->openW();
        f->write("error on: " + query);
        query = boost::str(boost::format("SELECT id, locate FROM %s WHERE bookname ILIKE '%s'") % tbl % bookname);
        sendQuery(&query);
        PGresult* result = PQexec(db, query.c_str());
        getResult(&result, 2, &list);
        filials_locate += ", " + list.back();
        query = boost::str(boost::format("UPDATE  %s SET locate ='%s' WHERE id = %s") % tbl % filials_locate % list.front());
        sendQuery(&query);
    
        return query;
    }
    return "";
}

vector<string> bdoper::getBooksByFilter(string filter) 
{
    vector<string> founded_books;
    string query = "SELECT books.bookname, series.name, autor.name, UPPER(books.locate) FROM books LEFT OUTER JOIN series ON (books.series = series.id) LEFT  JOIN autor ON (books.autor = autor.id) WHERE (books.bookname ILIKE '%" + filter + "%' OR series.name ILIKE '%" + filter + "%' OR autor.name ILIKE '%" + filter + "%') AND books.locate ILIKE '%" +_filial + "%' LIMIT " + _limit + ";";
    PGresult* result = PQexec(db, query.c_str());
    getResult(&result, 4, &founded_books);
    
    return founded_books;
}

vector<string> bdoper::getFilials() {
    vector<string> filials;
    string query = boost::str(boost::format("SELECT * FROM filials;"));
    PGresult* result = PQexec(db, query.c_str());
    getResult(&result, 3, &filials);
    
    return filials;
}

vector<string> bdoper::getBookInfo(string author, string bookname) {
    vector<string> bookinfo;
    string query = "SELECT pic_addr, \"desc\" FROM books WHERE autor ILIKE '%" + author + "%' AND bookname ILIKE '%" + bookname + "%';";
    cout << query << endl;
    PGresult* result = PQexec(db, query.c_str());
    getResult(&result, 2, &bookinfo);
    
    return bookinfo;
}
