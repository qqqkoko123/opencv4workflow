/********************************************************************************
** Form generated from reading UI file 'frmGlobalVariable.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMGLOBALVARIABLE_H
#define UI_FRMGLOBALVARIABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frmGlobalVariableClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QComboBox *comboType;
    QSpacerItem *verticalSpacer_6;
    QPushButton *btnAdd;
    QSpacerItem *verticalSpacer_4;
    QPushButton *btnDelete;
    QSpacerItem *verticalSpacer_5;
    QPushButton *btnMoveUp;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnMoveDown;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *frmGlobalVariableClass)
    {
        if (frmGlobalVariableClass->objectName().isEmpty())
            frmGlobalVariableClass->setObjectName(QString::fromUtf8("frmGlobalVariableClass"));
        frmGlobalVariableClass->resize(970, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmGlobalVariableClass->sizePolicy().hasHeightForWidth());
        frmGlobalVariableClass->setSizePolicy(sizePolicy);
        frmGlobalVariableClass->setMinimumSize(QSize(970, 600));
        frmGlobalVariableClass->setMaximumSize(QSize(970, 600));
        frmGlobalVariableClass->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        verticalLayout_3 = new QVBoxLayout(frmGlobalVariableClass);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 2, 2);
        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(9);
        gridLayout->setVerticalSpacing(7);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(frmGlobalVariableClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(128, 0));
        frame->setStyleSheet(QString::fromUtf8("border: 1px solid gray;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 0, 2, 0);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 127,180);\n"
"border:none;"));

        verticalLayout_4->addWidget(label);

        comboType = new QComboBox(frame);
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
        comboType->setMinimumSize(QSize(94, 27));
        comboType->setFont(font);
        comboType->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 6.1em;\n"
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
"		background:url(:/res/ico/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/res/ico/up.png) center no-repeat;}"));

        verticalLayout_4->addWidget(comboType);

        verticalSpacer_6 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_6);

        btnAdd = new QPushButton(frame);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(90, 37));
        btnAdd->setFont(font);
        btnAdd->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnAdd);

        verticalSpacer_4 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_4);

        btnDelete = new QPushButton(frame);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setMinimumSize(QSize(90, 37));
        btnDelete->setFont(font);
        btnDelete->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));

        verticalLayout_4->addWidget(btnDelete);

        verticalSpacer_5 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_5);

        btnMoveUp = new QPushButton(frame);
        btnMoveUp->setObjectName(QString::fromUtf8("btnMoveUp"));
        btnMoveUp->setMinimumSize(QSize(90, 37));
        btnMoveUp->setFont(font);
        btnMoveUp->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnMoveUp);

        verticalSpacer_3 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_3);

        btnMoveDown = new QPushButton(frame);
        btnMoveDown->setObjectName(QString::fromUtf8("btnMoveDown"));
        btnMoveDown->setMinimumSize(QSize(90, 37));
        btnMoveDown->setFont(font);
        btnMoveDown->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_4->addWidget(btnMoveDown);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_2->addWidget(frame);


        gridLayout->addLayout(verticalLayout_2, 0, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(frmGlobalVariableClass);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
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
"		border-left:1px s"
                        "olid #d7d7d7;}\n"
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
        tableWidget->horizontalHeader()->setDefaultSectionSize(206);

        verticalLayout->addWidget(tableWidget);


        gridLayout->addLayout(verticalLayout, 0, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        retranslateUi(frmGlobalVariableClass);

        QMetaObject::connectSlotsByName(frmGlobalVariableClass);
    } // setupUi

    void retranslateUi(QDialog *frmGlobalVariableClass)
    {
        frmGlobalVariableClass->setWindowTitle(QCoreApplication::translate("frmGlobalVariableClass", "\345\205\250\345\261\200\345\217\230\351\207\217", nullptr));
        label->setText(QCoreApplication::translate("frmGlobalVariableClass", "\347\261\273\345\236\213\357\274\232", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("frmGlobalVariableClass", "Int", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("frmGlobalVariableClass", "Double", nullptr));
        comboType->setItemText(2, QCoreApplication::translate("frmGlobalVariableClass", "QString", nullptr));
        comboType->setItemText(3, QCoreApplication::translate("frmGlobalVariableClass", "Bool", nullptr));
        comboType->setItemText(4, QCoreApplication::translate("frmGlobalVariableClass", "QPoint", nullptr));
        comboType->setItemText(5, QCoreApplication::translate("frmGlobalVariableClass", "QPointF", nullptr));
        comboType->setItemText(6, QCoreApplication::translate("frmGlobalVariableClass", "cv::Point", nullptr));
        comboType->setItemText(7, QCoreApplication::translate("frmGlobalVariableClass", "cv::Point2f", nullptr));
        comboType->setItemText(8, QCoreApplication::translate("frmGlobalVariableClass", "cv::Point3f", nullptr));
        comboType->setItemText(9, QCoreApplication::translate("frmGlobalVariableClass", "cv::Point3d", nullptr));
        comboType->setItemText(10, QCoreApplication::translate("frmGlobalVariableClass", "Float[]", nullptr));
        comboType->setItemText(11, QCoreApplication::translate("frmGlobalVariableClass", "Double[]", nullptr));

        btnAdd->setText(QCoreApplication::translate("frmGlobalVariableClass", "\346\267\273\345\212\240", nullptr));
        btnDelete->setText(QCoreApplication::translate("frmGlobalVariableClass", "\345\210\240\351\231\244", nullptr));
        btnMoveUp->setText(QCoreApplication::translate("frmGlobalVariableClass", "\344\270\212\347\247\273", nullptr));
        btnMoveDown->setText(QCoreApplication::translate("frmGlobalVariableClass", "\344\270\213\347\247\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmGlobalVariableClass", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("frmGlobalVariableClass", "\345\217\230\351\207\217\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("frmGlobalVariableClass", "\345\217\230\351\207\217\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("frmGlobalVariableClass", "\345\244\207\346\263\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmGlobalVariableClass: public Ui_frmGlobalVariableClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMGLOBALVARIABLE_H
