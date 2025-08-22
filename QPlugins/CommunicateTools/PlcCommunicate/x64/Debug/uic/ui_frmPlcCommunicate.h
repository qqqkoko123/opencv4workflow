/********************************************************************************
** Form generated from reading UI file 'frmPlcCommunicate.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPLCCOMMUNICATE_H
#define UI_FRMPLCCOMMUNICATE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmPlcCommunicateClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupC;
    QLabel *lblMsg;
    QLabel *label_8;
    QComboBox *comboCommName;
    QPushButton *btnUpdata;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupC2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetPlc;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnAddRegister;
    QPushButton *btnDeleteRegister;
    QSpacerItem *verticalSpacer_5;
    QWidget *page_2;
    QGroupBox *groupC3;
    QLabel *label_14;
    QLineEdit *txtMitRegisterData;
    QPushButton *btnLinkMitRegisterData;
    QPushButton *btnDelLinkMitRegisterData;
    QPushButton *btnMitBack;
    QLabel *label;
    QPushButton *btnMitSave;
    QLabel *lbl_mit;
    QComboBox *comboMitCode;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_12;
    QRadioButton *radioMitRead;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioMitWrite;
    QLineEdit *txtMitRegisterAddress;
    QLabel *label_15;
    QLabel *lbl_mit_2;
    QComboBox *comboMitMethod;
    QWidget *tab_2;
    QGroupBox *groupC3_2;
    QTextEdit *txtMsg;

    void setupUi(QDialog *frmPlcCommunicateClass)
    {
        if (frmPlcCommunicateClass->objectName().isEmpty())
            frmPlcCommunicateClass->setObjectName(QString::fromUtf8("frmPlcCommunicateClass"));
        frmPlcCommunicateClass->resize(720, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmPlcCommunicateClass->sizePolicy().hasHeightForWidth());
        frmPlcCommunicateClass->setSizePolicy(sizePolicy);
        frmPlcCommunicateClass->setMinimumSize(QSize(720, 500));
        frmPlcCommunicateClass->setMaximumSize(QSize(720, 500));
        frmPlcCommunicateClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmPlcCommunicateClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmPlcCommunicateClass);
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

        txtDescribe = new QLineEdit(frmPlcCommunicateClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmPlcCommunicateClass);
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

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frmPlcCommunicateClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupC = new QGroupBox(tab);
        groupC->setObjectName(QString::fromUtf8("groupC"));
        groupC->setGeometry(QRect(12, 16, 690, 69));
        groupC->setFont(font);
        groupC->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        lblMsg = new QLabel(groupC);
        lblMsg->setObjectName(QString::fromUtf8("lblMsg"));
        lblMsg->setGeometry(QRect(268, 37, 299, 19));
        lblMsg->setFont(font);
        lblMsg->setStyleSheet(QString::fromUtf8("color: rgb(85, 85, 127);\n"
"background-color: rgba(0, 0, 0, 0);"));
        label_8 = new QLabel(groupC);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(23, 36, 83, 19));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        comboCommName = new QComboBox(groupC);
        comboCommName->setObjectName(QString::fromUtf8("comboCommName"));
        comboCommName->setGeometry(QRect(106, 31, 233, 29));
        comboCommName->setFont(font);
        comboCommName->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        btnUpdata = new QPushButton(groupC);
        btnUpdata->setObjectName(QString::fromUtf8("btnUpdata"));
        btnUpdata->setGeometry(QRect(352, 31, 85, 30));
        sizePolicy.setHeightForWidth(btnUpdata->sizePolicy().hasHeightForWidth());
        btnUpdata->setSizePolicy(sizePolicy);
        btnUpdata->setMinimumSize(QSize(60, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        btnUpdata->setFont(font1);
        btnUpdata->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        stackedWidget = new QStackedWidget(tab);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(12, 102, 690, 307));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        groupC2 = new QGroupBox(page);
        groupC2->setObjectName(QString::fromUtf8("groupC2"));
        groupC2->setGeometry(QRect(0, 0, 690, 250));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        horizontalLayoutWidget_2 = new QWidget(groupC2);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 38, 669, 203));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(horizontalLayoutWidget_2);
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
        tableWidgetPlc = new QTableWidget(frame_3);
        if (tableWidgetPlc->columnCount() < 1)
            tableWidgetPlc->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidgetPlc->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetPlc->setObjectName(QString::fromUtf8("tableWidgetPlc"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tableWidgetPlc->setFont(font2);
        tableWidgetPlc->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: #b7c7af;   \n"
"    border:none;\n"
"    gridline-color: rgba(20, 25, 155,50);\n"
"    color: rgba(20, 20, 20,200);\n"
"}\n"
"QTableWidget::item::selected\n"
"{   \n"
"    background-color: rgba(180, 180, 215,255); \n"
"}\n"
"QHeaderView::section\n"
"{\n"
"    color: rgb(0, 0, 0);\n"
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
"		padding-left:2px;"
                        "\n"
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
        tableWidgetPlc->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetPlc->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetPlc->setGridStyle(Qt::DashLine);
        tableWidgetPlc->horizontalHeader()->setMinimumSectionSize(29);
        tableWidgetPlc->horizontalHeader()->setDefaultSectionSize(597);
        tableWidgetPlc->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout_3->addWidget(tableWidgetPlc);


        horizontalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(horizontalLayoutWidget_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);\n"
"background-color: #b7c7a7;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(13);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 2, 1, 1);
        btnAddRegister = new QPushButton(frame_4);
        btnAddRegister->setObjectName(QString::fromUtf8("btnAddRegister"));
        sizePolicy.setHeightForWidth(btnAddRegister->sizePolicy().hasHeightForWidth());
        btnAddRegister->setSizePolicy(sizePolicy);
        btnAddRegister->setMinimumSize(QSize(60, 30));
        btnAddRegister->setFont(font1);
        btnAddRegister->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnAddRegister);

        btnDeleteRegister = new QPushButton(frame_4);
        btnDeleteRegister->setObjectName(QString::fromUtf8("btnDeleteRegister"));
        btnDeleteRegister->setMinimumSize(QSize(60, 30));
        btnDeleteRegister->setFont(font1);
        btnDeleteRegister->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));

        verticalLayout_4->addWidget(btnDeleteRegister);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);


        horizontalLayout_3->addWidget(frame_4);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupC3 = new QGroupBox(page_2);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(0, 0, 690, 250));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_14 = new QLabel(groupC3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(21, 148, 115, 19));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));
        txtMitRegisterData = new QLineEdit(groupC3);
        txtMitRegisterData->setObjectName(QString::fromUtf8("txtMitRegisterData"));
        txtMitRegisterData->setGeometry(QRect(141, 144, 210, 27));
        txtMitRegisterData->setFont(font);
        txtMitRegisterData->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtMitRegisterData->setAlignment(Qt::AlignCenter);
        txtMitRegisterData->setReadOnly(true);
        btnLinkMitRegisterData = new QPushButton(groupC3);
        btnLinkMitRegisterData->setObjectName(QString::fromUtf8("btnLinkMitRegisterData"));
        btnLinkMitRegisterData->setGeometry(QRect(358, 144, 27, 27));
        btnLinkMitRegisterData->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkMitRegisterData->setIcon(icon);
        btnLinkMitRegisterData->setIconSize(QSize(27, 27));
        btnDelLinkMitRegisterData = new QPushButton(groupC3);
        btnDelLinkMitRegisterData->setObjectName(QString::fromUtf8("btnDelLinkMitRegisterData"));
        btnDelLinkMitRegisterData->setGeometry(QRect(392, 144, 27, 27));
        btnDelLinkMitRegisterData->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkMitRegisterData->setIcon(icon1);
        btnDelLinkMitRegisterData->setIconSize(QSize(27, 27));
        btnMitBack = new QPushButton(groupC3);
        btnMitBack->setObjectName(QString::fromUtf8("btnMitBack"));
        btnMitBack->setGeometry(QRect(598, 206, 70, 35));
        btnMitBack->setMinimumSize(QSize(70, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        btnMitBack->setFont(font3);
        btnMitBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label = new QLabel(groupC3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(539, 144, 48, 32));
        label->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resource/right_2.png")));
        label->setScaledContents(true);
        btnMitSave = new QPushButton(groupC3);
        btnMitSave->setObjectName(QString::fromUtf8("btnMitSave"));
        btnMitSave->setGeometry(QRect(598, 144, 70, 35));
        btnMitSave->setMinimumSize(QSize(70, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        btnMitSave->setFont(font4);
        btnMitSave->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(125, 255, 127,150);}\n"
"QWidget{ color: rgb(35, 35, 35);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(125, 255, 127,200);}\n"
"QPushButton:pressed{background-color: rgba(125, 255, 127,255);}"));
        lbl_mit = new QLabel(groupC3);
        lbl_mit->setObjectName(QString::fromUtf8("lbl_mit"));
        lbl_mit->setGeometry(QRect(23, 42, 119, 19));
        lbl_mit->setFont(font);
        lbl_mit->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));
        comboMitCode = new QComboBox(groupC3);
        comboMitCode->addItem(QString());
        comboMitCode->addItem(QString());
        comboMitCode->setObjectName(QString::fromUtf8("comboMitCode"));
        comboMitCode->setGeometry(QRect(141, 37, 100, 30));
        sizePolicy.setHeightForWidth(comboMitCode->sizePolicy().hasHeightForWidth());
        comboMitCode->setSizePolicy(sizePolicy);
        comboMitCode->setMinimumSize(QSize(100, 30));
        comboMitCode->setFont(font);
        comboMitCode->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        horizontalLayoutWidget = new QWidget(groupC3);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(448, 38, 219, 29));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 0, 2, 0);
        label_12 = new QLabel(horizontalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        horizontalLayout_2->addWidget(label_12);

        radioMitRead = new QRadioButton(horizontalLayoutWidget);
        radioMitRead->setObjectName(QString::fromUtf8("radioMitRead"));
        radioMitRead->setFont(font);
        radioMitRead->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border:none;"));
        radioMitRead->setChecked(true);

        horizontalLayout_2->addWidget(radioMitRead);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        radioMitWrite = new QRadioButton(horizontalLayoutWidget);
        radioMitWrite->setObjectName(QString::fromUtf8("radioMitWrite"));
        radioMitWrite->setFont(font);
        radioMitWrite->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"border:none;"));

        horizontalLayout_2->addWidget(radioMitWrite);

        txtMitRegisterAddress = new QLineEdit(groupC3);
        txtMitRegisterAddress->setObjectName(QString::fromUtf8("txtMitRegisterAddress"));
        txtMitRegisterAddress->setGeometry(QRect(548, 91, 118, 27));
        txtMitRegisterAddress->setFont(font);
        txtMitRegisterAddress->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(230, 230, 235,250);"));
        txtMitRegisterAddress->setAlignment(Qt::AlignCenter);
        txtMitRegisterAddress->setReadOnly(false);
        label_15 = new QLabel(groupC3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(448, 95, 97, 19));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));
        lbl_mit_2 = new QLabel(groupC3);
        lbl_mit_2->setObjectName(QString::fromUtf8("lbl_mit_2"));
        lbl_mit_2->setGeometry(QRect(23, 95, 119, 19));
        lbl_mit_2->setFont(font);
        lbl_mit_2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));
        comboMitMethod = new QComboBox(groupC3);
        comboMitMethod->addItem(QString());
        comboMitMethod->addItem(QString());
        comboMitMethod->setObjectName(QString::fromUtf8("comboMitMethod"));
        comboMitMethod->setGeometry(QRect(141, 90, 100, 30));
        sizePolicy.setHeightForWidth(comboMitMethod->sizePolicy().hasHeightForWidth());
        comboMitMethod->setSizePolicy(sizePolicy);
        comboMitMethod->setMinimumSize(QSize(100, 30));
        comboMitMethod->setFont(font);
        comboMitMethod->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        stackedWidget->addWidget(page_2);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupC3_2 = new QGroupBox(tab_2);
        groupC3_2->setObjectName(QString::fromUtf8("groupC3_2"));
        groupC3_2->setGeometry(QRect(9, 14, 695, 348));
        groupC3_2->setFont(font);
        groupC3_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC3_2);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 687, 313));
        txtMsg->setFont(font2);
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


        retranslateUi(frmPlcCommunicateClass);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmPlcCommunicateClass);
    } // setupUi

    void retranslateUi(QDialog *frmPlcCommunicateClass)
    {
        frmPlcCommunicateClass->setWindowTitle(QCoreApplication::translate("frmPlcCommunicateClass", "PLC\351\200\232\344\277\241", nullptr));
        label_3->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\346\211\247\350\241\214", nullptr));
        groupC->setTitle(QCoreApplication::translate("frmPlcCommunicateClass", "\351\200\232\350\256\257\345\257\271\350\261\241", nullptr));
        lblMsg->setText(QString());
        label_8->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\351\200\232\350\256\257\345\220\215\347\247\260\357\274\232", nullptr));
        btnUpdata->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\346\233\264\346\226\260\345\210\227\350\241\250", nullptr));
        groupC2->setTitle(QCoreApplication::translate("frmPlcCommunicateClass", "\351\223\276\346\216\245\345\257\271\350\261\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetPlc->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmPlcCommunicateClass", "PLC\345\257\204\345\255\230\345\231\250\351\223\276\346\216\245\345\234\260\345\235\200", nullptr));
        btnAddRegister->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteRegister->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\345\210\240\351\231\244", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmPlcCommunicateClass", "PLC\350\256\276\347\275\256", nullptr));
        label_14->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\345\257\204\345\255\230\345\231\250\345\206\231\345\205\245\345\200\274\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtMitRegisterData->setToolTip(QCoreApplication::translate("frmPlcCommunicateClass", "\345\205\250\345\261\200\345\217\230\351\207\217Int\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkMitRegisterData->setToolTip(QCoreApplication::translate("frmPlcCommunicateClass", "\351\223\276\346\216\245\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkMitRegisterData->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkMitRegisterData->setToolTip(QCoreApplication::translate("frmPlcCommunicateClass", "\345\210\240\351\231\244\345\206\205\345\256\271\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkMitRegisterData->setText(QString());
        btnMitBack->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label->setText(QString());
        btnMitSave->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\345\217\202\346\225\260\344\277\235\345\255\230", nullptr));
        lbl_mit->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\351\200\232\344\277\241\346\225\260\346\215\256\344\273\243\347\240\201\357\274\232", nullptr));
        comboMitCode->setItemText(0, QCoreApplication::translate("frmPlcCommunicateClass", "\344\272\214\350\277\233\345\210\266\347\240\201", nullptr));
        comboMitCode->setItemText(1, QCoreApplication::translate("frmPlcCommunicateClass", "ASCII\347\240\201", nullptr));

        label_12->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\351\200\232\344\277\241\346\250\241\345\274\217\357\274\232", nullptr));
        radioMitRead->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\350\257\273", nullptr));
        radioMitWrite->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\345\206\231", nullptr));
#if QT_CONFIG(tooltip)
        txtMitRegisterAddress->setToolTip(QCoreApplication::translate("frmPlcCommunicateClass", "eg: D0", nullptr));
#endif // QT_CONFIG(tooltip)
        label_15->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\345\257\204\345\255\230\345\231\250\345\234\260\345\235\200\357\274\232", nullptr));
        lbl_mit_2->setText(QCoreApplication::translate("frmPlcCommunicateClass", "\351\200\232\344\277\241\350\256\277\351\227\256\346\226\271\345\274\217\357\274\232", nullptr));
        comboMitMethod->setItemText(0, QCoreApplication::translate("frmPlcCommunicateClass", "\345\255\227", nullptr));
        comboMitMethod->setItemText(1, QCoreApplication::translate("frmPlcCommunicateClass", "\345\217\214\345\255\227", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmPlcCommunicateClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        groupC3_2->setTitle(QCoreApplication::translate("frmPlcCommunicateClass", "\350\276\223\345\207\272\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmPlcCommunicateClass", "\350\276\223\345\207\272\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmPlcCommunicateClass: public Ui_frmPlcCommunicateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPLCCOMMUNICATE_H
