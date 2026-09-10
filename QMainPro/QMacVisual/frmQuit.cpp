#include "frmQuit.h"
#include <QTimer>
#include "datavar.h"
#include <winsock2.h>

frmQuit::frmQuit(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/Bitmaps/app.ico"));		
	//执行保存参数信号与槽函数		
	QTimer* p_timer = new QTimer(this);
	connect(p_timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
	p_timer->start(200);			
}

void frmQuit::timerEvent()
{		
	dataVar::comm_state_buf = 1;
	QVector<QString> FlowProItemList_B = QVector<QString>(100);
	for (int i = 0; i < 20; i++)
	{
		FlowProItemList_B.clear();
		switch (i) {
		case 0:
			if (dataVar::fProItemTab->TempDragListWidget_B1 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B1->GetAllItemList_B1();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 1:
			if (dataVar::fProItemTab->TempDragListWidget_B2 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B2->GetAllItemList_B2();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 2:
			if (dataVar::fProItemTab->TempDragListWidget_B3 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B3->GetAllItemList_B3();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 3:
			if (dataVar::fProItemTab->TempDragListWidget_B4 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B4->GetAllItemList_B4();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 4:
			if (dataVar::fProItemTab->TempDragListWidget_B5 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B5->GetAllItemList_B5();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 5:
			if (dataVar::fProItemTab->TempDragListWidget_B6 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B6->GetAllItemList_B6();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 6:
			if (dataVar::fProItemTab->TempDragListWidget_B7 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B7->GetAllItemList_B7();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 7:
			if (dataVar::fProItemTab->TempDragListWidget_B8 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B8->GetAllItemList_B8();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 8:
			if (dataVar::fProItemTab->TempDragListWidget_B9 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B9->GetAllItemList_B9();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 9:
			if (dataVar::fProItemTab->TempDragListWidget_B10 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B10->GetAllItemList_B10();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 10:
			if (dataVar::fProItemTab->TempDragListWidget_B11 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B11->GetAllItemList_B11();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 11:
			if (dataVar::fProItemTab->TempDragListWidget_B12 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B12->GetAllItemList_B12();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 12:
			if (dataVar::fProItemTab->TempDragListWidget_B13 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B13->GetAllItemList_B13();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 13:
			if (dataVar::fProItemTab->TempDragListWidget_B14 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B14->GetAllItemList_B14();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 14:
			if (dataVar::fProItemTab->TempDragListWidget_B15 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B15->GetAllItemList_B15();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 15:
			if (dataVar::fProItemTab->TempDragListWidget_B16 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B16->GetAllItemList_B16();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 16:
			if (dataVar::fProItemTab->TempDragListWidget_B17 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B17->GetAllItemList_B17();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 17:
			if (dataVar::fProItemTab->TempDragListWidget_B18 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B18->GetAllItemList_B18();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 18:
			if (dataVar::fProItemTab->TempDragListWidget_B19 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B19->GetAllItemList_B19();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		case 19:
			if (dataVar::fProItemTab->TempDragListWidget_B20 != nullptr)
			{
				FlowProItemList_B = dataVar::fProItemTab->TempDragListWidget_B20->GetAllItemList_B20();
				QConfig::ToolBase[i]->m_FlowSortList = FlowProItemList_B;
			}			
			break;
		}		
	}	
	//关闭时保存项目
	dataVar::m_pWindow->slot_SaveProjectParam(1);  	
	if (dataVar::bol_connect == true)
	{
		dataVar::bol_connect = false;
		dataVar::sqlite.CloseDB(dataVar::soft_key, dataVar::database);
	}
	//相机
	comm_keys.clear();
	comm_keys = gVariable::camera_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::camera_variable_link.value(key).mindvision_framebuffer_value != nullptr)
		{
			CameraStop(gVariable::camera_variable_link.value(key).mindvision_haldle_value);
			//相机反初始化，释放资源
			CameraUnInit(gVariable::camera_variable_link.value(key).mindvision_haldle_value);
			CameraAlignFree(gVariable::camera_variable_link.value(key).mindvision_framebuffer_value);			
		}
	}	
	//通用I/O
	comm_keys.clear();
	comm_keys = gVariable::generalio_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::generalio_variable_link.value(key).io_value != nullptr)
		{			
			gVariable::generalio_variable_link.value(key).io_value->close();
			gVariable::generalio_variable_link.value(key).io_value->deleteLater();	
			gVariable::GeneralIoVar.connect_state = 0;
			gVariable::GeneralIoVar.io_value = nullptr;
			gVariable::generalio_variable_link.insert(key, gVariable::GeneralIoVar);
		}
	}
	//PLC通信
	comm_keys.clear();
	comm_keys = gVariable::plccommunicate_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::plccommunicate_variable_link.value(key).mit_value != nullptr)
		{
			gVariable::plccommunicate_variable_link.value(key).mit_value->close();
			gVariable::plccommunicate_variable_link.value(key).mit_value->deleteLater();
			gVariable::PlcCommunicateVar.connect_state = 0;
			gVariable::PlcCommunicateVar.mit_value = nullptr;
			gVariable::plccommunicate_variable_link.insert(key, gVariable::PlcCommunicateVar);
		}
	}
	//串口通信
	comm_keys.clear();
	comm_keys = gVariable::serialport_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::serialport_variable_link.value(key).serialport_value != nullptr)
		{			
			gVariable::serialport_variable_link.value(key).serialport_value->close();
			gVariable::serialport_variable_link.value(key).serialport_value->deleteLater();			
		}
	}
	//TCP/IP通信
	comm_keys.clear();
	comm_keys = gVariable::sockettcpserver_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];
		if (gVariable::sockettcpserver_variable_link.value(key).server_value != nullptr)
		{
			gVariable::sockettcpserver_variable_link.value(key).server_value->close();
			gVariable::sockettcpserver_variable_link.value(key).server_value->deleteLater();
		}	
	}
	comm_keys.clear();
	comm_keys = gVariable::sockettcpclient_variable_link.uniqueKeys();
	for (int k = 0; k < comm_keys.length(); k++)
	{
		QString key = comm_keys[k];		
		if (gVariable::sockettcpclient_variable_link.value(key).client_value != nullptr)
		{
			gVariable::sockettcpclient_variable_link.value(key).client_value->close();
			gVariable::sockettcpclient_variable_link.value(key).client_value->deleteLater();
			gVariable::SocketTcpClientVar.connect_state = 0;
			gVariable::SocketTcpClientVar.client_value = nullptr;
			gVariable::sockettcpclient_variable_link.insert(key, gVariable::SocketTcpClientVar);
		}
	}
	//程序关闭记录Log
	emit dataVar::fProItemTab->sig_InfoClick();
	emit dataVar::fProItemTab->sig_Log("主程序关闭...");	
	qApp->quit(); //退出系统，qApp是指向应用程序的全局指针
	//关闭程序进程
	HANDLE hself = GetCurrentProcess();
	TerminateProcess(hself, 0);
}

frmQuit::~frmQuit()
{
	if (this != nullptr)
	{
		this->deleteLater();
	}
}
