/********************************************************************************
** Form generated from reading UI file 'frmPerspectiveTransform.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPERSPECTIVETRANSFORM_H
#define UI_FRMPERSPECTIVETRANSFORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
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

class Ui_frmPerspectiveTransformClass
{
public:
    QGridLayout *gridLayout;
    QGridLayout *imageLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QGroupBox *groupCamera_2;
    QLabel *label_11;
    QLineEdit *txtInPutPos1;
    QPushButton *btnLinkInPutPos1;
    QPushButton *btnDelLinkInPutPos1;
    QLabel *label_10;
    QPushButton *btnDelLinkInPutPos2;
    QLineEdit *txtInPutPos2;
    QPushButton *btnLinkInPutPos2;
    QPushButton *btnLinkInPutPos4;
    QPushButton *btnDelLinkInPutPos4;
    QLabel *label_13;
    QPushButton *btnDelLinkInPutPos3;
    QLabel *label_12;
    QLineEdit *txtInPutPos3;
    QLineEdit *txtInPutPos4;
    QPushButton *btnLinkInPutPos3;
    QGroupBox *groupCamera_3;
    QLabel *label_14;
    QLineEdit *txtOutPutPos1;
    QPushButton *btnLinkOutPutPos1;
    QPushButton *btnDelLinkOutPutPos1;
    QLabel *label_15;
    QPushButton *btnDelLinkOutPutPos2;
    QLineEdit *txtOutPutPos2;
    QPushButton *btnLinkOutPutPos2;
    QPushButton *btnLinkOutPutPos4;
    QPushButton *btnDelLinkOutPutPos4;
    QLabel *label_16;
    QPushButton *btnDelLinkOutPutPos3;
    QLabel *label_17;
    QLineEdit *txtOutPutPos3;
    QLineEdit *txtOutPutPos4;
    QPushButton *btnLinkOutPutPos3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmPerspectiveTransformClass)
    {
        if (frmPerspectiveTransformClass->objectName().isEmpty())
            frmPerspectiveTransformClass->setObjectName(QString::fromUtf8("frmPerspectiveTransformClass"));
        frmPerspectiveTransformClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmPerspectiveTransformClass->sizePolicy().hasHeightForWidth());
        frmPerspectiveTransformClass->setSizePolicy(sizePolicy);
        frmPerspectiveTransformClass->setMinimumSize(QSize(1160, 655));
        frmPerspectiveTransformClass->setMaximumSize(QSize(1160, 655));
        frmPerspectiveTransformClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmPerspectiveTransformClass);
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

        tabWidget = new QTabWidget(frmPerspectiveTransformClass);
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
        groupCamera_2 = new QGroupBox(tab);
        groupCamera_2->setObjectName(QString::fromUtf8("groupCamera_2"));
        groupCamera_2->setGeometry(QRect(9, 108, 427, 193));
        groupCamera_2->setFont(font);
        groupCamera_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_11 = new QLabel(groupCamera_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(13, 80, 81, 19));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtInPutPos1 = new QLineEdit(groupCamera_2);
        txtInPutPos1->setObjectName(QString::fromUtf8("txtInPutPos1"));
        txtInPutPos1->setGeometry(QRect(100, 34, 255, 27));
        txtInPutPos1->setFont(font);
        txtInPutPos1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,150);"));
        txtInPutPos1->setAlignment(Qt::AlignCenter);
        txtInPutPos1->setReadOnly(true);
        btnLinkInPutPos1 = new QPushButton(groupCamera_2);
        btnLinkInPutPos1->setObjectName(QString::fromUtf8("btnLinkInPutPos1"));
        btnLinkInPutPos1->setGeometry(QRect(360, 34, 27, 27));
        btnLinkInPutPos1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkInPutPos1->setIcon(icon);
        btnLinkInPutPos1->setIconSize(QSize(27, 27));
        btnDelLinkInPutPos1 = new QPushButton(groupCamera_2);
        btnDelLinkInPutPos1->setObjectName(QString::fromUtf8("btnDelLinkInPutPos1"));
        btnDelLinkInPutPos1->setGeometry(QRect(394, 34, 27, 27));
        btnDelLinkInPutPos1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkInPutPos1->setIcon(icon1);
        btnDelLinkInPutPos1->setIconSize(QSize(27, 27));
        label_10 = new QLabel(groupCamera_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(13, 38, 81, 19));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        btnDelLinkInPutPos2 = new QPushButton(groupCamera_2);
        btnDelLinkInPutPos2->setObjectName(QString::fromUtf8("btnDelLinkInPutPos2"));
        btnDelLinkInPutPos2->setGeometry(QRect(394, 76, 27, 27));
        btnDelLinkInPutPos2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkInPutPos2->setIcon(icon1);
        btnDelLinkInPutPos2->setIconSize(QSize(27, 27));
        txtInPutPos2 = new QLineEdit(groupCamera_2);
        txtInPutPos2->setObjectName(QString::fromUtf8("txtInPutPos2"));
        txtInPutPos2->setGeometry(QRect(100, 76, 255, 27));
        txtInPutPos2->setFont(font);
        txtInPutPos2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,150);"));
        txtInPutPos2->setAlignment(Qt::AlignCenter);
        txtInPutPos2->setReadOnly(true);
        btnLinkInPutPos2 = new QPushButton(groupCamera_2);
        btnLinkInPutPos2->setObjectName(QString::fromUtf8("btnLinkInPutPos2"));
        btnLinkInPutPos2->setGeometry(QRect(360, 76, 27, 27));
        btnLinkInPutPos2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkInPutPos2->setIcon(icon);
        btnLinkInPutPos2->setIconSize(QSize(27, 27));
        btnLinkInPutPos4 = new QPushButton(groupCamera_2);
        btnLinkInPutPos4->setObjectName(QString::fromUtf8("btnLinkInPutPos4"));
        btnLinkInPutPos4->setGeometry(QRect(356, 160, 27, 27));
        btnLinkInPutPos4->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkInPutPos4->setIcon(icon);
        btnLinkInPutPos4->setIconSize(QSize(27, 27));
        btnDelLinkInPutPos4 = new QPushButton(groupCamera_2);
        btnDelLinkInPutPos4->setObjectName(QString::fromUtf8("btnDelLinkInPutPos4"));
        btnDelLinkInPutPos4->setGeometry(QRect(390, 160, 27, 27));
        btnDelLinkInPutPos4->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkInPutPos4->setIcon(icon1);
        btnDelLinkInPutPos4->setIconSize(QSize(27, 27));
        label_13 = new QLabel(groupCamera_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(13, 122, 81, 19));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        btnDelLinkInPutPos3 = new QPushButton(groupCamera_2);
        btnDelLinkInPutPos3->setObjectName(QString::fromUtf8("btnDelLinkInPutPos3"));
        btnDelLinkInPutPos3->setGeometry(QRect(390, 118, 27, 27));
        btnDelLinkInPutPos3->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkInPutPos3->setIcon(icon1);
        btnDelLinkInPutPos3->setIconSize(QSize(27, 27));
        label_12 = new QLabel(groupCamera_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(13, 164, 81, 19));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtInPutPos3 = new QLineEdit(groupCamera_2);
        txtInPutPos3->setObjectName(QString::fromUtf8("txtInPutPos3"));
        txtInPutPos3->setGeometry(QRect(100, 118, 255, 27));
        txtInPutPos3->setFont(font);
        txtInPutPos3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,150);"));
        txtInPutPos3->setAlignment(Qt::AlignCenter);
        txtInPutPos3->setReadOnly(true);
        txtInPutPos4 = new QLineEdit(groupCamera_2);
        txtInPutPos4->setObjectName(QString::fromUtf8("txtInPutPos4"));
        txtInPutPos4->setGeometry(QRect(100, 160, 255, 27));
        txtInPutPos4->setFont(font);
        txtInPutPos4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,150);"));
        txtInPutPos4->setAlignment(Qt::AlignCenter);
        txtInPutPos4->setReadOnly(true);
        btnLinkInPutPos3 = new QPushButton(groupCamera_2);
        btnLinkInPutPos3->setObjectName(QString::fromUtf8("btnLinkInPutPos3"));
        btnLinkInPutPos3->setGeometry(QRect(356, 118, 27, 27));
        btnLinkInPutPos3->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkInPutPos3->setIcon(icon);
        btnLinkInPutPos3->setIconSize(QSize(27, 27));
        groupCamera_3 = new QGroupBox(tab);
        groupCamera_3->setObjectName(QString::fromUtf8("groupCamera_3"));
        groupCamera_3->setGeometry(QRect(9, 318, 427, 193));
        groupCamera_3->setFont(font);
        groupCamera_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        label_14 = new QLabel(groupCamera_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(13, 80, 81, 19));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtOutPutPos1 = new QLineEdit(groupCamera_3);
        txtOutPutPos1->setObjectName(QString::fromUtf8("txtOutPutPos1"));
        txtOutPutPos1->setGeometry(QRect(100, 34, 255, 27));
        txtOutPutPos1->setFont(font);
        txtOutPutPos1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,150);"));
        txtOutPutPos1->setAlignment(Qt::AlignCenter);
        txtOutPutPos1->setReadOnly(true);
        btnLinkOutPutPos1 = new QPushButton(groupCamera_3);
        btnLinkOutPutPos1->setObjectName(QString::fromUtf8("btnLinkOutPutPos1"));
        btnLinkOutPutPos1->setGeometry(QRect(360, 34, 27, 27));
        btnLinkOutPutPos1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkOutPutPos1->setIcon(icon);
        btnLinkOutPutPos1->setIconSize(QSize(27, 27));
        btnDelLinkOutPutPos1 = new QPushButton(groupCamera_3);
        btnDelLinkOutPutPos1->setObjectName(QString::fromUtf8("btnDelLinkOutPutPos1"));
        btnDelLinkOutPutPos1->setGeometry(QRect(394, 34, 27, 27));
        btnDelLinkOutPutPos1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkOutPutPos1->setIcon(icon1);
        btnDelLinkOutPutPos1->setIconSize(QSize(27, 27));
        label_15 = new QLabel(groupCamera_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(13, 38, 81, 19));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        btnDelLinkOutPutPos2 = new QPushButton(groupCamera_3);
        btnDelLinkOutPutPos2->setObjectName(QString::fromUtf8("btnDelLinkOutPutPos2"));
        btnDelLinkOutPutPos2->setGeometry(QRect(394, 76, 27, 27));
        btnDelLinkOutPutPos2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkOutPutPos2->setIcon(icon1);
        btnDelLinkOutPutPos2->setIconSize(QSize(27, 27));
        txtOutPutPos2 = new QLineEdit(groupCamera_3);
        txtOutPutPos2->setObjectName(QString::fromUtf8("txtOutPutPos2"));
        txtOutPutPos2->setGeometry(QRect(100, 76, 255, 27));
        txtOutPutPos2->setFont(font);
        txtOutPutPos2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,150);"));
        txtOutPutPos2->setAlignment(Qt::AlignCenter);
        txtOutPutPos2->setReadOnly(true);
        btnLinkOutPutPos2 = new QPushButton(groupCamera_3);
        btnLinkOutPutPos2->setObjectName(QString::fromUtf8("btnLinkOutPutPos2"));
        btnLinkOutPutPos2->setGeometry(QRect(360, 76, 27, 27));
        btnLinkOutPutPos2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkOutPutPos2->setIcon(icon);
        btnLinkOutPutPos2->setIconSize(QSize(27, 27));
        btnLinkOutPutPos4 = new QPushButton(groupCamera_3);
        btnLinkOutPutPos4->setObjectName(QString::fromUtf8("btnLinkOutPutPos4"));
        btnLinkOutPutPos4->setGeometry(QRect(356, 160, 27, 27));
        btnLinkOutPutPos4->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkOutPutPos4->setIcon(icon);
        btnLinkOutPutPos4->setIconSize(QSize(27, 27));
        btnDelLinkOutPutPos4 = new QPushButton(groupCamera_3);
        btnDelLinkOutPutPos4->setObjectName(QString::fromUtf8("btnDelLinkOutPutPos4"));
        btnDelLinkOutPutPos4->setGeometry(QRect(390, 160, 27, 27));
        btnDelLinkOutPutPos4->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkOutPutPos4->setIcon(icon1);
        btnDelLinkOutPutPos4->setIconSize(QSize(27, 27));
        label_16 = new QLabel(groupCamera_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(13, 122, 81, 19));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        btnDelLinkOutPutPos3 = new QPushButton(groupCamera_3);
        btnDelLinkOutPutPos3->setObjectName(QString::fromUtf8("btnDelLinkOutPutPos3"));
        btnDelLinkOutPutPos3->setGeometry(QRect(390, 118, 27, 27));
        btnDelLinkOutPutPos3->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkOutPutPos3->setIcon(icon1);
        btnDelLinkOutPutPos3->setIconSize(QSize(27, 27));
        label_17 = new QLabel(groupCamera_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(13, 164, 81, 19));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
        txtOutPutPos3 = new QLineEdit(groupCamera_3);
        txtOutPutPos3->setObjectName(QString::fromUtf8("txtOutPutPos3"));
        txtOutPutPos3->setGeometry(QRect(100, 118, 255, 27));
        txtOutPutPos3->setFont(font);
        txtOutPutPos3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,150);"));
        txtOutPutPos3->setAlignment(Qt::AlignCenter);
        txtOutPutPos3->setReadOnly(true);
        txtOutPutPos4 = new QLineEdit(groupCamera_3);
        txtOutPutPos4->setObjectName(QString::fromUtf8("txtOutPutPos4"));
        txtOutPutPos4->setGeometry(QRect(100, 160, 255, 27));
        txtOutPutPos4->setFont(font);
        txtOutPutPos4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(220, 220, 227,150);"));
        txtOutPutPos4->setAlignment(Qt::AlignCenter);
        txtOutPutPos4->setReadOnly(true);
        btnLinkOutPutPos3 = new QPushButton(groupCamera_3);
        btnLinkOutPutPos3->setObjectName(QString::fromUtf8("btnLinkOutPutPos3"));
        btnLinkOutPutPos3->setGeometry(QRect(356, 118, 27, 27));
        btnLinkOutPutPos3->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkOutPutPos3->setIcon(icon);
        btnLinkOutPutPos3->setIconSize(QSize(27, 27));
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

        label_3 = new QLabel(frmPerspectiveTransformClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmPerspectiveTransformClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmPerspectiveTransformClass);
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


        retranslateUi(frmPerspectiveTransformClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmPerspectiveTransformClass);
    } // setupUi

    void retranslateUi(QDialog *frmPerspectiveTransformClass)
    {
        frmPerspectiveTransformClass->setWindowTitle(QCoreApplication::translate("frmPerspectiveTransformClass", "\351\200\217\350\247\206\345\217\230\346\215\242", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupCamera_2->setTitle(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\205\245\347\202\271", nullptr));
        label_11->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\205\245\347\202\2712\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtInPutPos1->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\205\250\345\261\200\345\217\230\351\207\217cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        txtInPutPos1->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkInPutPos1->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\351\223\276\346\216\245\350\276\223\345\205\245\347\202\2711", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkInPutPos1->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkInPutPos1->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\210\240\351\231\244\350\276\223\345\205\245\347\202\2711\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkInPutPos1->setText(QString());
        label_10->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\205\245\347\202\2711\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkInPutPos2->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\210\240\351\231\244\350\276\223\345\205\245\347\202\2712\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkInPutPos2->setText(QString());
#if QT_CONFIG(tooltip)
        txtInPutPos2->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\205\250\345\261\200\345\217\230\351\207\217cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        txtInPutPos2->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkInPutPos2->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\351\223\276\346\216\245\350\276\223\345\205\245\347\202\2712", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkInPutPos2->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkInPutPos4->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\351\223\276\346\216\245\350\276\223\345\205\245\347\202\2714", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkInPutPos4->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkInPutPos4->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\210\240\351\231\244\350\276\223\345\205\245\347\202\2714\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkInPutPos4->setText(QString());
        label_13->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\205\245\347\202\2713\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkInPutPos3->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\210\240\351\231\244\350\276\223\345\205\245\347\202\2713\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkInPutPos3->setText(QString());
        label_12->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\205\245\347\202\2714\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtInPutPos3->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\205\250\345\261\200\345\217\230\351\207\217cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        txtInPutPos3->setText(QString());
#if QT_CONFIG(tooltip)
        txtInPutPos4->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\205\250\345\261\200\345\217\230\351\207\217cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        txtInPutPos4->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkInPutPos3->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\351\223\276\346\216\245\350\276\223\345\205\245\347\202\2713", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkInPutPos3->setText(QString());
        groupCamera_3->setTitle(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\207\272\347\202\271", nullptr));
        label_14->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\207\272\347\202\2712\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtOutPutPos1->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\205\250\345\261\200\345\217\230\351\207\217cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        txtOutPutPos1->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkOutPutPos1->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\351\223\276\346\216\245\350\276\223\345\207\272\347\202\2711", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkOutPutPos1->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkOutPutPos1->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\210\240\351\231\244\350\276\223\345\207\272\347\202\2711\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkOutPutPos1->setText(QString());
        label_15->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\207\272\347\202\2711\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkOutPutPos2->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\210\240\351\231\244\350\276\223\345\207\272\347\202\2712\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkOutPutPos2->setText(QString());
#if QT_CONFIG(tooltip)
        txtOutPutPos2->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\205\250\345\261\200\345\217\230\351\207\217cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        txtOutPutPos2->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkOutPutPos2->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\351\223\276\346\216\245\350\276\223\345\207\272\347\202\2712", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkOutPutPos2->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkOutPutPos4->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\351\223\276\346\216\245\350\276\223\345\207\272\347\202\2714", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkOutPutPos4->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkOutPutPos4->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\210\240\351\231\244\350\276\223\345\207\272\347\202\2714\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkOutPutPos4->setText(QString());
        label_16->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\207\272\347\202\2713\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkOutPutPos3->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\210\240\351\231\244\350\276\223\345\207\272\347\202\2713\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkOutPutPos3->setText(QString());
        label_17->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\350\276\223\345\207\272\347\202\2714\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtOutPutPos3->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\205\250\345\261\200\345\217\230\351\207\217cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        txtOutPutPos3->setText(QString());
#if QT_CONFIG(tooltip)
        txtOutPutPos4->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\205\250\345\261\200\345\217\230\351\207\217cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        txtOutPutPos4->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkOutPutPos3->setToolTip(QCoreApplication::translate("frmPerspectiveTransformClass", "\351\223\276\346\216\245\350\276\223\345\207\272\347\202\2713", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkOutPutPos3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmPerspectiveTransformClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmPerspectiveTransformClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmPerspectiveTransformClass: public Ui_frmPerspectiveTransformClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPERSPECTIVETRANSFORM_H
