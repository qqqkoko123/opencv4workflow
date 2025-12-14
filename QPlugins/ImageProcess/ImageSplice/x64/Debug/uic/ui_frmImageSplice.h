/********************************************************************************
** Form generated from reading UI file 'frmImageSplice.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMIMAGESPLICE_H
#define UI_FRMIMAGESPLICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmImageSpliceClass
{
public:
    QGridLayout *gridLayout;
    QGridLayout *imageLayout;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupCamera;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetImage;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnAddImage;
    QPushButton *btnDeleteImage;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupCamera_2;
    QDoubleSpinBox *spinRegistrationResol;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QLineEdit *txtDescribe;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btnExecute;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *frmImageSpliceClass)
    {
        if (frmImageSpliceClass->objectName().isEmpty())
            frmImageSpliceClass->setObjectName(QString::fromUtf8("frmImageSpliceClass"));
        frmImageSpliceClass->resize(1160, 655);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmImageSpliceClass->sizePolicy().hasHeightForWidth());
        frmImageSpliceClass->setSizePolicy(sizePolicy);
        frmImageSpliceClass->setMinimumSize(QSize(1160, 655));
        frmImageSpliceClass->setMaximumSize(QSize(1160, 655));
        frmImageSpliceClass->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 220, 220);"));
        gridLayout = new QGridLayout(frmImageSpliceClass);
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

        tabWidget = new QTabWidget(frmImageSpliceClass);
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
        groupCamera->setGeometry(QRect(9, 18, 427, 244));
        groupCamera->setFont(font);
        groupCamera->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        horizontalLayoutWidget = new QWidget(groupCamera);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(8, 36, 411, 201));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(horizontalLayoutWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidgetImage = new QTableWidget(frame);
        if (tableWidgetImage->columnCount() < 1)
            tableWidgetImage->setColumnCount(1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidgetImage->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidgetImage->setObjectName(QString::fromUtf8("tableWidgetImage"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tableWidgetImage->setFont(font2);
        tableWidgetImage->setStyleSheet(QString::fromUtf8("QTableWidget          \n"
"{\n"
"    background-color: #b7c7af;   \n"
"    border:none;\n"
"    gridline-color: rgba(20, 25, 155,50);\n"
"    color: rgba(20, 20, 20,200);\n"
"}\n"
"QTableWidget::item::selected\n"
"{   \n"
"    background-color: rgba(180, 180, 215,255); \n"
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
""
                        "QScrollBar::handle:horizontal{\n"
"		background:#dbdbdb;\n"
"		border-radius:6px;\n"
"		min-height:20px;}\n"
"QScrollBar::handle:horizontal:hover{\n"
"		background:#d0d0d0;}\n"
"QScrollBar::add-line:horizontal{\n"
"		background:url(:/resource/right.png) center no-repeat;}\n"
"QScrollBar::sub-line:horizontal{\n"
"		background:url(:/resource/left.png) center no-repeat;}"));
        tableWidgetImage->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetImage->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidgetImage->setGridStyle(Qt::DashLine);
        tableWidgetImage->horizontalHeader()->setMinimumSectionSize(29);
        tableWidgetImage->horizontalHeader()->setDefaultSectionSize(339);
        tableWidgetImage->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout->addWidget(tableWidgetImage);


        horizontalLayout_2->addWidget(frame);

        frame_2 = new QFrame(horizontalLayoutWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("border: 1px solid;\n"
"border-color: rgba(173, 173, 173, 155);\n"
"background-color: #b7c7a7;   "));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(13);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 2, 1, 1);
        btnAddImage = new QPushButton(frame_2);
        btnAddImage->setObjectName(QString::fromUtf8("btnAddImage"));
        sizePolicy.setHeightForWidth(btnAddImage->sizePolicy().hasHeightForWidth());
        btnAddImage->setSizePolicy(sizePolicy);
        btnAddImage->setMinimumSize(QSize(60, 30));
        btnAddImage->setFont(font1);
        btnAddImage->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(9, 42, 47, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(9, 62, 52);}\n"
"QPushButton:pressed{background-color: rgb(9, 82, 72);}"));

        verticalLayout_2->addWidget(btnAddImage);

        btnDeleteImage = new QPushButton(frame_2);
        btnDeleteImage->setObjectName(QString::fromUtf8("btnDeleteImage"));
        btnDeleteImage->setMinimumSize(QSize(60, 30));
        btnDeleteImage->setFont(font1);
        btnDeleteImage->setStyleSheet(QString::fromUtf8("QWidget{ background-color: rgba(97, 63, 56, 200);}\n"
"QWidget{ color: rgb(235, 235, 235);}\n"
"QWidget{ border: 2px groove gray;border-radius: 5px;padding: 2px 4px;}\n"
"QPushButton:hover{ background-color: rgb(97, 83, 76);}\n"
"QPushButton:pressed{background-color: rgb(117, 83, 96);}"));

        verticalLayout_2->addWidget(btnDeleteImage);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout_2->addWidget(frame_2);

        groupCamera_2 = new QGroupBox(tab);
        groupCamera_2->setObjectName(QString::fromUtf8("groupCamera_2"));
        groupCamera_2->setGeometry(QRect(9, 276, 427, 73));
        groupCamera_2->setFont(font);
        groupCamera_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"color: rgb(85, 0, 255);"));
        spinRegistrationResol = new QDoubleSpinBox(groupCamera_2);
        spinRegistrationResol->setObjectName(QString::fromUtf8("spinRegistrationResol"));
        spinRegistrationResol->setGeometry(QRect(114, 38, 73, 27));
        sizePolicy.setHeightForWidth(spinRegistrationResol->sizePolicy().hasHeightForWidth());
        spinRegistrationResol->setSizePolicy(sizePolicy);
        spinRegistrationResol->setMinimumSize(QSize(70, 25));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        spinRegistrationResol->setFont(font3);
        spinRegistrationResol->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 155);background-color: rgb(180, 180, 210);}\n"
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
        spinRegistrationResol->setAlignment(Qt::AlignCenter);
        spinRegistrationResol->setDecimals(2);
        spinRegistrationResol->setMinimum(0.100000000000000);
        spinRegistrationResol->setMaximum(1.000000000000000);
        spinRegistrationResol->setSingleStep(0.100000000000000);
        spinRegistrationResol->setValue(0.350000000000000);
        label_9 = new QLabel(groupCamera_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(13, 42, 101, 19));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        label_9->setFont(font4);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(30, 30, 30);\n"
"background: transparent;"));
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

        label_3 = new QLabel(frmImageSpliceClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMaximumSize(QSize(83, 25));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label_3);

        txtDescribe = new QLineEdit(frmImageSpliceClass);
        txtDescribe->setObjectName(QString::fromUtf8("txtDescribe"));
        sizePolicy.setHeightForWidth(txtDescribe->sizePolicy().hasHeightForWidth());
        txtDescribe->setSizePolicy(sizePolicy);
        txtDescribe->setMinimumSize(QSize(357, 30));
        txtDescribe->setMaximumSize(QSize(16777215, 30));
        txtDescribe->setFont(font);

        horizontalLayout->addWidget(txtDescribe);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btnExecute = new QPushButton(frmImageSpliceClass);
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


        retranslateUi(frmImageSpliceClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmImageSpliceClass);
    } // setupUi

    void retranslateUi(QDialog *frmImageSpliceClass)
    {
        frmImageSpliceClass->setWindowTitle(QCoreApplication::translate("frmImageSpliceClass", "\345\233\276\345\203\217\346\213\274\346\216\245", nullptr));
        groupCamera->setTitle(QCoreApplication::translate("frmImageSpliceClass", "\345\233\276\345\203\217\345\257\271\350\261\241", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetImage->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("frmImageSpliceClass", "\345\233\276\345\203\217\351\223\276\346\216\245\345\234\260\345\235\200", nullptr));
        btnAddImage->setText(QCoreApplication::translate("frmImageSpliceClass", "\346\267\273\345\212\240", nullptr));
        btnDeleteImage->setText(QCoreApplication::translate("frmImageSpliceClass", "\345\210\240\351\231\244", nullptr));
        groupCamera_2->setTitle(QCoreApplication::translate("frmImageSpliceClass", "\346\213\274\346\216\245\345\217\202\346\225\260", nullptr));
#if QT_CONFIG(tooltip)
        spinRegistrationResol->setToolTip(QCoreApplication::translate("frmImageSpliceClass", "\345\200\274\350\266\212\345\260\217\346\213\274\346\216\245\351\200\237\345\272\246\350\266\212\345\277\253\357\274\214\344\275\206\345\214\271\351\205\215\347\202\271\345\217\230\345\260\221", nullptr));
#endif // QT_CONFIG(tooltip)
        label_9->setText(QCoreApplication::translate("frmImageSpliceClass", "\351\205\215\345\207\206\345\210\206\350\276\250\347\216\207\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmImageSpliceClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("frmImageSpliceClass", "\345\215\225\345\205\203\346\217\217\350\277\260\357\274\232", nullptr));
        btnExecute->setText(QCoreApplication::translate("frmImageSpliceClass", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmImageSpliceClass: public Ui_frmImageSpliceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMIMAGESPLICE_H
