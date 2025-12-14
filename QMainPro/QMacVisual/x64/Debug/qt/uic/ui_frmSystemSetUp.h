/********************************************************************************
** Form generated from reading UI file 'frmSystemSetUp.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMSYSTEMSETUP_H
#define UI_FRMSYSTEMSETUP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmSystemSetUpClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCheckBox *checkProgramSelfStart;
    QCheckBox *checkProcessSelfStart;
    QCheckBox *checkSignOutTime;
    QSpinBox *spinSignOutTime;
    QLabel *label;
    QWidget *tab_2;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinLogTime;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *frmSystemSetUpClass)
    {
        if (frmSystemSetUpClass->objectName().isEmpty())
            frmSystemSetUpClass->setObjectName(QString::fromUtf8("frmSystemSetUpClass"));
        frmSystemSetUpClass->resize(588, 292);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmSystemSetUpClass->sizePolicy().hasHeightForWidth());
        frmSystemSetUpClass->setSizePolicy(sizePolicy);
        frmSystemSetUpClass->setMinimumSize(QSize(520, 270));
        frmSystemSetUpClass->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        frmSystemSetUpClass->setFont(font);
        frmSystemSetUpClass->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QMacVisual/Icon/other_478.ico"), QSize(), QIcon::Normal, QIcon::Off);
        frmSystemSetUpClass->setWindowIcon(icon);
        frmSystemSetUpClass->setStyleSheet(QString::fromUtf8("background-color: #bcc2bc;"));
        verticalLayout = new QVBoxLayout(frmSystemSetUpClass);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(3, 0, 0, 0);
        tabWidget = new QTabWidget(frmSystemSetUpClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #dfd5cf, stop: 0.15 #acbbac, stop: 0.85 #acbbac,stop:1 #dfd5cf);\n"
"border:1px solid rgb(150, 150, 170);"));
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        checkProgramSelfStart = new QCheckBox(tab);
        checkProgramSelfStart->setObjectName(QString::fromUtf8("checkProgramSelfStart"));
        checkProgramSelfStart->setGeometry(QRect(50, 40, 123, 23));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        checkProgramSelfStart->setFont(font2);
        checkProgramSelfStart->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 17px;\n"
"    height: 17px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/res/ico/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/res/ico/tick.png);\n"
"};"));
        checkProgramSelfStart->setIconSize(QSize(22, 22));
        checkProgramSelfStart->setChecked(false);
        checkProcessSelfStart = new QCheckBox(tab);
        checkProcessSelfStart->setObjectName(QString::fromUtf8("checkProcessSelfStart"));
        checkProcessSelfStart->setGeometry(QRect(250, 40, 229, 23));
        checkProcessSelfStart->setFont(font2);
        checkProcessSelfStart->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 17px;\n"
"    height: 17px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/res/ico/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/res/ico/tick.png);\n"
"};"));
        checkSignOutTime = new QCheckBox(tab);
        checkSignOutTime->setObjectName(QString::fromUtf8("checkSignOutTime"));
        checkSignOutTime->setGeometry(QRect(50, 122, 230, 23));
        checkSignOutTime->setFont(font2);
        checkSignOutTime->setStyleSheet(QString::fromUtf8("QCheckBox{\n"
"    color: rgb(30, 30, 30);\n"
"	border-style: flat;\n"
"	background: transparent;\n"
"}\n"
"QCheckBox::indicator {\n"
"    width: 17px;\n"
"    height: 17px;    \n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"    image: url(:/res/ico/untick.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"    image: url(:/res/ico/tick.png);\n"
"};"));
        spinSignOutTime = new QSpinBox(tab);
        spinSignOutTime->setObjectName(QString::fromUtf8("spinSignOutTime"));
        spinSignOutTime->setGeometry(QRect(286, 121, 56, 26));
        spinSignOutTime->setFont(font2);
        spinSignOutTime->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/res/ico/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/res/ico/down.png);\n"
"}"));
        spinSignOutTime->setAlignment(Qt::AlignCenter);
        spinSignOutTime->setMinimum(1);
        spinSignOutTime->setMaximum(60);
        spinSignOutTime->setValue(10);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(346, 122, 41, 21));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgba(255, 255, 255, 0);"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 40, 123, 19));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgba(255, 255, 255, 0);"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 40, 23, 21));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgba(255, 255, 255, 0);"));
        spinLogTime = new QSpinBox(tab_2);
        spinLogTime->setObjectName(QString::fromUtf8("spinLogTime"));
        spinLogTime->setGeometry(QRect(170, 37, 56, 26));
        spinLogTime->setFont(font2);
        spinLogTime->setStyleSheet(QString::fromUtf8("QWidget{color: rgb(85, 0, 255);background-color: rgb(180, 180, 210);}\n"
"QSpinBox::up-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::down-button{\n"
"    border:transparent;\n"
"}\n"
"QSpinBox::up-arrow{\n"
"    image:url(:/res/ico/up.png);\n"
"}\n"
"QSpinBox::down-arrow{\n"
"    image:url(:/res/ico/down.png);\n"
"}"));
        spinLogTime->setAlignment(Qt::AlignCenter);
        spinLogTime->setMinimum(1);
        spinLogTime->setMaximum(365);
        spinLogTime->setValue(30);
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 45, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(frmSystemSetUpClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(frmSystemSetUpClass);
    } // setupUi

    void retranslateUi(QWidget *frmSystemSetUpClass)
    {
        frmSystemSetUpClass->setWindowTitle(QCoreApplication::translate("frmSystemSetUpClass", "QMacVisual", nullptr));
        checkProgramSelfStart->setText(QCoreApplication::translate("frmSystemSetUpClass", "\345\274\200\346\234\272\350\207\252\345\220\257\345\212\250", nullptr));
        checkProcessSelfStart->setText(QCoreApplication::translate("frmSystemSetUpClass", "\345\220\257\345\212\250\345\220\216\346\265\201\347\250\213\350\207\252\345\212\250\345\274\200\345\247\213\346\211\247\350\241\214", nullptr));
        checkSignOutTime->setText(QCoreApplication::translate("frmSystemSetUpClass", "\347\250\213\345\272\217\346\227\240\346\223\215\344\275\234\350\207\252\345\212\250\347\231\273\345\207\272\346\227\266\351\227\264\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("frmSystemSetUpClass", "\345\210\206\351\222\237", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("frmSystemSetUpClass", "\345\237\272\346\234\254\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("frmSystemSetUpClass", "\346\227\245\345\277\227\344\277\235\345\255\230\345\244\251\346\225\260\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("frmSystemSetUpClass", "\345\244\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("frmSystemSetUpClass", "\346\227\245\345\277\227\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmSystemSetUpClass: public Ui_frmSystemSetUpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMSYSTEMSETUP_H
