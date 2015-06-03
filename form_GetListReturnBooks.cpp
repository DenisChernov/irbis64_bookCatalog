/*
 * File:   form_GetListReturnBooks.cpp
 * Author: demiin
 *
 * Created on April 16, 2015, 12:46 PM
 */

#include "form_GetListReturnBooks.h"

form_GetListReturnBooks::form_GetListReturnBooks() {
    frm_GetListReturnBooks.setupUi(this);
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint/* | WindowType::WindowStaysOnTopHint*/);
    timerIDLE = new QTimer(this);
    connect(timerIDLE, SIGNAL(timeout()), this, SLOT(slot_timerIdleTimeout()));
    timerIDLE->start(TIME_IDLE);

    connect(frm_GetListReturnBooks.vsChangeSize, SIGNAL(valueChanged(int)), this, SLOT(slot_changeSizeValue(int)));
    connect(frm_GetListReturnBooks.pbReturnBook, SIGNAL(clicked()), this, SLOT(slot_ShowReturnDialog()));
    connect(frm_GetListReturnBooks.pbProlong, SIGNAL(clicked()), this, SLOT(slot_showProlongDlg()));
    
#ifdef _WIN32    
    QPixmap img;
    img.load("img/0.png");
    frm_GetListReturnBooks.lblPicTicket->setPixmap(img);        
#endif    
    this->setVisible(false);
    authWnd = new form_Auth();
    authWnd->setModal(true);
    authWnd->setAttribute(Qt::WA_DeleteOnClose);
    connect(authWnd, SIGNAL(authentificated()), this, SLOT(slot_authentificated()));
    connect(authWnd, SIGNAL(closeWithoutAuth()), this, SLOT(slot_closeWithoutAuth()));
    authWnd->show();
    
}

form_GetListReturnBooks::~form_GetListReturnBooks() {
}

void form_GetListReturnBooks::closeEvent(QCloseEvent*) {
    emit closed("lk");
}
void form_GetListReturnBooks::slot_timerIdleTimeout() {
    timerIDLE->stop();
    this->close();
}

void form_GetListReturnBooks::slot_authentificated() {
    this->setVisible(true);
    frm_GetListReturnBooks.leTicketNumber->setText(QString::fromStdString(authWnd->getAuthID()));
    authWnd->close();
    loadReaderData();
}

void form_GetListReturnBooks::makeAuthCentered() {
}

void form_GetListReturnBooks::resizeEvent(QResizeEvent*) {
    authWnd->move(this->width() / 2 - authWnd->width() / 2, this->height() / 2 - authWnd->height() / 2);
    frm_GetListReturnBooks.gbOwnedBooksJournals->setGeometry(frm_GetListReturnBooks.gbOwnedBooksJournals->x(), 
    //frm_GetListReturnBooks.gbOwnedBooksJournals->setGeometry(this->width() / 2 - 320, 
                                                                                                           frm_GetListReturnBooks.gbOwnedBooksJournals->y(), 
                                                                                                           this->width() - frm_GetListReturnBooks.gbOwnedBooksJournals->x() - frm_GetListReturnBooks.gbReaderInfo->x(), 
                                                                                                           this->height() - 421);
    frm_GetListReturnBooks.twOwnedBookJournals->setGeometry(frm_GetListReturnBooks.twOwnedBookJournals->x(),
                                                                                                        frm_GetListReturnBooks.twOwnedBookJournals->y(),
                                                                                                        frm_GetListReturnBooks.gbOwnedBooksJournals->width() - 40 ,
                                                                                                        frm_GetListReturnBooks.gbOwnedBooksJournals->height() - 40);
    frm_GetListReturnBooks.twBookJournalsReturned->setGeometry(frm_GetListReturnBooks.twBookJournalsReturned->x(),
                                                                                                        frm_GetListReturnBooks.twBookJournalsReturned->y(),
                                                                                                        frm_GetListReturnBooks.gbOwnedBooksJournals->width() - 40 ,
                                                                                                        frm_GetListReturnBooks.gbOwnedBooksJournals->height() - 40);
    
    frm_GetListReturnBooks.gbReaderInfo->setGeometry(frm_GetListReturnBooks.gbReaderInfo->x(), frm_GetListReturnBooks.gbReaderInfo->y(), frm_GetListReturnBooks.gbOwnedBooksJournals->x() - 20, frm_GetListReturnBooks.gbOwnedBooksJournals->height());
    //frm_GetListReturnBooks.gbReaderBio->setGeometry(frm_GetListReturnBooks.gbReaderBio->x(), frm_GetListReturnBooks.gbReaderBio->y(), frm_GetListReturnBooks.gbReaderBio->width(), frm_GetListReturnBooks.gbReaderInfo->height() - 150);
    
    slot_changeSizeValue(frm_GetListReturnBooks.vsChangeSize->value());
    
    frm_GetListReturnBooks.twOwnedBookJournals->horizontalHeader()->resizeSection(0, 70);
    frm_GetListReturnBooks.twOwnedBookJournals->horizontalHeader()->resizeSection(1, 110);
    frm_GetListReturnBooks.twOwnedBookJournals->horizontalHeader()->resizeSection(2, frm_GetListReturnBooks.twOwnedBookJournals->width() / 2 - 350);
    frm_GetListReturnBooks.twOwnedBookJournals->horizontalHeader()->resizeSection(3, frm_GetListReturnBooks.twOwnedBookJournals->width() / 2); 
    
    frm_GetListReturnBooks.twBookJournalsReturned->horizontalHeader()->resizeSection(0, 80);
    frm_GetListReturnBooks.twBookJournalsReturned->horizontalHeader()->resizeSection(1, 110);
    frm_GetListReturnBooks.twBookJournalsReturned->horizontalHeader()->resizeSection(2, frm_GetListReturnBooks.twBookJournalsReturned->width() / 2 - 300);
    frm_GetListReturnBooks.twBookJournalsReturned->horizontalHeader()->resizeSection(3, frm_GetListReturnBooks.twBookJournalsReturned->width() / 2 - 40);
    
    frm_GetListReturnBooks.gbRecomendations->setGeometry(frm_GetListReturnBooks.gbReaderInfo->x(), 
                                                                                                    frm_GetListReturnBooks.gbReaderInfo->y() + frm_GetListReturnBooks.gbReaderInfo->height() + 10,
                                                                                                    this->width() - 20,
                                                                                                    this->height() - frm_GetListReturnBooks.gbReaderInfo->height() - 40);
}



void form_GetListReturnBooks::loadReaderData() {
    engine* loadReader = new engine();
    QThread* thread = new QThread;
    loadReader->moveToThread(thread);
    loadReader->setCurrentWork(engine::ALL_DATA);
    loadReader->setReaderNumber(frm_GetListReturnBooks.leTicketNumber->text().toStdString());
    connect(thread, SIGNAL(started()), loadReader, SLOT(working()));
    connect(loadReader, SIGNAL(finished()), thread, SLOT(quit()));
    connect(this, SIGNAL(stopAll()), loadReader, SLOT(stop()));
    connect(loadReader, SIGNAL(finished(map<string,vector<string>>)), this, SLOT(threadLoadReaderFinished(map<string,vector<string>>)));

    thread->start();
}

void form_GetListReturnBooks::threadLoadReaderFinished(map<string,vector<string>> readerData) {
    parser pars;
    setReader(readerData);
    vector<string>::const_iterator it = readerData["books_owned"].begin();
    vector<string> data;
    
    while (it != readerData["books_owned"].end()) {
        data = pars.makeFields(it->data());
/*        for(string &value: data) {
            cout << value << endl;
        }
        cout << "------------------------------" << endl;*/
        insertBooksJournalsOwned(data);
        it++;
    }
    cout << "book owned finished" << endl;
    it = readerData["books_returned"].begin();
    while (it != readerData["books_returned"].end()) {
        data = pars.makeFields(it->data());
/*        for(string &value: data) {
            cout << value << endl;
        }
        cout << "------------------------------" << endl;*/
        insertBooksJournalsReturned(data);
        it++;
    }
    cout << "book returned finished" << endl;
}

void form_GetListReturnBooks::insertBooksJournalsOwned(vector<string> data) {
    QTableWidgetItem *item_daysLeft = new QTableWidgetItem(QString::fromStdString(data.at(data.size() == 6 ? 5 : 4)));
    QTableWidgetItem *item_filial = new QTableWidgetItem(QString::fromStdString(data.at(1)));
    QTableWidgetItem *item_autor = new QTableWidgetItem(QString::fromStdString(data.at(2)));
    QTableWidgetItem *item_bookname = new QTableWidgetItem(QString::fromStdString(data.at(data.size() == 6 ? 4 : 3)));
    int row = frm_GetListReturnBooks.twOwnedBookJournals->rowCount();
    frm_GetListReturnBooks.twOwnedBookJournals->insertRow(row);
    
    frm_GetListReturnBooks.twOwnedBookJournals->setItem(row, 0, item_daysLeft);
    if (boost::lexical_cast<int>(data.at(data.size() == 6 ? 5 : 4)) < 0) {
        frm_GetListReturnBooks.twOwnedBookJournals->item(row, 0)->setBackgroundColor(Qt::red);
    }
    else if (boost::lexical_cast<int>(data.at(data.size() == 6 ? 5 : 4)) < WARNING_RETURN_DAY){
        frm_GetListReturnBooks.twOwnedBookJournals->item(row, 0)->setBackgroundColor(Qt::yellow);
    }
    frm_GetListReturnBooks.twOwnedBookJournals->setItem(row, 1, item_filial);
    frm_GetListReturnBooks.twOwnedBookJournals->setItem(row, 2, item_autor);
    frm_GetListReturnBooks.twOwnedBookJournals->setItem(row, 3, item_bookname);

}

void form_GetListReturnBooks::insertBooksJournalsReturned(vector<string> data) {
    QTableWidgetItem *item_datagived = new QTableWidgetItem(QString::fromStdString(data.at(0)));
    QTableWidgetItem *item_filial = new QTableWidgetItem(QString::fromStdString(data.at(1)));
    QTableWidgetItem *item_autor_jrn = new QTableWidgetItem(QString::fromStdString(data.at(2)));
    QTableWidgetItem *item_bookname_ym = new QTableWidgetItem(QString::fromStdString(data.at(data.size() == 6 ? 4 : 3)));
    int row = frm_GetListReturnBooks.twBookJournalsReturned->rowCount();
    frm_GetListReturnBooks.twBookJournalsReturned->insertRow(row);
    
    frm_GetListReturnBooks.twBookJournalsReturned->setItem(row, 0, item_datagived);
    frm_GetListReturnBooks.twBookJournalsReturned->setItem(row, 1, item_filial);
    frm_GetListReturnBooks.twBookJournalsReturned->setItem(row, 2, item_autor_jrn);
    frm_GetListReturnBooks.twBookJournalsReturned->setItem(row, 3, item_bookname_ym);
}


void form_GetListReturnBooks::slot_changeSizeValue(int size) {
    frm_GetListReturnBooks.twOwnedBookJournals->setGeometry(frm_GetListReturnBooks.twOwnedBookJournals->x(),
                                                                                                     frm_GetListReturnBooks.twOwnedBookJournals->y(),
                                                                                                     frm_GetListReturnBooks.twOwnedBookJournals->width(),
                                                                                                     size);
    frm_GetListReturnBooks.twBookJournalsReturned->setGeometry(frm_GetListReturnBooks.twBookJournalsReturned->x(),
                                                                                                            frm_GetListReturnBooks.twOwnedBookJournals->height() + 30,
                                                                                                            frm_GetListReturnBooks.gbOwnedBooksJournals->width() - 40,
                                                                                                            frm_GetListReturnBooks.gbOwnedBooksJournals->height() - frm_GetListReturnBooks.twOwnedBookJournals->height() - 40);
}

void form_GetListReturnBooks::slot_ShowReturnDialog() {
    form_ReturnDialog* frmReturnDialog = new form_ReturnDialog();
    
    frmReturnDialog->show();
}

void form_GetListReturnBooks::slot_showProlongDlg() {
    form_Prolong* frmProlong = new form_Prolong(METHOD::EMAIL);
    frmProlong->setAttribute(Qt::WA_DeleteOnClose);
    frmProlong->setModal(true);
    //frmProlong->setReaderNumb(frm_GetListReturnBooks.leTicketNumber->text().toStdString());
    frmProlong->setReaderData(reader);
    frmProlong->setReaderNumb(frm_GetListReturnBooks.leTicketNumber->text().toStdString());
    frmProlong->loadReaderData();
    frmProlong->show();
}

void form_GetListReturnBooks::slot_closeWithoutAuth() {
    this->close();
}

void form_GetListReturnBooks::keyPressEvent(QKeyEvent* evt) {
    if (evt->key() == Qt::Key_Escape) {
      //  emit closed("lk");
        this->close();
    }
        
    if(evt->key() == Qt::Key_Enter)
        return;
}
