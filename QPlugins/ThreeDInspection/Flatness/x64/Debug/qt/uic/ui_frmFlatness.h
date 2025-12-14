/********************************************************************************
** Form generated from reading UI file 'frmFlatness.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMFLATNESS_H
#define UI_FRMFLATNESS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmFlatnessClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkPointsX;
    QPushButton *btnLinkPointsX;
    QPushButton *btnDelLinkPointsX;
    QPushButton *btnLinkPointsY;
    QPushButton *btnDelLinkPointsY;
    QLineEdit *txtLinkPointsY;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *txtLinkPointsZ;
    QPushButton *btnDelLinkPointsZ;
    QPushButton *btnLinkPointsZ;
    QGroupBox *groupCamera_2;
    QLabel *label_7;
    QLineEdit *txtLink3DPoint;
    QPushButton *btnLink3DPoint;
    QPushButton *btnDelLink3DPoint;
    QCheckBox *checkDist;
    QGroupBox *groupC3;
    QTextEdit *txtMsg;

    void setupUi(QDialog *frmFlatnessClass)
    {
        if (frmFlatnessClass->objectName().isEmpty())
            frmFlatnessClass->setObjectName(QString::fromUtf8("frmFlatnessClass"));
        frmFlatnessClass->resize(800, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmFlatnessClass->sizePolicy().hasHeightForWidth());
        frmFlatnessClass->setSizePolicy(sizePolicy);
        frmFlatnessClass->setMinimumSize(QSize(800, 450));
        frmFlatnessClass->setMaximumSize(QSize(800, 500));
        frmFlatnessClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmFlatnessClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmFlatnessClass);
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

        txtDescribe = new QLineEdit(frmFlatnessClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmFlatnessClass);
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

        tabWidget = new QTabWidget(frmFlatnessClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(450, 350));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupCamera = new QGroupBox(tab);
        groupCamera->setObjectName(QString::fromUtf8("groupCamera"));
        groupCamera->setGeometry(QRect(9, 14, 439, 185));
        groupCamera->setFont(font);
        groupCamera->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_4 = new QLabel(groupCamera);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 42, 91, 19));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLinkPointsX = new QLineEdit(groupCamera);
        txtLinkPointsX->setObjectName(QString::fromUtf8("txtLinkPointsX"));
        txtLinkPointsX->setGeometry(QRect(106, 39, 255, 27));
        txtLinkPointsX->setFont(font);
        txtLinkPointsX->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkPointsX->setAlignment(Qt::AlignCenter);
        txtLinkPointsX->setReadOnly(true);
        btnLinkPointsX = new QPushButton(groupCamera);
        btnLinkPointsX->setObjectName(QString::fromUtf8("btnLinkPointsX"));
        btnLinkPointsX->setGeometry(QRect(366, 39, 27, 27));
        btnLinkPointsX->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnLinkPointsX->setIcon(icon);
        btnLinkPointsX->setIconSize(QSize(27, 27));
        btnDelLinkPointsX = new QPushButton(groupCamera);
        btnDelLinkPointsX->setObjectName(QString::fromUtf8("btnDelLinkPointsX"));
        btnDelLinkPointsX->setGeometry(QRect(400, 39, 27, 27));
        btnDelLinkPointsX->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/del_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelLinkPointsX->setIcon(icon1);
        btnDelLinkPointsX->setIconSize(QSize(27, 27));
        btnLinkPointsY = new QPushButton(groupCamera);
        btnLinkPointsY->setObjectName(QString::fromUtf8("btnLinkPointsY"));
        btnLinkPointsY->setGeometry(QRect(366, 92, 27, 27));
        btnLinkPointsY->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkPointsY->setIcon(icon);
        btnLinkPointsY->setIconSize(QSize(27, 27));
        btnDelLinkPointsY = new QPushButton(groupCamera);
        btnDelLinkPointsY->setObjectName(QString::fromUtf8("btnDelLinkPointsY"));
        btnDelLinkPointsY->setGeometry(QRect(400, 92, 27, 27));
        btnDelLinkPointsY->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkPointsY->setIcon(icon1);
        btnDelLinkPointsY->setIconSize(QSize(27, 27));
        txtLinkPointsY = new QLineEdit(groupCamera);
        txtLinkPointsY->setObjectName(QString::fromUtf8("txtLinkPointsY"));
        txtLinkPointsY->setGeometry(QRect(106, 92, 255, 27));
        txtLinkPointsY->setFont(font);
        txtLinkPointsY->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkPointsY->setAlignment(Qt::AlignCenter);
        txtLinkPointsY->setReadOnly(true);
        label_5 = new QLabel(groupCamera);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 95, 91, 19));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_6 = new QLabel(groupCamera);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(13, 151, 91, 19));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLinkPointsZ = new QLineEdit(groupCamera);
        txtLinkPointsZ->setObjectName(QString::fromUtf8("txtLinkPointsZ"));
        txtLinkPointsZ->setGeometry(QRect(106, 148, 255, 27));
        txtLinkPointsZ->setFont(font);
        txtLinkPointsZ->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkPointsZ->setAlignment(Qt::AlignCenter);
        txtLinkPointsZ->setReadOnly(true);
        btnDelLinkPointsZ = new QPushButton(groupCamera);
        btnDelLinkPointsZ->setObjectName(QString::fromUtf8("btnDelLinkPointsZ"));
        btnDelLinkPointsZ->setGeometry(QRect(400, 148, 27, 27));
        btnDelLinkPointsZ->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkPointsZ->setIcon(icon1);
        btnDelLinkPointsZ->setIconSize(QSize(27, 27));
        btnLinkPointsZ = new QPushButton(groupCamera);
        btnLinkPointsZ->setObjectName(QString::fromUtf8("btnLinkPointsZ"));
        btnLinkPointsZ->setGeometry(QRect(366, 148, 27, 27));
        btnLinkPointsZ->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkPointsZ->setIcon(icon);
        btnLinkPointsZ->setIconSize(QSize(27, 27));
        groupCamera_2 = new QGroupBox(tab);
        groupCamera_2->setObjectName(QString::fromUtf8("groupCamera_2"));
        groupCamera_2->setGeometry(QRect(9, 210, 439, 100));
        groupCamera_2->setFont(font);
        groupCamera_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_7 = new QLabel(groupCamera_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(13, 67, 91, 19));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtLink3DPoint = new QLineEdit(groupCamera_2);
        txtLink3DPoint->setObjectName(QString::fromUtf8("txtLink3DPoint"));
        txtLink3DPoint->setGeometry(QRect(106, 64, 255, 27));
        txtLink3DPoint->setFont(font);
        txtLink3DPoint->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLink3DPoint->setAlignment(Qt::AlignCenter);
        txtLink3DPoint->setReadOnly(true);
        btnLink3DPoint = new QPushButton(groupCamera_2);
        btnLink3DPoint->setObjectName(QString::fromUtf8("btnLink3DPoint"));
        btnLink3DPoint->setGeometry(QRect(366, 64, 27, 27));
        btnLink3DPoint->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLink3DPoint->setIcon(icon);
        btnLink3DPoint->setIconSize(QSize(27, 27));
        btnDelLink3DPoint = new QPushButton(groupCamera_2);
        btnDelLink3DPoint->setObjectName(QString::fromUtf8("btnDelLink3DPoint"));
        btnDelLink3DPoint->setGeometry(QRect(400, 64, 27, 27));
        btnDelLink3DPoint->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLink3DPoint->setIcon(icon1);
        btnDelLink3DPoint->setIconSize(QSize(27, 27));
        checkDist = new QCheckBox(groupCamera_2);
        checkDist->setObjectName(QString::fromUtf8("checkDist"));
        checkDist->setGeometry(QRect(13, 28, 169, 27));
        sizePolicy.setHeightForWidth(checkDist->sizePolicy().hasHeightForWidth());
        checkDist->setSizePolicy(sizePolicy);
        checkDist->setFont(font);
        checkDist->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        checkDist->setIconSize(QSize(22, 22));
        groupC3 = new QGroupBox(tab);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(460, 14, 325, 296));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC3);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 317, 259));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        txtMsg->setFont(font1);
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
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 2);


        retranslateUi(frmFlatnessClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmFlatnessClass);
    } // setupUi

    void retranslateUi(QDialog *frmFlatnessClass)
    {
        frmFlatnessClass->setWindowTitle(QCoreApplication::translate("frmFlatnessClass", "\346\213\237\345\220\210\345\271\263\351\235\242/\350\256\241\347\256\227\347\202\271\345\210\260\345\271\263\351\235\242\350\267\235\347\246\273", nullptr));
        label_3->setText(QCoreApplication::translate("frmFlatnessClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmFlatnessClass", "\346\211\247\350\241\214", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmFlatnessClass", "\346\213\237\345\220\210\345\271\263\351\235\242", nullptr));
        label_4->setText(QCoreApplication::translate("frmFlatnessClass", "\350\276\223\345\205\245\347\202\271\351\233\206X\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkPointsX->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\345\205\250\345\261\200\345\217\230\351\207\217double[]\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkPointsX->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\351\223\276\346\216\245\350\276\223\345\205\245\347\202\271\351\233\206X", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkPointsX->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkPointsX->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\345\210\240\351\231\244\350\276\223\345\205\245\347\202\271\351\233\206X\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkPointsX->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkPointsY->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\351\223\276\346\216\245\350\276\223\345\205\245\347\202\271\351\233\206Y", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkPointsY->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkPointsY->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\345\210\240\351\231\244\350\276\223\345\205\245\347\202\271\351\233\206Y\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkPointsY->setText(QString());
#if QT_CONFIG(tooltip)
        txtLinkPointsY->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\345\205\250\345\261\200\345\217\230\351\207\217double[]\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("frmFlatnessClass", "\350\276\223\345\205\245\347\202\271\351\233\206Y\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("frmFlatnessClass", "\350\276\223\345\205\245\347\202\271\351\233\206Z\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkPointsZ->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\345\205\250\345\261\200\345\217\230\351\207\217double[]\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnDelLinkPointsZ->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\345\210\240\351\231\244\350\276\223\345\205\245\347\202\271\351\233\206Z\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkPointsZ->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkPointsZ->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\351\223\276\346\216\245\350\276\223\345\205\245\347\202\271\351\233\206Z", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkPointsZ->setText(QString());
        groupCamera_2->setTitle(QCoreApplication::translate("frmFlatnessClass", "\350\256\241\347\256\227\347\202\271\345\210\260\345\271\263\351\235\242\350\267\235\347\246\273", nullptr));
        label_7->setText(QCoreApplication::translate("frmFlatnessClass", "\344\270\211\347\273\264\350\276\223\345\205\245\347\202\271\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLink3DPoint->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\345\205\250\345\261\200\345\217\230\351\207\217cv::Point3d\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLink3DPoint->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\351\223\276\346\216\245\344\270\211\347\273\264\350\276\223\345\205\245\347\202\271", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLink3DPoint->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLink3DPoint->setToolTip(QCoreApplication::translate("frmFlatnessClass", "\345\210\240\351\231\244\344\270\211\347\273\264\350\276\223\345\205\245\347\202\271\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLink3DPoint->setText(QString());
        checkDist->setText(QCoreApplication::translate("frmFlatnessClass", "\350\256\241\347\256\227\347\202\271\345\210\260\345\271\263\351\235\242\350\267\235\347\246\273", nullptr));
        groupC3->setTitle(QCoreApplication::translate("frmFlatnessClass", "\350\276\223\345\207\272\346\225\260\346\215\256(A\343\200\201B\343\200\201C\343\200\201D\343\200\201Distance)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmFlatnessClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmFlatnessClass: public Ui_frmFlatnessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMFLATNESS_H
