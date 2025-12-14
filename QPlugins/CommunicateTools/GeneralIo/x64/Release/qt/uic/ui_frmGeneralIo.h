/********************************************************************************
** Form generated from reading UI file 'frmGeneralIo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMGENERALIO_H
#define UI_FRMGENERALIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmGeneralIoClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupC;
    QComboBox *comboType;
    QLabel *label_5;
    QPushButton *btnUpdata;
    QGroupBox *groupC_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkInPutX0;
    QCheckBox *checkInPutX1;
    QCheckBox *checkInPutX2;
    QCheckBox *checkInPutX3;
    QCheckBox *checkInPutX4;
    QCheckBox *checkInPutX5;
    QCheckBox *checkInPutX6;
    QCheckBox *checkInPutX7;
    QGroupBox *groupC_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkOutPutY0;
    QCheckBox *checkOutPutY1;
    QCheckBox *checkOutPutY2;
    QCheckBox *checkOutPutY3;
    QCheckBox *checkOutPutY4;
    QCheckBox *checkOutPutY5;
    QCheckBox *checkOutPutY6;
    QCheckBox *checkOutPutY7;

    void setupUi(QDialog *frmGeneralIoClass)
    {
        if (frmGeneralIoClass->objectName().isEmpty())
            frmGeneralIoClass->setObjectName(QString::fromUtf8("frmGeneralIoClass"));
        frmGeneralIoClass->resize(720, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmGeneralIoClass->sizePolicy().hasHeightForWidth());
        frmGeneralIoClass->setSizePolicy(sizePolicy);
        frmGeneralIoClass->setMinimumSize(QSize(720, 500));
        frmGeneralIoClass->setMaximumSize(QSize(720, 500));
        frmGeneralIoClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmGeneralIoClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmGeneralIoClass);
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

        txtDescribe = new QLineEdit(frmGeneralIoClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmGeneralIoClass);
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

        tabWidget = new QTabWidget(frmGeneralIoClass);
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
        groupC->setGeometry(QRect(15, 24, 685, 73));
        groupC->setFont(font);
        groupC->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        comboType = new QComboBox(groupC);
        comboType->setObjectName(QString::fromUtf8("comboType"));
        comboType->setGeometry(QRect(142, 28, 180, 30));
        sizePolicy.setHeightForWidth(comboType->sizePolicy().hasHeightForWidth());
        comboType->setSizePolicy(sizePolicy);
        comboType->setMinimumSize(QSize(100, 30));
        comboType->setMaximumSize(QSize(16777215, 16777215));
        comboType->setFont(font);
        comboType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 6.5em;\n"
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
        label_5 = new QLabel(groupC);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(51, 28, 93, 30));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));
        btnUpdata = new QPushButton(groupC);
        btnUpdata->setObjectName(QString::fromUtf8("btnUpdata"));
        btnUpdata->setGeometry(QRect(334, 28, 85, 30));
        sizePolicy.setHeightForWidth(btnUpdata->sizePolicy().hasHeightForWidth());
        btnUpdata->setSizePolicy(sizePolicy);
        btnUpdata->setMinimumSize(QSize(60, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        btnUpdata->setFont(font1);
        btnUpdata->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        groupC_2 = new QGroupBox(tab);
        groupC_2->setObjectName(QString::fromUtf8("groupC_2"));
        groupC_2->setGeometry(QRect(15, 122, 685, 100));
        groupC_2->setFont(font);
        groupC_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        verticalLayoutWidget = new QWidget(groupC_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(6, 28, 673, 65));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(23);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        sizePolicy.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy);
        label_14->setMinimumSize(QSize(20, 20));
        label_14->setMaximumSize(QSize(20, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_14);

        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        sizePolicy.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy);
        label_13->setMinimumSize(QSize(20, 20));
        label_13->setMaximumSize(QSize(20, 20));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_13);

        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMinimumSize(QSize(20, 20));
        label_12->setMaximumSize(QSize(20, 20));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_12);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(20, 20));
        label_11->setMaximumSize(QSize(20, 20));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_11);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(20, 20));
        label_10->setMaximumSize(QSize(20, 20));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_10);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(20, 20));
        label_9->setMaximumSize(QSize(20, 20));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_9);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(20, 20));
        label_8->setMaximumSize(QSize(20, 20));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_8);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(20, 20));
        label_7->setMaximumSize(QSize(20, 20));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 85, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(23);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkInPutX0 = new QCheckBox(verticalLayoutWidget);
        checkInPutX0->setObjectName(QString::fromUtf8("checkInPutX0"));
        sizePolicy.setHeightForWidth(checkInPutX0->sizePolicy().hasHeightForWidth());
        checkInPutX0->setSizePolicy(sizePolicy);
        checkInPutX0->setMinimumSize(QSize(20, 20));
        checkInPutX0->setMaximumSize(QSize(20, 20));
        checkInPutX0->setFont(font);
        checkInPutX0->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkInPutX0->setIconSize(QSize(20, 20));
        checkInPutX0->setChecked(false);

        horizontalLayout_3->addWidget(checkInPutX0);

        checkInPutX1 = new QCheckBox(verticalLayoutWidget);
        checkInPutX1->setObjectName(QString::fromUtf8("checkInPutX1"));
        sizePolicy.setHeightForWidth(checkInPutX1->sizePolicy().hasHeightForWidth());
        checkInPutX1->setSizePolicy(sizePolicy);
        checkInPutX1->setMinimumSize(QSize(20, 20));
        checkInPutX1->setMaximumSize(QSize(20, 20));
        checkInPutX1->setFont(font);
        checkInPutX1->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkInPutX1->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(checkInPutX1);

        checkInPutX2 = new QCheckBox(verticalLayoutWidget);
        checkInPutX2->setObjectName(QString::fromUtf8("checkInPutX2"));
        sizePolicy.setHeightForWidth(checkInPutX2->sizePolicy().hasHeightForWidth());
        checkInPutX2->setSizePolicy(sizePolicy);
        checkInPutX2->setMinimumSize(QSize(20, 20));
        checkInPutX2->setMaximumSize(QSize(20, 20));
        checkInPutX2->setFont(font);
        checkInPutX2->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkInPutX2->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(checkInPutX2);

        checkInPutX3 = new QCheckBox(verticalLayoutWidget);
        checkInPutX3->setObjectName(QString::fromUtf8("checkInPutX3"));
        sizePolicy.setHeightForWidth(checkInPutX3->sizePolicy().hasHeightForWidth());
        checkInPutX3->setSizePolicy(sizePolicy);
        checkInPutX3->setMinimumSize(QSize(20, 20));
        checkInPutX3->setMaximumSize(QSize(20, 20));
        checkInPutX3->setFont(font);
        checkInPutX3->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkInPutX3->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(checkInPutX3);

        checkInPutX4 = new QCheckBox(verticalLayoutWidget);
        checkInPutX4->setObjectName(QString::fromUtf8("checkInPutX4"));
        sizePolicy.setHeightForWidth(checkInPutX4->sizePolicy().hasHeightForWidth());
        checkInPutX4->setSizePolicy(sizePolicy);
        checkInPutX4->setMinimumSize(QSize(20, 20));
        checkInPutX4->setMaximumSize(QSize(20, 20));
        checkInPutX4->setFont(font);
        checkInPutX4->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkInPutX4->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(checkInPutX4);

        checkInPutX5 = new QCheckBox(verticalLayoutWidget);
        checkInPutX5->setObjectName(QString::fromUtf8("checkInPutX5"));
        sizePolicy.setHeightForWidth(checkInPutX5->sizePolicy().hasHeightForWidth());
        checkInPutX5->setSizePolicy(sizePolicy);
        checkInPutX5->setMinimumSize(QSize(20, 20));
        checkInPutX5->setMaximumSize(QSize(20, 20));
        checkInPutX5->setFont(font);
        checkInPutX5->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkInPutX5->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(checkInPutX5);

        checkInPutX6 = new QCheckBox(verticalLayoutWidget);
        checkInPutX6->setObjectName(QString::fromUtf8("checkInPutX6"));
        sizePolicy.setHeightForWidth(checkInPutX6->sizePolicy().hasHeightForWidth());
        checkInPutX6->setSizePolicy(sizePolicy);
        checkInPutX6->setMinimumSize(QSize(20, 20));
        checkInPutX6->setMaximumSize(QSize(20, 20));
        checkInPutX6->setFont(font);
        checkInPutX6->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkInPutX6->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(checkInPutX6);

        checkInPutX7 = new QCheckBox(verticalLayoutWidget);
        checkInPutX7->setObjectName(QString::fromUtf8("checkInPutX7"));
        sizePolicy.setHeightForWidth(checkInPutX7->sizePolicy().hasHeightForWidth());
        checkInPutX7->setSizePolicy(sizePolicy);
        checkInPutX7->setMinimumSize(QSize(20, 20));
        checkInPutX7->setMaximumSize(QSize(20, 20));
        checkInPutX7->setFont(font);
        checkInPutX7->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkInPutX7->setIconSize(QSize(20, 20));

        horizontalLayout_3->addWidget(checkInPutX7);


        verticalLayout->addLayout(horizontalLayout_3);

        groupC_3 = new QGroupBox(tab);
        groupC_3->setObjectName(QString::fromUtf8("groupC_3"));
        groupC_3->setGeometry(QRect(15, 248, 685, 100));
        groupC_3->setFont(font);
        groupC_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        verticalLayoutWidget_2 = new QWidget(groupC_3);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(6, 28, 673, 65));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(23);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_15 = new QLabel(verticalLayoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setMinimumSize(QSize(20, 20));
        label_15->setMaximumSize(QSize(20, 20));
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 170, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_15);

        label_16 = new QLabel(verticalLayoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        label_16->setMinimumSize(QSize(20, 20));
        label_16->setMaximumSize(QSize(20, 20));
        label_16->setFont(font2);
        label_16->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 170, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_16);

        label_17 = new QLabel(verticalLayoutWidget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy);
        label_17->setMinimumSize(QSize(20, 20));
        label_17->setMaximumSize(QSize(20, 20));
        label_17->setFont(font2);
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 170, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_17);

        label_18 = new QLabel(verticalLayoutWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy);
        label_18->setMinimumSize(QSize(20, 20));
        label_18->setMaximumSize(QSize(20, 20));
        label_18->setFont(font2);
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 170, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_18);

        label_19 = new QLabel(verticalLayoutWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setMinimumSize(QSize(20, 20));
        label_19->setMaximumSize(QSize(20, 20));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 170, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_19->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_19);

        label_20 = new QLabel(verticalLayoutWidget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy);
        label_20->setMinimumSize(QSize(20, 20));
        label_20->setMaximumSize(QSize(20, 20));
        label_20->setFont(font2);
        label_20->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 170, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_20);

        label_21 = new QLabel(verticalLayoutWidget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy);
        label_21->setMinimumSize(QSize(20, 20));
        label_21->setMaximumSize(QSize(20, 20));
        label_21->setFont(font2);
        label_21->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 170, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_21);

        label_22 = new QLabel(verticalLayoutWidget_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);
        label_22->setMinimumSize(QSize(20, 20));
        label_22->setMaximumSize(QSize(20, 20));
        label_22->setFont(font2);
        label_22->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 170, 0, 35);\n"
"color: rgb(0, 0, 0);"));
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_22);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(23);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        checkOutPutY0 = new QCheckBox(verticalLayoutWidget_2);
        checkOutPutY0->setObjectName(QString::fromUtf8("checkOutPutY0"));
        sizePolicy.setHeightForWidth(checkOutPutY0->sizePolicy().hasHeightForWidth());
        checkOutPutY0->setSizePolicy(sizePolicy);
        checkOutPutY0->setMinimumSize(QSize(20, 20));
        checkOutPutY0->setMaximumSize(QSize(20, 20));
        checkOutPutY0->setFont(font);
        checkOutPutY0->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkOutPutY0->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(checkOutPutY0);

        checkOutPutY1 = new QCheckBox(verticalLayoutWidget_2);
        checkOutPutY1->setObjectName(QString::fromUtf8("checkOutPutY1"));
        sizePolicy.setHeightForWidth(checkOutPutY1->sizePolicy().hasHeightForWidth());
        checkOutPutY1->setSizePolicy(sizePolicy);
        checkOutPutY1->setMinimumSize(QSize(20, 20));
        checkOutPutY1->setMaximumSize(QSize(20, 20));
        checkOutPutY1->setFont(font);
        checkOutPutY1->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkOutPutY1->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(checkOutPutY1);

        checkOutPutY2 = new QCheckBox(verticalLayoutWidget_2);
        checkOutPutY2->setObjectName(QString::fromUtf8("checkOutPutY2"));
        sizePolicy.setHeightForWidth(checkOutPutY2->sizePolicy().hasHeightForWidth());
        checkOutPutY2->setSizePolicy(sizePolicy);
        checkOutPutY2->setMinimumSize(QSize(20, 20));
        checkOutPutY2->setMaximumSize(QSize(20, 20));
        checkOutPutY2->setFont(font);
        checkOutPutY2->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkOutPutY2->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(checkOutPutY2);

        checkOutPutY3 = new QCheckBox(verticalLayoutWidget_2);
        checkOutPutY3->setObjectName(QString::fromUtf8("checkOutPutY3"));
        sizePolicy.setHeightForWidth(checkOutPutY3->sizePolicy().hasHeightForWidth());
        checkOutPutY3->setSizePolicy(sizePolicy);
        checkOutPutY3->setMinimumSize(QSize(20, 20));
        checkOutPutY3->setMaximumSize(QSize(20, 20));
        checkOutPutY3->setFont(font);
        checkOutPutY3->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkOutPutY3->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(checkOutPutY3);

        checkOutPutY4 = new QCheckBox(verticalLayoutWidget_2);
        checkOutPutY4->setObjectName(QString::fromUtf8("checkOutPutY4"));
        sizePolicy.setHeightForWidth(checkOutPutY4->sizePolicy().hasHeightForWidth());
        checkOutPutY4->setSizePolicy(sizePolicy);
        checkOutPutY4->setMinimumSize(QSize(20, 20));
        checkOutPutY4->setMaximumSize(QSize(20, 20));
        checkOutPutY4->setFont(font);
        checkOutPutY4->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkOutPutY4->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(checkOutPutY4);

        checkOutPutY5 = new QCheckBox(verticalLayoutWidget_2);
        checkOutPutY5->setObjectName(QString::fromUtf8("checkOutPutY5"));
        sizePolicy.setHeightForWidth(checkOutPutY5->sizePolicy().hasHeightForWidth());
        checkOutPutY5->setSizePolicy(sizePolicy);
        checkOutPutY5->setMinimumSize(QSize(20, 20));
        checkOutPutY5->setMaximumSize(QSize(20, 20));
        checkOutPutY5->setFont(font);
        checkOutPutY5->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkOutPutY5->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(checkOutPutY5);

        checkOutPutY6 = new QCheckBox(verticalLayoutWidget_2);
        checkOutPutY6->setObjectName(QString::fromUtf8("checkOutPutY6"));
        sizePolicy.setHeightForWidth(checkOutPutY6->sizePolicy().hasHeightForWidth());
        checkOutPutY6->setSizePolicy(sizePolicy);
        checkOutPutY6->setMinimumSize(QSize(20, 20));
        checkOutPutY6->setMaximumSize(QSize(20, 20));
        checkOutPutY6->setFont(font);
        checkOutPutY6->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkOutPutY6->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(checkOutPutY6);

        checkOutPutY7 = new QCheckBox(verticalLayoutWidget_2);
        checkOutPutY7->setObjectName(QString::fromUtf8("checkOutPutY7"));
        sizePolicy.setHeightForWidth(checkOutPutY7->sizePolicy().hasHeightForWidth());
        checkOutPutY7->setSizePolicy(sizePolicy);
        checkOutPutY7->setMinimumSize(QSize(20, 20));
        checkOutPutY7->setMaximumSize(QSize(20, 20));
        checkOutPutY7->setFont(font);
        checkOutPutY7->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 20px;\n"
"    height: 20px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkOutPutY7->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(checkOutPutY7);


        verticalLayout_2->addLayout(horizontalLayout_5);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(frmGeneralIoClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmGeneralIoClass);
    } // setupUi

    void retranslateUi(QDialog *frmGeneralIoClass)
    {
        frmGeneralIoClass->setWindowTitle(QCoreApplication::translate("frmGeneralIoClass", "\351\200\232\347\224\250I/O", nullptr));
        label_3->setText(QCoreApplication::translate("frmGeneralIoClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmGeneralIoClass", "\346\211\247\350\241\214", nullptr));
        groupC->setTitle(QCoreApplication::translate("frmGeneralIoClass", "I/O\345\215\241\345\257\271\350\261\241", nullptr));
        label_5->setText(QCoreApplication::translate("frmGeneralIoClass", "I/O\345\215\241\345\236\213\345\217\267\357\274\232", nullptr));
        btnUpdata->setText(QCoreApplication::translate("frmGeneralIoClass", "\346\233\264\346\226\260\345\210\227\350\241\250", nullptr));
        groupC_2->setTitle(QCoreApplication::translate("frmGeneralIoClass", "I/O\350\276\223\345\205\245\347\202\271(\350\257\273\345\217\226)", nullptr));
        label_14->setText(QCoreApplication::translate("frmGeneralIoClass", "0", nullptr));
        label_13->setText(QCoreApplication::translate("frmGeneralIoClass", "1", nullptr));
        label_12->setText(QCoreApplication::translate("frmGeneralIoClass", "2", nullptr));
        label_11->setText(QCoreApplication::translate("frmGeneralIoClass", "3", nullptr));
        label_10->setText(QCoreApplication::translate("frmGeneralIoClass", "4", nullptr));
        label_9->setText(QCoreApplication::translate("frmGeneralIoClass", "5", nullptr));
        label_8->setText(QCoreApplication::translate("frmGeneralIoClass", "6", nullptr));
        label_7->setText(QCoreApplication::translate("frmGeneralIoClass", "7", nullptr));
        checkInPutX0->setText(QString());
        checkInPutX1->setText(QString());
        checkInPutX2->setText(QString());
        checkInPutX3->setText(QString());
        checkInPutX4->setText(QString());
        checkInPutX5->setText(QString());
        checkInPutX6->setText(QString());
        checkInPutX7->setText(QString());
        groupC_3->setTitle(QCoreApplication::translate("frmGeneralIoClass", "I/O\350\276\223\345\207\272\347\202\271(\345\206\231\345\205\245)", nullptr));
        label_15->setText(QCoreApplication::translate("frmGeneralIoClass", "0", nullptr));
        label_16->setText(QCoreApplication::translate("frmGeneralIoClass", "1", nullptr));
        label_17->setText(QCoreApplication::translate("frmGeneralIoClass", "2", nullptr));
        label_18->setText(QCoreApplication::translate("frmGeneralIoClass", "3", nullptr));
        label_19->setText(QCoreApplication::translate("frmGeneralIoClass", "4", nullptr));
        label_20->setText(QCoreApplication::translate("frmGeneralIoClass", "5", nullptr));
        label_21->setText(QCoreApplication::translate("frmGeneralIoClass", "6", nullptr));
        label_22->setText(QCoreApplication::translate("frmGeneralIoClass", "7", nullptr));
        checkOutPutY0->setText(QString());
        checkOutPutY1->setText(QString());
        checkOutPutY2->setText(QString());
        checkOutPutY3->setText(QString());
        checkOutPutY4->setText(QString());
        checkOutPutY5->setText(QString());
        checkOutPutY6->setText(QString());
        checkOutPutY7->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmGeneralIoClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmGeneralIoClass: public Ui_frmGeneralIoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMGENERALIO_H
