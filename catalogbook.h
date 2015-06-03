/* 
 * File:   catalogbook.h
 * Author: demiin
 *
 * Created on February 25, 2015, 4:04 PM
 */

#ifndef _CATALOGBOOK_H
#define	_CATALOGBOOK_H

#include "ui_catalogbook.h"
#include "bdoper.h"

#include <iostream>
#include <QTimer>
#include <QThread>
#include <QModelIndex>
#include <boost/lexical_cast.hpp>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QTemporaryFile>
#include <boost/algorithm/string.hpp>
#include <qnamespace.h>
#include <QKeyEvent>
#include <Qt>
#include "thread_bookBaseSearch.h"

//#define VIEW_DEBUG_CTRLS 1

struct books_table{
    string autor;
    string bookname;
    string series;
    vector<string> contains;
    vector<string> filialsHave;
};

using namespace std;


class catalogbook : public QMainWindow {
    Q_OBJECT
public:
    catalogbook();
    virtual ~catalogbook();
private:
    Ui::catalogbook frmCatalog;
    bdoper bdOper;
    QTimer* timerStayConnected;
    QTimer* timerVisibleProgress;
    QTimer* timerHideFilialCB;
    const int MIN_SIMB = 2;
    const int TIMER_CONNECT = 1000;
    const int TIMER_PROGRESS = 40;
    const int TIMER_HIDE = 600;
    string _limit = "500";
    bool frontier = true;
    QString filter;
    int rgba = 0;
    string lastSearch;
    string filialAddressToSearch;
    map<string, string> filialsAdr;
    books_table listFoundedBooks;
    
    void loadParams();
    
    
signals:
    void stopAll();
    void closed(string what);
    
private slots:
    void slot_SearchQueryTextChanged(QString text);
    void threadSearchFinished(vector<string> listBooks);
    void threadSearchBookInfoFinished(vector<string>);
    void slot_TimerStayConnectedTimeout();
    void slot_TimerVisibleProgressTimeout();
    void slot_TimerHideTimeout();
    void slot_delayChanged(int);
    void slot_limitChanged(QString);
    void slot_timerBoostChanged(int);
    void slot_filterAddressChanged(QString);
    void slot_TableClicked(QModelIndex);
    void slot_doneDownloadPic(QNetworkReply*);

protected:
   void resizeEvent(QResizeEvent *);  // virtual        
   void closeEvent(QCloseEvent *);
    void keyPressEvent(QKeyEvent *);   
};

#endif	/* _CATALOGBOOK_H */
