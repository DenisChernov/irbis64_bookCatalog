/* 
 * File:   engine.h
 * Author: demiin
 *
 * Created on April 16, 2015, 2:24 PM
 */

#ifndef ENGINE_H
#define	ENGINE_H

#include <QObject>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include "parser.h"
#include <vector>
#include <map>
#include <boost/foreach.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <time.h>
#include <curl/curl.h>

using namespace std;
using boost::asio::ip::tcp;

struct upload_status {
  int lines_read;
  vector<string> data;
};

class engine : public QObject{
    Q_OBJECT
public:
    engine();
    virtual ~engine();
    
    enum WORK {AUTH, ALL_DATA};
    struct fullrecords {
        vector<string> book;
        vector<string> reader;
    };
    
    void login_unlogin(string codeAPM, string codeCommand);    
    void setReaderNumber(string number) {_readerNumb = number;};
    void setBookToProlong(map<string, vector<string> >books) {_booksToProlong = books;};
    map<string, vector<string>> getReaderData();
    void setCurrentWork(WORK work) {_curWork = work;};
    void setInvNumber(string _invNumber) {
        this->_invNumber = _invNumber;
    }

    
private:
    const string MAGIC_CODE = "31771";
    size_t reqCounter = 1;
    boost::asio::io_service io_service;
    string irbis64_login    = "irbisoft";
    string irbis64_password = "9f9@7Nuq";
    string irbis64_countAnswers = "1000";
    string server64         = "192.168.9.20";    
    boost::asio::streambuf _request;
    vector<string> fils;
    parser pars;
    string _readerNumb;
    WORK _curWork;
    string _invNumber;
    map<string, vector<string> > _booksToProlong;
    
    
    string sendRequest(boost::asio::streambuf* request);
    void makeRequest(string codeAPM, string codeCommand, string request);
    bool findReader(string number);
    
    static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp);   
    
    
public slots:
    void working();
    void makeReturn();
    void stop();
    void sendProlongRequest();
    
signals:
    void finished(map<string, vector<string>>);
    void finishReturnBook(bool success);
    void sendProlongRequestComplited();
    void closeWithoutAuth();
};

#endif	/* ENGINE_H */

