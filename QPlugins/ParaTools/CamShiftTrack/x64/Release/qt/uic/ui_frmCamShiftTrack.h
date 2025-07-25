/********************************************************************************
** Form generated from reading UI file 'frmCamShiftTrack.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMCAMSHIFTTRACK_H
#define UI_FRMCAMSHIFTTRACK_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
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

class Ui_frmCamShiftTrackClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *imageLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QGroupBox *groupCamera_8;
    QComboBox *comboROIShape;
    QPushButton *btnAddROI;
    QPushButton *btnDeleteROI;
    QCheckBox *checkUseROI;
    QGroupBox *groupCamera_2;
    QSpinBox *spinSMin;
    QLabel *label_5;
    QSpinBox *spinKSize;
    QLabel *label_6;
    QSpinBox *spinLineW;
    QLabel *label_7;

    void setupUi(QDialog *frmCamShiftTrackClass)
    {
        if (frmCamShiftTrackClass->objectName().isEmpty())
            frmCamShiftTrackClass->setObjectName(QString::fromUtf8("frmCamShiftTrackClass"));
        frmCamShiftTrackClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmCamShiftTrackClass->sizePolicy().hasHeightForWidth());
        frmCamShiftTrackClass->setSizePolicy(sizePolicy);
        frmCamShiftTrackClass->setMinimumSize(QSize(1160, 655));
        frmCamShiftTrackClass->setMaximumSize(QSize(1160, 655));
        frmCamShiftTrackClass->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
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
        gridLayout = new QGridLayout(frmCamShiftTrackClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmCamShiftTrackClass);
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

        txtDescribe = new QLineEdit(frmCamShiftTrackClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmCamShiftTrackClass);
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

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        imageLayout = new QGridLayout();
        imageLayout->setSpacing(1);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));

        gridLayout->addLayout(imageLayout, 1, 2, 1, 1);

        tabWidget = new QTabWidget(frmCamShiftTrackClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(450, 550));
        tabWidget->setMaximumSize(QSize(16777215, 16777215));
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
        groupCamera_8 = new QGroupBox(tab);
        groupCamera_8->setObjectName(QString::fromUtf8("groupCamera_8"));
        groupCamera_8->setGeometry(QRect(9, 108, 427, 73));
        groupCamera_8->setFont(font);
        groupCamera_8->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        comboROIShape = new QComboBox(groupCamera_8);
        comboROIShape->addItem(QString());
        comboROIShape->setObjectName(QString::fromUtf8("comboROIShape"));
        comboROIShape->setGeometry(QRect(130, 35, 95, 30));
        comboROIShape->setFont(font);
        comboROIShape->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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
        btnAddROI = new QPushButton(groupCamera_8);
        btnAddROI->setObjectName(QString::fromUtf8("btnAddROI"));
        btnAddROI->setGeometry(QRect(270, 34, 66, 32));
        sizePolicy.setHeightForWidth(btnAddROI->sizePolicy().hasHeightForWidth());
        btnAddROI->setSizePolicy(sizePolicy);
        btnAddROI->setMinimumSize(QSize(60, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        btnAddROI->setFont(font1);
        btnAddROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));
        btnDeleteROI = new QPushButton(groupCamera_8);
        btnDeleteROI->setObjectName(QString::fromUtf8("btnDeleteROI"));
        btnDeleteROI->setGeometry(QRect(350, 34, 66, 32));
        btnDeleteROI->setMinimumSize(QSize(60, 30));
        btnDeleteROI->setFont(font1);
        btnDeleteROI->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));
        checkUseROI = new QCheckBox(groupCamera_8);
        checkUseROI->setObjectName(QString::fromUtf8("checkUseROI"));
        checkUseROI->setEnabled(false);
        checkUseROI->setGeometry(QRect(13, 36, 93, 27));
        sizePolicy.setHeightForWidth(checkUseROI->sizePolicy().hasHeightForWidth());
        checkUseROI->setSizePolicy(sizePolicy);
        checkUseROI->setFont(font);
        checkUseROI->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        checkUseROI->setIconSize(QSize(22, 22));
        checkUseROI->setChecked(true);
        groupCamera_2 = new QGroupBox(tab);
        groupCamera_2->setObjectName(QString::fromUtf8("groupCamera_2"));
        groupCamera_2->setGeometry(QRect(9, 198, 427, 113));
        groupCamera_2->setFont(font);
        groupCamera_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        spinSMin = new QSpinBox(groupCamera_2);
        spinSMin->setObjectName(QString::fromUtf8("spinSMin"));
        spinSMin->setGeometry(QRect(155, 35, 66, 27));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        spinSMin->setFont(font2);
        spinSMin->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinSMin->setAlignment(Qt::AlignCenter);
        spinSMin->setMinimum(0);
        spinSMin->setMaximum(255);
        spinSMin->setValue(30);
        label_5 = new QLabel(groupCamera_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(13, 38, 139, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinKSize = new QSpinBox(groupCamera_2);
        spinKSize->setObjectName(QString::fromUtf8("spinKSize"));
        spinKSize->setGeometry(QRect(155, 78, 66, 27));
        spinKSize->setFont(font2);
        spinKSize->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinKSize->setAlignment(Qt::AlignCenter);
        spinKSize->setMinimum(1);
        spinKSize->setMaximum(101);
        spinKSize->setValue(3);
        label_6 = new QLabel(groupCamera_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(13, 81, 177, 21));
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        spinLineW = new QSpinBox(groupCamera_2);
        spinLineW->setObjectName(QString::fromUtf8("spinLineW"));
        spinLineW->setGeometry(QRect(350, 35, 66, 27));
        spinLineW->setFont(font2);
        spinLineW->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinLineW->setAlignment(Qt::AlignCenter);
        spinLineW->setMinimum(1);
        spinLineW->setMaximum(20);
        spinLineW->setValue(5);
        label_7 = new QLabel(groupCamera_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(268, 38, 79, 21));
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        label_5->raise();
        label_6->raise();
        spinSMin->raise();
        spinKSize->raise();
        spinLineW->raise();
        label_7->raise();
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);


        retranslateUi(frmCamShiftTrackClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmCamShiftTrackClass);
    } // setupUi

    void retranslateUi(QDialog *frmCamShiftTrackClass)
    {
        frmCamShiftTrackClass->setWindowTitle(QCoreApplication::translate("frmCamShiftTrackClass", "\347\233\256\346\240\207\350\267\237\350\270\252", nullptr));
        label_3->setText(QCoreApplication::translate("frmCamShiftTrackClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmCamShiftTrackClass", "\346\211\247\350\241\214", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmCamShiftTrackClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmCamShiftTrackClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkImage->setToolTip(QCoreApplication::translate("frmCamShiftTrackClass", "\344\270\211\351\200\232\351\201\223", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmCamShiftTrackClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmCamShiftTrackClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupCamera_8->setTitle(QCoreApplication::translate("frmCamShiftTrackClass", "ROI\345\257\271\350\261\241", nullptr));
        comboROIShape->setItemText(0, QCoreApplication::translate("frmCamShiftTrackClass", "\347\237\251\345\275\242", nullptr));

        btnAddROI->setText(QCoreApplication::translate("frmCamShiftTrackClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteROI->setText(QCoreApplication::translate("frmCamShiftTrackClass", "\345\210\240\351\231\244", nullptr));
        checkUseROI->setText(QCoreApplication::translate("frmCamShiftTrackClass", "\344\275\277\347\224\250ROI", nullptr));
        groupCamera_2->setTitle(QCoreApplication::translate("frmCamShiftTrackClass", "\347\233\256\346\240\207\350\267\237\350\270\252\345\217\202\346\225\260", nullptr));
        label_5->setText(QCoreApplication::translate("frmCamShiftTrackClass", "S\351\200\232\351\201\223\351\242\234\350\211\262\346\234\200\345\260\217\345\200\274\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("frmCamShiftTrackClass", "\344\270\255\345\200\274\346\273\244\346\263\242\346\240\270\345\244\247\345\260\217\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("frmCamShiftTrackClass", "\346\230\276\347\244\272\347\272\277\345\256\275\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmCamShiftTrackClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmCamShiftTrackClass: public Ui_frmCamShiftTrackClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCAMSHIFTTRACK_H
