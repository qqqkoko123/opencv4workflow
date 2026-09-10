/********************************************************************************
** Form generated from reading UI file 'frmAbout.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMABOUT_H
#define UI_FRMABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmAboutClass
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_4;

    void setupUi(QWidget *frmAboutClass)
    {
        if (frmAboutClass->objectName().isEmpty())
            frmAboutClass->setObjectName(QString::fromUtf8("frmAboutClass"));
        frmAboutClass->resize(520, 270);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmAboutClass->sizePolicy().hasHeightForWidth());
        frmAboutClass->setSizePolicy(sizePolicy);
        frmAboutClass->setMinimumSize(QSize(520, 270));
        frmAboutClass->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        frmAboutClass->setFont(font);
        frmAboutClass->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QMacVisual/Icon/other_478.ico"), QSize(), QIcon::Normal, QIcon::Off);
        frmAboutClass->setWindowIcon(icon);
        frmAboutClass->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        horizontalLayout = new QHBoxLayout(frmAboutClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(1, 1, 1, 3);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 38, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 1, 1);

        label = new QLabel(frmAboutClass);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Cambria"));
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(178, 178, 178,0);\n"
"color: rgb(0, 102, 0);"));
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 3, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(frmAboutClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(12);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(178, 178, 178,0);"));

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        label_2 = new QLabel(frmAboutClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(178, 178, 178,0);"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        label_5 = new QLabel(frmAboutClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgba(178, 178, 178,0);"));

        gridLayout_2->addWidget(label_5, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 3, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 2, 1, 1);

        label_4 = new QLabel(frmAboutClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMinimumSize(QSize(126, 126));
        label_4->setMaximumSize(QSize(126, 126));
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgba(178, 178, 178,0);"));
        label_4->setFrameShadow(QFrame::Plain);
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/Bitmaps/APP.png")));
        label_4->setScaledContents(true);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 3, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(frmAboutClass);

        QMetaObject::connectSlotsByName(frmAboutClass);
    } // setupUi

    void retranslateUi(QWidget *frmAboutClass)
    {
        frmAboutClass->setWindowTitle(QCoreApplication::translate("frmAboutClass", "QMacVisual", nullptr));
        label->setText(QCoreApplication::translate("frmAboutClass", "MachineVisionSystem", nullptr));
        label_3->setText(QCoreApplication::translate("frmAboutClass", " Copyright(c) MacV All Rights Reserved.", nullptr));
        label_2->setText(QCoreApplication::translate("frmAboutClass", " Main Program Version\357\274\2321.0.0.0", nullptr));
        label_5->setText(QCoreApplication::translate("frmAboutClass", "<html><head/><body><p> Email : 290828340@qq.com</p></body></html>", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frmAboutClass: public Ui_frmAboutClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMABOUT_H
