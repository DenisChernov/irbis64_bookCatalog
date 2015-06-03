/********************************************************************************
** Form generated from reading UI file 'form_ReturnDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_RETURNDIALOG_H
#define UI_FORM_RETURNDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_ReturnDialog
{
public:
    QLabel *lblInfo;
    QLineEdit *leCode;
    QPushButton *pbClose;

    void setupUi(QWidget *form_ReturnDialog)
    {
        if (form_ReturnDialog->objectName().isEmpty())
            form_ReturnDialog->setObjectName(QStringLiteral("form_ReturnDialog"));
        form_ReturnDialog->setWindowModality(Qt::ApplicationModal);
        form_ReturnDialog->resize(350, 160);
        lblInfo = new QLabel(form_ReturnDialog);
        lblInfo->setObjectName(QStringLiteral("lblInfo"));
        lblInfo->setGeometry(QRect(20, 20, 311, 61));
        lblInfo->setWordWrap(true);
        leCode = new QLineEdit(form_ReturnDialog);
        leCode->setObjectName(QStringLiteral("leCode"));
        leCode->setGeometry(QRect(20, 80, 311, 23));
        pbClose = new QPushButton(form_ReturnDialog);
        pbClose->setObjectName(QStringLiteral("pbClose"));
        pbClose->setGeometry(QRect(230, 120, 100, 24));

        retranslateUi(form_ReturnDialog);

        QMetaObject::connectSlotsByName(form_ReturnDialog);
    } // setupUi

    void retranslateUi(QWidget *form_ReturnDialog)
    {
        form_ReturnDialog->setWindowTitle(QApplication::translate("form_ReturnDialog", "\320\241\320\260\320\274\320\276\321\201\321\202\320\276\321\217\321\202\320\265\320\273\321\214\320\275\321\213\320\271 \320\262\320\276\320\267\320\262\321\200\320\260\321\202 \320\272\320\275\320\270\320\263", 0));
        lblInfo->setText(QApplication::translate("form_ReturnDialog", "\320\237\320\276\320\264\320\275\320\265\321\201\320\270\321\202\320\265 \321\210\321\202\321\200\320\270\321\205-\320\272\320\276\320\264, \320\277\321\200\320\270\320\272\320\273\320\265\320\265\320\275\321\213\320\271 \320\272 \320\272\320\275\320\270\320\263\320\265, \320\272 \321\201\320\272\320\260\320\275\320\265\321\200\321\203.", 0));
        pbClose->setText(QApplication::translate("form_ReturnDialog", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class form_ReturnDialog: public Ui_form_ReturnDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_RETURNDIALOG_H
