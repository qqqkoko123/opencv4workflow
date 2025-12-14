/********************************************************************************
** Form generated from reading UI file 'frmTemplateMatch.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTEMPLATEMATCH_H
#define UI_FRMTEMPLATEMATCH_H

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

class Ui_frmTemplateMatchClass
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
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QGroupBox *groupC2;
    QComboBox *comboMode;
    QLabel *label_10;
    QSpinBox *spinNumMatches;
    QLabel *label_11;
    QLabel *label_12;
    QSpinBox *spinRAngle;
    QLabel *label_19;
    QDoubleSpinBox *spinScore;
    QDoubleSpinBox *spinMaxOverlap;
    QLabel *label_20;
    QLabel *label_13;
    QSpinBox *spinThickness;
    QLabel *label_21;
    QComboBox *comboViewMode;
    QLabel *label_14;
    QSpinBox *spinPyramid;
    QGroupBox *groupCamera_2;
    QPushButton *btnDeleteROI_2;
    QPushButton *btnAddROI_2;
    QComboBox *comboROIShape_2;
    QPushButton *btnCreateROI;
    QLineEdit *txtSaveModel;
    QLabel *label_7;
    QLabel *label_5;
    QPushButton *btnDeleteModel;
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
    QWidget *tab_3;
    QGroupBox *groupC3;
    QTextEdit *txtMsg;

    void setupUi(QDialog *frmTemplateMatchClass)
    {
        if (frmTemplateMatchClass->objectName().isEmpty())
            frmTemplateMatchClass->setObjectName(QString::fromUtf8("frmTemplateMatchClass"));
        frmTemplateMatchClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmTemplateMatchClass->sizePolicy().hasHeightForWidth());
        frmTemplateMatchClass->setSizePolicy(sizePolicy);
        frmTemplateMatchClass->setMinimumSize(QSize(1160, 655));
        frmTemplateMatchClass->setMaximumSize(QSize(1160, 655));
        frmTemplateMatchClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmTemplateMatchClass);
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

        label_3 = new QLabel(frmTemplateMatchClass);
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

        txtDescribe = new QLineEdit(frmTemplateMatchClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmTemplateMatchClass);
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

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        tabWidget = new QTabWidget(frmTemplateMatchClass);
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
        groupCamera->setGeometry(QRect(9, 14, 427, 73));
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
        groupC2->setGeometry(QRect(9, 244, 427, 277));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        comboMode = new QComboBox(groupC2);
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->setObjectName(QString::fromUtf8("comboMode"));
        comboMode->setGeometry(QRect(129, 36, 213, 30));
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
        label_10 = new QLabel(groupC2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(12, 41, 117, 19));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinNumMatches = new QSpinBox(groupC2);
        spinNumMatches->setObjectName(QString::fromUtf8("spinNumMatches"));
        spinNumMatches->setGeometry(QRect(92, 139, 80, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        spinNumMatches->setFont(font1);
        spinNumMatches->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinNumMatches->setAlignment(Qt::AlignCenter);
        spinNumMatches->setMinimum(1);
        spinNumMatches->setMaximum(1000);
        spinNumMatches->setValue(1);
        label_11 = new QLabel(groupC2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(12, 142, 79, 19));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_11->setFont(font2);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_12 = new QLabel(groupC2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(198, 142, 139, 19));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinRAngle = new QSpinBox(groupC2);
        spinRAngle->setObjectName(QString::fromUtf8("spinRAngle"));
        spinRAngle->setGeometry(QRect(337, 139, 80, 27));
        spinRAngle->setFont(font1);
        spinRAngle->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinRAngle->setAlignment(Qt::AlignCenter);
        spinRAngle->setMinimum(0);
        spinRAngle->setMaximum(180);
        spinRAngle->setValue(60);
        label_19 = new QLabel(groupC2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(12, 192, 81, 19));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinScore = new QDoubleSpinBox(groupC2);
        spinScore->setObjectName(QString::fromUtf8("spinScore"));
        spinScore->setGeometry(QRect(92, 189, 80, 27));
        spinScore->setFont(font1);
        spinScore->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinScore->setAlignment(Qt::AlignCenter);
        spinScore->setDecimals(2);
        spinScore->setMinimum(0.500000000000000);
        spinScore->setMaximum(1.000000000000000);
        spinScore->setSingleStep(0.050000000000000);
        spinScore->setValue(0.750000000000000);
        spinMaxOverlap = new QDoubleSpinBox(groupC2);
        spinMaxOverlap->setObjectName(QString::fromUtf8("spinMaxOverlap"));
        spinMaxOverlap->setGeometry(QRect(337, 189, 80, 27));
        spinMaxOverlap->setFont(font1);
        spinMaxOverlap->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxOverlap->setAlignment(Qt::AlignCenter);
        spinMaxOverlap->setDecimals(1);
        spinMaxOverlap->setMinimum(0.000000000000000);
        spinMaxOverlap->setMaximum(0.800000000000000);
        spinMaxOverlap->setSingleStep(0.100000000000000);
        spinMaxOverlap->setValue(0.300000000000000);
        label_20 = new QLabel(groupC2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(198, 192, 115, 19));
        label_20->setFont(font2);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_13 = new QLabel(groupC2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(198, 244, 121, 19));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinThickness = new QSpinBox(groupC2);
        spinThickness->setObjectName(QString::fromUtf8("spinThickness"));
        spinThickness->setGeometry(QRect(337, 240, 80, 27));
        spinThickness->setFont(font1);
        spinThickness->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinThickness->setAlignment(Qt::AlignCenter);
        spinThickness->setMinimum(1);
        spinThickness->setMaximum(30);
        spinThickness->setValue(2);
        label_21 = new QLabel(groupC2);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(12, 244, 81, 19));
        label_21->setFont(font2);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboViewMode = new QComboBox(groupC2);
        comboViewMode->addItem(QString());
        comboViewMode->addItem(QString());
        comboViewMode->setObjectName(QString::fromUtf8("comboViewMode"));
        comboViewMode->setGeometry(QRect(92, 238, 80, 30));
        comboViewMode->setFont(font);
        comboViewMode->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        label_14 = new QLabel(groupC2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(13, 92, 133, 19));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinPyramid = new QSpinBox(groupC2);
        spinPyramid->setObjectName(QString::fromUtf8("spinPyramid"));
        spinPyramid->setGeometry(QRect(146, 89, 80, 27));
        spinPyramid->setFont(font1);
        spinPyramid->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinPyramid->setAlignment(Qt::AlignCenter);
        spinPyramid->setMinimum(1);
        spinPyramid->setMaximum(20);
        spinPyramid->setValue(3);
        groupCamera_2 = new QGroupBox(tab);
        groupCamera_2->setObjectName(QString::fromUtf8("groupCamera_2"));
        groupCamera_2->setGeometry(QRect(9, 98, 427, 135));
        groupCamera_2->setFont(font);
        groupCamera_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnDeleteROI_2 = new QPushButton(groupCamera_2);
        btnDeleteROI_2->setObjectName(QString::fromUtf8("btnDeleteROI_2"));
        btnDeleteROI_2->setGeometry(QRect(352, 34, 66, 32));
        btnDeleteROI_2->setMinimumSize(QSize(60, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        btnDeleteROI_2->setFont(font3);
        btnDeleteROI_2->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));
        btnAddROI_2 = new QPushButton(groupCamera_2);
        btnAddROI_2->setObjectName(QString::fromUtf8("btnAddROI_2"));
        btnAddROI_2->setGeometry(QRect(255, 34, 66, 32));
        sizePolicy.setHeightForWidth(btnAddROI_2->sizePolicy().hasHeightForWidth());
        btnAddROI_2->setSizePolicy(sizePolicy);
        btnAddROI_2->setMinimumSize(QSize(60, 30));
        btnAddROI_2->setFont(font3);
        btnAddROI_2->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        comboROIShape_2 = new QComboBox(groupCamera_2);
        comboROIShape_2->addItem(QString());
        comboROIShape_2->setObjectName(QString::fromUtf8("comboROIShape_2"));
        comboROIShape_2->setGeometry(QRect(100, 34, 95, 30));
        comboROIShape_2->setFont(font);
        comboROIShape_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        btnCreateROI = new QPushButton(groupCamera_2);
        btnCreateROI->setObjectName(QString::fromUtf8("btnCreateROI"));
        btnCreateROI->setGeometry(QRect(256, 96, 85, 32));
        btnCreateROI->setMinimumSize(QSize(60, 30));
        btnCreateROI->setFont(font3);
        btnCreateROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(19, 22, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(19, 22, 67);}\n"
"QPushButton:pressed{background-color: rgb(19, 22, 87);}"));
        txtSaveModel = new QLineEdit(groupCamera_2);
        txtSaveModel->setObjectName(QString::fromUtf8("txtSaveModel"));
        txtSaveModel->setGeometry(QRect(13, 98, 239, 27));
        txtSaveModel->setFont(font);
        txtSaveModel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtSaveModel->setReadOnly(true);
        label_7 = new QLabel(groupCamera_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(13, 74, 136, 19));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(10);
        label_7->setFont(font4);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_5 = new QLabel(groupCamera_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 39, 79, 19));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        btnDeleteModel = new QPushButton(groupCamera_2);
        btnDeleteModel->setObjectName(QString::fromUtf8("btnDeleteModel"));
        btnDeleteModel->setGeometry(QRect(352, 96, 66, 32));
        btnDeleteModel->setMinimumSize(QSize(60, 30));
        btnDeleteModel->setFont(font3);
        btnDeleteModel->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupCamera_8 = new QGroupBox(tab_2);
        groupCamera_8->setObjectName(QString::fromUtf8("groupCamera_8"));
        groupCamera_8->setGeometry(QRect(9, 14, 427, 179));
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
        btnAddROI->setFont(font3);
        btnAddROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        btnDeleteROI = new QPushButton(groupCamera_8);
        btnDeleteROI->setObjectName(QString::fromUtf8("btnDeleteROI"));
        btnDeleteROI->setGeometry(QRect(350, 34, 66, 32));
        btnDeleteROI->setMinimumSize(QSize(60, 30));
        btnDeleteROI->setFont(font3);
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
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupC3 = new QGroupBox(tab_3);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(9, 14, 427, 503));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC3);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 419, 467));
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
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(frmTemplateMatchClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmTemplateMatchClass);
    } // setupUi

    void retranslateUi(QDialog *frmTemplateMatchClass)
    {
        frmTemplateMatchClass->setWindowTitle(QCoreApplication::translate("frmTemplateMatchClass", "\347\201\260\345\272\246\345\214\271\351\205\215", nullptr));
        label_3->setText(QCoreApplication::translate("frmTemplateMatchClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\211\247\350\241\214", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmTemplateMatchClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmTemplateMatchClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmTemplateMatchClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmTemplateMatchClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupC2->setTitle(QCoreApplication::translate("frmTemplateMatchClass", "\345\214\271\351\205\215\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        comboMode->setItemText(0, QCoreApplication::translate("frmTemplateMatchClass", "TM_CCORR", nullptr));
        comboMode->setItemText(1, QCoreApplication::translate("frmTemplateMatchClass", "TM_CCORR_NORMED", nullptr));
        comboMode->setItemText(2, QCoreApplication::translate("frmTemplateMatchClass", "TM_CCOEFF_NORMED", nullptr));

        label_10->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\250\241\346\235\277\345\214\271\351\205\215\346\250\241\345\274\217\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("frmTemplateMatchClass", "\345\214\271\351\205\215\344\270\252\346\225\260\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\220\234\347\264\242\350\247\222\345\272\246\350\214\203\345\233\264(\302\261)\357\274\232", nullptr));
        label_19->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\234\200\344\275\216\345\210\206\346\225\260\357\274\232", nullptr));
        label_20->setText(QCoreApplication::translate("frmTemplateMatchClass", "\351\207\215\345\217\240\345\214\272\345\237\237\346\257\224\344\276\213\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\230\276\347\244\272\350\275\256\345\273\223\347\272\277\345\256\275\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\230\276\347\244\272\350\275\256\345\273\223\357\274\232", nullptr));
        comboViewMode->setItemText(0, QCoreApplication::translate("frmTemplateMatchClass", "\344\270\215\346\230\276\347\244\272", nullptr));
        comboViewMode->setItemText(1, QCoreApplication::translate("frmTemplateMatchClass", "\346\230\276\347\244\272", nullptr));

        label_14->setText(QCoreApplication::translate("frmTemplateMatchClass", "\345\233\276\345\203\217\351\207\221\345\255\227\345\241\224\345\261\202\346\225\260\357\274\232", nullptr));
        groupCamera_2->setTitle(QCoreApplication::translate("frmTemplateMatchClass", "\346\250\241\346\235\277\345\257\271\350\261\241", nullptr));
        btnDeleteROI_2->setText(QCoreApplication::translate("frmTemplateMatchClass", "\345\210\240\351\231\244", nullptr));
        btnAddROI_2->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\267\273\345\212\240", nullptr));
        comboROIShape_2->setItemText(0, QCoreApplication::translate("frmTemplateMatchClass", "\347\237\251\345\275\242", nullptr));

        btnCreateROI->setText(QCoreApplication::translate("frmTemplateMatchClass", "\345\210\233\345\273\272\346\250\241\346\235\277", nullptr));
        txtSaveModel->setText(QString());
        label_7->setText(QCoreApplication::translate("frmTemplateMatchClass", "\344\277\235\345\255\230\346\250\241\346\235\277\346\226\207\344\273\266\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\250\241\346\235\277\345\214\272\345\237\237\357\274\232", nullptr));
        btnDeleteModel->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\270\205\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmTemplateMatchClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupCamera_8->setTitle(QCoreApplication::translate("frmTemplateMatchClass", "\346\220\234\347\264\242\345\214\272\345\237\237", nullptr));
        checkUseROI->setText(QCoreApplication::translate("frmTemplateMatchClass", "\344\275\277\347\224\250ROI", nullptr));
        comboROIShape->setItemText(0, QCoreApplication::translate("frmTemplateMatchClass", "\347\237\251\345\275\242", nullptr));

        btnAddROI->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteROI->setText(QCoreApplication::translate("frmTemplateMatchClass", "\345\210\240\351\231\244", nullptr));
        checkViewROI->setText(QCoreApplication::translate("frmTemplateMatchClass", "\346\230\276\347\244\272ROI", nullptr));
        label_16->setText(QCoreApplication::translate("frmTemplateMatchClass", "ROI\345\256\275\345\272\246\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("frmTemplateMatchClass", "ROI\351\242\234\350\211\262\357\274\232", nullptr));
        btnRoiColor->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmTemplateMatchClass", "ROI\350\256\276\347\275\256", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmTemplateMatchClass", "\350\276\223\345\207\272\346\225\260\346\215\256(\345\214\271\351\205\215\347\232\204\344\270\255\345\277\203\343\200\201\350\247\222\345\272\246\343\200\201\345\210\206\346\225\260)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("frmTemplateMatchClass", "\350\276\223\345\207\272\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmTemplateMatchClass: public Ui_frmTemplateMatchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTEMPLATEMATCH_H
