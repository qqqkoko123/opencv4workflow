/********************************************************************************
** Form generated from reading UI file 'frmQRcodeIdentify.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMQRCODEIDENTIFY_H
#define UI_FRMQRCODEIDENTIFY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmQRcodeIdentifyClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupC1;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QGroupBox *groupC_2;
    QLabel *label_5;
    QComboBox *comboMode;
    QPushButton *btnTestImage_2;
    QGroupBox *groupC6;
    QTextEdit *txtMsg;
    QGroupBox *groupC3;
    QGroupBox *groupC4;
    QLabel *label_53;
    QSpinBox *spinBox;
    QLabel *label_54;
    QSpinBox *spinBox_2;
    QPushButton *btnTestImage;
    QLabel *label_8;
    QDoubleSpinBox *spinMulValue;
    QLabel *label_52;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *imageLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmQRcodeIdentifyClass)
    {
        if (frmQRcodeIdentifyClass->objectName().isEmpty())
            frmQRcodeIdentifyClass->setObjectName(QString::fromUtf8("frmQRcodeIdentifyClass"));
        frmQRcodeIdentifyClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmQRcodeIdentifyClass->sizePolicy().hasHeightForWidth());
        frmQRcodeIdentifyClass->setSizePolicy(sizePolicy);
        frmQRcodeIdentifyClass->setMinimumSize(QSize(1160, 655));
        frmQRcodeIdentifyClass->setMaximumSize(QSize(1160, 655));
        frmQRcodeIdentifyClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmQRcodeIdentifyClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frmQRcodeIdentifyClass);
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
        groupC1 = new QGroupBox(tab);
        groupC1->setObjectName(QString::fromUtf8("groupC1"));
        groupC1->setGeometry(QRect(9, 18, 427, 73));
        groupC1->setFont(font);
        groupC1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_4 = new QLabel(groupC1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 42, 79, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLinkImage = new QLineEdit(groupC1);
        txtLinkImage->setObjectName(QString::fromUtf8("txtLinkImage"));
        txtLinkImage->setGeometry(QRect(100, 39, 255, 27));
        txtLinkImage->setFont(font);
        txtLinkImage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkImage->setAlignment(Qt::AlignCenter);
        txtLinkImage->setReadOnly(true);
        btnLinkImage = new QPushButton(groupC1);
        btnLinkImage->setObjectName(QString::fromUtf8("btnLinkImage"));
        btnLinkImage->setGeometry(QRect(360, 39, 27, 27));
        btnLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkImage->setIcon(icon);
        btnLinkImage->setIconSize(QSize(27, 27));
        btnDelLinkImage = new QPushButton(groupC1);
        btnDelLinkImage->setObjectName(QString::fromUtf8("btnDelLinkImage"));
        btnDelLinkImage->setGeometry(QRect(394, 39, 27, 27));
        btnDelLinkImage->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkImage->setIcon(icon1);
        btnDelLinkImage->setIconSize(QSize(27, 27));
        groupC_2 = new QGroupBox(tab);
        groupC_2->setObjectName(QString::fromUtf8("groupC_2"));
        groupC_2->setGeometry(QRect(9, 106, 427, 71));
        groupC_2->setFont(font);
        groupC_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_5 = new QLabel(groupC_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 39, 151, 19));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        comboMode = new QComboBox(groupC_2);
        comboMode->addItem(QString());
        comboMode->addItem(QString());
        comboMode->setObjectName(QString::fromUtf8("comboMode"));
        comboMode->setGeometry(QRect(166, 34, 120, 30));
        sizePolicy.setHeightForWidth(comboMode->sizePolicy().hasHeightForWidth());
        comboMode->setSizePolicy(sizePolicy);
        comboMode->setMinimumSize(QSize(120, 30));
        comboMode->setMaximumSize(QSize(188, 16777215));
        comboMode->setFont(font);
        comboMode->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 2px;    \n"
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
        comboMode->setEditable(false);
        btnTestImage_2 = new QPushButton(groupC_2);
        btnTestImage_2->setObjectName(QString::fromUtf8("btnTestImage_2"));
        btnTestImage_2->setGeometry(QRect(330, 30, 83, 32));
        sizePolicy.setHeightForWidth(btnTestImage_2->sizePolicy().hasHeightForWidth());
        btnTestImage_2->setSizePolicy(sizePolicy);
        btnTestImage_2->setMinimumSize(QSize(60, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        btnTestImage_2->setFont(font1);
        btnTestImage_2->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 87, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 87);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 87);}"));
        groupC6 = new QGroupBox(tab);
        groupC6->setObjectName(QString::fromUtf8("groupC6"));
        groupC6->setGeometry(QRect(9, 365, 427, 152));
        groupC6->setFont(font);
        groupC6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC6);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 419, 117));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        txtMsg->setFont(font2);
        txtMsg->setStyleSheet(QString::fromUtf8("QTextEdit         \n"
"{\n"
"    background-color: rgba(180, 180, 215,120);    \n"
"    gridline-color: rgba(220, 220, 255,255);\n"
"    color: rgba(20, 20, 20,200);\n"
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
"		background:url(:/resource/down.png) center no-repeat;}\n"
"QScrollBar::sub-line:vertical{\n"
"		background:url(:/resource/up.png) center no-repeat;}\n"
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
"		min-height:20px"
                        ";}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/resource/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/resource/left.png) center no-repeat;}"));
        txtMsg->setReadOnly(true);
        groupC3 = new QGroupBox(tab);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(9, 192, 427, 158));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        groupC4 = new QGroupBox(groupC3);
        groupC4->setObjectName(QString::fromUtf8("groupC4"));
        groupC4->setGeometry(QRect(12, 34, 403, 67));
        groupC4->setFont(font);
        groupC4->setStyleSheet(QString::fromUtf8("background-color: #acbbac;\n"
"color: rgb(0, 0, 127);"));
        label_53 = new QLabel(groupC4);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(10, 30, 83, 19));
        label_53->setFont(font);
        label_53->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinBox = new QSpinBox(groupC4);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(110, 21, 81, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        spinBox->setFont(font3);
        spinBox->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinBox->setMaximum(9999999);
        spinBox->setValue(100);
        label_54 = new QLabel(groupC4);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(210, 30, 83, 19));
        label_54->setFont(font);
        label_54->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinBox_2 = new QSpinBox(groupC4);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(290, 20, 81, 31));
        spinBox_2->setFont(font3);
        spinBox_2->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinBox_2->setMaximum(9999999);
        spinBox_2->setValue(100);
        btnTestImage = new QPushButton(groupC3);
        btnTestImage->setObjectName(QString::fromUtf8("btnTestImage"));
        btnTestImage->setGeometry(QRect(334, 120, 83, 32));
        sizePolicy.setHeightForWidth(btnTestImage->sizePolicy().hasHeightForWidth());
        btnTestImage->setSizePolicy(sizePolicy);
        btnTestImage->setMinimumSize(QSize(60, 30));
        btnTestImage->setFont(font1);
        btnTestImage->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 87, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 87);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 87);}"));
        label_8 = new QLabel(groupC3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(285, 118, 43, 35));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(12);
        label_8->setFont(font4);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/resource/a_right.png")));
        label_8->setScaledContents(true);
        spinMulValue = new QDoubleSpinBox(groupC3);
        spinMulValue->setObjectName(QString::fromUtf8("spinMulValue"));
        spinMulValue->setGeometry(QRect(120, 120, 85, 27));
        spinMulValue->setFont(font3);
        spinMulValue->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
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
        spinMulValue->setAlignment(Qt::AlignCenter);
        spinMulValue->setDecimals(3);
        spinMulValue->setMaximum(21.000000000000000);
        spinMulValue->setSingleStep(0.010000000000000);
        spinMulValue->setValue(0.003000000000000);
        label_52 = new QLabel(groupC3);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(20, 120, 83, 19));
        label_52->setFont(font);
        label_52->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmQRcodeIdentifyClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmQRcodeIdentifyClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmQRcodeIdentifyClass);
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

        imageLayout = new QGridLayout();
        imageLayout->setSpacing(1);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));

        gridLayout->addLayout(imageLayout, 1, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        retranslateUi(frmQRcodeIdentifyClass);

        tabWidget->setCurrentIndex(0);
        comboMode->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmQRcodeIdentifyClass);
    } // setupUi

    void retranslateUi(QDialog *frmQRcodeIdentifyClass)
    {
        frmQRcodeIdentifyClass->setWindowTitle(QCoreApplication::translate("frmQRcodeIdentifyClass", "\344\272\214\347\273\264\347\240\201\350\257\206\345\210\253", nullptr));
        groupC1->setTitle(QCoreApplication::translate("frmQRcodeIdentifyClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmQRcodeIdentifyClass", "\350\276\223\345\205\245\346\226\207\346\234\254\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmQRcodeIdentifyClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmQRcodeIdentifyClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupC_2->setTitle(QCoreApplication::translate("frmQRcodeIdentifyClass", "\344\272\214\347\273\264\347\240\201\347\261\273\345\236\213", nullptr));
        label_5->setText(QCoreApplication::translate("frmQRcodeIdentifyClass", "\346\224\257\346\214\201\347\232\204\344\272\214\347\273\264\347\240\201\347\261\273\345\236\213\357\274\232", nullptr));
        comboMode->setItemText(0, QCoreApplication::translate("frmQRcodeIdentifyClass", "QRCode", nullptr));
        comboMode->setItemText(1, QCoreApplication::translate("frmQRcodeIdentifyClass", "DM", nullptr));

        comboMode->setCurrentText(QCoreApplication::translate("frmQRcodeIdentifyClass", "QRCode", nullptr));
        btnTestImage_2->setText(QCoreApplication::translate("frmQRcodeIdentifyClass", "\347\224\237\346\210\220\345\233\276\345\203\217", nullptr));
        groupC6->setTitle(QCoreApplication::translate("frmQRcodeIdentifyClass", "\344\272\214\347\273\264\347\240\201\345\206\205\345\256\271", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmQRcodeIdentifyClass", "\344\272\214\347\273\264\347\240\201\345\217\202\346\225\260", nullptr));
        groupC4->setTitle(QCoreApplication::translate("frmQRcodeIdentifyClass", "\345\233\276\345\203\217\347\233\270\344\271\230\345\217\202\346\225\260", nullptr));
        label_53->setText(QCoreApplication::translate("frmQRcodeIdentifyClass", "\345\233\276\345\203\217\345\256\275\345\272\246\357\274\232", nullptr));
        label_54->setText(QCoreApplication::translate("frmQRcodeIdentifyClass", "\345\233\276\345\203\217\351\253\230\345\272\246\357\274\232", nullptr));
        btnTestImage->setText(QCoreApplication::translate("frmQRcodeIdentifyClass", "\346\265\213\350\257\225\345\233\276\345\203\217", nullptr));
        label_8->setText(QString());
        label_52->setText(QCoreApplication::translate("frmQRcodeIdentifyClass", "\347\233\270\344\271\230\347\263\273\346\225\260\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmQRcodeIdentifyClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmQRcodeIdentifyClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmQRcodeIdentifyClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmQRcodeIdentifyClass: public Ui_frmQRcodeIdentifyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMQRCODEIDENTIFY_H
