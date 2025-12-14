#pragma once

#include <QtWidgets/QWidget>
#include "ui_frmRegister.h"
#include "frmVisualLogo.h"
#include "qprocess.h"
#include <QSettings>
#include <QMessageBox>
#include <QTimer>
#include <QCryptographicHash>

static int form_state;

class frmRegister : public QWidget
{
	Q_OBJECT

public:
	frmRegister(QWidget *parent = Q_NULLPTR);
	
private:
	Ui::frmRegisterClass ui;
	   
private slots:
	void form_statues();
	void on_btnCmdCheckID_clicked();
	void on_btnCmdCheckID_pressed();
	void on_btnCmdCheckID_released();
	QString GetKey(QString str);
	QString getWMIC(const QString& cmd);
	QString getCpuSerialNumber();
	QString getMotherboardSerialNumber();
	QString getBIOSSerialNumber();
	QString getDiskSerialNumber();

private:
	QTimer *m_timer;	
	QString str_input;
	QString value;	
	QString str_key;
};
