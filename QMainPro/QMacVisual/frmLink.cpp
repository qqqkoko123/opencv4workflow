#include "frmLink.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QDesktopWidget>
#include "datavar.h"
using namespace std;

frmLink::frmLink(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowIcon(QIcon(":/res/ico/link.png"));
	//FramelessWindowHint属性设置窗口去除边框
	//WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	//设置窗体在屏幕中间位置
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	//设置窗口背景透明
	setAttribute(Qt::WA_TranslucentBackground);
	//初始化标题栏
	initTitleBar();
	form_load();
	slot_CreateList();
	connect(ui.tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_DoubleClicked(int, int)));
}

frmLink::~frmLink()
{
	if (this != nullptr)
	{
		this->deleteLater();
	}
}

void frmLink::initTitleBar()
{
	MyTitleBar* m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setBackgroundColor(3, 110, 95);
	m_titleBar->setStyleSheet("background-color: rgba(0, 0, 0, 0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/res/ico/link.png");
	m_titleBar->setTitleContent("数据链接");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmLink::paintEvent(QPaintEvent* event)
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

void frmLink::form_load()
{
	//设置表格列宽	
	ui.tableWidget->setColumnWidth(0, 50);
	ui.tableWidget->setColumnWidth(1, 203);
	ui.tableWidget->setColumnWidth(2, 300);
	ui.tableWidget->setColumnWidth(3, 232);
	//隐藏水平header
	ui.tableWidget->verticalHeader()->setVisible(false);
	//设置整行选中
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->horizontalHeader()->setDisabled(true);	
	//添加List	 	
	ItemModel = new QStandardItemModel(this);
	ui.listProcess->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
}

void frmLink::onButtonCloseClicked()
{
	//信号与槽解除连接
	disconnect(ui.listProcess, SIGNAL(clicked(QModelIndex)), this, SLOT(slot_ListClick(QModelIndex)));
	disconnect(ui.tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_DoubleClicked(int, int)));
	this->close();
	this->deleteLater();
}

void frmLink::slot_CreateList()
{
	//获取子控件
	objTabName = dataVar::fProItemTab->findChild<QTabWidget*>("ProItemTabWidget");
	objTreeName = dataVar::fProItemTab->findChild<QTreeWidget*>("ProItemTreeWidget");
	int flow = objTabName->currentIndex();  //索引号
	flow_index = 0;
	QTreeWidgetItemIterator it(objTreeName);  //遍历treeWidget
	QList<QTreeWidgetItem*> pro_keys = dataVar::fProItemTab->m_pro_value.uniqueKeys();
	for (int i = 0; i < (*it)->childCount(); i++)
	{
		QTreeWidgetItem* key = pro_keys[i];
		if ((*it)->child(flow) == pro_keys[i])
		{
			flow_index = dataVar::fProItemTab->m_pro_value.values(key).at(0);
		}
	}
	QVector<QString> FlowProItemList;
	FlowProItemList.reserve(100);
	FlowProItemList.clear();
	int item_id;
	QString flowPageName = objTabName->tabText(objTabName->currentIndex());
	QMap<QString, QtDragListWidget*>::iterator iter = dataVar::FlowProMap.begin();
	while (iter != dataVar::FlowProMap.end())
	{
		if (iter.key() == flowPageName)
		{
			TempDragListWidget = iter.value();
			FlowProItemList = TempDragListWidget->GetAllItemList();
			item_id = TempDragListWidget->GetCurrentItemId() - 1;
			break;
		}
		iter++;
	}
	//流程所在的索引位置	
	tool_name_buf = FlowProItemList[item_id];
	//添加List	 		
	ItemModel->removeRows(0, ItemModel->rowCount());
	//添加全局变量
	QStandardItem* item = new QStandardItem("全局变量");
	QPixmap pixmap = GetIcon(GetIconName("全局变量"));
	item->setIcon(pixmap);
	ItemModel->appendRow(item);
	for (int i = 0; i < item_id; i++)
	{
		//添加流程
		QStandardItem* item = new QStandardItem(FlowProItemList[i]);
		QPixmap pixmap = GetIcon(GetIconName(FlowProItemList[i]));
		item->setIcon(pixmap);
		ItemModel->appendRow(item);
	}
	ui.listProcess->setModel(ItemModel);
	connect(ui.listProcess, SIGNAL(clicked(QModelIndex)), this, SLOT(slot_ListClick(QModelIndex)));
}

void frmLink::slot_ListClick(QModelIndex index)
{
	index_process_modify = index.row();
	tool_name = index.data().toString();
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < tool_name.length(); k++)
	{
		if (!(tool_name[k] > '0' && tool_name[k] < '9'))
		{
			++str_count;			
		}
	}
	QString str_name_buf = tool_name.mid(0, str_count);
	QStringList toolNames;
	toolNames.reserve(100);
	toolNames.clear();
	toolNames << "全局变量" << "获取图像" << "图像显示" << "导出图像" << "预处理" << "图像拼接" << "图像修复" << "图像细化" << "图像翻转" << "图像旋转" << "透视变换" << "裁切图像" << "创建ROI" << "条形码识别" << "斑点分析" << "二维码识别"
		<< "字符识别" << "分类器" << "颜色识别" << "亮度检测" << "图像清晰度" << "轮廓特征选择" << "N点标定" << "畸变标定" << "测量标定" << "灰度匹配" << "形状匹配" << "目标跟踪" << "线性计算" << "寻找圆" << "寻找直线" << "拟合圆" << "拟合椭圆" << "拟合直线" << "获取边界点"
	    << "线圆交点" << "点+点" << "点+线" << "线线交点" << "查找圆缺角" << "边缘宽度测量"	<< "拟合平面" << "扩展库" << "跳转语句" << "判断语句" << "结束语句" << "脚本编辑" << "TCP/IP服务器" << "TCP/IP客户端" << "PLC通信" << "串口通信" << "通用I/O" << "延时" << "导出CSV" << "YoloV" << "OCR" << "二维码生成" << "自动打印";
	//清空Table
	int rowNum = ui.tableWidget->rowCount();
	for (int i = rowNum - 1; i >= 0; i--)
	{
		ui.tableWidget->removeRow(i);
	}
	switch (toolNames.indexOf(str_name_buf)) {
#pragma region 全局变量
	case 0:
		//全局变量		
		objTableName = dataVar::fGlobalVariable->findChild<QTableWidget*>("tableWidget");  //获取子控件
		row_count = objTableName->rowCount();
		ui.tableWidget->setRowCount(row_count);  //设置行数	
		for (int k = 0; k < row_count; k++)
		{
			item_number = new QTableWidgetItem(QString::number(k + 1));
			item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			item_number->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(k, 0, item_number);
			item_variable_name = new QTableWidgetItem(objTableName->item(k, 1)->text());
			item_variable_value = new QTableWidgetItem(objTableName->item(k, 2)->text());
			if (objTableName->item(k, 0)->text() == "Int")
			{
				item_variable_type = new QTableWidgetItem("Int");
			}
			else if (objTableName->item(k, 0)->text() == "Double")
			{
				item_variable_type = new QTableWidgetItem("Double");
			}
			else if (objTableName->item(k, 0)->text() == "QString")
			{
				item_variable_type = new QTableWidgetItem("QString");
			}
			else if (objTableName->item(k, 0)->text() == "Bool")
			{
				item_variable_type = new QTableWidgetItem("Bool");
			}
			else if (objTableName->item(k, 0)->text() == "QPoint")
			{
				item_variable_type = new QTableWidgetItem("QPoint");
			}
			else if (objTableName->item(k, 0)->text() == "QPointF")
			{
				item_variable_type = new QTableWidgetItem("QPointF");
			}
			else if (objTableName->item(k, 0)->text() == "cv::Point")
			{
				item_variable_type = new QTableWidgetItem("cv::Point");
			}
			else if (objTableName->item(k, 0)->text() == "cv::Point2f")
			{
				item_variable_type = new QTableWidgetItem("cv::Point2f");
			}
			else if (objTableName->item(k, 0)->text() == "cv::Point3f")
			{
				item_variable_type = new QTableWidgetItem("cv::Point3f");
			}
			else if (objTableName->item(k, 0)->text() == "cv::Point3d")
			{
				item_variable_type = new QTableWidgetItem("cv::Point3d");
			}
			else if (objTableName->item(k, 0)->text() == "Float[]")
			{
				item_variable_type = new QTableWidgetItem("Float[]");
			}
			else if (objTableName->item(k, 0)->text() == "Double[]")
			{
				item_variable_type = new QTableWidgetItem("Double[]");
			}
			item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			item_variable_name->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(k, 1, item_variable_name);
			item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			item_variable_value->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(k, 2, item_variable_value);
			item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			item_variable_type->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(k, 3, item_variable_type);
		}
		break;
#pragma endregion

#pragma region 图像处理
	case 1:
		//获取图像		
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 2:
		//图像显示		
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputViewImage");
						item_variable_type = new QTableWidgetItem("QImage");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 3:
		//导出图像		
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;	
	case 4:
		//预处理		
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 5:
		//图像拼接		
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 6:
		//图像修复
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 7:
		//图像细化
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 8:
		//图像翻转
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 9:
		//图像旋转
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 10:
		//透视变换
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 11:
		//裁切图像
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 12:
		//创建ROI
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".矩形");
						item_variable_value = new QTableWidgetItem("PublicImageProcess.CvRect");
						item_variable_type = new QTableWidgetItem("cv::Rect");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".旋转矩形");
						item_variable_value = new QTableWidgetItem("PublicImageProcess.CvRotatedRect");
						item_variable_type = new QTableWidgetItem("cv::RotatedRect");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 检测识别
	case 13:
		//条形码识别
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".条形码");
						item_variable_value = new QTableWidgetItem("PublicDetect.Code");
						item_variable_type = new QTableWidgetItem("vector<QString>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 14:
		//斑点分析		
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;					
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".斑点个数");
						item_variable_value = new QTableWidgetItem("PublicDetect.Quantity");
						item_variable_type = new QTableWidgetItem("Int");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;					
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 15:
		//二维码识别
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".二维码");
						item_variable_value = new QTableWidgetItem("PublicDetect.Code");
						item_variable_type = new QTableWidgetItem("vector<QString>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 16:
		//字符识别
		
		break;
	case 17:
		//分类器
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".类别");
						item_variable_value = new QTableWidgetItem("PublicDetect.Category");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 18:
		//颜色识别
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;					
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".相似度");
						item_variable_value = new QTableWidgetItem("PublicDetect.Score");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 19:
		//亮度检测
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".亮度");
						item_variable_value = new QTableWidgetItem("PublicDetect.Brightness");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 20:
		//图像清晰度
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".清晰度");
						item_variable_value = new QTableWidgetItem("PublicDetect.Clarity");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;		
	case 21:
		//轮廓特征选择
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(5);  //设置行数	
				for (int k = 0; k < 5; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;					
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".轮廓");
						item_variable_value = new QTableWidgetItem("PublicDetect.Contours");
						item_variable_type = new QTableWidgetItem("vector<vector<cv::Point>>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".面积");
						item_variable_value = new QTableWidgetItem("PublicDetect.Areas");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".重心");
						item_variable_value = new QTableWidgetItem("PublicDetect.CenterPoints");
						item_variable_type = new QTableWidgetItem("vector<cv::Point2f>");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 标定工具
	case 22:
		//N点标定
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(9);  //设置行数	
				for (int k = 0; k < 9; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".N点标定参数");
						item_variable_value = new QTableWidgetItem("PublicCalib.EstimateAffine");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".旋转中心");
						item_variable_value = new QTableWidgetItem("PublicCalib.RotateCenter");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".像素当量X");
						item_variable_value = new QTableWidgetItem("PublicCalib.PixelEquivalentX");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".像素当量Y");
						item_variable_value = new QTableWidgetItem("PublicCalib.PixelEquivalentY");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 5:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".基准点1");
						item_variable_value = new QTableWidgetItem("PublicCalib.DatumPoint1");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 6:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".基准点2");
						item_variable_value = new QTableWidgetItem("PublicCalib.DatumPoint2");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 7:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".基准角度");
						item_variable_value = new QTableWidgetItem("PublicCalib.DatumAngle");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 8:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 23:
		//畸变标定
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".内参K");
						item_variable_value = new QTableWidgetItem("PublicCalib.CameraMatrix");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".畸变系数");
						item_variable_value = new QTableWidgetItem("PublicCalib.DistCoeffs");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 24:
		//测量标定
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".像素当量X");
						item_variable_value = new QTableWidgetItem("PublicCalib.PixelEquivalentX");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".像素当量Y");
						item_variable_value = new QTableWidgetItem("PublicCalib.PixelEquivalentY");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 对位工具
	case 25:
		//灰度匹配		
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(6);  //设置行数	
				for (int k = 0; k < 6; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".匹配中心坐标");
						item_variable_value = new QTableWidgetItem("PublicTPosition.Center");
						item_variable_type = new QTableWidgetItem("vector<cv::Point2f>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".匹配角度");
						item_variable_value = new QTableWidgetItem("PublicTPosition.Angle");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".匹配分数");
						item_variable_value = new QTableWidgetItem("PublicTPosition.OutScore");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".匹配基准中心");
						item_variable_value = new QTableWidgetItem("PublicTPosition.DatumCenter");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 5:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;	
	case 26:
		//形状匹配		
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(6);  //设置行数	
				for (int k = 0; k < 6; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".匹配中心坐标");
						item_variable_value = new QTableWidgetItem("PublicTPosition.Center");
						item_variable_type = new QTableWidgetItem("vector<cv::Point2f>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".匹配角度");
						item_variable_value = new QTableWidgetItem("PublicTPosition.Angle");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".匹配分数");
						item_variable_value = new QTableWidgetItem("PublicTPosition.OutScore");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".匹配基准中心");
						item_variable_value = new QTableWidgetItem("PublicTPosition.DatumCenter");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 5:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 27:
		//目标跟踪
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".旋转矩形");
						item_variable_value = new QTableWidgetItem("PublicTPosition.CvRotatedRect");
						item_variable_type = new QTableWidgetItem("cv::RotatedRect");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 28:
		//线性计算
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {					
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".移动量X");
						item_variable_value = new QTableWidgetItem("PublicTPosition.MovingDistanceX");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".移动量Y");
						item_variable_value = new QTableWidgetItem("PublicTPosition.MovingDistanceY");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".世界坐标点");
						item_variable_value = new QTableWidgetItem("PublicTPosition.WorldCoordinatePoint");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;					
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 几何工具/测量
	case 29:
		//寻找圆
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".中心坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Center");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".半径");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Radius");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 30:
		//寻找直线
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".斜率");
						item_variable_value = new QTableWidgetItem("PublicGeometry.k");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".截距");
						item_variable_value = new QTableWidgetItem("PublicGeometry.b");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 31:
		//拟合圆
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".中心坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Center");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".半径");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Radius");
						item_variable_type = new QTableWidgetItem("Double");
						break;					
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 32:
		//拟合椭圆
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(6);  //设置行数	
				for (int k = 0; k < 6; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".中心坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Center");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".角度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Angle");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".长轴长度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Length1");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".短轴长度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Length2");
						item_variable_type = new QTableWidgetItem("Double");
						break;							
					case 5:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 33:
		//拟合直线
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;					
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".斜率");
						item_variable_value = new QTableWidgetItem("PublicGeometry.k");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".截距");
						item_variable_value = new QTableWidgetItem("PublicGeometry.b");
						item_variable_type = new QTableWidgetItem("Double");
						break;		
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 34:
		//获取边界点
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;					
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".点集");
						item_variable_value = new QTableWidgetItem("PublicGeometry.BorderPoints");
						item_variable_type = new QTableWidgetItem("vector<cv::Point2f>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 35:
		//线圆交点
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".交点坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Intersections");
						item_variable_type = new QTableWidgetItem("vector<cv::Point2f>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 36:
		//点+点	
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(5);  //设置行数	
				for (int k = 0; k < 5; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".中心坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Center");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".角度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Angle");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".距离");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Distance");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 37:
		//点+线
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".垂足坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Pedal");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".距离");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Distance");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 38:
		//线线交点
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".交点坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Intersection");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".夹角");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Angle");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 39:
		//查找圆缺角
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(5);  //设置行数	
				for (int k = 0; k < 5; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".圆心坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Center");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".垂足坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Pedal");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".角度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Angle");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 40:
		//边缘宽度测量
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;					
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".边缘宽度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Distance");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 三维检测
	case 41:
		//拟合平面
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".平面参数");
						item_variable_value = new QTableWidgetItem("PublicThreeD.Flatness");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".点到平面距离");
						item_variable_value = new QTableWidgetItem("PublicThreeD.Distance");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;	
#pragma endregion

#pragma region 逻辑工具
	case 42:
		//扩展库		
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 43:
		//跳转语句
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 44:
		//判断语句
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 45:
		//结束语句
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:						
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 46:
		//脚本编辑
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 通讯工具
	case 47:
		//TCP/IP服务器
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".接收数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.InputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".发送数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.OutputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 48:
		//TCP/IP客户端
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".接收数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.InputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".发送数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.OutputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 49:
		//PLC通信
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".寄存器读取数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.RegisterReadData");
						item_variable_type = new QTableWidgetItem("QVector<int>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".寄存器写入数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.RegisterWriteData");
						item_variable_type = new QTableWidgetItem("QVector<int>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 50:
		//串口通信
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".接收数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.InputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".发送数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.OutputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 51:
		//通用I/O
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".输入点");
						item_variable_value = new QTableWidgetItem("PublicCommunication.InPutIoX");
						item_variable_type = new QTableWidgetItem("QVector<Bool>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 系统工具
	case 52:
		//延时		
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 53:
		//导出CSV
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {					
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;	
	case 54:
		//YoloV13
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".类别");
						item_variable_value = new QTableWidgetItem("PublicDetect.Category");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 55:
		//OCR识别
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".识别内容");
						item_variable_value = new QTableWidgetItem("PublicDetect.Code");
						item_variable_type = new QTableWidgetItem("vector<QString>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 56:
		//二维码生成
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".二维码");
						item_variable_value = new QTableWidgetItem("PublicDetect.Code");
						item_variable_type = new QTableWidgetItem("vector<QString>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 57:
		//自动打印
		for (int j = 0; j < QConfig::ToolBase[flow_index]->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".图像");
						item_variable_value = new QTableWidgetItem("PublicImage.OutputImage");
						item_variable_type = new QTableWidgetItem("cv::Mat");
						break;
					/*case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".二维码");
						item_variable_value = new QTableWidgetItem("PublicDetect.Code");
						item_variable_type = new QTableWidgetItem("vector<QString>");
						break;*/
					case 1:
						item_variable_name = new QTableWidgetItem(QConfig::ToolBase[flow_index]->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion
	}	
}

void frmLink::slot_DoubleClicked(int row, int column)
{
	dataVar::str_link = ui.tableWidget->item(row, 1)->text();
	QConfig::ToolBase[flow_index]->RunToolLink(tool_name_buf, dataVar::int_link, dataVar::str_link);
	onButtonCloseClicked();
}

// 获取图标
QPixmap frmLink::GetIcon(QString fileName)
{
	return IconHelper::Instance()->getPixmap(fileName);
}

// 获取图标路径
QString frmLink::GetIconName(QString Name)
{
	QString IconName;
	if (Name.contains("全局变量")) IconName = ":/res/ico/var.ico";
	if (Name.contains("获取图像")) IconName = ":/res/ico/image_source.png";
	if (Name.contains("图像显示")) IconName = ":/res/ico/image_view.ico";
	if (Name.contains("导出图像")) IconName = ":/res/ico/export_image.png";
	if (Name.contains("斑点分析")) IconName = ":/res/ico/blob.png";
	if (Name.contains("预处理")) IconName = ":/res/ico/morphology.png";
	if (Name.contains("图像拼接")) IconName = ":/res/ico/image_splice.png";
	if (Name.contains("图像修复")) IconName = ":/res/ico/repair.png";
	if (Name.contains("图像细化")) IconName = ":/res/ico/skeleton.png";
	if (Name.contains("图像翻转")) IconName = ":/res/ico/flip.png";
	if (Name.contains("图像旋转")) IconName = ":/res/ico/rotate.png";
	if (Name.contains("透视变换")) IconName = ":/res/ico/perspective.png";
	if (Name.contains("裁切图像")) IconName = ":/res/ico/crop.png";
	if (Name.contains("创建ROI")) IconName = ":/res/ico/roi.png";
	if (Name.contains("条形码识别")) IconName = ":/res/ico/barcode.png";
	if (Name.contains("二维码识别")) IconName = ":/res/ico/qrcode.png";
	if (Name.contains("字符识别")) IconName = ":/res/ico/ocr.png";
	if (Name.contains("分类器")) IconName = ":/res/ico/classifier.png";
	if (Name.contains("颜色识别")) IconName = ":/res/ico/color_r.png";
	if (Name.contains("亮度检测")) IconName = ":/res/ico/brightness.png";
	if (Name.contains("图像清晰度")) IconName = ":/res/ico/clarity.png";	
	if (Name.contains("轮廓特征选择")) IconName = ":/res/ico/shape.png";
	if (Name.contains("N点标定")) IconName = ":/res/ico/ert_calib.png";
	if (Name.contains("畸变标定")) IconName = ":/res/ico/distortion_calib.png";
	if (Name.contains("测量标定")) IconName = ":/res/ico/measure_calib.png";
	if (Name.contains("灰度匹配")) IconName = ":/res/ico/match.png";	
	if (Name.contains("形状匹配")) IconName = ":/res/ico/shape_match.png";
	if (Name.contains("目标跟踪")) IconName = ":/res/ico/track.png";
	if (Name.contains("线性计算")) IconName = ":/res/ico/affine.png";
	if (Name.contains("线圆交点")) IconName = ":/res/ico/line_circle.png";
	if (Name.contains("点+点")) IconName = ":/res/ico/point_point.png";
	if (Name.contains("点+线")) IconName = ":/res/ico/point_l.png";
	if (Name.contains("线线交点")) IconName = ":/res/ico/intersection.png";
	if (Name.contains("查找圆缺角")) IconName = ":/res/ico/rounded_c.png";
	if (Name.contains("寻找圆")) IconName = ":/res/ico/find_circle.png";
	if (Name.contains("寻找直线")) IconName = ":/res/ico/find_line.png";
	if (Name.contains("拟合圆")) IconName = ":/res/ico/fit_circle.png";
	if (Name.contains("拟合椭圆")) IconName = ":/res/ico/fit_ellipse.png";
	if (Name.contains("拟合直线")) IconName = ":/res/ico/fit_line.png";
	if (Name.contains("获取边界点")) IconName = ":/res/ico/border_point.png";
	if (Name.contains("边缘宽度测量")) IconName = ":/res/ico/edge.png";
	if (Name.contains("拟合平面")) IconName = ":/res/ico/flatness.png";	
	if (Name.contains("扩展库")) IconName = ":/res/ico/extension_library.png";
	if (Name.contains("跳转语句")) IconName = ":/res/ico/goto.png";
	if (Name.contains("判断语句")) IconName = ":/res/ico/logic_judge.png";
	if (Name.contains("结束语句")) IconName = ":/res/ico/end.png";
	if (Name.contains("脚本编辑")) IconName = ":/res/ico/script_edit.png";
	if (Name.contains("TCP/IP服务器")) IconName = ":/res/ico/server.png";
	if (Name.contains("TCP/IP客户端")) IconName = ":/res/ico/client.png";
	if (Name.contains("PLC通信")) IconName = ":/res/ico/plc_communicate.png";
	if (Name.contains("串口通信")) IconName = ":/res/ico/serial_port.png";
	if (Name.contains("通用I/O")) IconName = ":/res/ico/general_io.png";
	if (Name.contains("延时")) IconName = ":/res/ico/delay.png";
	if (Name.contains("导出CSV")) IconName = ":/res/ico/export_csv.png";
	if (Name.contains("YoloV13")) IconName = ":/res/ico/classifier.png";
	if (Name.contains("OCR")) IconName = ":/res/ico/ocr.png";
	if (Name.contains("二维码生成")) IconName = ":/res/ico/qrcode.png";
	if (Name.contains("自动打印")) IconName = ":/res/ico/print.png";
	return IconName;
}
