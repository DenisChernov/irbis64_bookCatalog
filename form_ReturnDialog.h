/* 
 * File:   form_ReturnDialog.h
 * Author: demiin
 *
 * Created on April 28, 2015, 10:00 AM
 */

#ifndef _FORM_RETURNDIALOG_H
#define	_FORM_RETURNDIALOG_H

#include "ui_form_ReturnDialog.h"
#include <string>
#include <iostream>
#include <QThread>
#include "engine.h"

using namespace std;

class form_ReturnDialog : public QWidget {
    Q_OBJECT
public:
    form_ReturnDialog();
    virtual ~form_ReturnDialog();
    
private:
    Ui::form_ReturnDialog frm_ReturnDialog;
    
private slots:
    void slot_closeBtnClicked();
    void slot_returnBook();
    void slot_finishReturnBook(bool);
    
signals:
    void stopAll();
};

#endif	/* _FORM_RETURNDIALOG_H */
