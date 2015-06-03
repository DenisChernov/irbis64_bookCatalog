/*
 * File:   catalogbook.cpp
 * Author: demiin
 *
 * Created on February 25, 2015, 4:04 PM
 * 
 */

#include <boost/algorithm/string/case_conv.hpp>

#include "catalogbook.h"

catalogbook::catalogbook() {
    frmCatalog.setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint/* | WindowType::WindowStaysOnTopHint*/);
    loadParams();
    
#ifndef VIEW_DEBUG_CTRLS    
    frmCatalog.hsTimerBoost->setVisible(false);
    frmCatalog.lblDelay->setVisible(false);
    frmCatalog.lblLimit->setVisible(false);
    frmCatalog.leBoost->setVisible(false);
    frmCatalog.leLimit->setVisible(false);
    frmCatalog.leDelay->setVisible(false);
    frmCatalog.vsDelay->setVisible(false);
#endif    
    //bdOper = new bdoper();
    
    frmCatalog.twBookCatalog->horizontalHeader()->resizeSection(0, 220); // Автор
    frmCatalog.twBookCatalog->horizontalHeader()->resizeSection(3, 80); // Заказ
    
    connect(frmCatalog.leSearchQuery, SIGNAL(textChanged(QString)), this, SLOT(slot_SearchQueryTextChanged(QString)));
    
    timerStayConnected = new QTimer(this);
    timerStayConnected->setInterval(TIMER_CONNECT);
    connect(timerStayConnected, SIGNAL(timeout()), this, SLOT(slot_TimerStayConnectedTimeout()));

    timerVisibleProgress = new QTimer(this);
    timerVisibleProgress->setInterval(TIMER_PROGRESS);
    connect(timerVisibleProgress, SIGNAL(timeout()), this, SLOT(slot_TimerVisibleProgressTimeout()));
    
    timerHideFilialCB = new QTimer(this);
    timerHideFilialCB->setInterval(TIMER_HIDE);
    connect(timerHideFilialCB, SIGNAL(timeout()), this, SLOT(slot_TimerHideTimeout()));
    
    connect(frmCatalog.vsDelay, SIGNAL(valueChanged(int)), this, SLOT(slot_delayChanged(int)));
    frmCatalog.vsDelay->setValue(0);
    
    connect(frmCatalog.hsTimerBoost, SIGNAL(valueChanged(int)), this, SLOT(slot_timerBoostChanged(int)));
    frmCatalog.hsTimerBoost->setValue(12);
    
    connect(frmCatalog.leLimit, SIGNAL(textChanged(QString)), this, SLOT(slot_limitChanged(QString)));
    
    connect(frmCatalog.cbFilterAddress, SIGNAL(currentIndexChanged(QString)), this, SLOT(slot_filterAddressChanged(QString)));
    
    connect(frmCatalog.twBookCatalog, SIGNAL(clicked(QModelIndex)), this, SLOT(slot_TableClicked(QModelIndex)));
    
    //bdOper.connectToBD();
    
    
}

catalogbook::~catalogbook() {

}

void catalogbook::loadParams() 
{
    bdoper* bd = new bdoper();
    if (bd->connectToBD()) {
        frmCatalog.cbFilterAddress->addItem("");
        vector<string> filials = bd->getFilials();
        vector<string>::const_iterator it = filials.begin();
        while (it != filials.end()) {
            string tmp = it->data();
            ++it;
            tmp += ": " + string(it->data());
            ++it;
            frmCatalog.cbFilterAddress->addItem(QString::fromStdString(tmp));
            filialsAdr[tmp] = it->data();
            ++it;    
        }
        frmCatalog.cbFilterAddress->setCurrentIndex(0);
    }
}

void catalogbook::slot_doneDownloadPic(QNetworkReply* reply) {
    QTemporaryFile* m_TempFile = new QTemporaryFile();
    m_TempFile->open();
    m_TempFile->write(reply->readAll());
    m_TempFile->close();
    frmCatalog.lblCover->setText("<img height=\"271\" width=\"241\" src=\"" + m_TempFile->fileName() + "\" />");
    
    
}


void catalogbook::resizeEvent(QResizeEvent*) 
{
    frmCatalog.twCatalogList->setGeometry(frmCatalog.twCatalogList->x(), frmCatalog.twCatalogList->y(), this->width() - 146, this->height() - 121);    
    
    frmCatalog.twBookCatalog->setGeometry(8, frmCatalog.twBookCatalog->y(), frmCatalog.twCatalogList->width() - 46, frmCatalog.twCatalogList->height() - 30);
    
    frmCatalog.leSearchQuery->setGeometry(frmCatalog.leSearchQuery->x(), frmCatalog.leSearchQuery->y(), frmCatalog.twCatalogList->width() - 140, frmCatalog.leSearchQuery->height());
    frmCatalog.cbFilterAddress->move(frmCatalog.leSearchQuery->width() - 88, frmCatalog.cbFilterAddress->y());
    
    frmCatalog.twBookCatalog->horizontalHeader()->resizeSection(1, frmCatalog.twBookCatalog->width() / 2 - 100); // Заглавие
    frmCatalog.twBookCatalog->horizontalHeader()->resizeSection(2, frmCatalog.twBookCatalog->width() / 2 - 200); // Серия
    frmCatalog.twBookCatalog->horizontalHeader()->hideSection(3);
    frmCatalog.twBookCatalog->horizontalHeader()->hideSection(4);
    
}

void catalogbook::slot_filterAddressChanged(QString filterAddress) {
    filialAddressToSearch = filialsAdr[filterAddress.toStdString()];
    timerHideFilialCB->start();
    if (filter.length() > MIN_SIMB)
    {
        if (!timerStayConnected->isActive()) {
                timerStayConnected->start();
        }else {
            timerStayConnected->stop();
            timerStayConnected->start();
            timerHideFilialCB->stop();
            timerHideFilialCB->start();
        }
    }
}


void catalogbook::slot_SearchQueryTextChanged(QString text) 
{
    filter = text;
    frmCatalog.cbFilterAddress->setVisible(false);
    slot_filterAddressChanged("");
}
    
void catalogbook::threadSearchFinished(vector<string> listBooks) 
{
    cout << "finished with: " << listBooks.size() / 3 << " books" << endl;
    frmCatalog.twBookCatalog->setRowCount(0);
    vector<string>::iterator it = listBooks.begin();
    int row= 0;
    while (it != listBooks.end())
    {
        QTableWidgetItem *item_bookname = new QTableWidgetItem(QString(it->data()));
        ++it;
        QTableWidgetItem *item_series = new QTableWidgetItem(QString(it->data()));
        ++it;
        QTableWidgetItem *item_autor = new QTableWidgetItem(QString(it->data()));
        ++it;
        QTableWidgetItem *item_locate = new QTableWidgetItem(QString(it->data()));

        frmCatalog.twBookCatalog->insertRow(row);
        frmCatalog.twBookCatalog->setItem(row, 0, item_autor);
        frmCatalog.twBookCatalog->setItem(row, 1, item_bookname);
        frmCatalog.twBookCatalog->setItem(row, 2, item_series);
        frmCatalog.twBookCatalog->setItem(row, 4, item_locate);
        ++row;
        ++it;
        
    }
    timerVisibleProgress->stop();    
    frmCatalog.leSearchQuery->setStyleSheet("");
    rgba = 0;
}

void catalogbook::slot_TimerStayConnectedTimeout() 
{
    if (!bdOper.isConnected()) {
        if (!timerVisibleProgress->isActive()) {
            thread_bookBaseSearch* bookSearch = new thread_bookBaseSearch();
            QThread* thread = new QThread;
            
//            bookSearch->setBDConn(&bdOper);
            bookSearch->setFilialToSearch(filialAddressToSearch);
            bookSearch->setLimitSearch(_limit);        
            bookSearch->setFilterSearch(filter.toStdString());
            bookSearch->setBDName("bookcatalog");
            bookSearch->moveToThread(thread);
            
            connect(thread, SIGNAL(started()), bookSearch, SLOT(working_SearchBooks()));
            connect(bookSearch, SIGNAL(finished()), thread, SLOT(quit()));
            connect(this, SIGNAL(stopAll()), bookSearch, SLOT(stop()));
            connect(bookSearch, SIGNAL(finished(vector<string>)), this, SLOT(threadSearchFinished(vector<string>)));
//            connect(bookSearch, SIGNAL(finished()), bookSearch, SLOT(deleteLayer()));
//            connect(thread, SIGNAL(finished()), thread, SLOT(deleteLayer()));
            lastSearch = filter.toStdString();
            thread->start();
            timerStayConnected->stop();
            timerVisibleProgress->start();
        }
   }
}

void catalogbook::slot_delayChanged(int delay) 
{
    frmCatalog.leDelay->setText(QString::number(delay));
    timerStayConnected->setInterval(delay * 1000);
}

void catalogbook::slot_limitChanged(QString limit) 
{
    _limit = limit.toStdString();
}

void catalogbook::slot_TimerVisibleProgressTimeout() {
        frmCatalog.leSearchQuery->setStyleSheet(QString::fromStdString("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, "
        "   stop: 0.0    rgba(255, 255, 255, 255),"        
        "   stop: 0." + boost::lexical_cast<string>(rgba < 10 ? "0" : "") + boost::lexical_cast<string>(rgba) +"       rgba(64, 167, 242, 255), "
//        "   stop: 0.1    rgba(255, 255, 255, 255),"
//        "   stop: 0.3    rgba(255, 255, 255, 255),"
//        "   stop: 0.4    rgba(255, 255, 255, 255),"
//        "   stop: 0.5    rgba(255, 255, 255, 255),"        
//        "   stop: 0.6    rgba(255, 255, 255, 255),"        
//        "   stop: 0.7    rgba(255, 255, 255, 255),"        
//        "   stop: 0.8    rgba(255, 255, 255, 255),"
//        "   stop: 0.9    rgba(255, 255, 255, 255),"        
        "   stop: 1       rgba(255, 255, 255, 255));"));
        switch (frontier)
        {
            case true:
            {
                rgba++;
                if (rgba >= 99)
                    frontier = !frontier;
                break;
            }
            case false:
            {
                rgba--;
                if (rgba <= 1)
                    frontier = !frontier;
                break;
            }
        }
}

void catalogbook::slot_timerBoostChanged(int boost) {
    frmCatalog.leBoost->setText(QString::number(boost));
    timerVisibleProgress->setInterval(boost);
}

void catalogbook::slot_TimerHideTimeout() {
    frmCatalog.cbFilterAddress->setVisible(true);
    timerHideFilialCB->stop();
}

void catalogbook::closeEvent(QCloseEvent*) {
    emit closed("catalog");
}

void catalogbook::slot_TableClicked(QModelIndex index) {
     thread_bookBaseSearch* bookSearch = new thread_bookBaseSearch();
     QThread* thread = new QThread;
            
     bookSearch->setLimitSearch(_limit);        
//     bookSearch->setFilterSearch(filter.toStdString());
     parser pars;
     bookSearch->setSearchBookInfo(pars.removeAllAfter(index.sibling(frmCatalog.twBookCatalog->currentRow(), 0).data().toString().toStdString(), " "), pars.removeAllAfter(index.sibling(frmCatalog.twBookCatalog->currentRow(), 1).data().toString().toStdString(), "-"));
     bookSearch->setBDName("site_books");
     bookSearch->moveToThread(thread);
            
     connect(thread, SIGNAL(started()), bookSearch, SLOT(working_GetBookInfo()));
     connect(bookSearch, SIGNAL(finished()), thread, SLOT(quit()));
     connect(this, SIGNAL(stopAll()), bookSearch, SLOT(stop()));
     connect(bookSearch, SIGNAL(finished(vector<string>)), this, SLOT(threadSearchBookInfoFinished(vector<string>)));
     
     thread->start();
}

void catalogbook::threadSearchBookInfoFinished(vector<string> bookinfo) {
    cout << "finished info search" << endl;
    frmCatalog.teAnnotation->clear();
    frmCatalog.lblCover->setText("");
    frmCatalog.lwLocate->clear();
    if (bookinfo.size() > 1){
        if (bookinfo.front() != ""){
           QNetworkAccessManager* m_Http = new QNetworkAccessManager();
           cout << bookinfo.front() << endl;
           connect(m_Http, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_doneDownloadPic(QNetworkReply*)));
           m_Http->get(QNetworkRequest(QUrl(QString::fromStdString("http://" + bookinfo.front()))));
        
        }
        if (bookinfo.back() != ""){
            frmCatalog.teAnnotation->setText(QString::fromStdString(bookinfo.back()));
        }
    }
    parser pars;
    vector<string>listFilials = pars.getLocate(frmCatalog.twBookCatalog->currentIndex().sibling(frmCatalog.twBookCatalog->currentRow(), 4).data().toString().toStdString());
    for (string &locate: listFilials){
        map<string, string>::const_iterator it = filialsAdr.begin();
        if (locate[0] == ' ') {
            locate = locate.substr(1, locate.length());
        }
        bool alreadyInList = false;
        
        while (it != filialsAdr.end()) {
            if (locate == it->second) {

                for (int i = 0; i < frmCatalog.lwLocate->count(); i++) {
                    map<string, string>::const_iterator it_locate = filialsAdr.begin();
                    while (it_locate != filialsAdr.end()) {
                        if (frmCatalog.lwLocate->item(i)->text() == QString::fromStdString(it->first)) {
                            alreadyInList = true;
                            break;
                        }
                        ++it_locate;
                    }
                }
//                cout << "\"" << locate << "\""  << "        :    \"" << it->second << "\""<< endl;
                if (!alreadyInList) {
                    frmCatalog.lwLocate->addItem(QString::fromStdString(it->first));
                }
            }
            ++it;
        }
    }
}

void catalogbook::keyPressEvent(QKeyEvent* evt) {
    if (evt->key() == Qt::Key_Escape) {
  //      emit closed("catalog");
        this->close();
    }
        
    if(evt->key() == Qt::Key_Enter)
        return;
//    QDialog::keyPressEvent(evt);
}
