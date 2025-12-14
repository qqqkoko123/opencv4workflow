#pragma once

#include <QDialog>
#include "ui_frmPlcCommunicate.h"
#include <QButtonGroup>
#include "mytitlebar.h"
#include "Toolnterface.h"

struct InitPlcCommunicateData
{
	int plc_index;
	QVector<QString> plc_tools;
	QVector<QString> plc_key;
	QVector<QString> mit_code;
	QVector<QString> mit_state;
	QVector<QString> mit_method;
	QVector<QString> mit_address;
	QVector<QString> mit_data;	
};
Q_DECLARE_METATYPE(InitPlcCommunicateData);

class frmPlcCommunicate : public Toolnterface
{
	Q_OBJECT

public:
	frmPlcCommunicate(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmPlcCommunicate();

private:
	Ui::frmPlcCommunicateClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int ExecutePlcCommunicateLink(const QMap<QString, gVariable::PlcCommunicate_Var> plccommunicate_var_link);	
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
	void on_btnAddRegister_clicked();
	void on_btnDeleteRegister_clicked();	
	void on_btnLinkMitRegisterData_clicked();
	void on_btnDelLinkMitRegisterData_clicked();
	void on_btnMitSave_clicked();
	void on_btnMitBack_clicked();
	bool InovancePLC_connect(QString key);
	void on_comboCommName_currentIndexChanged(int index);
	void slot_PlcDoubleClicked(int, int);

private slots:
	void onRadioClick();
	void slot_MitRegisterAddress(QString text);	

private:
	int RunToolPro();

	void disconnect(QString key);

	bool writeRegister(int num, int value, QString key);

	int readRegister(int num, QString key, int nb);

private:
	gVariable gvariable;
	QStringList strs;
	QButtonGroup* btnGroupRadio;
	int tool_index = 0;
	QList<QString> global_keys;
	QList<QString> keys;
	QList<QString> register_keys;
	QTcpSocket* plc_tcp_client = nullptr;	
	int choose_index = -10000;
	int choose_num;		
	int plc_tcp_state;
	int register_index_row;
	QList<int> m_process_buf;
	int table_buf = 0;
	QVector<int> RegisterReadData;  //寄存器读取数据
	QVector<int> RegisterWriteData;  //寄存器写入数据
	QString RegisterAddress_buf;
	QThread* h1, * h2;
	
signals:
	//三菱PLC
	bool sig_AsciiWrite1D(QTcpSocket* m_socket, QString device, short value);
	bool sig_AsciiRead1D(QTcpSocket* m_socket, QString device, short& value);
	bool sig_AsciiWrite2D(QTcpSocket* m_socket, QString device, int value);
	bool sig_AsciiRead2D(QTcpSocket* m_socket, QString device, int& value);
	bool sig_BinaryWrite1D(QTcpSocket* m_socket, string device, short value);
	bool sig_BinaryWrite2D(QTcpSocket* m_socket, string device, int value);
	bool sig_BinaryRead1D(QTcpSocket* m_socket, string device, short& value);
	bool sig_BinaryRead2D(QTcpSocket* m_socket, string device, int& value);

private slots:
	//三菱PLC
	bool AsciiWrite1D(QTcpSocket* m_socket, QString device, short value);
	bool AsciiRead1D(QTcpSocket* m_socket, QString device, short& value);
	bool AsciiWrite2D(QTcpSocket* m_socket, QString device, int value);
	bool AsciiRead2D(QTcpSocket* m_socket, QString device, int& value);
	bool BinaryWrite1D(QTcpSocket* m_socket, string device, short value);
	bool BinaryWrite2D(QTcpSocket* m_socket, string device, int value);
	bool BinaryRead1D(QTcpSocket* m_socket, string device, short& value);
	bool BinaryRead2D(QTcpSocket* m_socket, string device, int& value);

private:
	//三菱PLC	
	void AsciiDWordToSWord(int int32Num, int& int16Num_L, int& int16Num_H);	
	void AsciiSWordToDWord(int int16Num_L, int int16Num_H, int& int32Num);
	string& std_string_format(string& _str, const char* _Format, ...);
	string Int16ToHexConvert(short va);
	string Int32ToHexConvert(int va);
	string Int48ToHexConvert(int64 va);
	string Int64ToHexConvert(int64 va);
	string Int32ToHexConvert2(int va);
	bool BinarySendMessg(QTcpSocket* m_socket, string msg);
	string BinaryReceiveMsg(QTcpSocket* m_socket);	

private:
	typedef struct MITREGISTERCONTENT
	{
		QString mit_code;
		QString mit_state;
		QString mit_method;
		QString mit_address;
		QString mit_data;		
	} MitRegister_Content;
	MitRegister_Content MitRegisterContent;
	QMap<QString, MitRegister_Content> global_mit_register_content;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
