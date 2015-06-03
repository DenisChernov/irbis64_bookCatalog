/*
 * File:   form_Auth.cpp
 * Author: demiin
 *
 * Created on April 16, 2015, 1:20 PM
 */

#include "form_Auth.h"
#include "engine.h"

form_Auth::form_Auth() {
    frmAuth.setupUi(this);
    
    this->setWindowFlags(Qt::WindowType::FramelessWindowHint | Qt::WindowType::WindowStaysOnTopHint);
    timerAccessDenied = new QTimer(this);
    
    connect(frmAuth.cbAuth, SIGNAL(clicked()), this, SLOT(slot_tryAuth()));
    connect(timerAccessDenied, SIGNAL(timeout()), this, SLOT(slot_timerAccessDeniedTimeout()));
}

form_Auth::~form_Auth() {
}

void form_Auth::slot_tryAuth() {
    engine* auth = new engine();
    QThread* thread = new QThread;
    auth->moveToThread(thread);
    auth->setCurrentWork(engine::AUTH);
    auth->setReaderNumber(frmAuth.leReaderLogin->text().toStdString());
    connect(thread, SIGNAL(started()), auth, SLOT(working()));
    connect(auth, SIGNAL(finished()), thread, SLOT(quit()));
    connect(this, SIGNAL(stopAll()), auth, SLOT(stop()));
    connect(auth, SIGNAL(finished(map<string, vector<string>>)), this, SLOT(threadAuthFinished(map<string, vector<string>>)));

    thread->start();
}

void form_Auth::accessDenied() {
    frmAuth.leReaderLogin->setStyleSheet("background-color: rgb(255, 0, 0);");
    timerAccessDenied->start(TIMER_DENIED_INT);
}

void form_Auth::accessGranted() {
    emit authentificated();
}

void form_Auth::slot_timerAccessDeniedTimeout() {
    if (round != ROUND_COUNT) {
        switch (frontier) {
            case true: {
                if (frmAuth.leReaderLogin->x() >= 39) {
                    frontier = !frontier;
                    ++round;
                }
                else
                    frmAuth.leReaderLogin->move(frmAuth.leReaderLogin->x() + 1, frmAuth.leReaderLogin->y());
                break;
            }
            case false: {
                if (frmAuth.leReaderLogin->x() <= 1) {
                    frontier = !frontier;
                    ++round;
                }
                else
                    frmAuth.leReaderLogin->move(frmAuth.leReaderLogin->x() - 1, frmAuth.leReaderLogin->y());
                break;
            }
        }
    }
    else {
        round = 0;
        timerAccessDenied->stop();
        frmAuth.leReaderLogin->move(20, frmAuth.leReaderLogin->y());
        frmAuth.leReaderLogin->setStyleSheet("background-color: rgb(255, 255, 255);");
    }
}

void form_Auth::threadAuthFinished(map<string, vector<string>> result) {
    if (result.size() != 0) {
        authID = result["ticket"].front();
        accessGranted();
    }
    else {
        accessDenied();
    }
}

void form_Auth::keyPressEvent(QKeyEvent* evt) {
    if (evt->key() == Qt::Key_Escape) {
        emit closeWithoutAuth();
    }
        
    if(evt->key() == Qt::Key_Enter)
        return;
    QDialog::keyPressEvent(evt);
}
