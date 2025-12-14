/********************************************************************************
** Form generated from reading UI file 'frmLinearCalculation.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLINEARCALCULATION_H
#define UI_FRMLINEARCALCULATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmLinearCalculationClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupC1;
    QLineEdit *txtLinkERTCalib;
    QPushButton *btnLinkERTCalib;
    QPushButton *btnDelLinkERTCalib;
    QCheckBox *checkUseERTCalib;
    QLabel *label_5;
    QComboBox *comboMethod;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frame_1;
    QPushButton *btnDelLinkDatumPoint;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *txtLinkRotateCenter;
    QLineEdit *txtLinkDatumPoint;
    QPushButton *btnLinkDatumPoint;
    QPushButton *btnLinkRotateCenter;
    QPushButton *btnDelLinkRotateCenter;
    QPushButton *btnLinkCurrentPoint;
    QPushButton *btnLinkRotateAngle;
    QLabel *label_10;
    QPushButton *btnDelLinkRotateAngle;
    QLineEdit *txtLinkCurrentPoint;
    QLabel *label_11;
    QPushButton *btnDelLinkCurrentPoint;
    QLineEdit *txtLinkRotateAngle;
    QWidget *page_2;
    QFrame *frame_2;
    QPushButton *btnDelLinkDatumPoint2;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *txtLinkDatumPoint1;
    QLineEdit *txtLinkDatumPoint2;
    QPushButton *btnLinkDatumPoint2;
    QPushButton *btnLinkDatumPoint1;
    QPushButton *btnDelLinkDatumPoint1;
    QPushButton *btnLinkCurrentPoint1;
    QPushButton *btnLinkRotateAngle1;
    QLabel *label_14;
    QPushButton *btnDelLinkRotateAngle1;
    QLineEdit *txtLinkCurrentPoint1;
    QLabel *label_15;
    QPushButton *btnDelLinkCurrentPoint1;
    QLineEdit *txtLinkRotateAngle1;
    QWidget *page_3;
    QFrame *frame_3;
    QPushButton *btnDelLinkImagePoint;
    QLabel *label_17;
    QLineEdit *txtLinkImagePoint;
    QPushButton *btnLinkImagePoint;
    QWidget *tab_2;
    QGroupBox *groupC2;
    QTextEdit *txtMsg;

    void setupUi(QDialog *frmLinearCalculationClass)
    {
        if (frmLinearCalculationClass->objectName().isEmpty())
            frmLinearCalculationClass->setObjectName(QString::fromUtf8("frmLinearCalculationClass"));
        frmLinearCalculationClass->resize(613, 463);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmLinearCalculationClass->sizePolicy().hasHeightForWidth());
        frmLinearCalculationClass->setSizePolicy(sizePolicy);
        frmLinearCalculationClass->setMinimumSize(QSize(613, 463));
        frmLinearCalculationClass->setMaximumSize(QSize(613, 463));
        frmLinearCalculationClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmLinearCalculationClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmLinearCalculationClass);
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

        txtDescribe = new QLineEdit(frmLinearCalculationClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmLinearCalculationClass);
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


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 2);

        tabWidget = new QTabWidget(frmLinearCalculationClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(450, 0));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupC1 = new QGroupBox(tab);
        groupC1->setObjectName(QString::fromUtf8("groupC1"));
        groupC1->setGeometry(QRect(9, 16, 590, 311));
        groupC1->setFont(font);
        groupC1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtLinkERTCalib = new QLineEdit(groupC1);
        txtLinkERTCalib->setObjectName(QString::fromUtf8("txtLinkERTCalib"));
        txtLinkERTCalib->setEnabled(true);
        txtLinkERTCalib->setGeometry(QRect(143, 31, 370, 30));
        txtLinkERTCalib->setFont(font);
        txtLinkERTCalib->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkERTCalib->setAlignment(Qt::AlignCenter);
        txtLinkERTCalib->setReadOnly(true);
        btnLinkERTCalib = new QPushButton(groupC1);
        btnLinkERTCalib->setObjectName(QString::fromUtf8("btnLinkERTCalib"));
        btnLinkERTCalib->setEnabled(false);
        btnLinkERTCalib->setGeometry(QRect(518, 33, 27, 27));
        btnLinkERTCalib->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkERTCalib->setIcon(icon);
        btnLinkERTCalib->setIconSize(QSize(27, 27));
        btnDelLinkERTCalib = new QPushButton(groupC1);
        btnDelLinkERTCalib->setObjectName(QString::fromUtf8("btnDelLinkERTCalib"));
        btnDelLinkERTCalib->setEnabled(false);
        btnDelLinkERTCalib->setGeometry(QRect(552, 33, 27, 27));
        btnDelLinkERTCalib->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkERTCalib->setIcon(icon1);
        btnDelLinkERTCalib->setIconSize(QSize(27, 27));
        checkUseERTCalib = new QCheckBox(groupC1);
        checkUseERTCalib->setObjectName(QString::fromUtf8("checkUseERTCalib"));
        checkUseERTCalib->setEnabled(false);
        checkUseERTCalib->setGeometry(QRect(13, 32, 128, 27));
        sizePolicy.setHeightForWidth(checkUseERTCalib->sizePolicy().hasHeightForWidth());
        checkUseERTCalib->setSizePolicy(sizePolicy);
        checkUseERTCalib->setFont(font);
        checkUseERTCalib->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkUseERTCalib->setIconSize(QSize(22, 22));
        label_5 = new QLabel(groupC1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 88, 113, 19));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboMethod = new QComboBox(groupC1);
        comboMethod->addItem(QString());
        comboMethod->addItem(QString());
        comboMethod->addItem(QString());
        comboMethod->setObjectName(QString::fromUtf8("comboMethod"));
        comboMethod->setGeometry(QRect(143, 83, 370, 30));
        comboMethod->setFont(font);
        comboMethod->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        stackedWidget = new QStackedWidget(groupC1);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(1, 118, 588, 191));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        frame_1 = new QFrame(page);
        frame_1->setObjectName(QString::fromUtf8("frame_1"));
        frame_1->setGeometry(QRect(0, 14, 590, 177));
        frame_1->setStyleSheet(QString::fromUtf8(""));
        frame_1->setFrameShape(QFrame::StyledPanel);
        frame_1->setFrameShadow(QFrame::Raised);
        btnDelLinkDatumPoint = new QPushButton(frame_1);
        btnDelLinkDatumPoint->setObjectName(QString::fromUtf8("btnDelLinkDatumPoint"));
        btnDelLinkDatumPoint->setGeometry(QRect(552, 48, 27, 27));
        btnDelLinkDatumPoint->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkDatumPoint->setIcon(icon1);
        btnDelLinkDatumPoint->setIconSize(QSize(27, 27));
        label_8 = new QLabel(frame_1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(13, 8, 80, 19));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        label_9 = new QLabel(frame_1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(13, 52, 80, 19));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        txtLinkRotateCenter = new QLineEdit(frame_1);
        txtLinkRotateCenter->setObjectName(QString::fromUtf8("txtLinkRotateCenter"));
        txtLinkRotateCenter->setGeometry(QRect(96, 3, 417, 30));
        txtLinkRotateCenter->setFont(font);
        txtLinkRotateCenter->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkRotateCenter->setAlignment(Qt::AlignCenter);
        txtLinkRotateCenter->setReadOnly(true);
        txtLinkDatumPoint = new QLineEdit(frame_1);
        txtLinkDatumPoint->setObjectName(QString::fromUtf8("txtLinkDatumPoint"));
        txtLinkDatumPoint->setGeometry(QRect(96, 47, 417, 30));
        txtLinkDatumPoint->setFont(font);
        txtLinkDatumPoint->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkDatumPoint->setAlignment(Qt::AlignCenter);
        txtLinkDatumPoint->setReadOnly(true);
        btnLinkDatumPoint = new QPushButton(frame_1);
        btnLinkDatumPoint->setObjectName(QString::fromUtf8("btnLinkDatumPoint"));
        btnLinkDatumPoint->setGeometry(QRect(518, 48, 27, 27));
        btnLinkDatumPoint->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkDatumPoint->setIcon(icon);
        btnLinkDatumPoint->setIconSize(QSize(27, 27));
        btnLinkRotateCenter = new QPushButton(frame_1);
        btnLinkRotateCenter->setObjectName(QString::fromUtf8("btnLinkRotateCenter"));
        btnLinkRotateCenter->setGeometry(QRect(518, 4, 27, 27));
        btnLinkRotateCenter->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkRotateCenter->setIcon(icon);
        btnLinkRotateCenter->setIconSize(QSize(27, 27));
        btnDelLinkRotateCenter = new QPushButton(frame_1);
        btnDelLinkRotateCenter->setObjectName(QString::fromUtf8("btnDelLinkRotateCenter"));
        btnDelLinkRotateCenter->setGeometry(QRect(552, 4, 27, 27));
        btnDelLinkRotateCenter->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkRotateCenter->setIcon(icon1);
        btnDelLinkRotateCenter->setIconSize(QSize(27, 27));
        btnLinkCurrentPoint = new QPushButton(frame_1);
        btnLinkCurrentPoint->setObjectName(QString::fromUtf8("btnLinkCurrentPoint"));
        btnLinkCurrentPoint->setGeometry(QRect(518, 94, 27, 27));
        btnLinkCurrentPoint->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkCurrentPoint->setIcon(icon);
        btnLinkCurrentPoint->setIconSize(QSize(27, 27));
        btnLinkRotateAngle = new QPushButton(frame_1);
        btnLinkRotateAngle->setObjectName(QString::fromUtf8("btnLinkRotateAngle"));
        btnLinkRotateAngle->setGeometry(QRect(518, 138, 27, 27));
        btnLinkRotateAngle->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkRotateAngle->setIcon(icon);
        btnLinkRotateAngle->setIconSize(QSize(27, 27));
        label_10 = new QLabel(frame_1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(13, 142, 80, 19));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        btnDelLinkRotateAngle = new QPushButton(frame_1);
        btnDelLinkRotateAngle->setObjectName(QString::fromUtf8("btnDelLinkRotateAngle"));
        btnDelLinkRotateAngle->setGeometry(QRect(552, 138, 27, 27));
        btnDelLinkRotateAngle->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkRotateAngle->setIcon(icon1);
        btnDelLinkRotateAngle->setIconSize(QSize(27, 27));
        txtLinkCurrentPoint = new QLineEdit(frame_1);
        txtLinkCurrentPoint->setObjectName(QString::fromUtf8("txtLinkCurrentPoint"));
        txtLinkCurrentPoint->setGeometry(QRect(96, 93, 417, 30));
        txtLinkCurrentPoint->setFont(font);
        txtLinkCurrentPoint->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkCurrentPoint->setAlignment(Qt::AlignCenter);
        txtLinkCurrentPoint->setReadOnly(true);
        label_11 = new QLabel(frame_1);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(13, 98, 80, 19));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        btnDelLinkCurrentPoint = new QPushButton(frame_1);
        btnDelLinkCurrentPoint->setObjectName(QString::fromUtf8("btnDelLinkCurrentPoint"));
        btnDelLinkCurrentPoint->setGeometry(QRect(552, 94, 27, 27));
        btnDelLinkCurrentPoint->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkCurrentPoint->setIcon(icon1);
        btnDelLinkCurrentPoint->setIconSize(QSize(27, 27));
        txtLinkRotateAngle = new QLineEdit(frame_1);
        txtLinkRotateAngle->setObjectName(QString::fromUtf8("txtLinkRotateAngle"));
        txtLinkRotateAngle->setGeometry(QRect(96, 137, 417, 30));
        txtLinkRotateAngle->setFont(font);
        txtLinkRotateAngle->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkRotateAngle->setAlignment(Qt::AlignCenter);
        txtLinkRotateAngle->setReadOnly(true);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        frame_2 = new QFrame(page_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 14, 590, 177));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        btnDelLinkDatumPoint2 = new QPushButton(frame_2);
        btnDelLinkDatumPoint2->setObjectName(QString::fromUtf8("btnDelLinkDatumPoint2"));
        btnDelLinkDatumPoint2->setGeometry(QRect(552, 48, 27, 27));
        btnDelLinkDatumPoint2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkDatumPoint2->setIcon(icon1);
        btnDelLinkDatumPoint2->setIconSize(QSize(27, 27));
        label_12 = new QLabel(frame_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(13, 8, 80, 19));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        label_13 = new QLabel(frame_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(13, 52, 80, 19));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        txtLinkDatumPoint1 = new QLineEdit(frame_2);
        txtLinkDatumPoint1->setObjectName(QString::fromUtf8("txtLinkDatumPoint1"));
        txtLinkDatumPoint1->setGeometry(QRect(96, 3, 417, 30));
        txtLinkDatumPoint1->setFont(font);
        txtLinkDatumPoint1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkDatumPoint1->setAlignment(Qt::AlignCenter);
        txtLinkDatumPoint1->setReadOnly(true);
        txtLinkDatumPoint2 = new QLineEdit(frame_2);
        txtLinkDatumPoint2->setObjectName(QString::fromUtf8("txtLinkDatumPoint2"));
        txtLinkDatumPoint2->setGeometry(QRect(96, 47, 417, 30));
        txtLinkDatumPoint2->setFont(font);
        txtLinkDatumPoint2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkDatumPoint2->setAlignment(Qt::AlignCenter);
        txtLinkDatumPoint2->setReadOnly(true);
        btnLinkDatumPoint2 = new QPushButton(frame_2);
        btnLinkDatumPoint2->setObjectName(QString::fromUtf8("btnLinkDatumPoint2"));
        btnLinkDatumPoint2->setGeometry(QRect(518, 48, 27, 27));
        btnLinkDatumPoint2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkDatumPoint2->setIcon(icon);
        btnLinkDatumPoint2->setIconSize(QSize(27, 27));
        btnLinkDatumPoint1 = new QPushButton(frame_2);
        btnLinkDatumPoint1->setObjectName(QString::fromUtf8("btnLinkDatumPoint1"));
        btnLinkDatumPoint1->setGeometry(QRect(518, 4, 27, 27));
        btnLinkDatumPoint1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkDatumPoint1->setIcon(icon);
        btnLinkDatumPoint1->setIconSize(QSize(27, 27));
        btnDelLinkDatumPoint1 = new QPushButton(frame_2);
        btnDelLinkDatumPoint1->setObjectName(QString::fromUtf8("btnDelLinkDatumPoint1"));
        btnDelLinkDatumPoint1->setGeometry(QRect(552, 4, 27, 27));
        btnDelLinkDatumPoint1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkDatumPoint1->setIcon(icon1);
        btnDelLinkDatumPoint1->setIconSize(QSize(27, 27));
        btnLinkCurrentPoint1 = new QPushButton(frame_2);
        btnLinkCurrentPoint1->setObjectName(QString::fromUtf8("btnLinkCurrentPoint1"));
        btnLinkCurrentPoint1->setGeometry(QRect(518, 94, 27, 27));
        btnLinkCurrentPoint1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkCurrentPoint1->setIcon(icon);
        btnLinkCurrentPoint1->setIconSize(QSize(27, 27));
        btnLinkRotateAngle1 = new QPushButton(frame_2);
        btnLinkRotateAngle1->setObjectName(QString::fromUtf8("btnLinkRotateAngle1"));
        btnLinkRotateAngle1->setGeometry(QRect(518, 138, 27, 27));
        btnLinkRotateAngle1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkRotateAngle1->setIcon(icon);
        btnLinkRotateAngle1->setIconSize(QSize(27, 27));
        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(13, 142, 80, 19));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        btnDelLinkRotateAngle1 = new QPushButton(frame_2);
        btnDelLinkRotateAngle1->setObjectName(QString::fromUtf8("btnDelLinkRotateAngle1"));
        btnDelLinkRotateAngle1->setGeometry(QRect(552, 138, 27, 27));
        btnDelLinkRotateAngle1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkRotateAngle1->setIcon(icon1);
        btnDelLinkRotateAngle1->setIconSize(QSize(27, 27));
        txtLinkCurrentPoint1 = new QLineEdit(frame_2);
        txtLinkCurrentPoint1->setObjectName(QString::fromUtf8("txtLinkCurrentPoint1"));
        txtLinkCurrentPoint1->setGeometry(QRect(96, 93, 417, 30));
        txtLinkCurrentPoint1->setFont(font);
        txtLinkCurrentPoint1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkCurrentPoint1->setAlignment(Qt::AlignCenter);
        txtLinkCurrentPoint1->setReadOnly(true);
        label_15 = new QLabel(frame_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(13, 98, 80, 19));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        btnDelLinkCurrentPoint1 = new QPushButton(frame_2);
        btnDelLinkCurrentPoint1->setObjectName(QString::fromUtf8("btnDelLinkCurrentPoint1"));
        btnDelLinkCurrentPoint1->setGeometry(QRect(552, 94, 27, 27));
        btnDelLinkCurrentPoint1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkCurrentPoint1->setIcon(icon1);
        btnDelLinkCurrentPoint1->setIconSize(QSize(27, 27));
        txtLinkRotateAngle1 = new QLineEdit(frame_2);
        txtLinkRotateAngle1->setObjectName(QString::fromUtf8("txtLinkRotateAngle1"));
        txtLinkRotateAngle1->setGeometry(QRect(96, 137, 417, 30));
        txtLinkRotateAngle1->setFont(font);
        txtLinkRotateAngle1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkRotateAngle1->setAlignment(Qt::AlignCenter);
        txtLinkRotateAngle1->setReadOnly(true);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        frame_3 = new QFrame(page_3);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 14, 590, 177));
        frame_3->setStyleSheet(QString::fromUtf8(""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        btnDelLinkImagePoint = new QPushButton(frame_3);
        btnDelLinkImagePoint->setObjectName(QString::fromUtf8("btnDelLinkImagePoint"));
        btnDelLinkImagePoint->setGeometry(QRect(552, 60, 27, 27));
        btnDelLinkImagePoint->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkImagePoint->setIcon(icon1);
        btnDelLinkImagePoint->setIconSize(QSize(27, 27));
        label_17 = new QLabel(frame_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(13, 64, 95, 19));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        txtLinkImagePoint = new QLineEdit(frame_3);
        txtLinkImagePoint->setObjectName(QString::fromUtf8("txtLinkImagePoint"));
        txtLinkImagePoint->setGeometry(QRect(118, 59, 395, 30));
        txtLinkImagePoint->setFont(font);
        txtLinkImagePoint->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkImagePoint->setAlignment(Qt::AlignCenter);
        txtLinkImagePoint->setReadOnly(true);
        btnLinkImagePoint = new QPushButton(frame_3);
        btnLinkImagePoint->setObjectName(QString::fromUtf8("btnLinkImagePoint"));
        btnLinkImagePoint->setGeometry(QRect(518, 60, 27, 27));
        btnLinkImagePoint->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkImagePoint->setIcon(icon);
        btnLinkImagePoint->setIconSize(QSize(27, 27));
        stackedWidget->addWidget(page_3);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupC2 = new QGroupBox(tab_2);
        groupC2->setObjectName(QString::fromUtf8("groupC2"));
        groupC2->setGeometry(QRect(9, 16, 590, 311));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC2);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 583, 276));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        txtMsg->setFont(font1);
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

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(frmLinearCalculationClass);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmLinearCalculationClass);
    } // setupUi

    void retranslateUi(QDialog *frmLinearCalculationClass)
    {
        frmLinearCalculationClass->setWindowTitle(QCoreApplication::translate("frmLinearCalculationClass", "\347\272\277\346\200\247\350\256\241\347\256\227", nullptr));
        label_3->setText(QCoreApplication::translate("frmLinearCalculationClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmLinearCalculationClass", "\346\211\247\350\241\214", nullptr));
        groupC1->setTitle(QCoreApplication::translate("frmLinearCalculationClass", "\350\276\223\345\205\245\345\257\271\350\261\241", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkERTCalib->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "N\347\202\271\346\240\207\345\256\232\345\217\202\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkERTCalib->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\351\223\276\346\216\245N\347\202\271\346\240\207\345\256\232", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkERTCalib->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkERTCalib->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\345\210\240\351\231\244N\347\202\271\346\240\207\345\256\232\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkERTCalib->setText(QString());
        checkUseERTCalib->setText(QCoreApplication::translate("frmLinearCalculationClass", "\344\275\277\347\224\250N\347\202\271\346\240\207\345\256\232", nullptr));
        label_5->setText(QCoreApplication::translate("frmLinearCalculationClass", "\347\272\277\346\200\247\350\256\241\347\256\227\346\226\271\346\263\225\357\274\232", nullptr));
        comboMethod->setItemText(0, QCoreApplication::translate("frmLinearCalculationClass", "\350\256\241\347\256\227Robot\347\247\273\345\212\250\351\207\217(\344\275\277\347\224\250\346\227\213\350\275\254\344\270\255\345\277\203)", nullptr));
        comboMethod->setItemText(1, QCoreApplication::translate("frmLinearCalculationClass", "\350\256\241\347\256\227Robot\347\247\273\345\212\250\351\207\217(\344\270\215\344\275\277\347\224\250\346\227\213\350\275\254\344\270\255\345\277\203)", nullptr));
        comboMethod->setItemText(2, QCoreApplication::translate("frmLinearCalculationClass", "\345\233\276\345\203\217\345\235\220\346\240\207\347\263\273\347\273\237 --> \344\270\226\347\225\214\345\235\220\346\240\207\347\263\273\347\273\237", nullptr));

#if QT_CONFIG(tooltip)
        btnDelLinkDatumPoint->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\345\210\240\351\231\244\345\237\272\345\207\206\347\202\271\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkDatumPoint->setText(QString());
        label_8->setText(QCoreApplication::translate("frmLinearCalculationClass", "\346\227\213\350\275\254\344\270\255\345\277\203\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("frmLinearCalculationClass", "\345\237\272\345\207\206\347\202\271\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkRotateCenter->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        txtLinkDatumPoint->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "cv::Point2f\347\261\273\345\236\213--\346\240\207\345\207\206\345\267\245\344\273\266(Mark)\345\235\220\346\240\207\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkDatumPoint->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\351\223\276\346\216\245\345\237\272\345\207\206\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkDatumPoint->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkRotateCenter->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\351\223\276\346\216\245\346\227\213\350\275\254\344\270\255\345\277\203", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkRotateCenter->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkRotateCenter->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\345\210\240\351\231\244\346\227\213\350\275\254\344\270\255\345\277\203\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkRotateCenter->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkCurrentPoint->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\351\223\276\346\216\245\345\275\223\345\211\215\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkCurrentPoint->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkRotateAngle->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\351\223\276\346\216\245\346\227\213\350\275\254\350\247\222\345\272\246", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkRotateAngle->setText(QString());
        label_10->setText(QCoreApplication::translate("frmLinearCalculationClass", "\346\227\213\350\275\254\350\247\222\345\272\246\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkRotateAngle->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\345\210\240\351\231\244\346\227\213\350\275\254\350\247\222\345\272\246\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkRotateAngle->setText(QString());
#if QT_CONFIG(tooltip)
        txtLinkCurrentPoint->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "cv::Point2f\347\261\273\345\236\213--\345\267\245\344\273\266\347\247\273\345\212\250\345\220\216\346\226\260\347\232\204(Mark)\345\235\220\346\240\207\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        label_11->setText(QCoreApplication::translate("frmLinearCalculationClass", "\345\275\223\345\211\215\347\202\271\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkCurrentPoint->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\345\210\240\351\231\244\345\275\223\345\211\215\347\202\271\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkCurrentPoint->setText(QString());
#if QT_CONFIG(tooltip)
        txtLinkRotateAngle->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "Double\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnDelLinkDatumPoint2->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\345\210\240\351\231\244\345\237\272\345\207\206\347\202\2712\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkDatumPoint2->setText(QString());
        label_12->setText(QCoreApplication::translate("frmLinearCalculationClass", "\345\237\272\345\207\206\347\202\2711\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("frmLinearCalculationClass", "\345\237\272\345\207\206\347\202\2712\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkDatumPoint1->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "cv::Point2f\347\261\273\345\236\213--\346\240\207\345\207\206\345\267\245\344\273\266(Mark)\345\235\220\346\240\207\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        txtLinkDatumPoint2->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "cv::Point2f\347\261\273\345\236\213--\346\240\207\345\207\206\345\267\245\344\273\266(Mark)\347\273\225\346\227\213\350\275\254\344\270\255\345\277\203\346\227\213\350\275\254\345\220\216\347\232\204\345\235\220\346\240\207\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkDatumPoint2->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\351\223\276\346\216\245\345\237\272\345\207\206\347\202\2712", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkDatumPoint2->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkDatumPoint1->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\351\223\276\346\216\245\345\237\272\345\207\206\347\202\2711", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkDatumPoint1->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkDatumPoint1->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\345\210\240\351\231\244\345\237\272\345\207\206\347\202\2711\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkDatumPoint1->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkCurrentPoint1->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\351\223\276\346\216\245\345\275\223\345\211\215\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkCurrentPoint1->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkRotateAngle1->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\351\223\276\346\216\245\346\227\213\350\275\254\350\247\222\345\272\246", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkRotateAngle1->setText(QString());
        label_14->setText(QCoreApplication::translate("frmLinearCalculationClass", "\346\227\213\350\275\254\350\247\222\345\272\246\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkRotateAngle1->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\345\210\240\351\231\244\346\227\213\350\275\254\350\247\222\345\272\246\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkRotateAngle1->setText(QString());
#if QT_CONFIG(tooltip)
        txtLinkCurrentPoint1->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "cv::Point2f\347\261\273\345\236\213--\345\267\245\344\273\266\347\247\273\345\212\250\345\220\216\346\226\260\347\232\204(Mark)\345\235\220\346\240\207\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        label_15->setText(QCoreApplication::translate("frmLinearCalculationClass", "\345\275\223\345\211\215\347\202\271\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkCurrentPoint1->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\345\210\240\351\231\244\345\275\223\345\211\215\347\202\271\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkCurrentPoint1->setText(QString());
#if QT_CONFIG(tooltip)
        txtLinkRotateAngle1->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "Double\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnDelLinkImagePoint->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\345\210\240\351\231\244\345\233\276\345\203\217\345\235\220\346\240\207\347\202\271\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImagePoint->setText(QString());
        label_17->setText(QCoreApplication::translate("frmLinearCalculationClass", "\345\233\276\345\203\217\345\235\220\346\240\207\347\202\271\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkImagePoint->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkImagePoint->setToolTip(QCoreApplication::translate("frmLinearCalculationClass", "\351\223\276\346\216\245\345\233\276\345\203\217\345\235\220\346\240\207\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImagePoint->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmLinearCalculationClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupC2->setTitle(QCoreApplication::translate("frmLinearCalculationClass", "\350\276\223\345\207\272\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmLinearCalculationClass", "\350\276\223\345\207\272\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmLinearCalculationClass: public Ui_frmLinearCalculationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLINEARCALCULATION_H
