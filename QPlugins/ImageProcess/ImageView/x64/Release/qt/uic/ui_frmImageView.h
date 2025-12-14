/********************************************************************************
** Form generated from reading UI file 'frmImageView.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMIMAGEVIEW_H
#define UI_FRMIMAGEVIEW_H

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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmImageViewClass
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
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupC1;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QComboBox *comboScreenNum;
    QLabel *label_5;
    QGroupBox *groupC2;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *spinContour;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetContour;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnAddContour;
    QPushButton *btnDeleteContour;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnColor;
    QCheckBox *checkViewContour;
    QCheckBox *checkViewContourC;
    QSpinBox *spinCrossSize;
    QLabel *label_9;
    QWidget *tab_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGroupBox *groupC3;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetText;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnAddText;
    QPushButton *btnDeleteText;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_6;
    QSpinBox *spinTextSize;
    QCheckBox *checkBoldFont;
    QCheckBox *checkViewText;
    QWidget *page_2;
    QGroupBox *groupCamera_4;
    QLabel *label_10;
    QPushButton *btnOkColor;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *txtPos_XY;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *btnNgColor;
    QLineEdit *txtPrefix;
    QLineEdit *txtState;
    QPushButton *btnLinkState;
    QPushButton *btnDelLinkState;
    QLineEdit *txtContent;
    QPushButton *btnLinkContent;
    QPushButton *btnDelLinkContent;
    QPushButton *btnLinkPos_XY;
    QPushButton *btnDelLinkPos_XY;
    QPushButton *btnBack;
    QLabel *label;
    QPushButton *btnSave;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *txtOKtext;
    QLineEdit *txtNGtext;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmImageViewClass)
    {
        if (frmImageViewClass->objectName().isEmpty())
            frmImageViewClass->setObjectName(QString::fromUtf8("frmImageViewClass"));
        frmImageViewClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmImageViewClass->sizePolicy().hasHeightForWidth());
        frmImageViewClass->setSizePolicy(sizePolicy);
        frmImageViewClass->setMinimumSize(QSize(1160, 655));
        frmImageViewClass->setMaximumSize(QSize(1160, 655));
        frmImageViewClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmImageViewClass);
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

        label_3 = new QLabel(frmImageViewClass);
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

        txtDescribe = new QLineEdit(frmImageViewClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmImageViewClass);
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

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frmImageViewClass);
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
        groupC1 = new QGroupBox(tab);
        groupC1->setObjectName(QString::fromUtf8("groupC1"));
        groupC1->setGeometry(QRect(9, 12, 427, 115));
        groupC1->setFont(font);
        groupC1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(0, 0, 255);"));
        label_4 = new QLabel(groupC1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 42, 79, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        txtLinkImage = new QLineEdit(groupC1);
        txtLinkImage->setObjectName(QString::fromUtf8("txtLinkImage"));
        txtLinkImage->setGeometry(QRect(100, 39, 255, 27));
        txtLinkImage->setFont(font);
        txtLinkImage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkImage->setAlignment(Qt::AlignCenter);
        txtLinkImage->setReadOnly(true);
        btnLinkImage = new QPushButton(groupC1);
        btnLinkImage->setObjectName(QString::fromUtf8("btnLinkImage"));
        btnLinkImage->setGeometry(QRect(360, 39, 27, 27));
        btnLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkImage->setIcon(icon);
        btnLinkImage->setIconSize(QSize(27, 27));
        btnDelLinkImage = new QPushButton(groupC1);
        btnDelLinkImage->setObjectName(QString::fromUtf8("btnDelLinkImage"));
        btnDelLinkImage->setGeometry(QRect(394, 39, 27, 27));
        btnDelLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkImage->setIcon(icon1);
        btnDelLinkImage->setIconSize(QSize(27, 27));
        comboScreenNum = new QComboBox(groupC1);
        comboScreenNum->addItem(QString());
        comboScreenNum->addItem(QString());
        comboScreenNum->addItem(QString());
        comboScreenNum->addItem(QString());
        comboScreenNum->addItem(QString());
        comboScreenNum->addItem(QString());
        comboScreenNum->addItem(QString());
        comboScreenNum->addItem(QString());
        comboScreenNum->addItem(QString());
        comboScreenNum->addItem(QString());
        comboScreenNum->setObjectName(QString::fromUtf8("comboScreenNum"));
        comboScreenNum->setGeometry(QRect(100, 78, 255, 27));
        comboScreenNum->setFont(font);
        comboScreenNum->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 16.85em;\n"
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
        label_5 = new QLabel(groupC1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 82, 79, 19));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        groupC2 = new QGroupBox(tab);
        groupC2->setObjectName(QString::fromUtf8("groupC2"));
        groupC2->setGeometry(QRect(9, 136, 427, 383));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(0, 0, 255);"));
        label_7 = new QLabel(groupC2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(13, 78, 79, 19));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        label_8 = new QLabel(groupC2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(13, 120, 79, 19));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        spinContour = new QSpinBox(groupC2);
        spinContour->setObjectName(QString::fromUtf8("spinContour"));
        spinContour->setGeometry(QRect(100, 116, 255, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        spinContour->setFont(font1);
        spinContour->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinContour->setAlignment(Qt::AlignCenter);
        spinContour->setMinimum(1);
        spinContour->setMaximum(100);
        spinContour->setValue(2);
        horizontalLayoutWidget = new QWidget(groupC2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 197, 409, 181));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(horizontalLayoutWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidgetContour = new QTableWidget(frame);
        if (tableWidgetContour->columnCount() < 1)
            tableWidgetContour->setColumnCount(1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        tableWidgetContour->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetContour->setObjectName(QString::fromUtf8("tableWidgetContour"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tableWidgetContour->setFont(font3);
        tableWidgetContour->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: #b7c7af;  \n"
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
"		padding-left:2px;\n"
""
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
        tableWidgetContour->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetContour->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetContour->setGridStyle(Qt::DashLine);
        tableWidgetContour->horizontalHeader()->setMinimumSectionSize(29);
        tableWidgetContour->horizontalHeader()->setDefaultSectionSize(336);
        tableWidgetContour->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout->addWidget(tableWidgetContour);


        horizontalLayout_2->addWidget(frame);

        frame_2 = new QFrame(horizontalLayoutWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);\n"
"background-color: #b7c7a7;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(13);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 2, 1, 1);
        btnAddContour = new QPushButton(frame_2);
        btnAddContour->setObjectName(QString::fromUtf8("btnAddContour"));
        sizePolicy.setHeightForWidth(btnAddContour->sizePolicy().hasHeightForWidth());
        btnAddContour->setSizePolicy(sizePolicy);
        btnAddContour->setMinimumSize(QSize(60, 30));
        btnAddContour->setFont(font2);
        btnAddContour->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_2->addWidget(btnAddContour);

        btnDeleteContour = new QPushButton(frame_2);
        btnDeleteContour->setObjectName(QString::fromUtf8("btnDeleteContour"));
        btnDeleteContour->setMinimumSize(QSize(60, 30));
        btnDeleteContour->setFont(font2);
        btnDeleteContour->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));

        verticalLayout_2->addWidget(btnDeleteContour);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_2->addWidget(frame_2);

        btnColor = new QPushButton(groupC2);
        btnColor->setObjectName(QString::fromUtf8("btnColor"));
        btnColor->setGeometry(QRect(100, 74, 255, 27));
        btnColor->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgba(0, 255, 0);"));
        checkViewContour = new QCheckBox(groupC2);
        checkViewContour->setObjectName(QString::fromUtf8("checkViewContour"));
        checkViewContour->setGeometry(QRect(13, 36, 139, 23));
        checkViewContour->setFont(font1);
        checkViewContour->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkViewContour->setIconSize(QSize(22, 22));
        checkViewContour->setChecked(false);
        checkViewContourC = new QCheckBox(groupC2);
        checkViewContourC->setObjectName(QString::fromUtf8("checkViewContourC"));
        checkViewContourC->setGeometry(QRect(13, 158, 175, 23));
        checkViewContourC->setFont(font1);
        checkViewContourC->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkViewContourC->setIconSize(QSize(22, 22));
        spinCrossSize = new QSpinBox(groupC2);
        spinCrossSize->setObjectName(QString::fromUtf8("spinCrossSize"));
        spinCrossSize->setGeometry(QRect(295, 157, 60, 27));
        spinCrossSize->setFont(font1);
        spinCrossSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinCrossSize->setAlignment(Qt::AlignCenter);
        spinCrossSize->setMinimum(1);
        spinCrossSize->setMaximum(200);
        spinCrossSize->setValue(10);
        label_9 = new QLabel(groupC2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(214, 161, 79, 19));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        stackedWidget = new QStackedWidget(tab_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(2, 2, 439, 519));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        groupC3 = new QGroupBox(page);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(6, 10, 427, 507));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(0, 0, 255);"));
        horizontalLayoutWidget_2 = new QWidget(groupC3);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 119, 409, 383));
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
        tableWidgetText = new QTableWidget(frame_3);
        if (tableWidgetText->columnCount() < 1)
            tableWidgetText->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        tableWidgetText->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        tableWidgetText->setObjectName(QString::fromUtf8("tableWidgetText"));
        tableWidgetText->setFont(font3);
        tableWidgetText->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: #b7c7af;  \n"
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
"		padding-left:2px;\n"
""
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
        tableWidgetText->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetText->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetText->setGridStyle(Qt::DashLine);
        tableWidgetText->horizontalHeader()->setMinimumSectionSize(29);
        tableWidgetText->horizontalHeader()->setDefaultSectionSize(336);
        tableWidgetText->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout_3->addWidget(tableWidgetText);


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
        btnAddText = new QPushButton(frame_4);
        btnAddText->setObjectName(QString::fromUtf8("btnAddText"));
        sizePolicy.setHeightForWidth(btnAddText->sizePolicy().hasHeightForWidth());
        btnAddText->setSizePolicy(sizePolicy);
        btnAddText->setMinimumSize(QSize(60, 30));
        btnAddText->setFont(font2);
        btnAddText->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnAddText);

        btnDeleteText = new QPushButton(frame_4);
        btnDeleteText->setObjectName(QString::fromUtf8("btnDeleteText"));
        btnDeleteText->setMinimumSize(QSize(60, 30));
        btnDeleteText->setFont(font2);
        btnDeleteText->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));

        verticalLayout_4->addWidget(btnDeleteText);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);


        horizontalLayout_3->addWidget(frame_4);

        label_6 = new QLabel(groupC3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(13, 80, 79, 19));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        spinTextSize = new QSpinBox(groupC3);
        spinTextSize->setObjectName(QString::fromUtf8("spinTextSize"));
        spinTextSize->setGeometry(QRect(95, 76, 70, 27));
        spinTextSize->setFont(font1);
        spinTextSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinTextSize->setAlignment(Qt::AlignCenter);
        spinTextSize->setMinimum(5);
        spinTextSize->setMaximum(1000);
        spinTextSize->setSingleStep(1);
        spinTextSize->setValue(50);
        checkBoldFont = new QCheckBox(groupC3);
        checkBoldFont->setObjectName(QString::fromUtf8("checkBoldFont"));
        checkBoldFont->setGeometry(QRect(262, 80, 91, 19));
        checkBoldFont->setFont(font);
        checkBoldFont->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkBoldFont->setChecked(true);
        checkViewText = new QCheckBox(groupC3);
        checkViewText->setObjectName(QString::fromUtf8("checkViewText"));
        checkViewText->setGeometry(QRect(13, 34, 139, 23));
        checkViewText->setFont(font1);
        checkViewText->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkViewText->setIconSize(QSize(22, 22));
        checkViewText->setChecked(false);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupCamera_4 = new QGroupBox(page_2);
        groupCamera_4->setObjectName(QString::fromUtf8("groupCamera_4"));
        groupCamera_4->setGeometry(QRect(6, 10, 427, 507));
        groupCamera_4->setFont(font);
        groupCamera_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(0, 0, 255);"));
        label_10 = new QLabel(groupCamera_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(14, 42, 80, 19));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        btnOkColor = new QPushButton(groupCamera_4);
        btnOkColor->setObjectName(QString::fromUtf8("btnOkColor"));
        btnOkColor->setGeometry(QRect(95, 238, 91, 27));
        btnOkColor->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgba(0, 255, 0);"));
        label_12 = new QLabel(groupCamera_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(14, 92, 80, 19));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        label_13 = new QLabel(groupCamera_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(14, 192, 80, 19));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        label_14 = new QLabel(groupCamera_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(14, 142, 80, 19));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        txtPos_XY = new QLineEdit(groupCamera_4);
        txtPos_XY->setObjectName(QString::fromUtf8("txtPos_XY"));
        txtPos_XY->setGeometry(QRect(95, 38, 260, 27));
        txtPos_XY->setFont(font);
        txtPos_XY->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtPos_XY->setAlignment(Qt::AlignCenter);
        txtPos_XY->setReadOnly(true);
        label_16 = new QLabel(groupCamera_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(14, 242, 75, 19));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        label_17 = new QLabel(groupCamera_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(14, 292, 75, 19));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        btnNgColor = new QPushButton(groupCamera_4);
        btnNgColor->setObjectName(QString::fromUtf8("btnNgColor"));
        btnNgColor->setGeometry(QRect(95, 288, 91, 27));
        btnNgColor->setStyleSheet(QString::fromUtf8("border:none;\n"
"background-color: rgba(255, 0, 0);"));
        txtPrefix = new QLineEdit(groupCamera_4);
        txtPrefix->setObjectName(QString::fromUtf8("txtPrefix"));
        txtPrefix->setGeometry(QRect(95, 188, 260, 27));
        txtPrefix->setFont(font);
        txtPrefix->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,250);"));
        txtPrefix->setAlignment(Qt::AlignCenter);
        txtPrefix->setReadOnly(false);
        txtState = new QLineEdit(groupCamera_4);
        txtState->setObjectName(QString::fromUtf8("txtState"));
        txtState->setGeometry(QRect(95, 88, 260, 27));
        txtState->setFont(font);
        txtState->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtState->setAlignment(Qt::AlignCenter);
        txtState->setReadOnly(true);
        btnLinkState = new QPushButton(groupCamera_4);
        btnLinkState->setObjectName(QString::fromUtf8("btnLinkState"));
        btnLinkState->setGeometry(QRect(360, 88, 27, 27));
        btnLinkState->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkState->setIcon(icon);
        btnLinkState->setIconSize(QSize(27, 27));
        btnDelLinkState = new QPushButton(groupCamera_4);
        btnDelLinkState->setObjectName(QString::fromUtf8("btnDelLinkState"));
        btnDelLinkState->setGeometry(QRect(394, 88, 27, 27));
        btnDelLinkState->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkState->setIcon(icon1);
        btnDelLinkState->setIconSize(QSize(27, 27));
        txtContent = new QLineEdit(groupCamera_4);
        txtContent->setObjectName(QString::fromUtf8("txtContent"));
        txtContent->setGeometry(QRect(95, 138, 260, 27));
        txtContent->setFont(font);
        txtContent->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtContent->setAlignment(Qt::AlignCenter);
        txtContent->setReadOnly(true);
        btnLinkContent = new QPushButton(groupCamera_4);
        btnLinkContent->setObjectName(QString::fromUtf8("btnLinkContent"));
        btnLinkContent->setGeometry(QRect(360, 138, 27, 27));
        btnLinkContent->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkContent->setIcon(icon);
        btnLinkContent->setIconSize(QSize(27, 27));
        btnDelLinkContent = new QPushButton(groupCamera_4);
        btnDelLinkContent->setObjectName(QString::fromUtf8("btnDelLinkContent"));
        btnDelLinkContent->setGeometry(QRect(394, 138, 27, 27));
        btnDelLinkContent->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkContent->setIcon(icon1);
        btnDelLinkContent->setIconSize(QSize(27, 27));
        btnLinkPos_XY = new QPushButton(groupCamera_4);
        btnLinkPos_XY->setObjectName(QString::fromUtf8("btnLinkPos_XY"));
        btnLinkPos_XY->setGeometry(QRect(360, 38, 27, 27));
        btnLinkPos_XY->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkPos_XY->setIcon(icon);
        btnLinkPos_XY->setIconSize(QSize(27, 27));
        btnDelLinkPos_XY = new QPushButton(groupCamera_4);
        btnDelLinkPos_XY->setObjectName(QString::fromUtf8("btnDelLinkPos_XY"));
        btnDelLinkPos_XY->setGeometry(QRect(394, 38, 27, 27));
        btnDelLinkPos_XY->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkPos_XY->setIcon(icon1);
        btnDelLinkPos_XY->setIconSize(QSize(27, 27));
        btnBack = new QPushButton(groupCamera_4);
        btnBack->setObjectName(QString::fromUtf8("btnBack"));
        btnBack->setGeometry(QRect(352, 466, 70, 35));
        btnBack->setMinimumSize(QSize(70, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setWeight(75);
        btnBack->setFont(font4);
        btnBack->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(225, 255, 127,100);}\n"
"QWidget{ color: rgb(55, 55, 55);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(225, 255, 127,150);}\n"
"QPushButton:pressed{background-color: rgba(225, 255, 127,255);}"));
        label = new QLabel(groupCamera_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(294, 342, 48, 32));
        label->setStyleSheet(QString::fromUtf8("background: transparent;"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/resource/a_right_2.png")));
        label->setScaledContents(true);
        btnSave = new QPushButton(groupCamera_4);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(352, 342, 70, 35));
        btnSave->setMinimumSize(QSize(70, 30));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(9);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(50);
        btnSave->setFont(font5);
        btnSave->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(125, 255, 127,150);}\n"
"QWidget{ color: rgb(35, 35, 35);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(125, 255, 127,200);}\n"
"QPushButton:pressed{background-color: rgba(125, 255, 127,255);}"));
        label_18 = new QLabel(groupCamera_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(200, 240, 61, 19));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        label_19 = new QLabel(groupCamera_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(200, 290, 61, 19));
        label_19->setFont(font);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background: transparent;"));
        txtOKtext = new QLineEdit(groupCamera_4);
        txtOKtext->setObjectName(QString::fromUtf8("txtOKtext"));
        txtOKtext->setGeometry(QRect(270, 240, 141, 27));
        txtOKtext->setFont(font);
        txtOKtext->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,250);"));
        txtOKtext->setAlignment(Qt::AlignCenter);
        txtOKtext->setReadOnly(false);
        txtNGtext = new QLineEdit(groupCamera_4);
        txtNGtext->setObjectName(QString::fromUtf8("txtNGtext"));
        txtNGtext->setGeometry(QRect(270, 290, 141, 27));
        txtNGtext->setFont(font);
        txtNGtext->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,250);"));
        txtNGtext->setAlignment(Qt::AlignCenter);
        txtNGtext->setReadOnly(false);
        label_17->raise();
        label_10->raise();
        btnOkColor->raise();
        label_12->raise();
        label_13->raise();
        label_14->raise();
        txtPos_XY->raise();
        label_16->raise();
        btnNgColor->raise();
        txtPrefix->raise();
        txtState->raise();
        btnLinkState->raise();
        btnDelLinkState->raise();
        txtContent->raise();
        btnLinkContent->raise();
        btnDelLinkContent->raise();
        btnLinkPos_XY->raise();
        btnDelLinkPos_XY->raise();
        btnBack->raise();
        label->raise();
        btnSave->raise();
        label_18->raise();
        label_19->raise();
        txtOKtext->raise();
        txtNGtext->raise();
        stackedWidget->addWidget(page_2);
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        retranslateUi(frmImageViewClass);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmImageViewClass);
    } // setupUi

    void retranslateUi(QDialog *frmImageViewClass)
    {
        frmImageViewClass->setWindowTitle(QCoreApplication::translate("frmImageViewClass", "\345\233\276\345\203\217\346\230\276\347\244\272", nullptr));
        label_3->setText(QCoreApplication::translate("frmImageViewClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmImageViewClass", "\346\211\247\350\241\214", nullptr));
        groupC1->setTitle(QCoreApplication::translate("frmImageViewClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmImageViewClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmImageViewClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmImageViewClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        comboScreenNum->setItemText(0, QCoreApplication::translate("frmImageViewClass", "\346\227\240", nullptr));
        comboScreenNum->setItemText(1, QCoreApplication::translate("frmImageViewClass", "1\345\217\267\347\252\227\344\275\223\346\230\276\347\244\272", nullptr));
        comboScreenNum->setItemText(2, QCoreApplication::translate("frmImageViewClass", "2\345\217\267\347\252\227\344\275\223\346\230\276\347\244\272", nullptr));
        comboScreenNum->setItemText(3, QCoreApplication::translate("frmImageViewClass", "3\345\217\267\347\252\227\344\275\223\346\230\276\347\244\272", nullptr));
        comboScreenNum->setItemText(4, QCoreApplication::translate("frmImageViewClass", "4\345\217\267\347\252\227\344\275\223\346\230\276\347\244\272", nullptr));
        comboScreenNum->setItemText(5, QCoreApplication::translate("frmImageViewClass", "5\345\217\267\347\252\227\344\275\223\346\230\276\347\244\272", nullptr));
        comboScreenNum->setItemText(6, QCoreApplication::translate("frmImageViewClass", "6\345\217\267\347\252\227\344\275\223\346\230\276\347\244\272", nullptr));
        comboScreenNum->setItemText(7, QCoreApplication::translate("frmImageViewClass", "7\345\217\267\347\252\227\344\275\223\346\230\276\347\244\272", nullptr));
        comboScreenNum->setItemText(8, QCoreApplication::translate("frmImageViewClass", "8\345\217\267\347\252\227\344\275\223\346\230\276\347\244\272", nullptr));
        comboScreenNum->setItemText(9, QCoreApplication::translate("frmImageViewClass", "9\345\217\267\347\252\227\344\275\223\346\230\276\347\244\272", nullptr));

        label_5->setText(QCoreApplication::translate("frmImageViewClass", "\347\252\227\344\275\223\347\274\226\345\217\267\357\274\232", nullptr));
        groupC2->setTitle(QCoreApplication::translate("frmImageViewClass", "\350\275\256\345\273\223\345\257\271\350\261\241", nullptr));
        label_7->setText(QCoreApplication::translate("frmImageViewClass", "\345\257\271\350\261\241\351\242\234\350\211\262\357\274\232", nullptr));
        label_8->setText(QCoreApplication::translate("frmImageViewClass", "\350\275\256\345\273\223\345\256\275\345\272\246\357\274\232", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetContour->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmImageViewClass", "\350\275\256\345\273\223\351\223\276\346\216\245\345\234\260\345\235\200", nullptr));
        btnAddContour->setText(QCoreApplication::translate("frmImageViewClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteContour->setText(QCoreApplication::translate("frmImageViewClass", "\345\210\240\351\231\244", nullptr));
        btnColor->setText(QString());
        checkViewContour->setText(QCoreApplication::translate("frmImageViewClass", "\346\230\276\347\244\272\350\275\256\345\273\223\345\257\271\350\261\241", nullptr));
        checkViewContourC->setText(QCoreApplication::translate("frmImageViewClass", "\346\230\276\347\244\272\350\275\256\345\273\223\344\270\255\345\277\203\345\205\211\346\240\207", nullptr));
        label_9->setText(QCoreApplication::translate("frmImageViewClass", "\345\205\211\346\240\207\345\244\247\345\260\217\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmImageViewClass", "\345\233\276\345\203\217\350\256\276\347\275\256", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmImageViewClass", "\346\226\207\346\234\254\345\257\271\350\261\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetText->horizontalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("frmImageViewClass", "\346\226\207\346\234\254\351\223\276\346\216\245\345\234\260\345\235\200", nullptr));
        btnAddText->setText(QCoreApplication::translate("frmImageViewClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteText->setText(QCoreApplication::translate("frmImageViewClass", "\345\210\240\351\231\244", nullptr));
        label_6->setText(QCoreApplication::translate("frmImageViewClass", "\346\226\207\345\255\227\345\244\247\345\260\217\357\274\232", nullptr));
        checkBoldFont->setText(QCoreApplication::translate("frmImageViewClass", "\345\255\227\344\275\223\345\212\240\347\262\227", nullptr));
        checkViewText->setText(QCoreApplication::translate("frmImageViewClass", "\346\230\276\347\244\272\346\226\207\346\234\254\345\257\271\350\261\241", nullptr));
        groupCamera_4->setTitle(QCoreApplication::translate("frmImageViewClass", "\346\230\276\347\244\272\345\206\205\345\256\271\350\256\276\347\275\256", nullptr));
        label_10->setText(QCoreApplication::translate("frmImageViewClass", "\346\230\276\347\244\272\344\275\215\347\275\256\357\274\232", nullptr));
        btnOkColor->setText(QString());
        label_12->setText(QCoreApplication::translate("frmImageViewClass", "\347\212\266\346\200\201\351\223\276\346\216\245\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("frmImageViewClass", "\345\206\205\345\256\271\345\211\215\347\274\200\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("frmImageViewClass", "\346\230\276\347\244\272\345\206\205\345\256\271\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtPos_XY->setToolTip(QCoreApplication::translate("frmImageViewClass", "\345\205\250\345\261\200\345\217\230\351\207\217QPoint\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        txtPos_XY->setText(QString());
        label_16->setText(QCoreApplication::translate("frmImageViewClass", "OK\351\242\234\350\211\262\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("frmImageViewClass", "NG\351\242\234\350\211\262\357\274\232", nullptr));
        btnNgColor->setText(QString());
#if QT_CONFIG(tooltip)
        txtState->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkState->setToolTip(QCoreApplication::translate("frmImageViewClass", "\351\223\276\346\216\245\347\212\266\346\200\201", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkState->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkState->setToolTip(QCoreApplication::translate("frmImageViewClass", "\345\210\240\351\231\244\347\212\266\346\200\201\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkState->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkContent->setToolTip(QCoreApplication::translate("frmImageViewClass", "\351\223\276\346\216\245\345\206\205\345\256\271", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkContent->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkContent->setToolTip(QCoreApplication::translate("frmImageViewClass", "\345\210\240\351\231\244\345\206\205\345\256\271\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkContent->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkPos_XY->setToolTip(QCoreApplication::translate("frmImageViewClass", "\351\223\276\346\216\245\346\230\276\347\244\272\344\275\215\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkPos_XY->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkPos_XY->setToolTip(QCoreApplication::translate("frmImageViewClass", "\345\210\240\351\231\244\346\230\276\347\244\272\344\275\215\347\275\256\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkPos_XY->setText(QString());
        btnBack->setText(QCoreApplication::translate("frmImageViewClass", "\344\270\212\344\270\200\351\241\265", nullptr));
        label->setText(QString());
        btnSave->setText(QCoreApplication::translate("frmImageViewClass", "\345\217\202\346\225\260\344\277\235\345\255\230", nullptr));
        label_18->setText(QCoreApplication::translate("frmImageViewClass", "OK\346\226\207\346\234\254\357\274\232", nullptr));
        label_19->setText(QCoreApplication::translate("frmImageViewClass", "NG\346\226\207\346\234\254\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmImageViewClass", "\346\226\207\346\234\254\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmImageViewClass: public Ui_frmImageViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMIMAGEVIEW_H
