#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_frmPermis.h"
#include <QProxyStyle>
#include "basemainwindow.h"
#include "QWorld.h"

class frmPermis : public BaseWindow
{
	Q_OBJECT

public:
	frmPermis(QWidget*parent = Q_NULLPTR);
	~frmPermis();

private:
	Ui::frmPermisClass ui;
	
private slots:			
	void on_btnAdd_clicked();
	void on_btnAdd_pressed();
	void on_btnAdd_released();
	void on_btnDelete_clicked();
	void on_btnDelete_pressed();
	void on_btnDelete_released();
	void on_btnQuery_clicked();
	void on_btnQuery_pressed();
	void on_btnQuery_released();

private:			
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	
	bool bol_query;
	bool bol_delete;
	bool bol_add;
};
