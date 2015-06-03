/********************************************************************************
** Form generated from reading UI file 'form_Prolong.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_PROLONG_H
#define UI_FORM_PROLONG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_form_Prolong
{
public:
    QPushButton *pbProlong;
    QPushButton *pbClearChoise;
    QTableWidget *twProlong;

    void setupUi(QDialog *form_Prolong)
    {
        if (form_Prolong->objectName().isEmpty())
            form_Prolong->setObjectName(QStringLiteral("form_Prolong"));
        form_Prolong->resize(846, 405);
        pbProlong = new QPushButton(form_Prolong);
        pbProlong->setObjectName(QStringLiteral("pbProlong"));
        pbProlong->setGeometry(QRect(590, 370, 100, 24));
        pbClearChoise = new QPushButton(form_Prolong);
        pbClearChoise->setObjectName(QStringLiteral("pbClearChoise"));
        pbClearChoise->setGeometry(QRect(480, 370, 100, 24));
        twProlong = new QTableWidget(form_Prolong);
        if (twProlong->columnCount() < 7)
            twProlong->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        twProlong->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        twProlong->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        twProlong->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        twProlong->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        twProlong->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        twProlong->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        twProlong->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        twProlong->setObjectName(QStringLiteral("twProlong"));
        twProlong->setGeometry(QRect(10, 10, 831, 351));
        twProlong->setLayoutDirection(Qt::LeftToRight);
        twProlong->setStyleSheet(QLatin1String("QHeaderView {\n"
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
        twProlong->setEditTriggers(QAbstractItemView::NoEditTriggers);
        twProlong->setProperty("showDropIndicator", QVariant(false));
        twProlong->setDragDropOverwriteMode(false);
        twProlong->setAlternatingRowColors(true);
        twProlong->setSelectionMode(QAbstractItemView::NoSelection);
        twProlong->setSortingEnabled(true);
        twProlong->setWordWrap(false);
        twProlong->horizontalHeader()->setStretchLastSection(true);

        retranslateUi(form_Prolong);

        QMetaObject::connectSlotsByName(form_Prolong);
    } // setupUi

    void retranslateUi(QDialog *form_Prolong)
    {
        form_Prolong->setWindowTitle(QApplication::translate("form_Prolong", "\320\237\321\200\320\276\320\264\320\273\320\265\320\275\320\270\320\265", 0));
        pbProlong->setText(QApplication::translate("form_Prolong", "\320\237\321\200\320\276\320\264\320\273\320\270\321\202\321\214", 0));
        pbClearChoise->setText(QApplication::translate("form_Prolong", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0));
        QTableWidgetItem *___qtablewidgetitem = twProlong->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("form_Prolong", "\320\242\320\270\320\277 \320\270\320\267\320\264\320\260\320\275\320\270\321\217", 0));
        QTableWidgetItem *___qtablewidgetitem1 = twProlong->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("form_Prolong", "\320\237\321\200\320\276\320\264\320\273\320\265\320\275\320\270\320\271", 0));
        QTableWidgetItem *___qtablewidgetitem2 = twProlong->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("form_Prolong", "\320\236\321\201\321\202.", 0));
        QTableWidgetItem *___qtablewidgetitem3 = twProlong->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("form_Prolong", "\320\220\320\262\321\202\320\276\321\200 / \320\226\321\203\321\200\320\275\320\260\320\273", 0));
        QTableWidgetItem *___qtablewidgetitem4 = twProlong->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QApplication::translate("form_Prolong", "\320\227\320\260\320\263\320\273\320\260\320\262\320\270\320\265 / \320\223\320\276\320\264,\320\275\320\276\320\274\320\265\321\200", 0));
        QTableWidgetItem *___qtablewidgetitem5 = twProlong->horizontalHeaderItem(6);
        ___qtablewidgetitem5->setText(QApplication::translate("form_Prolong", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", 0));
    } // retranslateUi

};

namespace Ui {
    class form_Prolong: public Ui_form_Prolong {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_PROLONG_H
