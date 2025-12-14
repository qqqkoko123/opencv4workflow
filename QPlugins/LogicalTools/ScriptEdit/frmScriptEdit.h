#pragma once

#include <QDialog>
#include "ui_frmScriptEdit.h"
#include "mytitlebar.h"
#include "Toolnterface.h"
#include <QTextCodec>
#include <QCompleter>
#include <QTreeWidget>
#include <QtScript>
#include <QStandardItemModel>
#include <QGridLayout>
#include <QMetaType>
#include "highlighter.h"

typedef std::pair<QString, std::list<QString>> ToolsPair;

#pragma region 获取全局变量值
struct Point3f  //cv::Point3f类型
{
	float x = 0;
	float y = 0;
	float z = 0;
};
Q_DECLARE_METATYPE(Point3f);

struct Point3d  //cv::Point3d类型
{
	double x = 0;
	double y = 0;
	double z = 0;
}; 
Q_DECLARE_METATYPE(Point3d);

struct ArrayFloat  //Float[]类型
{
	QVector<float> g_array_f;
}; 
Q_DECLARE_METATYPE(ArrayFloat);

struct ArrayDouble  //Double[]类型
{
	QVector<double> g_array_d;
}; 
Q_DECLARE_METATYPE(ArrayDouble);
#pragma endregion

#pragma region 获取工具变量值
struct ArrayQString  //vector<QString>类型
{
	vector<QString> t_array_string;
};
Q_DECLARE_METATYPE(ArrayQString);

struct ToolArrayDouble  //vector<double>类型
{
	vector<double> t_array_d;
};
Q_DECLARE_METATYPE(ToolArrayDouble);

struct ArrayCvPoint2f  //vector<cv::Point2f>类型
{
	vector<cv::Point2f> t_array_points;
};
Q_DECLARE_METATYPE(ArrayCvPoint2f);

struct ArrayInt  //QVector<int>类型
{
	QVector<int> t_array_int;
};
Q_DECLARE_METATYPE(ArrayInt);

struct ArrayBool  //QVector<bool>类型
{
	QVector<bool> t_array_bool;
};
Q_DECLARE_METATYPE(ArrayBool);
#pragma endregion

class frmScriptEdit : public Toolnterface
{
	Q_OBJECT

public:	
	frmScriptEdit(QString toolName = QString(), QToolBase* toolBase = Q_NULLPTR, QWidget* parent = Q_NULLPTR);
	~frmScriptEdit();

private:
	Ui::frmScriptEditClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int ExecuteScriptEditLink(const QMap<QToolBase*, gVariable::ScriptEdit_Var> scriptedit_var_link);	
	
private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	

private slots:
	void onButtonCloseClicked();

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

private slots:	
	void on_btnCompile_clicked();
	void on_btnExecute_clicked();
	void slot_ItemDoubleClicked(QTreeWidgetItem* item, int column);
	void slot_CreateList();
	void slot_ListClick(QModelIndex);
	void slot_DoubleClicked(int, int);
	void slot_Accepted();
	void slot_ScriptError(QScriptEngine* script_engine, QString str_code, QScriptValue result);

signals:
	void sig_UpdateQTreeWidget(QString, QString);
	void sig_ScriptError(QScriptEngine* script_engine, QString str_code, QScriptValue result);

private:
	int RunToolPro();
	void form_load();
	void ToolsTreeWidgetInit();
	QString GetIconName(QString Name);
	QPixmap GetIcon(QString fileName);
	
private:	
	gVariable gvariable;
	int tool_index = 0;
	QCompleter* completer = nullptr;
	Highlighter* highlighter = nullptr;
	QTreeWidget* ToolTreeWidget;
	std::vector<ToolsPair> ToolNamesVec;
	std::list<QString> ToolNameList;		
	QStandardItemModel* ItemModel;
	int index_process_modify;
	QString tool_name;
	QList<QString> g_keys;
	QList<QToolBase*> script_keys;
	QTableWidgetItem* item_number;
	QTableWidgetItem* item_variable_name;
	QTableWidgetItem* item_variable_value;
	QTableWidgetItem* item_variable_type;
	int row_count;
	QString script_link;		
	QScriptEngine script_engine;
};

//图形字体处理类
class IconHelpers : public QObject
{
	Q_OBJECT

public:
	static IconHelpers* Instance();
	explicit IconHelpers(QObject* parent = 0);

	QPixmap getPixmap(QString& fileName);

private:
	static IconHelpers* self;    //对象自身
	QFont iconFont;             //图形字体    
};

//全局变量控制
class QConfig
{
public:
	static QToolBase* flowToolBase_B1;
	static QToolBase* flowToolBase_B2;
	static QToolBase* flowToolBase_B3;
	static QToolBase* flowToolBase_B4;
	static QToolBase* flowToolBase_B5;
	static QToolBase* flowToolBase_B6;
	static QToolBase* flowToolBase_B7;
	static QToolBase* flowToolBase_B8;
	static QToolBase* flowToolBase_B9;
	static QToolBase* flowToolBase_B10;
	static QToolBase* flowToolBase_B11;
	static QToolBase* flowToolBase_B12;
	static QToolBase* flowToolBase_B13;
	static QToolBase* flowToolBase_B14;
	static QToolBase* flowToolBase_B15;
	static QToolBase* flowToolBase_B16;
	static QToolBase* flowToolBase_B17;
	static QToolBase* flowToolBase_B18;
	static QToolBase* flowToolBase_B19;
	static QToolBase* flowToolBase_B20;
	static int tool_result;	
	static int g_flow_index;
};
