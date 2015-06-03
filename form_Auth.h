/* 
 * File:   form_Auth.h
 * Author: demiin
 *
 * Created on April 16, 2015, 1:20 PM
 */

#ifndef _FORM_AUTH_H
#define	_FORM_AUTH_H

#include "ui_form_Auth.h"

#include "engine.h"
#include <QTimer>
#include <iostream>
#include <qnamespace.h>
#include <QThread>
#include <QKeyEvent>

using namespace std;


class form_Auth : public QDialog {
    Q_OBJECT
public:
    form_Auth();
    virtual ~form_Auth();
    
    string getAuthID() {return authID;};
private:
    Ui::form_Auth frmAuth;
    bool checkLogin();
    void accessDenied();
    void accessGranted();
    QTimer* timerAccessDenied;
    const int TIMER_DENIED_INT = 2;
    const size_t ROUND_COUNT = 10;
    size_t round = 0;
    bool frontier = true;
    string authID;
    
private slots:
    void slot_tryAuth();
    void slot_timerAccessDeniedTimeout();
    void threadAuthFinished(map<string, vector<string>>);
    
protected:
    void keyPressEvent(QKeyEvent *);
    
signals:
    void authentificated();
    void stopAll();
    void closeWithoutAuth();
};

#endif	/* _FORM_AUTH_H */
