/********************************************************************************
** Form generated from reading UI file 'frmQuit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMQUIT_H
#define UI_FRMQUIT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmQuitClass
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *frmQuitClass)
    {
        if (frmQuitClass->objectName().isEmpty())
            frmQuitClass->setObjectName(QString::fromUtf8("frmQuitClass"));
        frmQuitClass->resize(480, 75);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmQuitClass->sizePolicy().hasHeightForWidth());
        frmQuitClass->setSizePolicy(sizePolicy);
        frmQuitClass->setMinimumSize(QSize(480, 75));
        frmQuitClass->setMaximumSize(QSize(480, 75));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        frmQuitClass->setFont(font);
        frmQuitClass->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Bitmaps/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        frmQuitClass->setWindowIcon(icon);
        frmQuitClass->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(frmQuitClass);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frmQuitClass);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(20);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel{ border: 0px groove;border-radius: 15px;padding: 2px 4px;color: rgb(255, 255, 255);background-color: rgb(85, 170, 255);}\n"
""));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        retranslateUi(frmQuitClass);

        QMetaObject::connectSlotsByName(frmQuitClass);
    } // setupUi

    void retranslateUi(QWidget *frmQuitClass)
    {
        frmQuitClass->setWindowTitle(QCoreApplication::translate("frmQuitClass", "QMacVisual", nullptr));
        label->setText(QCoreApplication::translate("frmQuitClass", "\346\255\243\345\234\250\344\277\235\345\255\230\347\233\270\345\205\263\346\225\260\346\215\256\357\274\214\350\257\267\347\250\215\345\220\216...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmQuitClass: public Ui_frmQuitClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMQUIT_H
