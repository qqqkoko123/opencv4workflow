/********************************************************************************
** Form generated from reading UI file 'frmDistortionCalibration.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDISTORTIONCALIBRATION_H
#define UI_FRMDISTORTIONCALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_frmDistortionCalibrationClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
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
    QPushButton *btnSelectPath;
    QLabel *label_2;
    QLineEdit *txtFolderPath;
    QGroupBox *groupC2;
    QComboBox *comboType;
    QLabel *label_5;
    QLabel *label_30;
    QSpinBox *spinCornersNx;
    QLabel *label_4;
    QLineEdit *txtFolderParamPath;
    QPushButton *btnStoragePath;
    QLabel *label_6;
    QSpinBox *spinCornersNy;
    QLabel *label_7;
    QSpinBox *spinCircleD;
    QLabel *label_8;
    QSpinBox *spinMinArea;
    QSpinBox *spinMaxArea;
    QLabel *label_9;
    QLabel *label_10;
    QDoubleSpinBox *spinMinCircularity;
    QLabel *label_11;
    QDoubleSpinBox *spinMaxCircularity;
    QGroupBox *groupCamera_3;
    QPushButton *btnBlobParam;
    QPushButton *btnCorrectedImage;
    QWidget *tab_2;
    QGroupBox *groupC3;
    QTextEdit *txtMsg;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmDistortionCalibrationClass)
    {
        if (frmDistortionCalibrationClass->objectName().isEmpty())
            frmDistortionCalibrationClass->setObjectName(QString::fromUtf8("frmDistortionCalibrationClass"));
        frmDistortionCalibrationClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmDistortionCalibrationClass->sizePolicy().hasHeightForWidth());
        frmDistortionCalibrationClass->setSizePolicy(sizePolicy);
        frmDistortionCalibrationClass->setMinimumSize(QSize(1160, 655));
        frmDistortionCalibrationClass->setMaximumSize(QSize(1160, 655));
        frmDistortionCalibrationClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmDistortionCalibrationClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

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

        label_3 = new QLabel(frmDistortionCalibrationClass);
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

        txtDescribe = new QLineEdit(frmDistortionCalibrationClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmDistortionCalibrationClass);
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

        tabWidget = new QTabWidget(frmDistortionCalibrationClass);
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
        groupCamera->setGeometry(QRect(9, 12, 427, 111));
        groupCamera->setFont(font);
        groupCamera->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnSelectPath = new QPushButton(groupCamera);
        btnSelectPath->setObjectName(QString::fromUtf8("btnSelectPath"));
        btnSelectPath->setGeometry(QRect(328, 70, 93, 35));
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
        label_2->setGeometry(QRect(6, 36, 97, 19));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtFolderPath = new QLineEdit(groupCamera);
        txtFolderPath->setObjectName(QString::fromUtf8("txtFolderPath"));
        txtFolderPath->setGeometry(QRect(104, 32, 316, 27));
        txtFolderPath->setFont(font);
        txtFolderPath->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtFolderPath->setReadOnly(true);
        groupC2 = new QGroupBox(tab);
        groupC2->setObjectName(QString::fromUtf8("groupC2"));
        groupC2->setGeometry(QRect(9, 136, 427, 303));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        comboType = new QComboBox(groupC2);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName(QString::fromUtf8("comboType"));
        comboType->setGeometry(QRect(144, 32, 115, 30));
        sizePolicy.setHeightForWidth(comboType->sizePolicy().hasHeightForWidth());
        comboType->setSizePolicy(sizePolicy);
        comboType->setMinimumSize(QSize(115, 30));
        comboType->setMaximumSize(QSize(115, 16777215));
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
        label_5 = new QLabel(groupC2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 85, 107, 19));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_30 = new QLabel(groupC2);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(13, 37, 133, 19));
        label_30->setFont(font);
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinCornersNx = new QSpinBox(groupC2);
        spinCornersNx->setObjectName(QString::fromUtf8("spinCornersNx"));
        spinCornersNx->setGeometry(QRect(120, 81, 73, 27));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        spinCornersNx->setFont(font3);
        spinCornersNx->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinCornersNx->setAlignment(Qt::AlignCenter);
        spinCornersNx->setMinimum(3);
        spinCornersNx->setMaximum(21);
        spinCornersNx->setValue(7);
        label_4 = new QLabel(groupC2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 228, 115, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtFolderParamPath = new QLineEdit(groupC2);
        txtFolderParamPath->setObjectName(QString::fromUtf8("txtFolderParamPath"));
        txtFolderParamPath->setGeometry(QRect(128, 224, 292, 27));
        txtFolderParamPath->setFont(font);
        txtFolderParamPath->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtFolderParamPath->setReadOnly(true);
        btnStoragePath = new QPushButton(groupC2);
        btnStoragePath->setObjectName(QString::fromUtf8("btnStoragePath"));
        btnStoragePath->setGeometry(QRect(328, 262, 93, 35));
        btnStoragePath->setFont(font1);
        btnStoragePath->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        label_6 = new QLabel(groupC2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(239, 85, 107, 19));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinCornersNy = new QSpinBox(groupC2);
        spinCornersNy->setObjectName(QString::fromUtf8("spinCornersNy"));
        spinCornersNy->setGeometry(QRect(346, 81, 73, 27));
        spinCornersNy->setFont(font3);
        spinCornersNy->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinCornersNy->setAlignment(Qt::AlignCenter);
        spinCornersNy->setMinimum(3);
        spinCornersNy->setMaximum(21);
        spinCornersNy->setValue(7);
        label_7 = new QLabel(groupC2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(283, 37, 63, 19));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinCircleD = new QSpinBox(groupC2);
        spinCircleD->setObjectName(QString::fromUtf8("spinCircleD"));
        spinCircleD->setGeometry(QRect(346, 33, 73, 27));
        spinCircleD->setFont(font3);
        spinCircleD->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinCircleD->setAlignment(Qt::AlignCenter);
        spinCircleD->setMinimum(3);
        spinCircleD->setMaximum(200);
        spinCircleD->setValue(25);
        label_8 = new QLabel(groupC2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(239, 133, 93, 19));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinArea = new QSpinBox(groupC2);
        spinMinArea->setObjectName(QString::fromUtf8("spinMinArea"));
        spinMinArea->setGeometry(QRect(110, 129, 83, 27));
        spinMinArea->setFont(font3);
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
        spinMaxArea = new QSpinBox(groupC2);
        spinMaxArea->setObjectName(QString::fromUtf8("spinMaxArea"));
        spinMaxArea->setGeometry(QRect(336, 129, 83, 27));
        spinMaxArea->setFont(font3);
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
        spinMaxArea->setMaximum(99999);
        spinMaxArea->setValue(1000);
        label_9 = new QLabel(groupC2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(13, 133, 93, 19));
        label_9->setFont(font2);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_10 = new QLabel(groupC2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(13, 178, 79, 19));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinCircularity = new QDoubleSpinBox(groupC2);
        spinMinCircularity->setObjectName(QString::fromUtf8("spinMinCircularity"));
        spinMinCircularity->setGeometry(QRect(110, 175, 83, 27));
        sizePolicy.setHeightForWidth(spinMinCircularity->sizePolicy().hasHeightForWidth());
        spinMinCircularity->setSizePolicy(sizePolicy);
        spinMinCircularity->setMinimumSize(QSize(83, 25));
        spinMinCircularity->setFont(font3);
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
        label_11 = new QLabel(groupC2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(239, 178, 79, 19));
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxCircularity = new QDoubleSpinBox(groupC2);
        spinMaxCircularity->setObjectName(QString::fromUtf8("spinMaxCircularity"));
        spinMaxCircularity->setGeometry(QRect(336, 175, 83, 27));
        sizePolicy.setHeightForWidth(spinMaxCircularity->sizePolicy().hasHeightForWidth());
        spinMaxCircularity->setSizePolicy(sizePolicy);
        spinMaxCircularity->setMinimumSize(QSize(83, 25));
        spinMaxCircularity->setFont(font3);
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
        label_30->raise();
        comboType->raise();
        label_5->raise();
        spinCornersNx->raise();
        label_4->raise();
        txtFolderParamPath->raise();
        btnStoragePath->raise();
        label_6->raise();
        spinCornersNy->raise();
        label_7->raise();
        spinCircleD->raise();
        label_8->raise();
        spinMinArea->raise();
        spinMaxArea->raise();
        label_9->raise();
        label_10->raise();
        spinMinCircularity->raise();
        label_11->raise();
        spinMaxCircularity->raise();
        groupCamera_3 = new QGroupBox(tab);
        groupCamera_3->setObjectName(QString::fromUtf8("groupCamera_3"));
        groupCamera_3->setGeometry(QRect(9, 452, 427, 67));
        groupCamera_3->setFont(font);
        groupCamera_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnBlobParam = new QPushButton(groupCamera_3);
        btnBlobParam->setObjectName(QString::fromUtf8("btnBlobParam"));
        btnBlobParam->setGeometry(QRect(88, 27, 85, 35));
        sizePolicy.setHeightForWidth(btnBlobParam->sizePolicy().hasHeightForWidth());
        btnBlobParam->setSizePolicy(sizePolicy);
        btnBlobParam->setMinimumSize(QSize(60, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        btnBlobParam->setFont(font4);
        btnBlobParam->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        btnCorrectedImage = new QPushButton(groupCamera_3);
        btnCorrectedImage->setObjectName(QString::fromUtf8("btnCorrectedImage"));
        btnCorrectedImage->setGeometry(QRect(336, 27, 85, 35));
        sizePolicy.setHeightForWidth(btnCorrectedImage->sizePolicy().hasHeightForWidth());
        btnCorrectedImage->setSizePolicy(sizePolicy);
        btnCorrectedImage->setMinimumSize(QSize(60, 30));
        btnCorrectedImage->setFont(font4);
        btnCorrectedImage->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupC3 = new QGroupBox(tab_2);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(9, 12, 427, 507));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC3);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 419, 471));
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
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        retranslateUi(frmDistortionCalibrationClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmDistortionCalibrationClass);
    } // setupUi

    void retranslateUi(QDialog *frmDistortionCalibrationClass)
    {
        frmDistortionCalibrationClass->setWindowTitle(QCoreApplication::translate("frmDistortionCalibrationClass", "\347\225\270\345\217\230\346\240\207\345\256\232", nullptr));
        label_3->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\346\211\247\350\241\214", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmDistortionCalibrationClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        btnSelectPath->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\350\267\257\345\276\204\351\200\211\346\213\251", nullptr));
        label_2->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\346\226\207\344\273\266\345\244\271\350\267\257\345\276\204\357\274\232", nullptr));
        txtFolderPath->setText(QString());
        groupC2->setTitle(QCoreApplication::translate("frmDistortionCalibrationClass", "\347\225\270\345\217\230\345\217\202\346\225\260", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("frmDistortionCalibrationClass", "\345\257\271\347\247\260\345\234\206\347\202\271", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("frmDistortionCalibrationClass", "\351\235\236\345\257\271\347\247\260\345\234\206\347\202\271", nullptr));

        label_5->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "X\346\226\271\345\220\221\345\234\206\347\202\271\346\225\260\357\274\232", nullptr));
        label_30->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\345\234\206\345\275\242\346\240\207\345\256\232\347\211\210\347\261\273\345\236\213\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\346\240\207\345\256\232\346\226\207\344\273\266\344\277\235\345\255\230\357\274\232", nullptr));
        txtFolderParamPath->setText(QString());
        btnStoragePath->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\350\267\257\345\276\204\351\200\211\346\213\251", nullptr));
        label_6->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "Y\346\226\271\345\220\221\345\234\206\347\202\271\346\225\260\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\345\234\206\347\233\264\345\276\204\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\345\234\206\346\234\200\345\244\247\351\235\242\347\247\257\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\345\234\206\346\234\200\345\260\217\351\235\242\347\247\257\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\346\234\200\345\260\217\345\234\206\345\272\246\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\346\234\200\345\244\247\345\234\206\345\272\246\357\274\232", nullptr));
        groupCamera_3->setTitle(QCoreApplication::translate("frmDistortionCalibrationClass", "\345\217\202\346\225\260\350\260\203\350\257\225", nullptr));
        btnBlobParam->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "Blob\345\217\202\346\225\260", nullptr));
        btnCorrectedImage->setText(QCoreApplication::translate("frmDistortionCalibrationClass", "\345\233\276\345\203\217\346\240\241\346\255\243", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmDistortionCalibrationClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmDistortionCalibrationClass", "\350\276\223\345\207\272\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmDistortionCalibrationClass", "\350\276\223\345\207\272\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmDistortionCalibrationClass: public Ui_frmDistortionCalibrationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDISTORTIONCALIBRATION_H
