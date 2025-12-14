/********************************************************************************
** Form generated from reading UI file 'frmColorIdentify.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCOLORIDENTIFY_H
#define UI_FRMCOLORIDENTIFY_H

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

class Ui_frmColorIdentifyClass
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QCheckBox *checkStandardImage;
    QGroupBox *groupCamera_6;
    QLabel *label_11;
    QDoubleSpinBox *spinMinScore;
    QLabel *label_12;
    QSpinBox *spinMaxS;
    QLabel *label_13;
    QSpinBox *spinMaxH;
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
    QCheckBox *checkUseFollow;
    QLineEdit *txtLinkFollow;
    QPushButton *btnDelLinkFollow;
    QPushButton *btnLinkFollow;
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

    void setupUi(QDialog *frmColorIdentifyClass)
    {
        if (frmColorIdentifyClass->objectName().isEmpty())
            frmColorIdentifyClass->setObjectName(QString::fromUtf8("frmColorIdentifyClass"));
        frmColorIdentifyClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmColorIdentifyClass->sizePolicy().hasHeightForWidth());
        frmColorIdentifyClass->setSizePolicy(sizePolicy);
        frmColorIdentifyClass->setMinimumSize(QSize(1160, 655));
        frmColorIdentifyClass->setMaximumSize(QSize(1160, 655));
        frmColorIdentifyClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmColorIdentifyClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(frmColorIdentifyClass);
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
        groupCamera->setGeometry(QRect(9, 18, 427, 120));
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
        checkStandardImage = new QCheckBox(groupCamera);
        checkStandardImage->setObjectName(QString::fromUtf8("checkStandardImage"));
        checkStandardImage->setGeometry(QRect(14, 88, 215, 27));
        sizePolicy.setHeightForWidth(checkStandardImage->sizePolicy().hasHeightForWidth());
        checkStandardImage->setSizePolicy(sizePolicy);
        checkStandardImage->setFont(font);
        checkStandardImage->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkStandardImage->setIconSize(QSize(22, 22));
        checkStandardImage->setChecked(false);
        groupCamera_6 = new QGroupBox(tab);
        groupCamera_6->setObjectName(QString::fromUtf8("groupCamera_6"));
        groupCamera_6->setGeometry(QRect(9, 154, 427, 149));
        groupCamera_6->setFont(font);
        groupCamera_6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_11 = new QLabel(groupCamera_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(26, 117, 131, 19));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinScore = new QDoubleSpinBox(groupCamera_6);
        spinMinScore->setObjectName(QString::fromUtf8("spinMinScore"));
        spinMinScore->setGeometry(QRect(170, 113, 90, 27));
        sizePolicy.setHeightForWidth(spinMinScore->sizePolicy().hasHeightForWidth());
        spinMinScore->setSizePolicy(sizePolicy);
        spinMinScore->setMinimumSize(QSize(80, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        spinMinScore->setFont(font2);
        spinMinScore->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinScore->setAlignment(Qt::AlignCenter);
        spinMinScore->setDecimals(2);
        spinMinScore->setMaximum(0.990000000000000);
        spinMinScore->setSingleStep(0.020000000000000);
        spinMinScore->setValue(0.700000000000000);
        label_12 = new QLabel(groupCamera_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(26, 77, 143, 19));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxS = new QSpinBox(groupCamera_6);
        spinMaxS->setObjectName(QString::fromUtf8("spinMaxS"));
        spinMaxS->setGeometry(QRect(170, 73, 90, 27));
        spinMaxS->setFont(font2);
        spinMaxS->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxS->setAlignment(Qt::AlignCenter);
        spinMaxS->setMaximum(256);
        spinMaxS->setValue(200);
        label_13 = new QLabel(groupCamera_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(26, 37, 143, 19));
        label_13->setFont(font1);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxH = new QSpinBox(groupCamera_6);
        spinMaxH->setObjectName(QString::fromUtf8("spinMaxH"));
        spinMaxH->setGeometry(QRect(170, 33, 90, 27));
        spinMaxH->setFont(font2);
        spinMaxH->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxH->setAlignment(Qt::AlignCenter);
        spinMaxH->setMaximum(256);
        spinMaxH->setValue(256);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupCamera_8 = new QGroupBox(tab_2);
        groupCamera_8->setObjectName(QString::fromUtf8("groupCamera_8"));
        groupCamera_8->setGeometry(QRect(9, 18, 427, 215));
        groupCamera_8->setFont(font);
        groupCamera_8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        checkUseROI = new QCheckBox(groupCamera_8);
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
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
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
        checkViewROI->setGeometry(QRect(13, 130, 93, 27));
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
        label_16->setGeometry(QRect(183, 134, 79, 19));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_17 = new QLabel(groupCamera_8);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(13, 182, 79, 19));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        btnRoiColor = new QPushButton(groupCamera_8);
        btnRoiColor->setObjectName(QString::fromUtf8("btnRoiColor"));
        btnRoiColor->setGeometry(QRect(108, 178, 307, 27));
        btnRoiColor->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgba(0, 255, 0);"));
        spinRoiW = new QSpinBox(groupCamera_8);
        spinRoiW->setObjectName(QString::fromUtf8("spinRoiW"));
        spinRoiW->setGeometry(QRect(270, 130, 146, 27));
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
        checkUseFollow = new QCheckBox(groupCamera_8);
        checkUseFollow->setObjectName(QString::fromUtf8("checkUseFollow"));
        checkUseFollow->setGeometry(QRect(13, 83, 95, 27));
        sizePolicy.setHeightForWidth(checkUseFollow->sizePolicy().hasHeightForWidth());
        checkUseFollow->setSizePolicy(sizePolicy);
        checkUseFollow->setFont(font);
        checkUseFollow->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkUseFollow->setIconSize(QSize(22, 22));
        txtLinkFollow = new QLineEdit(groupCamera_8);
        txtLinkFollow->setObjectName(QString::fromUtf8("txtLinkFollow"));
        txtLinkFollow->setGeometry(QRect(114, 84, 235, 27));
        txtLinkFollow->setFont(font);
        txtLinkFollow->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkFollow->setAlignment(Qt::AlignCenter);
        txtLinkFollow->setReadOnly(true);
        btnDelLinkFollow = new QPushButton(groupCamera_8);
        btnDelLinkFollow->setObjectName(QString::fromUtf8("btnDelLinkFollow"));
        btnDelLinkFollow->setGeometry(QRect(388, 84, 27, 27));
        btnDelLinkFollow->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkFollow->setIcon(icon1);
        btnDelLinkFollow->setIconSize(QSize(27, 27));
        btnLinkFollow = new QPushButton(groupCamera_8);
        btnLinkFollow->setObjectName(QString::fromUtf8("btnLinkFollow"));
        btnLinkFollow->setGeometry(QRect(354, 84, 27, 27));
        btnLinkFollow->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkFollow->setIcon(icon);
        btnLinkFollow->setIconSize(QSize(27, 27));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

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

        label_3 = new QLabel(frmColorIdentifyClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmColorIdentifyClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmColorIdentifyClass);
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


        retranslateUi(frmColorIdentifyClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmColorIdentifyClass);
    } // setupUi

    void retranslateUi(QDialog *frmColorIdentifyClass)
    {
        frmColorIdentifyClass->setWindowTitle(QCoreApplication::translate("frmColorIdentifyClass", "\351\242\234\350\211\262\350\257\206\345\210\253", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmColorIdentifyClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmColorIdentifyClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmColorIdentifyClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmColorIdentifyClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        checkStandardImage->setText(QCoreApplication::translate("frmColorIdentifyClass", "\346\240\207\345\207\206\345\233\276\345\203\217(\345\201\232\346\240\207\345\207\206\346\227\266\345\213\276\351\200\211)", nullptr));
        groupCamera_6->setTitle(QCoreApplication::translate("frmColorIdentifyClass", "\351\242\234\350\211\262\345\217\202\346\225\260", nullptr));
        label_11->setText(QCoreApplication::translate("frmColorIdentifyClass", "\346\234\200\345\260\217\351\242\234\350\211\262\347\233\270\344\274\274\345\272\246\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("frmColorIdentifyClass", "S\351\200\232\351\201\223\351\242\234\350\211\262\346\234\200\345\244\247\345\200\274\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("frmColorIdentifyClass", "H\351\200\232\351\201\223\351\242\234\350\211\262\346\234\200\345\244\247\345\200\274\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmColorIdentifyClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupCamera_8->setTitle(QCoreApplication::translate("frmColorIdentifyClass", "ROI\345\257\271\350\261\241", nullptr));
        checkUseROI->setText(QCoreApplication::translate("frmColorIdentifyClass", "\344\275\277\347\224\250ROI", nullptr));
        comboROIShape->setItemText(0, QCoreApplication::translate("frmColorIdentifyClass", "\347\237\251\345\275\242", nullptr));

        btnAddROI->setText(QCoreApplication::translate("frmColorIdentifyClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteROI->setText(QCoreApplication::translate("frmColorIdentifyClass", "\345\210\240\351\231\244", nullptr));
        checkViewROI->setText(QCoreApplication::translate("frmColorIdentifyClass", "\346\230\276\347\244\272ROI", nullptr));
        label_16->setText(QCoreApplication::translate("frmColorIdentifyClass", "ROI\345\256\275\345\272\246\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("frmColorIdentifyClass", "ROI\351\242\234\350\211\262\357\274\232", nullptr));
        btnRoiColor->setText(QString());
        checkUseFollow->setText(QCoreApplication::translate("frmColorIdentifyClass", "\344\275\215\347\275\256\350\267\237\351\232\217", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkFollow->setToolTip(QCoreApplication::translate("frmColorIdentifyClass", "\345\214\271\351\205\215\345\237\272\345\207\206\344\270\255\345\277\203", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnDelLinkFollow->setToolTip(QCoreApplication::translate("frmColorIdentifyClass", "\345\210\240\351\231\244\344\275\215\347\275\256\350\267\237\351\232\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkFollow->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkFollow->setToolTip(QCoreApplication::translate("frmColorIdentifyClass", "\351\223\276\346\216\245\344\275\215\347\275\256\350\267\237\351\232\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkFollow->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmColorIdentifyClass", "ROI\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmColorIdentifyClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmColorIdentifyClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmColorIdentifyClass: public Ui_frmColorIdentifyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCOLORIDENTIFY_H
