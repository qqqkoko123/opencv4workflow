#pragma once

#include <QDialog>
#include "ui_frmDelayTool.h"
#include <QButtonGroup>
#include "mytitlebar.h"
#include "Toolnterface.h"

class frmDelayTool : public Toolnterface
{
	Q_OBJECT

public:
	frmDelayTool(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmDelayTool();

private:
	Ui::frmDelayToolClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	

private slots:
	void onButtonCloseClicked();
	void onRadioClick(bool);

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

private slots:	
	void on_btnExecute_clicked();	

private:
	int RunToolPro();	

private:		
	gVariable gvariable;
	QButtonGroup* btnGroupRadio;
	int tool_index = 0;
	int radio_index;
};
