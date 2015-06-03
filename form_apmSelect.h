/* 
 * File:   form_apmSelect.h
 * Author: demiin
 *
 * Created on April 16, 2015, 11:13 AM
 */

#ifndef _FORM_APMSELECT_H
#define	_FORM_APMSELECT_H

#include "ui_form_apmSelect.h"
#include "catalogbook.h"
#include "form_GetListReturnBooks.h"
#include <iostream>
#include <qnamespace.h>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;


class form_apmSelect : public QDialog {
    Q_OBJECT
public:
    form_apmSelect();
    virtual ~form_apmSelect();
private:
    Ui::form_apmSelect frmApmSelect;
    catalogbook* catalogWnd;
    form_GetListReturnBooks* getListReturnBooksWnd;
    void setInstruction();
    string newWidth(int mainWndWidth, int oldPixWidth, int oldPixHeight);
    string newHeight(int mainWndWidth, int oldPixWidth, int oldPixHeight);
    
protected:
    void resizeEvent(QResizeEvent *);
    
    
private slots:
    void slot_bookCatalog();
    void slot_GetListReturnBooks();
    void slot_closed(string);

};

#endif	/* _FORM_APMSELECT_H */
