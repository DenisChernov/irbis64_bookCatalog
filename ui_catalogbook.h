/********************************************************************************
** Form generated from reading UI file 'catalogbook.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATALOGBOOK_H
#define UI_CATALOGBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_catalogbook
{
public:
    QAction *action;
    QWidget *centralwidget;
    QLineEdit *leSearchQuery;
    QLabel *label;
    QTabWidget *twCatalogList;
    QWidget *tab_Search;
    QTableWidget *twBookCatalog;
    QWidget *tab_FullDescription;
    QGroupBox *gbCOver;
    QLabel *lblCover;
    QGroupBox *groupBox;
    QTextEdit *teAnnotation;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QTreeView *tvContain;
    QGroupBox *groupBox_4;
    QListWidget *lwLocate;
    QLineEdit *leDelay;
    QSlider *vsDelay;
    QLineEdit *leLimit;
    QLabel *lblDelay;
    QLabel *lblLimit;
    QSlider *hsTimerBoost;
    QLineEdit *leBoost;
    QComboBox *cbFilterAddress;
    QMenuBar *mnu;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *catalogbook)
    {
        if (catalogbook->objectName().isEmpty())
            catalogbook->setObjectName(QStringLiteral("catalogbook"));
        catalogbook->resize(1107, 822);
        catalogbook->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        action = new QAction(catalogbook);
        action->setObjectName(QStringLiteral("action"));
        centralwidget = new QWidget(catalogbook);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        leSearchQuery = new QLineEdit(centralwidget);
        leSearchQuery->setObjectName(QStringLiteral("leSearchQuery"));
        leSearchQuery->setGeometry(QRect(123, 17, 871, 23));
        leSearchQuery->setStyleSheet(QStringLiteral(""));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 21, 59, 15));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        twCatalogList = new QTabWidget(centralwidget);
        twCatalogList->setObjectName(QStringLiteral("twCatalogList"));
        twCatalogList->setGeometry(QRect(40, 60, 1011, 511));
        twCatalogList->setTabPosition(QTabWidget::West);
        twCatalogList->setTabShape(QTabWidget::Rounded);
        twCatalogList->setElideMode(Qt::ElideNone);
        twCatalogList->setDocumentMode(false);
        twCatalogList->setTabsClosable(false);
        twCatalogList->setMovable(true);
        tab_Search = new QWidget();
        tab_Search->setObjectName(QStringLiteral("tab_Search"));
        twBookCatalog = new QTableWidget(tab_Search);
        if (twBookCatalog->columnCount() < 5)
            twBookCatalog->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        twBookCatalog->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        twBookCatalog->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        twBookCatalog->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        twBookCatalog->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        twBookCatalog->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        twBookCatalog->setObjectName(QStringLiteral("twBookCatalog"));
        twBookCatalog->setGeometry(QRect(0, 10, 961, 481));
        twBookCatalog->setAutoFillBackground(true);
        twBookCatalog->setStyleSheet(QLatin1String("QHeaderView {\n"
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
        twBookCatalog->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        twBookCatalog->setAlternatingRowColors(true);
        twBookCatalog->setSelectionMode(QAbstractItemView::SingleSelection);
        twBookCatalog->setSelectionBehavior(QAbstractItemView::SelectRows);
        twBookCatalog->setSortingEnabled(true);
        twBookCatalog->horizontalHeader()->setStretchLastSection(true);
        twCatalogList->addTab(tab_Search, QString());
        tab_FullDescription = new QWidget();
        tab_FullDescription->setObjectName(QStringLiteral("tab_FullDescription"));
        gbCOver = new QGroupBox(tab_FullDescription);
        gbCOver->setObjectName(QStringLiteral("gbCOver"));
        gbCOver->setGeometry(QRect(20, 30, 241, 271));
        lblCover = new QLabel(gbCOver);
        lblCover->setObjectName(QStringLiteral("lblCover"));
        lblCover->setGeometry(QRect(0, 0, 241, 271));
        lblCover->setTextFormat(Qt::RichText);
        lblCover->setScaledContents(true);
        groupBox = new QGroupBox(tab_FullDescription);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(270, 30, 701, 271));
        teAnnotation = new QTextEdit(groupBox);
        teAnnotation->setObjectName(QStringLiteral("teAnnotation"));
        teAnnotation->setGeometry(QRect(10, 30, 681, 221));
        groupBox_2 = new QGroupBox(tab_FullDescription);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 310, 951, 351));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(300, 30, 331, 321));
        tvContain = new QTreeView(groupBox_3);
        tvContain->setObjectName(QStringLiteral("tvContain"));
        tvContain->setGeometry(QRect(10, 30, 311, 281));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(640, 30, 301, 321));
        lwLocate = new QListWidget(groupBox_4);
        lwLocate->setObjectName(QStringLiteral("lwLocate"));
        lwLocate->setGeometry(QRect(10, 30, 281, 281));
        lwLocate->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lwLocate->setProperty("showDropIndicator", QVariant(false));
        lwLocate->setSortingEnabled(true);
        twCatalogList->addTab(tab_FullDescription, QString());
        leDelay = new QLineEdit(centralwidget);
        leDelay->setObjectName(QStringLiteral("leDelay"));
        leDelay->setGeometry(QRect(10, 620, 41, 23));
        leDelay->setAlignment(Qt::AlignCenter);
        vsDelay = new QSlider(centralwidget);
        vsDelay->setObjectName(QStringLiteral("vsDelay"));
        vsDelay->setGeometry(QRect(20, 340, 23, 271));
        vsDelay->setMaximum(10);
        vsDelay->setPageStep(1);
        vsDelay->setOrientation(Qt::Vertical);
        vsDelay->setInvertedAppearance(true);
        vsDelay->setInvertedControls(false);
        vsDelay->setTickPosition(QSlider::TicksBothSides);
        vsDelay->setTickInterval(1);
        leLimit = new QLineEdit(centralwidget);
        leLimit->setObjectName(QStringLiteral("leLimit"));
        leLimit->setGeometry(QRect(5, 660, 51, 21));
        lblDelay = new QLabel(centralwidget);
        lblDelay->setObjectName(QStringLiteral("lblDelay"));
        lblDelay->setGeometry(QRect(1, 330, 61, 20));
        lblLimit = new QLabel(centralwidget);
        lblLimit->setObjectName(QStringLiteral("lblLimit"));
        lblLimit->setGeometry(QRect(20, 650, 52, 13));
        hsTimerBoost = new QSlider(centralwidget);
        hsTimerBoost->setObjectName(QStringLiteral("hsTimerBoost"));
        hsTimerBoost->setGeometry(QRect(120, 40, 861, 23));
        hsTimerBoost->setMaximum(100);
        hsTimerBoost->setOrientation(Qt::Horizontal);
        hsTimerBoost->setTickPosition(QSlider::TicksAbove);
        hsTimerBoost->setTickInterval(5);
        leBoost = new QLineEdit(centralwidget);
        leBoost->setObjectName(QStringLiteral("leBoost"));
        leBoost->setGeometry(QRect(990, 40, 41, 21));
        cbFilterAddress = new QComboBox(centralwidget);
        cbFilterAddress->setObjectName(QStringLiteral("cbFilterAddress"));
        cbFilterAddress->setGeometry(QRect(780, 17, 211, 22));
        catalogbook->setCentralWidget(centralwidget);
        mnu = new QMenuBar(catalogbook);
        mnu->setObjectName(QStringLiteral("mnu"));
        mnu->setGeometry(QRect(0, 0, 1107, 21));
        mnu->setDefaultUp(false);
        mnu->setNativeMenuBar(true);
        menu = new QMenu(mnu);
        menu->setObjectName(QStringLiteral("menu"));
        catalogbook->setMenuBar(mnu);
        statusbar = new QStatusBar(catalogbook);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        catalogbook->setStatusBar(statusbar);

        mnu->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(catalogbook);

        twCatalogList->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(catalogbook);
    } // setupUi

    void retranslateUi(QMainWindow *catalogbook)
    {
        catalogbook->setWindowTitle(QApplication::translate("catalogbook", "\320\220\320\240\320\234 \320\232\320\260\321\202\320\260\320\273\320\276\320\263 \320\272\320\275\320\270\320\263", 0));
        action->setText(QApplication::translate("catalogbook", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \320\262\321\200\321\203\321\207\320\275\321\203\321\216", 0));
        leSearchQuery->setPlaceholderText(QApplication::translate("catalogbook", "\320\222\320\260\321\210 \320\277\320\276\320\270\321\201\320\272\320\276\320\262\321\213\320\271 \320\267\320\260\320\277\321\200\320\276\321\201 (\320\264\320\276\320\277\321\203\321\201\320\272\320\260\320\265\321\202\321\201\321\217 \320\277\320\276\320\270\321\201\320\272 \320\277\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216, \320\277\320\276 \321\201\320\265\321\200\320\270\320\270, \320\277\320\276 \320\260\320\262\321\202\320\276\321\200\321\203)", 0));
        label->setText(QApplication::translate("catalogbook", "\320\237\320\276\320\270\321\201\320\272:", 0));
        QTableWidgetItem *___qtablewidgetitem = twBookCatalog->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("catalogbook", "\320\220\320\262\321\202\320\276\321\200", 0));
        QTableWidgetItem *___qtablewidgetitem1 = twBookCatalog->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("catalogbook", "\320\227\320\260\320\263\320\273\320\260\320\262\320\270\320\265", 0));
        QTableWidgetItem *___qtablewidgetitem2 = twBookCatalog->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("catalogbook", "\320\241\320\265\321\200\320\270\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem3 = twBookCatalog->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("catalogbook", "\320\227\320\260\320\272\320\260\320\267\320\260\321\202\321\214?", 0));
        QTableWidgetItem *___qtablewidgetitem4 = twBookCatalog->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("catalogbook", "Locate", 0));
        twCatalogList->setTabText(twCatalogList->indexOf(tab_Search), QApplication::translate("catalogbook", "\320\237\320\276\320\270\321\201\320\272 \320\277\320\276 \320\272\320\260\321\202\320\260\320\273\320\276\320\263\321\203", 0));
        gbCOver->setTitle(QString());
        lblCover->setText(QString());
        groupBox->setTitle(QApplication::translate("catalogbook", "\320\220\320\275\320\275\320\276\321\202\320\260\321\206\320\270\321\217", 0));
        groupBox_2->setTitle(QApplication::translate("catalogbook", "\320\221\320\270\320\261\320\273\320\270\320\276\320\263\321\200\320\260\321\204\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\201\320\262\320\265\320\264\320\265\320\275\320\270\321\217", 0));
        groupBox_3->setTitle(QApplication::translate("catalogbook", "\320\241\320\276\320\264\320\265\321\200\320\266\320\260\320\275\320\270\320\265", 0));
        groupBox_4->setTitle(QApplication::translate("catalogbook", "\320\234\320\265\321\201\321\202\320\276 \321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217", 0));
        twCatalogList->setTabText(twCatalogList->indexOf(tab_FullDescription), QApplication::translate("catalogbook", "\320\236\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", 0));
        leDelay->setText(QApplication::translate("catalogbook", "0", 0));
        leLimit->setText(QApplication::translate("catalogbook", "500", 0));
        lblDelay->setText(QApplication::translate("catalogbook", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260", 0));
        lblLimit->setText(QApplication::translate("catalogbook", "LIMIT", 0));
        leBoost->setText(QApplication::translate("catalogbook", "70", 0));
        menu->setTitle(QApplication::translate("catalogbook", "\320\232\320\260\321\202\320\260\320\273\320\276\320\263", 0));
    } // retranslateUi

};

namespace Ui {
    class catalogbook: public Ui_catalogbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATALOGBOOK_H
