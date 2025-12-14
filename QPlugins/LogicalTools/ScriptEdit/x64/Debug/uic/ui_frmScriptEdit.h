/********************************************************************************
** Form generated from reading UI file 'frmScriptEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSCRIPTEDIT_H
#define UI_FRMSCRIPTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "codeeditor.h"

QT_BEGIN_NAMESPACE

class Ui_frmScriptEditClass
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QFrame *ToolTreeFrame;
    QGroupBox *groupBox;
    QPlainTextEdit *plainTextExample;
    CodeEditor *plainTextEdit;
    QListView *listProcess;
    QGroupBox *groupC3;
    QTextEdit *txtMsg;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnCompile;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *frmScriptEditClass)
    {
        if (frmScriptEditClass->objectName().isEmpty())
            frmScriptEditClass->setObjectName(QString::fromUtf8("frmScriptEditClass"));
        frmScriptEditClass->resize(1366, 768);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmScriptEditClass->sizePolicy().hasHeightForWidth());
        frmScriptEditClass->setSizePolicy(sizePolicy);
        frmScriptEditClass->setMinimumSize(QSize(1366, 768));
        frmScriptEditClass->setMaximumSize(QSize(1366, 768));
        frmScriptEditClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmScriptEditClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(frmScriptEditClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
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
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(3, 5, 3, 3);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ToolTreeFrame = new QFrame(tab);
        ToolTreeFrame->setObjectName(QString::fromUtf8("ToolTreeFrame"));
        sizePolicy.setHeightForWidth(ToolTreeFrame->sizePolicy().hasHeightForWidth());
        ToolTreeFrame->setSizePolicy(sizePolicy);
        ToolTreeFrame->setMinimumSize(QSize(360, 218));
        ToolTreeFrame->setMaximumSize(QSize(360, 218));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(11);
        ToolTreeFrame->setFont(font1);
        ToolTreeFrame->setStyleSheet(QString::fromUtf8("QWidget{ \n"
"        background-color: rgb(255, 255, 242);\n"
"}\n"
"QTreeView::item::selected{\n"
"        background-color:#96B5A8;\n"
"} \n"
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
"		min-height:20px;}\n"
"QScrollBar::handle:hori"
                        "zontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/resource/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/resource/left.png) center no-repeat;}"));
        ToolTreeFrame->setFrameShape(QFrame::StyledPanel);
        ToolTreeFrame->setFrameShadow(QFrame::Raised);
        ToolTreeFrame->setLineWidth(1);

        verticalLayout->addWidget(ToolTreeFrame);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(360, 223));
        groupBox->setMaximumSize(QSize(360, 223));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        groupBox->setFont(font2);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        plainTextExample = new QPlainTextEdit(groupBox);
        plainTextExample->setObjectName(QString::fromUtf8("plainTextExample"));
        plainTextExample->setGeometry(QRect(1, 26, 358, 196));
        sizePolicy.setHeightForWidth(plainTextExample->sizePolicy().hasHeightForWidth());
        plainTextExample->setSizePolicy(sizePolicy);
        plainTextExample->setMinimumSize(QSize(358, 196));
        plainTextExample->setMaximumSize(QSize(358, 196));
        plainTextExample->setFont(font2);
        plainTextExample->setStyleSheet(QString::fromUtf8("QPlainTextEdit {color: rgb(0, 0, 0);}\n"
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
"		min-height:20px;}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/res"
                        "ource/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/resource/left.png) center no-repeat;}"));
        plainTextExample->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextExample->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextExample->setLineWrapMode(QPlainTextEdit::NoWrap);
        plainTextExample->setReadOnly(true);
        plainTextExample->setOverwriteMode(false);
        plainTextExample->setBackgroundVisible(false);

        verticalLayout->addWidget(groupBox);


        gridLayout_2->addLayout(verticalLayout, 0, 2, 1, 1);

        plainTextEdit = new CodeEditor(tab);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        plainTextEdit->setMinimumSize(QSize(986, 450));
        plainTextEdit->setMaximumSize(QSize(986, 450));
        plainTextEdit->setFont(font);
        plainTextEdit->setStyleSheet(QString::fromUtf8(""));
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);

        gridLayout_2->addWidget(plainTextEdit, 0, 0, 1, 2);

        listProcess = new QListView(tab);
        listProcess->setObjectName(QString::fromUtf8("listProcess"));
        sizePolicy.setHeightForWidth(listProcess->sizePolicy().hasHeightForWidth());
        listProcess->setSizePolicy(sizePolicy);
        listProcess->setMinimumSize(QSize(180, 173));
        listProcess->setMaximumSize(QSize(180, 173));
        listProcess->setFont(font2);
        listProcess->setStyleSheet(QString::fromUtf8("QWidget{color: rgba(45, 45, 35, 230);background-color: rgb(245, 245, 245);}\n"
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
"QScrollBar::handle:horizontal{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:ho"
                        "rizontal{\n"
"		background:url(:/res/ico/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/res/ico/left.png) center no-repeat;}"));

        gridLayout_2->addWidget(listProcess, 1, 0, 2, 1);

        groupC3 = new QGroupBox(tab);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        sizePolicy.setHeightForWidth(groupC3->sizePolicy().hasHeightForWidth());
        groupC3->setSizePolicy(sizePolicy);
        groupC3->setMinimumSize(QSize(360, 171));
        groupC3->setMaximumSize(QSize(360, 171));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(9);
        font3.setBold(false);
        font3.setWeight(50);
        groupC3->setFont(font3);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC3);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(1, 26, 358, 144));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
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

        gridLayout_2->addWidget(groupC3, 1, 2, 2, 1);

        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(799, 171));
        tableWidget->setMaximumSize(QSize(799, 171));
        tableWidget->setFont(font4);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: rgba(180, 180, 215,120);   \n"
"    border:none;\n"
"    gridline-color: rgba(220, 220, 255,255);\n"
"    color: rgba(20, 20, 20,200);\n"
"}\n"
"QTableWidget::item::selected\n"
"{   \n"
"    background-color: rgba(180, 180, 215,255); \n"
"}\n"
"QHeaderView::section\n"
"{\n"
"    color: blue;\n"
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
"		paddin"
                        "g-left:2px;\n"
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
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setGridStyle(Qt::DashLine);
        tableWidget->horizontalHeader()->setDefaultSectionSize(199);

        gridLayout_2->addWidget(tableWidget, 1, 1, 2, 1);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

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

        label_3 = new QLabel(frmScriptEditClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmScriptEditClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnCompile = new QPushButton(frmScriptEditClass);
        btnCompile->setObjectName(QString::fromUtf8("btnCompile"));
        btnCompile->setMinimumSize(QSize(90, 37));
        btnCompile->setFont(font);
        btnCompile->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(19, 22, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(19, 22, 77);}\n"
"QPushButton:pressed{background-color: rgb(19, 22, 127);}"));

        horizontalLayout->addWidget(btnCompile);

        horizontalSpacer_3 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnExecute = new QPushButton(frmScriptEditClass);
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


        retranslateUi(frmScriptEditClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmScriptEditClass);
    } // setupUi

    void retranslateUi(QDialog *frmScriptEditClass)
    {
        frmScriptEditClass->setWindowTitle(QCoreApplication::translate("frmScriptEditClass", "\350\204\232\346\234\254\347\274\226\350\276\221", nullptr));
        groupBox->setTitle(QCoreApplication::translate("frmScriptEditClass", "\350\204\232\346\234\254\347\244\272\344\276\213", nullptr));
        plainTextExample->setPlainText(QCoreApplication::translate("frmScriptEditClass", "//\347\244\272\344\276\2131\n"
"var state = true;\n"
"if (state == true)\n"
"{\n"
"    ProjectSetGlobalValue(\"\345\217\230\351\207\217\345\220\215\", \"\345\200\274\");\n"
"}\n"
"\n"
"//\347\244\272\344\276\2132\n"
"for (var i=0;i<3;i++)\n"
"{\n"
"    LogInfo(GetCurrentTime());\n"
"}\n"
"\n"
"//\347\244\272\344\276\2133\357\274\210\346\225\260\347\273\204\347\261\273\345\236\213\357\274\211\n"
"var array= ProjectGetGlobalValue(\"\345\217\230\351\207\217\345\220\215\");\n"
"var count = GetArraySize(array);\n"
"for (var i=0;i<count;i++)\n"
"{\n"
"    LogInfo(ConvertToArrayFloat(array, i));\n"
"}\n"
"\n"
"//\347\244\272\344\276\2134\357\274\210QPoint\346\210\226cv::Point\347\261\273\345\236\213\357\274\211\n"
"var p = ProjectGetGlobalValue(\"\345\217\230\351\207\217\345\220\215\");\n"
"var p_x = ConvertToPoint(p, \"x\");\n"
"var p_y = ConvertToPoint(p, \"y\");\n"
"\n"
"//\347\244\272\344\276\2135\357\274\210QPointF\346\210\226cv::Point2f\347\261\273\345\236\213\357\274\211\n"
"var p2f = ProjectGetGlobalValue(\"\345"
                        "\217\230\351\207\217\345\220\215\");\n"
"var p2f_x = ConvertToPoint2f(p2f, \"x\");\n"
"var p2f_y = ConvertToPoint2f(p2f, \"y\");\n"
"\n"
"//\347\244\272\344\276\2136\357\274\210cv::Point3f\347\261\273\345\236\213\357\274\211\n"
"var p3f = ProjectGetGlobalValue(\"\345\217\230\351\207\217\345\220\215\");\n"
"var p3f_x = ConvertToPoint3f(p3f, \"x\");\n"
"var p3f_y = ConvertToPoint3f(p3f, \"y\");\n"
"var p3f_z = ConvertToPoint3f(p3f, \"z\");\n"
"\n"
"//\347\244\272\344\276\2137\357\274\210cv::Point3d\347\261\273\345\236\213\357\274\211\n"
"var p3d = ProjectGetGlobalValue(\"\345\217\230\351\207\217\345\220\215\");\n"
"var p3d_x = ConvertToPoint3d(p3d, \"x\");\n"
"var p3d_y = ConvertToPoint3d(p3d, \"y\");\n"
"var p3d_z = ConvertToPoint3d(p3d, \"z\");\n"
"\n"
"//\347\244\272\344\276\2138\357\274\210Float[]\347\261\273\345\236\213\357\274\211\n"
"var array_float = ProjectGetGlobalValue(\"\345\217\230\351\207\217\345\220\215\");\n"
"var f_element = ConvertToArrayFloat(array_float, 0);  //0\350\241\250\347\244\272\350\216"
                        "\267\345\217\226\346\225\260\347\273\204\347\264\242\345\274\2250\344\275\215\347\275\256\347\232\204\345\200\274\n"
"\n"
"//\347\244\272\344\276\2139\357\274\210Double[]\346\210\226vector<Double>\347\261\273\345\236\213\357\274\211\n"
"var array_double = ProjectGetGlobalValue(\"\345\217\230\351\207\217\345\220\215\");\n"
"var d_element = ConvertToArrayDouble(array_double, 0);  //0\350\241\250\347\244\272\350\216\267\345\217\226\346\225\260\347\273\204\347\264\242\345\274\2250\344\275\215\347\275\256\347\232\204\345\200\274\n"
"\n"
"//\347\244\272\344\276\21310\357\274\210vector<QString>\347\261\273\345\236\213\357\274\211\n"
"var code = GetFlowToolValue(\"\346\235\241\345\275\242\347\240\201\350\257\206\345\210\253.\346\235\241\345\275\242\347\240\201\");\n"
"var str = ConvertToArrayQString(code, 0);  //0\350\241\250\347\244\272\350\216\267\345\217\226\346\225\260\347\273\204\347\264\242\345\274\2250\344\275\215\347\275\256\347\232\204\345\200\274\n"
"\n"
"//\347\244\272\344\276\21311\357\274\210vector<cv::Po"
                        "int2f>\347\261\273\345\236\213\357\274\211\n"
"var center_points = GetFlowToolValue(\"\350\275\256\345\273\223\347\211\271\345\276\201\351\200\211\346\213\251.\351\207\215\345\277\203\");\n"
"var p1_x = ConvertToArrayCvPoint2f(center_points,0, \"x\");  //0\350\241\250\347\244\272\350\216\267\345\217\226\346\225\260\347\273\204\347\264\242\345\274\2250\344\275\215\347\275\256\347\232\204\345\200\274\n"
"var p1_y = ConvertToArrayCvPoint2f(center_points,0, \"y\");  //0\350\241\250\347\244\272\350\216\267\345\217\226\346\225\260\347\273\204\347\264\242\345\274\2250\344\275\215\347\275\256\347\232\204\345\200\274\n"
"\n"
"//\347\244\272\344\276\21312\357\274\210QVector<Bool>\347\261\273\345\236\213\357\274\211\n"
"var input = GetFlowToolValue(\"\351\200\232\347\224\250I/O.\350\276\223\345\205\245\347\202\271\");\n"
"var state = ConvertToArrayBool(input, 0);  //0\350\241\250\347\244\272\350\216\267\345\217\226\346\225\260\347\273\204\347\264\242\345\274\2250\344\275\215\347\275\256\347\232\204\345\200\274\n"
"\n"
"/"
                        "/\347\244\272\344\276\21313\357\274\210QVector<int>\347\261\273\345\236\213\357\274\211\n"
"var plc = GetFlowToolValue(\"PLC\351\200\232\344\277\241.\345\257\204\345\255\230\345\231\250\350\257\273\345\217\226\346\225\260\346\215\256\");\n"
"var data = ConvertToArrayInt(plc, 0);  //0\350\241\250\347\244\272\350\216\267\345\217\226\346\225\260\347\273\204\347\264\242\345\274\2250\344\275\215\347\275\256\347\232\204\345\200\274\n"
"", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmScriptEditClass", "\347\274\226\350\257\221\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmScriptEditClass", "\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("frmScriptEditClass", "\345\217\230\351\207\217\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("frmScriptEditClass", "\345\217\230\351\207\217\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("frmScriptEditClass", "\345\217\230\351\207\217\347\261\273\345\236\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmScriptEditClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmScriptEditClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnCompile->setText(QCoreApplication::translate("frmScriptEditClass", "\347\274\226\350\257\221", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmScriptEditClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmScriptEditClass: public Ui_frmScriptEditClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSCRIPTEDIT_H
