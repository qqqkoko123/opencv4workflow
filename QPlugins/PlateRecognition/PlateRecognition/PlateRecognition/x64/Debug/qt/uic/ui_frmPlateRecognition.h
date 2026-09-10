/********************************************************************************
** Form generated from reading UI file 'frmPlateRecognition.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPLATERECOGNITION_H
#define UI_FRMPLATERECOGNITION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmPlateRecognitionClass
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
    QGroupBox *groupModel;
    QLabel *labelDet;
    QLineEdit *txtDetectModel;
    QPushButton *btnDetectModel;
    QLabel *labelRec;
    QLineEdit *txtRecModel;
    QPushButton *btnRecModel;
    QLabel *labelScore;
    QDoubleSpinBox *spinScore;
    QCheckBox *chkGpu;
    QGroupBox *groupC6;
    QTextEdit *txtMsg;
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

    void setupUi(QDialog *frmPlateRecognitionClass)
    {
        if (frmPlateRecognitionClass->objectName().isEmpty())
            frmPlateRecognitionClass->setObjectName(QString::fromUtf8("frmPlateRecognitionClass"));
        frmPlateRecognitionClass->resize(1160, 655);
        frmPlateRecognitionClass->setMinimumSize(QSize(1160, 655));
        frmPlateRecognitionClass->setMaximumSize(QSize(1160, 655));
        frmPlateRecognitionClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmPlateRecognitionClass);
        gridLayout->setSpacing(1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(frmPlateRecognitionClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(450, 550));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        groupC1 = new QGroupBox(tab);
        groupC1->setObjectName(QString::fromUtf8("groupC1"));
        groupC1->setGeometry(QRect(9, 18, 427, 73));
        groupC1->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_4 = new QLabel(groupC1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 42, 79, 19));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);background: transparent;"));
        txtLinkImage = new QLineEdit(groupC1);
        txtLinkImage->setObjectName(QString::fromUtf8("txtLinkImage"));
        txtLinkImage->setGeometry(QRect(100, 39, 255, 27));
        txtLinkImage->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);background-color: rgba(170, 170, 127,50);"));
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
        groupModel = new QGroupBox(tab);
        groupModel->setObjectName(QString::fromUtf8("groupModel"));
        groupModel->setGeometry(QRect(9, 100, 427, 155));
        groupModel->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        labelDet = new QLabel(groupModel);
        labelDet->setObjectName(QString::fromUtf8("labelDet"));
        labelDet->setGeometry(QRect(13, 36, 79, 19));
        labelDet->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);background: transparent;"));
        txtDetectModel = new QLineEdit(groupModel);
        txtDetectModel->setObjectName(QString::fromUtf8("txtDetectModel"));
        txtDetectModel->setGeometry(QRect(92, 32, 263, 27));
        txtDetectModel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);background-color: rgba(170, 170, 127,50);"));
        btnDetectModel = new QPushButton(groupModel);
        btnDetectModel->setObjectName(QString::fromUtf8("btnDetectModel"));
        btnDetectModel->setGeometry(QRect(360, 32, 55, 27));
        labelRec = new QLabel(groupModel);
        labelRec->setObjectName(QString::fromUtf8("labelRec"));
        labelRec->setGeometry(QRect(13, 72, 79, 19));
        labelRec->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);background: transparent;"));
        txtRecModel = new QLineEdit(groupModel);
        txtRecModel->setObjectName(QString::fromUtf8("txtRecModel"));
        txtRecModel->setGeometry(QRect(92, 68, 263, 27));
        txtRecModel->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);background-color: rgba(170, 170, 127,50);"));
        btnRecModel = new QPushButton(groupModel);
        btnRecModel->setObjectName(QString::fromUtf8("btnRecModel"));
        btnRecModel->setGeometry(QRect(360, 68, 55, 27));
        labelScore = new QLabel(groupModel);
        labelScore->setObjectName(QString::fromUtf8("labelScore"));
        labelScore->setGeometry(QRect(13, 112, 79, 19));
        labelScore->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);background: transparent;"));
        spinScore = new QDoubleSpinBox(groupModel);
        spinScore->setObjectName(QString::fromUtf8("spinScore"));
        spinScore->setGeometry(QRect(92, 108, 90, 27));
        spinScore->setDecimals(2);
        spinScore->setMaximum(1.000000000000000);
        spinScore->setSingleStep(0.050000000000000);
        spinScore->setValue(0.250000000000000);
        spinScore->setAlignment(Qt::AlignCenter);
        chkGpu = new QCheckBox(groupModel);
        chkGpu->setObjectName(QString::fromUtf8("chkGpu"));
        chkGpu->setGeometry(QRect(210, 110, 141, 23));
        chkGpu->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);background: transparent;"));
        groupC6 = new QGroupBox(tab);
        groupC6->setObjectName(QString::fromUtf8("groupC6"));
        groupC6->setGeometry(QRect(9, 265, 427, 251));
        groupC6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC6);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(10, 30, 407, 211));
        txtMsg->setStyleSheet(QString::fromUtf8("QTextEdit { background-color: rgba(180, 180, 215,120); color: rgba(20, 20, 20,200); }"));
        txtMsg->setReadOnly(true);
        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmPlateRecognitionClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmPlateRecognitionClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        txtDescribe->setMinimumSize(QSize(357, 30));

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmPlateRecognitionClass);
        btnExecute->setObjectName(QString::fromUtf8("btnExecute"));
        btnExecute->setMinimumSize(QSize(90, 37));
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


        retranslateUi(frmPlateRecognitionClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmPlateRecognitionClass);
    } // setupUi

    void retranslateUi(QDialog *frmPlateRecognitionClass)
    {
        frmPlateRecognitionClass->setWindowTitle(QCoreApplication::translate("frmPlateRecognitionClass", "\350\275\246\347\211\214\350\257\206\345\210\253", nullptr));
        groupC1->setTitle(QCoreApplication::translate("frmPlateRecognitionClass", "\345\233\276\345\203\217\350\276\223\345\205\245", nullptr));
        label_4->setText(QCoreApplication::translate("frmPlateRecognitionClass", "\350\276\223\345\205\245\345\233\276\345\203\217", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmPlateRecognitionClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmPlateRecognitionClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        groupModel->setTitle(QCoreApplication::translate("frmPlateRecognitionClass", "\346\250\241\345\236\213\346\226\207\344\273\266", nullptr));
        labelDet->setText(QCoreApplication::translate("frmPlateRecognitionClass", "\346\243\200\346\265\213\346\250\241\345\236\213\357\274\232", nullptr));
        btnDetectModel->setText(QCoreApplication::translate("frmPlateRecognitionClass", "\346\265\217\350\247\210", nullptr));
        labelRec->setText(QCoreApplication::translate("frmPlateRecognitionClass", "\350\257\206\345\210\253\346\250\241\345\236\213\357\274\232", nullptr));
        btnRecModel->setText(QCoreApplication::translate("frmPlateRecognitionClass", "\346\265\217\350\247\210", nullptr));
        labelScore->setText(QCoreApplication::translate("frmPlateRecognitionClass", "\347\275\256\344\277\241\345\272\246\357\274\232", nullptr));
        chkGpu->setText(QCoreApplication::translate("frmPlateRecognitionClass", "\344\274\230\345\205\210\344\275\277\347\224\250GPU", nullptr));
        groupC6->setTitle(QCoreApplication::translate("frmPlateRecognitionClass", "\350\257\206\345\210\253\347\273\223\346\236\234", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmPlateRecognitionClass", "\345\237\272\346\234\254\345\217\202\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("frmPlateRecognitionClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmPlateRecognitionClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmPlateRecognitionClass: public Ui_frmPlateRecognitionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPLATERECOGNITION_H
