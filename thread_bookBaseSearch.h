/* 
 * File:   thread_bookBaseSearch.h
 * Author: demiin
 *
 * Created on March 7, 2015, 11:40 AM
 */

#ifndef THREAD_BOOKBASESEARCH_H
#define	THREAD_BOOKBASESEARCH_H

#include <QObject>
#include <string>
#include <iostream>
#include "bdoper.h"

using namespace std;

class thread_bookBaseSearch : public QObject{
    Q_OBJECT
public:
    
    thread_bookBaseSearch();
    virtual ~thread_bookBaseSearch();
    void setFilterSearch(string searchFilter) {_filter = searchFilter;};
    void setLimitSearch(string limit) {bdOper->setLimit(limit);};
    void setFilialToSearch(string filial) {bdOper->setFilial(filial);};
    void setBDConn(bdoper* bd) {bdOper = bd;};
    void setSearchBookInfo(string author, string bookname) {
        this->_searchBookInfo_author = author;
        this->_searchBookInfo_bookname = bookname;
    }
    void setBDName(string bd) {
        bdOper->setDBNAME_BOOKBASE(bd);
    }
    
private:
    string _filter;
    string _limit;
    string _searchBookInfo_author;
    string _searchBookInfo_bookname;
    bdoper* bdOper;
    
public slots:    
    void working_SearchBooks();
    void working_GetBookInfo();
    void stop();
    
signals:
    void finished(vector<string>);
};

#endif	/* THREAD_BOOKBASESEARCH_H */

