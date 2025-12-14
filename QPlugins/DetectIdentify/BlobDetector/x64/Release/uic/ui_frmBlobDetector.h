/********************************************************************************
** Form generated from reading UI file 'frmBlobDetector.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMBLOBDETECTOR_H
#define UI_FRMBLOBDETECTOR_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmBlobDetectorClass
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
    QGroupBox *groupCamera_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkArea;
    QCheckBox *checkGrayscale;
    QCheckBox *checkCircularity;
    QCheckBox *checkConvexity;
    QCheckBox *checkInertia;
    QGroupBox *groupCamera_3;
    QLabel *label_5;
    QLabel *label_6;
    QSpinBox *spinMinArea;
    QSpinBox *spinMaxArea;
    QGroupBox *groupCamera_4;
    QLabel *label_7;
    QSpinBox *spinMaxThreshold;
    QLabel *label_8;
    QSpinBox *spinMinThreshold;
    QLabel *label_15;
    QComboBox *comboColor;
    QGroupBox *groupCamera_5;
    QDoubleSpinBox *spinMinCircularity;
    QLabel *label_9;
    QLabel *label_10;
    QDoubleSpinBox *spinMaxCircularity;
    QGroupBox *groupCamera_6;
    QLabel *label_11;
    QDoubleSpinBox *spinMinConvexity;
    QLabel *label_12;
    QDoubleSpinBox *spinMaxConvexity;
    QGroupBox *groupCamera_7;
    QLabel *label_13;
    QDoubleSpinBox *spinMinInertia;
    QLabel *label_14;
    QDoubleSpinBox *spinMaxInertia;
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

    void setupUi(QDialog *frmBlobDetectorClass)
    {
        if (frmBlobDetectorClass->objectName().isEmpty())
            frmBlobDetectorClass->setObjectName(QString::fromUtf8("frmBlobDetectorClass"));
        frmBlobDetectorClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmBlobDetectorClass->sizePolicy().hasHeightForWidth());
        frmBlobDetectorClass->setSizePolicy(sizePolicy);
        frmBlobDetectorClass->setMinimumSize(QSize(1160, 655));
        frmBlobDetectorClass->setMaximumSize(QSize(1160, 655));
        frmBlobDetectorClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmBlobDetectorClass);
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

        label_3 = new QLabel(frmBlobDetectorClass);
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

        txtDescribe = new QLineEdit(frmBlobDetectorClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmBlobDetectorClass);
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

        tabWidget = new QTabWidget(frmBlobDetectorClass);
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
        groupCamera->setGeometry(QRect(9, 12, 427, 73));
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
        groupCamera_2 = new QGroupBox(tab);
        groupCamera_2->setObjectName(QString::fromUtf8("groupCamera_2"));
        groupCamera_2->setGeometry(QRect(9, 94, 427, 73));
        groupCamera_2->setFont(font);
        groupCamera_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        horizontalLayoutWidget = new QWidget(groupCamera_2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 34, 412, 29));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(22);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkArea = new QCheckBox(horizontalLayoutWidget);
        checkArea->setObjectName(QString::fromUtf8("checkArea"));
        sizePolicy.setHeightForWidth(checkArea->sizePolicy().hasHeightForWidth());
        checkArea->setSizePolicy(sizePolicy);
        checkArea->setFont(font);
        checkArea->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkArea->setIconSize(QSize(22, 22));

        horizontalLayout_2->addWidget(checkArea);

        checkGrayscale = new QCheckBox(horizontalLayoutWidget);
        checkGrayscale->setObjectName(QString::fromUtf8("checkGrayscale"));
        sizePolicy.setHeightForWidth(checkGrayscale->sizePolicy().hasHeightForWidth());
        checkGrayscale->setSizePolicy(sizePolicy);
        checkGrayscale->setFont(font);
        checkGrayscale->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkGrayscale->setIconSize(QSize(22, 22));

        horizontalLayout_2->addWidget(checkGrayscale);

        checkCircularity = new QCheckBox(horizontalLayoutWidget);
        checkCircularity->setObjectName(QString::fromUtf8("checkCircularity"));
        sizePolicy.setHeightForWidth(checkCircularity->sizePolicy().hasHeightForWidth());
        checkCircularity->setSizePolicy(sizePolicy);
        checkCircularity->setFont(font);
        checkCircularity->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkCircularity->setIconSize(QSize(22, 22));

        horizontalLayout_2->addWidget(checkCircularity);

        checkConvexity = new QCheckBox(horizontalLayoutWidget);
        checkConvexity->setObjectName(QString::fromUtf8("checkConvexity"));
        sizePolicy.setHeightForWidth(checkConvexity->sizePolicy().hasHeightForWidth());
        checkConvexity->setSizePolicy(sizePolicy);
        checkConvexity->setFont(font);
        checkConvexity->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkConvexity->setIconSize(QSize(22, 22));

        horizontalLayout_2->addWidget(checkConvexity);

        checkInertia = new QCheckBox(horizontalLayoutWidget);
        checkInertia->setObjectName(QString::fromUtf8("checkInertia"));
        sizePolicy.setHeightForWidth(checkInertia->sizePolicy().hasHeightForWidth());
        checkInertia->setSizePolicy(sizePolicy);
        checkInertia->setFont(font);
        checkInertia->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkInertia->setIconSize(QSize(22, 22));

        horizontalLayout_2->addWidget(checkInertia);

        groupCamera_3 = new QGroupBox(tab);
        groupCamera_3->setObjectName(QString::fromUtf8("groupCamera_3"));
        groupCamera_3->setGeometry(QRect(9, 176, 427, 60));
        groupCamera_3->setFont(font);
        groupCamera_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_5 = new QLabel(groupCamera_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(26, 32, 79, 19));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_6 = new QLabel(groupCamera_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(236, 32, 79, 19));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinArea = new QSpinBox(groupCamera_3);
        spinMinArea->setObjectName(QString::fromUtf8("spinMinArea"));
        spinMinArea->setGeometry(QRect(108, 28, 100, 27));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        spinMinArea->setFont(font2);
        spinMinArea->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinArea->setAlignment(Qt::AlignCenter);
        spinMinArea->setMinimum(0);
        spinMinArea->setMaximum(100000);
        spinMinArea->setValue(100);
        spinMaxArea = new QSpinBox(groupCamera_3);
        spinMaxArea->setObjectName(QString::fromUtf8("spinMaxArea"));
        spinMaxArea->setGeometry(QRect(318, 28, 100, 27));
        spinMaxArea->setFont(font2);
        spinMaxArea->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxArea->setAlignment(Qt::AlignCenter);
        spinMaxArea->setMinimum(1);
        spinMaxArea->setMaximum(999999);
        spinMaxArea->setValue(1000);
        groupCamera_4 = new QGroupBox(tab);
        groupCamera_4->setObjectName(QString::fromUtf8("groupCamera_4"));
        groupCamera_4->setGeometry(QRect(9, 246, 427, 60));
        groupCamera_4->setFont(font);
        groupCamera_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_7 = new QLabel(groupCamera_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(26, 32, 79, 19));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxThreshold = new QSpinBox(groupCamera_4);
        spinMaxThreshold->setObjectName(QString::fromUtf8("spinMaxThreshold"));
        spinMaxThreshold->setGeometry(QRect(238, 28, 60, 26));
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
        spinMaxThreshold->setValue(100);
        label_8 = new QLabel(groupCamera_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(168, 32, 73, 19));
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinThreshold = new QSpinBox(groupCamera_4);
        spinMinThreshold->setObjectName(QString::fromUtf8("spinMinThreshold"));
        spinMinThreshold->setGeometry(QRect(96, 28, 60, 27));
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
        spinMinThreshold->setValue(0);
        label_15 = new QLabel(groupCamera_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(313, 32, 47, 19));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        label_15->setFont(font4);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboColor = new QComboBox(groupCamera_4);
        comboColor->addItem(QString());
        comboColor->addItem(QString());
        comboColor->setObjectName(QString::fromUtf8("comboColor"));
        comboColor->setGeometry(QRect(353, 28, 65, 27));
        comboColor->setFont(font);
        comboColor->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 3em;\n"
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
        label_8->raise();
        label_7->raise();
        spinMaxThreshold->raise();
        spinMinThreshold->raise();
        label_15->raise();
        comboColor->raise();
        groupCamera_5 = new QGroupBox(tab);
        groupCamera_5->setObjectName(QString::fromUtf8("groupCamera_5"));
        groupCamera_5->setGeometry(QRect(9, 316, 427, 60));
        groupCamera_5->setFont(font);
        groupCamera_5->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        spinMinCircularity = new QDoubleSpinBox(groupCamera_5);
        spinMinCircularity->setObjectName(QString::fromUtf8("spinMinCircularity"));
        spinMinCircularity->setGeometry(QRect(108, 28, 100, 27));
        sizePolicy.setHeightForWidth(spinMinCircularity->sizePolicy().hasHeightForWidth());
        spinMinCircularity->setSizePolicy(sizePolicy);
        spinMinCircularity->setMinimumSize(QSize(100, 25));
        spinMinCircularity->setFont(font2);
        spinMinCircularity->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinCircularity->setAlignment(Qt::AlignCenter);
        spinMinCircularity->setDecimals(2);
        spinMinCircularity->setMaximum(0.990000000000000);
        spinMinCircularity->setSingleStep(0.100000000000000);
        spinMinCircularity->setValue(0.750000000000000);
        label_9 = new QLabel(groupCamera_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(26, 32, 79, 19));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_10 = new QLabel(groupCamera_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(236, 32, 79, 19));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxCircularity = new QDoubleSpinBox(groupCamera_5);
        spinMaxCircularity->setObjectName(QString::fromUtf8("spinMaxCircularity"));
        spinMaxCircularity->setGeometry(QRect(318, 28, 100, 27));
        sizePolicy.setHeightForWidth(spinMaxCircularity->sizePolicy().hasHeightForWidth());
        spinMaxCircularity->setSizePolicy(sizePolicy);
        spinMaxCircularity->setMinimumSize(QSize(100, 25));
        spinMaxCircularity->setFont(font2);
        spinMaxCircularity->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxCircularity->setAlignment(Qt::AlignCenter);
        spinMaxCircularity->setDecimals(2);
        spinMaxCircularity->setMinimum(0.010000000000000);
        spinMaxCircularity->setMaximum(1.000000000000000);
        spinMaxCircularity->setSingleStep(0.100000000000000);
        spinMaxCircularity->setValue(1.000000000000000);
        groupCamera_6 = new QGroupBox(tab);
        groupCamera_6->setObjectName(QString::fromUtf8("groupCamera_6"));
        groupCamera_6->setGeometry(QRect(8, 386, 427, 60));
        groupCamera_6->setFont(font);
        groupCamera_6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_11 = new QLabel(groupCamera_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(26, 32, 79, 19));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinConvexity = new QDoubleSpinBox(groupCamera_6);
        spinMinConvexity->setObjectName(QString::fromUtf8("spinMinConvexity"));
        spinMinConvexity->setGeometry(QRect(108, 28, 100, 27));
        sizePolicy.setHeightForWidth(spinMinConvexity->sizePolicy().hasHeightForWidth());
        spinMinConvexity->setSizePolicy(sizePolicy);
        spinMinConvexity->setMinimumSize(QSize(100, 25));
        spinMinConvexity->setFont(font2);
        spinMinConvexity->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinConvexity->setAlignment(Qt::AlignCenter);
        spinMinConvexity->setDecimals(2);
        spinMinConvexity->setMaximum(0.990000000000000);
        spinMinConvexity->setSingleStep(0.100000000000000);
        spinMinConvexity->setValue(0.750000000000000);
        label_12 = new QLabel(groupCamera_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(236, 32, 79, 19));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxConvexity = new QDoubleSpinBox(groupCamera_6);
        spinMaxConvexity->setObjectName(QString::fromUtf8("spinMaxConvexity"));
        spinMaxConvexity->setGeometry(QRect(318, 28, 100, 27));
        sizePolicy.setHeightForWidth(spinMaxConvexity->sizePolicy().hasHeightForWidth());
        spinMaxConvexity->setSizePolicy(sizePolicy);
        spinMaxConvexity->setMinimumSize(QSize(100, 25));
        spinMaxConvexity->setFont(font2);
        spinMaxConvexity->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxConvexity->setAlignment(Qt::AlignCenter);
        spinMaxConvexity->setDecimals(2);
        spinMaxConvexity->setMinimum(0.010000000000000);
        spinMaxConvexity->setMaximum(1.000000000000000);
        spinMaxConvexity->setSingleStep(0.100000000000000);
        spinMaxConvexity->setValue(1.000000000000000);
        groupCamera_7 = new QGroupBox(tab);
        groupCamera_7->setObjectName(QString::fromUtf8("groupCamera_7"));
        groupCamera_7->setGeometry(QRect(9, 456, 427, 60));
        groupCamera_7->setFont(font);
        groupCamera_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_13 = new QLabel(groupCamera_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(26, 32, 79, 19));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinInertia = new QDoubleSpinBox(groupCamera_7);
        spinMinInertia->setObjectName(QString::fromUtf8("spinMinInertia"));
        spinMinInertia->setGeometry(QRect(108, 28, 100, 27));
        sizePolicy.setHeightForWidth(spinMinInertia->sizePolicy().hasHeightForWidth());
        spinMinInertia->setSizePolicy(sizePolicy);
        spinMinInertia->setMinimumSize(QSize(100, 25));
        spinMinInertia->setFont(font2);
        spinMinInertia->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinInertia->setAlignment(Qt::AlignCenter);
        spinMinInertia->setDecimals(2);
        spinMinInertia->setMaximum(0.990000000000000);
        spinMinInertia->setSingleStep(0.100000000000000);
        spinMinInertia->setValue(0.050000000000000);
        label_14 = new QLabel(groupCamera_7);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(236, 32, 79, 19));
        label_14->setFont(font1);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxInertia = new QDoubleSpinBox(groupCamera_7);
        spinMaxInertia->setObjectName(QString::fromUtf8("spinMaxInertia"));
        spinMaxInertia->setGeometry(QRect(318, 28, 100, 27));
        sizePolicy.setHeightForWidth(spinMaxInertia->sizePolicy().hasHeightForWidth());
        spinMaxInertia->setSizePolicy(sizePolicy);
        spinMaxInertia->setMinimumSize(QSize(100, 25));
        spinMaxInertia->setFont(font2);
        spinMaxInertia->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxInertia->setAlignment(Qt::AlignCenter);
        spinMaxInertia->setDecimals(2);
        spinMaxInertia->setMinimum(0.010000000000000);
        spinMaxInertia->setMaximum(1.000000000000000);
        spinMaxInertia->setSingleStep(0.100000000000000);
        spinMaxInertia->setValue(0.250000000000000);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupCamera_8 = new QGroupBox(tab_2);
        groupCamera_8->setObjectName(QString::fromUtf8("groupCamera_8"));
        groupCamera_8->setGeometry(QRect(9, 12, 427, 179));
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


        retranslateUi(frmBlobDetectorClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmBlobDetectorClass);
    } // setupUi

    void retranslateUi(QDialog *frmBlobDetectorClass)
    {
        frmBlobDetectorClass->setWindowTitle(QCoreApplication::translate("frmBlobDetectorClass", "\346\226\221\347\202\271\345\210\206\346\236\220", nullptr));
        label_3->setText(QCoreApplication::translate("frmBlobDetectorClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\211\247\350\241\214", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmBlobDetectorClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmBlobDetectorClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmBlobDetectorClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmBlobDetectorClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupCamera_2->setTitle(QCoreApplication::translate("frmBlobDetectorClass", "\346\243\200\346\265\213\346\235\241\344\273\266", nullptr));
        checkArea->setText(QCoreApplication::translate("frmBlobDetectorClass", "\351\235\242\347\247\257", nullptr));
        checkGrayscale->setText(QCoreApplication::translate("frmBlobDetectorClass", "\347\201\260\345\272\246\345\200\274", nullptr));
        checkCircularity->setText(QCoreApplication::translate("frmBlobDetectorClass", "\345\234\206\345\272\246", nullptr));
        checkConvexity->setText(QCoreApplication::translate("frmBlobDetectorClass", "\345\207\270\345\272\246", nullptr));
        checkInertia->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\203\257\346\200\247", nullptr));
        groupCamera_3->setTitle(QCoreApplication::translate("frmBlobDetectorClass", "\351\235\242\347\247\257", nullptr));
        label_5->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\234\200\345\260\217\351\235\242\347\247\257\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\234\200\345\244\247\351\235\242\347\247\257\357\274\232", nullptr));
        groupCamera_4->setTitle(QCoreApplication::translate("frmBlobDetectorClass", "\347\201\260\345\272\246\345\200\274", nullptr));
        label_7->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\234\200\345\260\217\351\230\210\345\200\274\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\234\200\345\244\247\351\230\210\345\200\274\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("frmBlobDetectorClass", "\351\242\234\350\211\262\357\274\232", nullptr));
        comboColor->setItemText(0, QCoreApplication::translate("frmBlobDetectorClass", "\351\273\221\350\211\262", nullptr));
        comboColor->setItemText(1, QCoreApplication::translate("frmBlobDetectorClass", "\347\231\275\350\211\262", nullptr));

        groupCamera_5->setTitle(QCoreApplication::translate("frmBlobDetectorClass", "\345\234\206\345\272\246", nullptr));
        label_9->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\234\200\345\260\217\345\234\206\345\272\246\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\234\200\345\244\247\345\234\206\345\272\246\357\274\232", nullptr));
        groupCamera_6->setTitle(QCoreApplication::translate("frmBlobDetectorClass", "\345\207\270\345\272\246", nullptr));
        label_11->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\234\200\345\260\217\345\207\270\345\272\246\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\234\200\345\244\247\345\207\270\345\272\246\357\274\232", nullptr));
        groupCamera_7->setTitle(QCoreApplication::translate("frmBlobDetectorClass", "\346\203\257\346\200\247", nullptr));
        label_13->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\234\200\345\260\217\346\203\257\346\200\247\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\234\200\345\244\247\346\203\257\346\200\247\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmBlobDetectorClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupCamera_8->setTitle(QCoreApplication::translate("frmBlobDetectorClass", "ROI\345\257\271\350\261\241", nullptr));
        checkUseROI->setText(QCoreApplication::translate("frmBlobDetectorClass", "\344\275\277\347\224\250ROI", nullptr));
        comboROIShape->setItemText(0, QCoreApplication::translate("frmBlobDetectorClass", "\347\237\251\345\275\242", nullptr));
        comboROIShape->setItemText(1, QCoreApplication::translate("frmBlobDetectorClass", "\346\227\213\350\275\254\347\237\251\345\275\242", nullptr));
        comboROIShape->setItemText(2, QCoreApplication::translate("frmBlobDetectorClass", "\345\234\206\345\275\242", nullptr));
        comboROIShape->setItemText(3, QCoreApplication::translate("frmBlobDetectorClass", "\345\244\232\350\276\271\345\275\242", nullptr));

        btnAddROI->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteROI->setText(QCoreApplication::translate("frmBlobDetectorClass", "\345\210\240\351\231\244", nullptr));
        checkViewROI->setText(QCoreApplication::translate("frmBlobDetectorClass", "\346\230\276\347\244\272ROI", nullptr));
        label_16->setText(QCoreApplication::translate("frmBlobDetectorClass", "ROI\345\256\275\345\272\246\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("frmBlobDetectorClass", "ROI\351\242\234\350\211\262\357\274\232", nullptr));
        btnRoiColor->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmBlobDetectorClass", "ROI\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmBlobDetectorClass: public Ui_frmBlobDetectorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMBLOBDETECTOR_H
