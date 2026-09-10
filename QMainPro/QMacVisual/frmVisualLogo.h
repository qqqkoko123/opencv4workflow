#pragma once

#include <QtWidgets/QWidget>

class frmVisualLogo : public QWidget
{
	Q_OBJECT

public:
	frmVisualLogo(QWidget *parent = Q_NULLPTR);

signals:
	void sig_FormStatues();	

private slots:
	void slot_FormStatues();
	
private:
	void form_statues();		
};
