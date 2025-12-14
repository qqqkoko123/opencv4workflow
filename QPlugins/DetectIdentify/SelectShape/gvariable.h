#pragma once

#include <QMap>
#include <QPoint>
#include <QPointF>
#include <opencv2\opencv.hpp>

class QToolBase;

class gVariable 
{	
public:		
	//定义全局变量结构体
	typedef struct GLOBALVAR
	{		
		QString global_type;
		int global_int_value;		
		double global_double_value;		
		QString global_qstring_value;		
		bool global_bool_value;		
		QPoint global_qpoint_value;		
		QPointF global_qpointf_value;
		cv::Point global_cvpoint_value;
		cv::Point2f global_cvpoint2f_value;
		cv::Point3f global_cvpoint3f_value;
		cv::Point3d global_cvpoint3d_value;
		std::vector<float> global_array_float_value;
		std::vector<double> global_array_double_value;
	} Global_Var;
	Global_Var GlobalVar;
	QMap<QString, Global_Var> global_variable_link;	
	//定义跳转工具结构体
	typedef struct GOTOVAR
	{		
		std::vector<QString> goto_array_name_value;		
	} Goto_Var;
	Goto_Var GotoVar;
	QMap<QString, Goto_Var> goto_variable_link;
	//定义通讯结构体
	typedef struct CAMERAVAR  //相机
	{
		
	} Camera_Var;
	Camera_Var CameraVar;
	QMap<QString, Camera_Var> camera_variable_link;
	typedef struct GENERALIOVAR  //通用I/O
	{
		
	} GeneralIo_Var;
	GeneralIo_Var GeneralIoVar;
	QMap<QString, GeneralIo_Var> generalio_variable_link;
	typedef struct PLCCOMMUNICATEVAR  //PLC通信
	{
		
	} PlcCommunicate_Var;
	PlcCommunicate_Var PlcCommunicateVar;
	QMap<QString, PlcCommunicate_Var> plccommunicate_variable_link;
	typedef struct SERIALPORTVAR  //串口通信
	{
		
	} SerialPort_Var;
	SerialPort_Var SerialPortVar;
	QMap<QString, SerialPort_Var> serialport_variable_link;
	typedef struct SOCKETTCPSERVERVAR  //TCP/IP服务器
	{
		
	} SocketTcpServer_Var;
	SocketTcpServer_Var SocketTcpServerVar;
	QMap<QString, SocketTcpServer_Var> sockettcpserver_variable_link;
	typedef struct SOCKETTCPCLIENTVAR  //TCP/IP客户端
	{
		
	} SocketTcpClient_Var;
	SocketTcpClient_Var SocketTcpClientVar;
	QMap<QString, SocketTcpClient_Var> sockettcpclient_variable_link;
	typedef struct SCRIPTEDITVAR  //脚本编辑
	{

	} ScriptEdit_Var;
	ScriptEdit_Var ScriptEditVar;
	QMap<QToolBase*, ScriptEdit_Var> scriptedit_variable_link;
};
