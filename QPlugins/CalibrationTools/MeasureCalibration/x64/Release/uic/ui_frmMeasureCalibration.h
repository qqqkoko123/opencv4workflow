/********************************************************************************
** Form generated from reading UI file 'frmMeasureCalibration.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMEASURECALIBRATION_H
#define UI_FRMMEASURECALIBRATION_H

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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmMeasureCalibrationClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QGroupBox *groupC2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QDoubleSpinBox *spinPixelX;
    QLabel *label_12;
    QLabel *label_9;
    QDoubleSpinBox *spinPixelY;
    QWidget *page_2;
    QLabel *label_18;
    QLabel *label_19;
    QComboBox *comboGrayDirection;
    QSpinBox *spinThreshold;
    QSpinBox *spinCullDistance;
    QSpinBox *spinSegment;
    QLabel *label_14;
    QLabel *label_10;
    QSpinBox *spinActualSize;
    QLabel *label_22;
    QLabel *label_23;
    QComboBox *comboXYDirection;
    QLabel *label_13;
    QComboBox *comboMode;
    QLabel *label_11;
    QGroupBox *groupC3;
    QTextEdit *txtMsg;
    QWidget *tab_2;
    QGroupBox *groupROI;
    QCheckBox *checkUseROI;
    QComboBox *comboROIShape;
    QPushButton *btnAddROI;
    QPushButton *btnDeleteROI;
    QSpinBox *spinCrossL;
    QLabel *label_20;
    QLabel *label_21;
    QSpinBox *spinRoiW;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *imageLayout;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmMeasureCalibrationClass)
    {
        if (frmMeasureCalibrationClass->objectName().isEmpty())
            frmMeasureCalibrationClass->setObjectName(QString::fromUtf8("frmMeasureCalibrationClass"));
        frmMeasureCalibrationClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmMeasureCalibrationClass->sizePolicy().hasHeightForWidth());
        frmMeasureCalibrationClass->setSizePolicy(sizePolicy);
        frmMeasureCalibrationClass->setMinimumSize(QSize(1160, 655));
        frmMeasureCalibrationClass->setMaximumSize(QSize(1160, 655));
        frmMeasureCalibrationClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmMeasureCalibrationClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frmMeasureCalibrationClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(450, 550));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
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
        txtLinkImage->setGeometry(QRect(95, 39, 260, 27));
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
        groupC2->setGeometry(QRect(9, 108, 427, 205));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        stackedWidget = new QStackedWidget(groupC2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(2, 64, 424, 139));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        spinPixelX = new QDoubleSpinBox(page);
        spinPixelX->setObjectName(QString::fromUtf8("spinPixelX"));
        spinPixelX->setGeometry(QRect(156, 28, 102, 27));
        sizePolicy.setHeightForWidth(spinPixelX->sizePolicy().hasHeightForWidth());
        spinPixelX->setSizePolicy(sizePolicy);
        spinPixelX->setMinimumSize(QSize(96, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        spinPixelX->setFont(font1);
        spinPixelX->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinPixelX->setAlignment(Qt::AlignCenter);
        spinPixelX->setDecimals(5);
        spinPixelX->setMinimum(0.000010000000000);
        spinPixelX->setMaximum(1.000000000000000);
        spinPixelX->setSingleStep(0.010000000000000);
        spinPixelX->setValue(0.010010000000000);
        label_12 = new QLabel(page);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(13, 88, 145, 19));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        label_9 = new QLabel(page);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(13, 32, 145, 19));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        spinPixelY = new QDoubleSpinBox(page);
        spinPixelY->setObjectName(QString::fromUtf8("spinPixelY"));
        spinPixelY->setGeometry(QRect(156, 84, 102, 27));
        sizePolicy.setHeightForWidth(spinPixelY->sizePolicy().hasHeightForWidth());
        spinPixelY->setSizePolicy(sizePolicy);
        spinPixelY->setMinimumSize(QSize(96, 25));
        spinPixelY->setFont(font1);
        spinPixelY->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinPixelY->setAlignment(Qt::AlignCenter);
        spinPixelY->setDecimals(5);
        spinPixelY->setMinimum(0.000010000000000);
        spinPixelY->setMaximum(1.000000000000000);
        spinPixelY->setSingleStep(0.010000000000000);
        spinPixelY->setValue(0.010010000000000);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_18 = new QLabel(page_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(13, 65, 81, 19));
        label_18->setFont(font2);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        label_19 = new QLabel(page_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(236, 65, 81, 19));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        comboGrayDirection = new QComboBox(page_2);
        comboGrayDirection->addItem(QString());
        comboGrayDirection->addItem(QString());
        comboGrayDirection->setObjectName(QString::fromUtf8("comboGrayDirection"));
        comboGrayDirection->setGeometry(QRect(95, 15, 97, 30));
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
        spinThreshold = new QSpinBox(page_2);
        spinThreshold->setObjectName(QString::fromUtf8("spinThreshold"));
        spinThreshold->setGeometry(QRect(318, 16, 98, 27));
        spinThreshold->setFont(font1);
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
        spinCullDistance = new QSpinBox(page_2);
        spinCullDistance->setObjectName(QString::fromUtf8("spinCullDistance"));
        spinCullDistance->setGeometry(QRect(318, 62, 98, 27));
        spinCullDistance->setFont(font1);
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
        spinSegment = new QSpinBox(page_2);
        spinSegment->setObjectName(QString::fromUtf8("spinSegment"));
        spinSegment->setGeometry(QRect(95, 62, 97, 27));
        spinSegment->setFont(font1);
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
        label_14 = new QLabel(page_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(236, 20, 81, 19));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(13, 20, 81, 19));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        spinActualSize = new QSpinBox(page_2);
        spinActualSize->setObjectName(QString::fromUtf8("spinActualSize"));
        spinActualSize->setGeometry(QRect(95, 106, 97, 27));
        spinActualSize->setFont(font1);
        spinActualSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinActualSize->setAlignment(Qt::AlignCenter);
        spinActualSize->setMinimum(1);
        spinActualSize->setMaximum(300);
        spinActualSize->setValue(10);
        label_22 = new QLabel(page_2);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(13, 109, 81, 19));
        label_22->setFont(font2);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        label_23 = new QLabel(page_2);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(193, 109, 35, 19));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        label_23->setFont(font3);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        comboXYDirection = new QComboBox(page_2);
        comboXYDirection->addItem(QString());
        comboXYDirection->addItem(QString());
        comboXYDirection->setObjectName(QString::fromUtf8("comboXYDirection"));
        comboXYDirection->setGeometry(QRect(318, 104, 98, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        comboXYDirection->setFont(font4);
        comboXYDirection->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(236, 109, 81, 19));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        stackedWidget->addWidget(page_2);
        comboMode = new QComboBox(groupC2);
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->setObjectName(QString::fromUtf8("comboMode"));
        comboMode->setGeometry(QRect(95, 32, 97, 30));
        comboMode->setFont(font);
        comboMode->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_11 = new QLabel(groupC2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(13, 37, 81, 19));
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        groupC3 = new QGroupBox(tab);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(9, 330, 427, 187));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC3);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 419, 151));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupROI = new QGroupBox(tab_2);
        groupROI->setObjectName(QString::fromUtf8("groupROI"));
        groupROI->setEnabled(false);
        groupROI->setGeometry(QRect(9, 18, 427, 128));
        groupROI->setFont(font);
        groupROI->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        checkUseROI = new QCheckBox(groupROI);
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
        comboROIShape = new QComboBox(groupROI);
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
        btnAddROI = new QPushButton(groupROI);
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
        btnDeleteROI = new QPushButton(groupROI);
        btnDeleteROI->setObjectName(QString::fromUtf8("btnDeleteROI"));
        btnDeleteROI->setGeometry(QRect(350, 34, 66, 32));
        btnDeleteROI->setMinimumSize(QSize(60, 30));
        btnDeleteROI->setFont(font4);
        btnDeleteROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));
        spinCrossL = new QSpinBox(groupROI);
        spinCrossL->setObjectName(QString::fromUtf8("spinCrossL"));
        spinCrossL->setGeometry(QRect(335, 92, 80, 27));
        spinCrossL->setFont(font1);
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
        label_20 = new QLabel(groupROI);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(13, 96, 79, 19));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_21 = new QLabel(groupROI);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(234, 96, 95, 19));
        label_21->setFont(font);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinRoiW = new QSpinBox(groupROI);
        spinRoiW->setObjectName(QString::fromUtf8("spinRoiW"));
        spinRoiW->setGeometry(QRect(93, 92, 80, 27));
        spinRoiW->setFont(font1);
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmMeasureCalibrationClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmMeasureCalibrationClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmMeasureCalibrationClass);
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

        imageLayout = new QGridLayout();
        imageLayout->setSpacing(1);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));

        gridLayout->addLayout(imageLayout, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        retranslateUi(frmMeasureCalibrationClass);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmMeasureCalibrationClass);
    } // setupUi

    void retranslateUi(QDialog *frmMeasureCalibrationClass)
    {
        frmMeasureCalibrationClass->setWindowTitle(QCoreApplication::translate("frmMeasureCalibrationClass", "\346\265\213\351\207\217\346\240\207\345\256\232", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmMeasureCalibrationClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmMeasureCalibrationClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmMeasureCalibrationClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupC2->setTitle(QCoreApplication::translate("frmMeasureCalibrationClass", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_12->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "Y\346\226\271\345\220\221\347\232\204\345\203\217\347\264\240\345\275\223\351\207\217\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "X\346\226\271\345\220\221\347\232\204\345\203\217\347\264\240\345\275\223\351\207\217\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\345\210\206\345\211\262\346\225\260\351\207\217\357\274\232", nullptr));
        label_19->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\345\211\224\351\231\244\350\267\235\347\246\273\357\274\232", nullptr));
        comboGrayDirection->setItemText(0, QCoreApplication::translate("frmMeasureCalibrationClass", "\347\231\275\345\210\260\351\273\221", nullptr));
        comboGrayDirection->setItemText(1, QCoreApplication::translate("frmMeasureCalibrationClass", "\351\273\221\345\210\260\347\231\275", nullptr));

        label_14->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\350\276\271\347\274\230\345\274\272\345\272\246\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\347\201\260\345\272\246\346\226\271\345\220\221\357\274\232", nullptr));
        label_22->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\345\256\236\351\231\205\345\260\272\345\257\270\357\274\232", nullptr));
        label_23->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "mm", nullptr));
        comboXYDirection->setItemText(0, QCoreApplication::translate("frmMeasureCalibrationClass", "X\346\226\271\345\220\221\345\203\217\347\264\240", nullptr));
        comboXYDirection->setItemText(1, QCoreApplication::translate("frmMeasureCalibrationClass", "Y\346\226\271\345\220\221\345\203\217\347\264\240", nullptr));

        label_13->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\346\265\213\351\207\217\346\226\271\345\220\221\357\274\232", nullptr));
        comboMode->setItemText(0, QCoreApplication::translate("frmMeasureCalibrationClass", "\346\257\224\344\276\213\346\250\241\345\274\217", nullptr));
        comboMode->setItemText(1, QCoreApplication::translate("frmMeasureCalibrationClass", "\346\265\213\351\207\217\346\250\241\345\274\217", nullptr));

        label_11->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\346\240\207\345\256\232\346\250\241\345\274\217\357\274\232", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmMeasureCalibrationClass", "\350\276\223\345\207\272\346\225\260\346\215\256(\345\203\217\347\264\240\345\275\223\351\207\217)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmMeasureCalibrationClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupROI->setTitle(QCoreApplication::translate("frmMeasureCalibrationClass", "ROI\345\257\271\350\261\241", nullptr));
        checkUseROI->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\344\275\277\347\224\250ROI", nullptr));
        comboROIShape->setItemText(0, QCoreApplication::translate("frmMeasureCalibrationClass", "\345\215\241\345\260\272", nullptr));

        btnAddROI->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteROI->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\345\210\240\351\231\244", nullptr));
        label_20->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "ROI\345\256\275\345\272\246\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\344\272\244\345\217\211\347\272\277\351\225\277\345\272\246\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmMeasureCalibrationClass", "ROI\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmMeasureCalibrationClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmMeasureCalibrationClass: public Ui_frmMeasureCalibrationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMEASURECALIBRATION_H
