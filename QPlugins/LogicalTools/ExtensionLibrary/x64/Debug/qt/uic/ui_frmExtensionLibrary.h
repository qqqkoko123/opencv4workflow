/********************************************************************************
** Form generated from reading UI file 'frmExtensionLibrary.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMEXTENSIONLIBRARY_H
#define UI_FRMEXTENSIONLIBRARY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frmExtensionLibraryClass
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QPushButton *btnDelLinkImage;
    QLineEdit *txtLinkImage;
    QLabel *label_4;
    QPushButton *btnLinkImage;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *txtPath;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnPath;
    QPushButton *btnSet;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *txtDescribe;

    void setupUi(QDialog *frmExtensionLibraryClass)
    {
        if (frmExtensionLibraryClass->objectName().isEmpty())
            frmExtensionLibraryClass->setObjectName(QString::fromUtf8("frmExtensionLibraryClass"));
        frmExtensionLibraryClass->resize(560, 320);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmExtensionLibraryClass->sizePolicy().hasHeightForWidth());
        frmExtensionLibraryClass->setSizePolicy(sizePolicy);
        frmExtensionLibraryClass->setMinimumSize(QSize(560, 320));
        frmExtensionLibraryClass->setMaximumSize(QSize(560, 320));
        frmExtensionLibraryClass->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        verticalLayout_4 = new QVBoxLayout(frmExtensionLibraryClass);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(7);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, -1, 2, -1);
        groupBox = new QGroupBox(frmExtensionLibraryClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(500, 63));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);"));
        btnDelLinkImage = new QPushButton(groupBox);
        btnDelLinkImage->setObjectName(QString::fromUtf8("btnDelLinkImage"));
        btnDelLinkImage->setGeometry(QRect(522, 30, 27, 27));
        btnDelLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkImage->setIcon(icon);
        btnDelLinkImage->setIconSize(QSize(27, 27));
        txtLinkImage = new QLineEdit(groupBox);
        txtLinkImage->setObjectName(QString::fromUtf8("txtLinkImage"));
        txtLinkImage->setGeometry(QRect(112, 30, 355, 27));
        txtLinkImage->setFont(font);
        txtLinkImage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkImage->setAlignment(Qt::AlignCenter);
        txtLinkImage->setReadOnly(true);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(28, 33, 79, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        btnLinkImage = new QPushButton(groupBox);
        btnLinkImage->setObjectName(QString::fromUtf8("btnLinkImage"));
        btnLinkImage->setGeometry(QRect(486, 30, 27, 27));
        btnLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkImage->setIcon(icon1);
        btnLinkImage->setIconSize(QSize(27, 27));

        verticalLayout_2->addWidget(groupBox);

        label = new QLabel(frmExtensionLibraryClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(0, 0, 255);"));

        verticalLayout_2->addWidget(label);


        verticalLayout->addLayout(verticalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(7);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(2, -1, 5, -1);
        txtPath = new QTextEdit(frmExtensionLibraryClass);
        txtPath->setObjectName(QString::fromUtf8("txtPath"));
        txtPath->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        txtPath->setReadOnly(true);

        horizontalLayout_4->addWidget(txtPath);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        btnPath = new QPushButton(frmExtensionLibraryClass);
        btnPath->setObjectName(QString::fromUtf8("btnPath"));
        sizePolicy.setHeightForWidth(btnPath->sizePolicy().hasHeightForWidth());
        btnPath->setSizePolicy(sizePolicy);
        btnPath->setMinimumSize(QSize(75, 35));
        btnPath->setFont(font);
        btnPath->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(85, 120, 127);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(85, 150, 127);}\n"
"QPushButton:pressed{background-color: rgb(85, 170, 127);}"));

        verticalLayout_3->addWidget(btnPath);

        btnSet = new QPushButton(frmExtensionLibraryClass);
        btnSet->setObjectName(QString::fromUtf8("btnSet"));
        sizePolicy.setHeightForWidth(btnSet->sizePolicy().hasHeightForWidth());
        btnSet->setSizePolicy(sizePolicy);
        btnSet->setMinimumSize(QSize(75, 35));
        btnSet->setFont(font);
        btnSet->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgb(100, 105, 220);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(100, 125, 220);}\n"
"QPushButton:pressed{background-color: rgb(100, 145, 220);}"));

        verticalLayout_3->addWidget(btnSet);


        horizontalLayout_4->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, -1, 2, 5);
        label_3 = new QLabel(frmExtensionLibraryClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmExtensionLibraryClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy2);
        txtDescribe->setMinimumSize(QSize(368, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(frmExtensionLibraryClass);

        QMetaObject::connectSlotsByName(frmExtensionLibraryClass);
    } // setupUi

    void retranslateUi(QDialog *frmExtensionLibraryClass)
    {
        frmExtensionLibraryClass->setWindowTitle(QCoreApplication::translate("frmExtensionLibraryClass", "\346\211\251\345\261\225\345\272\223", nullptr));
        groupBox->setTitle(QCoreApplication::translate("frmExtensionLibraryClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmExtensionLibraryClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        label_4->setText(QCoreApplication::translate("frmExtensionLibraryClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmExtensionLibraryClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
        label->setText(QCoreApplication::translate("frmExtensionLibraryClass", "\345\212\250\346\200\201\345\272\223\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", nullptr));
        btnPath->setText(QCoreApplication::translate("frmExtensionLibraryClass", "\350\267\257\345\276\204", nullptr));
        btnSet->setText(QCoreApplication::translate("frmExtensionLibraryClass", "\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmExtensionLibraryClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmExtensionLibraryClass: public Ui_frmExtensionLibraryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMEXTENSIONLIBRARY_H
