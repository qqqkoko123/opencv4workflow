#pragma once

#include <QDialog>
#include "ui_frmExtensionLibrary.h"
#include "mytitlebar.h"
#include "Toolnterface.h"

struct InitExtensionLibraryData
{	
	QString image_link;
	QString dirPath;
};
Q_DECLARE_METATYPE(InitExtensionLibraryData);

//动态库--耗时函数
typedef int (*GetCostE)();

class frmExtensionLibrary : public Toolnterface
{
	Q_OBJECT

public:
	frmExtensionLibrary(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmExtensionLibrary();

private:
	Ui::frmExtensionLibraryClass ui;

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

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

signals:
	void sig_Message();	

private slots:	
	void slot_Message();
	void on_btnLinkImage_clicked();
	void on_btnDelLinkImage_clicked();
	void on_btnPath_clicked();
	void on_btnSet_clicked();

private:	
	gVariable gvariable;
	Toolnterface* frmPage = nullptr;	
	QString sToolName;
	QToolBase* sToolBase;
	QStringList strs;	
	QString dirPath;
	QString str_img_link;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
