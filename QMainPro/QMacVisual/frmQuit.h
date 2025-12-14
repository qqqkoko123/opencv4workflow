#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_frmQuit.h"
#include <QProxyStyle>

class frmQuit : public QWidget
{
	Q_OBJECT

public:
	frmQuit(QWidget*parent = Q_NULLPTR);
	~frmQuit();

private:
	Ui::frmQuitClass ui;

private slots:
	void timerEvent();

private:
	QList<QString> comm_keys;
};
