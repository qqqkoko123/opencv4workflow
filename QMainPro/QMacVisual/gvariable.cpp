#include "gvariable.h"

//定义全局变量结构体
gVariable::Global_Var gVariable::GlobalVar;
QMap<QString, gVariable::Global_Var> gVariable::global_variable_link = QMap<QString, gVariable::Global_Var>();
//定义跳转工具结构体
gVariable::Goto_Var gVariable::GotoVar;
QMap<QString, gVariable::Goto_Var> gVariable::goto_variable_link = QMap<QString, gVariable::Goto_Var>();
//定义通讯结构体
gVariable::Camera_Var gVariable::CameraVar;  //相机
QMap<QString, gVariable::Camera_Var> gVariable::camera_variable_link = QMap<QString, gVariable::Camera_Var>();
gVariable::GeneralIo_Var gVariable::GeneralIoVar;  //通用I/O
QMap<QString, gVariable::GeneralIo_Var> gVariable::generalio_variable_link = QMap<QString, gVariable::GeneralIo_Var>();
gVariable::PlcCommunicate_Var gVariable::PlcCommunicateVar;  //PLC通信
QMap<QString, gVariable::PlcCommunicate_Var> gVariable::plccommunicate_variable_link = QMap<QString, gVariable::PlcCommunicate_Var>();
gVariable::SerialPort_Var gVariable::SerialPortVar;  //串口通信
QMap<QString, gVariable::SerialPort_Var> gVariable::serialport_variable_link = QMap<QString, gVariable::SerialPort_Var>();
gVariable::SocketTcpServer_Var gVariable::SocketTcpServerVar;  //TCP/IP服务器
QMap<QString, gVariable::SocketTcpServer_Var> gVariable::sockettcpserver_variable_link = QMap<QString, gVariable::SocketTcpServer_Var>();
gVariable::SocketTcpClient_Var gVariable::SocketTcpClientVar;  //TCP/IP客户端
QMap<QString, gVariable::SocketTcpClient_Var> gVariable::sockettcpclient_variable_link = QMap<QString, gVariable::SocketTcpClient_Var>();
gVariable::ScriptEdit_Var gVariable::ScriptEditVar;  //脚本编辑
QMap<QToolBase*, gVariable::ScriptEdit_Var> gVariable::scriptedit_variable_link = QMap<QToolBase*, gVariable::ScriptEdit_Var>();
