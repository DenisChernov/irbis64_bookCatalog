/********************************************************************************
** Form generated from reading UI file 'form_Auth.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_AUTH_H
#define UI_FORM_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_form_Auth
{
public:
    QGroupBox *gbAuth;
    QLabel *lblReaderInfo;
    QLineEdit *leReaderLogin;
    QCommandLinkButton *cbAuth;

    void setupUi(QDialog *form_Auth)
    {
        if (form_Auth->objectName().isEmpty())
            form_Auth->setObjectName(QStringLiteral("form_Auth"));
        form_Auth->setWindowModality(Qt::ApplicationModal);
        form_Auth->resize(422, 168);
        form_Auth->setContextMenuPolicy(Qt::DefaultContextMenu);
        form_Auth->setModal(true);
        gbAuth = new QGroupBox(form_Auth);
        gbAuth->setObjectName(QStringLiteral("gbAuth"));
        gbAuth->setGeometry(QRect(10, 10, 401, 141));
        gbAuth->setFlat(false);
        lblReaderInfo = new QLabel(gbAuth);
        lblReaderInfo->setObjectName(QStringLiteral("lblReaderInfo"));
        lblReaderInfo->setGeometry(QRect(20, 30, 321, 16));
        leReaderLogin = new QLineEdit(gbAuth);
        leReaderLogin->setObjectName(QStringLiteral("leReaderLogin"));
        leReaderLogin->setGeometry(QRect(20, 50, 361, 23));
        cbAuth = new QCommandLinkButton(gbAuth);
        cbAuth->setObjectName(QStringLiteral("cbAuth"));
        cbAuth->setGeometry(QRect(290, 90, 91, 41));

        retranslateUi(form_Auth);

        QMetaObject::connectSlotsByName(form_Auth);
    } // setupUi

    void retranslateUi(QDialog *form_Auth)
    {
        form_Auth->setWindowTitle(QApplication::translate("form_Auth", "\320\220\321\203\321\202\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217", 0));
        gbAuth->setTitle(QString());
        lblReaderInfo->setText(QApplication::translate("form_Auth", "\320\224\320\260\320\275\320\275\321\213\320\265 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217:", 0));
        leReaderLogin->setPlaceholderText(QApplication::translate("form_Auth", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\262\320\260\321\210\320\265\320\263\320\276 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\276\320\263\320\276 \320\261\320\270\320\273\320\265\321\202\320\260", 0));
        cbAuth->setText(QApplication::translate("form_Auth", "\320\222\320\276\320\271\321\202\320\270", 0));
    } // retranslateUi

};

namespace Ui {
    class form_Auth: public Ui_form_Auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_AUTH_H
