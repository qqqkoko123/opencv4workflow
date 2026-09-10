/********************************************************************************
** Form generated from reading UI file 'frmRegister.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMREGISTER_H
#define UI_FRMREGISTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmRegisterClass
{
public:
    QPushButton *btnCmdCheckID;
    QLineEdit *txtAuthorizationCode;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *txtSerialNumber;

    void setupUi(QWidget *frmRegisterClass)
    {
        if (frmRegisterClass->objectName().isEmpty())
            frmRegisterClass->setObjectName(QString::fromUtf8("frmRegisterClass"));
        frmRegisterClass->resize(500, 190);
        frmRegisterClass->setMinimumSize(QSize(500, 190));
        frmRegisterClass->setMaximumSize(QSize(500, 190));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QMacVisual/Icon/other_478.ico"), QSize(), QIcon::Normal, QIcon::Off);
        frmRegisterClass->setWindowIcon(icon);
        frmRegisterClass->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);"));
        btnCmdCheckID = new QPushButton(frmRegisterClass);
        btnCmdCheckID->setObjectName(QString::fromUtf8("btnCmdCheckID"));
        btnCmdCheckID->setGeometry(QRect(364, 144, 120, 37));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(12);
        btnCmdCheckID->setFont(font);
        btnCmdCheckID->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 127);\n"
"color: rgb(255, 255, 255);\n"
"border: 2px groove gray;border-radius: 8px;padding: 2px 4px;"));
        txtAuthorizationCode = new QLineEdit(frmRegisterClass);
        txtAuthorizationCode->setObjectName(QString::fromUtf8("txtAuthorizationCode"));
        txtAuthorizationCode->setGeometry(QRect(84, 76, 401, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        txtAuthorizationCode->setFont(font1);
        txtAuthorizationCode->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtAuthorizationCode->setAlignment(Qt::AlignCenter);
        label = new QLabel(frmRegisterClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(18, 20, 72, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        label->setFont(font2);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background: transparent;"));
        label_2 = new QLabel(frmRegisterClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(18, 78, 72, 21));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(137, 30, 115);\n"
"background: transparent;"));
        txtSerialNumber = new QLineEdit(frmRegisterClass);
        txtSerialNumber->setObjectName(QString::fromUtf8("txtSerialNumber"));
        txtSerialNumber->setGeometry(QRect(84, 18, 401, 27));
        txtSerialNumber->setFont(font1);
        txtSerialNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtSerialNumber->setAlignment(Qt::AlignCenter);
        txtSerialNumber->setReadOnly(true);

        retranslateUi(frmRegisterClass);

        QMetaObject::connectSlotsByName(frmRegisterClass);
    } // setupUi

    void retranslateUi(QWidget *frmRegisterClass)
    {
        frmRegisterClass->setWindowTitle(QCoreApplication::translate("frmRegisterClass", "\346\263\250\345\206\214\350\275\257\344\273\266", nullptr));
        btnCmdCheckID->setText(QCoreApplication::translate("frmRegisterClass", "\346\263\250\345\206\214\350\275\257\344\273\266", nullptr));
        txtAuthorizationCode->setText(QString());
        label->setText(QCoreApplication::translate("frmRegisterClass", "\345\272\217\345\210\227\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("frmRegisterClass", "\346\216\210\346\235\203\347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmRegisterClass: public Ui_frmRegisterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMREGISTER_H
