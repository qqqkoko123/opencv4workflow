/********************************************************************************
** Form generated from reading UI file 'frmDelayTool.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDELAYTOOL_H
#define UI_FRMDELAYTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frmDelayToolClass
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *radioThread;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *radioTime;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpinBox *spinDelayTime;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmDelayToolClass)
    {
        if (frmDelayToolClass->objectName().isEmpty())
            frmDelayToolClass->setObjectName(QString::fromUtf8("frmDelayToolClass"));
        frmDelayToolClass->resize(500, 270);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmDelayToolClass->sizePolicy().hasHeightForWidth());
        frmDelayToolClass->setSizePolicy(sizePolicy);
        frmDelayToolClass->setMinimumSize(QSize(500, 270));
        frmDelayToolClass->setMaximumSize(QSize(500, 270));
        frmDelayToolClass->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        verticalLayout = new QVBoxLayout(frmDelayToolClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 3);
        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        radioThread = new QRadioButton(frmDelayToolClass);
        radioThread->setObjectName(QString::fromUtf8("radioThread"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        radioThread->setFont(font);
        radioThread->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));

        horizontalLayout_2->addWidget(radioThread);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        radioTime = new QRadioButton(frmDelayToolClass);
        radioTime->setObjectName(QString::fromUtf8("radioTime"));
        radioTime->setFont(font);
        radioTime->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));

        horizontalLayout_2->addWidget(radioTime);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        label = new QLabel(frmDelayToolClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        spinDelayTime = new QSpinBox(frmDelayToolClass);
        spinDelayTime->setObjectName(QString::fromUtf8("spinDelayTime"));
        sizePolicy.setHeightForWidth(spinDelayTime->sizePolicy().hasHeightForWidth());
        spinDelayTime->setSizePolicy(sizePolicy);
        spinDelayTime->setMinimumSize(QSize(130, 0));
        spinDelayTime->setFont(font);
        spinDelayTime->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinDelayTime->setAlignment(Qt::AlignCenter);
        spinDelayTime->setMinimum(1);
        spinDelayTime->setMaximum(100000);
        spinDelayTime->setValue(1);

        horizontalLayout->addWidget(spinDelayTime);

        label_2 = new QLabel(frmDelayToolClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        label_3 = new QLabel(frmDelayToolClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout_4->addWidget(label_3);

        txtDescribe = new QLineEdit(frmDelayToolClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(280, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);
        txtDescribe->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 215, 215);"));

        horizontalLayout_4->addWidget(txtDescribe);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnExecute = new QPushButton(frmDelayToolClass);
        btnExecute->setObjectName(QString::fromUtf8("btnExecute"));
        btnExecute->setMinimumSize(QSize(90, 37));
        btnExecute->setFont(font);
        btnExecute->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 135, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 165, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 165, 127);}"));

        horizontalLayout_4->addWidget(btnExecute);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout->setStretch(1, 6);

        retranslateUi(frmDelayToolClass);

        QMetaObject::connectSlotsByName(frmDelayToolClass);
    } // setupUi

    void retranslateUi(QDialog *frmDelayToolClass)
    {
        frmDelayToolClass->setWindowTitle(QCoreApplication::translate("frmDelayToolClass", "\345\273\266\346\227\266", nullptr));
        radioThread->setText(QCoreApplication::translate("frmDelayToolClass", "\347\272\277\347\250\213\344\274\221\347\234\240\346\227\266\351\227\264", nullptr));
        radioTime->setText(QCoreApplication::translate("frmDelayToolClass", "\345\273\266\346\227\266\346\227\266\351\227\264", nullptr));
        label->setText(QCoreApplication::translate("frmDelayToolClass", "\346\227\266\351\227\264\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("frmDelayToolClass", "ms", nullptr));
        label_3->setText(QCoreApplication::translate("frmDelayToolClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmDelayToolClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmDelayToolClass: public Ui_frmDelayToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDELAYTOOL_H
