#pragma once

#include <QDialog>
#include "ui_frmImageLayout.h"
#include <QButtonGroup>
#include "mytitlebar.h"

class frmImageLayout : public QDialog
{
	Q_OBJECT

public:
	frmImageLayout(QWidget* parent = Q_NULLPTR);
	~frmImageLayout();

private:
	Ui::frmImageLayoutClass ui;

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	

signals:
	void sig_Image1();
	void sig_Image2();
	void sig_Image3();
	void sig_Image4();
	void sig_Image6A();
	void sig_Image6B();
	void sig_Image9();

private slots:
	void onButtonCloseClicked();
	void slot_Image(bool);

private:	
	QButtonGroup* btnGroupRadio;	
};
