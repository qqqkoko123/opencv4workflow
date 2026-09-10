#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_frmAbout.h"
#include <QProxyStyle>
#include "basemainwindow.h"

class frmAbout : public BaseWindow
{
	Q_OBJECT

public:
	frmAbout(QWidget*parent = Q_NULLPTR);
	~frmAbout();

private:
	Ui::frmAboutClass ui;

private:		
	void initTitleBar();	
	void paintEvent(QPaintEvent* event);
};
