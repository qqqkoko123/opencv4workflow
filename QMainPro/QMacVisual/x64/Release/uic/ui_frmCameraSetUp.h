/********************************************************************************
** Form generated from reading UI file 'frmCameraSetUp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCAMERASETUP_H
#define UI_FRMCAMERASETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frmCameraSetUpClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QComboBox *comboCameraName;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnSearchCamera;
    QSpacerItem *verticalSpacer_3;
    QFrame *frame_4;
    QGridLayout *gridLayout_2;
    QSpinBox *spinTimeOut;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *spinExposure;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLabel *lblType;
    QLabel *label_11;
    QComboBox *comboTriggerMode;
    QLabel *label_10;
    QLineEdit *txtRemark;
    QLabel *label_3;
    QDoubleSpinBox *spinGain;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_7;
    QDoubleSpinBox *spinGamma;
    QLabel *label_8;
    QSpinBox *spinContrast;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnConnect;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnDisconnect;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *btnSave;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *comboCamera;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnAddCamera;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *frmCameraSetUpClass)
    {
        if (frmCameraSetUpClass->objectName().isEmpty())
            frmCameraSetUpClass->setObjectName(QString::fromUtf8("frmCameraSetUpClass"));
        frmCameraSetUpClass->resize(850, 530);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmCameraSetUpClass->sizePolicy().hasHeightForWidth());
        frmCameraSetUpClass->setSizePolicy(sizePolicy);
        frmCameraSetUpClass->setMinimumSize(QSize(850, 530));
        frmCameraSetUpClass->setMaximumSize(QSize(850, 530));
        frmCameraSetUpClass->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        verticalLayout_2 = new QVBoxLayout(frmCameraSetUpClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 3, 3);
        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(frmCameraSetUpClass);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
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
"    background-color: #b7c7a7;\n"
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
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setGridStyle(Qt::DashLine);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(1);
        tableWidget->horizontalHeader()->setDefaultSectionSize(256);

        verticalLayout->addWidget(tableWidget);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        frame_2 = new QFrame(frmCameraSetUpClass);
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
        verticalLayout_3->setSpacing(7);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(7, 7, 7, 7);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(5, -1, 4, -1);
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border:none;"));

        horizontalLayout_7->addWidget(label_2);

        comboCameraName = new QComboBox(frame_2);
        comboCameraName->setObjectName(QString::fromUtf8("comboCameraName"));
        sizePolicy2.setHeightForWidth(comboCameraName->sizePolicy().hasHeightForWidth());
        comboCameraName->setSizePolicy(sizePolicy2);
        comboCameraName->setMinimumSize(QSize(0, 33));
        comboCameraName->setMaximumSize(QSize(16777215, 33));
        comboCameraName->setFont(font1);
        comboCameraName->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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

        horizontalLayout_7->addWidget(comboCameraName);

        horizontalSpacer_8 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        btnSearchCamera = new QPushButton(frame_2);
        btnSearchCamera->setObjectName(QString::fromUtf8("btnSearchCamera"));
        sizePolicy.setHeightForWidth(btnSearchCamera->sizePolicy().hasHeightForWidth());
        btnSearchCamera->setSizePolicy(sizePolicy);
        btnSearchCamera->setMinimumSize(QSize(90, 37));
        btnSearchCamera->setFont(font1);
        btnSearchCamera->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(29, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(29, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(29, 82, 72);}"));

        horizontalLayout_7->addWidget(btnSearchCamera);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy4);
        frame_4->setMinimumSize(QSize(0, 295));
        frame_4->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_4);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(7);
        gridLayout_2->setVerticalSpacing(23);
        gridLayout_2->setContentsMargins(5, 7, 5, 9);
        spinTimeOut = new QSpinBox(frame_4);
        spinTimeOut->setObjectName(QString::fromUtf8("spinTimeOut"));
        sizePolicy.setHeightForWidth(spinTimeOut->sizePolicy().hasHeightForWidth());
        spinTimeOut->setSizePolicy(sizePolicy);
        spinTimeOut->setMinimumSize(QSize(106, 28));
        spinTimeOut->setMaximumSize(QSize(106, 28));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        spinTimeOut->setFont(font2);
        spinTimeOut->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(0, 0, 200);background-color: rgb(239, 239, 239);}\n"
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
        spinTimeOut->setAlignment(Qt::AlignCenter);
        spinTimeOut->setMinimum(1);
        spinTimeOut->setMaximum(10000);
        spinTimeOut->setValue(500);
        spinTimeOut->setDisplayIntegerBase(10);

        gridLayout_2->addWidget(spinTimeOut, 5, 6, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 7, 0, 1, 1);

        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_2->addWidget(label_4, 3, 4, 1, 1);

        label_5 = new QLabel(frame_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_2->addWidget(label_5, 5, 0, 1, 1);

        spinExposure = new QSpinBox(frame_4);
        spinExposure->setObjectName(QString::fromUtf8("spinExposure"));
        sizePolicy.setHeightForWidth(spinExposure->sizePolicy().hasHeightForWidth());
        spinExposure->setSizePolicy(sizePolicy);
        spinExposure->setMinimumSize(QSize(106, 28));
        spinExposure->setMaximumSize(QSize(106, 28));
        spinExposure->setFont(font2);
        spinExposure->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(0, 0, 200);background-color: rgb(239, 239, 239);}\n"
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
        spinExposure->setAlignment(Qt::AlignCenter);
        spinExposure->setMinimum(1);
        spinExposure->setMaximum(1728000);
        spinExposure->setValue(10000);

        gridLayout_2->addWidget(spinExposure, 3, 2, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(frame_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(0, 28));
        label_6->setMaximumSize(QSize(16777215, 28));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgba(255, 254, 237,0);\n"
"border:none;"));

        horizontalLayout_8->addWidget(label_6);

        lblType = new QLabel(frame_4);
        lblType->setObjectName(QString::fromUtf8("lblType"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        lblType->setFont(font3);
        lblType->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 254, 237,130);\n"
"color: rgb(129, 0, 193);"));
        lblType->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(lblType);


        gridLayout_2->addLayout(horizontalLayout_8, 1, 0, 1, 7);

        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_2->addWidget(label_11, 6, 0, 1, 1);

        comboTriggerMode = new QComboBox(frame_4);
        comboTriggerMode->addItem(QString());
        comboTriggerMode->addItem(QString());
        comboTriggerMode->addItem(QString());
        comboTriggerMode->setObjectName(QString::fromUtf8("comboTriggerMode"));
        sizePolicy.setHeightForWidth(comboTriggerMode->sizePolicy().hasHeightForWidth());
        comboTriggerMode->setSizePolicy(sizePolicy);
        comboTriggerMode->setMinimumSize(QSize(100, 30));
        comboTriggerMode->setMaximumSize(QSize(106, 28));
        comboTriggerMode->setFont(font1);
        comboTriggerMode->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 6.5em;\n"
"    color: rgb(0, 0, 200);\n"
"	background-color: rgb(239, 239, 239);\n"
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

        gridLayout_2->addWidget(comboTriggerMode, 5, 2, 1, 1);

        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_2->addWidget(label_10, 5, 4, 1, 1);

        txtRemark = new QLineEdit(frame_4);
        txtRemark->setObjectName(QString::fromUtf8("txtRemark"));
        txtRemark->setMinimumSize(QSize(0, 28));
        txtRemark->setFont(font1);
        txtRemark->setStyleSheet(QString::fromUtf8("border: 1px solid white ;\n"
"background-color: rgb(239, 239, 239);\n"
"color: rgb(0, 0, 200);"));

        gridLayout_2->addWidget(txtRemark, 6, 2, 1, 5);

        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        spinGain = new QDoubleSpinBox(frame_4);
        spinGain->setObjectName(QString::fromUtf8("spinGain"));
        sizePolicy.setHeightForWidth(spinGain->sizePolicy().hasHeightForWidth());
        spinGain->setSizePolicy(sizePolicy);
        spinGain->setMinimumSize(QSize(106, 28));
        spinGain->setMaximumSize(QSize(106, 28));
        spinGain->setFont(font2);
        spinGain->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(0, 0, 200);background-color: rgb(239, 239, 239);}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/res/ico/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/res/ico/down.png);\n"
"}"));
        spinGain->setAlignment(Qt::AlignCenter);
        spinGain->setDecimals(1);
        spinGain->setMinimum(1.000000000000000);
        spinGain->setMaximum(32.000000000000000);
        spinGain->setSingleStep(0.100000000000000);
        spinGain->setValue(1.000000000000000);

        gridLayout_2->addWidget(spinGain, 3, 6, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(250, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 3, 3, 1, 1);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        spinGamma = new QDoubleSpinBox(frame_4);
        spinGamma->setObjectName(QString::fromUtf8("spinGamma"));
        sizePolicy.setHeightForWidth(spinGamma->sizePolicy().hasHeightForWidth());
        spinGamma->setSizePolicy(sizePolicy);
        spinGamma->setMinimumSize(QSize(106, 28));
        spinGamma->setMaximumSize(QSize(106, 28));
        spinGamma->setFont(font2);
        spinGamma->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(0, 0, 200);background-color: rgb(239, 239, 239);}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/res/ico/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/res/ico/down.png);\n"
"}"));
        spinGamma->setAlignment(Qt::AlignCenter);
        spinGamma->setMaximum(2.500000000000000);
        spinGamma->setSingleStep(0.100000000000000);
        spinGamma->setValue(1.000000000000000);

        gridLayout_2->addWidget(spinGamma, 4, 2, 1, 1);

        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);\n"
"color: rgb(0, 0, 0);\n"
"border:none;"));

        gridLayout_2->addWidget(label_8, 4, 4, 1, 1);

        spinContrast = new QSpinBox(frame_4);
        spinContrast->setObjectName(QString::fromUtf8("spinContrast"));
        sizePolicy.setHeightForWidth(spinContrast->sizePolicy().hasHeightForWidth());
        spinContrast->setSizePolicy(sizePolicy);
        spinContrast->setMinimumSize(QSize(106, 28));
        spinContrast->setMaximumSize(QSize(106, 28));
        spinContrast->setFont(font2);
        spinContrast->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(0, 0, 200);background-color: rgb(239, 239, 239);}\n"
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
        spinContrast->setAlignment(Qt::AlignCenter);
        spinContrast->setMaximum(200);
        spinContrast->setValue(100);

        gridLayout_2->addWidget(spinContrast, 4, 6, 1, 1);


        verticalLayout_3->addWidget(frame_4);


        horizontalLayout_3->addWidget(frame_2);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_3 = new QFrame(frmCameraSetUpClass);
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
        btnConnect->setFont(font1);
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
        btnDisconnect->setFont(font1);
        btnDisconnect->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 103, 96);}"));

        horizontalLayout_6->addWidget(btnDisconnect);

        horizontalSpacer_11 = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        btnSave = new QPushButton(frame_3);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        sizePolicy.setHeightForWidth(btnSave->sizePolicy().hasHeightForWidth());
        btnSave->setSizePolicy(sizePolicy);
        btnSave->setMinimumSize(QSize(90, 37));
        btnSave->setFont(font1);
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

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        frame = new QFrame(frmCameraSetUpClass);
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
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 200,180);\n"
"border:none;"));

        horizontalLayout_5->addWidget(label);

        comboCamera = new QComboBox(frame);
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->setObjectName(QString::fromUtf8("comboCamera"));
        sizePolicy.setHeightForWidth(comboCamera->sizePolicy().hasHeightForWidth());
        comboCamera->setSizePolicy(sizePolicy);
        comboCamera->setMinimumSize(QSize(115, 33));
        comboCamera->setMaximumSize(QSize(16777215, 33));
        comboCamera->setFont(font1);
        comboCamera->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 7.5em;\n"
"    color: rgb(249, 245, 241);\n"
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

        horizontalLayout_5->addWidget(comboCamera);

        horizontalSpacer_7 = new QSpacerItem(45, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        btnAddCamera = new QPushButton(frame);
        btnAddCamera->setObjectName(QString::fromUtf8("btnAddCamera"));
        btnAddCamera->setMinimumSize(QSize(90, 37));
        btnAddCamera->setFont(font1);
        btnAddCamera->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(29, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(29, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(29, 82, 72);}"));

        horizontalLayout_5->addWidget(btnAddCamera);

        horizontalSpacer_2 = new QSpacerItem(40, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        horizontalLayout_4->addWidget(frame);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(frmCameraSetUpClass);

        QMetaObject::connectSlotsByName(frmCameraSetUpClass);
    } // setupUi

    void retranslateUi(QDialog *frmCameraSetUpClass)
    {
        frmCameraSetUpClass->setWindowTitle(QCoreApplication::translate("frmCameraSetUpClass", "\347\233\270\346\234\272\350\256\276\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmCameraSetUpClass", "\347\233\270\346\234\272\345\210\227\350\241\250", nullptr));
        label_2->setText(QCoreApplication::translate("frmCameraSetUpClass", "\347\233\270\346\234\272\345\220\215\347\247\260\357\274\232", nullptr));
        btnSearchCamera->setText(QCoreApplication::translate("frmCameraSetUpClass", "\346\220\234\347\264\242\347\233\270\346\234\272", nullptr));
        label_4->setText(QCoreApplication::translate("frmCameraSetUpClass", "\345\242\236\347\233\212\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("frmCameraSetUpClass", "\350\247\246\345\217\221\346\250\241\345\274\217\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("frmCameraSetUpClass", "\351\200\211\346\213\251\347\233\270\346\234\272\345\220\215\347\247\260\357\274\232", nullptr));
        lblType->setText(QString());
        label_11->setText(QCoreApplication::translate("frmCameraSetUpClass", "\345\244\207\346\263\250\357\274\232", nullptr));
        comboTriggerMode->setItemText(0, QCoreApplication::translate("frmCameraSetUpClass", "\350\277\236\347\273\255\351\207\207\351\233\206", nullptr));
        comboTriggerMode->setItemText(1, QCoreApplication::translate("frmCameraSetUpClass", "\350\275\257\344\273\266\350\247\246\345\217\221", nullptr));
        comboTriggerMode->setItemText(2, QCoreApplication::translate("frmCameraSetUpClass", "\347\241\254\344\273\266\350\247\246\345\217\221", nullptr));

        label_10->setText(QCoreApplication::translate("frmCameraSetUpClass", "\350\266\205\346\227\266(ms)\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("frmCameraSetUpClass", "\346\233\235\345\205\211(us)\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("frmCameraSetUpClass", "\344\274\275\351\251\254\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("frmCameraSetUpClass", "\345\257\271\346\257\224\345\272\246\357\274\232", nullptr));
        btnConnect->setText(QCoreApplication::translate("frmCameraSetUpClass", "\350\277\236\346\216\245\347\233\270\346\234\272", nullptr));
        btnDisconnect->setText(QCoreApplication::translate("frmCameraSetUpClass", "\346\226\255\345\274\200\347\233\270\346\234\272", nullptr));
        btnSave->setText(QCoreApplication::translate("frmCameraSetUpClass", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("frmCameraSetUpClass", "\347\233\270\346\234\272\345\223\201\347\211\214\357\274\232", nullptr));
        comboCamera->setItemText(0, QCoreApplication::translate("frmCameraSetUpClass", "MindVision", nullptr));
        comboCamera->setItemText(1, QCoreApplication::translate("frmCameraSetUpClass", "HIKVision", nullptr));

        btnAddCamera->setText(QCoreApplication::translate("frmCameraSetUpClass", "\346\267\273\345\212\240\347\233\270\346\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmCameraSetUpClass: public Ui_frmCameraSetUpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCAMERASETUP_H
