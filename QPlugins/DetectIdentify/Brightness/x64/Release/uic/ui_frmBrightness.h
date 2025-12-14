/********************************************************************************
** Form generated from reading UI file 'frmBrightness.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMBRIGHTNESS_H
#define UI_FRMBRIGHTNESS_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmBrightnessClass
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QGroupBox *groupCamera_6;
    QLabel *label_11;
    QDoubleSpinBox *spinMinBrightness;
    QLabel *label_12;
    QDoubleSpinBox *spinMaxBrightness;
    QGridLayout *imageLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmBrightnessClass)
    {
        if (frmBrightnessClass->objectName().isEmpty())
            frmBrightnessClass->setObjectName(QString::fromUtf8("frmBrightnessClass"));
        frmBrightnessClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmBrightnessClass->sizePolicy().hasHeightForWidth());
        frmBrightnessClass->setSizePolicy(sizePolicy);
        frmBrightnessClass->setMinimumSize(QSize(1160, 655));
        frmBrightnessClass->setMaximumSize(QSize(1160, 655));
        frmBrightnessClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmBrightnessClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(frmBrightnessClass);
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
        groupCamera_6 = new QGroupBox(tab);
        groupCamera_6->setObjectName(QString::fromUtf8("groupCamera_6"));
        groupCamera_6->setGeometry(QRect(9, 108, 427, 73));
        groupCamera_6->setFont(font);
        groupCamera_6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_11 = new QLabel(groupCamera_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(13, 42, 79, 19));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMinBrightness = new QDoubleSpinBox(groupCamera_6);
        spinMinBrightness->setObjectName(QString::fromUtf8("spinMinBrightness"));
        spinMinBrightness->setGeometry(QRect(95, 38, 100, 27));
        sizePolicy.setHeightForWidth(spinMinBrightness->sizePolicy().hasHeightForWidth());
        spinMinBrightness->setSizePolicy(sizePolicy);
        spinMinBrightness->setMinimumSize(QSize(100, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        spinMinBrightness->setFont(font2);
        spinMinBrightness->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMinBrightness->setAlignment(Qt::AlignCenter);
        spinMinBrightness->setDecimals(2);
        spinMinBrightness->setMaximum(999.990000000000009);
        spinMinBrightness->setSingleStep(0.100000000000000);
        spinMinBrightness->setValue(0.700000000000000);
        label_12 = new QLabel(groupCamera_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(236, 42, 79, 19));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinMaxBrightness = new QDoubleSpinBox(groupCamera_6);
        spinMaxBrightness->setObjectName(QString::fromUtf8("spinMaxBrightness"));
        spinMaxBrightness->setGeometry(QRect(318, 38, 100, 27));
        sizePolicy.setHeightForWidth(spinMaxBrightness->sizePolicy().hasHeightForWidth());
        spinMaxBrightness->setSizePolicy(sizePolicy);
        spinMaxBrightness->setMinimumSize(QSize(100, 25));
        spinMaxBrightness->setFont(font2);
        spinMaxBrightness->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinMaxBrightness->setAlignment(Qt::AlignCenter);
        spinMaxBrightness->setDecimals(2);
        spinMaxBrightness->setMinimum(0.010000000000000);
        spinMaxBrightness->setMaximum(1000.000000000000000);
        spinMaxBrightness->setSingleStep(0.100000000000000);
        spinMaxBrightness->setValue(0.950000000000000);
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        imageLayout = new QGridLayout();
        imageLayout->setSpacing(1);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));

        gridLayout->addLayout(imageLayout, 1, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmBrightnessClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmBrightnessClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmBrightnessClass);
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

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        retranslateUi(frmBrightnessClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmBrightnessClass);
    } // setupUi

    void retranslateUi(QDialog *frmBrightnessClass)
    {
        frmBrightnessClass->setWindowTitle(QCoreApplication::translate("frmBrightnessClass", "\344\272\256\345\272\246\346\243\200\346\265\213", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmBrightnessClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmBrightnessClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmBrightnessClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmBrightnessClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupCamera_6->setTitle(QCoreApplication::translate("frmBrightnessClass", "\344\272\256\345\272\246\345\217\202\346\225\260", nullptr));
        label_11->setText(QCoreApplication::translate("frmBrightnessClass", "\346\234\200\345\260\217\344\272\256\345\272\246\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("frmBrightnessClass", "\346\234\200\345\244\247\344\272\256\345\272\246\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmBrightnessClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmBrightnessClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmBrightnessClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmBrightnessClass: public Ui_frmBrightnessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMBRIGHTNESS_H
