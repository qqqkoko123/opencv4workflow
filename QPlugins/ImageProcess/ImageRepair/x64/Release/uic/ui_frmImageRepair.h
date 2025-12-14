/********************************************************************************
** Form generated from reading UI file 'frmImageRepair.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMIMAGEREPAIR_H
#define UI_FRMIMAGEREPAIR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmImageRepairClass
{
public:
    QGridLayout *gridLayout;
    QGridLayout *imageLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera_8;
    QSpinBox *spinMaxThreshold;
    QLabel *label_8;
    QSpinBox *spinMinThreshold;
    QLabel *label_7;
    QLabel *label_10;
    QDoubleSpinBox *spinRadius;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmImageRepairClass)
    {
        if (frmImageRepairClass->objectName().isEmpty())
            frmImageRepairClass->setObjectName(QString::fromUtf8("frmImageRepairClass"));
        frmImageRepairClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmImageRepairClass->sizePolicy().hasHeightForWidth());
        frmImageRepairClass->setSizePolicy(sizePolicy);
        frmImageRepairClass->setMinimumSize(QSize(1160, 655));
        frmImageRepairClass->setMaximumSize(QSize(1160, 655));
        frmImageRepairClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmImageRepairClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        imageLayout = new QGridLayout();
        imageLayout->setSpacing(1);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));

        gridLayout->addLayout(imageLayout, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        tabWidget = new QTabWidget(frmImageRepairClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
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
        groupCamera_8 = new QGroupBox(tab);
        groupCamera_8->setObjectName(QString::fromUtf8("groupCamera_8"));
        groupCamera_8->setGeometry(QRect(9, 108, 427, 73));
        groupCamera_8->setFont(font);
        groupCamera_8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        spinMaxThreshold = new QSpinBox(groupCamera_8);
        spinMaxThreshold->setObjectName(QString::fromUtf8("spinMaxThreshold"));
        spinMaxThreshold->setGeometry(QRect(230, 38, 60, 27));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        spinMaxThreshold->setFont(font1);
        spinMaxThreshold->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxThreshold->setAlignment(Qt::AlignCenter);
        spinMaxThreshold->setMinimum(1);
        spinMaxThreshold->setMaximum(255);
        spinMaxThreshold->setValue(100);
        label_8 = new QLabel(groupCamera_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(160, 42, 73, 19));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setWeight(50);
        label_8->setFont(font2);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinThreshold = new QSpinBox(groupCamera_8);
        spinMinThreshold->setObjectName(QString::fromUtf8("spinMinThreshold"));
        spinMinThreshold->setGeometry(QRect(83, 38, 60, 27));
        spinMinThreshold->setFont(font1);
        spinMinThreshold->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinThreshold->setAlignment(Qt::AlignCenter);
        spinMinThreshold->setMinimum(0);
        spinMinThreshold->setMaximum(254);
        spinMinThreshold->setValue(0);
        label_7 = new QLabel(groupCamera_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(13, 42, 69, 19));
        label_7->setFont(font2);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_10 = new QLabel(groupCamera_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(304, 42, 41, 19));
        label_10->setFont(font2);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinRadius = new QDoubleSpinBox(groupCamera_8);
        spinRadius->setObjectName(QString::fromUtf8("spinRadius"));
        spinRadius->setGeometry(QRect(344, 38, 72, 27));
        sizePolicy.setHeightForWidth(spinRadius->sizePolicy().hasHeightForWidth());
        spinRadius->setSizePolicy(sizePolicy);
        spinRadius->setMinimumSize(QSize(72, 25));
        spinRadius->setFont(font1);
        spinRadius->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
"QDoubleSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QDoubleSpinBox::up-arrow{\n"
"    image:url(:/resource/up.png);\n"
"}\n"
"QDoubleSpinBox::down-arrow{\n"
"    image:url(:/resource/down.png);\n"
"}"));
        spinRadius->setAlignment(Qt::AlignCenter);
        spinRadius->setDecimals(1);
        spinRadius->setMinimum(0.100000000000000);
        spinRadius->setMaximum(999.899999999999977);
        spinRadius->setSingleStep(1.000000000000000);
        spinRadius->setValue(10.000000000000000);
        label_8->raise();
        label_7->raise();
        spinMaxThreshold->raise();
        spinMinThreshold->raise();
        label_10->raise();
        spinRadius->raise();
        groupCamera = new QGroupBox(tab);
        groupCamera->setObjectName(QString::fromUtf8("groupCamera"));
        groupCamera->setGeometry(QRect(9, 18, 427, 73));
        groupCamera->setFont(font);
        groupCamera->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_4 = new QLabel(groupCamera);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 42, 79, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLinkImage = new QLineEdit(groupCamera);
        txtLinkImage->setObjectName(QString::fromUtf8("txtLinkImage"));
        txtLinkImage->setGeometry(QRect(100, 39, 255, 27));
        txtLinkImage->setFont(font);
        txtLinkImage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkImage->setAlignment(Qt::AlignCenter);
        txtLinkImage->setReadOnly(true);
        btnLinkImage = new QPushButton(groupCamera);
        btnLinkImage->setObjectName(QString::fromUtf8("btnLinkImage"));
        btnLinkImage->setGeometry(QRect(360, 39, 27, 27));
        btnLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkImage->setIcon(icon);
        btnLinkImage->setIconSize(QSize(27, 27));
        btnDelLinkImage = new QPushButton(groupCamera);
        btnDelLinkImage->setObjectName(QString::fromUtf8("btnDelLinkImage"));
        btnDelLinkImage->setGeometry(QRect(394, 39, 27, 27));
        btnDelLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkImage->setIcon(icon1);
        btnDelLinkImage->setIconSize(QSize(27, 27));
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmImageRepairClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmImageRepairClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmImageRepairClass);
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

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        retranslateUi(frmImageRepairClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmImageRepairClass);
    } // setupUi

    void retranslateUi(QDialog *frmImageRepairClass)
    {
        frmImageRepairClass->setWindowTitle(QCoreApplication::translate("frmImageRepairClass", "\345\233\276\345\203\217\344\277\256\345\244\215", nullptr));
        groupCamera_8->setTitle(QCoreApplication::translate("frmImageRepairClass", "\344\277\256\345\244\215\345\217\202\346\225\260", nullptr));
        label_8->setText(QCoreApplication::translate("frmImageRepairClass", "\346\234\200\345\244\247\351\230\210\345\200\274\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("frmImageRepairClass", "\346\234\200\345\260\217\351\230\210\345\200\274\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("frmImageRepairClass", "\345\215\212\345\276\204\357\274\232", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmImageRepairClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmImageRepairClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmImageRepairClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmImageRepairClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmImageRepairClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmImageRepairClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmImageRepairClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmImageRepairClass: public Ui_frmImageRepairClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMIMAGEREPAIR_H
