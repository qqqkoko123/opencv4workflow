/********************************************************************************
** Form generated from reading UI file 'frmLineCircle.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLINECIRCLE_H
#define UI_FRMLINECIRCLE_H

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

class Ui_frmLineCircleClass
{
public:
    QGridLayout *gridLayout;
    QGridLayout *imageLayout;
    QSpacerItem *verticalSpacer;
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
    QPushButton *btnDelLinkLineb;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *txtLinkLinek;
    QLineEdit *txtLinkLineb;
    QPushButton *btnLinkLineb;
    QPushButton *btnLinkLinek;
    QPushButton *btnDelLinkLinek;
    QWidget *page_2;
    QFrame *frame_3;
    QLabel *label_6;
    QLineEdit *txtLinkPoint1;
    QPushButton *btnLinkPoint1;
    QPushButton *btnDelLinkPoint1;
    QPushButton *btnLinkPoint2;
    QLabel *label_7;
    QLineEdit *txtLinkPoint2;
    QPushButton *btnDelLinkPoint2;
    QLabel *label_10;
    QLineEdit *txtLinkCircleCPoint;
    QPushButton *btnLinkCircleCPoint;
    QPushButton *btnDelLinkCircleCPoint;
    QLabel *label_11;
    QPushButton *btnDelLinkCircleRadius;
    QLineEdit *txtLinkCircleRadius;
    QPushButton *btnLinkCircleRadius;
    QGroupBox *groupC3;
    QTextEdit *txtMsg;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmLineCircleClass)
    {
        if (frmLineCircleClass->objectName().isEmpty())
            frmLineCircleClass->setObjectName(QString::fromUtf8("frmLineCircleClass"));
        frmLineCircleClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmLineCircleClass->sizePolicy().hasHeightForWidth());
        frmLineCircleClass->setSizePolicy(sizePolicy);
        frmLineCircleClass->setMinimumSize(QSize(1160, 655));
        frmLineCircleClass->setMaximumSize(QSize(1160, 655));
        frmLineCircleClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmLineCircleClass);
        gridLayout->setSpacing(1);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        imageLayout = new QGridLayout();
        imageLayout->setSpacing(1);
        imageLayout->setObjectName(QString::fromUtf8("imageLayout"));

        gridLayout->addLayout(imageLayout, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        tabWidget = new QTabWidget(frmLineCircleClass);
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
        groupCamera->setGeometry(QRect(9, 14, 427, 73));
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
        groupC2->setGeometry(QRect(9, 100, 427, 301));
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
        stackedWidget->setGeometry(QRect(1, 80, 425, 118));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        frame_2 = new QFrame(page);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 16, 425, 99));
        frame_2->setStyleSheet(QString::fromUtf8(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        btnDelLinkLineb = new QPushButton(frame_2);
        btnDelLinkLineb->setObjectName(QString::fromUtf8("btnDelLinkLineb"));
        btnDelLinkLineb->setGeometry(QRect(394, 64, 27, 27));
        btnDelLinkLineb->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkLineb->setIcon(icon1);
        btnDelLinkLineb->setIconSize(QSize(27, 27));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(13, 16, 79, 19));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        label_9 = new QLabel(frame_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(13, 68, 79, 19));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        txtLinkLinek = new QLineEdit(frame_2);
        txtLinkLinek->setObjectName(QString::fromUtf8("txtLinkLinek"));
        txtLinkLinek->setGeometry(QRect(100, 12, 255, 27));
        txtLinkLinek->setFont(font);
        txtLinkLinek->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkLinek->setAlignment(Qt::AlignCenter);
        txtLinkLinek->setReadOnly(true);
        txtLinkLineb = new QLineEdit(frame_2);
        txtLinkLineb->setObjectName(QString::fromUtf8("txtLinkLineb"));
        txtLinkLineb->setGeometry(QRect(100, 64, 255, 27));
        txtLinkLineb->setFont(font);
        txtLinkLineb->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkLineb->setAlignment(Qt::AlignCenter);
        txtLinkLineb->setReadOnly(true);
        btnLinkLineb = new QPushButton(frame_2);
        btnLinkLineb->setObjectName(QString::fromUtf8("btnLinkLineb"));
        btnLinkLineb->setGeometry(QRect(360, 64, 27, 27));
        btnLinkLineb->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkLineb->setIcon(icon);
        btnLinkLineb->setIconSize(QSize(27, 27));
        btnLinkLinek = new QPushButton(frame_2);
        btnLinkLinek->setObjectName(QString::fromUtf8("btnLinkLinek"));
        btnLinkLinek->setGeometry(QRect(360, 12, 27, 27));
        btnLinkLinek->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkLinek->setIcon(icon);
        btnLinkLinek->setIconSize(QSize(27, 27));
        btnDelLinkLinek = new QPushButton(frame_2);
        btnDelLinkLinek->setObjectName(QString::fromUtf8("btnDelLinkLinek"));
        btnDelLinkLinek->setGeometry(QRect(394, 12, 27, 27));
        btnDelLinkLinek->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkLinek->setIcon(icon1);
        btnDelLinkLinek->setIconSize(QSize(27, 27));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        frame_3 = new QFrame(page_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(0, 16, 425, 99));
        frame_3->setStyleSheet(QString::fromUtf8(""));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(13, 16, 79, 19));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        txtLinkPoint1 = new QLineEdit(frame_3);
        txtLinkPoint1->setObjectName(QString::fromUtf8("txtLinkPoint1"));
        txtLinkPoint1->setGeometry(QRect(100, 12, 255, 27));
        txtLinkPoint1->setFont(font);
        txtLinkPoint1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkPoint1->setAlignment(Qt::AlignCenter);
        txtLinkPoint1->setReadOnly(true);
        btnLinkPoint1 = new QPushButton(frame_3);
        btnLinkPoint1->setObjectName(QString::fromUtf8("btnLinkPoint1"));
        btnLinkPoint1->setGeometry(QRect(360, 12, 27, 27));
        btnLinkPoint1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkPoint1->setIcon(icon);
        btnLinkPoint1->setIconSize(QSize(27, 27));
        btnDelLinkPoint1 = new QPushButton(frame_3);
        btnDelLinkPoint1->setObjectName(QString::fromUtf8("btnDelLinkPoint1"));
        btnDelLinkPoint1->setGeometry(QRect(394, 12, 27, 27));
        btnDelLinkPoint1->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkPoint1->setIcon(icon1);
        btnDelLinkPoint1->setIconSize(QSize(27, 27));
        btnLinkPoint2 = new QPushButton(frame_3);
        btnLinkPoint2->setObjectName(QString::fromUtf8("btnLinkPoint2"));
        btnLinkPoint2->setGeometry(QRect(360, 64, 27, 27));
        btnLinkPoint2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkPoint2->setIcon(icon);
        btnLinkPoint2->setIconSize(QSize(27, 27));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(13, 68, 79, 19));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("color: rgba(0, 38, 56, 230);\n"
"background: transparent;"));
        txtLinkPoint2 = new QLineEdit(frame_3);
        txtLinkPoint2->setObjectName(QString::fromUtf8("txtLinkPoint2"));
        txtLinkPoint2->setGeometry(QRect(100, 64, 255, 27));
        txtLinkPoint2->setFont(font);
        txtLinkPoint2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkPoint2->setAlignment(Qt::AlignCenter);
        txtLinkPoint2->setReadOnly(true);
        btnDelLinkPoint2 = new QPushButton(frame_3);
        btnDelLinkPoint2->setObjectName(QString::fromUtf8("btnDelLinkPoint2"));
        btnDelLinkPoint2->setGeometry(QRect(394, 64, 27, 27));
        btnDelLinkPoint2->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkPoint2->setIcon(icon1);
        btnDelLinkPoint2->setIconSize(QSize(27, 27));
        stackedWidget->addWidget(page_2);
        label_10 = new QLabel(groupC2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(13, 218, 79, 19));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 30);\n"
"background: transparent;"));
        txtLinkCircleCPoint = new QLineEdit(groupC2);
        txtLinkCircleCPoint->setObjectName(QString::fromUtf8("txtLinkCircleCPoint"));
        txtLinkCircleCPoint->setGeometry(QRect(100, 214, 255, 27));
        txtLinkCircleCPoint->setFont(font);
        txtLinkCircleCPoint->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkCircleCPoint->setAlignment(Qt::AlignCenter);
        txtLinkCircleCPoint->setReadOnly(true);
        btnLinkCircleCPoint = new QPushButton(groupC2);
        btnLinkCircleCPoint->setObjectName(QString::fromUtf8("btnLinkCircleCPoint"));
        btnLinkCircleCPoint->setGeometry(QRect(360, 214, 27, 27));
        btnLinkCircleCPoint->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkCircleCPoint->setIcon(icon);
        btnLinkCircleCPoint->setIconSize(QSize(27, 27));
        btnDelLinkCircleCPoint = new QPushButton(groupC2);
        btnDelLinkCircleCPoint->setObjectName(QString::fromUtf8("btnDelLinkCircleCPoint"));
        btnDelLinkCircleCPoint->setGeometry(QRect(394, 214, 27, 27));
        btnDelLinkCircleCPoint->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkCircleCPoint->setIcon(icon1);
        btnDelLinkCircleCPoint->setIconSize(QSize(27, 27));
        label_11 = new QLabel(groupC2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(13, 271, 79, 19));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 30);\n"
"background: transparent;"));
        btnDelLinkCircleRadius = new QPushButton(groupC2);
        btnDelLinkCircleRadius->setObjectName(QString::fromUtf8("btnDelLinkCircleRadius"));
        btnDelLinkCircleRadius->setGeometry(QRect(394, 267, 27, 27));
        btnDelLinkCircleRadius->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(226, 142, 162, 100);}\n"
"QPushButton:pressed{background-color: rgba(226, 172, 162, 200);}"));
        btnDelLinkCircleRadius->setIcon(icon1);
        btnDelLinkCircleRadius->setIconSize(QSize(27, 27));
        txtLinkCircleRadius = new QLineEdit(groupC2);
        txtLinkCircleRadius->setObjectName(QString::fromUtf8("txtLinkCircleRadius"));
        txtLinkCircleRadius->setGeometry(QRect(100, 267, 255, 27));
        txtLinkCircleRadius->setFont(font);
        txtLinkCircleRadius->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 200);\n"
"background-color: rgba(170, 170, 127,50);"));
        txtLinkCircleRadius->setAlignment(Qt::AlignCenter);
        txtLinkCircleRadius->setReadOnly(true);
        btnLinkCircleRadius = new QPushButton(groupC2);
        btnLinkCircleRadius->setObjectName(QString::fromUtf8("btnLinkCircleRadius"));
        btnLinkCircleRadius->setGeometry(QRect(360, 267, 27, 27));
        btnLinkCircleRadius->setStyleSheet(QString::fromUtf8("QWidget{ border:none;border-radius: 8px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgba(85, 150, 127, 100);}\n"
"QPushButton:pressed{background-color: rgba(85, 180, 127, 160);}"));
        btnLinkCircleRadius->setIcon(icon);
        btnLinkCircleRadius->setIconSize(QSize(27, 27));
        stackedWidget->raise();
        frame->raise();
        label_10->raise();
        txtLinkCircleCPoint->raise();
        btnLinkCircleCPoint->raise();
        btnDelLinkCircleCPoint->raise();
        label_11->raise();
        btnDelLinkCircleRadius->raise();
        txtLinkCircleRadius->raise();
        btnLinkCircleRadius->raise();
        groupC3 = new QGroupBox(tab);
        groupC3->setObjectName(QString::fromUtf8("groupC3"));
        groupC3->setGeometry(QRect(9, 414, 427, 103));
        groupC3->setFont(font);
        groupC3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        txtMsg = new QTextEdit(groupC3);
        txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
        txtMsg->setGeometry(QRect(4, 32, 419, 67));
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

        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 6);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(frmLineCircleClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmLineCircleClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmLineCircleClass);
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

        verticalSpacer_2 = new QSpacerItem(20, 42, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(3, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);


        retranslateUi(frmLineCircleClass);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmLineCircleClass);
    } // setupUi

    void retranslateUi(QDialog *frmLineCircleClass)
    {
        frmLineCircleClass->setWindowTitle(QCoreApplication::translate("frmLineCircleClass", "\347\272\277\345\234\206\344\272\244\347\202\271", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmLineCircleClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        label_4->setText(QCoreApplication::translate("frmLineCircleClass", "\350\276\223\345\205\245\345\233\276\345\203\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnLinkImage->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\351\223\276\346\216\245\345\233\276\345\203\217", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkImage->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkImage->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\345\210\240\351\231\244\345\233\276\345\203\217\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkImage->setText(QString());
        groupC2->setTitle(QCoreApplication::translate("frmLineCircleClass", "\346\236\204\345\273\272\345\217\202\346\225\260", nullptr));
        radioPoints->setText(QCoreApplication::translate("frmLineCircleClass", "\347\233\264\347\272\277\346\226\234\347\216\207/\346\210\252\350\267\235\346\226\271\345\274\217", nullptr));
        radioTwoPoint->setText(QCoreApplication::translate("frmLineCircleClass", "\347\233\264\347\272\277\344\270\244\347\202\271\346\226\271\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkLineb->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\345\210\240\351\231\244\347\233\264\347\272\277\346\210\252\350\267\235\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkLineb->setText(QString());
        label_8->setText(QCoreApplication::translate("frmLineCircleClass", "\347\233\264\347\272\277\346\226\234\347\216\207\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("frmLineCircleClass", "\347\233\264\347\272\277\346\210\252\350\267\235\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkLinek->setToolTip(QCoreApplication::translate("frmLineCircleClass", "Double\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        txtLinkLineb->setToolTip(QCoreApplication::translate("frmLineCircleClass", "Double\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkLineb->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\351\223\276\346\216\245\347\233\264\347\272\277\346\210\252\350\267\235", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkLineb->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkLinek->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\351\223\276\346\216\245\347\233\264\347\272\277\346\226\234\347\216\207", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkLinek->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkLinek->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\345\210\240\351\231\244\347\233\264\347\272\277\346\226\234\347\216\207\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkLinek->setText(QString());
        label_6->setText(QCoreApplication::translate("frmLineCircleClass", "\347\202\2711\345\235\220\346\240\207\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkPoint1->setToolTip(QCoreApplication::translate("frmLineCircleClass", "cv::Point\346\210\226cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkPoint1->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\351\223\276\346\216\245\347\202\2711\345\235\220\346\240\207", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkPoint1->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkPoint1->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\345\210\240\351\231\244\347\202\2711\345\235\220\346\240\207\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkPoint1->setText(QString());
#if QT_CONFIG(tooltip)
        btnLinkPoint2->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\351\223\276\346\216\245\347\202\2712\345\235\220\346\240\207", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkPoint2->setText(QString());
        label_7->setText(QCoreApplication::translate("frmLineCircleClass", "\347\202\2712\345\235\220\346\240\207\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkPoint2->setToolTip(QCoreApplication::translate("frmLineCircleClass", "cv::Point\346\210\226cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnDelLinkPoint2->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\345\210\240\351\231\244\347\202\2712\345\235\220\346\240\207\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkPoint2->setText(QString());
        label_10->setText(QCoreApplication::translate("frmLineCircleClass", "\345\234\206\345\277\203\345\235\220\346\240\207\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        txtLinkCircleCPoint->setToolTip(QCoreApplication::translate("frmLineCircleClass", "cv::Point\346\210\226cv::Point2f\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkCircleCPoint->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\351\223\276\346\216\245\345\234\206\345\277\203\345\235\220\346\240\207", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkCircleCPoint->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelLinkCircleCPoint->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\345\210\240\351\231\244\345\234\206\345\277\203\345\235\220\346\240\207\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkCircleCPoint->setText(QString());
        label_11->setText(QCoreApplication::translate("frmLineCircleClass", "\345\234\206\345\215\212\345\276\204\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        btnDelLinkCircleRadius->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\345\210\240\351\231\244\345\234\206\345\215\212\345\276\204\351\223\276\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelLinkCircleRadius->setText(QString());
#if QT_CONFIG(tooltip)
        txtLinkCircleRadius->setToolTip(QCoreApplication::translate("frmLineCircleClass", "Double\347\261\273\345\236\213", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        btnLinkCircleRadius->setToolTip(QCoreApplication::translate("frmLineCircleClass", "\351\223\276\346\216\245\345\234\206\345\215\212\345\276\204", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLinkCircleRadius->setText(QString());
        groupC3->setTitle(QCoreApplication::translate("frmLineCircleClass", "\350\276\223\345\207\272\346\225\260\346\215\256(\347\272\277\345\234\206\344\272\244\347\202\271\345\235\220\346\240\207)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmLineCircleClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmLineCircleClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmLineCircleClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmLineCircleClass: public Ui_frmLineCircleClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLINECIRCLE_H
