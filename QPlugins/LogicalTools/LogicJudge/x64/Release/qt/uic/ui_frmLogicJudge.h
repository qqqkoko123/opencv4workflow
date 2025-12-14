/********************************************************************************
** Form generated from reading UI file 'frmLogicJudge.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLOGICJUDGE_H
#define UI_FRMLOGICJUDGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmLogicJudgeClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupC;
    QComboBox *comboType;
    QLabel *label_30;
    QGroupBox *groupC2;
    QPushButton *btnDelLinkBool;
    QPushButton *btnLinkBool;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *txtLinkBool;
    QComboBox *comboBool;
    QGroupBox *groupC3;
    QPushButton *btnDelLinkRegex;
    QPushButton *btnLinkRegex;
    QLabel *label_7;
    QLineEdit *txtLinkRegex;
    QComboBox *comboRegex;
    QSpinBox *spinRegex;
    QLabel *lblMsg;

    void setupUi(QDialog *frmLogicJudgeClass)
    {
        if (frmLogicJudgeClass->objectName().isEmpty())
            frmLogicJudgeClass->setObjectName(QString::fromUtf8("frmLogicJudgeClass"));
        frmLogicJudgeClass->resize(600, 380);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmLogicJudgeClass->sizePolicy().hasHeightForWidth());
        frmLogicJudgeClass->setSizePolicy(sizePolicy);
        frmLogicJudgeClass->setMinimumSize(QSize(600, 380));
        frmLogicJudgeClass->setMaximumSize(QSize(600, 380));
        frmLogicJudgeClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmLogicJudgeClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmLogicJudgeClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmLogicJudgeClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmLogicJudgeClass);
        btnExecute->setObjectName(QString::fromUtf8("btnExecute"));
        btnExecute->setMinimumSize(QSize(90, 37));
        btnExecute->setFont(font);
        btnExecute->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 135, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 155, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 175, 127);}"));

        horizontalLayout->addWidget(btnExecute);

        horizontalSpacer_2 = new QSpacerItem(6, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        tabWidget = new QTabWidget(frmLogicJudgeClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupC = new QGroupBox(tab);
        groupC->setObjectName(QString::fromUtf8("groupC"));
        groupC->setGeometry(QRect(9, 14, 576, 229));
        groupC->setFont(font);
        groupC->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        comboType = new QComboBox(groupC);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName(QString::fromUtf8("comboType"));
        comboType->setGeometry(QRect(96, 32, 120, 30));
        sizePolicy.setHeightForWidth(comboType->sizePolicy().hasHeightForWidth());
        comboType->setSizePolicy(sizePolicy);
        comboType->setMinimumSize(QSize(120, 30));
        comboType->setMaximumSize(QSize(120, 16777215));
        comboType->setFont(font);
        comboType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_30 = new QLabel(groupC);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(17, 37, 81, 19));
        label_30->setFont(font);
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        groupC2 = new QGroupBox(groupC);
        groupC2->setObjectName(QString::fromUtf8("groupC2"));
        groupC2->setGeometry(QRect(6, 80, 565, 72));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: #b7c7af;\n"
"color: rgb(0, 0, 127);"));
        btnDelLinkBool = new QPushButton(groupC2);
        btnDelLinkBool->setObjectName(QString::fromUtf8("btnDelLinkBool"));
        btnDelLinkBool->setGeometry(QRect(534, 28, 27, 27));
        btnDelLinkBool->setStyleSheet(QString::fromUtf8("QWidget{ border:none;background-color: rgba(0, 0, 0, 0);border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkBool->setIcon(icon);
        btnDelLinkBool->setIconSize(QSize(27, 27));
        btnLinkBool = new QPushButton(groupC2);
        btnLinkBool->setObjectName(QString::fromUtf8("btnLinkBool"));
        btnLinkBool->setGeometry(QRect(502, 28, 27, 27));
        btnLinkBool->setStyleSheet(QString::fromUtf8("QWidget{ border:none;background-color: rgba(0, 0, 0, 0);border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkBool->setIcon(icon1);
        btnLinkBool->setIconSize(QSize(27, 27));
        label_5 = new QLabel(groupC2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(405, 30, 16, 19));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        label_4 = new QLabel(groupC2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(4, 32, 119, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        txtLinkBool = new QLineEdit(groupC2);
        txtLinkBool->setObjectName(QString::fromUtf8("txtLinkBool"));
        txtLinkBool->setGeometry(QRect(121, 28, 280, 28));
        txtLinkBool->setFont(font);
        txtLinkBool->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkBool->setAlignment(Qt::AlignCenter);
        txtLinkBool->setReadOnly(true);
        comboBool = new QComboBox(groupC2);
        comboBool->addItem(QString());
        comboBool->setObjectName(QString::fromUtf8("comboBool"));
        comboBool->setGeometry(QRect(423, 28, 70, 28));
        sizePolicy.setHeightForWidth(comboBool->sizePolicy().hasHeightForWidth());
        comboBool->setSizePolicy(sizePolicy);
        comboBool->setMinimumSize(QSize(70, 28));
        comboBool->setMaximumSize(QSize(70, 28));
        comboBool->setFont(font);
        comboBool->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboBool->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        groupC3 = new QGroupBox(groupC);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setEnabled(false);
        groupC3->setGeometry(QRect(6, 154, 565, 72));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: #b7c7af;\n"
"color: rgb(0, 0, 127);"));
        btnDelLinkRegex = new QPushButton(groupC3);
        btnDelLinkRegex->setObjectName(QString::fromUtf8("btnDelLinkRegex"));
        btnDelLinkRegex->setGeometry(QRect(534, 28, 27, 27));
        btnDelLinkRegex->setStyleSheet(QString::fromUtf8("QWidget{ border:none;background-color: rgba(0, 0, 0, 0);border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkRegex->setIcon(icon);
        btnDelLinkRegex->setIconSize(QSize(27, 27));
        btnLinkRegex = new QPushButton(groupC3);
        btnLinkRegex->setObjectName(QString::fromUtf8("btnLinkRegex"));
        btnLinkRegex->setGeometry(QRect(502, 28, 27, 27));
        btnLinkRegex->setStyleSheet(QString::fromUtf8("QWidget{ border:none;background-color: rgba(0, 0, 0, 0);border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkRegex->setIcon(icon1);
        btnLinkRegex->setIconSize(QSize(27, 27));
        label_7 = new QLabel(groupC3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(4, 32, 97, 19));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        txtLinkRegex = new QLineEdit(groupC3);
        txtLinkRegex->setObjectName(QString::fromUtf8("txtLinkRegex"));
        txtLinkRegex->setGeometry(QRect(100, 28, 237, 28));
        txtLinkRegex->setFont(font);
        txtLinkRegex->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkRegex->setAlignment(Qt::AlignCenter);
        txtLinkRegex->setReadOnly(true);
        comboRegex = new QComboBox(groupC3);
        comboRegex->addItem(QString());
        comboRegex->addItem(QString());
        comboRegex->addItem(QString());
        comboRegex->addItem(QString());
        comboRegex->addItem(QString());
        comboRegex->addItem(QString());
        comboRegex->setObjectName(QString::fromUtf8("comboRegex"));
        comboRegex->setGeometry(QRect(344, 28, 55, 28));
        sizePolicy.setHeightForWidth(comboRegex->sizePolicy().hasHeightForWidth());
        comboRegex->setSizePolicy(sizePolicy);
        comboRegex->setMinimumSize(QSize(55, 28));
        comboRegex->setMaximumSize(QSize(55, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        comboRegex->setFont(font2);
        comboRegex->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(170, 170, 127,100);\n"
"}\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 15px; \n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        comboRegex->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        spinRegex = new QSpinBox(groupC3);
        spinRegex->setObjectName(QString::fromUtf8("spinRegex"));
        spinRegex->setGeometry(QRect(407, 28, 87, 28));
        spinRegex->setFont(font);
        spinRegex->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinRegex->setAlignment(Qt::AlignCenter);
        spinRegex->setMinimum(-32768);
        spinRegex->setMaximum(32767);
        spinRegex->setValue(100);
        lblMsg = new QLabel(groupC);
        lblMsg->setObjectName(QString::fromUtf8("lblMsg"));
        lblMsg->setGeometry(QRect(268, 37, 299, 19));
        lblMsg->setFont(font);
        lblMsg->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 127);\n"
"background-color: rgba(0, 0, 0, 0);"));
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(frmLogicJudgeClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmLogicJudgeClass);
    } // setupUi

    void retranslateUi(QDialog *frmLogicJudgeClass)
    {
        frmLogicJudgeClass->setWindowTitle(QCoreApplication::translate("frmLogicJudgeClass", "\345\210\244\346\226\255\350\257\255\345\217\245", nullptr));
        label_3->setText(QCoreApplication::translate("frmLogicJudgeClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmLogicJudgeClass", "\346\211\247\350\241\214", nullptr));
        groupC->setTitle(QCoreApplication::translate("frmLogicJudgeClass", "\346\235\241\344\273\266\350\256\276\347\275\256", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("frmLogicJudgeClass", "Bool\351\223\276\346\216\245", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("frmLogicJudgeClass", "\350\256\241\347\256\227\350\241\250\350\276\276\345\274\217", nullptr));

        label_30->setText(QCoreApplication::translate("frmLogicJudgeClass", "\345\210\244\346\226\255\346\226\271\345\274\217\357\274\232", nullptr));
        groupC2->setTitle(QCoreApplication::translate("frmLogicJudgeClass", "Bool\351\223\276\346\216\245", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkBool->setToolTip(QCoreApplication::translate("frmLogicJudgeClass", "\345\210\240\351\231\244Bool\346\225\260\346\215\256\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkBool->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkBool->setToolTip(QCoreApplication::translate("frmLogicJudgeClass", "\351\223\276\346\216\245Bool\346\225\260\346\215\256", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkBool->setText(QString());
        label_5->setText(QCoreApplication::translate("frmLogicJudgeClass", "=", nullptr));
        label_4->setText(QCoreApplication::translate("frmLogicJudgeClass", "Bool\346\225\260\346\215\256\351\223\276\346\216\245\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkBool->setToolTip(QCoreApplication::translate("frmLogicJudgeClass", "Bool\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        comboBool->setItemText(0, QCoreApplication::translate("frmLogicJudgeClass", "true", nullptr));

        groupC3->setTitle(QCoreApplication::translate("frmLogicJudgeClass", "\350\256\241\347\256\227\350\241\250\350\276\276\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkRegex->setToolTip(QCoreApplication::translate("frmLogicJudgeClass", "\345\210\240\351\231\244\350\256\241\347\256\227\350\241\250\350\276\276\345\274\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkRegex->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkRegex->setToolTip(QCoreApplication::translate("frmLogicJudgeClass", "\351\223\276\346\216\245\350\256\241\347\256\227\350\241\250\350\276\276\345\274\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkRegex->setText(QString());
        label_7->setText(QCoreApplication::translate("frmLogicJudgeClass", "\350\241\250\350\276\276\345\274\217\351\223\276\346\216\245\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkRegex->setToolTip(QCoreApplication::translate("frmLogicJudgeClass", "Int\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        comboRegex->setItemText(0, QCoreApplication::translate("frmLogicJudgeClass", "==", nullptr));
        comboRegex->setItemText(1, QCoreApplication::translate("frmLogicJudgeClass", "!=", nullptr));
        comboRegex->setItemText(2, QCoreApplication::translate("frmLogicJudgeClass", ">", nullptr));
        comboRegex->setItemText(3, QCoreApplication::translate("frmLogicJudgeClass", ">=", nullptr));
        comboRegex->setItemText(4, QCoreApplication::translate("frmLogicJudgeClass", "<", nullptr));
        comboRegex->setItemText(5, QCoreApplication::translate("frmLogicJudgeClass", "<=", nullptr));

        lblMsg->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmLogicJudgeClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmLogicJudgeClass: public Ui_frmLogicJudgeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLOGICJUDGE_H
