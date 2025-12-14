/********************************************************************************
** Form generated from reading UI file 'frmClassifier.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCLASSIFIER_H
#define UI_FRMCLASSIFIER_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmClassifierClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *imageLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *lbl_inputimage;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QGroupBox *groupFolder;
    QLabel *label_2;
    QLineEdit *txtLabels;
    QPushButton *btnLabels;
    QLabel *label_6;
    QPushButton *btnList;
    QLineEdit *txtList;
    QLabel *label_7;
    QLineEdit *txtSaveModel;
    QPushButton *btnSaveModel;
    QPushButton *btnTrainModel;
    QLabel *label_8;
    QGroupBox *groupCamera_2;
    QLabel *label_5;
    QPushButton *btnLoadModel;
    QLineEdit *txtLoadModel;
    QWidget *tab_2;
    QGroupBox *groupCamera_3;
    QLabel *label_9;
    QComboBox *comboType;
    QComboBox *comboTypeBuf;
    QLineEdit *txtTypeName;
    QPushButton *btnWrite;

    void setupUi(QDialog *frmClassifierClass)
    {
        if (frmClassifierClass->objectName().isEmpty())
            frmClassifierClass->setObjectName(QString::fromUtf8("frmClassifierClass"));
        frmClassifierClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmClassifierClass->sizePolicy().hasHeightForWidth());
        frmClassifierClass->setSizePolicy(sizePolicy);
        frmClassifierClass->setMinimumSize(QSize(1160, 655));
        frmClassifierClass->setMaximumSize(QSize(1160, 655));
        frmClassifierClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmClassifierClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

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

        label_3 = new QLabel(frmClassifierClass);
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

        txtDescribe = new QLineEdit(frmClassifierClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmClassifierClass);
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

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        tabWidget = new QTabWidget(frmClassifierClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
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
        groupCamera->setGeometry(QRect(9, 18, 427, 73));
        groupCamera->setFont(font);
        groupCamera->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        lbl_inputimage = new QLabel(groupCamera);
        lbl_inputimage->setObjectName(QString::fromUtf8("lbl_inputimage"));
        lbl_inputimage->setGeometry(QRect(13, 42, 79, 19));
        lbl_inputimage->setFont(font);
        lbl_inputimage->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLinkImage = new QLineEdit(groupCamera);
        txtLinkImage->setObjectName(QString::fromUtf8("txtLinkImage"));
        txtLinkImage->setGeometry(QRect(96, 39, 255, 27));
        txtLinkImage->setFont(font);
        txtLinkImage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkImage->setAlignment(Qt::AlignCenter);
        txtLinkImage->setReadOnly(true);
        btnLinkImage = new QPushButton(groupCamera);
        btnLinkImage->setObjectName(QString::fromUtf8("btnLinkImage"));
        btnLinkImage->setGeometry(QRect(360, 39, 27, 27));
        btnLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkImage->setIcon(icon);
        btnLinkImage->setIconSize(QSize(27, 27));
        btnDelLinkImage = new QPushButton(groupCamera);
        btnDelLinkImage->setObjectName(QString::fromUtf8("btnDelLinkImage"));
        btnDelLinkImage->setGeometry(QRect(394, 39, 27, 27));
        btnDelLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkImage->setIcon(icon1);
        btnDelLinkImage->setIconSize(QSize(27, 27));
        groupFolder = new QGroupBox(tab);
        groupFolder->setObjectName(QString::fromUtf8("groupFolder"));
        groupFolder->setGeometry(QRect(9, 108, 427, 101));
        groupFolder->setFont(font);
        groupFolder->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_2 = new QLabel(groupFolder);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(13, 34, 136, 22));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLabels = new QLineEdit(groupFolder);
        txtLabels->setObjectName(QString::fromUtf8("txtLabels"));
        txtLabels->setGeometry(QRect(13, 58, 333, 27));
        txtLabels->setFont(font);
        txtLabels->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtLabels->setReadOnly(true);
        btnLabels = new QPushButton(groupFolder);
        btnLabels->setObjectName(QString::fromUtf8("btnLabels"));
        btnLabels->setGeometry(QRect(352, 56, 70, 32));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(9);
        btnLabels->setFont(font2);
        btnLabels->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        label_6 = new QLabel(groupFolder);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setEnabled(false);
        label_6->setGeometry(QRect(13, 100, 136, 19));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        btnList = new QPushButton(groupFolder);
        btnList->setObjectName(QString::fromUtf8("btnList"));
        btnList->setEnabled(false);
        btnList->setGeometry(QRect(352, 122, 70, 32));
        btnList->setFont(font2);
        btnList->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        txtList = new QLineEdit(groupFolder);
        txtList->setObjectName(QString::fromUtf8("txtList"));
        txtList->setEnabled(false);
        txtList->setGeometry(QRect(13, 124, 333, 27));
        txtList->setFont(font);
        txtList->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtList->setReadOnly(true);
        label_7 = new QLabel(groupFolder);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(false);
        label_7->setGeometry(QRect(13, 166, 136, 19));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtSaveModel = new QLineEdit(groupFolder);
        txtSaveModel->setObjectName(QString::fromUtf8("txtSaveModel"));
        txtSaveModel->setEnabled(false);
        txtSaveModel->setGeometry(QRect(13, 190, 333, 27));
        txtSaveModel->setFont(font);
        txtSaveModel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtSaveModel->setReadOnly(true);
        btnSaveModel = new QPushButton(groupFolder);
        btnSaveModel->setObjectName(QString::fromUtf8("btnSaveModel"));
        btnSaveModel->setEnabled(false);
        btnSaveModel->setGeometry(QRect(352, 188, 70, 32));
        btnSaveModel->setFont(font2);
        btnSaveModel->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        btnTrainModel = new QPushButton(groupFolder);
        btnTrainModel->setObjectName(QString::fromUtf8("btnTrainModel"));
        btnTrainModel->setEnabled(false);
        btnTrainModel->setGeometry(QRect(329, 237, 93, 35));
        btnTrainModel->setMinimumSize(QSize(82, 35));
        btnTrainModel->setFont(font);
        btnTrainModel->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 135, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 155, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 175, 127);}"));
        label_8 = new QLabel(groupFolder);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setEnabled(false);
        label_8->setGeometry(QRect(200, 244, 123, 22));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(12);
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        groupCamera_2 = new QGroupBox(tab);
        groupCamera_2->setObjectName(QString::fromUtf8("groupCamera_2"));
        groupCamera_2->setGeometry(QRect(10, 220, 427, 97));
        groupCamera_2->setFont(font);
        groupCamera_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_5 = new QLabel(groupCamera_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 36, 136, 22));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        btnLoadModel = new QPushButton(groupCamera_2);
        btnLoadModel->setObjectName(QString::fromUtf8("btnLoadModel"));
        btnLoadModel->setGeometry(QRect(352, 60, 70, 32));
        btnLoadModel->setFont(font2);
        btnLoadModel->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        txtLoadModel = new QLineEdit(groupCamera_2);
        txtLoadModel->setObjectName(QString::fromUtf8("txtLoadModel"));
        txtLoadModel->setGeometry(QRect(13, 62, 333, 27));
        txtLoadModel->setFont(font);
        txtLoadModel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtLoadModel->setReadOnly(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setEnabled(false);
        groupCamera_3 = new QGroupBox(tab_2);
        groupCamera_3->setObjectName(QString::fromUtf8("groupCamera_3"));
        groupCamera_3->setGeometry(QRect(9, 18, 427, 175));
        groupCamera_3->setFont(font);
        groupCamera_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_9 = new QLabel(groupCamera_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(13, 42, 115, 19));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboType = new QComboBox(groupCamera_3);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName(QString::fromUtf8("comboType"));
        comboType->setGeometry(QRect(132, 38, 105, 27));
        comboType->setMinimumSize(QSize(51, 27));
        comboType->setFont(font);
        comboType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 4.1em;\n"
"    color: rgb(239, 235, 231);\n"
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
"}\n"
"QScrollBar:vertical{\n"
"		background:#FFFFF2; \n"
"		padding-top:20px;\n"
"		padding-bottom:20px;\n"
"		padding-left:2px;\n"
"		padding-right:2px;\n"
"		border-left:1px solid #d7d7d7;}\n"
"QScrollBar::handle:vertical{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:vertical:hover{\n"
"		background:#d0d0d0;}\n"
""
                        "QScrollBar::add-line:vertical{\n"
"		background:url(:/resource/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/resource/up.png) center no-repeat;}"));
        comboTypeBuf = new QComboBox(groupCamera_3);
        comboTypeBuf->setObjectName(QString::fromUtf8("comboTypeBuf"));
        comboTypeBuf->setGeometry(QRect(13, 96, 150, 27));
        comboTypeBuf->setMinimumSize(QSize(51, 27));
        comboTypeBuf->setFont(font);
        comboTypeBuf->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 4.1em;\n"
"    color: rgb(239, 235, 231);\n"
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
"}\n"
"QScrollBar:vertical{\n"
"		background:#FFFFF2; \n"
"		padding-top:20px;\n"
"		padding-bottom:20px;\n"
"		padding-left:2px;\n"
"		padding-right:2px;\n"
"		border-left:1px solid #d7d7d7;}\n"
"QScrollBar::handle:vertical{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:vertical:hover{\n"
"		background:#d0d0d0;}\n"
""
                        "QScrollBar::add-line:vertical{\n"
"		background:url(:/resource/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/resource/up.png) center no-repeat;}"));
        txtTypeName = new QLineEdit(groupCamera_3);
        txtTypeName->setObjectName(QString::fromUtf8("txtTypeName"));
        txtTypeName->setGeometry(QRect(172, 96, 249, 27));
        txtTypeName->setFont(font);
        txtTypeName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtTypeName->setReadOnly(false);
        btnWrite = new QPushButton(groupCamera_3);
        btnWrite->setObjectName(QString::fromUtf8("btnWrite"));
        btnWrite->setGeometry(QRect(352, 138, 70, 32));
        btnWrite->setFont(font);
        btnWrite->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(frmClassifierClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmClassifierClass);
    } // setupUi

    void retranslateUi(QDialog *frmClassifierClass)
    {
        frmClassifierClass->setWindowTitle(QCoreApplication::translate("frmClassifierClass", "\345\210\206\347\261\273\345\231\250", nullptr));
        label_3->setText(QCoreApplication::translate("frmClassifierClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmClassifierClass", "\346\211\247\350\241\214", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmClassifierClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        lbl_inputimage->setText(QCoreApplication::translate("frmClassifierClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmClassifierClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmClassifierClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupFolder->setTitle(QCoreApplication::translate("frmClassifierClass", "\350\256\255\347\273\203\346\250\241\345\236\213", nullptr));
        label_2->setText(QCoreApplication::translate("frmClassifierClass", "\345\233\276\345\203\217\346\240\207\347\255\276\346\226\207\344\273\266\357\274\232", nullptr));
        txtLabels->setText(QString());
        btnLabels->setText(QCoreApplication::translate("frmClassifierClass", "\345\233\276\345\203\217\346\240\207\347\255\276", nullptr));
        label_6->setText(QCoreApplication::translate("frmClassifierClass", "\342\221\241\345\233\276\345\203\217\345\210\227\350\241\250\346\226\207\344\273\266\357\274\232", nullptr));
        btnList->setText(QCoreApplication::translate("frmClassifierClass", "\345\233\276\345\203\217\345\210\227\350\241\250", nullptr));
        txtList->setText(QString());
        label_7->setText(QCoreApplication::translate("frmClassifierClass", "\342\221\242\344\277\235\345\255\230\346\250\241\345\236\213\346\226\207\344\273\266\357\274\232", nullptr));
        txtSaveModel->setText(QString());
        btnSaveModel->setText(QCoreApplication::translate("frmClassifierClass", "\344\277\235\345\255\230\346\250\241\345\236\213", nullptr));
        btnTrainModel->setText(QCoreApplication::translate("frmClassifierClass", "\350\256\255\347\273\203\346\250\241\345\236\213", nullptr));
        label_8->setText(QCoreApplication::translate("frmClassifierClass", "\342\221\240\342\206\222\342\221\241\342\206\222\342\221\242\342\206\222", nullptr));
        groupCamera_2->setTitle(QCoreApplication::translate("frmClassifierClass", "\351\242\204\346\265\213\346\250\241\345\236\213", nullptr));
        label_5->setText(QCoreApplication::translate("frmClassifierClass", "\351\242\204\346\265\213\346\250\241\345\236\213\346\226\207\344\273\266\357\274\232", nullptr));
        btnLoadModel->setText(QCoreApplication::translate("frmClassifierClass", "\346\250\241\345\236\213\346\226\207\344\273\266", nullptr));
        txtLoadModel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmClassifierClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupCamera_3->setTitle(QCoreApplication::translate("frmClassifierClass", "\345\233\276\345\203\217\347\261\273\345\210\253\345\217\202\346\225\260", nullptr));
        label_9->setText(QCoreApplication::translate("frmClassifierClass", "\345\233\276\345\203\217\347\261\273\345\210\253\346\225\260\351\207\217\357\274\232", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("frmClassifierClass", "2\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("frmClassifierClass", "3\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(2, QCoreApplication::translate("frmClassifierClass", "4\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(3, QCoreApplication::translate("frmClassifierClass", "5\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(4, QCoreApplication::translate("frmClassifierClass", "6\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(5, QCoreApplication::translate("frmClassifierClass", "7\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(6, QCoreApplication::translate("frmClassifierClass", "8\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(7, QCoreApplication::translate("frmClassifierClass", "9\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(8, QCoreApplication::translate("frmClassifierClass", "10\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(9, QCoreApplication::translate("frmClassifierClass", "11\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(10, QCoreApplication::translate("frmClassifierClass", "12\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(11, QCoreApplication::translate("frmClassifierClass", "13\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(12, QCoreApplication::translate("frmClassifierClass", "14\347\247\215\347\261\273\345\210\253", nullptr));
        comboType->setItemText(13, QCoreApplication::translate("frmClassifierClass", "15\347\247\215\347\261\273\345\210\253", nullptr));

        txtTypeName->setText(QString());
        btnWrite->setText(QCoreApplication::translate("frmClassifierClass", "\345\206\231\345\205\245", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmClassifierClass", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmClassifierClass: public Ui_frmClassifierClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCLASSIFIER_H
