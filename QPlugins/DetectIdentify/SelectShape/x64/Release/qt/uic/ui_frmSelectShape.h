/********************************************************************************
** Form generated from reading UI file 'frmSelectShape.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSELECTSHAPE_H
#define UI_FRMSELECTSHAPE_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmSelectShapeClass
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
    QGroupBox *groupC;
    QLabel *label_9;
    QComboBox *comboMode;
    QLabel *label_10;
    QComboBox *comboMethod;
    QLabel *label_11;
    QComboBox *comboCMode;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupParam;
    QSpinBox *spinMaxArea;
    QLabel *label_5;
    QSpinBox *spinMinArea;
    QLabel *label_6;
    QWidget *page_2;
    QGroupBox *groupParam_2;
    QSpinBox *spinMaxLength;
    QLabel *label_7;
    QSpinBox *spinMinLength;
    QLabel *label_8;
    QWidget *page_3;
    QGroupBox *groupParam_3;
    QLabel *label_12;
    QSpinBox *spinVertices;
    QLabel *label_15;
    QDoubleSpinBox *spinApprox;
    QWidget *page_4;
    QGroupBox *groupParam_4;
    QSpinBox *spinMaxRadius;
    QLabel *label_13;
    QSpinBox *spinMinRadius;
    QLabel *label_14;
    QLabel *label_18;
    QLabel *label_19;
    QDoubleSpinBox *spinMinCircularity;
    QDoubleSpinBox *spinMaxCircularity;
    QWidget *page_5;
    QGroupBox *groupParam_5;
    QDoubleSpinBox *spinMinRectangularity;
    QLabel *label_20;
    QLabel *label_21;
    QDoubleSpinBox *spinMaxRectangularity;
    QWidget *page_6;
    QGroupBox *groupParam_6;
    QSpinBox *spinMaxRectW;
    QLabel *label_22;
    QSpinBox *spinMinRectW;
    QLabel *label_23;
    QWidget *page_7;
    QGroupBox *groupParam_7;
    QSpinBox *spinMaxRectH;
    QLabel *label_24;
    QSpinBox *spinMinRectH;
    QLabel *label_25;
    QWidget *page_8;
    QGroupBox *groupParam_8;
    QSpinBox *spinMaxRow;
    QLabel *label_26;
    QSpinBox *spinMinRow;
    QLabel *label_27;
    QWidget *page_9;
    QGroupBox *groupParam_9;
    QSpinBox *spinMaxColumn;
    QLabel *label_28;
    QSpinBox *spinMinColumn;
    QLabel *label_29;
    QWidget *page_10;
    QGroupBox *groupParam_10;
    QSpinBox *spinMaxRectLen1;
    QLabel *label_31;
    QSpinBox *spinMinRectLen1;
    QLabel *label_32;
    QWidget *page_11;
    QGroupBox *groupParam_11;
    QSpinBox *spinMaxRectLen2;
    QLabel *label_33;
    QSpinBox *spinMinRectLen2;
    QLabel *label_34;
    QWidget *page_12;
    QGroupBox *groupParam_12;
    QDoubleSpinBox *spinMinRectPhi;
    QLabel *label_35;
    QLabel *label_36;
    QDoubleSpinBox *spinMaxRectPhi;
    QWidget *page_13;
    QGroupBox *groupParam_13;
    QSpinBox *spinMaxEllipseLena;
    QLabel *label_37;
    QSpinBox *spinMinEllipseLena;
    QLabel *label_38;
    QWidget *page_14;
    QGroupBox *groupParam_14;
    QSpinBox *spinMaxEllipseLenb;
    QLabel *label_39;
    QSpinBox *spinMinEllipseLenb;
    QLabel *label_40;
    QWidget *page_15;
    QGroupBox *groupParam_15;
    QDoubleSpinBox *spinMinEllipsePhi;
    QLabel *label_41;
    QLabel *label_42;
    QDoubleSpinBox *spinMaxEllipsePhi;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetType;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnAddType;
    QPushButton *btnDeleteType;
    QSpacerItem *verticalSpacer_3;
    QComboBox *comboType;
    QLabel *label_30;
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

    void setupUi(QDialog *frmSelectShapeClass)
    {
        if (frmSelectShapeClass->objectName().isEmpty())
            frmSelectShapeClass->setObjectName(QString::fromUtf8("frmSelectShapeClass"));
        frmSelectShapeClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmSelectShapeClass->sizePolicy().hasHeightForWidth());
        frmSelectShapeClass->setSizePolicy(sizePolicy);
        frmSelectShapeClass->setMinimumSize(QSize(1160, 655));
        frmSelectShapeClass->setMaximumSize(QSize(1160, 655));
        frmSelectShapeClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmSelectShapeClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(frmSelectShapeClass);
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
        groupC = new QGroupBox(tab);
        groupC->setObjectName(QString::fromUtf8("groupC"));
        groupC->setGeometry(QRect(9, 106, 427, 411));
        groupC->setFont(font);
        groupC->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_9 = new QLabel(groupC);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(13, 32, 131, 19));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboMode = new QComboBox(groupC);
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->setObjectName(QString::fromUtf8("comboMode"));
        comboMode->setGeometry(QRect(146, 27, 165, 30));
        sizePolicy.setHeightForWidth(comboMode->sizePolicy().hasHeightForWidth());
        comboMode->setSizePolicy(sizePolicy);
        comboMode->setMinimumSize(QSize(165, 30));
        comboMode->setMaximumSize(QSize(165, 16777215));
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
        comboMode->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_10 = new QLabel(groupC);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(13, 75, 131, 19));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboMethod = new QComboBox(groupC);
        comboMethod->addItem(QString());
        comboMethod->addItem(QString());
        comboMethod->addItem(QString());
        comboMethod->addItem(QString());
        comboMethod->setObjectName(QString::fromUtf8("comboMethod"));
        comboMethod->setGeometry(QRect(146, 70, 265, 30));
        sizePolicy.setHeightForWidth(comboMethod->sizePolicy().hasHeightForWidth());
        comboMethod->setSizePolicy(sizePolicy);
        comboMethod->setMinimumSize(QSize(265, 30));
        comboMethod->setMaximumSize(QSize(265, 16777215));
        comboMethod->setFont(font);
        comboMethod->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        comboMethod->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_11 = new QLabel(groupC);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(13, 118, 131, 19));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboCMode = new QComboBox(groupC);
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->addItem(QString());
        comboCMode->setObjectName(QString::fromUtf8("comboCMode"));
        comboCMode->setGeometry(QRect(146, 113, 165, 30));
        sizePolicy.setHeightForWidth(comboCMode->sizePolicy().hasHeightForWidth());
        comboCMode->setSizePolicy(sizePolicy);
        comboCMode->setMinimumSize(QSize(165, 30));
        comboCMode->setMaximumSize(QSize(165, 16777215));
        comboCMode->setFont(font);
        comboCMode->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
"QScrollBar::add-line:vertica"
                        "l{\n"
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
"		min-height:20px;}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/resource/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/resource/left.png) center no-repeat;}"));
        comboCMode->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        stackedWidget = new QStackedWidget(groupC);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(1, 194, 425, 101));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        groupParam = new QGroupBox(page);
        groupParam->setObjectName(QString::fromUtf8("groupParam"));
        groupParam->setGeometry(QRect(1, 2, 423, 97));
        groupParam->setFont(font);
        groupParam->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxArea = new QSpinBox(groupParam);
        spinMaxArea->setObjectName(QString::fromUtf8("spinMaxArea"));
        spinMaxArea->setGeometry(QRect(312, 42, 100, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        spinMaxArea->setFont(font1);
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
        label_5 = new QLabel(groupParam);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 46, 79, 19));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinArea = new QSpinBox(groupParam);
        spinMinArea->setObjectName(QString::fromUtf8("spinMinArea"));
        spinMinArea->setGeometry(QRect(92, 42, 100, 27));
        spinMinArea->setFont(font1);
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
        label_6 = new QLabel(groupParam);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 46, 79, 19));
        label_6->setFont(font2);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupParam_2 = new QGroupBox(page_2);
        groupParam_2->setObjectName(QString::fromUtf8("groupParam_2"));
        groupParam_2->setGeometry(QRect(1, 2, 423, 97));
        groupParam_2->setFont(font);
        groupParam_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxLength = new QSpinBox(groupParam_2);
        spinMaxLength->setObjectName(QString::fromUtf8("spinMaxLength"));
        spinMaxLength->setGeometry(QRect(312, 42, 100, 27));
        spinMaxLength->setFont(font1);
        spinMaxLength->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxLength->setAlignment(Qt::AlignCenter);
        spinMaxLength->setMinimum(1);
        spinMaxLength->setMaximum(20000);
        spinMaxLength->setValue(100);
        label_7 = new QLabel(groupParam_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 46, 79, 19));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinLength = new QSpinBox(groupParam_2);
        spinMinLength->setObjectName(QString::fromUtf8("spinMinLength"));
        spinMinLength->setGeometry(QRect(92, 42, 100, 27));
        spinMinLength->setFont(font1);
        spinMinLength->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinLength->setAlignment(Qt::AlignCenter);
        spinMinLength->setMinimum(0);
        spinMinLength->setMaximum(10000);
        spinMinLength->setValue(10);
        label_8 = new QLabel(groupParam_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(230, 46, 79, 19));
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        groupParam_3 = new QGroupBox(page_3);
        groupParam_3->setObjectName(QString::fromUtf8("groupParam_3"));
        groupParam_3->setGeometry(QRect(1, 2, 423, 97));
        groupParam_3->setFont(font);
        groupParam_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        label_12 = new QLabel(groupParam_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 46, 79, 19));
        label_12->setFont(font2);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinVertices = new QSpinBox(groupParam_3);
        spinVertices->setObjectName(QString::fromUtf8("spinVertices"));
        spinVertices->setGeometry(QRect(92, 42, 90, 27));
        spinVertices->setFont(font1);
        spinVertices->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinVertices->setAlignment(Qt::AlignCenter);
        spinVertices->setMinimum(1);
        spinVertices->setMaximum(100);
        spinVertices->setValue(3);
        label_15 = new QLabel(groupParam_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(206, 46, 113, 19));
        label_15->setFont(font2);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinApprox = new QDoubleSpinBox(groupParam_3);
        spinApprox->setObjectName(QString::fromUtf8("spinApprox"));
        spinApprox->setGeometry(QRect(322, 42, 90, 27));
        spinApprox->setFont(font1);
        spinApprox->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinApprox->setAlignment(Qt::AlignCenter);
        spinApprox->setDecimals(3);
        spinApprox->setMinimum(0.001000000000000);
        spinApprox->setMaximum(0.100000000000000);
        spinApprox->setSingleStep(0.010000000000000);
        spinApprox->setValue(0.025000000000000);
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        groupParam_4 = new QGroupBox(page_4);
        groupParam_4->setObjectName(QString::fromUtf8("groupParam_4"));
        groupParam_4->setGeometry(QRect(1, 2, 423, 97));
        groupParam_4->setFont(font);
        groupParam_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxRadius = new QSpinBox(groupParam_4);
        spinMaxRadius->setObjectName(QString::fromUtf8("spinMaxRadius"));
        spinMaxRadius->setGeometry(QRect(326, 64, 85, 27));
        spinMaxRadius->setFont(font1);
        spinMaxRadius->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxRadius->setAlignment(Qt::AlignCenter);
        spinMaxRadius->setMinimum(1);
        spinMaxRadius->setMaximum(20000);
        spinMaxRadius->setValue(100);
        label_13 = new QLabel(groupParam_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 68, 95, 19));
        label_13->setFont(font2);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinRadius = new QSpinBox(groupParam_4);
        spinMinRadius->setObjectName(QString::fromUtf8("spinMinRadius"));
        spinMinRadius->setGeometry(QRect(107, 64, 85, 27));
        spinMinRadius->setFont(font1);
        spinMinRadius->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinRadius->setAlignment(Qt::AlignCenter);
        spinMinRadius->setMinimum(0);
        spinMinRadius->setMaximum(10000);
        spinMinRadius->setValue(10);
        label_14 = new QLabel(groupParam_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(229, 68, 95, 19));
        label_14->setFont(font2);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_18 = new QLabel(groupParam_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(229, 32, 95, 19));
        label_18->setFont(font2);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_19 = new QLabel(groupParam_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 32, 95, 19));
        label_19->setFont(font2);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinCircularity = new QDoubleSpinBox(groupParam_4);
        spinMinCircularity->setObjectName(QString::fromUtf8("spinMinCircularity"));
        spinMinCircularity->setGeometry(QRect(107, 28, 85, 27));
        spinMinCircularity->setFont(font1);
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
        spinMinCircularity->setMinimum(0.000000000000000);
        spinMinCircularity->setMaximum(0.990000000000000);
        spinMinCircularity->setSingleStep(0.010000000000000);
        spinMinCircularity->setValue(0.750000000000000);
        spinMaxCircularity = new QDoubleSpinBox(groupParam_4);
        spinMaxCircularity->setObjectName(QString::fromUtf8("spinMaxCircularity"));
        spinMaxCircularity->setGeometry(QRect(326, 28, 85, 27));
        spinMaxCircularity->setFont(font1);
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
        spinMaxCircularity->setSingleStep(0.010000000000000);
        spinMaxCircularity->setValue(1.000000000000000);
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        groupParam_5 = new QGroupBox(page_5);
        groupParam_5->setObjectName(QString::fromUtf8("groupParam_5"));
        groupParam_5->setGeometry(QRect(1, 2, 423, 97));
        groupParam_5->setFont(font);
        groupParam_5->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMinRectangularity = new QDoubleSpinBox(groupParam_5);
        spinMinRectangularity->setObjectName(QString::fromUtf8("spinMinRectangularity"));
        spinMinRectangularity->setGeometry(QRect(107, 42, 85, 27));
        spinMinRectangularity->setFont(font1);
        spinMinRectangularity->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinRectangularity->setAlignment(Qt::AlignCenter);
        spinMinRectangularity->setDecimals(2);
        spinMinRectangularity->setMinimum(0.000000000000000);
        spinMinRectangularity->setMaximum(0.990000000000000);
        spinMinRectangularity->setSingleStep(0.010000000000000);
        spinMinRectangularity->setValue(0.750000000000000);
        label_20 = new QLabel(groupParam_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(229, 46, 95, 19));
        label_20->setFont(font2);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_21 = new QLabel(groupParam_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 46, 95, 19));
        label_21->setFont(font2);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxRectangularity = new QDoubleSpinBox(groupParam_5);
        spinMaxRectangularity->setObjectName(QString::fromUtf8("spinMaxRectangularity"));
        spinMaxRectangularity->setGeometry(QRect(326, 42, 85, 27));
        spinMaxRectangularity->setFont(font1);
        spinMaxRectangularity->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxRectangularity->setAlignment(Qt::AlignCenter);
        spinMaxRectangularity->setDecimals(2);
        spinMaxRectangularity->setMinimum(0.010000000000000);
        spinMaxRectangularity->setMaximum(1.000000000000000);
        spinMaxRectangularity->setSingleStep(0.010000000000000);
        spinMaxRectangularity->setValue(1.000000000000000);
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        groupParam_6 = new QGroupBox(page_6);
        groupParam_6->setObjectName(QString::fromUtf8("groupParam_6"));
        groupParam_6->setGeometry(QRect(1, 2, 423, 97));
        groupParam_6->setFont(font);
        groupParam_6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxRectW = new QSpinBox(groupParam_6);
        spinMaxRectW->setObjectName(QString::fromUtf8("spinMaxRectW"));
        spinMaxRectW->setGeometry(QRect(312, 42, 100, 27));
        spinMaxRectW->setFont(font1);
        spinMaxRectW->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxRectW->setAlignment(Qt::AlignCenter);
        spinMaxRectW->setMinimum(1);
        spinMaxRectW->setMaximum(20000);
        spinMaxRectW->setValue(100);
        label_22 = new QLabel(groupParam_6);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(10, 46, 79, 19));
        label_22->setFont(font2);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinRectW = new QSpinBox(groupParam_6);
        spinMinRectW->setObjectName(QString::fromUtf8("spinMinRectW"));
        spinMinRectW->setGeometry(QRect(92, 42, 100, 27));
        spinMinRectW->setFont(font1);
        spinMinRectW->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinRectW->setAlignment(Qt::AlignCenter);
        spinMinRectW->setMinimum(0);
        spinMinRectW->setMaximum(10000);
        spinMinRectW->setValue(10);
        label_23 = new QLabel(groupParam_6);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(230, 46, 79, 19));
        label_23->setFont(font2);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        groupParam_7 = new QGroupBox(page_7);
        groupParam_7->setObjectName(QString::fromUtf8("groupParam_7"));
        groupParam_7->setGeometry(QRect(1, 2, 423, 97));
        groupParam_7->setFont(font);
        groupParam_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxRectH = new QSpinBox(groupParam_7);
        spinMaxRectH->setObjectName(QString::fromUtf8("spinMaxRectH"));
        spinMaxRectH->setGeometry(QRect(312, 42, 100, 27));
        spinMaxRectH->setFont(font1);
        spinMaxRectH->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxRectH->setAlignment(Qt::AlignCenter);
        spinMaxRectH->setMinimum(1);
        spinMaxRectH->setMaximum(20000);
        spinMaxRectH->setValue(100);
        label_24 = new QLabel(groupParam_7);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 46, 79, 19));
        label_24->setFont(font2);
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinRectH = new QSpinBox(groupParam_7);
        spinMinRectH->setObjectName(QString::fromUtf8("spinMinRectH"));
        spinMinRectH->setGeometry(QRect(92, 42, 100, 27));
        spinMinRectH->setFont(font1);
        spinMinRectH->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinRectH->setAlignment(Qt::AlignCenter);
        spinMinRectH->setMinimum(0);
        spinMinRectH->setMaximum(10000);
        spinMinRectH->setValue(10);
        label_25 = new QLabel(groupParam_7);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(230, 46, 79, 19));
        label_25->setFont(font2);
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        groupParam_8 = new QGroupBox(page_8);
        groupParam_8->setObjectName(QString::fromUtf8("groupParam_8"));
        groupParam_8->setGeometry(QRect(1, 2, 423, 97));
        groupParam_8->setFont(font);
        groupParam_8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxRow = new QSpinBox(groupParam_8);
        spinMaxRow->setObjectName(QString::fromUtf8("spinMaxRow"));
        spinMaxRow->setGeometry(QRect(332, 42, 80, 27));
        spinMaxRow->setFont(font1);
        spinMaxRow->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxRow->setAlignment(Qt::AlignCenter);
        spinMaxRow->setMinimum(1);
        spinMaxRow->setMaximum(20000);
        spinMaxRow->setValue(100);
        label_26 = new QLabel(groupParam_8);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(10, 46, 95, 19));
        label_26->setFont(font2);
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinRow = new QSpinBox(groupParam_8);
        spinMinRow->setObjectName(QString::fromUtf8("spinMinRow"));
        spinMinRow->setGeometry(QRect(109, 42, 80, 27));
        spinMinRow->setFont(font1);
        spinMinRow->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinRow->setAlignment(Qt::AlignCenter);
        spinMinRow->setMinimum(0);
        spinMinRow->setMaximum(10000);
        spinMinRow->setValue(10);
        label_27 = new QLabel(groupParam_8);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(233, 46, 95, 19));
        label_27->setFont(font2);
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        stackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        groupParam_9 = new QGroupBox(page_9);
        groupParam_9->setObjectName(QString::fromUtf8("groupParam_9"));
        groupParam_9->setGeometry(QRect(1, 2, 423, 97));
        groupParam_9->setFont(font);
        groupParam_9->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxColumn = new QSpinBox(groupParam_9);
        spinMaxColumn->setObjectName(QString::fromUtf8("spinMaxColumn"));
        spinMaxColumn->setGeometry(QRect(332, 42, 80, 27));
        spinMaxColumn->setFont(font1);
        spinMaxColumn->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxColumn->setAlignment(Qt::AlignCenter);
        spinMaxColumn->setMinimum(1);
        spinMaxColumn->setMaximum(20000);
        spinMaxColumn->setValue(100);
        label_28 = new QLabel(groupParam_9);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(10, 46, 95, 19));
        label_28->setFont(font2);
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinColumn = new QSpinBox(groupParam_9);
        spinMinColumn->setObjectName(QString::fromUtf8("spinMinColumn"));
        spinMinColumn->setGeometry(QRect(109, 42, 80, 27));
        spinMinColumn->setFont(font1);
        spinMinColumn->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinColumn->setAlignment(Qt::AlignCenter);
        spinMinColumn->setMinimum(0);
        spinMinColumn->setMaximum(10000);
        spinMinColumn->setValue(10);
        label_29 = new QLabel(groupParam_9);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(233, 46, 95, 19));
        label_29->setFont(font2);
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        stackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        groupParam_10 = new QGroupBox(page_10);
        groupParam_10->setObjectName(QString::fromUtf8("groupParam_10"));
        groupParam_10->setGeometry(QRect(1, 2, 423, 97));
        groupParam_10->setFont(font);
        groupParam_10->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxRectLen1 = new QSpinBox(groupParam_10);
        spinMaxRectLen1->setObjectName(QString::fromUtf8("spinMaxRectLen1"));
        spinMaxRectLen1->setGeometry(QRect(312, 42, 100, 27));
        spinMaxRectLen1->setFont(font1);
        spinMaxRectLen1->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxRectLen1->setAlignment(Qt::AlignCenter);
        spinMaxRectLen1->setMinimum(1);
        spinMaxRectLen1->setMaximum(20000);
        spinMaxRectLen1->setValue(100);
        label_31 = new QLabel(groupParam_10);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(10, 46, 95, 19));
        label_31->setFont(font2);
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinRectLen1 = new QSpinBox(groupParam_10);
        spinMinRectLen1->setObjectName(QString::fromUtf8("spinMinRectLen1"));
        spinMinRectLen1->setGeometry(QRect(92, 42, 100, 27));
        spinMinRectLen1->setFont(font1);
        spinMinRectLen1->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinRectLen1->setAlignment(Qt::AlignCenter);
        spinMinRectLen1->setMinimum(0);
        spinMinRectLen1->setMaximum(10000);
        spinMinRectLen1->setValue(10);
        label_32 = new QLabel(groupParam_10);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(230, 46, 95, 19));
        label_32->setFont(font2);
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_32->raise();
        spinMaxRectLen1->raise();
        label_31->raise();
        spinMinRectLen1->raise();
        stackedWidget->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName(QString::fromUtf8("page_11"));
        groupParam_11 = new QGroupBox(page_11);
        groupParam_11->setObjectName(QString::fromUtf8("groupParam_11"));
        groupParam_11->setGeometry(QRect(1, 2, 423, 97));
        groupParam_11->setFont(font);
        groupParam_11->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxRectLen2 = new QSpinBox(groupParam_11);
        spinMaxRectLen2->setObjectName(QString::fromUtf8("spinMaxRectLen2"));
        spinMaxRectLen2->setGeometry(QRect(312, 42, 100, 27));
        spinMaxRectLen2->setFont(font1);
        spinMaxRectLen2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxRectLen2->setAlignment(Qt::AlignCenter);
        spinMaxRectLen2->setMinimum(1);
        spinMaxRectLen2->setMaximum(20000);
        spinMaxRectLen2->setValue(100);
        label_33 = new QLabel(groupParam_11);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(10, 46, 95, 19));
        label_33->setFont(font2);
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinRectLen2 = new QSpinBox(groupParam_11);
        spinMinRectLen2->setObjectName(QString::fromUtf8("spinMinRectLen2"));
        spinMinRectLen2->setGeometry(QRect(92, 42, 100, 27));
        spinMinRectLen2->setFont(font1);
        spinMinRectLen2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinRectLen2->setAlignment(Qt::AlignCenter);
        spinMinRectLen2->setMinimum(0);
        spinMinRectLen2->setMaximum(10000);
        spinMinRectLen2->setValue(10);
        label_34 = new QLabel(groupParam_11);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(230, 46, 95, 19));
        label_34->setFont(font2);
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_34->raise();
        spinMaxRectLen2->raise();
        label_33->raise();
        spinMinRectLen2->raise();
        stackedWidget->addWidget(page_11);
        page_12 = new QWidget();
        page_12->setObjectName(QString::fromUtf8("page_12"));
        groupParam_12 = new QGroupBox(page_12);
        groupParam_12->setObjectName(QString::fromUtf8("groupParam_12"));
        groupParam_12->setGeometry(QRect(1, 2, 423, 97));
        groupParam_12->setFont(font);
        groupParam_12->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMinRectPhi = new QDoubleSpinBox(groupParam_12);
        spinMinRectPhi->setObjectName(QString::fromUtf8("spinMinRectPhi"));
        spinMinRectPhi->setGeometry(QRect(92, 42, 100, 27));
        spinMinRectPhi->setFont(font1);
        spinMinRectPhi->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinRectPhi->setAlignment(Qt::AlignCenter);
        spinMinRectPhi->setDecimals(1);
        spinMinRectPhi->setMinimum(0.000000000000000);
        spinMinRectPhi->setMaximum(359.899999999999977);
        spinMinRectPhi->setSingleStep(0.100000000000000);
        spinMinRectPhi->setValue(10.000000000000000);
        label_35 = new QLabel(groupParam_12);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(229, 46, 81, 19));
        label_35->setFont(font2);
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_36 = new QLabel(groupParam_12);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(10, 46, 81, 19));
        label_36->setFont(font2);
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxRectPhi = new QDoubleSpinBox(groupParam_12);
        spinMaxRectPhi->setObjectName(QString::fromUtf8("spinMaxRectPhi"));
        spinMaxRectPhi->setGeometry(QRect(312, 42, 100, 27));
        spinMaxRectPhi->setFont(font1);
        spinMaxRectPhi->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxRectPhi->setAlignment(Qt::AlignCenter);
        spinMaxRectPhi->setDecimals(1);
        spinMaxRectPhi->setMinimum(0.100000000000000);
        spinMaxRectPhi->setMaximum(360.000000000000000);
        spinMaxRectPhi->setSingleStep(0.100000000000000);
        spinMaxRectPhi->setValue(100.000000000000000);
        stackedWidget->addWidget(page_12);
        page_13 = new QWidget();
        page_13->setObjectName(QString::fromUtf8("page_13"));
        groupParam_13 = new QGroupBox(page_13);
        groupParam_13->setObjectName(QString::fromUtf8("groupParam_13"));
        groupParam_13->setGeometry(QRect(1, 2, 423, 97));
        groupParam_13->setFont(font);
        groupParam_13->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxEllipseLena = new QSpinBox(groupParam_13);
        spinMaxEllipseLena->setObjectName(QString::fromUtf8("spinMaxEllipseLena"));
        spinMaxEllipseLena->setGeometry(QRect(332, 42, 80, 27));
        spinMaxEllipseLena->setFont(font1);
        spinMaxEllipseLena->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxEllipseLena->setAlignment(Qt::AlignCenter);
        spinMaxEllipseLena->setMinimum(1);
        spinMaxEllipseLena->setMaximum(20000);
        spinMaxEllipseLena->setValue(100);
        label_37 = new QLabel(groupParam_13);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(10, 46, 95, 19));
        label_37->setFont(font2);
        label_37->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinEllipseLena = new QSpinBox(groupParam_13);
        spinMinEllipseLena->setObjectName(QString::fromUtf8("spinMinEllipseLena"));
        spinMinEllipseLena->setGeometry(QRect(109, 42, 80, 27));
        spinMinEllipseLena->setFont(font1);
        spinMinEllipseLena->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinEllipseLena->setAlignment(Qt::AlignCenter);
        spinMinEllipseLena->setMinimum(0);
        spinMinEllipseLena->setMaximum(10000);
        spinMinEllipseLena->setValue(10);
        label_38 = new QLabel(groupParam_13);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(230, 46, 95, 19));
        label_38->setFont(font2);
        label_38->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_38->raise();
        spinMaxEllipseLena->raise();
        label_37->raise();
        spinMinEllipseLena->raise();
        stackedWidget->addWidget(page_13);
        page_14 = new QWidget();
        page_14->setObjectName(QString::fromUtf8("page_14"));
        groupParam_14 = new QGroupBox(page_14);
        groupParam_14->setObjectName(QString::fromUtf8("groupParam_14"));
        groupParam_14->setGeometry(QRect(1, 2, 423, 97));
        groupParam_14->setFont(font);
        groupParam_14->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMaxEllipseLenb = new QSpinBox(groupParam_14);
        spinMaxEllipseLenb->setObjectName(QString::fromUtf8("spinMaxEllipseLenb"));
        spinMaxEllipseLenb->setGeometry(QRect(332, 42, 80, 27));
        spinMaxEllipseLenb->setFont(font1);
        spinMaxEllipseLenb->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxEllipseLenb->setAlignment(Qt::AlignCenter);
        spinMaxEllipseLenb->setMinimum(1);
        spinMaxEllipseLenb->setMaximum(20000);
        spinMaxEllipseLenb->setValue(100);
        label_39 = new QLabel(groupParam_14);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(10, 46, 95, 19));
        label_39->setFont(font2);
        label_39->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinEllipseLenb = new QSpinBox(groupParam_14);
        spinMinEllipseLenb->setObjectName(QString::fromUtf8("spinMinEllipseLenb"));
        spinMinEllipseLenb->setGeometry(QRect(109, 42, 80, 27));
        spinMinEllipseLenb->setFont(font1);
        spinMinEllipseLenb->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinEllipseLenb->setAlignment(Qt::AlignCenter);
        spinMinEllipseLenb->setMinimum(0);
        spinMinEllipseLenb->setMaximum(10000);
        spinMinEllipseLenb->setValue(10);
        label_40 = new QLabel(groupParam_14);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(230, 46, 95, 19));
        label_40->setFont(font2);
        label_40->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        stackedWidget->addWidget(page_14);
        page_15 = new QWidget();
        page_15->setObjectName(QString::fromUtf8("page_15"));
        groupParam_15 = new QGroupBox(page_15);
        groupParam_15->setObjectName(QString::fromUtf8("groupParam_15"));
        groupParam_15->setGeometry(QRect(1, 2, 423, 97));
        groupParam_15->setFont(font);
        groupParam_15->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(105, 50, 155);"));
        spinMinEllipsePhi = new QDoubleSpinBox(groupParam_15);
        spinMinEllipsePhi->setObjectName(QString::fromUtf8("spinMinEllipsePhi"));
        spinMinEllipsePhi->setGeometry(QRect(92, 42, 100, 27));
        spinMinEllipsePhi->setFont(font1);
        spinMinEllipsePhi->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinEllipsePhi->setAlignment(Qt::AlignCenter);
        spinMinEllipsePhi->setDecimals(1);
        spinMinEllipsePhi->setMinimum(0.000000000000000);
        spinMinEllipsePhi->setMaximum(359.899999999999977);
        spinMinEllipsePhi->setSingleStep(0.100000000000000);
        spinMinEllipsePhi->setValue(10.000000000000000);
        label_41 = new QLabel(groupParam_15);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(229, 46, 81, 19));
        label_41->setFont(font2);
        label_41->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_42 = new QLabel(groupParam_15);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(10, 46, 81, 19));
        label_42->setFont(font2);
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxEllipsePhi = new QDoubleSpinBox(groupParam_15);
        spinMaxEllipsePhi->setObjectName(QString::fromUtf8("spinMaxEllipsePhi"));
        spinMaxEllipsePhi->setGeometry(QRect(312, 42, 100, 27));
        spinMaxEllipsePhi->setFont(font1);
        spinMaxEllipsePhi->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxEllipsePhi->setAlignment(Qt::AlignCenter);
        spinMaxEllipsePhi->setDecimals(1);
        spinMaxEllipsePhi->setMinimum(0.100000000000000);
        spinMaxEllipsePhi->setMaximum(360.000000000000000);
        spinMaxEllipsePhi->setSingleStep(0.100000000000000);
        spinMaxEllipsePhi->setValue(100.000000000000000);
        stackedWidget->addWidget(page_15);
        horizontalLayoutWidget_3 = new QWidget(groupC);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(2, 296, 423, 113));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(horizontalLayoutWidget_3);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableWidgetType = new QTableWidget(frame_3);
        if (tableWidgetType->columnCount() < 1)
            tableWidgetType->setColumnCount(1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font3);
        tableWidgetType->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetType->setObjectName(QString::fromUtf8("tableWidgetType"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tableWidgetType->setFont(font4);
        tableWidgetType->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: #b7c7af; \n"
"    border:none;\n"
"    gridline-color: rgba(20, 25, 155,50);\n"
"    color: rgba(20, 20, 20,200);\n"
"}\n"
"QTableWidget::item::selected\n"
"{   \n"
"    background-color: rgba(180, 180, 215,255); \n"
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
""
                        "QScrollBar::handle:horizontal{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/resource/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/resource/left.png) center no-repeat;}"));
        tableWidgetType->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetType->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetType->setGridStyle(Qt::DashLine);
        tableWidgetType->horizontalHeader()->setMinimumSectionSize(29);
        tableWidgetType->horizontalHeader()->setDefaultSectionSize(353);
        tableWidgetType->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout_3->addWidget(tableWidgetType);


        horizontalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(horizontalLayoutWidget_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);\n"
"background-color: #b7c7a7;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 2, 1, 1);
        btnAddType = new QPushButton(frame_4);
        btnAddType->setObjectName(QString::fromUtf8("btnAddType"));
        sizePolicy.setHeightForWidth(btnAddType->sizePolicy().hasHeightForWidth());
        btnAddType->setSizePolicy(sizePolicy);
        btnAddType->setMinimumSize(QSize(60, 30));
        btnAddType->setFont(font3);
        btnAddType->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnAddType);

        btnDeleteType = new QPushButton(frame_4);
        btnDeleteType->setObjectName(QString::fromUtf8("btnDeleteType"));
        sizePolicy.setHeightForWidth(btnDeleteType->sizePolicy().hasHeightForWidth());
        btnDeleteType->setSizePolicy(sizePolicy);
        btnDeleteType->setMinimumSize(QSize(60, 30));
        btnDeleteType->setFont(font3);
        btnDeleteType->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));

        verticalLayout_4->addWidget(btnDeleteType);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_3);


        horizontalLayout_3->addWidget(frame_4);

        comboType = new QComboBox(groupC);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName(QString::fromUtf8("comboType"));
        comboType->setGeometry(QRect(181, 156, 130, 30));
        sizePolicy.setHeightForWidth(comboType->sizePolicy().hasHeightForWidth());
        comboType->setSizePolicy(sizePolicy);
        comboType->setMinimumSize(QSize(130, 30));
        comboType->setMaximumSize(QSize(130, 16777215));
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
        label_30 = new QLabel(groupC);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(13, 161, 165, 19));
        label_30->setFont(font);
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
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
        groupC3->setGeometry(QRect(9, 18, 427, 499));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC3);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 419, 463));
        txtMsg->setFont(font4);
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

        label_3 = new QLabel(frmSelectShapeClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmSelectShapeClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmSelectShapeClass);
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


        retranslateUi(frmSelectShapeClass);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmSelectShapeClass);
    } // setupUi

    void retranslateUi(QDialog *frmSelectShapeClass)
    {
        frmSelectShapeClass->setWindowTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\347\211\271\345\276\201\351\200\211\346\213\251", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmSelectShapeClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmSelectShapeClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmSelectShapeClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupC->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\345\257\271\350\261\241", nullptr));
        label_9->setText(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\347\232\204\346\243\200\347\264\242\346\250\241\345\274\217\357\274\232", nullptr));
        comboMode->setItemText(0, QCoreApplication::translate("frmSelectShapeClass", "RETR_EXTERNAL", nullptr));
        comboMode->setItemText(1, QCoreApplication::translate("frmSelectShapeClass", "RETR_LIST", nullptr));
        comboMode->setItemText(2, QCoreApplication::translate("frmSelectShapeClass", "RETR_CCOMP", nullptr));
        comboMode->setItemText(3, QCoreApplication::translate("frmSelectShapeClass", "RETR_TREE", nullptr));

        label_10->setText(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\347\232\204\350\277\221\344\274\274\346\226\271\346\263\225\357\274\232", nullptr));
        comboMethod->setItemText(0, QCoreApplication::translate("frmSelectShapeClass", "CHAIN_APPROX_NONE", nullptr));
        comboMethod->setItemText(1, QCoreApplication::translate("frmSelectShapeClass", "CHAIN_APPROX_SIMPLE", nullptr));
        comboMethod->setItemText(2, QCoreApplication::translate("frmSelectShapeClass", "CHAIN_APPROX_TC89_L1", nullptr));
        comboMethod->setItemText(3, QCoreApplication::translate("frmSelectShapeClass", "CHAIN_APPROX_TC89_KCOS", nullptr));

        label_11->setText(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\347\232\204\345\275\242\347\212\266\347\211\271\345\276\201\357\274\232", nullptr));
        comboCMode->setItemText(0, QCoreApplication::translate("frmSelectShapeClass", "area", nullptr));
        comboCMode->setItemText(1, QCoreApplication::translate("frmSelectShapeClass", "max_area", nullptr));
        comboCMode->setItemText(2, QCoreApplication::translate("frmSelectShapeClass", "contlength", nullptr));
        comboCMode->setItemText(3, QCoreApplication::translate("frmSelectShapeClass", "vertices", nullptr));
        comboCMode->setItemText(4, QCoreApplication::translate("frmSelectShapeClass", "circle_radius", nullptr));
        comboCMode->setItemText(5, QCoreApplication::translate("frmSelectShapeClass", "rectangularity", nullptr));
        comboCMode->setItemText(6, QCoreApplication::translate("frmSelectShapeClass", "inner_width", nullptr));
        comboCMode->setItemText(7, QCoreApplication::translate("frmSelectShapeClass", "inner_height", nullptr));
        comboCMode->setItemText(8, QCoreApplication::translate("frmSelectShapeClass", "row", nullptr));
        comboCMode->setItemText(9, QCoreApplication::translate("frmSelectShapeClass", "column", nullptr));
        comboCMode->setItemText(10, QCoreApplication::translate("frmSelectShapeClass", "rect2_len1", nullptr));
        comboCMode->setItemText(11, QCoreApplication::translate("frmSelectShapeClass", "rect2_len2", nullptr));
        comboCMode->setItemText(12, QCoreApplication::translate("frmSelectShapeClass", "rect2_phi", nullptr));
        comboCMode->setItemText(13, QCoreApplication::translate("frmSelectShapeClass", "ellipse_lena", nullptr));
        comboCMode->setItemText(14, QCoreApplication::translate("frmSelectShapeClass", "ellipse_lenb", nullptr));
        comboCMode->setItemText(15, QCoreApplication::translate("frmSelectShapeClass", "ellipse_phi", nullptr));

        groupParam->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\351\235\242\347\247\257\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\351\235\242\347\247\257\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\351\235\242\347\247\257\357\274\232", nullptr));
        groupParam_2->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\351\225\277\345\272\246\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\351\225\277\345\272\246\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\351\225\277\345\272\246\357\274\232", nullptr));
        groupParam_3->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\351\241\266\347\202\271\346\225\260\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_12->setText(QCoreApplication::translate("frmSelectShapeClass", "\351\241\266\347\202\271\344\270\252\346\225\260\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("frmSelectShapeClass", "\345\207\240\344\275\225\351\200\274\350\277\221\347\263\273\346\225\260\357\274\232", nullptr));
        groupParam_4->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\345\234\206\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_13->setText(QCoreApplication::translate("frmSelectShapeClass", "\345\234\206\346\234\200\345\260\217\345\215\212\345\276\204\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("frmSelectShapeClass", "\345\234\206\346\234\200\345\244\247\345\215\212\345\276\204\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\345\234\206\345\272\246\357\274\232", nullptr));
        label_19->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\345\234\206\345\272\246\357\274\232", nullptr));
        groupParam_5->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\347\237\251\345\275\242\345\272\246\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_20->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\347\237\251\345\275\242\345\272\246\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\347\237\251\345\275\242\345\272\246\357\274\232", nullptr));
        groupParam_6->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\345\244\226\346\216\245\347\237\251\345\275\242\345\256\275\345\272\246\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_22->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\345\256\275\345\272\246\357\274\232", nullptr));
        label_23->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\345\256\275\345\272\246\357\274\232", nullptr));
        groupParam_7->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\345\244\226\346\216\245\347\237\251\345\275\242\351\253\230\345\272\246\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_24->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\351\253\230\345\272\246\357\274\232", nullptr));
        label_25->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\351\253\230\345\272\246\357\274\232", nullptr));
        groupParam_8->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\350\241\214\345\235\220\346\240\207\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_26->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\350\241\214\345\235\220\346\240\207\357\274\232", nullptr));
        label_27->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\350\241\214\345\235\220\346\240\207\357\274\232", nullptr));
        groupParam_9->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\345\210\227\345\235\220\346\240\207\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_28->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\345\210\227\345\235\220\346\240\207\357\274\232", nullptr));
        label_29->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\345\210\227\345\235\220\346\240\207\357\274\232", nullptr));
        groupParam_10->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\346\234\200\345\260\217\345\244\226\346\216\245\347\237\251\345\275\242\347\232\204\344\270\200\345\215\212\351\225\277\345\272\246\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_31->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\345\215\212\351\225\277\357\274\232", nullptr));
        label_32->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\345\215\212\351\225\277\357\274\232", nullptr));
        groupParam_11->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\346\234\200\345\260\217\345\244\226\346\216\245\347\237\251\345\275\242\347\232\204\344\270\200\345\215\212\345\256\275\345\272\246\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_33->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\345\215\212\345\256\275\357\274\232", nullptr));
        label_34->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\345\215\212\345\256\275\357\274\232", nullptr));
        groupParam_12->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\346\234\200\345\260\217\345\244\226\346\216\245\347\237\251\345\275\242\347\232\204\346\226\271\345\220\221\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_35->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\350\247\222\345\272\246\357\274\232", nullptr));
        label_36->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\350\247\222\345\272\246\357\274\232", nullptr));
        groupParam_13->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\346\234\200\345\260\217\345\244\226\346\216\245\346\244\255\345\234\206\347\232\204\351\225\277\345\215\212\350\275\264\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_37->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\351\225\277\345\215\212\350\275\264\357\274\232", nullptr));
        label_38->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\351\225\277\345\215\212\350\275\264\357\274\232", nullptr));
        groupParam_14->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\346\234\200\345\260\217\345\244\226\346\216\245\346\244\255\345\234\206\347\232\204\347\237\255\345\215\212\350\275\264\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_39->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\347\237\255\345\215\212\350\275\264\357\274\232", nullptr));
        label_40->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\347\237\255\345\215\212\350\275\264\357\274\232", nullptr));
        groupParam_15->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\346\234\200\345\260\217\345\244\226\346\216\245\346\244\255\345\234\206\347\232\204\346\226\271\345\220\221\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_41->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\244\247\350\247\222\345\272\246\357\274\232", nullptr));
        label_42->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\234\200\345\260\217\350\247\222\345\272\246\357\274\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetType->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmSelectShapeClass", "\345\275\242\347\212\266\347\211\271\345\276\201\347\261\273\345\210\253", nullptr));
        btnAddType->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteType->setText(QCoreApplication::translate("frmSelectShapeClass", "\345\210\240\351\231\244", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("frmSelectShapeClass", "and", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("frmSelectShapeClass", "or", nullptr));

        label_30->setText(QCoreApplication::translate("frmSelectShapeClass", "\350\275\256\345\273\223\347\211\271\345\276\201\347\232\204\351\223\276\346\216\245\347\261\273\345\236\213\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmSelectShapeClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupCamera_8->setTitle(QCoreApplication::translate("frmSelectShapeClass", "ROI\345\257\271\350\261\241", nullptr));
        checkUseROI->setText(QCoreApplication::translate("frmSelectShapeClass", "\344\275\277\347\224\250ROI", nullptr));
        comboROIShape->setItemText(0, QCoreApplication::translate("frmSelectShapeClass", "\347\237\251\345\275\242", nullptr));
        comboROIShape->setItemText(1, QCoreApplication::translate("frmSelectShapeClass", "\346\227\213\350\275\254\347\237\251\345\275\242", nullptr));
        comboROIShape->setItemText(2, QCoreApplication::translate("frmSelectShapeClass", "\345\234\206\345\275\242", nullptr));
        comboROIShape->setItemText(3, QCoreApplication::translate("frmSelectShapeClass", "\345\244\232\350\276\271\345\275\242", nullptr));

        btnAddROI->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteROI->setText(QCoreApplication::translate("frmSelectShapeClass", "\345\210\240\351\231\244", nullptr));
        checkViewROI->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\230\276\347\244\272ROI", nullptr));
        label_16->setText(QCoreApplication::translate("frmSelectShapeClass", "ROI\345\256\275\345\272\246\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("frmSelectShapeClass", "ROI\351\242\234\350\211\262\357\274\232", nullptr));
        btnRoiColor->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmSelectShapeClass", "ROI\350\256\276\347\275\256", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmSelectShapeClass", "\350\276\223\345\207\272\346\225\260\346\215\256(\350\275\256\345\273\223\347\232\204\344\270\252\346\225\260\343\200\201\351\235\242\347\247\257\343\200\201\351\207\215\345\277\203)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("frmSelectShapeClass", "\350\276\223\345\207\272\346\230\276\347\244\272", nullptr));
        label_3->setText(QCoreApplication::translate("frmSelectShapeClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmSelectShapeClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmSelectShapeClass: public Ui_frmSelectShapeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSELECTSHAPE_H
