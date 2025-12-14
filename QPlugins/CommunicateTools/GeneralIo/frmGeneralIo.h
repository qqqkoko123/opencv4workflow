#pragma once

#include <QDialog>
#include "ui_frmGeneralIo.h"
#include "mytitlebar.h"
#include "Toolnterface.h"

struct InitGeneralIoData
{
	int io_index;
	QVector<QString> io_tools;
};
Q_DECLARE_METATYPE(InitGeneralIoData);

class frmGeneralIo : public Toolnterface
{
	Q_OBJECT

public:
	frmGeneralIo(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmGeneralIo();

private:
	Ui::frmGeneralIoClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int ExecuteGeneralIoLink(const QMap<QString, gVariable::GeneralIo_Var> generalio_var_link);
	virtual int InitSetToolData(const QVariant data);
	virtual QVariant InitGetToolData();

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
	void on_btnUpdata_clicked();

private:
	int RunToolPro();		

private:
	gVariable gvariable;
	int tool_index = 0;
	QVector<bool> InPutIoX = QVector<bool>(8);	
};
