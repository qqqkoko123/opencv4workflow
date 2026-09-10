#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_frmLogin.h"
#include <QProxyStyle>
#include "basemainwindow.h"
#include "QWorld.h"

class frmLogin : public BaseWindow
{
	Q_OBJECT

public:
	frmLogin(QWidget*parent = Q_NULLPTR);
	~frmLogin();

private:
	Ui::frmLoginClass ui;

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);
	
private slots:		
	void form_load();		
	void on_btnLogout_clicked();
	void on_btnLogout_pressed();
	void on_btnLogout_released();
	void on_btnLogin_clicked();
	void on_btnLogin_pressed();
	void on_btnLogin_released();

signals:
	void sendLoginSignal();
	void sendInStateSignal();
	void sendOutStateSignal();

private:			
	bool bol_query;
};
