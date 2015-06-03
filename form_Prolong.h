/* 
 * File:   form_Prolong.h
 * Author: demiin
 *
 * Created on April 30, 2015, 1:52 PM
 */

#ifndef _FORM_PROLONG_H
#define	_FORM_PROLONG_H

#include "ui_form_Prolong.h"
#include <string>
#include <iostream>
#include <QThread>
#include <QCheckBox>
#include <boost/lexical_cast.hpp>
#include <QPushButton>
#include <vector>
#include "engine.h"


using namespace std;

enum class METHOD {EMAIL, MANUAL};

class form_Prolong : public QDialog {
    Q_OBJECT
public:
    form_Prolong(METHOD method);
    virtual ~form_Prolong();
    void setReaderNumb(string readerNumb) {
        this->readerNumb = readerNumb;
    }
    void setReaderData(map<string, vector<string> > readerData) {
        this->readerData = readerData;
    }
    void loadReaderData();
    
private:
    Ui::form_Prolong frm_Prolong;
    const int WARNING_RETURN_DAY = 4;
    string readerNumb;
    map<string,vector<string>> readerData;
    METHOD _method;

    void insertBooksJournalsOwned(vector<string>);
    
private slots:
    void threadLoadReaderFinished(map<string, vector<string>>);
    void slot_prolong();
    void threadProlongFinished();
    
signals:
    void stopAll();    
};

#endif	/* _FORM_PROLONG_H */
