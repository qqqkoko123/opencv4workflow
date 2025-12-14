/********************************************************************************
** Form generated from reading UI file 'frmERTCalibration.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMERTCALIBRATION_H
#define UI_FRMERTCALIBRATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmERTCalibrationClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *imageLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QGroupBox *groupC2;
    QVBoxLayout *verticalLayout;
    QLabel *lblImg1;
    QGroupBox *groupC3;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblImg2;
    QWidget *tab_2;
    QGroupBox *groupC5;
    QCheckBox *checkUseROI;
    QComboBox *comboROIShape;
    QPushButton *btnAddROI;
    QPushButton *btnDeleteROI;
    QSpinBox *spinCrossL;
    QLabel *label_20;
    QLabel *label_18;
    QSpinBox *spinRoiW;
    QPushButton *btnGetCenter;
    QLabel *label_8;
    QGroupBox *groupC4;
    QComboBox *comboGrayDirection;
    QLabel *label_10;
    QLabel *label_14;
    QSpinBox *spinThreshold;
    QLabel *label_15;
    QComboBox *comboScanDirection;
    QLabel *label_16;
    QSpinBox *spinSegment;
    QLabel *label_19;
    QSpinBox *spinCullDistance;
    QGroupBox *groupC6;
    QTextEdit *txtFindCirMsg;
    QWidget *tab_3;
    QGroupBox *groupC7;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioNinePoints;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *radioRotateCenter;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupC8;
    QDoubleSpinBox *spinImageY2;
    QDoubleSpinBox *spinImageX8;
    QDoubleSpinBox *spinMachineX2;
    QDoubleSpinBox *spinImageY8;
    QTableWidget *tableWidget;
    QDoubleSpinBox *spinMachineX3;
    QDoubleSpinBox *spinMachineY8;
    QDoubleSpinBox *spinMachineX9;
    QDoubleSpinBox *spinImageX5;
    QDoubleSpinBox *spinMachineY5;
    QDoubleSpinBox *spinImageX9;
    QDoubleSpinBox *spinMachineY4;
    QDoubleSpinBox *spinImageY6;
    QDoubleSpinBox *spinImageX7;
    QDoubleSpinBox *spinMachineX1;
    QDoubleSpinBox *spinMachineX7;
    QDoubleSpinBox *spinImageX6;
    QDoubleSpinBox *spinMachineX8;
    QDoubleSpinBox *spinImageX4;
    QDoubleSpinBox *spinMachineX6;
    QDoubleSpinBox *spinMachineY3;
    QDoubleSpinBox *spinImageX1;
    QDoubleSpinBox *spinImageX3;
    QDoubleSpinBox *spinImageY4;
    QDoubleSpinBox *spinMachineY2;
    QDoubleSpinBox *spinImageY7;
    QDoubleSpinBox *spinMachineY9;
    QDoubleSpinBox *spinMachineY1;
    QDoubleSpinBox *spinImageY1;
    QDoubleSpinBox *spinImageY5;
    QDoubleSpinBox *spinMachineX4;
    QDoubleSpinBox *spinImageY3;
    QDoubleSpinBox *spinImageX2;
    QDoubleSpinBox *spinMachineY6;
    QDoubleSpinBox *spinMachineX5;
    QDoubleSpinBox *spinMachineY7;
    QDoubleSpinBox *spinImageY9;
    QWidget *page_2;
    QGroupBox *groupC9;
    QDoubleSpinBox *spinStandardAngle;
    QLabel *label_17;
    QCheckBox *checkUseRotateC;
    QLabel *label_21;
    QComboBox *comboCalibMethod;
    QStackedWidget *stackedWidgetC;
    QWidget *page_3;
    QDoubleSpinBox *spinImageRY2;
    QDoubleSpinBox *spinImageRX2;
    QDoubleSpinBox *spinImageRX1;
    QDoubleSpinBox *spinImageRY3;
    QDoubleSpinBox *spinImageRX3;
    QTableWidget *tableWidgetR;
    QDoubleSpinBox *spinImageRY1;
    QWidget *page_4;
    QDoubleSpinBox *spinImgRX2;
    QDoubleSpinBox *spinImgRX1;
    QDoubleSpinBox *spinImgRY2;
    QDoubleSpinBox *spinImgRY1;
    QTableWidget *tableWidgetR2;
    QLabel *label_22;
    QLabel *label_23;
    QDoubleSpinBox *spinRotateAngle;
    QWidget *tab_4;
    QGroupBox *groupC10;
    QTextEdit *txtMsg;

    void setupUi(QDialog *frmERTCalibrationClass)
    {
        if (frmERTCalibrationClass->objectName().isEmpty())
            frmERTCalibrationClass->setObjectName(QString::fromUtf8("frmERTCalibrationClass"));
        frmERTCalibrationClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmERTCalibrationClass->sizePolicy().hasHeightForWidth());
        frmERTCalibrationClass->setSizePolicy(sizePolicy);
        frmERTCalibrationClass->setMinimumSize(QSize(1160, 655));
        frmERTCalibrationClass->setMaximumSize(QSize(1160, 655));
        frmERTCalibrationClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmERTCalibrationClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

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

        label_3 = new QLabel(frmERTCalibrationClass);
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

        txtDescribe = new QLineEdit(frmERTCalibrationClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(377, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmERTCalibrationClass);
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

        tabWidget = new QTabWidget(frmERTCalibrationClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(470, 550));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupCamera = new QGroupBox(tab);
        groupCamera->setObjectName(QString::fromUtf8("groupCamera"));
        groupCamera->setGeometry(QRect(8, 18, 449, 73));
        groupCamera->setFont(font);
        groupCamera->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_4 = new QLabel(groupCamera);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 42, 79, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLinkImage = new QLineEdit(groupCamera);
        txtLinkImage->setObjectName(QString::fromUtf8("txtLinkImage"));
        txtLinkImage->setGeometry(QRect(100, 39, 269, 27));
        txtLinkImage->setFont(font);
        txtLinkImage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkImage->setAlignment(Qt::AlignCenter);
        txtLinkImage->setReadOnly(true);
        btnLinkImage = new QPushButton(groupCamera);
        btnLinkImage->setObjectName(QString::fromUtf8("btnLinkImage"));
        btnLinkImage->setGeometry(QRect(376, 38, 27, 27));
        btnLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkImage->setIcon(icon);
        btnLinkImage->setIconSize(QSize(27, 27));
        btnDelLinkImage = new QPushButton(groupCamera);
        btnDelLinkImage->setObjectName(QString::fromUtf8("btnDelLinkImage"));
        btnDelLinkImage->setGeometry(QRect(410, 38, 27, 27));
        btnDelLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkImage->setIcon(icon1);
        btnDelLinkImage->setIconSize(QSize(27, 27));
        groupC2 = new QGroupBox(tab);
        groupC2->setObjectName(QString::fromUtf8("groupC2"));
        groupC2->setGeometry(QRect(8, 108, 449, 245));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        verticalLayout = new QVBoxLayout(groupC2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 5, 1, 2);
        lblImg1 = new QLabel(groupC2);
        lblImg1->setObjectName(QString::fromUtf8("lblImg1"));
        lblImg1->setPixmap(QPixmap(QString::fromUtf8(":/resource/n9.png")));
        lblImg1->setScaledContents(true);

        verticalLayout->addWidget(lblImg1);

        groupC3 = new QGroupBox(tab);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(8, 368, 449, 151));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        verticalLayout_2 = new QVBoxLayout(groupC3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 5, 1, 2);
        lblImg2 = new QLabel(groupC3);
        lblImg2->setObjectName(QString::fromUtf8("lblImg2"));
        lblImg2->setPixmap(QPixmap(QString::fromUtf8(":/resource/n_rotate.png")));
        lblImg2->setScaledContents(true);

        verticalLayout_2->addWidget(lblImg2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupC5 = new QGroupBox(tab_2);
        groupC5->setObjectName(QString::fromUtf8("groupC5"));
        groupC5->setGeometry(QRect(8, 206, 449, 179));
        groupC5->setFont(font);
        groupC5->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        checkUseROI = new QCheckBox(groupC5);
        checkUseROI->setObjectName(QString::fromUtf8("checkUseROI"));
        checkUseROI->setEnabled(false);
        checkUseROI->setGeometry(QRect(13, 36, 93, 27));
        sizePolicy.setHeightForWidth(checkUseROI->sizePolicy().hasHeightForWidth());
        checkUseROI->setSizePolicy(sizePolicy);
        checkUseROI->setFont(font);
        checkUseROI->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkUseROI->setIconSize(QSize(22, 22));
        checkUseROI->setChecked(true);
        comboROIShape = new QComboBox(groupC5);
        comboROIShape->addItem(QString());
        comboROIShape->setObjectName(QString::fromUtf8("comboROIShape"));
        comboROIShape->setGeometry(QRect(130, 35, 85, 30));
        comboROIShape->setFont(font);
        comboROIShape->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 5em;\n"
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
        btnAddROI = new QPushButton(groupC5);
        btnAddROI->setObjectName(QString::fromUtf8("btnAddROI"));
        btnAddROI->setGeometry(QRect(290, 34, 66, 32));
        sizePolicy.setHeightForWidth(btnAddROI->sizePolicy().hasHeightForWidth());
        btnAddROI->setSizePolicy(sizePolicy);
        btnAddROI->setMinimumSize(QSize(60, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        btnAddROI->setFont(font1);
        btnAddROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        btnDeleteROI = new QPushButton(groupC5);
        btnDeleteROI->setObjectName(QString::fromUtf8("btnDeleteROI"));
        btnDeleteROI->setGeometry(QRect(370, 34, 66, 32));
        btnDeleteROI->setMinimumSize(QSize(60, 30));
        btnDeleteROI->setFont(font1);
        btnDeleteROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));
        spinCrossL = new QSpinBox(groupC5);
        spinCrossL->setObjectName(QString::fromUtf8("spinCrossL"));
        spinCrossL->setGeometry(QRect(355, 88, 80, 27));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        spinCrossL->setFont(font2);
        spinCrossL->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinCrossL->setAlignment(Qt::AlignCenter);
        spinCrossL->setMinimum(1);
        spinCrossL->setMaximum(100);
        spinCrossL->setValue(10);
        label_20 = new QLabel(groupC5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(13, 92, 79, 19));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_18 = new QLabel(groupC5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(254, 92, 95, 19));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinRoiW = new QSpinBox(groupC5);
        spinRoiW->setObjectName(QString::fromUtf8("spinRoiW"));
        spinRoiW->setGeometry(QRect(93, 88, 80, 27));
        spinRoiW->setFont(font2);
        spinRoiW->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinRoiW->setAlignment(Qt::AlignCenter);
        spinRoiW->setMinimum(1);
        spinRoiW->setMaximum(100);
        spinRoiW->setValue(2);
        btnGetCenter = new QPushButton(groupC5);
        btnGetCenter->setObjectName(QString::fromUtf8("btnGetCenter"));
        btnGetCenter->setGeometry(QRect(353, 138, 83, 32));
        sizePolicy.setHeightForWidth(btnGetCenter->sizePolicy().hasHeightForWidth());
        btnGetCenter->setSizePolicy(sizePolicy);
        btnGetCenter->setMinimumSize(QSize(60, 30));
        btnGetCenter->setFont(font1);
        btnGetCenter->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 87, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 87);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 87);}"));
        label_8 = new QLabel(groupC5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(304, 136, 43, 35));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(12);
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/resource/a_right.png")));
        label_8->setScaledContents(true);
        groupC4 = new QGroupBox(tab_2);
        groupC4->setObjectName(QString::fromUtf8("groupC4"));
        groupC4->setGeometry(QRect(8, 18, 449, 171));
        groupC4->setFont(font);
        groupC4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        comboGrayDirection = new QComboBox(groupC4);
        comboGrayDirection->addItem(QString());
        comboGrayDirection->addItem(QString());
        comboGrayDirection->setObjectName(QString::fromUtf8("comboGrayDirection"));
        comboGrayDirection->setGeometry(QRect(350, 32, 85, 30));
        comboGrayDirection->setFont(font);
        comboGrayDirection->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_10 = new QLabel(groupC4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(262, 37, 81, 19));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_14 = new QLabel(groupC4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(13, 87, 81, 19));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        label_14->setFont(font4);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinThreshold = new QSpinBox(groupC4);
        spinThreshold->setObjectName(QString::fromUtf8("spinThreshold"));
        spinThreshold->setGeometry(QRect(100, 84, 85, 27));
        spinThreshold->setFont(font2);
        spinThreshold->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinThreshold->setAlignment(Qt::AlignCenter);
        spinThreshold->setMinimum(0);
        spinThreshold->setMaximum(255);
        spinThreshold->setValue(20);
        label_15 = new QLabel(groupC4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(12, 37, 81, 19));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboScanDirection = new QComboBox(groupC4);
        comboScanDirection->addItem(QString());
        comboScanDirection->addItem(QString());
        comboScanDirection->setObjectName(QString::fromUtf8("comboScanDirection"));
        comboScanDirection->setGeometry(QRect(100, 32, 85, 30));
        comboScanDirection->setFont(font);
        comboScanDirection->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_16 = new QLabel(groupC4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(263, 87, 81, 19));
        label_16->setFont(font4);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinSegment = new QSpinBox(groupC4);
        spinSegment->setObjectName(QString::fromUtf8("spinSegment"));
        spinSegment->setGeometry(QRect(350, 84, 85, 27));
        spinSegment->setFont(font2);
        spinSegment->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinSegment->setAlignment(Qt::AlignCenter);
        spinSegment->setMinimum(30);
        spinSegment->setMaximum(360);
        spinSegment->setValue(30);
        label_19 = new QLabel(groupC4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(13, 137, 81, 19));
        label_19->setFont(font4);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinCullDistance = new QSpinBox(groupC4);
        spinCullDistance->setObjectName(QString::fromUtf8("spinCullDistance"));
        spinCullDistance->setGeometry(QRect(100, 134, 85, 27));
        spinCullDistance->setFont(font2);
        spinCullDistance->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinCullDistance->setAlignment(Qt::AlignCenter);
        spinCullDistance->setMinimum(1);
        spinCullDistance->setMaximum(100);
        spinCullDistance->setValue(5);
        groupC6 = new QGroupBox(tab_2);
        groupC6->setObjectName(QString::fromUtf8("groupC6"));
        groupC6->setGeometry(QRect(8, 402, 449, 119));
        groupC6->setFont(font);
        groupC6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtFindCirMsg = new QTextEdit(groupC6);
        txtFindCirMsg->setObjectName(QString::fromUtf8("txtFindCirMsg"));
        txtFindCirMsg->setGeometry(QRect(4, 32, 439, 83));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        txtFindCirMsg->setFont(font5);
        txtFindCirMsg->setStyleSheet(QString::fromUtf8("QTextEdit         \n"
"{\n"
"    background-color: rgba(180, 180, 215,120);    \n"
"    gridline-color: rgba(220, 220, 255,255);\n"
"    color: rgba(20, 20, 20,200);\n"
"}\n"
"QScrollBar:vertical{ \n"
"		background:#FFFFF2;\n"
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
"QScrollBar::add-line:vertical{\n"
"		background:url(:/resource/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/resource/up.png) center no-repeat;}\n"
"QScrollBar:horizontal{ \n"
"		background:#FFFFF2;\n"
"		padding-top:20px;\n"
"		padding-bottom:20px;\n"
"		padding-left:2px;\n"
"		padding-right:2px;\n"
"		border-left:1px solid #d7d7d7;}\n"
"QScrollBar::handle:horizontal{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px"
                        ";}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/resource/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/resource/left.png) center no-repeat;}"));
        txtFindCirMsg->setReadOnly(true);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupC7 = new QGroupBox(tab_3);
        groupC7->setObjectName(QString::fromUtf8("groupC7"));
        groupC7->setGeometry(QRect(8, 18, 449, 499));
        groupC7->setFont(font);
        groupC7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        frame = new QFrame(groupC7);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(16, 40, 418, 47));
        frame->setStyleSheet(QString::fromUtf8("border:2px solid #778899;border-radius: 22px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioNinePoints = new QRadioButton(frame);
        radioNinePoints->setObjectName(QString::fromUtf8("radioNinePoints"));
        radioNinePoints->setFont(font);
        radioNinePoints->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"border:none;\n"
"background: transparent;"));
        radioNinePoints->setChecked(true);

        horizontalLayout_2->addWidget(radioNinePoints);

        horizontalSpacer_6 = new QSpacerItem(110, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        radioRotateCenter = new QRadioButton(frame);
        radioRotateCenter->setObjectName(QString::fromUtf8("radioRotateCenter"));
        radioRotateCenter->setFont(font);
        radioRotateCenter->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"border:none;\n"
"background: transparent;"));

        horizontalLayout_2->addWidget(radioRotateCenter);

        stackedWidget = new QStackedWidget(groupC7);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(1, 91, 447, 409));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        groupC8 = new QGroupBox(page);
        groupC8->setObjectName(QString::fromUtf8("groupC8"));
        groupC8->setGeometry(QRect(0, 17, 449, 391));
        groupC8->setFont(font);
        groupC8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        spinImageY2 = new QDoubleSpinBox(groupC8);
        spinImageY2->setObjectName(QString::fromUtf8("spinImageY2"));
        spinImageY2->setGeometry(QRect(127, 104, 104, 27));
        sizePolicy.setHeightForWidth(spinImageY2->sizePolicy().hasHeightForWidth());
        spinImageY2->setSizePolicy(sizePolicy);
        spinImageY2->setMinimumSize(QSize(96, 25));
        spinImageY2->setFont(font1);
        spinImageY2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageY2->setAlignment(Qt::AlignCenter);
        spinImageY2->setDecimals(4);
        spinImageY2->setMinimum(0.000000000000000);
        spinImageY2->setMaximum(9999.998999999999796);
        spinImageY2->setSingleStep(1.000000000000000);
        spinImageY2->setValue(0.000000000000000);
        spinImageX8 = new QDoubleSpinBox(groupC8);
        spinImageX8->setObjectName(QString::fromUtf8("spinImageX8"));
        spinImageX8->setGeometry(QRect(20, 320, 104, 27));
        sizePolicy.setHeightForWidth(spinImageX8->sizePolicy().hasHeightForWidth());
        spinImageX8->setSizePolicy(sizePolicy);
        spinImageX8->setMinimumSize(QSize(96, 25));
        spinImageX8->setFont(font1);
        spinImageX8->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageX8->setAlignment(Qt::AlignCenter);
        spinImageX8->setDecimals(4);
        spinImageX8->setMinimum(0.000000000000000);
        spinImageX8->setMaximum(9999.998999999999796);
        spinImageX8->setSingleStep(1.000000000000000);
        spinImageX8->setValue(0.000000000000000);
        spinMachineX2 = new QDoubleSpinBox(groupC8);
        spinMachineX2->setObjectName(QString::fromUtf8("spinMachineX2"));
        spinMachineX2->setGeometry(QRect(232, 104, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineX2->sizePolicy().hasHeightForWidth());
        spinMachineX2->setSizePolicy(sizePolicy);
        spinMachineX2->setMinimumSize(QSize(96, 25));
        spinMachineX2->setFont(font1);
        spinMachineX2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineX2->setAlignment(Qt::AlignCenter);
        spinMachineX2->setDecimals(4);
        spinMachineX2->setMinimum(-9999.998999999999796);
        spinMachineX2->setMaximum(9999.998999999999796);
        spinMachineX2->setSingleStep(1.000000000000000);
        spinMachineX2->setValue(0.000000000000000);
        spinImageY8 = new QDoubleSpinBox(groupC8);
        spinImageY8->setObjectName(QString::fromUtf8("spinImageY8"));
        spinImageY8->setGeometry(QRect(127, 320, 104, 27));
        sizePolicy.setHeightForWidth(spinImageY8->sizePolicy().hasHeightForWidth());
        spinImageY8->setSizePolicy(sizePolicy);
        spinImageY8->setMinimumSize(QSize(96, 25));
        spinImageY8->setFont(font1);
        spinImageY8->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageY8->setAlignment(Qt::AlignCenter);
        spinImageY8->setDecimals(4);
        spinImageY8->setMinimum(0.000000000000000);
        spinImageY8->setMaximum(9999.998999999999796);
        spinImageY8->setSingleStep(1.000000000000000);
        spinImageY8->setValue(0.000000000000000);
        tableWidget = new QTableWidget(groupC8);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font5);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 9)
            tableWidget->setRowCount(9);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(1, 37, 445, 353));
        tableWidget->setFont(font5);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: rgba(180, 180, 210,255);   \n"
"    border:none;\n"
"    gridline-color: rgba(100, 100, 100,200);\n"
"    color: rgba(20, 20, 20,200);\n"
"}\n"
"QTableWidget::item::selected\n"
"{   \n"
"    background-color: rgba(180, 180, 210,255); \n"
"}\n"
"QHeaderView::section\n"
"{\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #00CD00, stop: 0.5 #00CD00,stop: 0.6 #66CD00, stop:1 #66CD00);color: white;\n"
"}\n"
"QHeaderView::section::pressed {\n"
"        color: white;\n"
"        background-color: rgb(39,106,220);\n"
"}\n"
"QScrollBar:vertical{ \n"
"		background:#FFFFF2;\n"
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
"QScrollBar::add-line:vertical{\n"
"		background:url(:/res/ic"
                        "o/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/res/ico/up.png) center no-repeat;}\n"
"QScrollBar:horizontal{ \n"
"		background:#FFFFF2;\n"
"		padding-top:20px;\n"
"		padding-bottom:20px;\n"
"		padding-left:2px;\n"
"		padding-right:2px;\n"
"		border-left:1px solid #d7d7d7;}\n"
"QScrollBar::handle:horizontal{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/res/ico/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/res/ico/left.png) center no-repeat;}"));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setRowCount(9);
        tableWidget->setColumnCount(4);
        tableWidget->horizontalHeader()->setMinimumSectionSize(31);
        tableWidget->horizontalHeader()->setDefaultSectionSize(106);
        tableWidget->verticalHeader()->setMinimumSectionSize(20);
        tableWidget->verticalHeader()->setDefaultSectionSize(36);
        spinMachineX3 = new QDoubleSpinBox(groupC8);
        spinMachineX3->setObjectName(QString::fromUtf8("spinMachineX3"));
        spinMachineX3->setGeometry(QRect(232, 140, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineX3->sizePolicy().hasHeightForWidth());
        spinMachineX3->setSizePolicy(sizePolicy);
        spinMachineX3->setMinimumSize(QSize(96, 25));
        spinMachineX3->setFont(font1);
        spinMachineX3->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineX3->setAlignment(Qt::AlignCenter);
        spinMachineX3->setDecimals(4);
        spinMachineX3->setMinimum(-9999.998999999999796);
        spinMachineX3->setMaximum(9999.998999999999796);
        spinMachineX3->setSingleStep(1.000000000000000);
        spinMachineX3->setValue(0.000000000000000);
        spinMachineY8 = new QDoubleSpinBox(groupC8);
        spinMachineY8->setObjectName(QString::fromUtf8("spinMachineY8"));
        spinMachineY8->setGeometry(QRect(339, 320, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineY8->sizePolicy().hasHeightForWidth());
        spinMachineY8->setSizePolicy(sizePolicy);
        spinMachineY8->setMinimumSize(QSize(96, 25));
        spinMachineY8->setFont(font1);
        spinMachineY8->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineY8->setAlignment(Qt::AlignCenter);
        spinMachineY8->setDecimals(4);
        spinMachineY8->setMinimum(-9999.998999999999796);
        spinMachineY8->setMaximum(9999.998999999999796);
        spinMachineY8->setSingleStep(1.000000000000000);
        spinMachineY8->setValue(0.000000000000000);
        spinMachineX9 = new QDoubleSpinBox(groupC8);
        spinMachineX9->setObjectName(QString::fromUtf8("spinMachineX9"));
        spinMachineX9->setGeometry(QRect(232, 356, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineX9->sizePolicy().hasHeightForWidth());
        spinMachineX9->setSizePolicy(sizePolicy);
        spinMachineX9->setMinimumSize(QSize(96, 25));
        spinMachineX9->setFont(font1);
        spinMachineX9->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineX9->setAlignment(Qt::AlignCenter);
        spinMachineX9->setDecimals(4);
        spinMachineX9->setMinimum(-9999.998999999999796);
        spinMachineX9->setMaximum(9999.998999999999796);
        spinMachineX9->setSingleStep(1.000000000000000);
        spinMachineX9->setValue(0.000000000000000);
        spinImageX5 = new QDoubleSpinBox(groupC8);
        spinImageX5->setObjectName(QString::fromUtf8("spinImageX5"));
        spinImageX5->setGeometry(QRect(20, 212, 104, 27));
        sizePolicy.setHeightForWidth(spinImageX5->sizePolicy().hasHeightForWidth());
        spinImageX5->setSizePolicy(sizePolicy);
        spinImageX5->setMinimumSize(QSize(96, 25));
        spinImageX5->setFont(font1);
        spinImageX5->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageX5->setAlignment(Qt::AlignCenter);
        spinImageX5->setDecimals(4);
        spinImageX5->setMinimum(0.000000000000000);
        spinImageX5->setMaximum(9999.998999999999796);
        spinImageX5->setSingleStep(1.000000000000000);
        spinImageX5->setValue(0.000000000000000);
        spinMachineY5 = new QDoubleSpinBox(groupC8);
        spinMachineY5->setObjectName(QString::fromUtf8("spinMachineY5"));
        spinMachineY5->setGeometry(QRect(339, 212, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineY5->sizePolicy().hasHeightForWidth());
        spinMachineY5->setSizePolicy(sizePolicy);
        spinMachineY5->setMinimumSize(QSize(96, 25));
        spinMachineY5->setFont(font1);
        spinMachineY5->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineY5->setAlignment(Qt::AlignCenter);
        spinMachineY5->setDecimals(4);
        spinMachineY5->setMinimum(-9999.998999999999796);
        spinMachineY5->setMaximum(9999.998999999999796);
        spinMachineY5->setSingleStep(1.000000000000000);
        spinMachineY5->setValue(0.000000000000000);
        spinImageX9 = new QDoubleSpinBox(groupC8);
        spinImageX9->setObjectName(QString::fromUtf8("spinImageX9"));
        spinImageX9->setGeometry(QRect(20, 356, 104, 27));
        sizePolicy.setHeightForWidth(spinImageX9->sizePolicy().hasHeightForWidth());
        spinImageX9->setSizePolicy(sizePolicy);
        spinImageX9->setMinimumSize(QSize(96, 25));
        spinImageX9->setFont(font1);
        spinImageX9->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageX9->setAlignment(Qt::AlignCenter);
        spinImageX9->setDecimals(4);
        spinImageX9->setMinimum(0.000000000000000);
        spinImageX9->setMaximum(9999.998999999999796);
        spinImageX9->setSingleStep(1.000000000000000);
        spinImageX9->setValue(0.000000000000000);
        spinMachineY4 = new QDoubleSpinBox(groupC8);
        spinMachineY4->setObjectName(QString::fromUtf8("spinMachineY4"));
        spinMachineY4->setGeometry(QRect(339, 176, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineY4->sizePolicy().hasHeightForWidth());
        spinMachineY4->setSizePolicy(sizePolicy);
        spinMachineY4->setMinimumSize(QSize(96, 25));
        spinMachineY4->setFont(font1);
        spinMachineY4->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineY4->setAlignment(Qt::AlignCenter);
        spinMachineY4->setDecimals(4);
        spinMachineY4->setMinimum(-9999.998999999999796);
        spinMachineY4->setMaximum(9999.998999999999796);
        spinMachineY4->setSingleStep(1.000000000000000);
        spinMachineY4->setValue(0.000000000000000);
        spinImageY6 = new QDoubleSpinBox(groupC8);
        spinImageY6->setObjectName(QString::fromUtf8("spinImageY6"));
        spinImageY6->setGeometry(QRect(127, 248, 104, 27));
        sizePolicy.setHeightForWidth(spinImageY6->sizePolicy().hasHeightForWidth());
        spinImageY6->setSizePolicy(sizePolicy);
        spinImageY6->setMinimumSize(QSize(96, 25));
        spinImageY6->setFont(font1);
        spinImageY6->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageY6->setAlignment(Qt::AlignCenter);
        spinImageY6->setDecimals(4);
        spinImageY6->setMinimum(0.000000000000000);
        spinImageY6->setMaximum(9999.998999999999796);
        spinImageY6->setSingleStep(1.000000000000000);
        spinImageY6->setValue(0.000000000000000);
        spinImageX7 = new QDoubleSpinBox(groupC8);
        spinImageX7->setObjectName(QString::fromUtf8("spinImageX7"));
        spinImageX7->setGeometry(QRect(20, 284, 104, 27));
        sizePolicy.setHeightForWidth(spinImageX7->sizePolicy().hasHeightForWidth());
        spinImageX7->setSizePolicy(sizePolicy);
        spinImageX7->setMinimumSize(QSize(96, 25));
        spinImageX7->setFont(font1);
        spinImageX7->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageX7->setAlignment(Qt::AlignCenter);
        spinImageX7->setDecimals(4);
        spinImageX7->setMinimum(0.000000000000000);
        spinImageX7->setMaximum(9999.998999999999796);
        spinImageX7->setSingleStep(1.000000000000000);
        spinImageX7->setValue(0.000000000000000);
        spinMachineX1 = new QDoubleSpinBox(groupC8);
        spinMachineX1->setObjectName(QString::fromUtf8("spinMachineX1"));
        spinMachineX1->setGeometry(QRect(232, 68, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineX1->sizePolicy().hasHeightForWidth());
        spinMachineX1->setSizePolicy(sizePolicy);
        spinMachineX1->setMinimumSize(QSize(96, 25));
        spinMachineX1->setFont(font1);
        spinMachineX1->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineX1->setAlignment(Qt::AlignCenter);
        spinMachineX1->setDecimals(4);
        spinMachineX1->setMinimum(-9999.998999999999796);
        spinMachineX1->setMaximum(9999.998999999999796);
        spinMachineX1->setSingleStep(1.000000000000000);
        spinMachineX1->setValue(0.000000000000000);
        spinMachineX7 = new QDoubleSpinBox(groupC8);
        spinMachineX7->setObjectName(QString::fromUtf8("spinMachineX7"));
        spinMachineX7->setGeometry(QRect(232, 284, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineX7->sizePolicy().hasHeightForWidth());
        spinMachineX7->setSizePolicy(sizePolicy);
        spinMachineX7->setMinimumSize(QSize(96, 25));
        spinMachineX7->setFont(font1);
        spinMachineX7->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineX7->setAlignment(Qt::AlignCenter);
        spinMachineX7->setDecimals(4);
        spinMachineX7->setMinimum(-9999.998999999999796);
        spinMachineX7->setMaximum(9999.998999999999796);
        spinMachineX7->setSingleStep(1.000000000000000);
        spinMachineX7->setValue(0.000000000000000);
        spinImageX6 = new QDoubleSpinBox(groupC8);
        spinImageX6->setObjectName(QString::fromUtf8("spinImageX6"));
        spinImageX6->setGeometry(QRect(20, 248, 104, 27));
        sizePolicy.setHeightForWidth(spinImageX6->sizePolicy().hasHeightForWidth());
        spinImageX6->setSizePolicy(sizePolicy);
        spinImageX6->setMinimumSize(QSize(96, 25));
        spinImageX6->setFont(font1);
        spinImageX6->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageX6->setAlignment(Qt::AlignCenter);
        spinImageX6->setDecimals(4);
        spinImageX6->setMinimum(0.000000000000000);
        spinImageX6->setMaximum(9999.998999999999796);
        spinImageX6->setSingleStep(1.000000000000000);
        spinImageX6->setValue(0.000000000000000);
        spinMachineX8 = new QDoubleSpinBox(groupC8);
        spinMachineX8->setObjectName(QString::fromUtf8("spinMachineX8"));
        spinMachineX8->setGeometry(QRect(232, 320, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineX8->sizePolicy().hasHeightForWidth());
        spinMachineX8->setSizePolicy(sizePolicy);
        spinMachineX8->setMinimumSize(QSize(96, 25));
        spinMachineX8->setFont(font1);
        spinMachineX8->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineX8->setAlignment(Qt::AlignCenter);
        spinMachineX8->setDecimals(4);
        spinMachineX8->setMinimum(-9999.998999999999796);
        spinMachineX8->setMaximum(9999.998999999999796);
        spinMachineX8->setSingleStep(1.000000000000000);
        spinMachineX8->setValue(0.000000000000000);
        spinImageX4 = new QDoubleSpinBox(groupC8);
        spinImageX4->setObjectName(QString::fromUtf8("spinImageX4"));
        spinImageX4->setGeometry(QRect(20, 176, 104, 27));
        sizePolicy.setHeightForWidth(spinImageX4->sizePolicy().hasHeightForWidth());
        spinImageX4->setSizePolicy(sizePolicy);
        spinImageX4->setMinimumSize(QSize(96, 25));
        spinImageX4->setFont(font1);
        spinImageX4->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageX4->setAlignment(Qt::AlignCenter);
        spinImageX4->setDecimals(4);
        spinImageX4->setMinimum(0.000000000000000);
        spinImageX4->setMaximum(9999.998999999999796);
        spinImageX4->setSingleStep(1.000000000000000);
        spinImageX4->setValue(0.000000000000000);
        spinMachineX6 = new QDoubleSpinBox(groupC8);
        spinMachineX6->setObjectName(QString::fromUtf8("spinMachineX6"));
        spinMachineX6->setGeometry(QRect(232, 248, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineX6->sizePolicy().hasHeightForWidth());
        spinMachineX6->setSizePolicy(sizePolicy);
        spinMachineX6->setMinimumSize(QSize(96, 25));
        spinMachineX6->setFont(font1);
        spinMachineX6->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineX6->setAlignment(Qt::AlignCenter);
        spinMachineX6->setDecimals(4);
        spinMachineX6->setMinimum(-9999.998999999999796);
        spinMachineX6->setMaximum(9999.998999999999796);
        spinMachineX6->setSingleStep(1.000000000000000);
        spinMachineX6->setValue(0.000000000000000);
        spinMachineY3 = new QDoubleSpinBox(groupC8);
        spinMachineY3->setObjectName(QString::fromUtf8("spinMachineY3"));
        spinMachineY3->setGeometry(QRect(339, 140, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineY3->sizePolicy().hasHeightForWidth());
        spinMachineY3->setSizePolicy(sizePolicy);
        spinMachineY3->setMinimumSize(QSize(96, 25));
        spinMachineY3->setFont(font1);
        spinMachineY3->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineY3->setAlignment(Qt::AlignCenter);
        spinMachineY3->setDecimals(4);
        spinMachineY3->setMinimum(-9999.998999999999796);
        spinMachineY3->setMaximum(9999.998999999999796);
        spinMachineY3->setSingleStep(1.000000000000000);
        spinMachineY3->setValue(0.000000000000000);
        spinImageX1 = new QDoubleSpinBox(groupC8);
        spinImageX1->setObjectName(QString::fromUtf8("spinImageX1"));
        spinImageX1->setGeometry(QRect(20, 68, 104, 27));
        sizePolicy.setHeightForWidth(spinImageX1->sizePolicy().hasHeightForWidth());
        spinImageX1->setSizePolicy(sizePolicy);
        spinImageX1->setMinimumSize(QSize(96, 25));
        spinImageX1->setFont(font1);
        spinImageX1->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageX1->setAlignment(Qt::AlignCenter);
        spinImageX1->setDecimals(4);
        spinImageX1->setMinimum(0.000000000000000);
        spinImageX1->setMaximum(9999.998999999999796);
        spinImageX1->setSingleStep(1.000000000000000);
        spinImageX1->setValue(0.000000000000000);
        spinImageX3 = new QDoubleSpinBox(groupC8);
        spinImageX3->setObjectName(QString::fromUtf8("spinImageX3"));
        spinImageX3->setGeometry(QRect(20, 140, 104, 27));
        sizePolicy.setHeightForWidth(spinImageX3->sizePolicy().hasHeightForWidth());
        spinImageX3->setSizePolicy(sizePolicy);
        spinImageX3->setMinimumSize(QSize(96, 25));
        spinImageX3->setFont(font1);
        spinImageX3->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageX3->setAlignment(Qt::AlignCenter);
        spinImageX3->setDecimals(4);
        spinImageX3->setMinimum(0.000000000000000);
        spinImageX3->setMaximum(9999.998999999999796);
        spinImageX3->setSingleStep(1.000000000000000);
        spinImageX3->setValue(0.000000000000000);
        spinImageY4 = new QDoubleSpinBox(groupC8);
        spinImageY4->setObjectName(QString::fromUtf8("spinImageY4"));
        spinImageY4->setGeometry(QRect(127, 176, 104, 27));
        sizePolicy.setHeightForWidth(spinImageY4->sizePolicy().hasHeightForWidth());
        spinImageY4->setSizePolicy(sizePolicy);
        spinImageY4->setMinimumSize(QSize(96, 25));
        spinImageY4->setFont(font1);
        spinImageY4->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageY4->setAlignment(Qt::AlignCenter);
        spinImageY4->setDecimals(4);
        spinImageY4->setMinimum(0.000000000000000);
        spinImageY4->setMaximum(9999.998999999999796);
        spinImageY4->setSingleStep(1.000000000000000);
        spinImageY4->setValue(0.000000000000000);
        spinMachineY2 = new QDoubleSpinBox(groupC8);
        spinMachineY2->setObjectName(QString::fromUtf8("spinMachineY2"));
        spinMachineY2->setGeometry(QRect(339, 104, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineY2->sizePolicy().hasHeightForWidth());
        spinMachineY2->setSizePolicy(sizePolicy);
        spinMachineY2->setMinimumSize(QSize(96, 25));
        spinMachineY2->setFont(font1);
        spinMachineY2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineY2->setAlignment(Qt::AlignCenter);
        spinMachineY2->setDecimals(4);
        spinMachineY2->setMinimum(-9999.998999999999796);
        spinMachineY2->setMaximum(9999.998999999999796);
        spinMachineY2->setSingleStep(1.000000000000000);
        spinMachineY2->setValue(0.000000000000000);
        spinImageY7 = new QDoubleSpinBox(groupC8);
        spinImageY7->setObjectName(QString::fromUtf8("spinImageY7"));
        spinImageY7->setGeometry(QRect(127, 284, 104, 27));
        sizePolicy.setHeightForWidth(spinImageY7->sizePolicy().hasHeightForWidth());
        spinImageY7->setSizePolicy(sizePolicy);
        spinImageY7->setMinimumSize(QSize(96, 25));
        spinImageY7->setFont(font1);
        spinImageY7->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageY7->setAlignment(Qt::AlignCenter);
        spinImageY7->setDecimals(4);
        spinImageY7->setMinimum(0.000000000000000);
        spinImageY7->setMaximum(9999.998999999999796);
        spinImageY7->setSingleStep(1.000000000000000);
        spinImageY7->setValue(0.000000000000000);
        spinMachineY9 = new QDoubleSpinBox(groupC8);
        spinMachineY9->setObjectName(QString::fromUtf8("spinMachineY9"));
        spinMachineY9->setGeometry(QRect(339, 356, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineY9->sizePolicy().hasHeightForWidth());
        spinMachineY9->setSizePolicy(sizePolicy);
        spinMachineY9->setMinimumSize(QSize(96, 25));
        spinMachineY9->setFont(font1);
        spinMachineY9->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineY9->setAlignment(Qt::AlignCenter);
        spinMachineY9->setDecimals(4);
        spinMachineY9->setMinimum(-9999.998999999999796);
        spinMachineY9->setMaximum(9999.998999999999796);
        spinMachineY9->setSingleStep(1.000000000000000);
        spinMachineY9->setValue(0.000000000000000);
        spinMachineY1 = new QDoubleSpinBox(groupC8);
        spinMachineY1->setObjectName(QString::fromUtf8("spinMachineY1"));
        spinMachineY1->setGeometry(QRect(339, 68, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineY1->sizePolicy().hasHeightForWidth());
        spinMachineY1->setSizePolicy(sizePolicy);
        spinMachineY1->setMinimumSize(QSize(96, 25));
        spinMachineY1->setFont(font1);
        spinMachineY1->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineY1->setAlignment(Qt::AlignCenter);
        spinMachineY1->setDecimals(4);
        spinMachineY1->setMinimum(-9999.998999999999796);
        spinMachineY1->setMaximum(9999.998999999999796);
        spinMachineY1->setSingleStep(1.000000000000000);
        spinMachineY1->setValue(0.000000000000000);
        spinImageY1 = new QDoubleSpinBox(groupC8);
        spinImageY1->setObjectName(QString::fromUtf8("spinImageY1"));
        spinImageY1->setGeometry(QRect(127, 68, 104, 27));
        sizePolicy.setHeightForWidth(spinImageY1->sizePolicy().hasHeightForWidth());
        spinImageY1->setSizePolicy(sizePolicy);
        spinImageY1->setMinimumSize(QSize(96, 25));
        spinImageY1->setFont(font1);
        spinImageY1->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageY1->setAlignment(Qt::AlignCenter);
        spinImageY1->setDecimals(4);
        spinImageY1->setMinimum(0.000000000000000);
        spinImageY1->setMaximum(9999.998999999999796);
        spinImageY1->setSingleStep(1.000000000000000);
        spinImageY1->setValue(0.000000000000000);
        spinImageY5 = new QDoubleSpinBox(groupC8);
        spinImageY5->setObjectName(QString::fromUtf8("spinImageY5"));
        spinImageY5->setGeometry(QRect(127, 212, 104, 27));
        sizePolicy.setHeightForWidth(spinImageY5->sizePolicy().hasHeightForWidth());
        spinImageY5->setSizePolicy(sizePolicy);
        spinImageY5->setMinimumSize(QSize(96, 25));
        spinImageY5->setFont(font1);
        spinImageY5->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageY5->setAlignment(Qt::AlignCenter);
        spinImageY5->setDecimals(4);
        spinImageY5->setMinimum(0.000000000000000);
        spinImageY5->setMaximum(9999.998999999999796);
        spinImageY5->setSingleStep(1.000000000000000);
        spinImageY5->setValue(0.000000000000000);
        spinMachineX4 = new QDoubleSpinBox(groupC8);
        spinMachineX4->setObjectName(QString::fromUtf8("spinMachineX4"));
        spinMachineX4->setGeometry(QRect(232, 176, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineX4->sizePolicy().hasHeightForWidth());
        spinMachineX4->setSizePolicy(sizePolicy);
        spinMachineX4->setMinimumSize(QSize(96, 25));
        spinMachineX4->setFont(font1);
        spinMachineX4->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineX4->setAlignment(Qt::AlignCenter);
        spinMachineX4->setDecimals(4);
        spinMachineX4->setMinimum(-9999.998999999999796);
        spinMachineX4->setMaximum(9999.998999999999796);
        spinMachineX4->setSingleStep(1.000000000000000);
        spinMachineX4->setValue(0.000000000000000);
        spinImageY3 = new QDoubleSpinBox(groupC8);
        spinImageY3->setObjectName(QString::fromUtf8("spinImageY3"));
        spinImageY3->setGeometry(QRect(127, 140, 104, 27));
        sizePolicy.setHeightForWidth(spinImageY3->sizePolicy().hasHeightForWidth());
        spinImageY3->setSizePolicy(sizePolicy);
        spinImageY3->setMinimumSize(QSize(96, 25));
        spinImageY3->setFont(font1);
        spinImageY3->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageY3->setAlignment(Qt::AlignCenter);
        spinImageY3->setDecimals(4);
        spinImageY3->setMinimum(0.000000000000000);
        spinImageY3->setMaximum(9999.998999999999796);
        spinImageY3->setSingleStep(1.000000000000000);
        spinImageY3->setValue(0.000000000000000);
        spinImageX2 = new QDoubleSpinBox(groupC8);
        spinImageX2->setObjectName(QString::fromUtf8("spinImageX2"));
        spinImageX2->setGeometry(QRect(20, 104, 104, 27));
        sizePolicy.setHeightForWidth(spinImageX2->sizePolicy().hasHeightForWidth());
        spinImageX2->setSizePolicy(sizePolicy);
        spinImageX2->setMinimumSize(QSize(96, 25));
        spinImageX2->setFont(font1);
        spinImageX2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageX2->setAlignment(Qt::AlignCenter);
        spinImageX2->setDecimals(4);
        spinImageX2->setMinimum(0.000000000000000);
        spinImageX2->setMaximum(9999.998999999999796);
        spinImageX2->setSingleStep(1.000000000000000);
        spinImageX2->setValue(0.000000000000000);
        spinMachineY6 = new QDoubleSpinBox(groupC8);
        spinMachineY6->setObjectName(QString::fromUtf8("spinMachineY6"));
        spinMachineY6->setGeometry(QRect(339, 248, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineY6->sizePolicy().hasHeightForWidth());
        spinMachineY6->setSizePolicy(sizePolicy);
        spinMachineY6->setMinimumSize(QSize(96, 25));
        spinMachineY6->setFont(font1);
        spinMachineY6->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineY6->setAlignment(Qt::AlignCenter);
        spinMachineY6->setDecimals(4);
        spinMachineY6->setMinimum(-9999.998999999999796);
        spinMachineY6->setMaximum(9999.998999999999796);
        spinMachineY6->setSingleStep(1.000000000000000);
        spinMachineY6->setValue(0.000000000000000);
        spinMachineX5 = new QDoubleSpinBox(groupC8);
        spinMachineX5->setObjectName(QString::fromUtf8("spinMachineX5"));
        spinMachineX5->setGeometry(QRect(232, 212, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineX5->sizePolicy().hasHeightForWidth());
        spinMachineX5->setSizePolicy(sizePolicy);
        spinMachineX5->setMinimumSize(QSize(96, 25));
        spinMachineX5->setFont(font1);
        spinMachineX5->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineX5->setAlignment(Qt::AlignCenter);
        spinMachineX5->setDecimals(4);
        spinMachineX5->setMinimum(-9999.998999999999796);
        spinMachineX5->setMaximum(9999.998999999999796);
        spinMachineX5->setSingleStep(1.000000000000000);
        spinMachineX5->setValue(0.000000000000000);
        spinMachineY7 = new QDoubleSpinBox(groupC8);
        spinMachineY7->setObjectName(QString::fromUtf8("spinMachineY7"));
        spinMachineY7->setGeometry(QRect(339, 284, 104, 27));
        sizePolicy.setHeightForWidth(spinMachineY7->sizePolicy().hasHeightForWidth());
        spinMachineY7->setSizePolicy(sizePolicy);
        spinMachineY7->setMinimumSize(QSize(96, 25));
        spinMachineY7->setFont(font1);
        spinMachineY7->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinMachineY7->setAlignment(Qt::AlignCenter);
        spinMachineY7->setDecimals(4);
        spinMachineY7->setMinimum(-9999.998999999999796);
        spinMachineY7->setMaximum(9999.998999999999796);
        spinMachineY7->setSingleStep(1.000000000000000);
        spinMachineY7->setValue(0.000000000000000);
        spinImageY9 = new QDoubleSpinBox(groupC8);
        spinImageY9->setObjectName(QString::fromUtf8("spinImageY9"));
        spinImageY9->setGeometry(QRect(127, 356, 104, 27));
        sizePolicy.setHeightForWidth(spinImageY9->sizePolicy().hasHeightForWidth());
        spinImageY9->setSizePolicy(sizePolicy);
        spinImageY9->setMinimumSize(QSize(96, 25));
        spinImageY9->setFont(font1);
        spinImageY9->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageY9->setAlignment(Qt::AlignCenter);
        spinImageY9->setDecimals(4);
        spinImageY9->setMinimum(0.000000000000000);
        spinImageY9->setMaximum(9999.998999999999796);
        spinImageY9->setSingleStep(1.000000000000000);
        spinImageY9->setValue(0.000000000000000);
        tableWidget->raise();
        spinImageY2->raise();
        spinImageX8->raise();
        spinMachineX2->raise();
        spinImageY8->raise();
        spinMachineX3->raise();
        spinMachineY8->raise();
        spinMachineX9->raise();
        spinImageX5->raise();
        spinMachineY5->raise();
        spinImageX9->raise();
        spinMachineY4->raise();
        spinImageY6->raise();
        spinImageX7->raise();
        spinMachineX1->raise();
        spinMachineX7->raise();
        spinImageX6->raise();
        spinMachineX8->raise();
        spinImageX4->raise();
        spinMachineX6->raise();
        spinMachineY3->raise();
        spinImageX1->raise();
        spinImageX3->raise();
        spinImageY4->raise();
        spinMachineY2->raise();
        spinImageY7->raise();
        spinMachineY9->raise();
        spinMachineY1->raise();
        spinImageY1->raise();
        spinImageY5->raise();
        spinMachineX4->raise();
        spinImageY3->raise();
        spinImageX2->raise();
        spinMachineY6->raise();
        spinMachineX5->raise();
        spinMachineY7->raise();
        spinImageY9->raise();
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupC9 = new QGroupBox(page_2);
        groupC9->setObjectName(QString::fromUtf8("groupC9"));
        groupC9->setGeometry(QRect(0, 17, 449, 391));
        groupC9->setFont(font);
        groupC9->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        spinStandardAngle = new QDoubleSpinBox(groupC9);
        spinStandardAngle->setObjectName(QString::fromUtf8("spinStandardAngle"));
        spinStandardAngle->setGeometry(QRect(96, 146, 100, 28));
        sizePolicy.setHeightForWidth(spinStandardAngle->sizePolicy().hasHeightForWidth());
        spinStandardAngle->setSizePolicy(sizePolicy);
        spinStandardAngle->setMinimumSize(QSize(80, 25));
        spinStandardAngle->setFont(font);
        spinStandardAngle->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinStandardAngle->setAlignment(Qt::AlignCenter);
        spinStandardAngle->setDecimals(3);
        spinStandardAngle->setMinimum(-180.000000000000000);
        spinStandardAngle->setMaximum(180.000000000000000);
        spinStandardAngle->setSingleStep(1.000000000000000);
        spinStandardAngle->setValue(0.000000000000000);
        label_17 = new QLabel(groupC9);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(13, 149, 81, 19));
        sizePolicy2.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy2);
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        checkUseRotateC = new QCheckBox(groupC9);
        checkUseRotateC->setObjectName(QString::fromUtf8("checkUseRotateC"));
        checkUseRotateC->setEnabled(true);
        checkUseRotateC->setGeometry(QRect(13, 37, 135, 27));
        sizePolicy.setHeightForWidth(checkUseRotateC->sizePolicy().hasHeightForWidth());
        checkUseRotateC->setSizePolicy(sizePolicy);
        checkUseRotateC->setFont(font);
        checkUseRotateC->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkUseRotateC->setIconSize(QSize(22, 22));
        checkUseRotateC->setChecked(false);
        label_21 = new QLabel(groupC9);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(13, 88, 81, 19));
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);
        label_21->setFont(font);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboCalibMethod = new QComboBox(groupC9);
        comboCalibMethod->addItem(QString());
        comboCalibMethod->addItem(QString());
        comboCalibMethod->setObjectName(QString::fromUtf8("comboCalibMethod"));
        comboCalibMethod->setGeometry(QRect(96, 84, 147, 30));
        comboCalibMethod->setFont(font);
        comboCalibMethod->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        stackedWidgetC = new QStackedWidget(groupC9);
        stackedWidgetC->setObjectName(QString::fromUtf8("stackedWidgetC"));
        stackedWidgetC->setGeometry(QRect(1, 182, 445, 207));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        spinImageRY2 = new QDoubleSpinBox(page_3);
        spinImageRY2->setObjectName(QString::fromUtf8("spinImageRY2"));
        spinImageRY2->setGeometry(QRect(236, 107, 137, 27));
        sizePolicy.setHeightForWidth(spinImageRY2->sizePolicy().hasHeightForWidth());
        spinImageRY2->setSizePolicy(sizePolicy);
        spinImageRY2->setMinimumSize(QSize(96, 25));
        spinImageRY2->setFont(font);
        spinImageRY2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageRY2->setAlignment(Qt::AlignCenter);
        spinImageRY2->setDecimals(4);
        spinImageRY2->setMinimum(0.000000000000000);
        spinImageRY2->setMaximum(9999.998999999999796);
        spinImageRY2->setSingleStep(1.000000000000000);
        spinImageRY2->setValue(0.000000000000000);
        spinImageRX2 = new QDoubleSpinBox(page_3);
        spinImageRX2->setObjectName(QString::fromUtf8("spinImageRX2"));
        spinImageRX2->setGeometry(QRect(92, 107, 137, 27));
        sizePolicy.setHeightForWidth(spinImageRX2->sizePolicy().hasHeightForWidth());
        spinImageRX2->setSizePolicy(sizePolicy);
        spinImageRX2->setMinimumSize(QSize(96, 25));
        spinImageRX2->setFont(font);
        spinImageRX2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageRX2->setAlignment(Qt::AlignCenter);
        spinImageRX2->setDecimals(4);
        spinImageRX2->setMinimum(0.000000000000000);
        spinImageRX2->setMaximum(9999.998999999999796);
        spinImageRX2->setSingleStep(1.000000000000000);
        spinImageRX2->setValue(0.000000000000000);
        spinImageRX1 = new QDoubleSpinBox(page_3);
        spinImageRX1->setObjectName(QString::fromUtf8("spinImageRX1"));
        spinImageRX1->setGeometry(QRect(92, 68, 137, 27));
        sizePolicy.setHeightForWidth(spinImageRX1->sizePolicy().hasHeightForWidth());
        spinImageRX1->setSizePolicy(sizePolicy);
        spinImageRX1->setMinimumSize(QSize(96, 25));
        spinImageRX1->setFont(font);
        spinImageRX1->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageRX1->setAlignment(Qt::AlignCenter);
        spinImageRX1->setDecimals(4);
        spinImageRX1->setMinimum(0.000000000000000);
        spinImageRX1->setMaximum(9999.998999999999796);
        spinImageRX1->setSingleStep(1.000000000000000);
        spinImageRX1->setValue(0.000000000000000);
        spinImageRY3 = new QDoubleSpinBox(page_3);
        spinImageRY3->setObjectName(QString::fromUtf8("spinImageRY3"));
        spinImageRY3->setGeometry(QRect(236, 146, 137, 27));
        sizePolicy.setHeightForWidth(spinImageRY3->sizePolicy().hasHeightForWidth());
        spinImageRY3->setSizePolicy(sizePolicy);
        spinImageRY3->setMinimumSize(QSize(96, 25));
        spinImageRY3->setFont(font);
        spinImageRY3->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageRY3->setAlignment(Qt::AlignCenter);
        spinImageRY3->setDecimals(4);
        spinImageRY3->setMinimum(0.000000000000000);
        spinImageRY3->setMaximum(9999.998999999999796);
        spinImageRY3->setSingleStep(1.000000000000000);
        spinImageRY3->setValue(0.000000000000000);
        spinImageRX3 = new QDoubleSpinBox(page_3);
        spinImageRX3->setObjectName(QString::fromUtf8("spinImageRX3"));
        spinImageRX3->setGeometry(QRect(92, 146, 137, 27));
        sizePolicy.setHeightForWidth(spinImageRX3->sizePolicy().hasHeightForWidth());
        spinImageRX3->setSizePolicy(sizePolicy);
        spinImageRX3->setMinimumSize(QSize(96, 25));
        spinImageRX3->setFont(font);
        spinImageRX3->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageRX3->setAlignment(Qt::AlignCenter);
        spinImageRX3->setDecimals(4);
        spinImageRX3->setMinimum(0.000000000000000);
        spinImageRX3->setMaximum(9999.998999999999796);
        spinImageRX3->setSingleStep(1.000000000000000);
        spinImageRX3->setValue(0.000000000000000);
        tableWidgetR = new QTableWidget(page_3);
        if (tableWidgetR->columnCount() < 2)
            tableWidgetR->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tableWidgetR->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font5);
        tableWidgetR->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        if (tableWidgetR->rowCount() < 3)
            tableWidgetR->setRowCount(3);
        tableWidgetR->setObjectName(QString::fromUtf8("tableWidgetR"));
        tableWidgetR->setGeometry(QRect(70, 33, 307, 146));
        tableWidgetR->setFont(font5);
        tableWidgetR->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: rgba(180, 180, 210,255);   \n"
"    border:none;\n"
"    gridline-color: rgba(100, 100, 100,200);\n"
"    color: rgba(20, 20, 20,200);\n"
"}\n"
"QTableWidget::item::selected\n"
"{   \n"
"    background-color: rgba(180, 180, 210,255); \n"
"}\n"
"QHeaderView::section\n"
"{\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #00CD00, stop: 0.5 #00CD00,stop: 0.6 #66CD00, stop:1 #66CD00);color: white;\n"
"}\n"
"QHeaderView::section::pressed {\n"
"        color: white;\n"
"        background-color: rgb(39,106,220);\n"
"}\n"
"QScrollBar:vertical{ \n"
"		background:#FFFFF2;\n"
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
"QScrollBar::add-line:vertical{\n"
"		background:url(:/res/ic"
                        "o/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/res/ico/up.png) center no-repeat;}\n"
"QScrollBar:horizontal{ \n"
"		background:#FFFFF2;\n"
"		padding-top:20px;\n"
"		padding-bottom:20px;\n"
"		padding-left:2px;\n"
"		padding-right:2px;\n"
"		border-left:1px solid #d7d7d7;}\n"
"QScrollBar::handle:horizontal{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/res/ico/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/res/ico/left.png) center no-repeat;}"));
        tableWidgetR->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetR->setGridStyle(Qt::SolidLine);
        tableWidgetR->setRowCount(3);
        tableWidgetR->setColumnCount(2);
        tableWidgetR->horizontalHeader()->setMinimumSectionSize(31);
        tableWidgetR->horizontalHeader()->setDefaultSectionSize(144);
        tableWidgetR->verticalHeader()->setMinimumSectionSize(20);
        tableWidgetR->verticalHeader()->setDefaultSectionSize(39);
        spinImageRY1 = new QDoubleSpinBox(page_3);
        spinImageRY1->setObjectName(QString::fromUtf8("spinImageRY1"));
        spinImageRY1->setGeometry(QRect(236, 68, 137, 27));
        sizePolicy.setHeightForWidth(spinImageRY1->sizePolicy().hasHeightForWidth());
        spinImageRY1->setSizePolicy(sizePolicy);
        spinImageRY1->setMinimumSize(QSize(96, 25));
        spinImageRY1->setFont(font);
        spinImageRY1->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImageRY1->setAlignment(Qt::AlignCenter);
        spinImageRY1->setDecimals(4);
        spinImageRY1->setMinimum(0.000000000000000);
        spinImageRY1->setMaximum(9999.998999999999796);
        spinImageRY1->setSingleStep(1.000000000000000);
        spinImageRY1->setValue(0.000000000000000);
        stackedWidgetC->addWidget(page_3);
        tableWidgetR->raise();
        spinImageRY2->raise();
        spinImageRX2->raise();
        spinImageRX1->raise();
        spinImageRY3->raise();
        spinImageRX3->raise();
        spinImageRY1->raise();
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        spinImgRX2 = new QDoubleSpinBox(page_4);
        spinImgRX2->setObjectName(QString::fromUtf8("spinImgRX2"));
        spinImgRX2->setGeometry(QRect(92, 107, 137, 27));
        sizePolicy.setHeightForWidth(spinImgRX2->sizePolicy().hasHeightForWidth());
        spinImgRX2->setSizePolicy(sizePolicy);
        spinImgRX2->setMinimumSize(QSize(96, 25));
        spinImgRX2->setFont(font);
        spinImgRX2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImgRX2->setAlignment(Qt::AlignCenter);
        spinImgRX2->setDecimals(4);
        spinImgRX2->setMinimum(0.000000000000000);
        spinImgRX2->setMaximum(9999.998999999999796);
        spinImgRX2->setSingleStep(1.000000000000000);
        spinImgRX2->setValue(0.000000000000000);
        spinImgRX1 = new QDoubleSpinBox(page_4);
        spinImgRX1->setObjectName(QString::fromUtf8("spinImgRX1"));
        spinImgRX1->setGeometry(QRect(92, 68, 137, 27));
        sizePolicy.setHeightForWidth(spinImgRX1->sizePolicy().hasHeightForWidth());
        spinImgRX1->setSizePolicy(sizePolicy);
        spinImgRX1->setMinimumSize(QSize(96, 25));
        spinImgRX1->setFont(font);
        spinImgRX1->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImgRX1->setAlignment(Qt::AlignCenter);
        spinImgRX1->setDecimals(4);
        spinImgRX1->setMinimum(0.000000000000000);
        spinImgRX1->setMaximum(9999.998999999999796);
        spinImgRX1->setSingleStep(1.000000000000000);
        spinImgRX1->setValue(0.000000000000000);
        spinImgRY2 = new QDoubleSpinBox(page_4);
        spinImgRY2->setObjectName(QString::fromUtf8("spinImgRY2"));
        spinImgRY2->setGeometry(QRect(236, 107, 137, 27));
        sizePolicy.setHeightForWidth(spinImgRY2->sizePolicy().hasHeightForWidth());
        spinImgRY2->setSizePolicy(sizePolicy);
        spinImgRY2->setMinimumSize(QSize(96, 25));
        spinImgRY2->setFont(font);
        spinImgRY2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImgRY2->setAlignment(Qt::AlignCenter);
        spinImgRY2->setDecimals(4);
        spinImgRY2->setMinimum(0.000000000000000);
        spinImgRY2->setMaximum(9999.998999999999796);
        spinImgRY2->setSingleStep(1.000000000000000);
        spinImgRY2->setValue(0.000000000000000);
        spinImgRY1 = new QDoubleSpinBox(page_4);
        spinImgRY1->setObjectName(QString::fromUtf8("spinImgRY1"));
        spinImgRY1->setGeometry(QRect(236, 68, 137, 27));
        sizePolicy.setHeightForWidth(spinImgRY1->sizePolicy().hasHeightForWidth());
        spinImgRY1->setSizePolicy(sizePolicy);
        spinImgRY1->setMinimumSize(QSize(96, 25));
        spinImgRY1->setFont(font);
        spinImgRY1->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);border:none}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinImgRY1->setAlignment(Qt::AlignCenter);
        spinImgRY1->setDecimals(4);
        spinImgRY1->setMinimum(0.000000000000000);
        spinImgRY1->setMaximum(9999.998999999999796);
        spinImgRY1->setSingleStep(1.000000000000000);
        spinImgRY1->setValue(0.000000000000000);
        tableWidgetR2 = new QTableWidget(page_4);
        if (tableWidgetR2->columnCount() < 2)
            tableWidgetR2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font1);
        tableWidgetR2->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font5);
        tableWidgetR2->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        if (tableWidgetR2->rowCount() < 3)
            tableWidgetR2->setRowCount(3);
        tableWidgetR2->setObjectName(QString::fromUtf8("tableWidgetR2"));
        tableWidgetR2->setGeometry(QRect(70, 33, 307, 146));
        tableWidgetR2->setFont(font5);
        tableWidgetR2->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: rgba(180, 180, 210,255);   \n"
"    border:none;\n"
"    gridline-color: rgba(100, 100, 100,200);\n"
"    color: rgba(20, 20, 20,200);\n"
"}\n"
"QTableWidget::item::selected\n"
"{   \n"
"    background-color: rgba(180, 180, 210,255); \n"
"}\n"
"QHeaderView::section\n"
"{\n"
"    background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #00CD00, stop: 0.5 #00CD00,stop: 0.6 #66CD00, stop:1 #66CD00);color: white;\n"
"}\n"
"QHeaderView::section::pressed {\n"
"        color: white;\n"
"        background-color: rgb(39,106,220);\n"
"}\n"
"QScrollBar:vertical{ \n"
"		background:#FFFFF2;\n"
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
"QScrollBar::add-line:vertical{\n"
"		background:url(:/res/ic"
                        "o/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/res/ico/up.png) center no-repeat;}\n"
"QScrollBar:horizontal{ \n"
"		background:#FFFFF2;\n"
"		padding-top:20px;\n"
"		padding-bottom:20px;\n"
"		padding-left:2px;\n"
"		padding-right:2px;\n"
"		border-left:1px solid #d7d7d7;}\n"
"QScrollBar::handle:horizontal{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/res/ico/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/res/ico/left.png) center no-repeat;}"));
        tableWidgetR2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetR2->setGridStyle(Qt::SolidLine);
        tableWidgetR2->setRowCount(3);
        tableWidgetR2->setColumnCount(2);
        tableWidgetR2->horizontalHeader()->setMinimumSectionSize(31);
        tableWidgetR2->horizontalHeader()->setDefaultSectionSize(144);
        tableWidgetR2->verticalHeader()->setMinimumSectionSize(20);
        tableWidgetR2->verticalHeader()->setDefaultSectionSize(39);
        label_22 = new QLabel(page_4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(89, 140, 141, 36));
        sizePolicy2.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy2);
        label_22->setFont(font);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 189, 130, 100);"));
        label_22->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(page_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(225, 140, 141, 36));
        sizePolicy2.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy2);
        label_23->setFont(font);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(255, 189, 130, 100);"));
        label_23->setAlignment(Qt::AlignCenter);
        spinRotateAngle = new QDoubleSpinBox(page_4);
        spinRotateAngle->setObjectName(QString::fromUtf8("spinRotateAngle"));
        spinRotateAngle->setGeometry(QRect(236, 146, 137, 27));
        sizePolicy.setHeightForWidth(spinRotateAngle->sizePolicy().hasHeightForWidth());
        spinRotateAngle->setSizePolicy(sizePolicy);
        spinRotateAngle->setMinimumSize(QSize(80, 25));
        spinRotateAngle->setFont(font);
        spinRotateAngle->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(255, 255, 255);background-color: rgba(255, 189, 130, 0);border:none;}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinRotateAngle->setAlignment(Qt::AlignCenter);
        spinRotateAngle->setDecimals(3);
        spinRotateAngle->setMinimum(-180.000000000000000);
        spinRotateAngle->setMaximum(180.000000000000000);
        spinRotateAngle->setSingleStep(1.000000000000000);
        spinRotateAngle->setValue(0.000000000000000);
        stackedWidgetC->addWidget(page_4);
        tableWidgetR2->raise();
        spinImgRX2->raise();
        spinImgRX1->raise();
        spinImgRY2->raise();
        spinImgRY1->raise();
        label_22->raise();
        label_23->raise();
        spinRotateAngle->raise();
        stackedWidget->addWidget(page_2);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        groupC10 = new QGroupBox(tab_4);
        groupC10->setObjectName(QString::fromUtf8("groupC10"));
        groupC10->setGeometry(QRect(8, 18, 449, 499));
        groupC10->setFont(font);
        groupC10->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC10);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 441, 463));
        txtMsg->setFont(font5);
        txtMsg->setStyleSheet(QString::fromUtf8("QTextEdit         \n"
"{\n"
"    background-color: rgba(180, 180, 215,120);    \n"
"    gridline-color: rgba(220, 220, 255,255);\n"
"    color: rgba(20, 20, 20,200);\n"
"}\n"
"QScrollBar:vertical{ \n"
"		background:#FFFFF2;\n"
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
"QScrollBar::add-line:vertical{\n"
"		background:url(:/resource/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/resource/up.png) center no-repeat;}\n"
"QScrollBar:horizontal{ \n"
"		background:#FFFFF2;\n"
"		padding-top:20px;\n"
"		padding-bottom:20px;\n"
"		padding-left:2px;\n"
"		padding-right:2px;\n"
"		border-left:1px solid #d7d7d7;}\n"
"QScrollBar::handle:horizontal{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px"
                        ";}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/resource/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/resource/left.png) center no-repeat;}"));
        txtMsg->setReadOnly(true);
        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(frmERTCalibrationClass);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);
        stackedWidgetC->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmERTCalibrationClass);
    } // setupUi

    void retranslateUi(QDialog *frmERTCalibrationClass)
    {
        frmERTCalibrationClass->setWindowTitle(QCoreApplication::translate("frmERTCalibrationClass", "N\347\202\271\346\240\207\345\256\232", nullptr));
        label_3->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmERTCalibrationClass", "\346\211\247\350\241\214", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmERTCalibrationClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmERTCalibrationClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmERTCalibrationClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmERTCalibrationClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupC2->setTitle(QCoreApplication::translate("frmERTCalibrationClass", "\344\271\235\347\202\271\346\240\207\345\256\232\347\244\272\346\204\217\345\233\276", nullptr));
        lblImg1->setText(QString());
        groupC3->setTitle(QCoreApplication::translate("frmERTCalibrationClass", "\346\227\213\350\275\254\344\270\255\345\277\203\346\240\207\345\256\232\347\244\272\346\204\217\345\233\276", nullptr));
        lblImg2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmERTCalibrationClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupC5->setTitle(QCoreApplication::translate("frmERTCalibrationClass", "ROI\345\257\271\350\261\241", nullptr));
        checkUseROI->setText(QCoreApplication::translate("frmERTCalibrationClass", "\344\275\277\347\224\250ROI", nullptr));
        comboROIShape->setItemText(0, QCoreApplication::translate("frmERTCalibrationClass", "\345\234\206\347\216\257", nullptr));

        btnAddROI->setText(QCoreApplication::translate("frmERTCalibrationClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteROI->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\210\240\351\231\244", nullptr));
        label_20->setText(QCoreApplication::translate("frmERTCalibrationClass", "ROI\345\256\275\345\272\246\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("frmERTCalibrationClass", "\344\272\244\345\217\211\347\272\277\351\225\277\345\272\246\357\274\232", nullptr));
        btnGetCenter->setText(QCoreApplication::translate("frmERTCalibrationClass", "\350\216\267\345\217\226\345\234\206\345\277\203", nullptr));
        label_8->setText(QString());
        groupC4->setTitle(QCoreApplication::translate("frmERTCalibrationClass", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        comboGrayDirection->setItemText(0, QCoreApplication::translate("frmERTCalibrationClass", "\347\231\275\345\210\260\351\273\221", nullptr));
        comboGrayDirection->setItemText(1, QCoreApplication::translate("frmERTCalibrationClass", "\351\273\221\345\210\260\347\231\275", nullptr));

        label_10->setText(QCoreApplication::translate("frmERTCalibrationClass", "\347\201\260\345\272\246\346\226\271\345\220\221\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("frmERTCalibrationClass", "\350\276\271\347\274\230\345\274\272\345\272\246\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("frmERTCalibrationClass", "\346\211\253\346\217\217\346\226\271\345\220\221\357\274\232", nullptr));
        comboScanDirection->setItemText(0, QCoreApplication::translate("frmERTCalibrationClass", "\345\206\205\345\210\260\345\244\226", nullptr));
        comboScanDirection->setItemText(1, QCoreApplication::translate("frmERTCalibrationClass", "\345\244\226\345\210\260\345\206\205", nullptr));

        label_16->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\210\206\345\211\262\346\225\260\351\207\217\357\274\232", nullptr));
        label_19->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\211\224\351\231\244\350\267\235\347\246\273\357\274\232", nullptr));
        groupC6->setTitle(QCoreApplication::translate("frmERTCalibrationClass", "\350\276\223\345\207\272\346\225\260\346\215\256(\345\234\206\347\232\204\344\270\255\345\277\203\345\235\220\346\240\207)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmERTCalibrationClass", "\346\211\276\345\234\206\345\267\245\345\205\267", nullptr));
        groupC7->setTitle(QCoreApplication::translate("frmERTCalibrationClass", "\346\240\207\345\256\232\345\217\202\346\225\260", nullptr));
        radioNinePoints->setText(QCoreApplication::translate("frmERTCalibrationClass", "\344\271\235\347\202\271\346\240\207\345\256\232\345\217\202\346\225\260", nullptr));
        radioRotateCenter->setText(QCoreApplication::translate("frmERTCalibrationClass", "\346\227\213\350\275\254\344\270\255\345\277\203\346\240\207\345\256\232\345\217\202\346\225\260", nullptr));
        groupC8->setTitle(QCoreApplication::translate("frmERTCalibrationClass", "\345\235\220\346\240\207\346\225\260\346\215\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\233\276\345\203\217\345\235\220\346\240\207X", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\233\276\345\203\217\345\235\220\346\240\207Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("frmERTCalibrationClass", "\346\234\272\346\242\260\345\235\220\346\240\207X", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("frmERTCalibrationClass", "\346\234\272\346\242\260\345\235\220\346\240\207Y", nullptr));
        groupC9->setTitle(QCoreApplication::translate("frmERTCalibrationClass", "\345\235\220\346\240\207\346\225\260\346\215\256", nullptr));
        label_17->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\237\272\345\207\206\350\247\222\345\272\246\357\274\232", nullptr));
        checkUseRotateC->setText(QCoreApplication::translate("frmERTCalibrationClass", "\346\240\207\345\256\232\346\227\213\350\275\254\344\270\255\345\277\203", nullptr));
        label_21->setText(QCoreApplication::translate("frmERTCalibrationClass", "\346\240\207\345\256\232\346\226\271\345\274\217\357\274\232", nullptr));
        comboCalibMethod->setItemText(0, QCoreApplication::translate("frmERTCalibrationClass", "\344\270\211\347\202\271\346\213\237\345\220\210\345\234\206\346\240\207\345\256\232", nullptr));
        comboCalibMethod->setItemText(1, QCoreApplication::translate("frmERTCalibrationClass", "\344\270\244\347\202\271+\350\247\222\345\272\246\346\240\207\345\256\232", nullptr));

        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetR->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\233\276\345\203\217\345\235\220\346\240\207X", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetR->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\233\276\345\203\217\345\235\220\346\240\207Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetR2->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\233\276\345\203\217\345\235\220\346\240\207X", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetR2->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("frmERTCalibrationClass", "\345\233\276\345\203\217\345\235\220\346\240\207Y", nullptr));
        label_22->setText(QCoreApplication::translate("frmERTCalibrationClass", "\346\227\213\350\275\254\350\247\222\345\272\246 -->", nullptr));
        label_23->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("frmERTCalibrationClass", "\346\240\207\345\256\232\350\256\276\347\275\256", nullptr));
        groupC10->setTitle(QCoreApplication::translate("frmERTCalibrationClass", "\350\276\223\345\207\272\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("frmERTCalibrationClass", "\350\276\223\345\207\272\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmERTCalibrationClass: public Ui_frmERTCalibrationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMERTCALIBRATION_H
