/********************************************************************************
** Form generated from reading UI file 'frmSerialPort.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSERIALPORT_H
#define UI_FRMSERIALPORT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmSerialPortClass
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
    QGroupBox *groupC2;
    QPushButton *btnDelLinkContent;
    QPushButton *btnLinkContent;
    QLabel *label_4;
    QLineEdit *txtLinkContent;
    QCheckBox *chkComHexSend;
    QLabel *label_5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioEndNull;
    QRadioButton *radioEndEnter;
    QRadioButton *radioEndNewline;
    QRadioButton *radioEndEnterNewline;
    QCheckBox *chkSendEnable;
    QGroupBox *groupC3;
    QCheckBox *chkComHexReceive;
    QPushButton *btnComClear;
    QTextEdit *txtComReceiveData;
    QCheckBox *chkReceiveEnable;

    void setupUi(QDialog *frmSerialPortClass)
    {
        if (frmSerialPortClass->objectName().isEmpty())
            frmSerialPortClass->setObjectName(QString::fromUtf8("frmSerialPortClass"));
        frmSerialPortClass->resize(720, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmSerialPortClass->sizePolicy().hasHeightForWidth());
        frmSerialPortClass->setSizePolicy(sizePolicy);
        frmSerialPortClass->setMinimumSize(QSize(720, 500));
        frmSerialPortClass->setMaximumSize(QSize(720, 500));
        frmSerialPortClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmSerialPortClass);
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

        label_3 = new QLabel(frmSerialPortClass);
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

        txtDescribe = new QLineEdit(frmSerialPortClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmSerialPortClass);
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

        tabWidget = new QTabWidget(frmSerialPortClass);
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
        groupC2 = new QGroupBox(tab);
        groupC2->setObjectName(QString::fromUtf8("groupC2"));
        groupC2->setGeometry(QRect(12, 100, 690, 99));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        btnDelLinkContent = new QPushButton(groupC2);
        btnDelLinkContent->setObjectName(QString::fromUtf8("btnDelLinkContent"));
        btnDelLinkContent->setGeometry(QRect(460, 28, 27, 27));
        btnDelLinkContent->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkContent->setIcon(icon);
        btnDelLinkContent->setIconSize(QSize(27, 27));
        btnLinkContent = new QPushButton(groupC2);
        btnLinkContent->setObjectName(QString::fromUtf8("btnLinkContent"));
        btnLinkContent->setGeometry(QRect(428, 28, 27, 27));
        btnLinkContent->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkContent->setIcon(icon1);
        btnLinkContent->setIconSize(QSize(27, 27));
        label_4 = new QLabel(groupC2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(23, 32, 81, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        txtLinkContent = new QLineEdit(groupC2);
        txtLinkContent->setObjectName(QString::fromUtf8("txtLinkContent"));
        txtLinkContent->setGeometry(QRect(106, 28, 313, 28));
        txtLinkContent->setFont(font);
        txtLinkContent->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkContent->setAlignment(Qt::AlignCenter);
        txtLinkContent->setReadOnly(true);
        chkComHexSend = new QCheckBox(groupC2);
        chkComHexSend->setObjectName(QString::fromUtf8("chkComHexSend"));
        chkComHexSend->setGeometry(QRect(554, 68, 121, 27));
        sizePolicy.setHeightForWidth(chkComHexSend->sizePolicy().hasHeightForWidth());
        chkComHexSend->setSizePolicy(sizePolicy);
        chkComHexSend->setFont(font);
        chkComHexSend->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        chkComHexSend->setIconSize(QSize(22, 22));
        label_5 = new QLabel(groupC2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(23, 72, 81, 19));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background-color: rgba(0, 0, 0, 0);"));
        horizontalLayoutWidget = new QWidget(groupC2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(106, 66, 377, 29));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(22);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioEndNull = new QRadioButton(horizontalLayoutWidget);
        radioEndNull->setObjectName(QString::fromUtf8("radioEndNull"));
        radioEndNull->setFont(font);
        radioEndNull->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(0, 0, 0);"));
        radioEndNull->setChecked(true);

        horizontalLayout_2->addWidget(radioEndNull);

        radioEndEnter = new QRadioButton(horizontalLayoutWidget);
        radioEndEnter->setObjectName(QString::fromUtf8("radioEndEnter"));
        radioEndEnter->setFont(font);
        radioEndEnter->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(radioEndEnter);

        radioEndNewline = new QRadioButton(horizontalLayoutWidget);
        radioEndNewline->setObjectName(QString::fromUtf8("radioEndNewline"));
        radioEndNewline->setFont(font);
        radioEndNewline->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(radioEndNewline);

        radioEndEnterNewline = new QRadioButton(horizontalLayoutWidget);
        radioEndEnterNewline->setObjectName(QString::fromUtf8("radioEndEnterNewline"));
        radioEndEnterNewline->setFont(font);
        radioEndEnterNewline->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_2->addWidget(radioEndEnterNewline);

        chkSendEnable = new QCheckBox(groupC2);
        chkSendEnable->setObjectName(QString::fromUtf8("chkSendEnable"));
        chkSendEnable->setGeometry(QRect(554, 28, 97, 27));
        sizePolicy.setHeightForWidth(chkSendEnable->sizePolicy().hasHeightForWidth());
        chkSendEnable->setSizePolicy(sizePolicy);
        chkSendEnable->setFont(font);
        chkSendEnable->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        chkSendEnable->setIconSize(QSize(22, 22));
        chkSendEnable->setChecked(true);
        groupC3 = new QGroupBox(tab);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(12, 214, 690, 147));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        chkComHexReceive = new QCheckBox(groupC3);
        chkComHexReceive->setObjectName(QString::fromUtf8("chkComHexReceive"));
        chkComHexReceive->setGeometry(QRect(554, 30, 121, 27));
        sizePolicy.setHeightForWidth(chkComHexReceive->sizePolicy().hasHeightForWidth());
        chkComHexReceive->setSizePolicy(sizePolicy);
        chkComHexReceive->setFont(font);
        chkComHexReceive->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        chkComHexReceive->setIconSize(QSize(22, 22));
        btnComClear = new QPushButton(groupC3);
        btnComClear->setObjectName(QString::fromUtf8("btnComClear"));
        btnComClear->setGeometry(QRect(23, 30, 85, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        btnComClear->setFont(font2);
        btnComClear->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        txtComReceiveData = new QTextEdit(groupC3);
        txtComReceiveData->setObjectName(QString::fromUtf8("txtComReceiveData"));
        txtComReceiveData->setGeometry(QRect(23, 68, 644, 75));
        txtComReceiveData->setStyleSheet(QString::fromUtf8("QTextEdit         \n"
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
        txtComReceiveData->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        chkReceiveEnable = new QCheckBox(groupC3);
        chkReceiveEnable->setObjectName(QString::fromUtf8("chkReceiveEnable"));
        chkReceiveEnable->setGeometry(QRect(390, 30, 97, 27));
        sizePolicy.setHeightForWidth(chkReceiveEnable->sizePolicy().hasHeightForWidth());
        chkReceiveEnable->setSizePolicy(sizePolicy);
        chkReceiveEnable->setFont(font);
        chkReceiveEnable->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        chkReceiveEnable->setIconSize(QSize(22, 22));
        chkReceiveEnable->setChecked(true);
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(frmSerialPortClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmSerialPortClass);
    } // setupUi

    void retranslateUi(QDialog *frmSerialPortClass)
    {
        frmSerialPortClass->setWindowTitle(QCoreApplication::translate("frmSerialPortClass", "\344\270\262\345\217\243\351\200\232\344\277\241", nullptr));
        label_3->setText(QCoreApplication::translate("frmSerialPortClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmSerialPortClass", "\346\211\247\350\241\214", nullptr));
        groupC->setTitle(QCoreApplication::translate("frmSerialPortClass", "\351\200\232\350\256\257\345\257\271\350\261\241", nullptr));
        lblMsg->setText(QString());
        label_8->setText(QCoreApplication::translate("frmSerialPortClass", "\351\200\232\350\256\257\345\220\215\347\247\260\357\274\232", nullptr));
        btnUpdata->setText(QCoreApplication::translate("frmSerialPortClass", "\346\233\264\346\226\260\345\210\227\350\241\250", nullptr));
        groupC2->setTitle(QCoreApplication::translate("frmSerialPortClass", "\345\217\221\351\200\201\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkContent->setToolTip(QCoreApplication::translate("frmSerialPortClass", "\345\210\240\351\231\244\345\217\221\351\200\201\345\206\205\345\256\271\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkContent->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkContent->setToolTip(QCoreApplication::translate("frmSerialPortClass", "\351\223\276\346\216\245\345\217\221\351\200\201\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkContent->setText(QString());
        label_4->setText(QCoreApplication::translate("frmSerialPortClass", "\345\217\221\351\200\201\345\206\205\345\256\271\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkContent->setToolTip(QCoreApplication::translate("frmSerialPortClass", "\345\205\250\345\261\200\345\217\230\351\207\217QString\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        chkComHexSend->setText(QCoreApplication::translate("frmSerialPortClass", "16\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        label_5->setText(QCoreApplication::translate("frmSerialPortClass", "\347\273\223\346\235\237\347\254\246\357\274\232", nullptr));
        radioEndNull->setText(QCoreApplication::translate("frmSerialPortClass", "\346\227\240", nullptr));
        radioEndEnter->setText(QCoreApplication::translate("frmSerialPortClass", "\345\233\236\350\275\246", nullptr));
        radioEndNewline->setText(QCoreApplication::translate("frmSerialPortClass", "\346\215\242\350\241\214", nullptr));
        radioEndEnterNewline->setText(QCoreApplication::translate("frmSerialPortClass", "\345\233\236\350\275\246\346\215\242\350\241\214", nullptr));
        chkSendEnable->setText(QCoreApplication::translate("frmSerialPortClass", "\345\217\221\351\200\201\344\275\277\350\203\275", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmSerialPortClass", "\346\216\245\346\224\266\350\256\276\347\275\256", nullptr));
        chkComHexReceive->setText(QCoreApplication::translate("frmSerialPortClass", "16\350\277\233\345\210\266\346\216\245\346\224\266", nullptr));
        btnComClear->setText(QCoreApplication::translate("frmSerialPortClass", "\346\270\205\347\251\272\346\216\245\346\224\266", nullptr));
        chkReceiveEnable->setText(QCoreApplication::translate("frmSerialPortClass", "\346\216\245\346\224\266\344\275\277\350\203\275", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmSerialPortClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmSerialPortClass: public Ui_frmSerialPortClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSERIALPORT_H
