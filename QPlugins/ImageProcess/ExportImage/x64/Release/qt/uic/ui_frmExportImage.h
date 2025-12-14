/********************************************************************************
** Form generated from reading UI file 'frmExportImage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMEXPORTIMAGE_H
#define UI_FRMEXPORTIMAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmExportImageClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QLabel *label_4;
    QPushButton *btnDelLinkImage;
    QPushButton *btnStoragePath;
    QLabel *label_5;
    QPushButton *btnDelLinkFileName;
    QPushButton *btnLinkFileName;
    QLabel *label_6;
    QLineEdit *txtFileName;
    QCheckBox *checkUseTime;
    QTextEdit *txtStoragePath;
    QWidget *tab_2;
    QLabel *label_8;
    QSpinBox *spinImageTime;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *comboImageFormat;

    void setupUi(QDialog *frmExportImageClass)
    {
        if (frmExportImageClass->objectName().isEmpty())
            frmExportImageClass->setObjectName(QString::fromUtf8("frmExportImageClass"));
        frmExportImageClass->resize(530, 360);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmExportImageClass->sizePolicy().hasHeightForWidth());
        frmExportImageClass->setSizePolicy(sizePolicy);
        frmExportImageClass->setMinimumSize(QSize(530, 360));
        frmExportImageClass->setMaximumSize(QSize(530, 360));
        frmExportImageClass->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        gridLayout = new QGridLayout(frmExportImageClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmExportImageClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmExportImageClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(320, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmExportImageClass);
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

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frmExportImageClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(450, 200));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        txtLinkImage = new QLineEdit(tab);
        txtLinkImage->setObjectName(QString::fromUtf8("txtLinkImage"));
        txtLinkImage->setGeometry(QRect(100, 18, 335, 27));
        txtLinkImage->setFont(font);
        txtLinkImage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkImage->setAlignment(Qt::AlignCenter);
        txtLinkImage->setReadOnly(true);
        btnLinkImage = new QPushButton(tab);
        btnLinkImage->setObjectName(QString::fromUtf8("btnLinkImage"));
        btnLinkImage->setGeometry(QRect(448, 18, 27, 27));
        btnLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkImage->setIcon(icon);
        btnLinkImage->setIconSize(QSize(27, 27));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(18, 21, 79, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        btnDelLinkImage = new QPushButton(tab);
        btnDelLinkImage->setObjectName(QString::fromUtf8("btnDelLinkImage"));
        btnDelLinkImage->setGeometry(QRect(484, 18, 27, 27));
        btnDelLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkImage->setIcon(icon1);
        btnDelLinkImage->setIconSize(QSize(27, 27));
        btnStoragePath = new QPushButton(tab);
        btnStoragePath->setObjectName(QString::fromUtf8("btnStoragePath"));
        btnStoragePath->setGeometry(QRect(448, 78, 32, 32));
        btnStoragePath->setStyleSheet(QString::fromUtf8("QWidget{ border:none;background-color: rgba(0, 0, 0, 0);border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resource/tag.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStoragePath->setIcon(icon2);
        btnStoragePath->setIconSize(QSize(32, 32));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(18, 67, 79, 19));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        btnDelLinkFileName = new QPushButton(tab);
        btnDelLinkFileName->setObjectName(QString::fromUtf8("btnDelLinkFileName"));
        btnDelLinkFileName->setGeometry(QRect(484, 146, 27, 27));
        btnDelLinkFileName->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkFileName->setIcon(icon1);
        btnDelLinkFileName->setIconSize(QSize(27, 27));
        btnLinkFileName = new QPushButton(tab);
        btnLinkFileName->setObjectName(QString::fromUtf8("btnLinkFileName"));
        btnLinkFileName->setGeometry(QRect(448, 146, 27, 27));
        btnLinkFileName->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkFileName->setIcon(icon);
        btnLinkFileName->setIconSize(QSize(27, 27));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(18, 149, 79, 19));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        txtFileName = new QLineEdit(tab);
        txtFileName->setObjectName(QString::fromUtf8("txtFileName"));
        txtFileName->setGeometry(QRect(100, 146, 335, 27));
        txtFileName->setFont(font);
        txtFileName->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtFileName->setAlignment(Qt::AlignCenter);
        txtFileName->setReadOnly(true);
        checkUseTime = new QCheckBox(tab);
        checkUseTime->setObjectName(QString::fromUtf8("checkUseTime"));
        checkUseTime->setGeometry(QRect(99, 192, 197, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        checkUseTime->setFont(font1);
        checkUseTime->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 17px;\n"
"    height: 17px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/resource/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/resource/tick.png);\n"
"};"));
        txtStoragePath = new QTextEdit(tab);
        txtStoragePath->setObjectName(QString::fromUtf8("txtStoragePath"));
        txtStoragePath->setGeometry(QRect(100, 64, 335, 63));
        txtStoragePath->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtStoragePath->setReadOnly(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(38, 79, 123, 19));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgba(0, 0, 0, 0);"));
        spinImageTime = new QSpinBox(tab_2);
        spinImageTime->setObjectName(QString::fromUtf8("spinImageTime"));
        spinImageTime->setGeometry(QRect(163, 75, 66, 27));
        spinImageTime->setFont(font1);
        spinImageTime->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinImageTime->setAlignment(Qt::AlignCenter);
        spinImageTime->setMinimum(1);
        spinImageTime->setMaximum(365);
        spinImageTime->setValue(30);
        label_9 = new QLabel(tab_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(234, 79, 23, 21));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgba(0, 0, 0, 0);"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(38, 20, 83, 30));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border:none;\n"
"background-color: rgba(0, 0, 0, 0);"));
        comboImageFormat = new QComboBox(tab_2);
        comboImageFormat->addItem(QString());
        comboImageFormat->addItem(QString());
        comboImageFormat->addItem(QString());
        comboImageFormat->setObjectName(QString::fromUtf8("comboImageFormat"));
        comboImageFormat->setGeometry(QRect(124, 22, 77, 30));
        sizePolicy.setHeightForWidth(comboImageFormat->sizePolicy().hasHeightForWidth());
        comboImageFormat->setSizePolicy(sizePolicy);
        comboImageFormat->setMinimumSize(QSize(77, 30));
        comboImageFormat->setMaximumSize(QSize(16777215, 16777215));
        comboImageFormat->setFont(font);
        comboImageFormat->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;  \n"
"    min-width: 5em;\n"
"    color: rgb(0, 0, 200);\n"
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
"    image: url(:/resource/down.png);\n"
"} \n"
"QComboBox::down-arrow:on {\n"
"    top: 1px;\n"
"    left: 1px;\n"
"}"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(frmExportImageClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmExportImageClass);
    } // setupUi

    void retranslateUi(QDialog *frmExportImageClass)
    {
        frmExportImageClass->setWindowTitle(QCoreApplication::translate("frmExportImageClass", "\345\257\274\345\207\272\345\233\276\345\203\217", nullptr));
        label_3->setText(QCoreApplication::translate("frmExportImageClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmExportImageClass", "\346\211\247\350\241\214", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmExportImageClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
        label_4->setText(QCoreApplication::translate("frmExportImageClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmExportImageClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnStoragePath->setToolTip(QCoreApplication::translate("frmExportImageClass", "\345\255\230\345\202\250\350\267\257\345\276\204", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStoragePath->setText(QString());
        label_5->setText(QCoreApplication::translate("frmExportImageClass", "\345\255\230\345\202\250\350\267\257\345\276\204\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkFileName->setToolTip(QCoreApplication::translate("frmExportImageClass", "\345\210\240\351\231\244\346\226\207\344\273\266\345\220\215\347\247\260\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkFileName->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkFileName->setToolTip(QCoreApplication::translate("frmExportImageClass", "\351\223\276\346\216\245\346\226\207\344\273\266\345\220\215\347\247\260", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkFileName->setText(QString());
        label_6->setText(QCoreApplication::translate("frmExportImageClass", "\346\226\207\344\273\266\345\220\215\347\247\260\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtFileName->setToolTip(QCoreApplication::translate("frmExportImageClass", "\345\205\250\345\261\200\345\217\230\351\207\217QString\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        checkUseTime->setText(QCoreApplication::translate("frmExportImageClass", "\346\226\207\344\273\266\345\220\215\350\207\252\345\212\250\346\267\273\345\212\240\346\227\266\351\227\264", nullptr));
#if QT_CONFIG(tooltip)
        txtStoragePath->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmExportImageClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        label_8->setText(QCoreApplication::translate("frmExportImageClass", "\345\233\276\345\203\217\344\277\235\345\255\230\345\244\251\346\225\260\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("frmExportImageClass", "\345\244\251", nullptr));
        label_10->setText(QCoreApplication::translate("frmExportImageClass", "\345\233\276\345\203\217\346\240\274\345\274\217\357\274\232", nullptr));
        comboImageFormat->setItemText(0, QCoreApplication::translate("frmExportImageClass", "bmp", nullptr));
        comboImageFormat->setItemText(1, QCoreApplication::translate("frmExportImageClass", "jpg", nullptr));
        comboImageFormat->setItemText(2, QCoreApplication::translate("frmExportImageClass", "png", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmExportImageClass", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmExportImageClass: public Ui_frmExportImageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMEXPORTIMAGE_H
