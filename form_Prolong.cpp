/*
 * File:   form_Prolong.cpp
 * Author: demiin
 *
 * Created on April 30, 2015, 1:52 PM
 */

#include "form_Prolong.h"

form_Prolong::form_Prolong(METHOD method) {
    frm_Prolong.setupUi(this);
//    loadReaderData();
    connect(frm_Prolong.pbProlong, SIGNAL(clicked()), this, SLOT(slot_prolong()));
//    connect(frm_Prolong.pbProlong, &QPushButton::clicked, slot_prolong);
    _method = method;

}

form_Prolong::~form_Prolong() {
}

void form_Prolong::loadReaderData() {
    parser pars;
    vector<string>::const_iterator it = readerData["books_owned"].begin();
    vector<string> data;
    
    while (it != readerData["books_owned"].end()) {
        data = pars.makeFields(it->data());
/*        for(string &value: data) {
            cout << value << endl;
        }
        cout << "------------------------------" << endl;*/
        insertBooksJournalsOwned(data);
        ++it;
    }
    
    frm_Prolong.twProlong->horizontalHeader()->resizeSection(0, 26);
    frm_Prolong.twProlong->horizontalHeader()->resizeSection(1, 90);
    frm_Prolong.twProlong->horizontalHeader()->resizeSection(2, 80);
    frm_Prolong.twProlong->horizontalHeader()->resizeSection(3, 44);
    frm_Prolong.twProlong->horizontalHeader()->resizeSection(4, 200);
    frm_Prolong.twProlong->horizontalHeader()->hideSection(6);
    
}

void form_Prolong::threadLoadReaderFinished(map<string, vector<string>> readerData) {
    
}

void form_Prolong::insertBooksJournalsOwned(vector<string> data) {
    QTableWidgetItem *item_daysLeft = new QTableWidgetItem(QString::fromStdString(data.at(data.size() == 6 ? 5 : 4)));
    QTableWidgetItem *item_filial = new QTableWidgetItem(QString::fromStdString(data.at(1)));
    QTableWidgetItem *item_autor = new QTableWidgetItem(QString::fromStdString(data.at(2)));
    QTableWidgetItem *item_bookname = new QTableWidgetItem(QString::fromStdString(data.at(data.size() == 6 ? 4 : 3)));
    
    int row = frm_Prolong.twProlong->rowCount();
    frm_Prolong.twProlong->insertRow(row);
    
    frm_Prolong.twProlong->setCellWidget(frm_Prolong.twProlong->rowCount()-1, 0, new QCheckBox(this));
    frm_Prolong.twProlong->setItem(row, 3, item_daysLeft);
    if (boost::lexical_cast<int>(data.at(data.size() == 6 ? 5 : 4)) < 0) {
        frm_Prolong.twProlong->item(row, 3)->setBackgroundColor(Qt::red);
    }
    else if (boost::lexical_cast<int>(data.at(data.size() == 6 ? 5 : 4)) < WARNING_RETURN_DAY){
        frm_Prolong.twProlong->item(row, 3)->setBackgroundColor(Qt::yellow);
    }
    frm_Prolong.twProlong->setItem(row, 4, item_autor);
    frm_Prolong.twProlong->setItem(row, 5, item_bookname);
    frm_Prolong.twProlong->setItem(row, 6, item_filial);
}

void form_Prolong::slot_prolong() {
    map<string, vector<string> >books;
    
    QList<QCheckBox* > list;
    list = frm_Prolong.twProlong->findChildren<QCheckBox *>();
    
    for (int i = 0; i < list.count(); i++)
    {
        if (list.at(i)->isChecked())
        {
            string tmp = frm_Prolong.twProlong->item(i, 6)->text().toStdString();
            size_t pos = frm_Prolong.twProlong->item(i, 6)->text().toStdString().find("Ф ");
            if (pos != string::npos) {
                tmp = tmp.substr(0, frm_Prolong.twProlong->item(i, 6)->text().toStdString().find_last_of(" "));                
                //cout << "\""<< tmp.replace(0, 3, "f") << "\""<<endl;
                
            }
            pos = frm_Prolong.twProlong->item(i, 6)->text().toStdString().find("ЦГБ ЦОДИ");
            if (pos != string::npos) {
                tmp = "codi";
                //cout << tmp << endl;
            }
            pos = frm_Prolong.twProlong->item(i, 6)->text().toStdString().find("ЦГБ АБ");
            if (pos != string::npos) {
                tmp = "ab";
                //cout << tmp << endl;
            }
            
            books[tmp].push_back("<b>" + frm_Prolong.twProlong->item(i, 4)->text().toStdString() + "</b>: " + frm_Prolong.twProlong->item(i, 5)->text().toStdString());
        }
    }
    engine* sendProlong = new engine();
    QThread* thread = new QThread;
    sendProlong->moveToThread(thread);
    sendProlong->setReaderNumber(readerNumb);
    sendProlong->setBookToProlong(books);
    connect(thread, &QThread::started, sendProlong, &engine::sendProlongRequest);
    connect(sendProlong, &engine::finished, thread, &QThread::quit);
    connect(this, &form_Prolong::stopAll, sendProlong, &engine::stop);
    connect(sendProlong, &engine::sendProlongRequestComplited, this, &form_Prolong::threadProlongFinished);
    
    thread->start();
    this->close();
}

void form_Prolong::threadProlongFinished() {
    
}

