/********************************************************************************
** Form generated from reading UI file 'frmInstrumentation.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMINSTRUMENTATION_H
#define UI_FRMINSTRUMENTATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ipaddress.h"

QT_BEGIN_NAMESPACE

class Ui_frmInstrumentationClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnConnect;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnDisconnect;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnSave;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QComboBox *comboInstrumentName;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_3;
    QLabel *lblType;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_4;
    QGridLayout *gridLayout_3;
    QLabel *label_12;
    QLabel *label_4;
    QLineEdit *txtIoRemark;
    QLabel *label_10;
    IPAddress *widgetIoIP;
    QSpinBox *spinIoTimeOut;
    QLabel *label_11;
    QSpacerItem *verticalSpacer_3;
    QSpinBox *spinIoPort;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_5;
    QGridLayout *gridLayout_4;
    QLabel *label_14;
    QLabel *label_5;
    QSpinBox *spinPlcPort;
    QLabel *label_17;
    QLineEdit *txtPlcRemark;
    QLabel *label_15;
    QSpinBox *spinPlcTimeOut;
    QSpacerItem *verticalSpacer_4;
    IPAddress *widgetPlcIP;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame_6;
    QGridLayout *gridLayout_5;
    QComboBox *comboFlowControl;
    QLabel *label_19;
    QLabel *label_8;
    QLabel *label_18;
    QComboBox *comboSerialPort;
    QLineEdit *txtSPRemark;
    QLabel *label_6;
    QLabel *label_9;
    QComboBox *comboCheckDigit;
    QLabel *label_21;
    QComboBox *comboStopBit;
    QComboBox *comboBaudRate;
    QComboBox *comboDataBits;
    QLabel *label_7;
    QPlainTextEdit *plainTextEdit_2;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_7;
    QGridLayout *gridLayout_6;
    QPlainTextEdit *plainTextEdit;
    QComboBox *comboProtocol;
    QLineEdit *txtSocketRemark;
    QLabel *label_20;
    QLabel *lbl_ip;
    IPAddress *widgetSocketIP;
    QLabel *label_22;
    QLabel *lbl_port;
    QSpinBox *spinSocketPort;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *comboInstrument;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnAdd;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *frmInstrumentationClass)
    {
        if (frmInstrumentationClass->objectName().isEmpty())
            frmInstrumentationClass->setObjectName(QString::fromUtf8("frmInstrumentationClass"));
        frmInstrumentationClass->resize(850, 530);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmInstrumentationClass->sizePolicy().hasHeightForWidth());
        frmInstrumentationClass->setSizePolicy(sizePolicy);
        frmInstrumentationClass->setMinimumSize(QSize(850, 530));
        frmInstrumentationClass->setMaximumSize(QSize(850, 530));
        frmInstrumentationClass->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        verticalLayout_2 = new QVBoxLayout(frmInstrumentationClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 2, 2, 2);
        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, -1, 2, 2);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(frmInstrumentationClass);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: #b7c7a7;  \n"
"    border:none;\n"
"    gridline-color: rgba(220, 220, 255,255);\n"
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
"		background:url(:/res/ico/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/res/ico/up.png) center no-repeat;}\n"
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
"		background:url(:/res/ico/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/res/ico/left.png) center no-repeat;}"));
        tableWidget->setGridStyle(Qt::DashLine);
        tableWidget->horizontalHeader()->setDefaultSectionSize(256);

        verticalLayout->addWidget(tableWidget);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_3 = new QFrame(frmInstrumentationClass);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_3);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(3, 3, 3, 3);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        btnConnect = new QPushButton(frame_3);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setMinimumSize(QSize(90, 37));
        btnConnect->setFont(font);
        btnConnect->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        horizontalLayout_6->addWidget(btnConnect);

        horizontalSpacer_5 = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        btnDisconnect = new QPushButton(frame_3);
        btnDisconnect->setObjectName(QString::fromUtf8("btnDisconnect"));
        btnDisconnect->setMinimumSize(QSize(90, 37));
        btnDisconnect->setFont(font);
        btnDisconnect->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 103, 96);}"));

        horizontalLayout_6->addWidget(btnDisconnect);

        horizontalSpacer_6 = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        btnSave = new QPushButton(frame_3);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        sizePolicy.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy);
        btnSave->setMinimumSize(QSize(90, 37));
        btnSave->setFont(font);
        btnSave->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(19, 22, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(19, 22, 67);}\n"
"QPushButton:pressed{background-color: rgb(19, 22, 87);}"));

        horizontalLayout_6->addWidget(btnSave);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        horizontalLayout_2->addWidget(frame_3);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame_2 = new QFrame(frmInstrumentationClass);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy2);
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(7, 7, 7, 7);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(5, -1, 5, -1);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border:none;"));

        horizontalLayout_7->addWidget(label_2);

        comboInstrumentName = new QComboBox(frame_2);
        comboInstrumentName->addItem(QString());
        comboInstrumentName->setObjectName(QString::fromUtf8("comboInstrumentName"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(comboInstrumentName->sizePolicy().hasHeightForWidth());
        comboInstrumentName->setSizePolicy(sizePolicy4);
        comboInstrumentName->setMinimumSize(QSize(325, 30));
        comboInstrumentName->setMaximumSize(QSize(16777215, 16777215));
        comboInstrumentName->setFont(font);
        comboInstrumentName->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;     \n"
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
"    image: url(:/res/ico/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        horizontalLayout_7->addWidget(comboInstrumentName);


        gridLayout_2->addLayout(horizontalLayout_7, 0, 0, 1, 2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(5, -1, 5, -1);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(0, 28));
        label_3->setMaximumSize(QSize(16777215, 28));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 254, 237,0);\n"
"border:none;"));

        horizontalLayout_8->addWidget(label_3);

        lblType = new QLabel(frame_2);
        lblType->setObjectName(QString::fromUtf8("lblType"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        lblType->setFont(font1);
        lblType->setStyleSheet(QString::fromUtf8("color: rgb(129, 0, 193);\n"
"background-color: rgba(255, 254, 237,130);\n"
"border:none;"));
        lblType->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(lblType);


        gridLayout_2->addLayout(horizontalLayout_8, 2, 0, 1, 2);


        verticalLayout_3->addLayout(gridLayout_2);

        stackedWidget = new QStackedWidget(frame_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("border:none;"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 11, 0, 0);
        frame_4 = new QFrame(page);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        sizePolicy2.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy2);
        frame_4->setMinimumSize(QSize(0, 0));
        frame_4->setMaximumSize(QSize(16777215, 16777215));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        gridLayout_3->setVerticalSpacing(23);
        gridLayout_3->setContentsMargins(5, 7, 5, 9);
        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy3.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy3);
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_3->addWidget(label_12, 0, 3, 1, 1);

        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(0, 0, 0, 0);\n"
"border:none;"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        txtIoRemark = new QLineEdit(frame_4);
        txtIoRemark->setObjectName(QString::fromUtf8("txtIoRemark"));
        txtIoRemark->setMinimumSize(QSize(0, 28));
        txtIoRemark->setFont(font);
        txtIoRemark->setStyleSheet(QString::fromUtf8("border: 1px solid white ;\n"
"background-color: rgb(239, 239, 239);\n"
"color: rgb(0, 0, 200);"));

        gridLayout_3->addWidget(txtIoRemark, 2, 1, 1, 4);

        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        widgetIoIP = new IPAddress(frame_4);
        widgetIoIP->setObjectName(QString::fromUtf8("widgetIoIP"));
        sizePolicy4.setHeightForWidth(widgetIoIP->sizePolicy().hasHeightForWidth());
        widgetIoIP->setSizePolicy(sizePolicy4);
        widgetIoIP->setMinimumSize(QSize(200, 29));
        widgetIoIP->setMaximumSize(QSize(200, 29));
        widgetIoIP->setFont(font);
        widgetIoIP->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 239, 239);"));

        gridLayout_3->addWidget(widgetIoIP, 0, 1, 1, 2);

        spinIoTimeOut = new QSpinBox(frame_4);
        spinIoTimeOut->setObjectName(QString::fromUtf8("spinIoTimeOut"));
        sizePolicy.setHeightForWidth(spinIoTimeOut->sizePolicy().hasHeightForWidth());
        spinIoTimeOut->setSizePolicy(sizePolicy);
        spinIoTimeOut->setMinimumSize(QSize(100, 28));
        spinIoTimeOut->setMaximumSize(QSize(100, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        spinIoTimeOut->setFont(font2);
        spinIoTimeOut->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(0, 0, 200);background-color: rgb(239, 239, 239);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/res/ico/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/res/ico/down.png);\n"
"}"));
        spinIoTimeOut->setAlignment(Qt::AlignCenter);
        spinIoTimeOut->setMinimum(1);
        spinIoTimeOut->setMaximum(10000);
        spinIoTimeOut->setValue(5000);
        spinIoTimeOut->setDisplayIntegerBase(10);

        gridLayout_3->addWidget(spinIoTimeOut, 1, 1, 1, 1);

        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_3->addWidget(label_11, 2, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 0, 1, 1);

        spinIoPort = new QSpinBox(frame_4);
        spinIoPort->setObjectName(QString::fromUtf8("spinIoPort"));
        spinIoPort->setMinimumSize(QSize(100, 28));
        spinIoPort->setMaximumSize(QSize(100, 16777215));
        spinIoPort->setFont(font2);
        spinIoPort->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(0, 0, 200);background-color: rgb(239, 239, 239);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/res/ico/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/res/ico/down.png);\n"
"}"));
        spinIoPort->setAlignment(Qt::AlignCenter);
        spinIoPort->setMinimum(0);
        spinIoPort->setMaximum(65535);
        spinIoPort->setValue(1024);
        spinIoPort->setDisplayIntegerBase(10);

        gridLayout_3->addWidget(spinIoPort, 0, 4, 1, 1);


        verticalLayout_4->addWidget(frame_4);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        sizePolicy2.setHeightForWidth(page_2->sizePolicy().hasHeightForWidth());
        page_2->setSizePolicy(sizePolicy2);
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 11, 0, 0);
        frame_5 = new QFrame(page_2);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        sizePolicy2.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy2);
        frame_5->setMinimumSize(QSize(0, 0));
        frame_5->setMaximumSize(QSize(16777215, 16777215));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_5);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(0);
        gridLayout_4->setVerticalSpacing(23);
        gridLayout_4->setContentsMargins(5, 7, 5, 9);
        label_14 = new QLabel(frame_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_4->addWidget(label_14, 2, 0, 1, 1);

        label_5 = new QLabel(frame_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(0, 0, 0, 0);\n"
"border:none;"));

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        spinPlcPort = new QSpinBox(frame_5);
        spinPlcPort->setObjectName(QString::fromUtf8("spinPlcPort"));
        spinPlcPort->setMinimumSize(QSize(100, 28));
        spinPlcPort->setMaximumSize(QSize(100, 16777215));
        spinPlcPort->setFont(font2);
        spinPlcPort->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(0, 0, 200);background-color: rgb(239, 239, 239);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/res/ico/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/res/ico/down.png);\n"
"}"));
        spinPlcPort->setAlignment(Qt::AlignCenter);
        spinPlcPort->setMinimum(0);
        spinPlcPort->setMaximum(65535);
        spinPlcPort->setValue(1024);
        spinPlcPort->setDisplayIntegerBase(10);

        gridLayout_4->addWidget(spinPlcPort, 0, 4, 1, 1);

        label_17 = new QLabel(frame_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_4->addWidget(label_17, 1, 0, 1, 1);

        txtPlcRemark = new QLineEdit(frame_5);
        txtPlcRemark->setObjectName(QString::fromUtf8("txtPlcRemark"));
        txtPlcRemark->setMinimumSize(QSize(0, 28));
        txtPlcRemark->setFont(font);
        txtPlcRemark->setStyleSheet(QString::fromUtf8("border: 1px solid white ;\n"
"background-color: rgb(239, 239, 239);\n"
"color: rgb(0, 0, 200);"));

        gridLayout_4->addWidget(txtPlcRemark, 2, 1, 1, 4);

        label_15 = new QLabel(frame_5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        sizePolicy3.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy3);
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_4->addWidget(label_15, 0, 3, 1, 1);

        spinPlcTimeOut = new QSpinBox(frame_5);
        spinPlcTimeOut->setObjectName(QString::fromUtf8("spinPlcTimeOut"));
        spinPlcTimeOut->setMinimumSize(QSize(100, 28));
        spinPlcTimeOut->setMaximumSize(QSize(100, 16777215));
        spinPlcTimeOut->setFont(font2);
        spinPlcTimeOut->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(0, 0, 200);background-color: rgb(239, 239, 239);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/res/ico/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/res/ico/down.png);\n"
"}"));
        spinPlcTimeOut->setAlignment(Qt::AlignCenter);
        spinPlcTimeOut->setMinimum(1);
        spinPlcTimeOut->setMaximum(10000);
        spinPlcTimeOut->setValue(5000);
        spinPlcTimeOut->setDisplayIntegerBase(10);

        gridLayout_4->addWidget(spinPlcTimeOut, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 3, 0, 1, 1);

        widgetPlcIP = new IPAddress(frame_5);
        widgetPlcIP->setObjectName(QString::fromUtf8("widgetPlcIP"));
        sizePolicy.setHeightForWidth(widgetPlcIP->sizePolicy().hasHeightForWidth());
        widgetPlcIP->setSizePolicy(sizePolicy);
        widgetPlcIP->setMinimumSize(QSize(200, 29));
        widgetPlcIP->setMaximumSize(QSize(200, 29));
        widgetPlcIP->setFont(font);
        widgetPlcIP->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 239, 239);"));

        gridLayout_4->addWidget(widgetPlcIP, 0, 1, 1, 2);


        verticalLayout_5->addWidget(frame_5);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_6 = new QVBoxLayout(page_3);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, -1, 0, 0);
        frame_6 = new QFrame(page_3);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        sizePolicy2.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy2);
        frame_6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(0);
        gridLayout_5->setVerticalSpacing(15);
        gridLayout_5->setContentsMargins(5, 7, 5, 9);
        comboFlowControl = new QComboBox(frame_6);
        comboFlowControl->addItem(QString());
        comboFlowControl->addItem(QString());
        comboFlowControl->addItem(QString());
        comboFlowControl->setObjectName(QString::fromUtf8("comboFlowControl"));
        comboFlowControl->setMinimumSize(QSize(120, 30));
        comboFlowControl->setMaximumSize(QSize(120, 16777215));
        comboFlowControl->setFont(font);
        comboFlowControl->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;     \n"
"    color: rgb(0, 0, 200);\n"
"		background-color: rgba(230, 230, 230,210);\n"
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
"QComboBox::down-arrow {\n"
"    image: url(:/res/ico/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        gridLayout_5->addWidget(comboFlowControl, 2, 4, 1, 1);

        label_19 = new QLabel(frame_6);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy3.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy3);
        label_19->setFont(font);
        label_19->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_5->addWidget(label_19, 0, 3, 1, 1);

        label_8 = new QLabel(frame_6);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_5->addWidget(label_8, 1, 3, 1, 1);

        label_18 = new QLabel(frame_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_5->addWidget(label_18, 3, 0, 1, 1);

        comboSerialPort = new QComboBox(frame_6);
        comboSerialPort->addItem(QString());
        comboSerialPort->addItem(QString());
        comboSerialPort->addItem(QString());
        comboSerialPort->addItem(QString());
        comboSerialPort->addItem(QString());
        comboSerialPort->addItem(QString());
        comboSerialPort->addItem(QString());
        comboSerialPort->addItem(QString());
        comboSerialPort->addItem(QString());
        comboSerialPort->setObjectName(QString::fromUtf8("comboSerialPort"));
        comboSerialPort->setMinimumSize(QSize(120, 30));
        comboSerialPort->setMaximumSize(QSize(120, 16777215));
        comboSerialPort->setFont(font);
        comboSerialPort->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;     \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(230, 230, 230,210);\n"
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
"QComboBox::down-arrow {\n"
"    image: url(:/res/ico/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        gridLayout_5->addWidget(comboSerialPort, 0, 1, 1, 1);

        txtSPRemark = new QLineEdit(frame_6);
        txtSPRemark->setObjectName(QString::fromUtf8("txtSPRemark"));
        txtSPRemark->setMinimumSize(QSize(0, 28));
        txtSPRemark->setFont(font);
        txtSPRemark->setStyleSheet(QString::fromUtf8("border: 1px solid white ;\n"
"background-color: rgb(239, 239, 239);\n"
"color: rgb(0, 0, 200);"));

        gridLayout_5->addWidget(txtSPRemark, 3, 1, 1, 4);

        label_6 = new QLabel(frame_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(0, 0, 0, 0);\n"
"border:none;"));

        gridLayout_5->addWidget(label_6, 0, 0, 1, 1);

        label_9 = new QLabel(frame_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_5->addWidget(label_9, 2, 0, 1, 1);

        comboCheckDigit = new QComboBox(frame_6);
        comboCheckDigit->addItem(QString());
        comboCheckDigit->addItem(QString());
        comboCheckDigit->addItem(QString());
        comboCheckDigit->addItem(QString());
        comboCheckDigit->addItem(QString());
        comboCheckDigit->setObjectName(QString::fromUtf8("comboCheckDigit"));
        comboCheckDigit->setMinimumSize(QSize(120, 30));
        comboCheckDigit->setMaximumSize(QSize(120, 16777215));
        comboCheckDigit->setFont(font);
        comboCheckDigit->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;     \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(230, 230, 230,210);\n"
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
"QComboBox::down-arrow {\n"
"    image: url(:/res/ico/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        gridLayout_5->addWidget(comboCheckDigit, 1, 1, 1, 1);

        label_21 = new QLabel(frame_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setFont(font);
        label_21->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_5->addWidget(label_21, 1, 0, 1, 1);

        comboStopBit = new QComboBox(frame_6);
        comboStopBit->addItem(QString());
        comboStopBit->addItem(QString());
        comboStopBit->addItem(QString());
        comboStopBit->setObjectName(QString::fromUtf8("comboStopBit"));
        comboStopBit->setMinimumSize(QSize(120, 30));
        comboStopBit->setMaximumSize(QSize(120, 16777215));
        comboStopBit->setFont(font);
        comboStopBit->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;     \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(230, 230, 230,210);\n"
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
"QComboBox::down-arrow {\n"
"    image: url(:/res/ico/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        gridLayout_5->addWidget(comboStopBit, 2, 1, 1, 1);

        comboBaudRate = new QComboBox(frame_6);
        comboBaudRate->addItem(QString());
        comboBaudRate->addItem(QString());
        comboBaudRate->addItem(QString());
        comboBaudRate->addItem(QString());
        comboBaudRate->addItem(QString());
        comboBaudRate->addItem(QString());
        comboBaudRate->addItem(QString());
        comboBaudRate->addItem(QString());
        comboBaudRate->addItem(QString());
        comboBaudRate->addItem(QString());
        comboBaudRate->setObjectName(QString::fromUtf8("comboBaudRate"));
        comboBaudRate->setMinimumSize(QSize(120, 30));
        comboBaudRate->setMaximumSize(QSize(120, 16777215));
        comboBaudRate->setFont(font);
        comboBaudRate->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;     \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(230, 230, 230,210);\n"
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
"QComboBox::down-arrow {\n"
"    image: url(:/res/ico/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        gridLayout_5->addWidget(comboBaudRate, 0, 4, 1, 1);

        comboDataBits = new QComboBox(frame_6);
        comboDataBits->addItem(QString());
        comboDataBits->addItem(QString());
        comboDataBits->addItem(QString());
        comboDataBits->addItem(QString());
        comboDataBits->setObjectName(QString::fromUtf8("comboDataBits"));
        comboDataBits->setMinimumSize(QSize(120, 30));
        comboDataBits->setMaximumSize(QSize(120, 16777215));
        comboDataBits->setFont(font);
        comboDataBits->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;     \n"
"    color: rgb(0, 0, 200);\n"
"		background-color: rgba(230, 230, 230,210);\n"
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
"QComboBox::down-arrow {\n"
"    image: url(:/res/ico/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        gridLayout_5->addWidget(comboDataBits, 1, 4, 1, 1);

        label_7 = new QLabel(frame_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_5->addWidget(label_7, 2, 3, 1, 1);

        plainTextEdit_2 = new QPlainTextEdit(frame_6);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setFont(font);
        plainTextEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(255, 122, 15);\n"
"border:none;"));
        plainTextEdit_2->setReadOnly(true);

        gridLayout_5->addWidget(plainTextEdit_2, 4, 0, 1, 5);


        verticalLayout_6->addWidget(frame_6);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        verticalLayout_7 = new QVBoxLayout(page_4);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, -1, 0, 0);
        frame_7 = new QFrame(page_4);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        sizePolicy2.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy2);
        frame_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_7);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(0);
        gridLayout_6->setVerticalSpacing(23);
        gridLayout_6->setContentsMargins(5, 7, 5, 9);
        plainTextEdit = new QPlainTextEdit(frame_7);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        plainTextEdit->setFont(font3);
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(255, 122, 15);\n"
"border:none;"));
        plainTextEdit->setReadOnly(true);

        gridLayout_6->addWidget(plainTextEdit, 3, 0, 1, 4);

        comboProtocol = new QComboBox(frame_7);
        comboProtocol->addItem(QString());
        comboProtocol->addItem(QString());
        comboProtocol->setObjectName(QString::fromUtf8("comboProtocol"));
        sizePolicy.setHeightForWidth(comboProtocol->sizePolicy().hasHeightForWidth());
        comboProtocol->setSizePolicy(sizePolicy);
        comboProtocol->setMinimumSize(QSize(120, 30));
        comboProtocol->setMaximumSize(QSize(120, 16777215));
        comboProtocol->setFont(font);
        comboProtocol->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;     \n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgba(230, 230, 230,210);\n"
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
"QComboBox::down-arrow {\n"
"    image: url(:/res/ico/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        gridLayout_6->addWidget(comboProtocol, 0, 1, 1, 1);

        txtSocketRemark = new QLineEdit(frame_7);
        txtSocketRemark->setObjectName(QString::fromUtf8("txtSocketRemark"));
        txtSocketRemark->setMinimumSize(QSize(0, 28));
        txtSocketRemark->setFont(font);
        txtSocketRemark->setStyleSheet(QString::fromUtf8("border: 1px solid white ;\n"
"background-color: rgb(239, 239, 239);\n"
"color: rgb(0, 0, 200);"));

        gridLayout_6->addWidget(txtSocketRemark, 2, 1, 1, 3);

        label_20 = new QLabel(frame_7);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(0, 0, 0, 0);\n"
"border:none;"));

        gridLayout_6->addWidget(label_20, 0, 0, 1, 1);

        lbl_ip = new QLabel(frame_7);
        lbl_ip->setObjectName(QString::fromUtf8("lbl_ip"));
        sizePolicy3.setHeightForWidth(lbl_ip->sizePolicy().hasHeightForWidth());
        lbl_ip->setSizePolicy(sizePolicy3);
        lbl_ip->setFont(font);
        lbl_ip->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(0, 0, 0, 0);\n"
"border:none;"));

        gridLayout_6->addWidget(lbl_ip, 0, 2, 1, 1);

        widgetSocketIP = new IPAddress(frame_7);
        widgetSocketIP->setObjectName(QString::fromUtf8("widgetSocketIP"));
        sizePolicy.setHeightForWidth(widgetSocketIP->sizePolicy().hasHeightForWidth());
        widgetSocketIP->setSizePolicy(sizePolicy);
        widgetSocketIP->setMinimumSize(QSize(200, 29));
        widgetSocketIP->setMaximumSize(QSize(200, 29));
        widgetSocketIP->setFont(font);
        widgetSocketIP->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 239, 239);"));

        gridLayout_6->addWidget(widgetSocketIP, 0, 3, 1, 1);

        label_22 = new QLabel(frame_7);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setFont(font);
        label_22->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_6->addWidget(label_22, 2, 0, 1, 1);

        lbl_port = new QLabel(frame_7);
        lbl_port->setObjectName(QString::fromUtf8("lbl_port"));
        sizePolicy3.setHeightForWidth(lbl_port->sizePolicy().hasHeightForWidth());
        lbl_port->setSizePolicy(sizePolicy3);
        lbl_port->setFont(font);
        lbl_port->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_6->addWidget(lbl_port, 1, 0, 1, 1);

        spinSocketPort = new QSpinBox(frame_7);
        spinSocketPort->setObjectName(QString::fromUtf8("spinSocketPort"));
        spinSocketPort->setMinimumSize(QSize(120, 28));
        spinSocketPort->setMaximumSize(QSize(120, 16777215));
        spinSocketPort->setFont(font2);
        spinSocketPort->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(0, 0, 200);background-color: rgb(239, 239, 239);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/res/ico/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/res/ico/down.png);\n"
"}"));
        spinSocketPort->setAlignment(Qt::AlignCenter);
        spinSocketPort->setMinimum(0);
        spinSocketPort->setMaximum(65535);
        spinSocketPort->setValue(1024);
        spinSocketPort->setDisplayIntegerBase(10);

        gridLayout_6->addWidget(spinSocketPort, 1, 1, 1, 1);


        verticalLayout_7->addWidget(frame_7);

        stackedWidget->addWidget(page_4);

        verticalLayout_3->addWidget(stackedWidget);


        horizontalLayout_3->addWidget(frame_2);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame = new QFrame(frmInstrumentationClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(3, 3, 3, 3);
        horizontalSpacer = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 200,180);\n"
"border:none;"));

        horizontalLayout_5->addWidget(label);

        comboInstrument = new QComboBox(frame);
        comboInstrument->addItem(QString());
        comboInstrument->addItem(QString());
        comboInstrument->addItem(QString());
        comboInstrument->addItem(QString());
        comboInstrument->setObjectName(QString::fromUtf8("comboInstrument"));
        sizePolicy.setHeightForWidth(comboInstrument->sizePolicy().hasHeightForWidth());
        comboInstrument->setSizePolicy(sizePolicy);
        comboInstrument->setMinimumSize(QSize(115, 30));
        comboInstrument->setMaximumSize(QSize(120, 16777215));
        comboInstrument->setFont(font);
        comboInstrument->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 7.5em;\n"
"    color: rgb(239, 235, 231);\n"
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
"    image: url(:/res/ico/down_2.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));

        horizontalLayout_5->addWidget(comboInstrument);

        horizontalSpacer_7 = new QSpacerItem(45, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        btnAdd = new QPushButton(frame);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(90, 37));
        btnAdd->setFont(font);
        btnAdd->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(29, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(29, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(29, 82, 72);}"));

        horizontalLayout_5->addWidget(btnAdd);

        horizontalSpacer_2 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        horizontalLayout_4->addWidget(frame);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(frmInstrumentationClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmInstrumentationClass);
    } // setupUi

    void retranslateUi(QDialog *frmInstrumentationClass)
    {
        frmInstrumentationClass->setWindowTitle(QCoreApplication::translate("frmInstrumentationClass", "\344\273\252\345\231\250\344\273\252\350\241\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmInstrumentationClass", "\344\273\252\345\231\250\351\200\232\350\256\257\345\210\227\350\241\250", nullptr));
        btnConnect->setText(QCoreApplication::translate("frmInstrumentationClass", "\350\277\236\346\216\245\344\273\252\345\231\250", nullptr));
        btnDisconnect->setText(QCoreApplication::translate("frmInstrumentationClass", "\346\226\255\345\274\200\344\273\252\345\231\250", nullptr));
        btnSave->setText(QCoreApplication::translate("frmInstrumentationClass", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("frmInstrumentationClass", "\344\273\252\345\231\250\345\220\215\347\247\260\346\210\226\347\274\226\345\217\267\357\274\232", nullptr));
        comboInstrumentName->setItemText(0, QCoreApplication::translate("frmInstrumentationClass", "DAM-E3021N", nullptr));

        label_3->setText(QCoreApplication::translate("frmInstrumentationClass", "\351\200\211\346\213\251\344\273\252\345\231\250\351\200\232\350\256\257\345\220\215\347\247\260\346\210\226\347\274\226\345\217\267\357\274\232", nullptr));
        lblType->setText(QString());
        label_12->setText(QCoreApplication::translate("frmInstrumentationClass", "\344\273\252\345\231\250\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("frmInstrumentationClass", "\344\273\252\345\231\250IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("frmInstrumentationClass", "\350\266\205\346\227\266(ms)\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("frmInstrumentationClass", "\345\244\207\346\263\250\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("frmInstrumentationClass", "\345\244\207\346\263\250\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("frmInstrumentationClass", "\344\273\252\345\231\250IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("frmInstrumentationClass", "\350\266\205\346\227\266(ms)\357\274\232", nullptr));
        label_15->setText(QCoreApplication::translate("frmInstrumentationClass", "\344\273\252\345\231\250\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        comboFlowControl->setItemText(0, QCoreApplication::translate("frmInstrumentationClass", "\346\227\240", nullptr));
        comboFlowControl->setItemText(1, QCoreApplication::translate("frmInstrumentationClass", "\347\241\254\344\273\266", nullptr));
        comboFlowControl->setItemText(2, QCoreApplication::translate("frmInstrumentationClass", "\350\275\257\344\273\266", nullptr));

        label_19->setText(QCoreApplication::translate("frmInstrumentationClass", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("frmInstrumentationClass", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("frmInstrumentationClass", "\345\244\207\346\263\250\357\274\232", nullptr));
        comboSerialPort->setItemText(0, QCoreApplication::translate("frmInstrumentationClass", "COM1", nullptr));
        comboSerialPort->setItemText(1, QCoreApplication::translate("frmInstrumentationClass", "COM2", nullptr));
        comboSerialPort->setItemText(2, QCoreApplication::translate("frmInstrumentationClass", "COM3", nullptr));
        comboSerialPort->setItemText(3, QCoreApplication::translate("frmInstrumentationClass", "COM4", nullptr));
        comboSerialPort->setItemText(4, QCoreApplication::translate("frmInstrumentationClass", "COM5", nullptr));
        comboSerialPort->setItemText(5, QCoreApplication::translate("frmInstrumentationClass", "COM6", nullptr));
        comboSerialPort->setItemText(6, QCoreApplication::translate("frmInstrumentationClass", "COM7", nullptr));
        comboSerialPort->setItemText(7, QCoreApplication::translate("frmInstrumentationClass", "COM8", nullptr));
        comboSerialPort->setItemText(8, QCoreApplication::translate("frmInstrumentationClass", "COM9", nullptr));

        label_6->setText(QCoreApplication::translate("frmInstrumentationClass", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("frmInstrumentationClass", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        comboCheckDigit->setItemText(0, QCoreApplication::translate("frmInstrumentationClass", "\346\227\240", nullptr));
        comboCheckDigit->setItemText(1, QCoreApplication::translate("frmInstrumentationClass", "\345\245\207", nullptr));
        comboCheckDigit->setItemText(2, QCoreApplication::translate("frmInstrumentationClass", "\345\201\266", nullptr));
        comboCheckDigit->setItemText(3, QCoreApplication::translate("frmInstrumentationClass", "\346\240\207\345\277\227", nullptr));
        comboCheckDigit->setItemText(4, QCoreApplication::translate("frmInstrumentationClass", "\347\251\272\346\240\274", nullptr));

        label_21->setText(QCoreApplication::translate("frmInstrumentationClass", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        comboStopBit->setItemText(0, QCoreApplication::translate("frmInstrumentationClass", "1", nullptr));
        comboStopBit->setItemText(1, QCoreApplication::translate("frmInstrumentationClass", "1.5", nullptr));
        comboStopBit->setItemText(2, QCoreApplication::translate("frmInstrumentationClass", "2", nullptr));

        comboBaudRate->setItemText(0, QCoreApplication::translate("frmInstrumentationClass", "4800", nullptr));
        comboBaudRate->setItemText(1, QCoreApplication::translate("frmInstrumentationClass", "9600", nullptr));
        comboBaudRate->setItemText(2, QCoreApplication::translate("frmInstrumentationClass", "14400", nullptr));
        comboBaudRate->setItemText(3, QCoreApplication::translate("frmInstrumentationClass", "19200", nullptr));
        comboBaudRate->setItemText(4, QCoreApplication::translate("frmInstrumentationClass", "38400", nullptr));
        comboBaudRate->setItemText(5, QCoreApplication::translate("frmInstrumentationClass", "57600", nullptr));
        comboBaudRate->setItemText(6, QCoreApplication::translate("frmInstrumentationClass", "115200", nullptr));
        comboBaudRate->setItemText(7, QCoreApplication::translate("frmInstrumentationClass", "128000", nullptr));
        comboBaudRate->setItemText(8, QCoreApplication::translate("frmInstrumentationClass", "230400", nullptr));
        comboBaudRate->setItemText(9, QCoreApplication::translate("frmInstrumentationClass", "256000", nullptr));

        comboBaudRate->setCurrentText(QCoreApplication::translate("frmInstrumentationClass", "4800", nullptr));
        comboDataBits->setItemText(0, QCoreApplication::translate("frmInstrumentationClass", "5", nullptr));
        comboDataBits->setItemText(1, QCoreApplication::translate("frmInstrumentationClass", "6", nullptr));
        comboDataBits->setItemText(2, QCoreApplication::translate("frmInstrumentationClass", "7", nullptr));
        comboDataBits->setItemText(3, QCoreApplication::translate("frmInstrumentationClass", "8", nullptr));

        comboDataBits->setCurrentText(QCoreApplication::translate("frmInstrumentationClass", "5", nullptr));
        label_7->setText(QCoreApplication::translate("frmInstrumentationClass", "\346\265\201\346\216\247\345\210\266\357\274\232", nullptr));
        plainTextEdit_2->setPlainText(QCoreApplication::translate("frmInstrumentationClass", "\350\257\264\346\230\216\357\274\232\344\270\262\345\217\243\351\200\232\344\277\241\345\210\227\350\241\250\346\225\260\351\207\217\346\210\226\350\277\236\346\216\245\347\212\266\346\200\201\346\224\271\345\217\230\345\220\216\357\274\214\351\234\200\350\246\201\346\233\264\346\226\260\346\265\201\347\250\213\347\232\204\344\270\262\345\217\243\351\200\232\344\277\241\350\256\276\347\275\256\343\200\202", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("frmInstrumentationClass", "\350\257\264\346\230\216\357\274\232(1)\346\234\215\345\212\241\345\231\250\350\277\236\346\216\245\345\220\216\357\274\214\351\234\200\350\246\201\345\234\250\346\265\201\347\250\213\346\226\260\345\273\272TCP/IP\351\200\232\344\277\241\345\267\245\345\205\267\345\220\216\357\274\214\345\256\242\346\210\267\347\253\257\346\211\215\350\203\275\350\277\236\346\216\245\357\274\233(2)TCP/IP\351\200\232\344\277\241\345\210\227\350\241\250\346\225\260\351\207\217\346\210\226\350\277\236\346\216\245\347\212\266\346\200\201\346\224\271\345\217\230\345\220\216\357\274\214\351\234\200\350\246\201\346\233\264\346\226\260\346\265\201\347\250\213\347\232\204TCP/IP\351\200\232\344\277\241\350\256\276\347\275\256\343\200\202", nullptr));
        comboProtocol->setItemText(0, QCoreApplication::translate("frmInstrumentationClass", "TCP Server", nullptr));
        comboProtocol->setItemText(1, QCoreApplication::translate("frmInstrumentationClass", "TCP Client", nullptr));

        label_20->setText(QCoreApplication::translate("frmInstrumentationClass", "\345\215\217\350\256\256\347\261\273\345\236\213\357\274\232", nullptr));
        lbl_ip->setText(QCoreApplication::translate("frmInstrumentationClass", "\346\234\254\345\234\260IP\345\234\260\345\235\200\357\274\232", nullptr));
        label_22->setText(QCoreApplication::translate("frmInstrumentationClass", "\345\244\207\346\263\250\357\274\232", nullptr));
        lbl_port->setText(QCoreApplication::translate("frmInstrumentationClass", "\346\234\254\345\234\260\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("frmInstrumentationClass", "\344\273\252\345\231\250\351\200\232\350\256\257\347\261\273\345\210\253\357\274\232", nullptr));
        comboInstrument->setItemText(0, QCoreApplication::translate("frmInstrumentationClass", "\351\200\232\347\224\250I/O", nullptr));
        comboInstrument->setItemText(1, QCoreApplication::translate("frmInstrumentationClass", "PLC\351\200\232\344\277\241", nullptr));
        comboInstrument->setItemText(2, QCoreApplication::translate("frmInstrumentationClass", "\344\270\262\345\217\243\351\200\232\344\277\241", nullptr));
        comboInstrument->setItemText(3, QCoreApplication::translate("frmInstrumentationClass", "TCP/IP\351\200\232\344\277\241", nullptr));

        btnAdd->setText(QCoreApplication::translate("frmInstrumentationClass", "\346\267\273\345\212\240\344\273\252\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmInstrumentationClass: public Ui_frmInstrumentationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMINSTRUMENTATION_H
