/********************************************************************************
** Form generated from reading UI file 'frmToolsTree.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMTOOLSTREE_H
#define UI_FRMTOOLSTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmToolsTreeClass
{
public:
    QGridLayout *gridLayout;
    QFrame *ToolTreeFrame;

    void setupUi(QWidget *frmToolsTreeClass)
    {
        if (frmToolsTreeClass->objectName().isEmpty())
            frmToolsTreeClass->setObjectName(QString::fromUtf8("frmToolsTreeClass"));
        frmToolsTreeClass->resize(250, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frmToolsTreeClass->sizePolicy().hasHeightForWidth());
        frmToolsTreeClass->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        frmToolsTreeClass->setFont(font);
        frmToolsTreeClass->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 248, 226);"));
        gridLayout = new QGridLayout(frmToolsTreeClass);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 8, 0, 0);
        ToolTreeFrame = new QFrame(frmToolsTreeClass);
        ToolTreeFrame->setObjectName(QString::fromUtf8("ToolTreeFrame"));
        ToolTreeFrame->setFont(font);
        ToolTreeFrame->setStyleSheet(QString::fromUtf8(""));
        ToolTreeFrame->setFrameShape(QFrame::StyledPanel);
        ToolTreeFrame->setFrameShadow(QFrame::Raised);
        ToolTreeFrame->setLineWidth(1);

        gridLayout->addWidget(ToolTreeFrame, 0, 0, 1, 1);


        retranslateUi(frmToolsTreeClass);

        QMetaObject::connectSlotsByName(frmToolsTreeClass);
    } // setupUi

    void retranslateUi(QWidget *frmToolsTreeClass)
    {
        frmToolsTreeClass->setWindowTitle(QCoreApplication::translate("frmToolsTreeClass", "\345\267\245\345\205\267\347\256\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmToolsTreeClass: public Ui_frmToolsTreeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMTOOLSTREE_H
