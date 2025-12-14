/********************************************************************************
** Form generated from reading UI file 'frmLineLineI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLINELINEI_H
#define UI_FRMLINELINEI_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmLineLineIClass
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QLabel *label_4;
    QLineEdit *txtLinkImage;
    QPushButton *btnLinkImage;
    QPushButton *btnDelLinkImage;
    QGroupBox *groupC2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioPoints;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *radioTwoPoint;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFrame *frame_2;
    QPushButton *btnDelLinkLine1b;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *txtLinkLine1k;
    QLineEdit *txtLinkLine1b;
    QPushButton *btnLinkLine1b;
    QPushButton *btnLinkLine1k;
    QPushButton *btnDelLinkLine1k;
    QLabel *label_10;
    QPushButton *btnLinkLine2k;
    QPushButton *btnLinkLine2b;
    QLineEdit *txtLinkLine2b;
    QLineEdit *txtLinkLine2k;
    QLabel *label_11;
    QPushButton *btnDelLinkLine2k;
    QPushButton *btnDelLinkLine2b;
    QWidget *page_2;
    QFrame *frame_3;
    QPushButton *btnDelLinkLine1Point2;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *txtLinkLine1Point1;
    QLineEdit *txtLinkLine1Point2;
    QPushButton *btnLinkLine1Point2;
    QPushButton *btnLinkLine1Point1;
    QPushButton *btnDelLinkLine1Point1;
    QLabel *label_14;
    QPushButton *btnLinkLine2Point1;
    QPushButton *btnLinkLine2Point2;
    QLineEdit *txtLinkLine2Point2;
    QLineEdit *txtLinkLine2Point1;
    QLabel *label_15;
    QPushButton *btnDelLinkLine2Point1;
    QPushButton *btnDelLinkLine2Point2;
    QGroupBox *groupC3;
    QTextEdit *txtMsg;
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
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmLineLineIClass)
    {
        if (frmLineLineIClass->objectName().isEmpty())
            frmLineLineIClass->setObjectName(QString::fromUtf8("frmLineLineIClass"));
        frmLineLineIClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmLineLineIClass->sizePolicy().hasHeightForWidth());
        frmLineLineIClass->setSizePolicy(sizePolicy);
        frmLineLineIClass->setMinimumSize(QSize(1160, 655));
        frmLineLineIClass->setMaximumSize(QSize(1160, 655));
        frmLineLineIClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmLineLineIClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        tabWidget = new QTabWidget(frmLineLineIClass);
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
        groupC2 = new QGroupBox(tab);
        groupC2->setObjectName(QString::fromUtf8("groupC2"));
        groupC2->setGeometry(QRect(9, 107, 427, 268));
        groupC2->setFont(font);
        groupC2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        frame = new QFrame(groupC2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(15, 34, 398, 47));
        frame->setStyleSheet(QString::fromUtf8("border:2px solid #778899;border-radius: 22px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioPoints = new QRadioButton(frame);
        radioPoints->setObjectName(QString::fromUtf8("radioPoints"));
        radioPoints->setFont(font);
        radioPoints->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"border:none;\n"
"background: transparent;"));
        radioPoints->setChecked(true);

        horizontalLayout_2->addWidget(radioPoints);

        horizontalSpacer_6 = new QSpacerItem(110, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        radioTwoPoint = new QRadioButton(frame);
        radioTwoPoint->setObjectName(QString::fromUtf8("radioTwoPoint"));
        radioTwoPoint->setFont(font);
        radioTwoPoint->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"border:none;\n"
"background: transparent;"));

        horizontalLayout_2->addWidget(radioTwoPoint);

        stackedWidget = new QStackedWidget(groupC2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(1, 81, 425, 185));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        frame_2 = new QFrame(page);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 16, 425, 168));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        btnDelLinkLine1b = new QPushButton(frame_2);
        btnDelLinkLine1b->setObjectName(QString::fromUtf8("btnDelLinkLine1b"));
        btnDelLinkLine1b->setGeometry(QRect(394, 48, 27, 27));
        btnDelLinkLine1b->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkLine1b->setIcon(icon1);
        btnDelLinkLine1b->setIconSize(QSize(27, 27));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(13, 8, 86, 19));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(13, 52, 86, 19));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        txtLinkLine1k = new QLineEdit(frame_2);
        txtLinkLine1k->setObjectName(QString::fromUtf8("txtLinkLine1k"));
        txtLinkLine1k->setGeometry(QRect(100, 4, 255, 27));
        txtLinkLine1k->setFont(font);
        txtLinkLine1k->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkLine1k->setAlignment(Qt::AlignCenter);
        txtLinkLine1k->setReadOnly(true);
        txtLinkLine1b = new QLineEdit(frame_2);
        txtLinkLine1b->setObjectName(QString::fromUtf8("txtLinkLine1b"));
        txtLinkLine1b->setGeometry(QRect(100, 48, 255, 27));
        txtLinkLine1b->setFont(font);
        txtLinkLine1b->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkLine1b->setAlignment(Qt::AlignCenter);
        txtLinkLine1b->setReadOnly(true);
        btnLinkLine1b = new QPushButton(frame_2);
        btnLinkLine1b->setObjectName(QString::fromUtf8("btnLinkLine1b"));
        btnLinkLine1b->setGeometry(QRect(360, 48, 27, 27));
        btnLinkLine1b->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkLine1b->setIcon(icon);
        btnLinkLine1b->setIconSize(QSize(27, 27));
        btnLinkLine1k = new QPushButton(frame_2);
        btnLinkLine1k->setObjectName(QString::fromUtf8("btnLinkLine1k"));
        btnLinkLine1k->setGeometry(QRect(360, 4, 27, 27));
        btnLinkLine1k->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkLine1k->setIcon(icon);
        btnLinkLine1k->setIconSize(QSize(27, 27));
        btnDelLinkLine1k = new QPushButton(frame_2);
        btnDelLinkLine1k->setObjectName(QString::fromUtf8("btnDelLinkLine1k"));
        btnDelLinkLine1k->setGeometry(QRect(394, 4, 27, 27));
        btnDelLinkLine1k->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkLine1k->setIcon(icon1);
        btnDelLinkLine1k->setIconSize(QSize(27, 27));
        label_10 = new QLabel(frame_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(13, 140, 86, 19));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 30);\n"
"background: transparent;"));
        btnLinkLine2k = new QPushButton(frame_2);
        btnLinkLine2k->setObjectName(QString::fromUtf8("btnLinkLine2k"));
        btnLinkLine2k->setGeometry(QRect(360, 92, 27, 27));
        btnLinkLine2k->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkLine2k->setIcon(icon);
        btnLinkLine2k->setIconSize(QSize(27, 27));
        btnLinkLine2b = new QPushButton(frame_2);
        btnLinkLine2b->setObjectName(QString::fromUtf8("btnLinkLine2b"));
        btnLinkLine2b->setGeometry(QRect(360, 136, 27, 27));
        btnLinkLine2b->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkLine2b->setIcon(icon);
        btnLinkLine2b->setIconSize(QSize(27, 27));
        txtLinkLine2b = new QLineEdit(frame_2);
        txtLinkLine2b->setObjectName(QString::fromUtf8("txtLinkLine2b"));
        txtLinkLine2b->setGeometry(QRect(100, 136, 255, 27));
        txtLinkLine2b->setFont(font);
        txtLinkLine2b->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkLine2b->setAlignment(Qt::AlignCenter);
        txtLinkLine2b->setReadOnly(true);
        txtLinkLine2k = new QLineEdit(frame_2);
        txtLinkLine2k->setObjectName(QString::fromUtf8("txtLinkLine2k"));
        txtLinkLine2k->setGeometry(QRect(100, 92, 255, 27));
        txtLinkLine2k->setFont(font);
        txtLinkLine2k->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkLine2k->setAlignment(Qt::AlignCenter);
        txtLinkLine2k->setReadOnly(true);
        label_11 = new QLabel(frame_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(13, 96, 86, 19));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 30);\n"
"background: transparent;"));
        btnDelLinkLine2k = new QPushButton(frame_2);
        btnDelLinkLine2k->setObjectName(QString::fromUtf8("btnDelLinkLine2k"));
        btnDelLinkLine2k->setGeometry(QRect(394, 92, 27, 27));
        btnDelLinkLine2k->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkLine2k->setIcon(icon1);
        btnDelLinkLine2k->setIconSize(QSize(27, 27));
        btnDelLinkLine2b = new QPushButton(frame_2);
        btnDelLinkLine2b->setObjectName(QString::fromUtf8("btnDelLinkLine2b"));
        btnDelLinkLine2b->setGeometry(QRect(394, 136, 27, 27));
        btnDelLinkLine2b->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkLine2b->setIcon(icon1);
        btnDelLinkLine2b->setIconSize(QSize(27, 27));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        frame_3 = new QFrame(page_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 16, 425, 168));
        frame_3->setStyleSheet(QString::fromUtf8(""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        btnDelLinkLine1Point2 = new QPushButton(frame_3);
        btnDelLinkLine1Point2->setObjectName(QString::fromUtf8("btnDelLinkLine1Point2"));
        btnDelLinkLine1Point2->setGeometry(QRect(394, 48, 27, 27));
        btnDelLinkLine1Point2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkLine1Point2->setIcon(icon1);
        btnDelLinkLine1Point2->setIconSize(QSize(27, 27));
        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(13, 8, 113, 19));
        label_12->setFont(font);
        label_12->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(13, 52, 113, 19));
        label_13->setFont(font);
        label_13->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        txtLinkLine1Point1 = new QLineEdit(frame_3);
        txtLinkLine1Point1->setObjectName(QString::fromUtf8("txtLinkLine1Point1"));
        txtLinkLine1Point1->setGeometry(QRect(127, 4, 228, 27));
        txtLinkLine1Point1->setFont(font);
        txtLinkLine1Point1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkLine1Point1->setAlignment(Qt::AlignCenter);
        txtLinkLine1Point1->setReadOnly(true);
        txtLinkLine1Point2 = new QLineEdit(frame_3);
        txtLinkLine1Point2->setObjectName(QString::fromUtf8("txtLinkLine1Point2"));
        txtLinkLine1Point2->setGeometry(QRect(127, 48, 228, 27));
        txtLinkLine1Point2->setFont(font);
        txtLinkLine1Point2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkLine1Point2->setAlignment(Qt::AlignCenter);
        txtLinkLine1Point2->setReadOnly(true);
        btnLinkLine1Point2 = new QPushButton(frame_3);
        btnLinkLine1Point2->setObjectName(QString::fromUtf8("btnLinkLine1Point2"));
        btnLinkLine1Point2->setGeometry(QRect(360, 48, 27, 27));
        btnLinkLine1Point2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkLine1Point2->setIcon(icon);
        btnLinkLine1Point2->setIconSize(QSize(27, 27));
        btnLinkLine1Point1 = new QPushButton(frame_3);
        btnLinkLine1Point1->setObjectName(QString::fromUtf8("btnLinkLine1Point1"));
        btnLinkLine1Point1->setGeometry(QRect(360, 4, 27, 27));
        btnLinkLine1Point1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkLine1Point1->setIcon(icon);
        btnLinkLine1Point1->setIconSize(QSize(27, 27));
        btnDelLinkLine1Point1 = new QPushButton(frame_3);
        btnDelLinkLine1Point1->setObjectName(QString::fromUtf8("btnDelLinkLine1Point1"));
        btnDelLinkLine1Point1->setGeometry(QRect(394, 4, 27, 27));
        btnDelLinkLine1Point1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkLine1Point1->setIcon(icon1);
        btnDelLinkLine1Point1->setIconSize(QSize(27, 27));
        label_14 = new QLabel(frame_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(13, 140, 113, 19));
        label_14->setFont(font);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 30);\n"
"background: transparent;"));
        btnLinkLine2Point1 = new QPushButton(frame_3);
        btnLinkLine2Point1->setObjectName(QString::fromUtf8("btnLinkLine2Point1"));
        btnLinkLine2Point1->setGeometry(QRect(360, 92, 27, 27));
        btnLinkLine2Point1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkLine2Point1->setIcon(icon);
        btnLinkLine2Point1->setIconSize(QSize(27, 27));
        btnLinkLine2Point2 = new QPushButton(frame_3);
        btnLinkLine2Point2->setObjectName(QString::fromUtf8("btnLinkLine2Point2"));
        btnLinkLine2Point2->setGeometry(QRect(360, 136, 27, 27));
        btnLinkLine2Point2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkLine2Point2->setIcon(icon);
        btnLinkLine2Point2->setIconSize(QSize(27, 27));
        txtLinkLine2Point2 = new QLineEdit(frame_3);
        txtLinkLine2Point2->setObjectName(QString::fromUtf8("txtLinkLine2Point2"));
        txtLinkLine2Point2->setGeometry(QRect(127, 136, 228, 27));
        txtLinkLine2Point2->setFont(font);
        txtLinkLine2Point2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkLine2Point2->setAlignment(Qt::AlignCenter);
        txtLinkLine2Point2->setReadOnly(true);
        txtLinkLine2Point1 = new QLineEdit(frame_3);
        txtLinkLine2Point1->setObjectName(QString::fromUtf8("txtLinkLine2Point1"));
        txtLinkLine2Point1->setGeometry(QRect(127, 92, 228, 27));
        txtLinkLine2Point1->setFont(font);
        txtLinkLine2Point1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkLine2Point1->setAlignment(Qt::AlignCenter);
        txtLinkLine2Point1->setReadOnly(true);
        label_15 = new QLabel(frame_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(13, 96, 113, 19));
        label_15->setFont(font);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 30);\n"
"background: transparent;"));
        btnDelLinkLine2Point1 = new QPushButton(frame_3);
        btnDelLinkLine2Point1->setObjectName(QString::fromUtf8("btnDelLinkLine2Point1"));
        btnDelLinkLine2Point1->setGeometry(QRect(394, 92, 27, 27));
        btnDelLinkLine2Point1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkLine2Point1->setIcon(icon1);
        btnDelLinkLine2Point1->setIconSize(QSize(27, 27));
        btnDelLinkLine2Point2 = new QPushButton(frame_3);
        btnDelLinkLine2Point2->setObjectName(QString::fromUtf8("btnDelLinkLine2Point2"));
        btnDelLinkLine2Point2->setGeometry(QRect(394, 136, 27, 27));
        btnDelLinkLine2Point2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkLine2Point2->setIcon(icon1);
        btnDelLinkLine2Point2->setIconSize(QSize(27, 27));
        stackedWidget->addWidget(page_2);
        groupC3 = new QGroupBox(tab);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(9, 390, 427, 127));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC3);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 419, 91));
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

        label_3 = new QLabel(frmLineLineIClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmLineLineIClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmLineLineIClass);
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

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        retranslateUi(frmLineLineIClass);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmLineLineIClass);
    } // setupUi

    void retranslateUi(QDialog *frmLineLineIClass)
    {
        frmLineLineIClass->setWindowTitle(QCoreApplication::translate("frmLineLineIClass", "\347\272\277\347\272\277\344\272\244\347\202\271", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmLineLineIClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmLineLineIClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupC2->setTitle(QCoreApplication::translate("frmLineLineIClass", "\346\236\204\345\273\272\345\217\202\346\225\260", nullptr));
        radioPoints->setText(QCoreApplication::translate("frmLineLineIClass", "\347\233\264\347\272\277\346\226\234\347\216\207/\346\210\252\350\267\235\346\226\271\345\274\217", nullptr));
        radioTwoPoint->setText(QCoreApplication::translate("frmLineLineIClass", "\347\233\264\347\272\277\344\270\244\347\202\271\346\226\271\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkLine1b->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\345\210\240\351\231\244\347\233\264\347\272\2771\346\210\252\350\267\235\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkLine1b->setText(QString());
        label_8->setText(QCoreApplication::translate("frmLineLineIClass", "\347\233\264\347\272\2771\346\226\234\347\216\207\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("frmLineLineIClass", "\347\233\264\347\272\2771\346\210\252\350\267\235\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkLine1k->setToolTip(QCoreApplication::translate("frmLineLineIClass", "Double\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        txtLinkLine1b->setToolTip(QCoreApplication::translate("frmLineLineIClass", "Double\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkLine1b->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\351\223\276\346\216\245\347\233\264\347\272\2771\346\210\252\350\267\235", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkLine1b->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkLine1k->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\351\223\276\346\216\245\347\233\264\347\272\2771\346\226\234\347\216\207", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkLine1k->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkLine1k->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\345\210\240\351\231\244\347\233\264\347\272\2771\346\226\234\347\216\207\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkLine1k->setText(QString());
        label_10->setText(QCoreApplication::translate("frmLineLineIClass", "\347\233\264\347\272\2772\346\210\252\350\267\235\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkLine2k->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\351\223\276\346\216\245\347\233\264\347\272\2772\346\226\234\347\216\207", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkLine2k->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkLine2b->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\351\223\276\346\216\245\347\233\264\347\272\2772\346\210\252\350\267\235", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkLine2b->setText(QString());
#if QT_CONFIG(tooltip)
        txtLinkLine2b->setToolTip(QCoreApplication::translate("frmLineLineIClass", "Double\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        txtLinkLine2k->setToolTip(QCoreApplication::translate("frmLineLineIClass", "Double\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        label_11->setText(QCoreApplication::translate("frmLineLineIClass", "\347\233\264\347\272\2772\346\226\234\347\216\207\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkLine2k->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\345\210\240\351\231\244\347\233\264\347\272\2772\346\226\234\347\216\207\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkLine2k->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkLine2b->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\345\210\240\351\231\244\347\233\264\347\272\2772\346\210\252\350\267\235\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkLine2b->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkLine1Point2->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\345\210\240\351\231\244\347\233\264\347\272\2771\347\202\2712\345\235\220\346\240\207\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkLine1Point2->setText(QString());
        label_12->setText(QCoreApplication::translate("frmLineLineIClass", "\347\233\264\347\272\2771\347\202\2711\345\235\220\346\240\207\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("frmLineLineIClass", "\347\233\264\347\272\2771\347\202\2712\345\235\220\346\240\207\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkLine1Point1->setToolTip(QCoreApplication::translate("frmLineLineIClass", "cv::Point\346\210\226cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        txtLinkLine1Point2->setToolTip(QCoreApplication::translate("frmLineLineIClass", "cv::Point\346\210\226cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkLine1Point2->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\351\223\276\346\216\245\347\233\264\347\272\2771\347\202\2712\345\235\220\346\240\207", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkLine1Point2->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkLine1Point1->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\351\223\276\346\216\245\347\233\264\347\272\2771\347\202\2711\345\235\220\346\240\207", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkLine1Point1->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkLine1Point1->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\345\210\240\351\231\244\347\233\264\347\272\2771\347\202\2711\345\235\220\346\240\207\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkLine1Point1->setText(QString());
        label_14->setText(QCoreApplication::translate("frmLineLineIClass", "\347\233\264\347\272\2772\347\202\2712\345\235\220\346\240\207\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkLine2Point1->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\351\223\276\346\216\245\347\233\264\347\272\2772\347\202\2711\345\235\220\346\240\207", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkLine2Point1->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkLine2Point2->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\351\223\276\346\216\245\347\233\264\347\272\2772\347\202\2712\345\235\220\346\240\207", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkLine2Point2->setText(QString());
#if QT_CONFIG(tooltip)
        txtLinkLine2Point2->setToolTip(QCoreApplication::translate("frmLineLineIClass", "cv::Point\346\210\226cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        txtLinkLine2Point1->setToolTip(QCoreApplication::translate("frmLineLineIClass", "cv::Point\346\210\226cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
        label_15->setText(QCoreApplication::translate("frmLineLineIClass", "\347\233\264\347\272\2772\347\202\2711\345\235\220\346\240\207\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkLine2Point1->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\345\210\240\351\231\244\347\233\264\347\272\2772\347\202\2711\345\235\220\346\240\207\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkLine2Point1->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkLine2Point2->setToolTip(QCoreApplication::translate("frmLineLineIClass", "\345\210\240\351\231\244\347\233\264\347\272\2772\347\202\2712\345\235\220\346\240\207\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkLine2Point2->setText(QString());
        groupC3->setTitle(QCoreApplication::translate("frmLineLineIClass", "\350\276\223\345\207\272\346\225\260\346\215\256(\344\270\244\347\233\264\347\272\277\344\272\244\347\202\271\345\235\220\346\240\207\343\200\201\345\244\271\350\247\222)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmLineLineIClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmLineLineIClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmLineLineIClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmLineLineIClass: public Ui_frmLineLineIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLINELINEI_H
