/********************************************************************************
** Form generated from reading UI file 'frmImageView.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMIMAGEVIEW_H
#define UI_FRMIMAGEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewClass
{
public:

    void setupUi(QWidget *ImageViewClass)
    {
        if (ImageViewClass->objectName().isEmpty())
            ImageViewClass->setObjectName(QString::fromUtf8("ImageViewClass"));
        ImageViewClass->resize(1060, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageViewClass->sizePolicy().hasHeightForWidth());
        ImageViewClass->setSizePolicy(sizePolicy);
        ImageViewClass->setMinimumSize(QSize(0, 0));
        ImageViewClass->setMaximumSize(QSize(16777215, 16777215));

        retranslateUi(ImageViewClass);

        QMetaObject::connectSlotsByName(ImageViewClass);
    } // setupUi

    void retranslateUi(QWidget *ImageViewClass)
    {
        ImageViewClass->setWindowTitle(QCoreApplication::translate("ImageViewClass", "ImageView", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageViewClass: public Ui_ImageViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMIMAGEVIEW_H
