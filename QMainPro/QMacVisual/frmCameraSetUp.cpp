#include "frmCameraSetUp.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QDesktopWidget>
#include <QPainter>
#include <QWidgetAction>
#include <QElapsedTimer>
#include "datavar.h"
#include "MvCameraControl.h"
#include "gvariable.h"
frmCameraSetUp::frmCameraSetUp(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	//FramelessWindowHint属性设置窗口去除边框
	//WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	//设置窗体在屏幕中间位置
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	//设置窗口背景透明
	setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/res/ico/cam.png"));
	//初始化标题栏
	initTitleBar();
	//设置表格列宽	
	ui.tableWidget->setColumnWidth(0, 256);
	//隐藏水平header
	ui.tableWidget->verticalHeader()->setVisible(false);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置只能单选
	connect(ui.tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_DoubleClicked(int, int)));
	ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
	ui.tableWidget->setItemDelegateForColumn(0, readOnlyDelegate); //设置第1列只读	
	//添加右键菜单
	AddRightButtonMenu();
	mindvision_camera_state = 0;
}

frmCameraSetUp::~frmCameraSetUp()
{	
	this->deleteLater();
}

void frmCameraSetUp::initTitleBar()
{
	MyTitleBar* m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setBackgroundColor(3, 110, 95);
	m_titleBar->setStyleSheet("background-color: rgba(0, 0, 0,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/res/ico/cam.png");
	m_titleBar->setTitleContent("相机设置");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmCameraSetUp::paintEvent(QPaintEvent* event)
{
	//设置背景色
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor("#bcc2bc")));
	return QWidget::paintEvent(event);
}

void frmCameraSetUp::onButtonCloseClicked()
{
	this->close();
}

//右键菜单
void frmCameraSetUp::AddRightButtonMenu()
{
	QMenu* m_menu = new QMenu(this);
	//菜单样式
	QString menuStyle(
		"QMenu::item{"
		"color: rgb(0, 0, 0);"
		"}"
		"QMenu::item:hover{"
		"background-color: rgb(176, 190, 225);"
		"}"
		"QMenu::item:selected{"
		"background-color: rgb(176, 190, 225);"
		"}"
	);
	QString buttonStyle(
		"QPushButton{"
		"color: rgb(0, 0, 0);"
		"border: none;"
		"text-align: left;"
		"font: 9pt Microsoft YaHei;"
		"padding-left: 5px;"
		"padding-right: 5px;"
		"min-height: 23px;"
		"}"
		"QPushButton::hover{"
		"background-color: rgba(176, 190, 225, 200);"
		"}"
		"QPushButton::selected{"
		"background-color: rgba(176, 190, 255, 255);"
		"}"
	);
	m_menu->setStyleSheet(menuStyle);
	QPushButton* moveUpAction_buf = new QPushButton(m_menu);
	moveUpAction_buf->setStyleSheet(buttonStyle);
	moveUpAction_buf->setText("上移");
	moveUpAction_buf->setIconSize(QSize(20, 20));
	moveUpAction_buf->setIcon(QIcon(":/res/ico/previous.png"));
	QWidgetAction* moveUpAction = new QWidgetAction(this);
	moveUpAction->setDefaultWidget(moveUpAction_buf);
	connect(moveUpAction_buf, &QPushButton::clicked, this, &frmCameraSetUp::slot_MoveUp);
	connect(moveUpAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(moveUpAction);
	QPushButton* moveDownAction_buf = new QPushButton(m_menu);
	moveDownAction_buf->setStyleSheet(buttonStyle);
	moveDownAction_buf->setText("下移");
	moveDownAction_buf->setIconSize(QSize(20, 20));
	moveDownAction_buf->setIcon(QIcon(":/res/ico/next.png"));
	QWidgetAction* moveDownAction = new QWidgetAction(this);
	moveDownAction->setDefaultWidget(moveDownAction_buf);
	connect(moveDownAction_buf, &QPushButton::clicked, this, &frmCameraSetUp::slot_MoveDown);
	connect(moveDownAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(moveDownAction);
	QPushButton* deleteNameAction_buf = new QPushButton(m_menu);
	deleteNameAction_buf->setStyleSheet(buttonStyle);
	deleteNameAction_buf->setText("删除");
	deleteNameAction_buf->setIconSize(QSize(21, 21));
	deleteNameAction_buf->setIcon(QIcon(":/res/ico/del.png"));
	QWidgetAction* deleteNameAction = new QWidgetAction(this);
	deleteNameAction->setDefaultWidget(deleteNameAction_buf);
	connect(deleteNameAction_buf, &QPushButton::clicked, this, &frmCameraSetUp::slot_DeleteName);
	connect(deleteNameAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(deleteNameAction);
	//给控件设置上下文菜单策略
	ui.tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	//给信号设置相应的槽函数
	connect(ui.tableWidget, &QTableWidget::customContextMenuRequested, [=](const QPoint& pos)
		{
			//参数pos用来传递右键点击时的鼠标的坐标，这个坐标一般是相对于控件左上角
			m_menu->exec(QCursor::pos());
		});
}

void frmCameraSetUp::on_btnAddCamera_clicked()
{
	if (ui.comboCameraName->currentText() == QString())
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("未找到或选择相机！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "未找到或选择相机！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
		return;
	}
	else
	{
		int count = ui.tableWidget->rowCount();
		QString cam_name = ui.comboCamera->currentText() + "_" + ui.comboCameraName->currentText();
		for (int m = 0; m < count; m++)
		{
			if (cam_name == ui.tableWidget->item(m, 0)->text())
			{
				emit dataVar::fProItemTab->sig_ErrorClick();
				emit dataVar::fProItemTab->sig_Log("已存在该相机名称！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "已存在该相机名称！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return;
			}
		}
		ui.tableWidget->setRowCount(count + 1);  //设置行数		
		QTableWidgetItem* item_type = new QTableWidgetItem(cam_name);
		item_type->setFlags(item_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
		ui.tableWidget->setItem(count, 0, item_type);
	}
}

void frmCameraSetUp::on_btnSearchCamera_clicked()
{
	//搜索相机
	ui.comboCameraName->clear();	
	switch (ui.comboCamera->currentIndex()) {
	case 0:	
		tSdkCameraDevInfo sCameraList_buf[9];
		iCameraNums = 9;		
		//返回的相机信息列表，会根据acFriendlyName排序
		if (CameraEnumerateDevice(sCameraList_buf, &iCameraNums) != CAMERA_STATUS_SUCCESS || iCameraNums == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("未搜索到迈德威视相机！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未搜索到迈德威视相机！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
		sCameraList.clear();
		for (int i = 0; i < iCameraNums; i++)
		{
			sCameraList.append(sCameraList_buf[i]);
			ui.comboCameraName->addItem(sCameraList_buf[i].acFriendlyName);
		}
		break;
	case 1:
		//海康威视
		MV_CC_DEVICE_INFO_LIST stDeviceList; // 存储设备列表的结构体
		memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST)); // 初始化清零

		// 枚举设备（支持GigE网口和USB设备）
		int nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &stDeviceList);
		if (nRet == MV_OK && stDeviceList.nDeviceNum > 0) {
			for (unsigned int i = 0; i < stDeviceList.nDeviceNum; i++) {
				MV_CC_DEVICE_INFO* pDeviceInfo = stDeviceList.pDeviceInfo[i];
				// 判断设备类型（GigE/USB）
				if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE) {
					std::cout << "GigE相机IP: "
						<< pDeviceInfo->SpecialInfo.stGigEInfo.nCurrentIp << std::endl;
				}
				else if (pDeviceInfo->nTLayerType == MV_USB_DEVICE) {
					std::cout << "USB相机序列号: "
						<< pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber << std::endl;
				}
			}
		}
		else {
			std::cerr << "未找到设备或枚举失败！错误码: " << nRet << std::endl;
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未搜索到海康威视相机！");
		}

		hCameraList.clear();
		hCameraList.append(stDeviceList);
		for (int i = 0; i < stDeviceList.nDeviceNum; i++)
		{
			/*unsigned char* pch = (unsigned char*)&stDeviceList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp;
			char szIPAddr[64] = { 0 };
			sprintf(szIPAddr, "%d.%d.%d.%d", *(pch + 3), *(pch + 2), *(pch + 1), *(pch));*/
			ui.comboCameraName->addItem(IPIntToStr(stDeviceList.pDeviceInfo[i]->SpecialInfo.stGigEInfo.nCurrentIp));
		}
		break;
	}
}
QString frmCameraSetUp::IPIntToStr(uint32_t ipInt)
{

	QString ipA = QString::number(ipInt >> 24);
	QString ipB = QString::number((ipInt & 0x00FFFFFF) >> 16);
	QString ipC = QString::number((ipInt & 0x0000FFFF) >> 8);
	QString ipD = QString::number(ipInt & 0x000000FF);

	//QString ipStr = ipA + "." + ipB + "." + ipC + "." + ipD;
	QString ipStr = ipD + "." + ipC + "." + ipB + "." + ipA;
	return ipStr;
}
void frmCameraSetUp::on_btnConnect_clicked()
{
	//连接相机	
	if (ui.lblType->text() == QString())
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("选择相机名称为空！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "选择相机名称为空！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	QStringList strs = ui.lblType->text().split("_");
	if (strs[0] == "MindVision")
	{
		//迈德威视
		camera_keys.clear();
		camera_keys = global_camera_content.uniqueKeys();
		int count = 0;
		int ccd_Index = 0;
		for (int k = 0; k < camera_keys.length(); k++)
		{
			QString key = camera_keys[k];
			if (key == ui.lblType->text())
			{
				ccd_Index = k;
				count = 1;
				ui.spinExposure->setValue(global_camera_content.value(key).global_exposure);
				ui.spinGain->setValue(global_camera_content.value(key).global_gain);
				ui.spinGamma->setValue(global_camera_content.value(key).global_gamma);
				ui.spinContrast->setValue(global_camera_content.value(key).global_contrast);
				ui.comboTriggerMode->setCurrentText(global_camera_content.value(key).global_trigger_mode);
				ui.spinTimeOut->setValue(global_camera_content.value(key).global_timeout);
				CameraContent.ccd_index = ccd_Index;
				global_camera_content.insert(key, CameraContent);
				break;
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该相机参数未保存！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该相机参数未保存！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
		for (int n = 0; n < dataVar::camera_state.count(); n++)
		{
			if (dataVar::camera_state[n] == ui.lblType->text())
			{
				emit dataVar::fProItemTab->sig_ErrorClick();
				emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "相机已连接！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + "相机已连接！");
				msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
				msgBox.exec();
				return;
			}
		}
		//初始化相机，(-1,-1)表示加载上次退出前保存的参数，如果是第一次使用该相机，则加载默认参数
		if ((status = CameraInit(&sCameraList[ccd_Index], -1, -1, &mindvision_haldle)) != CAMERA_STATUS_SUCCESS)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("初始化相机失败！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "初始化相机失败！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
		//获得该相机的特性描述
		CameraGetCapability(mindvision_haldle, &sCameraInfo);
		mindvision_framebuffer = (BYTE*)CameraAlignMalloc(sCameraInfo.sResolutionRange.iWidthMax * sCameraInfo.sResolutionRange.iWidthMax * 3, 16);
		//设置曝光
		CameraSetAeState(mindvision_haldle, false);
		CameraSetExposureTime(mindvision_haldle, ui.spinExposure->value());
		//设置增益
		CameraSetAnalogGain(mindvision_haldle, ui.spinGain->value());
		//设置伽马
		CameraSetGamma(mindvision_haldle, ui.spinGamma->value() * 100);
		//设置对比度
		CameraSetContrast(mindvision_haldle, ui.spinContrast->value());
		//设置触发模式
		int iModeSel = 0;
		if (ui.comboTriggerMode->currentIndex() == 0)
		{
			iModeSel = 0;
		}
		else if (ui.comboTriggerMode->currentIndex() == 1)
		{
			iModeSel = 1;
		}
		else if (ui.comboTriggerMode->currentIndex() == 2)
		{
			iModeSel = 2;
		}
		CameraSetTriggerMode(mindvision_haldle, iModeSel);
		//保存当前相机参数到指定的参数组中
		CameraSaveParameter(mindvision_haldle, 0);
		if (sCameraInfo.sIspCapacity.bMonoSensor)
		{
			CameraSetIspOutFormat(mindvision_haldle, CAMERA_MEDIA_TYPE_MONO8);
		}
		CameraPlay(mindvision_haldle);
		gVariable::CameraVar.camera_type = "MindVision";
		gVariable::CameraVar.mindvision_haldle_value = mindvision_haldle;
		gVariable::CameraVar.mindvision_framebuffer_value = mindvision_framebuffer;
		gVariable::CameraVar.time_out = ui.spinTimeOut->value();
		gVariable::camera_variable_link.insert(ui.lblType->text(), gVariable::CameraVar);
		dataVar::camera_state.append(ui.lblType->text());
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "相机连接成功！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", ui.lblType->text() + "相机连接成功！");
		msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
		msgBox.exec();
	}
	else if (strs[0] == "HIKVision")
	{
		//海康威视
		connectHikVison(1);

	}
	//更新获取图像工具
	QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
	for (int i = 0; i < link_keys.length(); i++)
	{
		int key = link_keys[i];
		for (int j = 0; j < 20; j++)
		{
			if (j == key)
			{
				QConfig::ToolBase[key]->RunCommunicationLink("获取图像");
			}
		}
	}
}
void __stdcall ImageCallBackEx(unsigned char* pData, MV_FRAME_OUT_INFO_EX* pFrameInfo, void* pUser) {
	if (!pFrameInfo || !pData) return;

	cv::Mat imgConverted;
	// 根据像素格式选择转换方式
	switch (pFrameInfo->enPixelType)
	{
	case PixelType_Gvsp_Mono8:  // 单通道灰度图
		imgConverted = cv::Mat(pFrameInfo->nHeight, pFrameInfo->nWidth,
			CV_8UC1, pData).clone(); // 必须克隆数据
		break;

	case PixelType_Gvsp_BayerRG8:  // Bayer格式需转RGB
	{
		cv::Mat bayerImg = cv::Mat(pFrameInfo->nHeight, pFrameInfo->nWidth, CV_8UC1, pData).clone();
		cv::cvtColor(bayerImg, imgConverted, cv::COLOR_BayerRG2RGB); // Bayer转RGB
		bayerImg.release();
	}
	break;
	case PixelType_Gvsp_BayerGB8:
	{
		cv::Mat bayerImg = cv::Mat(pFrameInfo->nHeight, pFrameInfo->nWidth, CV_8UC1, pData).clone();
		cv::cvtColor(bayerImg, imgConverted, cv::COLOR_BayerGB2RGB); // Bayer转RGB
		bayerImg.release();
	}
	break;
	case PixelType_Gvsp_RGB8_Packed:  // 原生RGB
		imgConverted = cv::Mat(pFrameInfo->nHeight, pFrameInfo->nWidth,
			CV_8UC3, pData).clone();
		break;

	default:
	{
		std::cerr << "Unsupported pixel format: " << pFrameInfo->enPixelType << std::endl;
		return;
	}
	}
	// 安全存储到全局变量（深拷贝）
	gVariable::CameraVar.srcImg = imgConverted.clone();
	imgConverted.release(); // 释放临时图像
}

//海康连接
void frmCameraSetUp::connectHikVison(int type)
{
	int nRet = MV_CC_Initialize();
	if (MV_OK != nRet)
	{
		printf("Initialize SDK fail! nRet [0x%x]\n", nRet);
		return;
	}
	camera_keys.clear();
	camera_keys = global_camera_content.uniqueKeys();
	int count = 0;
	int ccd_Index = 0;
	for (int k = 0; k < camera_keys.length(); k++)
	{
		QString key = camera_keys[k];
		QString camera_name = ui.lblType->text();
		if (!key.isEmpty())
		{
			ccd_Index = k;
			count += 1;
			ui.spinExposure->setValue(global_camera_content.value(key).global_exposure);
			ui.spinGain->setValue(global_camera_content.value(key).global_gain);
			ui.spinGamma->setValue(global_camera_content.value(key).global_gamma);
			ui.spinContrast->setValue(global_camera_content.value(key).global_contrast);
			ui.comboTriggerMode->setCurrentText(global_camera_content.value(key).global_trigger_mode);
			ui.spinTimeOut->setValue(global_camera_content.value(key).global_timeout);
			CameraContent.ccd_index = k;
			global_camera_content.insert(key, CameraContent);
			break;
		}
	}
	if (count == 0)
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("该相机参数未保存！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该相机参数未保存！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	/*for (int n = 0; n < dataVar::camera_state.count(); n++)
	{
		if (dataVar::camera_state[n] == ui.lblType->text() && !ui.lblType->text().isEmpty() && ui.lblType->text() != "" && type == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "相机已连接！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + "相机已连接！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
	}*/

	std::string id;
	MV_CC_DEVICE_INFO_LIST CameraList = MV_CC_DEVICE_INFO_LIST();
	if (hCameraList.length() > 0) 
	{
		CameraList = hCameraList[0];
	}	
	//查询设备列表
	
	int tempValue = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &CameraList);
	if (tempValue != 0)
		//设备更新成功接收命令的返回值为0，返回值不为0则为异常
		return;
	if (CameraList.nDeviceNum == 0)
		//未找到任何相机
		return;
	if (type == 0) //相机初始化
	{
		for (int k = 0; k < camera_keys.length(); k++)
		{
			QString key = camera_keys[k];
			if (!key.isEmpty())
			{
				ccd_Index = k;
				MV_CC_DEVICE_INFO* pDeviceInfo = NULL;
				pDeviceInfo = CameraList.pDeviceInfo[k];
				if (NULL == pDeviceInfo)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + ":未找到指定名称的相机！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + ":未找到指定名称的相机！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				if (pDeviceInfo->nTLayerType == MV_USB_DEVICE)
				{
					//if (id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber || id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName || id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber || id == "PECVD")
					//{
					m_Device = CameraList.pDeviceInfo[k];
					//return;
				//}
				}
				if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
				{
					//if (id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber || id == (char*)pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName || id == (char*)pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber || id == "PECVD")
					//{
					m_Device = CameraList.pDeviceInfo[k];
					//return;
				//}
				}
				//continue;
			//}
				if (m_Device == NULL)
				{
					//未找到指定名称的相机
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("未找到指定名称的相机！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未找到指定名称的相机！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				void* m_hDevHandle = NULL;
				// 释放旧句柄资源
				if (m_hDevHandle != nullptr) {
					MV_CC_DestroyHandle(m_hDevHandle);
					m_hDevHandle = nullptr;  // 必须重置指针
				}
				//创建相机句柄
				tempValue = MV_CC_CreateHandle(&m_hDevHandle, m_Device);
				if (tempValue != MV_OK)
					return;
				//uintptr_t handleAddr = reinterpret_cast<uintptr_t>(m_hDevHandle);
				//QMessageBox::warning(this, "提示", QString::number(handleAddr));
				tempValue = MV_CC_OpenDevice(m_hDevHandle);
				if (tempValue != MV_OK)
				{
					MV_CC_DestroyHandle(m_hDevHandle);
					m_hDevHandle = NULL;
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log(key + ":初始化相机设备失败！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", key + ":初始化相机设备失败！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				else
				{
					//setTriggerMode(1);
				}
				if (m_Device->nTLayerType == MV_GIGE_DEVICE)
				{
				}
				if (m_Device->nTLayerType == MV_USB_DEVICE)
				{
					MV_CC_SetImageNodeNum(&m_hDevHandle, 2);
				}
				// ch:探测网络最佳包大小(只对GigE相机有效) | en:Detection network optimal package size(It only works for the GigE camera)
				if (m_Device->nTLayerType == MV_GIGE_DEVICE)
				{
					int nPacketSize = MV_CC_GetOptimalPacketSize(m_hDevHandle);
					if (nPacketSize > 0)
					{
						int nRet = MV_CC_SetIntValueEx(m_hDevHandle, "GevSCPSPacketSize", nPacketSize);
						if (nRet != MV_OK)
						{
							printf("Warning: Set Packet Size fail nRet [0x%x]!", nRet);
						}
					}
					else
					{
						printf("Warning: Get Packet Size fail nRet [0x%x]!", nPacketSize);
					}
				}


				////获得该相机的特性描述
				//CameraGetCapability(mindvision_haldle, &sCameraInfo);
				//mindvision_framebuffer = (BYTE*)CameraAlignMalloc(sCameraInfo.sResolutionRange.iWidthMax * sCameraInfo.sResolutionRange.iWidthMax * 3, 16);
				////设置曝光
				//CameraSetAeState(mindvision_haldle, false);
				//CameraSetExposureTime(mindvision_haldle, ui.spinExposure->value());
				////设置增益
				//CameraSetAnalogGain(mindvision_haldle, ui.spinGain->value());
				////设置伽马
				//CameraSetGamma(mindvision_haldle, ui.spinGamma->value() * 100);
				////设置对比度
				//CameraSetContrast(mindvision_haldle, ui.spinContrast->value());
				////设置触发模式
				//int iModeSel = 0;
				//if (ui.comboTriggerMode->currentIndex() == 0)
				//{
				//	iModeSel = 0;
				//}
				//else if (ui.comboTriggerMode->currentIndex() == 1)
				//{
				//	iModeSel = 1;
				//}
				//else if (ui.comboTriggerMode->currentIndex() == 2)
				//{
				//	iModeSel = 2;
				//}
				//CameraSetTriggerMode(mindvision_haldle, iModeSel);
				////保存当前相机参数到指定的参数组中
				//CameraSaveParameter(mindvision_haldle, 0);
				//if (sCameraInfo.sIspCapacity.bMonoSensor)
				//{
				//	CameraSetIspOutFormat(mindvision_haldle, CAMERA_MEDIA_TYPE_MONO8);
				//}
				//CameraPlay(mindvision_haldle);

				//设置曝光
				setExposureAuto(m_hDevHandle, false);
				setExposureTime(m_hDevHandle, ui.spinExposure->value());
				//设置增益
				setGainAuto(m_hDevHandle, false);
				/*m_pcMyCamera->SetFloatValue("Gain", (float)ui.spinGain->value());*/
				MV_CC_SetFloatValue(m_hDevHandle, "Gain", (float)ui.spinGain->value());
				//设置伽马
				MV_CC_SetFloatValue(m_hDevHandle, "Gamma", (float)ui.spinGamma->value() * 100);
				//设置对比度
				// Define a variable of type MV_CC_CCM_PARAM_EX and initialize it properly
				MV_CC_CCM_PARAM_EX ccmParam;
				ccmParam.bCCMEnable = true; // Example initialization, adjust as needed
				ccmParam.nCCMat[0] = ui.spinContrast->value(); // Assuming spinContrast provides a valid value
				ccmParam.nCCMScale = 1; // Example scale, adjust as needed

				// Pass the address of the variable to the function
				MV_CC_SetBayerCCMParamEx(m_hDevHandle, &ccmParam);
				//设置触发模式
				//setTriggerMode(1);
				if (ui.comboTriggerMode->currentIndex() == 0)// 连续采集模式
				{
					setTriggerMode(m_hDevHandle, 0);
					setTriggerSource(m_hDevHandle, 0);
					// ch:注册抓图异步回调 | en:Register image callback
					nRet = MV_CC_RegisterImageCallBackEx(m_hDevHandle, ImageCallBackEx, m_hDevHandle);
					if (MV_OK != nRet)
					{
						printf("Register Image CallBack fail! nRet [0x%x]\n", nRet);
						return;
					}
				}
				else if (ui.comboTriggerMode->currentIndex() == 1) // 软件触发模式
				{
					setTriggerMode(m_hDevHandle, 1);
					setTriggerSource(m_hDevHandle, 7); // 设置触发源为软件
				}
				else if (ui.comboTriggerMode->currentIndex() == 2) // 硬件触发模式
				{
					int nRet = setTriggerMode(m_hDevHandle, 1);
					if (nRet == MV_OK) {
						setTriggerSource(m_hDevHandle, 0); // 触发源为硬件
						nRet = MV_CC_SetEnumValue(m_hDevHandle, "TriggerActivation", 0);  // 触发激活为上升沿
						// ch:注册抓图异步回调 | en:Register image callback
						nRet = MV_CC_RegisterImageCallBackEx(m_hDevHandle, ImageCallBackEx, m_hDevHandle);
						if (MV_OK != nRet)
						{
							printf("Register Image CallBack fail! nRet [0x%x]\n", nRet);
							return;
						}
					}
					else
					{
						setTriggerSource(m_hDevHandle, 1); // 触发源为硬件
					}
				}
				//setTriggerSource(7);//设置为软触发模式



				// 开始取流
				int tempvalue = MV_CC_StartGrabbing(m_hDevHandle);
				if (tempvalue == 0)
				{
					gVariable::CameraVar.camera_type = "HIKVision";
					// Update the type of `hikvision_haldle_value` in `gVariable::CameraVar` to match the type of `m_hDevHandle` (void*).  
					// This ensures compatibility and resolves the type mismatch error.  

					// In the definition of `gVariable::CameraVar`, update the type of `hikvision_haldle_value` from `int` to `void*`.  
					//struct CameraVar {
					//	QString camera_type;
					//	void* hikvision_haldle_value; // Change from int to void*  
					//	BYTE* mindvision_framebuffer_value;
					//	int time_out;
					//	// Other members remain unchanged  
					//};

					// Ensure this change is reflected wherever `hikvision_haldle_value` is used in the codebase.
					m_hDevHandleList->append(static_cast<int*>(m_hDevHandle));
					gVariable::CameraVar.index = ui.comboTriggerMode->currentIndex();
					gVariable::CameraVar.hikvision_haldle_value = m_hDevHandle;
					gVariable::CameraVar.m_hDevHandleList = m_hDevHandleList;
					gVariable::CameraVar.hikvision_deviceInfo = m_Device;
					gVariable::CameraVar.m_hDevHandleKey = key;
					//gVariable::CameraVar.hikvision_framebuffer_value = mindvision_framebuffer;
					gVariable::CameraVar.time_out = ui.spinTimeOut->value();
					//gVariable::Camera_Var CameraVar = gVariable::CameraVar;
					gVariable::camera_variable_link.insert(key, gVariable::CameraVar);
					dataVar::camera_state.append(key);
					emit dataVar::fProItemTab->sig_InfoClick();
					emit dataVar::fProItemTab->sig_Log(key + ":相机连接成功！");
					//quintptr m_Devicestr = reinterpret_cast<quintptr>(m_Device);
					uintptr_t handleAddr = reinterpret_cast<uintptr_t>(gVariable::camera_variable_link.value(key).hikvision_haldle_value);
					//QMessageBox::warning(this, "提示", key + ":" + handleAddr, QMessageBox::Ok);
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", key + ":相机连接成功！");
					msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
					msgBox.exec();
				}
			}
		}
	}
	else if (type == 1) //相机连接
	{
		for (int k = 0; k < camera_keys.length(); k++)
		{
			QString key = camera_keys[k];
			QString camera_name = ui.lblType->text();
			if (!key.isEmpty() && camera_name == key)
			{
				ccd_Index = k;
				MV_CC_DEVICE_INFO* pDeviceInfo = NULL;
				if (!ui.lblType->text().isEmpty()) 
				{
					if (ui.lblType->text() == camera_keys[k])
					{
						pDeviceInfo = CameraList.pDeviceInfo[k];
					}
				}
				else
				{
                    pDeviceInfo = CameraList.pDeviceInfo[k];
				}
				if (NULL == pDeviceInfo)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + ":未找到指定名称的相机！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + ":未找到指定名称的相机！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				//if (pDeviceInfo->nTLayerType == MV_USB_DEVICE)
				//{
				//	//if (id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber || id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName || id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber || id == "PECVD")
				//	//{
				//	m_Device = CameraList.pDeviceInfo[ccd_Index];
				//	//return;
				////}
				//}
				//if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
				//{
				//	//if (id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber || id == (char*)pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName || id == (char*)pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber || id == "PECVD")
				//	//{
				//	m_Device = CameraList.pDeviceInfo[ccd_Index];
				//	//return;
				////}
				//}
				//continue;
			//}
				m_Device = pDeviceInfo;
				if (m_Device == NULL)
				{
					//未找到指定名称的相机
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("未找到指定名称的相机！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未找到指定名称的相机！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				void* m_hDevHandle = 0;
				//创建相机句柄
				tempValue = MV_CC_CreateHandle(&m_hDevHandle, m_Device);
				if (tempValue != MV_OK)
					return;
				tempValue = MV_CC_OpenDevice(m_hDevHandle);
				if (tempValue != MV_OK)
				{
					MV_CC_DestroyHandle(m_hDevHandle);
					m_hDevHandle = NULL;
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log( "初始化相机设备失败！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "初始化相机设备失败！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				else
				{
					//setTriggerMode(1);
				}
				if (m_Device->nTLayerType == MV_GIGE_DEVICE)
				{
				}
				if (m_Device->nTLayerType == MV_USB_DEVICE)
				{
					MV_CC_SetImageNodeNum(&m_hDevHandle, 2);
				}
				// ch:探测网络最佳包大小(只对GigE相机有效) | en:Detection network optimal package size(It only works for the GigE camera)
				if (m_Device->nTLayerType == MV_GIGE_DEVICE)
				{
					int nPacketSize = MV_CC_GetOptimalPacketSize(m_hDevHandle);
					if (nPacketSize > 0)
					{
						int nRet = MV_CC_SetIntValueEx(m_hDevHandle, "GevSCPSPacketSize", nPacketSize);
						if (nRet != MV_OK)
						{
							printf("Warning: Set Packet Size fail nRet [0x%x]!", nRet);
						}
					}
					else
					{
						printf("Warning: Get Packet Size fail nRet [0x%x]!", nPacketSize);
					}
				}
				//设置曝光
				setExposureAuto(m_hDevHandle, false);
				setExposureTime(m_hDevHandle, ui.spinExposure->value());
				//设置增益
				setGainAuto(m_hDevHandle, false);
				/*m_pcMyCamera->SetFloatValue("Gain", (float)ui.spinGain->value());*/
				MV_CC_SetFloatValue(m_hDevHandle, "Gain", (float)ui.spinGain->value());
				//设置伽马
				MV_CC_SetFloatValue(m_hDevHandle, "Gamma", (float)ui.spinGamma->value() * 100);
				//设置对比度
				// Define a variable of type MV_CC_CCM_PARAM_EX and initialize it properly
				MV_CC_CCM_PARAM_EX ccmParam;
				ccmParam.bCCMEnable = true; // Example initialization, adjust as needed
				ccmParam.nCCMat[0] = ui.spinContrast->value(); // Assuming spinContrast provides a valid value
				ccmParam.nCCMScale = 1; // Example scale, adjust as needed

				// Pass the address of the variable to the function
				MV_CC_SetBayerCCMParamEx(m_hDevHandle, &ccmParam);
				//设置触发模式
				//setTriggerMode(1);
				if (ui.comboTriggerMode->currentIndex() == 0)// 连续采集模式
				{
					setTriggerMode(m_hDevHandle, 0);
					setTriggerSource(m_hDevHandle, 0);
					// ch:注册抓图异步回调 | en:Register image callback
					nRet = MV_CC_RegisterImageCallBackEx(m_hDevHandle, ImageCallBackEx, m_hDevHandle);
					if (MV_OK != nRet)
					{
						printf("Register Image CallBack fail! nRet [0x%x]\n", nRet);
						return;
					}
				}
				else if (ui.comboTriggerMode->currentIndex() == 1) // 软件触发模式
				{
					setTriggerMode(m_hDevHandle, 1);
					setTriggerSource(m_hDevHandle, 7); // 设置触发源为软件
				}
				else if (ui.comboTriggerMode->currentIndex() == 2) // 硬件触发模式
				{
					int nRet = setTriggerMode(m_hDevHandle, 1);
					if (nRet == MV_OK) {
						setTriggerSource(m_hDevHandle, 0); // 触发源为硬件
						nRet = MV_CC_SetEnumValue(m_hDevHandle, "TriggerActivation", 0);  // 触发激活为上升沿
						// ch:注册抓图异步回调 | en:Register image callback
						nRet = MV_CC_RegisterImageCallBackEx(m_hDevHandle, ImageCallBackEx, m_hDevHandle);
						if (MV_OK != nRet)
						{
							printf("Register Image CallBack fail! nRet [0x%x]\n", nRet);
							return;
						}
					}
					else
					{
						setTriggerSource(m_hDevHandle, 1); // 触发源为硬件
					}
				}
				//setTriggerSource(7);//设置为软触发模式



				// 开始取流
				int tempvalue = MV_CC_StartGrabbing(m_hDevHandle);
				if (tempvalue == 0)
				{
					gVariable::CameraVar.camera_type = "HIKVision";
					// Update the type of `hikvision_haldle_value` in `gVariable::CameraVar` to match the type of `m_hDevHandle` (void*).  
					// This ensures compatibility and resolves the type mismatch error.  

					// In the definition of `gVariable::CameraVar`, update the type of `hikvision_haldle_value` from `int` to `void*`.  
					//struct CameraVar {
					//	QString camera_type;
					//	void* hikvision_haldle_value; // Change from int to void*  
					//	BYTE* mindvision_framebuffer_value;
					//	int time_out;
					//	// Other members remain unchanged  
					//};

					// Ensure this change is reflected wherever `hikvision_haldle_value` is used in the codebase.
					m_hDevHandleList->append(static_cast<int*>(m_hDevHandle));
					gVariable::CameraVar.index = ui.comboTriggerMode->currentIndex();
					gVariable::CameraVar.hikvision_haldle_value = m_hDevHandle;
					gVariable::CameraVar.m_hDevHandleList = m_hDevHandleList;
					gVariable::CameraVar.hikvision_deviceInfo = m_Device;
					gVariable::CameraVar.m_hDevHandleKey = key;
                    //gVariable::camera_variable_link.insert(ui.lblType->text(), gVariable::CameraVar);
					//gVariable::CameraVar.hikvision_framebuffer_value = mindvision_framebuffer;
					gVariable::CameraVar.time_out = ui.spinTimeOut->value();
					//CameraVar = gVariable::CameraVar;
					gVariable::camera_variable_link.insert(key, gVariable::CameraVar);
					dataVar::camera_state.append(key);
					emit dataVar::fProItemTab->sig_InfoClick();
					emit dataVar::fProItemTab->sig_Log(key + ":相机连接成功！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", key + ":相机连接成功！");
					msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
					msgBox.exec();
				}
			}
		}
	}
	
	
	
}

//海康连接
void frmCameraSetUp::connectHikVison(QString key)
{
	int nRet = MV_CC_Initialize();
	if (MV_OK != nRet)
	{
		printf("Initialize SDK fail! nRet [0x%x]\n", nRet);
		return;
	}
	camera_keys.clear();
	camera_keys = global_camera_content.uniqueKeys();
	int count = 0;
	int ccd_Index = 0;
	for (int k = 0; k < camera_keys.length(); k++)
	{
		QString key = camera_keys[k];
		QString camera_name = ui.lblType->text();
		if (!key.isEmpty())
		{
			ccd_Index = k;
			count = 1;
			ui.spinExposure->setValue(global_camera_content.value(key).global_exposure);
			ui.spinGain->setValue(global_camera_content.value(key).global_gain);
			ui.spinGamma->setValue(global_camera_content.value(key).global_gamma);
			ui.spinContrast->setValue(global_camera_content.value(key).global_contrast);
			ui.comboTriggerMode->setCurrentText(global_camera_content.value(key).global_trigger_mode);
			ui.spinTimeOut->setValue(global_camera_content.value(key).global_timeout);
			CameraContent.ccd_index = k;
			global_camera_content.insert(key, CameraContent);
			break;
		}
	}
	if (count == 0)
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("该相机参数未保存！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该相机参数未保存！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	/*for (int n = 0; n < dataVar::camera_state.count(); n++)
	{
		if (dataVar::camera_state[n] == ui.lblType->text() && !ui.lblType->text().isEmpty() && ui.lblType->text() != "")
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "相机已连接！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ui.lblType->text() + "相机已连接！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
	}*/
	//初始化相机，(-1,-1)表示加载上次退出前保存的参数，如果是第一次使用该相机，则加载默认参数
	/*if ((status = CameraInit(&sCameraList[ccd_Index], -1, -1, &mindvision_haldle)) != CAMERA_STATUS_SUCCESS)
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("初始化相机失败！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "初始化相机失败！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}*/
	std::string id;
	MV_CC_DEVICE_INFO_LIST CameraList = MV_CC_DEVICE_INFO_LIST();
	//查询设备列表
	if (hCameraList.size() > 0)
	{
		CameraList = hCameraList[0];
	}
	else 
	{
		on_btnSearchCamera_clicked();
		CameraList = hCameraList[0];
	}
	int tempValue = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &CameraList);
	if (tempValue != 0)
		//设备更新成功接收命令的返回值为0，返回值不为0则为异常
		return;
	if (CameraList.nDeviceNum == 0)
		//未找到任何相机
		return;
	MV_CC_DEVICE_INFO* pDeviceInfo = CameraList.pDeviceInfo[ccd_Index];

	if (NULL == pDeviceInfo)
	{
		return;
	}
	if (pDeviceInfo->nTLayerType == MV_USB_DEVICE)
	{
		if (id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber || id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName || id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber || id == "PECVD")
		{
			m_Device = CameraList.pDeviceInfo[ccd_Index];
			//return;
		}
	}

	if (pDeviceInfo->nTLayerType == MV_GIGE_DEVICE)
	{
		if (id == (char*)pDeviceInfo->SpecialInfo.stUsb3VInfo.chSerialNumber || id == (char*)pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName || id == (char*)pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber || id == "PECVD")
		{
			m_Device = CameraList.pDeviceInfo[ccd_Index];
			//return;
		}
	}
	//continue;
//}
	if (m_Device == NULL)
	{
		//未找到指定名称的相机
		return;
	}
	void* m_hDevHandle = 0;
	tempValue = MV_CC_CreateHandle(&m_hDevHandle, m_Device);
	if (tempValue != 0)
		return;

	tempValue = MV_CC_OpenDevice(m_hDevHandle);
	if (tempValue != 0)
	{
		MV_CC_DestroyHandle(m_hDevHandle);
		m_hDevHandle = NULL;
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("初始化相机失败！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "初始化相机失败！" + QString::number(tempValue));
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	else
	{
		//setTriggerMode(1);
	}
	if (m_Device->nTLayerType == MV_GIGE_DEVICE)
	{
	}
	if (m_Device->nTLayerType == MV_USB_DEVICE)
	{
		MV_CC_SetImageNodeNum(&m_hDevHandle, 2);
	}
	// ch:探测网络最佳包大小(只对GigE相机有效) | en:Detection network optimal package size(It only works for the GigE camera)
	if (m_Device->nTLayerType == MV_GIGE_DEVICE)
	{
		int nPacketSize = MV_CC_GetOptimalPacketSize(m_hDevHandle);
		if (nPacketSize > 0)
		{
			int nRet = MV_CC_SetIntValueEx(m_hDevHandle, "GevSCPSPacketSize", nPacketSize);
			if (nRet != MV_OK)
			{
				printf("Warning: Set Packet Size fail nRet [0x%x]!", nRet);
			}
		}
		else
		{
			printf("Warning: Get Packet Size fail nRet [0x%x]!", nPacketSize);
		}
	}


	////获得该相机的特性描述
	//CameraGetCapability(mindvision_haldle, &sCameraInfo);
	//mindvision_framebuffer = (BYTE*)CameraAlignMalloc(sCameraInfo.sResolutionRange.iWidthMax * sCameraInfo.sResolutionRange.iWidthMax * 3, 16);
	////设置曝光
	//CameraSetAeState(mindvision_haldle, false);
	//CameraSetExposureTime(mindvision_haldle, ui.spinExposure->value());
	////设置增益
	//CameraSetAnalogGain(mindvision_haldle, ui.spinGain->value());
	////设置伽马
	//CameraSetGamma(mindvision_haldle, ui.spinGamma->value() * 100);
	////设置对比度
	//CameraSetContrast(mindvision_haldle, ui.spinContrast->value());
	////设置触发模式
	//int iModeSel = 0;
	//if (ui.comboTriggerMode->currentIndex() == 0)
	//{
	//	iModeSel = 0;
	//}
	//else if (ui.comboTriggerMode->currentIndex() == 1)
	//{
	//	iModeSel = 1;
	//}
	//else if (ui.comboTriggerMode->currentIndex() == 2)
	//{
	//	iModeSel = 2;
	//}
	//CameraSetTriggerMode(mindvision_haldle, iModeSel);
	////保存当前相机参数到指定的参数组中
	//CameraSaveParameter(mindvision_haldle, 0);
	//if (sCameraInfo.sIspCapacity.bMonoSensor)
	//{
	//	CameraSetIspOutFormat(mindvision_haldle, CAMERA_MEDIA_TYPE_MONO8);
	//}
	//CameraPlay(mindvision_haldle);

	//设置曝光
	setExposureAuto(m_hDevHandle,false);
	setExposureTime(m_hDevHandle, ui.spinExposure->value());
	//设置增益
	setGainAuto(m_hDevHandle, false);
	/*m_pcMyCamera->SetFloatValue("Gain", (float)ui.spinGain->value());*/
	MV_CC_SetFloatValue(m_hDevHandle, "Gain", (float)ui.spinGain->value());
	//设置伽马
	MV_CC_SetFloatValue(m_hDevHandle, "Gamma", (float)ui.spinGamma->value() * 100);
	//设置对比度
	// Define a variable of type MV_CC_CCM_PARAM_EX and initialize it properly
	MV_CC_CCM_PARAM_EX ccmParam;
	ccmParam.bCCMEnable = true; // Example initialization, adjust as needed
	ccmParam.nCCMat[0] = ui.spinContrast->value(); // Assuming spinContrast provides a valid value
	ccmParam.nCCMScale = 1; // Example scale, adjust as needed

	// Pass the address of the variable to the function
	MV_CC_SetBayerCCMParamEx(m_hDevHandle, &ccmParam);
	//设置触发模式
	//setTriggerMode(1);
	if (ui.comboTriggerMode->currentIndex() == 0)// 连续采集模式
	{
		setTriggerMode(m_hDevHandle, 0);
		setTriggerSource(m_hDevHandle, 0);
		// ch:注册抓图异步回调 | en:Register image callback
		nRet = MV_CC_RegisterImageCallBackEx(m_hDevHandle, ImageCallBackEx, m_hDevHandle);
		if (MV_OK != nRet)
		{
			printf("Register Image CallBack fail! nRet [0x%x]\n", nRet);
			return;
		}
	}
	else if (ui.comboTriggerMode->currentIndex() == 1) // 软件触发模式
	{
		setTriggerMode(m_hDevHandle, 1);
		setTriggerSource(m_hDevHandle, 7); // 设置触发源为软件
	}
	else if (ui.comboTriggerMode->currentIndex() == 2) // 硬件触发模式
	{
		int nRet = setTriggerMode(m_hDevHandle, 1);
		if (nRet == MV_OK) {
			setTriggerSource(m_hDevHandle, 0); // 触发源为硬件
			nRet = MV_CC_SetEnumValue(m_hDevHandle, "TriggerActivation", 0);  // 触发激活为上升沿
			// ch:注册抓图异步回调 | en:Register image callback
			nRet = MV_CC_RegisterImageCallBackEx(m_hDevHandle, ImageCallBackEx, m_hDevHandle);
			if (MV_OK != nRet)
			{
				printf("Register Image CallBack fail! nRet [0x%x]\n", nRet);
				return;
			}
		}
		else
		{
			setTriggerSource(m_hDevHandle, 1); // 触发源为硬件
		}
	}
	//setTriggerSource(7);//设置为软触发模式



	// 开始取流
	int tempvalue = MV_CC_StartGrabbing(m_hDevHandle);
	gVariable::CameraVar.camera_type = "HIKVision";
	// Update the type of `hikvision_haldle_value` in `gVariable::CameraVar` to match the type of `m_hDevHandle` (void*).  
	// This ensures compatibility and resolves the type mismatch error.  

	// In the definition of `gVariable::CameraVar`, update the type of `hikvision_haldle_value` from `int` to `void*`.  
	struct CameraVar {
		QString camera_type;
		void* hikvision_haldle_value; // Change from int to void*  
		BYTE* mindvision_framebuffer_value;
		int time_out;
		// Other members remain unchanged  
	};

	// Ensure this change is reflected wherever `hikvision_haldle_value` is used in the codebase.
	m_hDevHandleList->append(static_cast<int*>(m_hDevHandle));
	gVariable::CameraVar.index = ui.comboTriggerMode->currentIndex();
	gVariable::CameraVar.hikvision_haldle_value = m_hDevHandle;
	gVariable::CameraVar.m_hDevHandleList = m_hDevHandleList;
	gVariable::CameraVar.hikvision_deviceInfo = m_Device;
	gVariable::CameraVar.m_hDevHandleKey = key;
	//gVariable::camera_variable_link.insert(ui.lblType->text(), gVariable::CameraVar);
	//gVariable::CameraVar.hikvision_framebuffer_value = mindvision_framebuffer;
	gVariable::CameraVar.time_out = ui.spinTimeOut->value();
	//CameraVar = gVariable::CameraVar;
	gVariable::camera_variable_link.insert(ui.lblType->text(), gVariable::CameraVar);
	dataVar::camera_state.append(ui.lblType->text());
	emit dataVar::fProItemTab->sig_InfoClick();
	emit dataVar::fProItemTab->sig_Log(key + ":相机连接成功！");
	QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", key + ":相机连接成功！");
	msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
	msgBox.exec();
}

//启动相机采集
int frmCameraSetUp::startCamera(void* handle)
{
	int tempValue = MV_CC_StartGrabbing(handle);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//停止相机采集
int frmCameraSetUp::stopCamera(void* handle)
{
	int tempValue = MV_CC_StopGrabbing(handle);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//关闭相机
int frmCameraSetUp::closeCamera(void* handle)
{
	if (NULL == handle)
	{
		return -1;
	}
	MV_CC_CloseDevice(handle);
	int tempValue = MV_CC_DestroyHandle(handle);
	handle = NULL;
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//发送软触发
int frmCameraSetUp::softTrigger(void* handle)
{
	int tempValue = MV_CC_SetCommandValue(handle, "TriggerSoftware");
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//读取相机中的图像
int frmCameraSetUp::ReadBuffer(void* handle, cv::Mat& image)
{
	cv::Mat* getImage = new cv::Mat();
	unsigned int nRecvBufSize = 0;
	MVCC_INTVALUE stParam;
	memset(&stParam, 0, sizeof(MVCC_INTVALUE));
	int tempValue = MV_CC_GetIntValue(handle, "PayloadSize", &stParam);
	if (tempValue != 0)
	{
		return -1;
	}
	nRecvBufSize = stParam.nCurValue;
	unsigned char* pDate;
	pDate = (unsigned char*)malloc(nRecvBufSize);

	MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };
	tempValue = MV_CC_GetOneFrameTimeout(handle, pDate, nRecvBufSize, &stImageInfo, 700);
	if (tempValue != 0)
	{
		return -1;
	}
	m_nBufSizeForSaveImage = stImageInfo.nWidth * stImageInfo.nHeight * 3 + 2048;
	unsigned char* m_pBufForSaveImage;
	m_pBufForSaveImage = (unsigned char*)malloc(m_nBufSizeForSaveImage);


	bool isMono;
	switch (stImageInfo.enPixelType)
	{
	case PixelType_Gvsp_Mono8:
	case PixelType_Gvsp_Mono10:
	case PixelType_Gvsp_Mono10_Packed:
	case PixelType_Gvsp_Mono12:
	case PixelType_Gvsp_Mono12_Packed:
		isMono = true;
		break;
	default:
		isMono = false;
		break;
	}
	if (isMono)
	{
		*getImage = cv::Mat(stImageInfo.nHeight, stImageInfo.nWidth, CV_8UC1, pDate);
		//imwrite("d:\\测试opencv_Mono.tif", image);
	}
	else
	{
		//转换图像格式为BGR8
		MV_CC_PIXEL_CONVERT_PARAM stConvertParam = { 0 };
		memset(&stConvertParam, 0, sizeof(MV_CC_PIXEL_CONVERT_PARAM));
		stConvertParam.nWidth = stImageInfo.nWidth;                 //ch:图像宽 | en:image width
		stConvertParam.nHeight = stImageInfo.nHeight;               //ch:图像高 | en:image height
		//stConvertParam.pSrcData = m_pBufForDriver;                  //ch:输入数据缓存 | en:input data buffer
		stConvertParam.pSrcData = pDate;                  //ch:输入数据缓存 | en:input data buffer
		stConvertParam.nSrcDataLen = stImageInfo.nFrameLen;         //ch:输入数据大小 | en:input data size
		stConvertParam.enSrcPixelType = stImageInfo.enPixelType;    //ch:输入像素格式 | en:input pixel format
		stConvertParam.enDstPixelType = PixelType_Gvsp_BGR8_Packed; //ch:输出像素格式 | en:output pixel format  适用于OPENCV的图像格式
		//stConvertParam.enDstPixelType = PixelType_Gvsp_RGB8_Packed; //ch:输出像素格式 | en:output pixel format
		stConvertParam.pDstBuffer = m_pBufForSaveImage;                    //ch:输出数据缓存 | en:output data buffer
		stConvertParam.nDstBufferSize = m_nBufSizeForSaveImage;            //ch:输出缓存大小 | en:output buffer size
		MV_CC_ConvertPixelType(handle, &stConvertParam);

		*getImage = cv::Mat(stImageInfo.nHeight, stImageInfo.nWidth, CV_8UC3, m_pBufForSaveImage);
		//imwrite("d:\\测试opencv_Color.tif", image);
	}
	(*getImage).copyTo(image);
	(*getImage).release();
	free(pDate);
	free(m_pBufForSaveImage);
	return 0;
}

//获取图像高度值
int frmCameraSetUp::getHeight(void* handle)
{
	MVCC_INTVALUE stParam;
	memset(&stParam, 0, sizeof(MVCC_INTVALUE));
	int tempValue = MV_CC_GetIntValue(handle, "Height", &stParam);
	int value = stParam.nCurValue;
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return value;
	}
}

//获取图像宽度值
int frmCameraSetUp::getWidth(void* handle)
{
	MVCC_INTVALUE stParam;
	memset(&stParam, 0, sizeof(MVCC_INTVALUE));
	int tempValue = MV_CC_GetIntValue(handle, "Width", &stParam);
	int value = stParam.nCurValue;
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return value;
	}
}

//获取相机曝光时间
float frmCameraSetUp::getExposureTime(void* handle)
{
	MVCC_FLOATVALUE stParam;
	memset(&stParam, 0, sizeof(MVCC_INTVALUE));
	int tempValue = MV_CC_GetFloatValue(handle, "ExposureTime", &stParam);
	float value = stParam.fCurValue;
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return value;
	}
}

//设置图像ROI高度
int frmCameraSetUp::setHeight(void* handle,unsigned int height)
{
	int tempValue = MV_CC_SetIntValue(handle, "Height", height);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置图像ROI宽度
int frmCameraSetUp::setWidth(void* handle, unsigned int width)
{
	int tempValue = MV_CC_SetIntValue(handle, "Width", width);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置图像水平偏移OffsetX
int frmCameraSetUp::setOffsetX(void* handle, unsigned int offsetX)
{
	int tempValue = MV_CC_SetIntValue(handle, "OffsetX", offsetX);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置图像竖直偏移OffsetY
int frmCameraSetUp::setOffsetY(void* handle, unsigned int offsetY)
{
	int tempValue = MV_CC_SetIntValue(handle, "OffsetY", offsetY);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置是否为触发模式
int frmCameraSetUp::setTriggerMode(void* handle, unsigned int TriggerModeNum)
{
	//0：Off  1：On
	int tempValue = MV_CC_SetEnumValue(handle, "TriggerMode", TriggerModeNum);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置触发源
int frmCameraSetUp::setTriggerSource(void* handle, unsigned int TriggerSourceNum)
{
	//0：Line0  1：Line1  7：Software
	int tempValue = MV_CC_SetEnumValue(handle, "TriggerSource", TriggerSourceNum);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置帧率控制使能
int frmCameraSetUp::setFrameRateEnable(void* handle, bool comm)
{
	int tempValue = MV_CC_SetBoolValue(handle, "AcquisitionFrameRateEnable", comm);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置心跳时间
int frmCameraSetUp::setHeartBeatTime(void* handle, unsigned int time)
{
	//心跳时间最小为500ms
	if (time < 500)
		time = 500;
	int tempValue = MV_CC_SetIntValue(handle, "GevHeartbeatTimeout", time);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//设置曝光时间
int frmCameraSetUp::setExposureTime(void* handle, float ExposureTimeNum)
{
	int tempValue = MV_CC_SetFloatValue(handle, "ExposureTime", ExposureTimeNum);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
//关闭自动曝光
int frmCameraSetUp::setExposureAuto(void* handle, bool exposureAutoFlag)
{
	int tempValue = MV_CC_SetEnumValue(handle, "ExposureAuto", exposureAutoFlag);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//关闭自动增益
int frmCameraSetUp::setGainAuto(void* handle, bool gainAutoFlag)
{
	int tempValue = MV_CC_SetEnumValue(handle, "GainAuto", gainAutoFlag);
	if (tempValue != 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//清理相机缓存
void frmCameraSetUp::clearBuffer()
{
	//stopCamera();
	//startCamera();
}
//初始化相机连接
void frmCameraSetUp::InitCameraConnect(QString camera_key_value)
{	
	QStringList strs = camera_key_value.split("_");
	if (strs[0] == "MindVision")
	{		
		tSdkCameraDevInfo sCameraList_buf[9];
		iCameraNums = 9;
		//返回的相机信息列表，会根据acFriendlyName排序
		if (CameraEnumerateDevice(sCameraList_buf, &iCameraNums) != CAMERA_STATUS_SUCCESS || iCameraNums == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("未搜索到迈德威视相机！");			
			dataVar::camera_state.clear();
			return;
		}
		int ccd_Index = global_camera_content.value(camera_key_value).ccd_index;
		bool cam_state = false;
		sCameraList.clear();
		for (int i = 0; i < iCameraNums; i++)
		{
			sCameraList.append(sCameraList_buf[i]);
			ui.comboCameraName->addItem(sCameraList_buf[i].acFriendlyName);
			if (camera_key_value.mid(11, camera_key_value.length() - 1) == sCameraList_buf[i].acFriendlyName)
			{
				if (i == ccd_Index)
				{
					cam_state = true;
				}
			}
		}
		if (cam_state == false)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log(camera_key_value + "相机索引错误！");
			dataVar::camera_state.removeOne(camera_key_value);
			return;
		}
		//初始化相机，(-1,-1)表示加载上次退出前保存的参数，如果是第一次使用该相机，则加载默认参数
		if ((status = CameraInit(&sCameraList[ccd_Index], -1, -1, &mindvision_haldle)) != CAMERA_STATUS_SUCCESS)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("初始化" + camera_key_value + "相机失败！");
			dataVar::camera_state.removeOne(camera_key_value);
			return;
		}
		//获得该相机的特性描述
		CameraGetCapability(mindvision_haldle, &sCameraInfo);
		mindvision_framebuffer = (BYTE*)CameraAlignMalloc(sCameraInfo.sResolutionRange.iWidthMax * sCameraInfo.sResolutionRange.iWidthMax * 3, 16);
		//设置曝光
		CameraSetAeState(mindvision_haldle, false);
		CameraSetExposureTime(mindvision_haldle, global_camera_content.value(camera_key_value).global_exposure);
		//设置增益
		CameraSetAnalogGain(mindvision_haldle, global_camera_content.value(camera_key_value).global_gain);
		//设置伽马
		CameraSetGamma(mindvision_haldle, global_camera_content.value(camera_key_value).global_gamma * 100);
		//设置对比度
		CameraSetContrast(mindvision_haldle, global_camera_content.value(camera_key_value).global_contrast);
		//设置触发模式
		int iModeSel = 0;
		if (global_camera_content.value(camera_key_value).global_trigger_mode == "连续采集")
		{
			iModeSel = 0;
		}
		else if (global_camera_content.value(camera_key_value).global_trigger_mode == "软件触发")
		{
			iModeSel = 1;
		}
		else if (global_camera_content.value(camera_key_value).global_trigger_mode == "硬件触发")
		{
			iModeSel = 2;
		}
		CameraSetTriggerMode(mindvision_haldle, iModeSel);
		//保存当前相机参数到指定的参数组中
		CameraSaveParameter(mindvision_haldle, 0);
		if (sCameraInfo.sIspCapacity.bMonoSensor)
		{
			CameraSetIspOutFormat(mindvision_haldle, CAMERA_MEDIA_TYPE_MONO8);
		}
		CameraPlay(mindvision_haldle);
		gVariable::CameraVar.camera_type = "MindVision";
		gVariable::CameraVar.mindvision_haldle_value = mindvision_haldle;
		gVariable::CameraVar.mindvision_framebuffer_value = mindvision_framebuffer;		
		gVariable::camera_variable_link.insert(camera_key_value, gVariable::CameraVar);
		dataVar::camera_state.append(camera_key_value);
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log(camera_key_value + "相机连接成功！");
	}
	else if (strs[0] == "HIKVision") 
	{
		//海康威视
		connectHikVison(0);
	}
	//更新获取图像工具
	QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
	for (int i = 0; i < link_keys.length(); i++)
	{
		int key = link_keys[i];
		for (int j = 0; j < 20; j++)
		{
			if (j == key)
			{
				QConfig::ToolBase[key]->RunCommunicationLink("获取图像");
			}
		}
	}
}

void frmCameraSetUp::on_btnDisconnect_clicked()
{
	//断开相机
	if (ui.lblType->text() == QString())
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("选择相机名称为空！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "选择相机名称为空！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	QStringList strs = ui.lblType->text().split("_");
	if (strs[0] == "MindVision")
	{
		//迈德威视		
		camera_keys.clear();
		camera_keys = gVariable::camera_variable_link.uniqueKeys();
		int count = 0;
		for (int k = 0; k < camera_keys.length(); k++)
		{
			QString key = camera_keys[k];
			if (key == ui.lblType->text())
			{
				if (gVariable::camera_variable_link.value(key).mindvision_haldle_value > 0)
				{
					CameraStop(gVariable::camera_variable_link.value(key).mindvision_haldle_value);
					//相机反初始化，释放资源
					CameraUnInit(gVariable::camera_variable_link.value(key).mindvision_haldle_value);
					CameraAlignFree(gVariable::camera_variable_link.value(key).mindvision_framebuffer_value);
					dataVar::camera_state.removeOne(ui.lblType->text());
					gVariable::camera_variable_link.remove(key);
					count = 1;
					emit dataVar::fProItemTab->sig_InfoClick();
					emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "已断开连接！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "该相机已断开连接！");
					msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
					msgBox.exec();
				}
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该相机未连接！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该相机未连接！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
	}
	else if (strs[0] == "HIKVision")
	{
		//海康威视
		camera_keys.clear();
		camera_keys = gVariable::camera_variable_link.uniqueKeys();
		int count = 0;
		for (int k = 0; k < camera_keys.length(); k++)
		{
			QString key = camera_keys[k];
			if (key == ui.lblType->text())
			{
				if (gVariable::CameraVar.hikvision_haldle_value != NULL)
				{
					void* m_hDevHandle = gVariable::CameraVar.hikvision_haldle_value;
					// ch:停止取流 | en:Stop grab image
					int nRet = MV_CC_StopGrabbing(m_hDevHandle);
					if (MV_OK != nRet)
					{
						printf("Stop Grabbing fail! nRet [0x%x]\n", nRet);
					}

					// ch:注销抓图回调 | en:Unregister image callback
					nRet = MV_CC_RegisterImageCallBackEx(m_hDevHandle, NULL, NULL);
					if (MV_OK != nRet)
					{
						printf("Unregister Image CallBack fail! nRet [0x%x]\n", nRet);
					}

					// ch:关闭设备 | en:Close device
					nRet = MV_CC_CloseDevice(m_hDevHandle);
					if (MV_OK != nRet)
					{
						printf("Close Device fail! nRet [0x%x]\n", nRet);
					}

					// ch:销毁句柄 | en:Destroy handle
					nRet = MV_CC_DestroyHandle(m_hDevHandle);
					if (MV_OK != nRet)
					{
						printf("Destroy Handle fail! nRet [0x%x]\n", nRet);
					}
					if (m_hDevHandle != NULL)
					{
						MV_CC_DestroyHandle(m_hDevHandle);
						m_hDevHandle = NULL;
					}
					// ch:反初始化SDK | en:Finalize SDK
					MV_CC_Finalize();
					dataVar::camera_state.removeOne(ui.lblType->text());
					gVariable::camera_variable_link.remove(ui.lblType->text());
					count++;
					emit dataVar::fProItemTab->sig_InfoClick();
					emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "已断开连接！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "该相机已断开连接！");
					msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
					msgBox.exec();
					return;
				}
			}
		}
		if (count == 0)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("该相机未连接！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "该相机未连接！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
		
	}
	//更新获取图像工具
	QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
	for (int i = 0; i < link_keys.length(); i++)
	{
		int key = link_keys[i];
		for (int j = 0; j < 20; j++)
		{
			if (j == key)
			{
				QConfig::ToolBase[key]->RunCommunicationLink("获取图像");
			}
		}
	}
}

void frmCameraSetUp::on_btnSave_clicked()
{
	//保存参数
	if (ui.lblType->text() == QString())
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log("选择相机名称为空！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "选择相机名称为空！");
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
		return;
	}
	CameraContent.global_exposure = ui.spinExposure->value();
	CameraContent.global_gain = ui.spinGain->value();
	CameraContent.global_gamma = ui.spinGamma->value();
	CameraContent.global_contrast = ui.spinContrast->value();
	CameraContent.global_trigger_mode = ui.comboTriggerMode->currentText();
	CameraContent.global_timeout = ui.spinTimeOut->value();
	CameraContent.global_remark = ui.txtRemark->text();
	global_camera_content.insert(ui.lblType->text(), CameraContent);
	emit dataVar::fProItemTab->sig_InfoClick();
	emit dataVar::fProItemTab->sig_Log(ui.lblType->text() + "保存参数完成！");
	QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "保存参数完成！");
	msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
	msgBox.exec();
}

void frmCameraSetUp::slot_DoubleClicked(int row, int column)
{
	QString selectInstrument = ui.tableWidget->item(row, 0)->text();
	ui.lblType->setText(selectInstrument);
	camera_keys.reserve(100);
	camera_keys.clear();
	camera_keys = global_camera_content.uniqueKeys();
	int count = 0;
	for (int k = 0; k < camera_keys.length(); k++)
	{
		QString key = camera_keys[k];
		if (key == selectInstrument)
		{
			count = 1;
			ui.spinExposure->setValue(global_camera_content.value(key).global_exposure);
			ui.spinGain->setValue(global_camera_content.value(key).global_gain);
			ui.spinGamma->setValue(global_camera_content.value(key).global_gamma);
			ui.spinContrast->setValue(global_camera_content.value(key).global_contrast);
			ui.comboTriggerMode->setCurrentText(global_camera_content.value(key).global_trigger_mode);
			ui.spinTimeOut->setValue(global_camera_content.value(key).global_timeout);
			ui.txtRemark->setText(global_camera_content.value(key).global_remark);
		}
	}
	if (count == 0)
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("该相机参数未保存！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "该相机参数未保存！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
	}
}

void frmCameraSetUp::slot_MoveUp()
{
	int nRow = ui.tableWidget->currentRow();
	moveRow(ui.tableWidget, nRow, nRow - 1);
}

void frmCameraSetUp::slot_MoveDown()
{
	int nRow = ui.tableWidget->currentRow();
	moveRow(ui.tableWidget, nRow, nRow + 2);
}

void frmCameraSetUp::slot_DeleteName()
{
	int rowIndex = ui.tableWidget->currentRow();
	if (rowIndex != -1)
	{
		QString str = ui.tableWidget->item(rowIndex, 0)->text();
		global_camera_content.remove(str);
		gVariable::camera_variable_link.remove(str);
		ui.tableWidget->removeRow(rowIndex);
	}
	int count = ui.tableWidget->rowCount();
	if (count == 0)
	{
		ui.lblType->clear();
		global_camera_content.clear();
		gVariable::camera_variable_link.clear();
	}
	//更新获取图像工具
	QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
	for (int i = 0; i < link_keys.length(); i++)
	{
		int key = link_keys[i];
		for (int j = 0; j < 20; j++)
		{
			if (j == key)
			{
				QConfig::ToolBase[key]->RunCommunicationLink("获取图像");
			}
		}
	}
}

void frmCameraSetUp::moveRow(QTableWidget* pTable, int nFrom, int nTo)
{
	if (pTable == NULL) return;
	pTable->setFocus();
	if (nFrom == nTo) return;
	if (nFrom < 0 || nTo < 0) return;
	int nRowCount = pTable->rowCount();
	if (nFrom >= nRowCount || nTo > nRowCount) return;
	if (nTo < nFrom) nFrom++; pTable->insertRow(nTo);
	int nCol = pTable->columnCount();
	for (int i = 0; i < nCol; i++)
	{
		pTable->setItem(nTo, i, pTable->takeItem(nFrom, i));
	}
	if (nFrom < nTo)
	{
		nTo--;
	}
	pTable->removeRow(nFrom); pTable->selectRow(nTo);
}
