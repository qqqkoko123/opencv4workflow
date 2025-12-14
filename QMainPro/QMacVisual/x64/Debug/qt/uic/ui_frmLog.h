/********************************************************************************
** Form generated from reading UI file 'frmLog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLOG_H
#define UI_FRMLOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmLogClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnInfo;
    QToolButton *btnWarn;
    QToolButton *btnError;
    QLabel *label;
    QListView *listView;

    void setupUi(QWidget *frmLogClass)
    {
        if (frmLogClass->objectName().isEmpty())
            frmLogClass->setObjectName(QString::fromUtf8("frmLogClass"));
        frmLogClass->resize(860, 126);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmLogClass->sizePolicy().hasHeightForWidth());
        frmLogClass->setSizePolicy(sizePolicy);
        frmLogClass->setStyleSheet(QString::fromUtf8("QWidget         \n"
"{\n"
"    background-color: rgb(240, 248, 226);\n"
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
"QScrollBar::handle:horizontal{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:hor"
                        "izontal{\n"
"		background:url(:/res/ico/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/res/ico/left.png) center no-repeat;}"));
        verticalLayout = new QVBoxLayout(frmLogClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 3, -1, -1);
        btnInfo = new QToolButton(frmLogClass);
        btnInfo->setObjectName(QString::fromUtf8("btnInfo"));
        btnInfo->setMinimumSize(QSize(90, 32));
        btnInfo->setMaximumSize(QSize(100, 32));
        btnInfo->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/ico/info.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnInfo->setIcon(icon);
        btnInfo->setIconSize(QSize(20, 20));
        btnInfo->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btnInfo);

        btnWarn = new QToolButton(frmLogClass);
        btnWarn->setObjectName(QString::fromUtf8("btnWarn"));
        btnWarn->setMinimumSize(QSize(90, 32));
        btnWarn->setMaximumSize(QSize(100, 32));
        btnWarn->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/ico/warn.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnWarn->setIcon(icon1);
        btnWarn->setIconSize(QSize(20, 20));
        btnWarn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btnWarn);

        btnError = new QToolButton(frmLogClass);
        btnError->setObjectName(QString::fromUtf8("btnError"));
        btnError->setMinimumSize(QSize(90, 32));
        btnError->setMaximumSize(QSize(100, 32));
        btnError->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/ico/error.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnError->setIcon(icon2);
        btnError->setIconSize(QSize(20, 20));
        btnError->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(btnError);

        label = new QLabel(frmLogClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        listView = new QListView(frmLogClass);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(9);
        listView->setFont(font);
        listView->setStyleSheet(QString::fromUtf8(""));
        listView->setBatchSize(100);

        verticalLayout->addWidget(listView);


        retranslateUi(frmLogClass);

        QMetaObject::connectSlotsByName(frmLogClass);
    } // setupUi

    void retranslateUi(QWidget *frmLogClass)
    {
        frmLogClass->setWindowTitle(QCoreApplication::translate("frmLogClass", "Form", nullptr));
        btnInfo->setText(QCoreApplication::translate("frmLogClass", "\346\217\220\347\244\272(0)", nullptr));
        btnWarn->setText(QCoreApplication::translate("frmLogClass", "\350\255\246\345\221\212(0)", nullptr));
        btnError->setText(QCoreApplication::translate("frmLogClass", "\351\224\231\350\257\257(0)", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frmLogClass: public Ui_frmLogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLOG_H
