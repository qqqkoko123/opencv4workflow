/********************************************************************************
** Form generated from reading UI file 'frmGetContourPoints.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMGETCONTOURPOINTS_H
#define UI_FRMGETCONTOURPOINTS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmGetContourPointsClass
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
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *imageLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QGroupBox *groupC2;
    QLabel *label_7;
    QSpinBox *spinMaxThreshold;
    QLabel *label_8;
    QSpinBox *spinMinThreshold;
    QDoubleSpinBox *spinSigma;
    QLabel *label_9;
    QLabel *label_10;
    QSpinBox *spinCullRatio;
    QGroupBox *groupC3;
    QTextEdit *txtMsg;
    QWidget *tab_2;
    QGroupBox *groupCamera_8;
    QCheckBox *checkUseROI;
    QComboBox *comboROIShape;
    QPushButton *btnAddROI;
    QPushButton *btnDeleteROI;
    QCheckBox *checkViewROI;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *btnRoiColor;
    QSpinBox *spinRoiW;

    void setupUi(QDialog *frmGetContourPointsClass)
    {
        if (frmGetContourPointsClass->objectName().isEmpty())
            frmGetContourPointsClass->setObjectName(QString::fromUtf8("frmGetContourPointsClass"));
        frmGetContourPointsClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmGetContourPointsClass->sizePolicy().hasHeightForWidth());
        frmGetContourPointsClass->setSizePolicy(sizePolicy);
        frmGetContourPointsClass->setMinimumSize(QSize(1160, 655));
        frmGetContourPointsClass->setMaximumSize(QSize(1160, 655));
        frmGetContourPointsClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmGetContourPointsClass);
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

        label_3 = new QLabel(frmGetContourPointsClass);
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

        txtDescribe = new QLineEdit(frmGetContourPointsClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmGetContourPointsClass);
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

        imageLayout = new QGridLayout();
        imageLayout->setSpacing(1);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));

        gridLayout->addLayout(imageLayout, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        tabWidget = new QTabWidget(frmGetContourPointsClass);
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
        groupCamera->setGeometry(QRect(9, 18, 427, 73));
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
        txtLinkImage->setGeometry(QRect(100, 39, 255, 27));
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
        groupC2 = new QGroupBox(tab);
        groupC2->setObjectName(QString::fromUtf8("groupC2"));
        groupC2->setGeometry(QRect(9, 108, 427, 115));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_7 = new QLabel(groupC2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(13, 34, 79, 19));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxThreshold = new QSpinBox(groupC2);
        spinMaxThreshold->setObjectName(QString::fromUtf8("spinMaxThreshold"));
        spinMaxThreshold->setGeometry(QRect(318, 30, 100, 27));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        spinMaxThreshold->setFont(font2);
        spinMaxThreshold->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxThreshold->setAlignment(Qt::AlignCenter);
        spinMaxThreshold->setMinimum(1);
        spinMaxThreshold->setMaximum(255);
        spinMaxThreshold->setValue(40);
        label_8 = new QLabel(groupC2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(236, 34, 73, 19));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinThreshold = new QSpinBox(groupC2);
        spinMinThreshold->setObjectName(QString::fromUtf8("spinMinThreshold"));
        spinMinThreshold->setGeometry(QRect(95, 30, 100, 27));
        spinMinThreshold->setFont(font2);
        spinMinThreshold->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinThreshold->setAlignment(Qt::AlignCenter);
        spinMinThreshold->setMinimum(0);
        spinMinThreshold->setMaximum(254);
        spinMinThreshold->setValue(20);
        spinSigma = new QDoubleSpinBox(groupC2);
        spinSigma->setObjectName(QString::fromUtf8("spinSigma"));
        spinSigma->setGeometry(QRect(95, 80, 100, 27));
        sizePolicy.setHeightForWidth(spinSigma->sizePolicy().hasHeightForWidth());
        spinSigma->setSizePolicy(sizePolicy);
        spinSigma->setMinimumSize(QSize(100, 25));
        spinSigma->setFont(font2);
        spinSigma->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinSigma->setAlignment(Qt::AlignCenter);
        spinSigma->setDecimals(1);
        spinSigma->setMinimum(0.100000000000000);
        spinSigma->setMaximum(3.000000000000000);
        spinSigma->setSingleStep(0.100000000000000);
        spinSigma->setValue(1.000000000000000);
        label_9 = new QLabel(groupC2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(13, 84, 79, 21));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_10 = new QLabel(groupC2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(236, 84, 73, 19));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinCullRatio = new QSpinBox(groupC2);
        spinCullRatio->setObjectName(QString::fromUtf8("spinCullRatio"));
        spinCullRatio->setGeometry(QRect(318, 80, 100, 27));
        spinCullRatio->setFont(font2);
        spinCullRatio->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinCullRatio->setAlignment(Qt::AlignCenter);
        spinCullRatio->setMinimum(0);
        spinCullRatio->setMaximum(50);
        spinCullRatio->setValue(50);
        label_8->raise();
        label_7->raise();
        spinMaxThreshold->raise();
        spinMinThreshold->raise();
        spinSigma->raise();
        label_9->raise();
        label_10->raise();
        spinCullRatio->raise();
        groupC3 = new QGroupBox(tab);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(9, 240, 427, 277));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC3);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 419, 240));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        txtMsg->setFont(font3);
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupCamera_8 = new QGroupBox(tab_2);
        groupCamera_8->setObjectName(QString::fromUtf8("groupCamera_8"));
        groupCamera_8->setGeometry(QRect(9, 18, 427, 179));
        groupCamera_8->setFont(font);
        groupCamera_8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        checkUseROI = new QCheckBox(groupCamera_8);
        checkUseROI->setObjectName(QString::fromUtf8("checkUseROI"));
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
        comboROIShape = new QComboBox(groupCamera_8);
        comboROIShape->addItem(QString());
        comboROIShape->addItem(QString());
        comboROIShape->setObjectName(QString::fromUtf8("comboROIShape"));
        comboROIShape->setGeometry(QRect(130, 35, 95, 30));
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
        btnAddROI = new QPushButton(groupCamera_8);
        btnAddROI->setObjectName(QString::fromUtf8("btnAddROI"));
        btnAddROI->setGeometry(QRect(270, 34, 66, 32));
        sizePolicy.setHeightForWidth(btnAddROI->sizePolicy().hasHeightForWidth());
        btnAddROI->setSizePolicy(sizePolicy);
        btnAddROI->setMinimumSize(QSize(60, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        btnAddROI->setFont(font4);
        btnAddROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        btnDeleteROI = new QPushButton(groupCamera_8);
        btnDeleteROI->setObjectName(QString::fromUtf8("btnDeleteROI"));
        btnDeleteROI->setGeometry(QRect(350, 34, 66, 32));
        btnDeleteROI->setMinimumSize(QSize(60, 30));
        btnDeleteROI->setFont(font4);
        btnDeleteROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));
        checkViewROI = new QCheckBox(groupCamera_8);
        checkViewROI->setObjectName(QString::fromUtf8("checkViewROI"));
        checkViewROI->setGeometry(QRect(13, 89, 93, 27));
        sizePolicy.setHeightForWidth(checkViewROI->sizePolicy().hasHeightForWidth());
        checkViewROI->setSizePolicy(sizePolicy);
        checkViewROI->setFont(font);
        checkViewROI->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkViewROI->setIconSize(QSize(22, 22));
        label_16 = new QLabel(groupCamera_8);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(183, 93, 79, 19));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_17 = new QLabel(groupCamera_8);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(13, 144, 79, 19));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        btnRoiColor = new QPushButton(groupCamera_8);
        btnRoiColor->setObjectName(QString::fromUtf8("btnRoiColor"));
        btnRoiColor->setGeometry(QRect(108, 140, 307, 27));
        btnRoiColor->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgba(0, 255, 0);"));
        spinRoiW = new QSpinBox(groupCamera_8);
        spinRoiW->setObjectName(QString::fromUtf8("spinRoiW"));
        spinRoiW->setGeometry(QRect(270, 89, 146, 27));
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
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(frmGetContourPointsClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmGetContourPointsClass);
    } // setupUi

    void retranslateUi(QDialog *frmGetContourPointsClass)
    {
        frmGetContourPointsClass->setWindowTitle(QCoreApplication::translate("frmGetContourPointsClass", "\350\216\267\345\217\226\350\276\271\347\225\214\347\202\271", nullptr));
        label_3->setText(QCoreApplication::translate("frmGetContourPointsClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmGetContourPointsClass", "\346\211\247\350\241\214", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmGetContourPointsClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmGetContourPointsClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmGetContourPointsClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmGetContourPointsClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupC2->setTitle(QCoreApplication::translate("frmGetContourPointsClass", "\350\276\223\345\205\245\345\217\202\346\225\260", nullptr));
        label_7->setText(QCoreApplication::translate("frmGetContourPointsClass", "\346\234\200\345\260\217\351\230\210\345\200\274\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinMaxThreshold->setToolTip(QCoreApplication::translate("frmGetContourPointsClass", "cv::Canny", nullptr));
#endif // QT_CONFIG(tooltip)
        label_8->setText(QCoreApplication::translate("frmGetContourPointsClass", "\346\234\200\345\244\247\351\230\210\345\200\274\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        spinMinThreshold->setToolTip(QCoreApplication::translate("frmGetContourPointsClass", "cv::Canny", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        spinSigma->setToolTip(QCoreApplication::translate("frmGetContourPointsClass", "cv::GaussianBlur", nullptr));
#endif // QT_CONFIG(tooltip)
        label_9->setText(QCoreApplication::translate("frmGetContourPointsClass", "Sigma\345\200\274\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("frmGetContourPointsClass", "\345\211\224\351\231\244\346\257\224\344\276\213\357\274\232", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmGetContourPointsClass", "\350\276\223\345\207\272\346\225\260\346\215\256(\347\202\271\351\233\206)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmGetContourPointsClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupCamera_8->setTitle(QCoreApplication::translate("frmGetContourPointsClass", "ROI\345\257\271\350\261\241", nullptr));
        checkUseROI->setText(QCoreApplication::translate("frmGetContourPointsClass", "\344\275\277\347\224\250ROI", nullptr));
        comboROIShape->setItemText(0, QCoreApplication::translate("frmGetContourPointsClass", "\347\237\251\345\275\242", nullptr));
        comboROIShape->setItemText(1, QCoreApplication::translate("frmGetContourPointsClass", "\345\234\206\345\275\242", nullptr));

        btnAddROI->setText(QCoreApplication::translate("frmGetContourPointsClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteROI->setText(QCoreApplication::translate("frmGetContourPointsClass", "\345\210\240\351\231\244", nullptr));
        checkViewROI->setText(QCoreApplication::translate("frmGetContourPointsClass", "\346\230\276\347\244\272ROI", nullptr));
        label_16->setText(QCoreApplication::translate("frmGetContourPointsClass", "ROI\345\256\275\345\272\246\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("frmGetContourPointsClass", "ROI\351\242\234\350\211\262\357\274\232", nullptr));
        btnRoiColor->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmGetContourPointsClass", "ROI\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmGetContourPointsClass: public Ui_frmGetContourPointsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMGETCONTOURPOINTS_H
