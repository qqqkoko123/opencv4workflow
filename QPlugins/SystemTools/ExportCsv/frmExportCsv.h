#pragma once

#include <QDialog>
#include "ui_frmExportCsv.h"
#include "mytitlebar.h"
#include "Toolnterface.h"

struct InitExportCsvData
{
	QVector<int> csv_key;
	QVector<QString> csv_names;
	QString dirPath;
};
Q_DECLARE_METATYPE(InitExportCsvData);

class frmExportCsv : public Toolnterface
{
	Q_OBJECT

public:
	frmExportCsv(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmExportCsv();

private:
	Ui::frmExportCsvClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int InitSetToolData(const QVariant data);
	virtual QVariant InitGetToolData();

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	

private slots:
	void onButtonCloseClicked();
	void timerEvent();

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

private slots:	
	void on_btnExecute_clicked();	
	void on_btnStoragePath_clicked();
	void on_btnAddContent_clicked();
	void on_btnDeleteContent_clicked();
	void on_btnWrite_clicked();
	void on_btnMoveUp_clicked();
	void on_btnMoveDown_clicked();
	void slot_CurrentIndexChanged(int);
	void slot_DoubleClicked(int, int);
	void on_comboTypeBuf_currentIndexChanged(int);

private:
	int RunToolPro();	
	void moveRow(QTableWidget* pTable, int nFrom, int nTo) const;
	bool WriteCSV(const QString pathName, const QMap<int, QString> vector_str);
	bool FindFileForDelete(const QString path, const int day);

private:
	gVariable gvariable;
	int tool_index = 0;
	QString dirPath;
	QStringList strs;
	QList<QString> var_keys;
	QList<QString> keys;  	
	QMap<int, QString> typeNames;
	QMap<int, QString> typeContents;
	int text_index_row;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
