#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OCR.h"

class OCR : public QMainWindow
{
    Q_OBJECT

public:
    OCR(QWidget *parent = nullptr);
    ~OCR();

private:
    Ui::OCRClass ui;
};

