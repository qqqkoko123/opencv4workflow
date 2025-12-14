/********************************************************************************
** Form generated from reading UI file 'frmProItemTab.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPROITEMTAB_H
#define UI_FRMPROITEMTAB_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmProItemTabClass
{
public:
    QGridLayout *gridLayout_2;
    QFrame *FlowFrame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAddProFlow;
    QPushButton *btnDelProFlow;
    QPushButton *btnSetProFlow;
    QPushButton *btnRunOnce;
    QPushButton *btnRunCycle;
    QPushButton *btnStop;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *ProItemTreeWidget;
    QDockWidget *dockTabWidget;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_3;
    QTabWidget *ProItemTabWidget;

    void setupUi(QWidget *frmProItemTabClass)
    {
        if (frmProItemTabClass->objectName().isEmpty())
            frmProItemTabClass->setObjectName(QString::fromUtf8("frmProItemTabClass"));
        frmProItemTabClass->resize(298, 621);
        frmProItemTabClass->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 248, 226);"));
        gridLayout_2 = new QGridLayout(frmProItemTabClass);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 9, 0, 0);
        FlowFrame = new QFrame(frmProItemTabClass);
        FlowFrame->setObjectName(QString::fromUtf8("FlowFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FlowFrame->sizePolicy().hasHeightForWidth());
        FlowFrame->setSizePolicy(sizePolicy);
        FlowFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 248, 226);"));
        FlowFrame->setFrameShape(QFrame::StyledPanel);
        FlowFrame->setFrameShadow(QFrame::Raised);
        FlowFrame->setLineWidth(0);
        gridLayout = new QGridLayout(FlowFrame);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnAddProFlow = new QPushButton(FlowFrame);
        btnAddProFlow->setObjectName(QString::fromUtf8("btnAddProFlow"));
        btnAddProFlow->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnAddProFlow->sizePolicy().hasHeightForWidth());
        btnAddProFlow->setSizePolicy(sizePolicy1);
        btnAddProFlow->setMinimumSize(QSize(42, 42));
        btnAddProFlow->setMaximumSize(QSize(42, 42));
        btnAddProFlow->setStyleSheet(QString::fromUtf8(""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Bitmaps/process.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnAddProFlow->setIcon(icon);
        btnAddProFlow->setIconSize(QSize(42, 42));
        btnAddProFlow->setFlat(false);

        horizontalLayout->addWidget(btnAddProFlow);

        btnDelProFlow = new QPushButton(FlowFrame);
        btnDelProFlow->setObjectName(QString::fromUtf8("btnDelProFlow"));
        btnDelProFlow->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnDelProFlow->sizePolicy().hasHeightForWidth());
        btnDelProFlow->setSizePolicy(sizePolicy1);
        btnDelProFlow->setMinimumSize(QSize(42, 42));
        btnDelProFlow->setMaximumSize(QSize(42, 42));
        btnDelProFlow->setStyleSheet(QString::fromUtf8(""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Bitmaps/process_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelProFlow->setIcon(icon1);
        btnDelProFlow->setIconSize(QSize(42, 42));
        btnDelProFlow->setFlat(false);

        horizontalLayout->addWidget(btnDelProFlow);

        btnSetProFlow = new QPushButton(FlowFrame);
        btnSetProFlow->setObjectName(QString::fromUtf8("btnSetProFlow"));
        btnSetProFlow->setEnabled(true);
        sizePolicy1.setHeightForWidth(btnSetProFlow->sizePolicy().hasHeightForWidth());
        btnSetProFlow->setSizePolicy(sizePolicy1);
        btnSetProFlow->setMinimumSize(QSize(42, 42));
        btnSetProFlow->setMaximumSize(QSize(42, 42));
        btnSetProFlow->setStyleSheet(QString::fromUtf8(""));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Bitmaps/process_3.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSetProFlow->setIcon(icon2);
        btnSetProFlow->setIconSize(QSize(42, 42));
        btnSetProFlow->setFlat(false);

        horizontalLayout->addWidget(btnSetProFlow);

        btnRunOnce = new QPushButton(FlowFrame);
        btnRunOnce->setObjectName(QString::fromUtf8("btnRunOnce"));
        sizePolicy1.setHeightForWidth(btnRunOnce->sizePolicy().hasHeightForWidth());
        btnRunOnce->setSizePolicy(sizePolicy1);
        btnRunOnce->setMinimumSize(QSize(42, 42));
        btnRunOnce->setMaximumSize(QSize(42, 42));
        btnRunOnce->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Bitmaps/run_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRunOnce->setIcon(icon3);
        btnRunOnce->setIconSize(QSize(32, 32));
        btnRunOnce->setFlat(false);

        horizontalLayout->addWidget(btnRunOnce);

        btnRunCycle = new QPushButton(FlowFrame);
        btnRunCycle->setObjectName(QString::fromUtf8("btnRunCycle"));
        sizePolicy1.setHeightForWidth(btnRunCycle->sizePolicy().hasHeightForWidth());
        btnRunCycle->setSizePolicy(sizePolicy1);
        btnRunCycle->setMinimumSize(QSize(42, 42));
        btnRunCycle->setMaximumSize(QSize(42, 42));
        btnRunCycle->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Bitmaps/cycle.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRunCycle->setIcon(icon4);
        btnRunCycle->setIconSize(QSize(32, 32));
        btnRunCycle->setFlat(false);

        horizontalLayout->addWidget(btnRunCycle);

        btnStop = new QPushButton(FlowFrame);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        sizePolicy1.setHeightForWidth(btnStop->sizePolicy().hasHeightForWidth());
        btnStop->setSizePolicy(sizePolicy1);
        btnStop->setMinimumSize(QSize(42, 42));
        btnStop->setMaximumSize(QSize(42, 42));
        btnStop->setStyleSheet(QString::fromUtf8(""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Bitmaps/Stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnStop->setIcon(icon5);
        btnStop->setIconSize(QSize(32, 32));
        btnStop->setFlat(false);

        horizontalLayout->addWidget(btnStop);

        horizontalSpacer = new QSpacerItem(13, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ProItemTreeWidget = new QTreeWidget(FlowFrame);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        ProItemTreeWidget->setHeaderItem(__qtreewidgetitem);
        ProItemTreeWidget->setObjectName(QString::fromUtf8("ProItemTreeWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ProItemTreeWidget->sizePolicy().hasHeightForWidth());
        ProItemTreeWidget->setSizePolicy(sizePolicy2);
        ProItemTreeWidget->setStyleSheet(QString::fromUtf8("border:1px solid rgb(220, 220, 220);\n"
"background-color: rgb(240, 248, 226);"));
        ProItemTreeWidget->setFrameShape(QFrame::StyledPanel);
        ProItemTreeWidget->setFrameShadow(QFrame::Sunken);
        ProItemTreeWidget->setColumnCount(1);
        ProItemTreeWidget->header()->setVisible(false);

        verticalLayout_2->addWidget(ProItemTreeWidget);

        dockTabWidget = new QDockWidget(FlowFrame);
        dockTabWidget->setObjectName(QString::fromUtf8("dockTabWidget"));
        sizePolicy.setHeightForWidth(dockTabWidget->sizePolicy().hasHeightForWidth());
        dockTabWidget->setSizePolicy(sizePolicy);
        dockTabWidget->setMinimumSize(QSize(242, 56));
        dockTabWidget->setLayoutDirection(Qt::LeftToRight);
        dockTabWidget->setAutoFillBackground(false);
        dockTabWidget->setStyleSheet(QString::fromUtf8("QDockWidget {\n"
"    background-color: rgba(155, 0, 127,50);       	\n"
"	color: rgb(0, 0, 215);\n"
"}"));
        dockTabWidget->setFeatures(QDockWidget::DockWidgetMovable);
        dockTabWidget->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        dockWidgetContents_2->setMinimumSize(QSize(0, 30));
        dockWidgetContents_2->setLayoutDirection(Qt::LeftToRight);
        dockWidgetContents_2->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(dockWidgetContents_2);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        ProItemTabWidget = new QTabWidget(dockWidgetContents_2);
        ProItemTabWidget->setObjectName(QString::fromUtf8("ProItemTabWidget"));
        ProItemTabWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(ProItemTabWidget->sizePolicy().hasHeightForWidth());
        ProItemTabWidget->setSizePolicy(sizePolicy);
        ProItemTabWidget->setMinimumSize(QSize(240, 0));
        ProItemTabWidget->setAutoFillBackground(false);
        ProItemTabWidget->setStyleSheet(QString::fromUtf8(""));
        ProItemTabWidget->setTabShape(QTabWidget::Rounded);
        ProItemTabWidget->setDocumentMode(true);

        gridLayout_3->addWidget(ProItemTabWidget, 0, 0, 1, 1);

        dockTabWidget->setWidget(dockWidgetContents_2);

        verticalLayout_2->addWidget(dockTabWidget);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(FlowFrame, 0, 0, 1, 1);


        retranslateUi(frmProItemTabClass);

        QMetaObject::connectSlotsByName(frmProItemTabClass);
    } // setupUi

    void retranslateUi(QWidget *frmProItemTabClass)
    {
        frmProItemTabClass->setWindowTitle(QCoreApplication::translate("frmProItemTabClass", "\346\265\201\347\250\213\345\233\276", nullptr));
#if QT_CONFIG(tooltip)
        btnAddProFlow->setToolTip(QCoreApplication::translate("frmProItemTabClass", "\346\267\273\345\212\240\346\265\201\347\250\213", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAddProFlow->setText(QString());
#if QT_CONFIG(tooltip)
        btnDelProFlow->setToolTip(QCoreApplication::translate("frmProItemTabClass", "\345\210\240\351\231\244\346\265\201\347\250\213", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDelProFlow->setText(QString());
#if QT_CONFIG(tooltip)
        btnSetProFlow->setToolTip(QCoreApplication::translate("frmProItemTabClass", "\346\265\201\347\250\213\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSetProFlow->setText(QString());
#if QT_CONFIG(tooltip)
        btnRunOnce->setToolTip(QCoreApplication::translate("frmProItemTabClass", "Once", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRunOnce->setText(QString());
#if QT_CONFIG(tooltip)
        btnRunCycle->setToolTip(QCoreApplication::translate("frmProItemTabClass", "Cycle", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRunCycle->setText(QString());
#if QT_CONFIG(tooltip)
        btnStop->setToolTip(QCoreApplication::translate("frmProItemTabClass", "Stop", nullptr));
#endif // QT_CONFIG(tooltip)
        btnStop->setText(QString());
        dockTabWidget->setWindowTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class frmProItemTabClass: public Ui_frmProItemTabClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPROITEMTAB_H
