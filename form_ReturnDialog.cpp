/*
 * File:   form_ReturnDialog.cpp
 * Author: demiin
 *
 * Created on April 28, 2015, 10:00 AM
 */

#include "form_ReturnDialog.h"

form_ReturnDialog::form_ReturnDialog() {
    frm_ReturnDialog.setupUi(this);
    
    connect(frm_ReturnDialog.pbClose, SIGNAL(clicked()), this, SLOT(slot_closeBtnClicked()));
    connect(frm_ReturnDialog.leCode, SIGNAL(editingFinished()), this, SLOT(slot_returnBook()));
}

form_ReturnDialog::~form_ReturnDialog() {
}

void form_ReturnDialog::slot_closeBtnClicked() {
    //this->close();
    
    engine* threadReturn = new engine();
    QThread* thread = new QThread;
    threadReturn->moveToThread(thread);
    threadReturn->setInvNumber(frm_ReturnDialog.leCode->text().toStdString());
    connect(thread, SIGNAL(started()), threadReturn, SLOT(makeReturn()));
    connect(threadReturn, SIGNAL(finished()), thread, SLOT(quit()));
    connect(this, SIGNAL(stopAll()), threadReturn, SLOT(stop()));
    connect(threadReturn, SIGNAL(finishReturnBook(bool)), this, SLOT(slot_finishReturnBook(bool)));

    thread->start();
}

void form_ReturnDialog::slot_returnBook() {
    cout << frm_ReturnDialog.leCode->text().toStdString() << endl;
}

void form_ReturnDialog::slot_finishReturnBook(bool success) {
    switch (success) {
        case true: {
            frm_ReturnDialog.leCode->setText("OK");
            break;
        }
        case false: {
            frm_ReturnDialog.leCode->setText("BAD");
            break;
        }
    }
}
