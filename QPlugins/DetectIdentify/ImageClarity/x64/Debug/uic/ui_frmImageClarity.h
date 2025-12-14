/********************************************************************************
** Form generated from reading UI file 'frmImageClarity.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMIMAGECLARITY_H
#define UI_FRMIMAGECLARITY_H

#include <QtCore/QVariant>
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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmImageClarityClass
{
public:
    QGridLayout *gridLayout;
    QGridLayout *imageLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QPushButton *btnSelectPath;
    QLabel *label_2;
    QLineEdit *txtFolderPath;
    QGroupBox *groupCamera_2;
    QLabel *label_4;
    QComboBox *comboClarity;

    void setupUi(QDialog *frmImageClarityClass)
    {
        if (frmImageClarityClass->objectName().isEmpty())
            frmImageClarityClass->setObjectName(QString::fromUtf8("frmImageClarityClass"));
        frmImageClarityClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmImageClarityClass->sizePolicy().hasHeightForWidth());
        frmImageClarityClass->setSizePolicy(sizePolicy);
        frmImageClarityClass->setMinimumSize(QSize(1160, 655));
        frmImageClarityClass->setMaximumSize(QSize(1160, 655));
        frmImageClarityClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmImageClarityClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        imageLayout = new QGridLayout();
        imageLayout->setSpacing(1);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));

        gridLayout->addLayout(imageLayout, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmImageClarityClass);
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

        txtDescribe = new QLineEdit(frmImageClarityClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmImageClarityClass);
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


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        tabWidget = new QTabWidget(frmImageClarityClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(450, 550));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupCamera = new QGroupBox(tab);
        groupCamera->setObjectName(QString::fromUtf8("groupCamera"));
        groupCamera->setGeometry(QRect(9, 18, 427, 113));
        groupCamera->setFont(font);
        groupCamera->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnSelectPath = new QPushButton(groupCamera);
        btnSelectPath->setObjectName(QString::fromUtf8("btnSelectPath"));
        btnSelectPath->setGeometry(QRect(325, 70, 93, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        btnSelectPath->setFont(font1);
        btnSelectPath->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        label_2 = new QLabel(groupCamera);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(13, 36, 97, 19));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtFolderPath = new QLineEdit(groupCamera);
        txtFolderPath->setObjectName(QString::fromUtf8("txtFolderPath"));
        txtFolderPath->setGeometry(QRect(112, 32, 305, 27));
        txtFolderPath->setFont(font);
        txtFolderPath->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtFolderPath->setReadOnly(true);
        groupCamera_2 = new QGroupBox(tab);
        groupCamera_2->setObjectName(QString::fromUtf8("groupCamera_2"));
        groupCamera_2->setGeometry(QRect(9, 148, 427, 73));
        groupCamera_2->setFont(font);
        groupCamera_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_4 = new QLabel(groupCamera_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 40, 97, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboClarity = new QComboBox(groupCamera_2);
        comboClarity->addItem(QString());
        comboClarity->addItem(QString());
        comboClarity->addItem(QString());
        comboClarity->setObjectName(QString::fromUtf8("comboClarity"));
        comboClarity->setGeometry(QRect(112, 35, 305, 30));
        sizePolicy.setHeightForWidth(comboClarity->sizePolicy().hasHeightForWidth());
        comboClarity->setSizePolicy(sizePolicy);
        comboClarity->setMinimumSize(QSize(85, 30));
        comboClarity->setMaximumSize(QSize(16777215, 16777215));
        comboClarity->setFont(font);
        comboClarity->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 5.5em;\n"
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
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(frmImageClarityClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmImageClarityClass);
    } // setupUi

    void retranslateUi(QDialog *frmImageClarityClass)
    {
        frmImageClarityClass->setWindowTitle(QCoreApplication::translate("frmImageClarityClass", "\345\233\276\345\203\217\346\270\205\346\231\260\345\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("frmImageClarityClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmImageClarityClass", "\346\211\247\350\241\214", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmImageClarityClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        btnSelectPath->setText(QCoreApplication::translate("frmImageClarityClass", "\350\267\257\345\276\204\351\200\211\346\213\251", nullptr));
        label_2->setText(QCoreApplication::translate("frmImageClarityClass", "\346\226\207\344\273\266\345\244\271\350\267\257\345\276\204\357\274\232", nullptr));
        txtFolderPath->setText(QString());
        groupCamera_2->setTitle(QCoreApplication::translate("frmImageClarityClass", "\346\270\205\346\231\260\345\272\246\345\217\202\346\225\260", nullptr));
        label_4->setText(QCoreApplication::translate("frmImageClarityClass", "\346\270\205\346\231\260\345\272\246\347\256\227\346\263\225\357\274\232", nullptr));
        comboClarity->setItemText(0, QCoreApplication::translate("frmImageClarityClass", "Tenengrad\346\242\257\345\272\246\347\256\227\346\263\225", nullptr));
        comboClarity->setItemText(1, QCoreApplication::translate("frmImageClarityClass", "Laplacian\346\242\257\345\272\246\347\256\227\346\263\225", nullptr));
        comboClarity->setItemText(2, QCoreApplication::translate("frmImageClarityClass", "SMD\347\201\260\345\272\246\345\267\256\345\210\206\347\273\235\345\257\271\345\200\274\344\271\213\345\222\214\347\256\227\346\263\225", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmImageClarityClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmImageClarityClass: public Ui_frmImageClarityClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMIMAGECLARITY_H
