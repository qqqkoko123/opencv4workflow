/********************************************************************************
** Form generated from reading UI file 'frmLogin.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLOGIN_H
#define UI_FRMLOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmLoginClass
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *txtUserName;
    QPushButton *btnLogout;
    QLineEdit *txtUserPW;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnLogin;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_3;
    QLabel *label_2;

    void setupUi(QWidget *frmLoginClass)
    {
        if (frmLoginClass->objectName().isEmpty())
            frmLoginClass->setObjectName(QString::fromUtf8("frmLoginClass"));
        frmLoginClass->resize(520, 270);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmLoginClass->sizePolicy().hasHeightForWidth());
        frmLoginClass->setSizePolicy(sizePolicy);
        frmLoginClass->setMinimumSize(QSize(520, 270));
        frmLoginClass->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        frmLoginClass->setFont(font);
        frmLoginClass->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QMacVisual/Icon/other_478.ico"), QSize(), QIcon::Normal, QIcon::Off);
        frmLoginClass->setWindowIcon(icon);
        frmLoginClass->setStyleSheet(QString::fromUtf8("QWidget#frmLoginClass{background-color: #bcc2bc;}\n"
"QWidget#frmLoginClass{font: 10pt \"Arial\";}"));
        horizontalLayout = new QHBoxLayout(frmLoginClass);
        horizontalLayout->setSpacing(7);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        txtUserName = new QLineEdit(frmLoginClass);
        txtUserName->setObjectName(QString::fromUtf8("txtUserName"));
        sizePolicy.setHeightForWidth(txtUserName->sizePolicy().hasHeightForWidth());
        txtUserName->setSizePolicy(sizePolicy);
        txtUserName->setMaximumSize(QSize(16777215, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        txtUserName->setFont(font1);
        txtUserName->setFocusPolicy(Qt::StrongFocus);
        txtUserName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border: 1px groove gray;border-radius: 2px;padding: 2px 4px;"));
        txtUserName->setReadOnly(false);

        gridLayout->addWidget(txtUserName, 3, 1, 1, 4);

        btnLogout = new QPushButton(frmLoginClass);
        btnLogout->setObjectName(QString::fromUtf8("btnLogout"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnLogout->sizePolicy().hasHeightForWidth());
        btnLogout->setSizePolicy(sizePolicy1);
        btnLogout->setMinimumSize(QSize(107, 42));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        btnLogout->setFont(font2);
        btnLogout->setFocusPolicy(Qt::StrongFocus);
        btnLogout->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 163, 97);\n"
"color: rgb(0, 0, 0);\n"
"border: 2px groove gray;border-radius: 8px;padding: 2px 4px;"));

        gridLayout->addWidget(btnLogout, 7, 2, 1, 1);

        txtUserPW = new QLineEdit(frmLoginClass);
        txtUserPW->setObjectName(QString::fromUtf8("txtUserPW"));
        sizePolicy.setHeightForWidth(txtUserPW->sizePolicy().hasHeightForWidth());
        txtUserPW->setSizePolicy(sizePolicy);
        txtUserPW->setMaximumSize(QSize(16777215, 35));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Calibri"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        txtUserPW->setFont(font3);
        txtUserPW->setFocusPolicy(Qt::StrongFocus);
        txtUserPW->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(25, 75, 11);\n"
"border: 1px groove gray;border-radius: 2px;padding: 2px 4px;"));

        gridLayout->addWidget(txtUserPW, 5, 1, 1, 4);

        horizontalSpacer = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 7, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 7, 1, 1, 1);

        btnLogin = new QPushButton(frmLoginClass);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        sizePolicy1.setHeightForWidth(btnLogin->sizePolicy().hasHeightForWidth());
        btnLogin->setSizePolicy(sizePolicy1);
        btnLogin->setMinimumSize(QSize(107, 42));
        btnLogin->setFont(font2);
        btnLogin->setFocusPolicy(Qt::StrongFocus);
        btnLogin->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 127);\n"
"color: rgb(0, 0, 0);\n"
"border: 2px groove gray;border-radius: 8px;padding: 2px 4px;"));

        gridLayout->addWidget(btnLogin, 7, 4, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 1);

        label = new QLabel(frmLoginClass);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setPixmap(QPixmap(QString::fromUtf8(":/Bitmaps/user_2.png")));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 0, 0, 1, 1);

        label_3 = new QLabel(frmLoginClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(12);
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(75, 75, 61);"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_2 = new QLabel(frmLoginClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font4);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(25, 75, 11);"));

        gridLayout->addWidget(label_2, 5, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(frmLoginClass);

        QMetaObject::connectSlotsByName(frmLoginClass);
    } // setupUi

    void retranslateUi(QWidget *frmLoginClass)
    {
        frmLoginClass->setWindowTitle(QCoreApplication::translate("frmLoginClass", "QMacVisual", nullptr));
        btnLogout->setText(QCoreApplication::translate("frmLoginClass", "\346\263\250\351\224\200", nullptr));
        txtUserPW->setText(QString());
        btnLogin->setText(QCoreApplication::translate("frmLoginClass", "\347\231\273\345\275\225", nullptr));
        label->setText(QString());
        label_3->setText(QCoreApplication::translate("frmLoginClass", "\347\224\250\346\210\267\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("frmLoginClass", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmLoginClass: public Ui_frmLoginClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLOGIN_H
