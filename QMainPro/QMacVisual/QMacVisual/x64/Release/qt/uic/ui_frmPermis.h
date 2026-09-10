/********************************************************************************
** Form generated from reading UI file 'frmPermis.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPERMIS_H
#define UI_FRMPERMIS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmPermisClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_4;
    QPushButton *btnDelete;
    QLabel *label_7;
    QLineEdit *txtUserPW;
    QSpacerItem *verticalSpacer_8;
    QLineEdit *txtUserName;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_8;
    QPushButton *btnAdd;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QGroupBox *groupQuery;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QPushButton *btnQuery;
    QTextEdit *txtQuery;

    void setupUi(QWidget *frmPermisClass)
    {
        if (frmPermisClass->objectName().isEmpty())
            frmPermisClass->setObjectName(QString::fromUtf8("frmPermisClass"));
        frmPermisClass->resize(855, 378);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmPermisClass->sizePolicy().hasHeightForWidth());
        frmPermisClass->setSizePolicy(sizePolicy);
        frmPermisClass->setMinimumSize(QSize(855, 378));
        frmPermisClass->setMaximumSize(QSize(855, 378));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        frmPermisClass->setFont(font);
        frmPermisClass->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QMacVisual/Icon/other_478.ico"), QSize(), QIcon::Normal, QIcon::Off);
        frmPermisClass->setWindowIcon(icon);
        frmPermisClass->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        verticalLayout = new QVBoxLayout(frmPermisClass);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 1, 2, 1);
        groupBox_2 = new QGroupBox(frmPermisClass);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(415, 0));
        groupBox_2->setMaximumSize(QSize(415, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        groupBox_2->setFont(font1);
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 127);\n"
"font: 16pt \"\346\245\267\344\275\223\";\n"
"text-align:center;"));
        groupBox_2->setAlignment(Qt::AlignCenter);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(1);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(2);
        gridLayout_4->setVerticalSpacing(7);
        gridLayout_4->setContentsMargins(5, 5, 5, 5);
        btnDelete = new QPushButton(groupBox_2);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        sizePolicy.setHeightForWidth(btnDelete->sizePolicy().hasHeightForWidth());
        btnDelete->setSizePolicy(sizePolicy);
        btnDelete->setMinimumSize(QSize(100, 42));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        btnDelete->setFont(font2);
        btnDelete->setFocusPolicy(Qt::StrongFocus);
        btnDelete->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 85, 127);\n"
"color: rgb(0, 0, 0);\n"
"border: 2px groove gray;border-radius: 8px;padding: 2px 4px;\n"
"font: 15pt \"\346\245\267\344\275\223\";"));

        gridLayout_4->addWidget(btnDelete, 5, 2, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(25, 75, 11);\n"
"font: 14pt \"\346\245\267\344\275\223\";"));

        gridLayout_4->addWidget(label_7, 3, 0, 1, 1);

        txtUserPW = new QLineEdit(groupBox_2);
        txtUserPW->setObjectName(QString::fromUtf8("txtUserPW"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(txtUserPW->sizePolicy().hasHeightForWidth());
        txtUserPW->setSizePolicy(sizePolicy2);
        txtUserPW->setMinimumSize(QSize(275, 0));
        txtUserPW->setMaximumSize(QSize(16777215, 35));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Calibri"));
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        txtUserPW->setFont(font4);
        txtUserPW->setFocusPolicy(Qt::StrongFocus);
        txtUserPW->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(25, 75, 11);\n"
"border: 1px groove gray;border-radius: 3px;padding: 2px 4px;\n"
"font: 14pt \"Calibri\";"));

        gridLayout_4->addWidget(txtUserPW, 3, 1, 1, 4);

        verticalSpacer_8 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_8, 4, 0, 1, 1);

        txtUserName = new QLineEdit(groupBox_2);
        txtUserName->setObjectName(QString::fromUtf8("txtUserName"));
        sizePolicy2.setHeightForWidth(txtUserName->sizePolicy().hasHeightForWidth());
        txtUserName->setSizePolicy(sizePolicy2);
        txtUserName->setMinimumSize(QSize(275, 0));
        txtUserName->setMaximumSize(QSize(16777215, 35));
        txtUserName->setFont(font4);
        txtUserName->setFocusPolicy(Qt::StrongFocus);
        txtUserName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"border: 1px groove gray;border-radius: 3px;padding: 2px 4px;\n"
"font: 14pt \"Calibri\";"));
        txtUserName->setReadOnly(false);

        gridLayout_4->addWidget(txtUserName, 1, 1, 1, 4);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_6, 0, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font3);
        label_8->setAutoFillBackground(false);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 14pt \"\346\245\267\344\275\223\";"));

        gridLayout_4->addWidget(label_8, 1, 0, 1, 1);

        btnAdd = new QPushButton(groupBox_2);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        sizePolicy.setHeightForWidth(btnAdd->sizePolicy().hasHeightForWidth());
        btnAdd->setSizePolicy(sizePolicy);
        btnAdd->setMinimumSize(QSize(100, 42));
        btnAdd->setFont(font1);
        btnAdd->setFocusPolicy(Qt::StrongFocus);
        btnAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 190, 127);\n"
"color: rgb(0, 0, 0);\n"
"border: 2px groove gray;border-radius: 8px;padding: 2px 4px;\n"
"font: 15.5pt \"\346\245\267\344\275\223\";"));

        gridLayout_4->addWidget(btnAdd, 5, 4, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_4->addItem(verticalSpacer_7, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 5, 3, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);


        gridLayout->addWidget(groupBox_2, 2, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 45, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        label = new QLabel(frmPermisClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/Bitmaps/group.png")));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label->setMargin(0);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        groupQuery = new QGroupBox(frmPermisClass);
        groupQuery->setObjectName(QString::fromUtf8("groupQuery"));
        sizePolicy1.setHeightForWidth(groupQuery->sizePolicy().hasHeightForWidth());
        groupQuery->setSizePolicy(sizePolicy1);
        groupQuery->setMinimumSize(QSize(435, 0));
        groupQuery->setMaximumSize(QSize(16777215, 16777215));
        groupQuery->setFont(font1);
        groupQuery->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 127);\n"
"font: 16pt \"\346\245\267\344\275\223\";\n"
"text-align:center;"));
        groupQuery->setAlignment(Qt::AlignCenter);
        verticalLayout_3 = new QVBoxLayout(groupQuery);
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(7);
        gridLayout_3->setVerticalSpacing(1);
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        btnQuery = new QPushButton(groupQuery);
        btnQuery->setObjectName(QString::fromUtf8("btnQuery"));
        sizePolicy.setHeightForWidth(btnQuery->sizePolicy().hasHeightForWidth());
        btnQuery->setSizePolicy(sizePolicy);
        btnQuery->setMinimumSize(QSize(100, 42));
        btnQuery->setFont(font2);
        btnQuery->setFocusPolicy(Qt::StrongFocus);
        btnQuery->setStyleSheet(QString::fromUtf8("background-color: rgb(185, 170, 127);\n"
"color: rgb(50, 50, 50);\n"
"border: 2px groove gray;border-radius: 8px;padding: 2px 4px;\n"
"font: 15pt \"\346\245\267\344\275\223\";"));

        gridLayout_3->addWidget(btnQuery, 0, 0, 1, 1);

        txtQuery = new QTextEdit(groupQuery);
        txtQuery->setObjectName(QString::fromUtf8("txtQuery"));
        txtQuery->setEnabled(true);
        QFont font5;
        font5.setFamily(QString::fromUtf8("Calibri"));
        font5.setPointSize(13);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        txtQuery->setFont(font5);
        txtQuery->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #b7c7a7, stop: 0.85 #b7c7a7,stop:1 #dfd5cf);\n"
"font: 13pt \"Calibri\";\n"
"color: rgb(0, 0, 255);"));
        txtQuery->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        txtQuery->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        txtQuery->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        gridLayout_3->addWidget(txtQuery, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);


        gridLayout->addWidget(groupQuery, 2, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(frmPermisClass);

        QMetaObject::connectSlotsByName(frmPermisClass);
    } // setupUi

    void retranslateUi(QWidget *frmPermisClass)
    {
        frmPermisClass->setWindowTitle(QCoreApplication::translate("frmPermisClass", "QMacVisual", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("frmPermisClass", "\347\276\244\347\273\204\347\256\241\347\220\206", nullptr));
        btnDelete->setText(QCoreApplication::translate("frmPermisClass", "\345\210\240\351\231\244", nullptr));
        label_7->setText(QCoreApplication::translate("frmPermisClass", "\347\224\250\346\210\267\345\257\206\347\240\201:", nullptr));
        txtUserPW->setText(QString());
        label_8->setText(QCoreApplication::translate("frmPermisClass", "\347\224\250\346\210\267\345\220\215\347\247\260:", nullptr));
        btnAdd->setText(QCoreApplication::translate("frmPermisClass", "\346\267\273\345\212\240", nullptr));
        label->setText(QString());
        groupQuery->setTitle(QCoreApplication::translate("frmPermisClass", "\347\224\250\346\210\267\346\237\245\350\257\242", nullptr));
        btnQuery->setText(QCoreApplication::translate("frmPermisClass", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmPermisClass: public Ui_frmPermisClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPERMIS_H
