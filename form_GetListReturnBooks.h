/* 
 * File:   form_GetListReturnBooks.h
 * Author: demiin
 *
 * Created on April 16, 2015, 12:46 PM
 */

#ifndef _FORM_GETLISTRETURNBOOKS_H
#define	_FORM_GETLISTRETURNBOOKS_H

#include "ui_form_GetListReturnBooks.h"
#include "engine.h"
#include "form_Auth.h"
#include "form_ReturnDialog.h"
#include "form_Prolong.h"
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <QThread>
#include <QTimer>
#include <map>
#include <vector>
#include <QTableWidgetItem>
#include <qnamespace.h>
#include <QKeyEvent>

using namespace std;


class form_GetListReturnBooks : public QMainWindow {
    Q_OBJECT
public:
    form_GetListReturnBooks();
    virtual ~form_GetListReturnBooks();
    void setReader(map<string, vector<string> > reader) {
        this->reader = reader;
    }

private:
    Ui::form_GetListReturnBooks frm_GetListReturnBooks;
    form_Auth* authWnd;
    QTimer* timerIDLE;
    const int TIME_IDLE = 1000 * 60 * 5; // ms * минута * количество минут
    const int WARNING_RETURN_DAY = 4;
    map<string,vector<string>> reader;
            
    void makeAuthCentered();
    void loadReaderData();
    void insertBooksJournalsOwned(vector<string>);
    void insertBooksJournalsReturned(vector<string>);
    
signals:
    void closed(string);
    void stopAll();

private slots:
    void slot_timerIdleTimeout();
    void slot_authentificated();
    void slot_changeSizeValue(int);
    void slot_ShowReturnDialog();
    void slot_showProlongDlg();
    void threadLoadReaderFinished(map<string, vector<string>>);
    void slot_closeWithoutAuth();
    
protected:
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *);
    void keyPressEvent(QKeyEvent *);
    
};

#endif	/* _FORM_GETLISTRETURNBOOKS_H */
