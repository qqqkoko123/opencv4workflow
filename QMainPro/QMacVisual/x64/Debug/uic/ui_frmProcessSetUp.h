/********************************************************************************
** Form generated from reading UI file 'frmProcessSetUp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPROCESSSETUP_H
#define UI_FRMPROCESSSETUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmProcessSetUpClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *btnProcessModify;
    QLineEdit *txtProcess;
    QLabel *label_2;
    QLineEdit *txtProject;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnProjectModify;
    QSpacerItem *horizontalSpacer_5;
    QListView *listProcess;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *frmProcessSetUpClass)
    {
        if (frmProcessSetUpClass->objectName().isEmpty())
            frmProcessSetUpClass->setObjectName(QString::fromUtf8("frmProcessSetUpClass"));
        frmProcessSetUpClass->resize(652, 410);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmProcessSetUpClass->sizePolicy().hasHeightForWidth());
        frmProcessSetUpClass->setSizePolicy(sizePolicy);
        frmProcessSetUpClass->setMinimumSize(QSize(650, 410));
        frmProcessSetUpClass->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        frmProcessSetUpClass->setFont(font);
        frmProcessSetUpClass->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QMacVisual/Icon/other_478.ico"), QSize(), QIcon::Normal, QIcon::Off);
        frmProcessSetUpClass->setWindowIcon(icon);
        frmProcessSetUpClass->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        horizontalLayout_2 = new QHBoxLayout(frmProcessSetUpClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 1, 3, 1);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(frmProcessSetUpClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(644, 0));
        frame->setMaximumSize(QSize(644, 16777215));
        frame->setStyleSheet(QString::fromUtf8("#frame{border:2px solid rgba(30,30,200,80)}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(7);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnProcessModify = new QPushButton(frame);
        btnProcessModify->setObjectName(QString::fromUtf8("btnProcessModify"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnProcessModify->sizePolicy().hasHeightForWidth());
        btnProcessModify->setSizePolicy(sizePolicy2);
        btnProcessModify->setMinimumSize(QSize(90, 37));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        btnProcessModify->setFont(font1);
        btnProcessModify->setFocusPolicy(Qt::StrongFocus);
        btnProcessModify->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(163, 206, 207,200);}\n"
"QWidget{ color: rgb(45, 45, 35);}\n"
"QWidget{ border: 2px groove gray;border-radius: 6px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(163, 216, 207,200);}\n"
"QPushButton:pressed{background-color: rgba(163, 226, 207,200);}"));

        gridLayout->addWidget(btnProcessModify, 6, 4, 1, 1);

        txtProcess = new QLineEdit(frame);
        txtProcess->setObjectName(QString::fromUtf8("txtProcess"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(txtProcess->sizePolicy().hasHeightForWidth());
        txtProcess->setSizePolicy(sizePolicy3);
        txtProcess->setMinimumSize(QSize(300, 0));
        txtProcess->setMaximumSize(QSize(16777215, 35));
        txtProcess->setFont(font1);
        txtProcess->setFocusPolicy(Qt::StrongFocus);
        txtProcess->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 235);\n"
"color: rgb(45, 45, 35);\n"
"border: 1px groove gray;border-radius: 2px;padding: 2px 4px;"));

        gridLayout->addWidget(txtProcess, 4, 2, 1, 3);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 35);"));

        gridLayout->addWidget(label_2, 3, 2, 1, 3);

        txtProject = new QLineEdit(frame);
        txtProject->setObjectName(QString::fromUtf8("txtProject"));
        sizePolicy.setHeightForWidth(txtProject->sizePolicy().hasHeightForWidth());
        txtProject->setSizePolicy(sizePolicy);
        txtProject->setMaximumSize(QSize(16777215, 35));
        txtProject->setFont(font1);
        txtProject->setFocusPolicy(Qt::StrongFocus);
        txtProject->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 235);\n"
"color: rgb(45, 45, 35);\n"
"border: 1px groove gray;border-radius: 2px;padding: 2px 4px;"));

        gridLayout->addWidget(txtProject, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 4, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 5, 4, 1, 1);

        btnProjectModify = new QPushButton(frame);
        btnProjectModify->setObjectName(QString::fromUtf8("btnProjectModify"));
        sizePolicy2.setHeightForWidth(btnProjectModify->sizePolicy().hasHeightForWidth());
        btnProjectModify->setSizePolicy(sizePolicy2);
        btnProjectModify->setMinimumSize(QSize(90, 37));
        btnProjectModify->setFont(font1);
        btnProjectModify->setFocusPolicy(Qt::StrongFocus);
        btnProjectModify->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(163, 206, 207,200);}\n"
"QWidget{ color: rgb(45, 45, 35);}\n"
"QWidget{ border: 2px groove gray;border-radius: 6px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(163, 216, 207,200);}\n"
"QPushButton:pressed{background-color: rgba(163, 226, 207,200);}"));

        gridLayout->addWidget(btnProjectModify, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 6, 2, 1, 2);

        listProcess = new QListView(frame);
        listProcess->setObjectName(QString::fromUtf8("listProcess"));
        listProcess->setFont(font2);
        listProcess->setStyleSheet(QString::fromUtf8("QWidget{color: rgba(45, 45, 35, 230);background-color: rgb(225, 225, 235);}\n"
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

        gridLayout->addWidget(listProcess, 2, 0, 6, 2);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(75, 16777215));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 35);"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 2);

        verticalSpacer_5 = new QSpacerItem(20, 2, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        gridLayout_2->addWidget(frame, 1, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_4, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);


        retranslateUi(frmProcessSetUpClass);

        QMetaObject::connectSlotsByName(frmProcessSetUpClass);
    } // setupUi

    void retranslateUi(QWidget *frmProcessSetUpClass)
    {
        frmProcessSetUpClass->setWindowTitle(QCoreApplication::translate("frmProcessSetUpClass", "QMacVisual", nullptr));
        btnProcessModify->setText(QCoreApplication::translate("frmProcessSetUpClass", "\344\277\256\346\224\271", nullptr));
        txtProcess->setText(QString());
        label_2->setText(QCoreApplication::translate("frmProcessSetUpClass", "\351\200\211\344\270\255\347\232\204\346\265\201\347\250\213\345\220\215\347\247\260\357\274\232", nullptr));
        txtProject->setText(QCoreApplication::translate("frmProcessSetUpClass", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        btnProjectModify->setText(QCoreApplication::translate("frmProcessSetUpClass", "\344\277\256\346\224\271", nullptr));
        label->setText(QCoreApplication::translate("frmProcessSetUpClass", "\351\241\271\347\233\256\345\220\215\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmProcessSetUpClass: public Ui_frmProcessSetUpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPROCESSSETUP_H
