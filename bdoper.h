/* 
 * File:   bdoper.h
 * Author: demiin
 *
 * Created on February 27, 2015, 2:32 PM
 */

#ifndef BDOPER_H
#define	BDOPER_H

#include <string>
#include <iostream>
#ifdef __linux__ 
    #include <postgresql/libpq-fe.h>
#elif _WIN32
    #include <9.1/libpq-fe.h>
#endif
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>
#include "parser.h"
#include "fOper.h"

enum tables {SERIES, AUTOR, BOOKNAME};


#define DEBUG 1

using namespace std;

class bdoper {
public:
    bdoper();
    bdoper(const bdoper& orig);
    virtual ~bdoper();
    
    bool connectToBD();
    void disconnect();
    bool isConnected(){return _online;};
    bool sendQuery(string* query);
    void clearTable(string table);
    string insertRow(tables table, string data);
    void insertRow(tables table, vector<string> data);
    string insertBook(tables table, string bookname, int series, int autor, vector<where>locate);
    vector<string> getBooksByFilter(string filter);
    void setLimit(string limit) {_limit = limit;};
    void setFilial(string filial) {_filial = filial;};
    vector<string> getFilials();
    void setDBNAME_BOOKBASE(string DBNAME_BOOKBASE) {
        this->DBNAME_BOOKBASE = DBNAME_BOOKBASE;
    }
    vector<string> getBookInfo(string author, string bookname);
    
    const string HOSTBD = "192.168.9.250";
    string DBNAME_BOOKBASE = "bookcatalog";
    const string DBLOGIN_BOOKBASE = "oa";
    const string DBPASS_BOOKBASE = "oa";

    
private:
    PGconn* db;
    bool _online = false;
    fOper* f;
    string _limit;
    string _filial;
    void queryError(PGresult* result);
    void getResult(PGresult** result, unsigned short int items, vector<string>* container);

};

#endif	/* BDOPER_H */

