/* 
 * File:   thread_bookBaseSearch.cpp
 * Author: demiin
 * 
 * Created on March 7, 2015, 11:41 AM
 */

#include "thread_bookBaseSearch.h"

thread_bookBaseSearch::thread_bookBaseSearch() {
    bdOper = new bdoper();
}

thread_bookBaseSearch::~thread_bookBaseSearch() {
}

void thread_bookBaseSearch::stop() {
    cout << "thread with filter: \"" << _filter << "\" is stopped"<< endl;

}

void thread_bookBaseSearch::working_SearchBooks() {
    cout << "thread with filter: \"" << _filter << "\" is started"<< endl;
    bdOper->connectToBD();
    vector<string>list = bdOper->getBooksByFilter(_filter);
    emit finished(list);
}

void thread_bookBaseSearch::working_GetBookInfo() {
    cout << "thread with search filter: \"" << _searchBookInfo_author << " -  " <<  _searchBookInfo_bookname << "\" is started" << endl;
    bdOper->connectToBD();
    vector<string> list = bdOper->getBookInfo(_searchBookInfo_author, _searchBookInfo_bookname);
    emit finished(list);
}
