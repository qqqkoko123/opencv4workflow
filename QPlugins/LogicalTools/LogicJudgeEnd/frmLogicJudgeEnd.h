#pragma once

#include <QDialog>
#include "ui_frmLogicJudgeEnd.h"
#include "mytitlebar.h"
#include "Toolnterface.h"

class frmLogicJudgeEnd : public Toolnterface
{
	Q_OBJECT

public:
	frmLogicJudgeEnd(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmLogicJudgeEnd();

private:
	Ui::frmLogicJudgeEndClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	

private slots:
	void onButtonCloseClicked();

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

private slots:	
	void on_btnExecute_clicked();
	void on_btnLinkBool_clicked();
	void on_btnDelLinkBool_clicked();
	void on_btnLinkRegex_clicked();
	void on_btnDelLinkRegex_clicked();
	void on_comboType_currentIndexChanged(int index);

private:
	int RunToolPro();	

private:
	gVariable gvariable;
	QStringList strs;
	int tool_index = 0;
	QList<QString> keys;	
	bool state;
	bool var_state;
	int var_state_buf;
	int var_regex;
	int var_regex_buf;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
