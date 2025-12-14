/********************************************************************************
** Form generated from reading UI file 'frmExportCsv.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMEXPORTCSV_H
#define UI_FRMEXPORTCSV_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmExportCsvClass
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
    QGroupBox *groupC1;
    QLabel *label_10;
    QComboBox *comboType;
    QComboBox *comboTypeBuf;
    QLineEdit *txtTypeName;
    QPushButton *btnWrite;
    QPushButton *btnStoragePath;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_5;
    QTextEdit *txtStoragePath;
    QSpinBox *spinImageTime;
    QWidget *tab_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetContent;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *btnAddContent;
    QPushButton *btnDeleteContent;
    QPushButton *btnMoveUp;
    QPushButton *btnMoveDown;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *frmExportCsvClass)
    {
        if (frmExportCsvClass->objectName().isEmpty())
            frmExportCsvClass->setObjectName(QString::fromUtf8("frmExportCsvClass"));
        frmExportCsvClass->resize(600, 420);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmExportCsvClass->sizePolicy().hasHeightForWidth());
        frmExportCsvClass->setSizePolicy(sizePolicy);
        frmExportCsvClass->setMinimumSize(QSize(600, 420));
        frmExportCsvClass->setMaximumSize(QSize(600, 420));
        frmExportCsvClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmExportCsvClass);
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

        label_3 = new QLabel(frmExportCsvClass);
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

        txtDescribe = new QLineEdit(frmExportCsvClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(320, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmExportCsvClass);
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

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frmExportCsvClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(450, 200));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupC1 = new QGroupBox(tab);
        groupC1->setObjectName(QString::fromUtf8("groupC1"));
        groupC1->setGeometry(QRect(8, 16, 578, 117));
        groupC1->setFont(font);
        groupC1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_10 = new QLabel(groupC1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(11, 36, 129, 19));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboType = new QComboBox(groupC1);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName(QString::fromUtf8("comboType"));
        comboType->setGeometry(QRect(148, 32, 105, 27));
        comboType->setMinimumSize(QSize(63, 27));
        comboType->setFont(font);
        comboType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 4.1em;\n"
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
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"QScrollBar:vertical{\n"
"		background:#FFFFF2; \n"
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
""
                        "QScrollBar::add-line:vertical{\n"
"		background:url(:/resource/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/resource/up.png) center no-repeat;}"));
        comboTypeBuf = new QComboBox(groupC1);
        comboTypeBuf->setObjectName(QString::fromUtf8("comboTypeBuf"));
        comboTypeBuf->setGeometry(QRect(12, 78, 150, 27));
        comboTypeBuf->setMinimumSize(QSize(63, 27));
        comboTypeBuf->setFont(font);
        comboTypeBuf->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 4.1em;\n"
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
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}\n"
"QScrollBar:vertical{\n"
"		background:#FFFFF2; \n"
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
""
                        "QScrollBar::add-line:vertical{\n"
"		background:url(:/resource/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/resource/up.png) center no-repeat;}"));
        txtTypeName = new QLineEdit(groupC1);
        txtTypeName->setObjectName(QString::fromUtf8("txtTypeName"));
        txtTypeName->setGeometry(QRect(172, 78, 299, 27));
        txtTypeName->setFont(font);
        txtTypeName->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        txtTypeName->setReadOnly(false);
        btnWrite = new QPushButton(groupC1);
        btnWrite->setObjectName(QString::fromUtf8("btnWrite"));
        btnWrite->setGeometry(QRect(490, 75, 76, 33));
        btnWrite->setFont(font);
        btnWrite->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));
        btnStoragePath = new QPushButton(tab);
        btnStoragePath->setObjectName(QString::fromUtf8("btnStoragePath"));
        btnStoragePath->setGeometry(QRect(529, 163, 48, 48));
        btnStoragePath->setStyleSheet(QString::fromUtf8("QWidget{ border:none;background-color: rgba(0, 0, 0, 0);border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/tag.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStoragePath->setIcon(icon);
        btnStoragePath->setIconSize(QSize(48, 48));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(210, 247, 23, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgba(0, 0, 0, 0);"));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(19, 247, 123, 19));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgba(0, 0, 0, 0);"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(19, 150, 79, 19));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        txtStoragePath = new QTextEdit(tab);
        txtStoragePath->setObjectName(QString::fromUtf8("txtStoragePath"));
        txtStoragePath->setGeometry(QRect(101, 150, 411, 77));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(10);
        txtStoragePath->setFont(font2);
        txtStoragePath->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtStoragePath->setReadOnly(true);
        spinImageTime = new QSpinBox(tab);
        spinImageTime->setObjectName(QString::fromUtf8("spinImageTime"));
        spinImageTime->setGeometry(QRect(140, 244, 66, 27));
        spinImageTime->setFont(font1);
        spinImageTime->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinImageTime->setAlignment(Qt::AlignCenter);
        spinImageTime->setMinimum(1);
        spinImageTime->setMaximum(365);
        spinImageTime->setValue(30);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayoutWidget_3 = new QWidget(tab_2);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 16, 573, 257));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(3);
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
        tableWidgetContent = new QTableWidget(frame_3);
        if (tableWidgetContent->columnCount() < 1)
            tableWidgetContent->setColumnCount(1);
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font3);
        tableWidgetContent->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetContent->setObjectName(QString::fromUtf8("tableWidgetContent"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tableWidgetContent->setFont(font4);
        tableWidgetContent->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
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
        tableWidgetContent->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetContent->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetContent->setGridStyle(Qt::DashLine);
        tableWidgetContent->horizontalHeader()->setMinimumSectionSize(29);
        tableWidgetContent->horizontalHeader()->setDefaultSectionSize(501);
        tableWidgetContent->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout_3->addWidget(tableWidgetContent);


        horizontalLayout_3->addWidget(frame_3);

        frame_4 = new QFrame(horizontalLayoutWidget_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);\n"
"background-color: #b7c7a7;"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 2, 1, 1);
        btnAddContent = new QPushButton(frame_4);
        btnAddContent->setObjectName(QString::fromUtf8("btnAddContent"));
        sizePolicy.setHeightForWidth(btnAddContent->sizePolicy().hasHeightForWidth());
        btnAddContent->setSizePolicy(sizePolicy);
        btnAddContent->setMinimumSize(QSize(60, 30));
        btnAddContent->setFont(font3);
        btnAddContent->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnAddContent);

        btnDeleteContent = new QPushButton(frame_4);
        btnDeleteContent->setObjectName(QString::fromUtf8("btnDeleteContent"));
        sizePolicy.setHeightForWidth(btnDeleteContent->sizePolicy().hasHeightForWidth());
        btnDeleteContent->setSizePolicy(sizePolicy);
        btnDeleteContent->setMinimumSize(QSize(60, 30));
        btnDeleteContent->setFont(font3);
        btnDeleteContent->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));

        verticalLayout_4->addWidget(btnDeleteContent);

        btnMoveUp = new QPushButton(frame_4);
        btnMoveUp->setObjectName(QString::fromUtf8("btnMoveUp"));
        sizePolicy.setHeightForWidth(btnMoveUp->sizePolicy().hasHeightForWidth());
        btnMoveUp->setSizePolicy(sizePolicy);
        btnMoveUp->setMinimumSize(QSize(60, 30));
        btnMoveUp->setFont(font4);
        btnMoveUp->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnMoveUp);

        btnMoveDown = new QPushButton(frame_4);
        btnMoveDown->setObjectName(QString::fromUtf8("btnMoveDown"));
        sizePolicy.setHeightForWidth(btnMoveDown->sizePolicy().hasHeightForWidth());
        btnMoveDown->setSizePolicy(sizePolicy);
        btnMoveDown->setMinimumSize(QSize(60, 30));
        btnMoveDown->setFont(font4);
        btnMoveDown->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnMoveDown);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);


        horizontalLayout_3->addWidget(frame_4);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(frmExportCsvClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmExportCsvClass);
    } // setupUi

    void retranslateUi(QDialog *frmExportCsvClass)
    {
        frmExportCsvClass->setWindowTitle(QCoreApplication::translate("frmExportCsvClass", "\345\257\274\345\207\272CSV", nullptr));
        label_3->setText(QCoreApplication::translate("frmExportCsvClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmExportCsvClass", "\346\211\247\350\241\214", nullptr));
        groupC1->setTitle(QCoreApplication::translate("frmExportCsvClass", "\346\226\207\346\234\254\346\240\207\351\242\230\345\217\202\346\225\260", nullptr));
        label_10->setText(QCoreApplication::translate("frmExportCsvClass", "\346\226\207\346\234\254\346\240\207\351\242\230\345\210\227\346\225\260\351\207\217\357\274\232", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("frmExportCsvClass", "2\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("frmExportCsvClass", "3\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(2, QCoreApplication::translate("frmExportCsvClass", "4\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(3, QCoreApplication::translate("frmExportCsvClass", "5\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(4, QCoreApplication::translate("frmExportCsvClass", "6\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(5, QCoreApplication::translate("frmExportCsvClass", "7\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(6, QCoreApplication::translate("frmExportCsvClass", "8\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(7, QCoreApplication::translate("frmExportCsvClass", "9\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(8, QCoreApplication::translate("frmExportCsvClass", "10\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(9, QCoreApplication::translate("frmExportCsvClass", "11\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(10, QCoreApplication::translate("frmExportCsvClass", "12\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(11, QCoreApplication::translate("frmExportCsvClass", "13\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(12, QCoreApplication::translate("frmExportCsvClass", "14\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(13, QCoreApplication::translate("frmExportCsvClass", "15\345\210\227\346\240\207\351\242\230", nullptr));
        comboType->setItemText(14, QCoreApplication::translate("frmExportCsvClass", "16\345\210\227\346\240\207\351\242\230", nullptr));

#if QT_CONFIG(tooltip)
        comboType->setToolTip(QCoreApplication::translate("frmExportCsvClass", "\351\273\230\350\256\244\346\227\266\351\227\264\344\270\272\347\254\2541\345\210\227\357\274\214\346\224\271\345\217\230\345\210\227\346\225\260\351\207\217\345\220\216\351\234\200\350\246\201\351\207\215\346\226\260\347\274\226\350\276\221\346\226\207\346\234\254\346\240\207\351\242\230", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        comboTypeBuf->setToolTip(QCoreApplication::translate("frmExportCsvClass", "\351\273\230\350\256\244\346\227\266\351\227\264\344\270\272\347\254\2541\345\210\227", nullptr));
#endif // QT_CONFIG(tooltip)
        txtTypeName->setText(QString());
        btnWrite->setText(QCoreApplication::translate("frmExportCsvClass", "\345\206\231\345\205\245", nullptr));
#if QT_CONFIG(tooltip)
        btnStoragePath->setToolTip(QCoreApplication::translate("frmExportCsvClass", "\345\255\230\345\202\250\350\267\257\345\276\204", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStoragePath->setText(QString());
        label_9->setText(QCoreApplication::translate("frmExportCsvClass", "\345\244\251", nullptr));
        label_8->setText(QCoreApplication::translate("frmExportCsvClass", "\346\226\207\344\273\266\344\277\235\345\255\230\345\244\251\346\225\260\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("frmExportCsvClass", "\345\255\230\345\202\250\350\267\257\345\276\204\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtStoragePath->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmExportCsvClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetContent->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmExportCsvClass", "\346\226\207\346\234\254\345\220\204\345\210\227\345\206\205\345\256\271", nullptr));
        btnAddContent->setText(QCoreApplication::translate("frmExportCsvClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteContent->setText(QCoreApplication::translate("frmExportCsvClass", "\345\210\240\351\231\244", nullptr));
        btnMoveUp->setText(QCoreApplication::translate("frmExportCsvClass", "\344\270\212\347\247\273", nullptr));
        btnMoveDown->setText(QCoreApplication::translate("frmExportCsvClass", "\344\270\213\347\247\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmExportCsvClass", "\345\206\205\345\256\271\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmExportCsvClass: public Ui_frmExportCsvClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMEXPORTCSV_H
