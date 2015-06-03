/********************************************************************************
** Form generated from reading UI file 'form_GetListReturnBooks.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_GETLISTRETURNBOOKS_H
#define UI_FORM_GETLISTRETURNBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_GetListReturnBooks
{
public:
    QWidget *centralwidget;
    QGroupBox *gbReaderInfo;
    QLabel *label;
    QLabel *lblPicTicket;
    QLineEdit *leTicketNumber;
    QGroupBox *gbReaderBio;
    QGroupBox *gbUserActions;
    QPushButton *pbProlong;
    QPushButton *pbReturnBook;
    QGroupBox *gbOwnedBooksJournals;
    QTableWidget *twOwnedBookJournals;
    QSlider *vsChangeSize;
    QTableWidget *twBookJournalsReturned;
    QGroupBox *gbRecomendations;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *form_GetListReturnBooks)
    {
        if (form_GetListReturnBooks->objectName().isEmpty())
            form_GetListReturnBooks->setObjectName(QStringLiteral("form_GetListReturnBooks"));
        form_GetListReturnBooks->setWindowModality(Qt::NonModal);
        form_GetListReturnBooks->resize(1292, 904);
        form_GetListReturnBooks->setDocumentMode(false);
        centralwidget = new QWidget(form_GetListReturnBooks);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gbReaderInfo = new QGroupBox(centralwidget);
        gbReaderInfo->setObjectName(QStringLiteral("gbReaderInfo"));
        gbReaderInfo->setGeometry(QRect(10, 10, 571, 600));
        label = new QLabel(gbReaderInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 151, 16));
        lblPicTicket = new QLabel(gbReaderInfo);
        lblPicTicket->setObjectName(QStringLiteral("lblPicTicket"));
        lblPicTicket->setGeometry(QRect(10, 50, 241, 151));
        lblPicTicket->setPixmap(QPixmap(QString::fromUtf8(":/\320\247\320\221.png")));
        lblPicTicket->setScaledContents(true);
        leTicketNumber = new QLineEdit(gbReaderInfo);
        leTicketNumber->setObjectName(QStringLiteral("leTicketNumber"));
        leTicketNumber->setGeometry(QRect(50, 170, 181, 23));
        leTicketNumber->setAlignment(Qt::AlignCenter);
        leTicketNumber->setReadOnly(true);
        gbReaderBio = new QGroupBox(gbReaderInfo);
        gbReaderBio->setObjectName(QStringLiteral("gbReaderBio"));
        gbReaderBio->setGeometry(QRect(10, 220, 551, 381));
        gbUserActions = new QGroupBox(gbReaderInfo);
        gbUserActions->setObjectName(QStringLiteral("gbUserActions"));
        gbUserActions->setGeometry(QRect(260, 30, 301, 171));
        pbProlong = new QPushButton(gbUserActions);
        pbProlong->setObjectName(QStringLiteral("pbProlong"));
        pbProlong->setGeometry(QRect(10, 70, 281, 31));
        pbReturnBook = new QPushButton(gbUserActions);
        pbReturnBook->setObjectName(QStringLiteral("pbReturnBook"));
        pbReturnBook->setEnabled(false);
        pbReturnBook->setGeometry(QRect(10, 30, 281, 31));
        pbReturnBook->setAutoDefault(false);
        pbReturnBook->setFlat(false);
        gbOwnedBooksJournals = new QGroupBox(centralwidget);
        gbOwnedBooksJournals->setObjectName(QStringLiteral("gbOwnedBooksJournals"));
        gbOwnedBooksJournals->setGeometry(QRect(590, 10, 691, 600));
        twOwnedBookJournals = new QTableWidget(gbOwnedBooksJournals);
        if (twOwnedBookJournals->columnCount() < 4)
            twOwnedBookJournals->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        twOwnedBookJournals->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        twOwnedBookJournals->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        twOwnedBookJournals->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        twOwnedBookJournals->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        twOwnedBookJournals->setObjectName(QStringLiteral("twOwnedBookJournals"));
        twOwnedBookJournals->setGeometry(QRect(30, 30, 651, 270));
        twOwnedBookJournals->setStyleSheet(QLatin1String("QHeaderView {\n"
"    background-color: #fff;\n"
"    font-size:13px;\n"
"}\n"
"QHeaderView::section:horizontal {\n"
"    color: #fff;\n"
"    border-style: solid;\n"
"    background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                        stop: 0 #4287ff, stop: 1 #356ccc);\n"
" }\n"
"QTableView {\n"
"    border: 2px solid #3873d9;\n"
"    border-top-color: #4287ff;\n"
"    border-radius: 4px;\n"
"    background-color: #fff;\n"
"    gridline-color: #777;\n"
"    selection-background-color: #ccdfff;\n"
"    color:#333;\n"
"    font-size:12px;\n"
" }\n"
"\n"
"QScrollBar:vertical {\n"
"     background: #e4e4e4;\n"
"     border-top-right-radius: 4px;\n"
"     border-bottom-right-radius: 4px;\n"
"     width: 12px;\n"
"     margin: 0px;\n"
" }\n"
" QScrollBar::handle:vertical {\n"
"    background-color: qlineargradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"                                    stop: 0 #4287ff, stop: 1 #356ccc);\n"
"     border-radius: 4px;\n"
"     min-height: 20px;\n"
""
                        "     margin: 0px 2px 0px 2px;\n"
" }\n"
" QScrollBar::add-line:vertical {\n"
"     background: none;\n"
"     height: 0px;\n"
"     subcontrol-position: right;\n"
"     subcontrol-origin: margin;\n"
" }\n"
" QScrollBar::sub-line:vertical {\n"
"     background: none;\n"
"     height: 0px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
" }"));
        twOwnedBookJournals->setEditTriggers(QAbstractItemView::NoEditTriggers);
        twOwnedBookJournals->setProperty("showDropIndicator", QVariant(false));
        twOwnedBookJournals->setDragDropOverwriteMode(false);
        twOwnedBookJournals->setAlternatingRowColors(true);
        twOwnedBookJournals->setSelectionMode(QAbstractItemView::ContiguousSelection);
        twOwnedBookJournals->setSelectionBehavior(QAbstractItemView::SelectRows);
        twOwnedBookJournals->setTextElideMode(Qt::ElideMiddle);
        twOwnedBookJournals->setSortingEnabled(true);
        twOwnedBookJournals->horizontalHeader()->setStretchLastSection(true);
        vsChangeSize = new QSlider(gbOwnedBooksJournals);
        vsChangeSize->setObjectName(QStringLiteral("vsChangeSize"));
        vsChangeSize->setGeometry(QRect(4, 50, 23, 521));
        vsChangeSize->setMaximum(566);
        vsChangeSize->setValue(300);
        vsChangeSize->setOrientation(Qt::Vertical);
        vsChangeSize->setInvertedAppearance(true);
        twBookJournalsReturned = new QTableWidget(gbOwnedBooksJournals);
        if (twBookJournalsReturned->columnCount() < 4)
            twBookJournalsReturned->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        twBookJournalsReturned->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        twBookJournalsReturned->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        twBookJournalsReturned->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        twBookJournalsReturned->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        twBookJournalsReturned->setObjectName(QStringLiteral("twBookJournalsReturned"));
        twBookJournalsReturned->setGeometry(QRect(30, 295, 651, 251));
        twBookJournalsReturned->setStyleSheet(QLatin1String("QHeaderView {\n"
"    background-color: #fff;\n"
"    font-size:13px;\n"
"}\n"
"QHeaderView::section:horizontal {\n"
"    color: #fff;\n"
"    border-style: solid;\n"
"    background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                        stop: 0 #4287ff, stop: 1 #356ccc);\n"
" }\n"
"QTableView {\n"
"    border: 2px solid #3873d9;\n"
"    border-top-color: #4287ff;\n"
"    border-radius: 4px;\n"
"    background-color: #fff;\n"
"    gridline-color: #777;\n"
"    selection-background-color: #ccdfff;\n"
"    color:#333;\n"
"    font-size:12px;\n"
" }\n"
"\n"
"QScrollBar:vertical {\n"
"     background: #e4e4e4;\n"
"     border-top-right-radius: 4px;\n"
"     border-bottom-right-radius: 4px;\n"
"     width: 12px;\n"
"     margin: 0px;\n"
" }\n"
" QScrollBar::handle:vertical {\n"
"    background-color: qlineargradient( x1: 0, y1: 0, x2: 1, y2: 0,\n"
"                                    stop: 0 #4287ff, stop: 1 #356ccc);\n"
"     border-radius: 4px;\n"
"     min-height: 20px;\n"
""
                        "     margin: 0px 2px 0px 2px;\n"
" }\n"
" QScrollBar::add-line:vertical {\n"
"     background: none;\n"
"     height: 0px;\n"
"     subcontrol-position: right;\n"
"     subcontrol-origin: margin;\n"
" }\n"
" QScrollBar::sub-line:vertical {\n"
"     background: none;\n"
"     height: 0px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
" }"));
        twBookJournalsReturned->setEditTriggers(QAbstractItemView::NoEditTriggers);
        twBookJournalsReturned->setProperty("showDropIndicator", QVariant(false));
        twBookJournalsReturned->setDragDropOverwriteMode(false);
        twBookJournalsReturned->setAlternatingRowColors(true);
        twBookJournalsReturned->setSelectionMode(QAbstractItemView::ContiguousSelection);
        twBookJournalsReturned->setSelectionBehavior(QAbstractItemView::SelectRows);
        twBookJournalsReturned->setTextElideMode(Qt::ElideMiddle);
        twBookJournalsReturned->setSortingEnabled(true);
        twBookJournalsReturned->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        twBookJournalsReturned->horizontalHeader()->setStretchLastSection(true);
        gbRecomendations = new QGroupBox(centralwidget);
        gbRecomendations->setObjectName(QStringLiteral("gbRecomendations"));
        gbRecomendations->setGeometry(QRect(10, 610, 1271, 241));
        form_GetListReturnBooks->setCentralWidget(centralwidget);
        menubar = new QMenuBar(form_GetListReturnBooks);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1292, 21));
        form_GetListReturnBooks->setMenuBar(menubar);
        statusbar = new QStatusBar(form_GetListReturnBooks);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        form_GetListReturnBooks->setStatusBar(statusbar);

        retranslateUi(form_GetListReturnBooks);

        QMetaObject::connectSlotsByName(form_GetListReturnBooks);
    } // setupUi

    void retranslateUi(QMainWindow *form_GetListReturnBooks)
    {
        form_GetListReturnBooks->setWindowTitle(QApplication::translate("form_GetListReturnBooks", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\272\320\275\320\270\320\263 \320\275\320\260 \321\200\321\203\320\272\320\260\321\205", 0));
        gbReaderInfo->setTitle(QApplication::translate("form_GetListReturnBooks", "\320\247\320\270\321\202\320\260\321\202\320\265\320\273\321\214", 0));
        label->setText(QApplication::translate("form_GetListReturnBooks", "\320\247\320\270\321\202\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\270\320\271 \320\261\320\270\320\273\320\265\321\202:", 0));
        lblPicTicket->setText(QString());
        gbReaderBio->setTitle(QApplication::translate("form_GetListReturnBooks", "\320\222\320\260\321\210\320\270 \320\264\320\260\320\275\320\275\321\213\320\265:", 0));
        gbUserActions->setTitle(QString());
        pbProlong->setText(QApplication::translate("form_GetListReturnBooks", "\320\237\321\200\320\276\320\264\320\273\320\270\321\202\321\214", 0));
        pbReturnBook->setText(QApplication::translate("form_GetListReturnBooks", "\320\241\320\264\320\260\321\202\321\214", 0));
        gbOwnedBooksJournals->setTitle(QApplication::translate("form_GetListReturnBooks", "\320\232\320\275\320\270\320\263\320\270 \320\270 \320\266\321\203\321\200\320\275\320\260\320\273\321\213", 0));
        QTableWidgetItem *___qtablewidgetitem = twOwnedBookJournals->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("form_GetListReturnBooks", "\320\236\321\201\321\202.", 0));
        QTableWidgetItem *___qtablewidgetitem1 = twOwnedBookJournals->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("form_GetListReturnBooks", "\320\234\320\265\321\201\321\202\320\276 \320\262\321\213\320\264\320\260\321\207\320\270", 0));
        QTableWidgetItem *___qtablewidgetitem2 = twOwnedBookJournals->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("form_GetListReturnBooks", "\320\220\320\262\321\202\320\276\321\200 / \320\226\321\203\321\200\320\275\320\260\320\273", 0));
        QTableWidgetItem *___qtablewidgetitem3 = twOwnedBookJournals->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("form_GetListReturnBooks", "\320\227\320\260\320\263\320\273\320\260\320\262\320\270\320\265 / \320\223\320\276\320\264,\320\235\320\276\320\274\320\265\321\200", 0));
        QTableWidgetItem *___qtablewidgetitem4 = twBookJournalsReturned->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("form_GetListReturnBooks", "\320\222\320\276\320\267\320\262\321\200\320\260\321\202", 0));
        QTableWidgetItem *___qtablewidgetitem5 = twBookJournalsReturned->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("form_GetListReturnBooks", "\320\234\320\265\321\201\321\202\320\276 \320\262\321\213\320\264\320\260\321\207\320\270", 0));
        QTableWidgetItem *___qtablewidgetitem6 = twBookJournalsReturned->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("form_GetListReturnBooks", "\320\220\320\262\321\202\320\276\321\200 / \320\226\321\203\321\200\320\275\320\260\320\273", 0));
        QTableWidgetItem *___qtablewidgetitem7 = twBookJournalsReturned->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("form_GetListReturnBooks", "\320\227\320\260\320\263\320\273\320\260\320\262\320\270\320\265 / \320\223\320\276\320\264,\320\235\320\276\320\274\320\265\321\200", 0));
        gbRecomendations->setTitle(QApplication::translate("form_GetListReturnBooks", "\320\235\320\276\320\262\320\270\320\275\320\272\320\270 \320\270 \321\200\320\265\320\272\320\276\320\274\320\265\320\275\320\264\320\260\321\206\320\270\320\270 \320\275\320\260 \320\276\321\201\320\275\320\276\320\262\320\265 \320\262\320\260\321\210\320\265\320\271 \320\262\320\267\321\217\321\202\320\276\320\271 \320\273\320\270\321\202\320\265\321\200\320\260\321\202\321\203\321\200\321\213", 0));
    } // retranslateUi

};

namespace Ui {
    class form_GetListReturnBooks: public Ui_form_GetListReturnBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_GETLISTRETURNBOOKS_H
