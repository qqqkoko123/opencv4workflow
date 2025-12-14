/********************************************************************************
** Form generated from reading UI file 'YoloV13.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YOLOV13_H
#define UI_YOLOV13_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmImageSourceClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QGridLayout *imageLayout;
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
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *radioImage;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *radioFolder;
    QSpacerItem *horizontalSpacer_7;
    QRadioButton *radioCamera;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupImage;
    QLabel *label;
    QLineEdit *txtImagePath;
    QPushButton *btnSelectImage;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QComboBox *comboCamera;
    QPushButton *btnUpdata;
    QGroupBox *groupFolder;
    QLabel *label_2;
    QLineEdit *txtFolderPath;
    QPushButton *btnSelectPath;
    QWidget *tab_2;
    QGroupBox *groupC8;
    QCheckBox *checkUseCalib;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_9;
    QRadioButton *radioLinkParam;
    QSpacerItem *horizontalSpacer_11;
    QRadioButton *radioCalibFile;
    QSpacerItem *horizontalSpacer_12;
    QGroupBox *groupC;
    QLabel *label_5;
    QLineEdit *txtLinkCameraMatrix;
    QPushButton *btnLinkCameraMatrix;
    QPushButton *btnDelLinkCameraMatrix;
    QPushButton *btnDelLinkDistCoeffs;
    QPushButton *btnLinkDistCoeffs;
    QLabel *label_6;
    QLineEdit *txtLinkDistCoeffs;
    QGroupBox *groupC2;
    QLabel *label_7;
    QLineEdit *txtCalibPath;
    QPushButton *btnSelectCalibPath;
    QWidget *tab_3;
    QGroupBox *groupImage_2;
    QLabel *label_8;
    QLineEdit *txtImagePath_2;
    QPushButton *btnSelectImage_2;
    QGroupBox *groupImage_3;
    QLabel *label_9;
    QLineEdit *txtImagePath_3;
    QPushButton *btnSelectImage_3;

    void setupUi(QDialog *frmImageSourceClass)
    {
        if (frmImageSourceClass->objectName().isEmpty())
            frmImageSourceClass->setObjectName(QString::fromUtf8("frmImageSourceClass"));
        frmImageSourceClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmImageSourceClass->sizePolicy().hasHeightForWidth());
        frmImageSourceClass->setSizePolicy(sizePolicy);
        frmImageSourceClass->setMinimumSize(QSize(1160, 655));
        frmImageSourceClass->setMaximumSize(QSize(1160, 655));
        frmImageSourceClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmImageSourceClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

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

        label_3 = new QLabel(frmImageSourceClass);
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

        txtDescribe = new QLineEdit(frmImageSourceClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmImageSourceClass);
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

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frmImageSourceClass);
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
        horizontalLayoutWidget_2 = new QWidget(tab);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(3, 10, 437, 39));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        radioImage = new QRadioButton(horizontalLayoutWidget_2);
        radioImage->setObjectName(QString::fromUtf8("radioImage"));
        radioImage->setFont(font);
        radioImage->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        radioImage->setChecked(true);

        horizontalLayout_2->addWidget(radioImage);

        horizontalSpacer_6 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        radioFolder = new QRadioButton(horizontalLayoutWidget_2);
        radioFolder->setObjectName(QString::fromUtf8("radioFolder"));
        radioFolder->setFont(font);
        radioFolder->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));

        horizontalLayout_2->addWidget(radioFolder);

        horizontalSpacer_7 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        radioCamera = new QRadioButton(horizontalLayoutWidget_2);
        radioCamera->setObjectName(QString::fromUtf8("radioCamera"));
        radioCamera->setFont(font);
        radioCamera->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));

        horizontalLayout_2->addWidget(radioCamera);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        groupImage = new QGroupBox(tab);
        groupImage->setObjectName(QString::fromUtf8("groupImage"));
        groupImage->setGeometry(QRect(8, 68, 427, 111));
        groupImage->setFont(font);
        groupImage->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(0, 0, 255);"));
        label = new QLabel(groupImage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(16, 34, 85, 19));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtImagePath = new QLineEdit(groupImage);
        txtImagePath->setObjectName(QString::fromUtf8("txtImagePath"));
        txtImagePath->setGeometry(QRect(98, 30, 323, 27));
        txtImagePath->setFont(font);
        txtImagePath->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtImagePath->setReadOnly(true);
        btnSelectImage = new QPushButton(groupImage);
        btnSelectImage->setObjectName(QString::fromUtf8("btnSelectImage"));
        btnSelectImage->setGeometry(QRect(328, 68, 93, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        btnSelectImage->setFont(font1);
        btnSelectImage->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        groupCamera = new QGroupBox(tab);
        groupCamera->setObjectName(QString::fromUtf8("groupCamera"));
        groupCamera->setGeometry(QRect(8, 340, 427, 115));
        groupCamera->setFont(font);
        groupCamera->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(0, 0, 255);"));
        label_4 = new QLabel(groupCamera);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(16, 42, 79, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboCamera = new QComboBox(groupCamera);
        comboCamera->setObjectName(QString::fromUtf8("comboCamera"));
        comboCamera->setGeometry(QRect(98, 38, 323, 27));
        comboCamera->setFont(font);
        comboCamera->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        btnUpdata = new QPushButton(groupCamera);
        btnUpdata->setObjectName(QString::fromUtf8("btnUpdata"));
        btnUpdata->setGeometry(QRect(337, 77, 85, 30));
        sizePolicy.setHeightForWidth(btnUpdata->sizePolicy().hasHeightForWidth());
        btnUpdata->setSizePolicy(sizePolicy);
        btnUpdata->setMinimumSize(QSize(60, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        btnUpdata->setFont(font2);
        btnUpdata->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        groupFolder = new QGroupBox(tab);
        groupFolder->setObjectName(QString::fromUtf8("groupFolder"));
        groupFolder->setGeometry(QRect(8, 204, 427, 111));
        groupFolder->setFont(font);
        groupFolder->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(0, 0, 255);"));
        label_2 = new QLabel(groupFolder);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(4, 34, 97, 19));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtFolderPath = new QLineEdit(groupFolder);
        txtFolderPath->setObjectName(QString::fromUtf8("txtFolderPath"));
        txtFolderPath->setGeometry(QRect(98, 30, 323, 27));
        txtFolderPath->setFont(font);
        txtFolderPath->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtFolderPath->setReadOnly(true);
        btnSelectPath = new QPushButton(groupFolder);
        btnSelectPath->setObjectName(QString::fromUtf8("btnSelectPath"));
        btnSelectPath->setGeometry(QRect(328, 68, 93, 35));
        btnSelectPath->setFont(font1);
        btnSelectPath->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupC8 = new QGroupBox(tab_2);
        groupC8->setObjectName(QString::fromUtf8("groupC8"));
        groupC8->setGeometry(QRect(9, 18, 427, 403));
        groupC8->setFont(font);
        groupC8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        checkUseCalib = new QCheckBox(groupC8);
        checkUseCalib->setObjectName(QString::fromUtf8("checkUseCalib"));
        checkUseCalib->setGeometry(QRect(22, 36, 203, 27));
        sizePolicy.setHeightForWidth(checkUseCalib->sizePolicy().hasHeightForWidth());
        checkUseCalib->setSizePolicy(sizePolicy);
        checkUseCalib->setFont(font);
        checkUseCalib->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 17px;\n"
"    height: 17px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        checkUseCalib->setIconSize(QSize(22, 22));
        horizontalLayoutWidget_3 = new QWidget(groupC8);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(34, 72, 359, 39));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        radioLinkParam = new QRadioButton(horizontalLayoutWidget_3);
        radioLinkParam->setObjectName(QString::fromUtf8("radioLinkParam"));
        radioLinkParam->setFont(font);
        radioLinkParam->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(30, 30, 30);"));
        radioLinkParam->setChecked(true);

        horizontalLayout_3->addWidget(radioLinkParam);

        horizontalSpacer_11 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);

        radioCalibFile = new QRadioButton(horizontalLayoutWidget_3);
        radioCalibFile->setObjectName(QString::fromUtf8("radioCalibFile"));
        radioCalibFile->setFont(font);
        radioCalibFile->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(30, 30, 30);"));

        horizontalLayout_3->addWidget(radioCalibFile);

        horizontalSpacer_12 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_12);

        groupC = new QGroupBox(groupC8);
        groupC->setObjectName(QString::fromUtf8("groupC"));
        groupC->setGeometry(QRect(5, 132, 417, 127));
        groupC->setFont(font);
        groupC->setStyleSheet(QString::fromUtf8("background-color: #acbbac;\n"
"color: rgb(0, 0, 127);"));
        label_5 = new QLabel(groupC);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 43, 63, 19));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLinkCameraMatrix = new QLineEdit(groupC);
        txtLinkCameraMatrix->setObjectName(QString::fromUtf8("txtLinkCameraMatrix"));
        txtLinkCameraMatrix->setGeometry(QRect(94, 39, 241, 27));
        txtLinkCameraMatrix->setFont(font);
        txtLinkCameraMatrix->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkCameraMatrix->setAlignment(Qt::AlignCenter);
        txtLinkCameraMatrix->setReadOnly(true);
        btnLinkCameraMatrix = new QPushButton(groupC);
        btnLinkCameraMatrix->setObjectName(QString::fromUtf8("btnLinkCameraMatrix"));
        btnLinkCameraMatrix->setGeometry(QRect(344, 39, 27, 27));
        btnLinkCameraMatrix->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkCameraMatrix->setIcon(icon);
        btnLinkCameraMatrix->setIconSize(QSize(27, 27));
        btnDelLinkCameraMatrix = new QPushButton(groupC);
        btnDelLinkCameraMatrix->setObjectName(QString::fromUtf8("btnDelLinkCameraMatrix"));
        btnDelLinkCameraMatrix->setGeometry(QRect(378, 39, 27, 27));
        btnDelLinkCameraMatrix->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkCameraMatrix->setIcon(icon1);
        btnDelLinkCameraMatrix->setIconSize(QSize(27, 27));
        btnDelLinkDistCoeffs = new QPushButton(groupC);
        btnDelLinkDistCoeffs->setObjectName(QString::fromUtf8("btnDelLinkDistCoeffs"));
        btnDelLinkDistCoeffs->setGeometry(QRect(378, 88, 27, 27));
        btnDelLinkDistCoeffs->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkDistCoeffs->setIcon(icon1);
        btnDelLinkDistCoeffs->setIconSize(QSize(27, 27));
        btnLinkDistCoeffs = new QPushButton(groupC);
        btnLinkDistCoeffs->setObjectName(QString::fromUtf8("btnLinkDistCoeffs"));
        btnLinkDistCoeffs->setGeometry(QRect(344, 88, 27, 27));
        btnLinkDistCoeffs->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkDistCoeffs->setIcon(icon);
        btnLinkDistCoeffs->setIconSize(QSize(27, 27));
        label_6 = new QLabel(groupC);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(13, 92, 77, 19));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLinkDistCoeffs = new QLineEdit(groupC);
        txtLinkDistCoeffs->setObjectName(QString::fromUtf8("txtLinkDistCoeffs"));
        txtLinkDistCoeffs->setGeometry(QRect(94, 88, 241, 27));
        txtLinkDistCoeffs->setFont(font);
        txtLinkDistCoeffs->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkDistCoeffs->setAlignment(Qt::AlignCenter);
        txtLinkDistCoeffs->setReadOnly(true);
        groupC2 = new QGroupBox(groupC8);
        groupC2->setObjectName(QString::fromUtf8("groupC2"));
        groupC2->setGeometry(QRect(5, 286, 417, 113));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: #acbbac;\n"
"color: rgb(0, 0, 127);"));
        label_7 = new QLabel(groupC2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(13, 36, 115, 19));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtCalibPath = new QLineEdit(groupC2);
        txtCalibPath->setObjectName(QString::fromUtf8("txtCalibPath"));
        txtCalibPath->setGeometry(QRect(128, 32, 285, 27));
        txtCalibPath->setFont(font);
        txtCalibPath->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtCalibPath->setReadOnly(true);
        btnSelectCalibPath = new QPushButton(groupC2);
        btnSelectCalibPath->setObjectName(QString::fromUtf8("btnSelectCalibPath"));
        btnSelectCalibPath->setGeometry(QRect(320, 70, 93, 35));
        btnSelectCalibPath->setFont(font1);
        btnSelectCalibPath->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupImage_2 = new QGroupBox(tab_3);
        groupImage_2->setObjectName(QString::fromUtf8("groupImage_2"));
        groupImage_2->setGeometry(QRect(10, 20, 427, 111));
        groupImage_2->setFont(font);
        groupImage_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(0, 0, 255);"));
        label_8 = new QLabel(groupImage_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(16, 34, 85, 19));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtImagePath_2 = new QLineEdit(groupImage_2);
        txtImagePath_2->setObjectName(QString::fromUtf8("txtImagePath_2"));
        txtImagePath_2->setGeometry(QRect(98, 30, 323, 27));
        txtImagePath_2->setFont(font);
        txtImagePath_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtImagePath_2->setReadOnly(true);
        btnSelectImage_2 = new QPushButton(groupImage_2);
        btnSelectImage_2->setObjectName(QString::fromUtf8("btnSelectImage_2"));
        btnSelectImage_2->setGeometry(QRect(328, 68, 93, 35));
        btnSelectImage_2->setFont(font1);
        btnSelectImage_2->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        groupImage_3 = new QGroupBox(tab_3);
        groupImage_3->setObjectName(QString::fromUtf8("groupImage_3"));
        groupImage_3->setGeometry(QRect(10, 150, 427, 111));
        groupImage_3->setFont(font);
        groupImage_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(0, 0, 255);"));
        label_9 = new QLabel(groupImage_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(16, 34, 85, 19));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtImagePath_3 = new QLineEdit(groupImage_3);
        txtImagePath_3->setObjectName(QString::fromUtf8("txtImagePath_3"));
        txtImagePath_3->setGeometry(QRect(98, 30, 323, 27));
        txtImagePath_3->setFont(font);
        txtImagePath_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtImagePath_3->setReadOnly(true);
        btnSelectImage_3 = new QPushButton(groupImage_3);
        btnSelectImage_3->setObjectName(QString::fromUtf8("btnSelectImage_3"));
        btnSelectImage_3->setGeometry(QRect(328, 68, 93, 35));
        btnSelectImage_3->setFont(font1);
        btnSelectImage_3->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(frmImageSourceClass);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(frmImageSourceClass);
    } // setupUi

    void retranslateUi(QDialog *frmImageSourceClass)
    {
        frmImageSourceClass->setWindowTitle(QCoreApplication::translate("frmImageSourceClass", "\350\216\267\345\217\226\345\233\276\345\203\217", nullptr));
        label_3->setText(QCoreApplication::translate("frmImageSourceClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmImageSourceClass", "\346\211\247\350\241\214", nullptr));
        radioImage->setText(QCoreApplication::translate("frmImageSourceClass", "\346\234\254\345\234\260\345\233\276\345\203\217", nullptr));
        radioFolder->setText(QCoreApplication::translate("frmImageSourceClass", "\346\226\207\344\273\266\345\244\271", nullptr));
        radioCamera->setText(QCoreApplication::translate("frmImageSourceClass", "\347\233\270\346\234\272", nullptr));
        groupImage->setTitle(QCoreApplication::translate("frmImageSourceClass", "\345\215\225\345\274\240\345\233\276\345\203\217", nullptr));
        label->setText(QCoreApplication::translate("frmImageSourceClass", "\345\233\276\345\203\217\350\267\257\345\276\204\357\274\232", nullptr));
        btnSelectImage->setText(QCoreApplication::translate("frmImageSourceClass", "\345\233\276\345\203\217\351\200\211\346\213\251", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmImageSourceClass", "\344\273\216\347\233\270\346\234\272\350\216\267\345\217\226\345\233\276\345\203\217", nullptr));
        label_4->setText(QCoreApplication::translate("frmImageSourceClass", "\351\200\211\346\213\251\347\233\270\346\234\272\357\274\232", nullptr));
        btnUpdata->setText(QCoreApplication::translate("frmImageSourceClass", "\346\233\264\346\226\260\345\210\227\350\241\250", nullptr));
        groupFolder->setTitle(QCoreApplication::translate("frmImageSourceClass", "\344\273\216\346\226\207\344\273\266\345\244\271\350\216\267\345\217\226\345\233\276\345\203\217", nullptr));
        label_2->setText(QCoreApplication::translate("frmImageSourceClass", "\346\226\207\344\273\266\345\244\271\350\267\257\345\276\204\357\274\232", nullptr));
        txtFolderPath->setText(QString());
        btnSelectPath->setText(QCoreApplication::translate("frmImageSourceClass", "\350\267\257\345\276\204\351\200\211\346\213\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmImageSourceClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupC8->setTitle(QCoreApplication::translate("frmImageSourceClass", "\347\225\270\345\217\230\346\240\207\345\256\232\345\217\202\346\225\260", nullptr));
        checkUseCalib->setText(QCoreApplication::translate("frmImageSourceClass", "\344\275\277\347\224\250\347\225\270\345\217\230\346\240\207\345\256\232\346\240\241\346\255\243\345\233\276\345\203\217", nullptr));
        radioLinkParam->setText(QCoreApplication::translate("frmImageSourceClass", "\351\223\276\346\216\245\345\217\202\346\225\260\346\226\271\345\274\217", nullptr));
        radioCalibFile->setText(QCoreApplication::translate("frmImageSourceClass", "\350\257\273\345\217\226\346\240\207\345\256\232\346\226\207\344\273\266\346\226\271\345\274\217", nullptr));
        groupC->setTitle(QCoreApplication::translate("frmImageSourceClass", "\351\223\276\346\216\245\345\217\202\346\225\260\346\226\271\345\274\217", nullptr));
        label_5->setText(QCoreApplication::translate("frmImageSourceClass", "\345\206\205\345\217\202K\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkCameraMatrix->setToolTip(QCoreApplication::translate("frmImageSourceClass", "\345\206\205\345\217\202K", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkCameraMatrix->setToolTip(QCoreApplication::translate("frmImageSourceClass", "\351\223\276\346\216\245\345\206\205\345\217\202K", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkCameraMatrix->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkCameraMatrix->setToolTip(QCoreApplication::translate("frmImageSourceClass", "\345\210\240\351\231\244\345\206\205\345\217\202K\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkCameraMatrix->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkDistCoeffs->setToolTip(QCoreApplication::translate("frmImageSourceClass", "\345\210\240\351\231\244\347\225\270\345\217\230\347\263\273\346\225\260\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkDistCoeffs->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkDistCoeffs->setToolTip(QCoreApplication::translate("frmImageSourceClass", "\351\223\276\346\216\245\347\225\270\345\217\230\347\263\273\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkDistCoeffs->setText(QString());
        label_6->setText(QCoreApplication::translate("frmImageSourceClass", "\347\225\270\345\217\230\347\263\273\346\225\260\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkDistCoeffs->setToolTip(QCoreApplication::translate("frmImageSourceClass", "\347\225\270\345\217\230\347\263\273\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
        groupC2->setTitle(QCoreApplication::translate("frmImageSourceClass", "\350\257\273\345\217\226\346\240\207\345\256\232\346\226\207\344\273\266\346\226\271\345\274\217", nullptr));
        label_7->setText(QCoreApplication::translate("frmImageSourceClass", "\346\240\207\345\256\232\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        txtCalibPath->setText(QString());
        btnSelectCalibPath->setText(QCoreApplication::translate("frmImageSourceClass", "\346\226\207\344\273\266\351\200\211\346\213\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmImageSourceClass", "\346\240\207\345\256\232\350\256\276\347\275\256", nullptr));
        groupImage_2->setTitle(QCoreApplication::translate("frmImageSourceClass", "YOLO\346\250\241\345\236\213\345\234\260\345\235\200", nullptr));
        label_8->setText(QCoreApplication::translate("frmImageSourceClass", "\346\250\241\345\236\213\350\267\257\345\276\204\357\274\232", nullptr));
        btnSelectImage_2->setText(QCoreApplication::translate("frmImageSourceClass", "\350\267\257\345\276\204\351\200\211\346\213\251", nullptr));
        groupImage_3->setTitle(QCoreApplication::translate("frmImageSourceClass", "YOLO\346\240\207\347\255\276\346\226\207\344\273\266\345\234\260\345\235\200", nullptr));
        label_9->setText(QCoreApplication::translate("frmImageSourceClass", "\346\240\207\347\255\276\346\226\207\344\273\266\357\274\232", nullptr));
        btnSelectImage_3->setText(QCoreApplication::translate("frmImageSourceClass", "\350\267\257\345\276\204\351\200\211\346\213\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("frmImageSourceClass", "YOLO\345\261\236\346\200\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmImageSourceClass: public Ui_frmImageSourceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YOLOV13_H
