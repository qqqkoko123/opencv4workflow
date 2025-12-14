#include "frmGlobalVariable.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QDesktopWidget>
#include <QPainter>
#include "datavar.h"
#include "gvariable.h"
#include "qmutex.h"

frmGlobalVariable::frmGlobalVariable(QWidget* parent)
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
	this->setWindowIcon(QIcon(":/res/ico/var.ico"));
	//初始化标题栏
	initTitleBar();
	h1 = QThread::currentThread();
	//设置表格列宽	
	ui.tableWidget->setColumnWidth(0, 120);
	ui.tableWidget->setColumnWidth(1, 200);
	ui.tableWidget->setColumnWidth(2, 273);
	ui.tableWidget->setColumnWidth(3, 237);
	//隐藏水平header
	ui.tableWidget->verticalHeader()->setVisible(false);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);  //设置只能单选	
	connect(this, &frmGlobalVariable::sig_GlobalValue, this, &frmGlobalVariable::slot_GlobalValue, Qt::BlockingQueuedConnection);
	ReadOnlyDelegate* readOnlyDelegate = new ReadOnlyDelegate(this);
	ui.tableWidget->setItemDelegateForColumn(0, readOnlyDelegate); //设置第1列只读	
}

frmGlobalVariable::~frmGlobalVariable()
{
	this->deleteLater();
}

void frmGlobalVariable::initTitleBar()
{
	MyTitleBar* m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setBackgroundColor(3, 110, 95);
	m_titleBar->setStyleSheet("background-color: rgba(0, 0, 0,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/res/ico/var.ico");
	m_titleBar->setTitleContent("全局变量");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmGlobalVariable::paintEvent(QPaintEvent* event)
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

void frmGlobalVariable::onButtonCloseClicked()
{
	try
	{
		QStringList m_VarNameList;
		m_VarNameList.reserve(1000);
		m_VarNameList.clear();
		gVariable::global_variable_link.clear();
		int row_count = ui.tableWidget->rowCount();
		for (int m = 0; m < row_count; m++)
		{
			m_VarNameList.append(ui.tableWidget->item(m, 1)->text());
		}
		QMap<QString, int> m_qmap;
		for (int m = 0; m < m_VarNameList.size(); m++)
		{
			m_qmap.insert(m_VarNameList[m], m);
		}
		QList<QString> keys;
		keys.reserve(1000);
		keys.clear();
		keys = m_qmap.uniqueKeys();
		if (keys.length() < row_count)
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("变量名称不能重复！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "变量名称不能重复！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
			return;
		}
		for (int i = 0; i < row_count; i++)
		{
			if (ui.tableWidget->item(i, 0)->text() == "Int")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				if (ui.tableWidget->item(i, 2)->text().contains(QRegExp("[0-9]+$")) == false || ui.tableWidget->item(i, 2)->text().contains(QRegExp("[a-zA-Z{()}]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Int类型只能输入数字！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "Int类型只能输入数字！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				gVariable::GlobalVar.global_type = "Int";
				gVariable::GlobalVar.global_int_value = ui.tableWidget->item(i, 2)->text().toInt();
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "Double")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				if (ui.tableWidget->item(i, 2)->text().contains(QRegExp("[0-9]+$")) == false || ui.tableWidget->item(i, 2)->text().contains(QRegExp("[a-zA-Z{()}]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Double类型只能输入数字！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "Double类型只能输入数字！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				gVariable::GlobalVar.global_type = "Double";
				gVariable::GlobalVar.global_double_value = ui.tableWidget->item(i, 2)->text().toDouble();
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "QString")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				gVariable::GlobalVar.global_type = "QString";
				gVariable::GlobalVar.global_qstring_value = ui.tableWidget->item(i, 2)->text();
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "Bool")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				bool state;
				if (ui.tableWidget->item(i, 2)->text() == "false")
				{
					state = false;
				}
				else if (ui.tableWidget->item(i, 2)->text() == "true")
				{
					state = true;
				}
				else
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Bool类型输入条件错误！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "Bool类型输入条件错误！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				gVariable::GlobalVar.global_type = "Bool";
				gVariable::GlobalVar.global_bool_value = state;
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "QPoint")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				QStringList list = ui.tableWidget->item(i, 2)->text().split(QRegExp("[(,)]"));
				if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("QPoint输入条件错误！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "QPoint输入条件错误！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				QPoint qpoint;
				qpoint.setX(list[1].toInt());
				qpoint.setY(list[2].toInt());
				gVariable::GlobalVar.global_type = "QPoint";
				gVariable::GlobalVar.global_qpoint_value = qpoint;
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "QPointF")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				QStringList list = ui.tableWidget->item(i, 2)->text().split(QRegExp("[(,)]"));
				if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("QPointF输入条件错误！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "QPointF输入条件错误！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				QPointF qpointf;
				qpointf.setX(list[1].toFloat());
				qpointf.setY(list[2].toFloat());
				gVariable::GlobalVar.global_type = "QPointF";
				gVariable::GlobalVar.global_qpointf_value = qpointf;
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "cv::Point")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				QStringList list = ui.tableWidget->item(i, 2)->text().split(QRegExp("[(,)]"));
				if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("cv::Point输入条件错误！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "cv::Point输入条件错误！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				cv::Point cvpoint;
				cvpoint.x = list[1].toInt();
				cvpoint.y = list[2].toInt();
				gVariable::GlobalVar.global_type = "cv::Point";
				gVariable::GlobalVar.global_cvpoint_value = cvpoint;
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "cv::Point2f")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				QStringList list = ui.tableWidget->item(i, 2)->text().split(QRegExp("[(,)]"));
				if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("cv::Point2f输入条件错误！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "cv::Point2f输入条件错误！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				cv::Point2f cvpoint2f;
				cvpoint2f.x = list[1].toFloat();
				cvpoint2f.y = list[2].toFloat();
				gVariable::GlobalVar.global_type = "cv::Point2f";
				gVariable::GlobalVar.global_cvpoint2f_value = cvpoint2f;
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "cv::Point3f")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				QStringList list = ui.tableWidget->item(i, 2)->text().split(QRegExp("[(,,)]"));
				if (list.size() != 5 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true || list[4].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("cv::Point3f输入条件错误！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "cv::Point3f输入条件错误！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				cv::Point3f cvpoint3f;
				cvpoint3f.x = list[1].toFloat();
				cvpoint3f.y = list[2].toFloat();
				cvpoint3f.z = list[3].toFloat();
				gVariable::GlobalVar.global_type = "cv::Point3f";
				gVariable::GlobalVar.global_cvpoint3f_value = cvpoint3f;
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "cv::Point3d")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				QStringList list = ui.tableWidget->item(i, 2)->text().split(QRegExp("[(,,)]"));
				if (list.size() != 5 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true || list[4].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("cv::Point3d输入条件错误！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "cv::Point3d输入条件错误！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				cv::Point3d cvpoint3d;
				cvpoint3d.x = list[1].toDouble();
				cvpoint3d.y = list[2].toDouble();
				cvpoint3d.z = list[3].toDouble();
				gVariable::GlobalVar.global_type = "cv::Point3d";
				gVariable::GlobalVar.global_cvpoint3d_value = cvpoint3d;
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "Float[]")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				if (ui.tableWidget->item(i, 2)->text().contains(QRegExp("[0-9{,}]+$")) == false || ui.tableWidget->item(i, 2)->text().contains(QRegExp("[，a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Float[]类型只能输入数字！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "Float[]类型只能输入数字！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				gVariable::GlobalVar.global_type = "Float[]";
				gVariable::GlobalVar.global_array_float_value.reserve(1000);
				gVariable::GlobalVar.global_array_float_value.clear();
				if (ui.tableWidget->item(i, 2)->text().mid(0, 1) != "{" || ui.tableWidget->item(i, 2)->text().mid(ui.tableWidget->item(i, 2)->text().length() - 1, 1) != "}")
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Float[]类型未包含{}！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "Float[]类型未包含{}！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				QString s_float = ui.tableWidget->item(i, 2)->text().remove(QRegExp("[{}]"));
				QStringList list_float = s_float.split(",", QString::SkipEmptyParts);
				for (int m = 0; m < list_float.count(); m++)
				{
					gVariable::GlobalVar.global_array_float_value.push_back(list_float[m].toFloat());
				}
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
			else if (ui.tableWidget->item(i, 0)->text() == "Double[]")
			{
				if (ui.tableWidget->item(i, 1)->text().contains(QRegExp("[.]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("不允许输入“.”符号！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "不允许输入“.”符号！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				if (ui.tableWidget->item(i, 2)->text().contains(QRegExp("[0-9{,}]+$")) == false || ui.tableWidget->item(i, 2)->text().contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Double[]类型只能输入数字！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "Double[]类型只能输入数字！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				gVariable::GlobalVar.global_type = "Double[]";
				gVariable::GlobalVar.global_array_double_value.reserve(1000);
				gVariable::GlobalVar.global_array_double_value.clear();
				if (ui.tableWidget->item(i, 2)->text().mid(0, 1) != "{" || ui.tableWidget->item(i, 2)->text().mid(ui.tableWidget->item(i, 2)->text().length() - 1, 1) != "}")
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Double[]类型未包含{}！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "Double[]类型未包含{}！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();
					return;
				}
				QString s_double = ui.tableWidget->item(i, 2)->text().remove(QRegExp("[{}]"));
				QStringList list_double = s_double.split(",", QString::SkipEmptyParts);
				for (int m = 0; m < list_double.count(); m++)
				{
					gVariable::GlobalVar.global_array_double_value.push_back(list_double[m].toDouble());
				}
				gVariable::global_variable_link.insert(ui.tableWidget->item(i, 1)->text(), gVariable::GlobalVar);
			}
		}
		//更新全局变量
		QList<int> link_keys = dataVar::all_link_process.uniqueKeys();
		for (int i = 0; i < link_keys.length(); i++)
		{
			int key = link_keys[i];
			for (int j = 0; j < 20; j++)
			{
				if (j == key)
				{
					QConfig::ToolBase[key]->RunAllToolLink();
				}
			}
		}
		this->close();
	}
	catch (std::exception& ex)
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log(ex.what());
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", ex.what());
		msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		msgBox.exec();
	}
}

QString frmGlobalVariable::slot_SetGlobalValue(const QString strVar, const QString value, const int flowIndex)
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);
	h2 = QThread::currentThread();
	if (h1 != h2)
	{
		QString result_msg = emit sig_GlobalValue(strVar, value, flowIndex);
		if (result_msg == "p_error")
		{
			return result_msg;
		}
	}
	else
	{
		//获取全局变量值
		QList<QString> global_keys;
		global_keys.reserve(300);
		global_keys.clear();
		global_keys = gVariable::global_variable_link.uniqueKeys();
		for (int k = 0; k < global_keys.length(); k++)
		{
			QString key = global_keys[k];
			if (gVariable::global_variable_link.value(key).global_type == "Int")
			{
				if (strVar == key)
				{
					if (value.contains(QRegExp("[0-9]+$")) == false || value.contains(QRegExp("[a-zA-Z{()}]")) == true)
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("Int类型只能输入数字！");
						return "p_error";
					}
					gVariable::GlobalVar.global_type = "Int";
					gVariable::GlobalVar.global_int_value = value.toInt();
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Double")
			{
				if (strVar == key)
				{
					if (value.contains(QRegExp("[0-9]+$")) == false || value.contains(QRegExp("[a-zA-Z{()}]")) == true)
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("Double类型只能输入数字！");
						return "p_error";
					}
					gVariable::GlobalVar.global_type = "Double";
					gVariable::GlobalVar.global_double_value = value.toDouble();
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "QString")
			{
				if (strVar == key)
				{

					gVariable::GlobalVar.global_type = "QString";
					gVariable::GlobalVar.global_qstring_value = value;
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Bool")
			{
				if (strVar == key)
				{
					bool state;
					if (value == "false")
					{
						state = false;
					}
					else if (value == "true")
					{
						state = true;
					}
					else
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("Bool类型输入条件错误！");
						return "p_error";
					}
					gVariable::GlobalVar.global_type = "Bool";
					gVariable::GlobalVar.global_bool_value = state;
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "QPoint")
			{
				if (strVar == key)
				{
					QStringList list = value.split(QRegExp("[(,)]"));
					if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("QPoint输入条件错误！");
						return "p_error";
					}
					QPoint qpoint;
					qpoint.setX(list[1].toInt());
					qpoint.setY(list[2].toInt());
					gVariable::GlobalVar.global_type = "QPoint";
					gVariable::GlobalVar.global_qpoint_value = qpoint;
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "QPointF")
			{
				if (strVar == key)
				{
					QStringList list = value.split(QRegExp("[(,)]"));
					if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("QPointF输入条件错误！");
						return "p_error";
					}
					QPointF qpointf;
					qpointf.setX(list[1].toFloat());
					qpointf.setY(list[2].toFloat());
					gVariable::GlobalVar.global_type = "QPointF";
					gVariable::GlobalVar.global_qpointf_value = qpointf;
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point")
			{
				if (strVar == key)
				{
					QStringList list = value.split(QRegExp("[(,)]"));
					if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("cv::Point输入条件错误！");
						return "p_error";
					}
					cv::Point cvpoint;
					cvpoint.x = list[1].toInt();
					cvpoint.y = list[2].toInt();
					gVariable::GlobalVar.global_type = "cv::Point";
					gVariable::GlobalVar.global_cvpoint_value = cvpoint;
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point2f")
			{
				if (strVar == key)
				{
					QStringList list = value.split(QRegExp("[(,)]"));
					if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("cv::Point2f输入条件错误！");
						return "p_error";
					}
					cv::Point2f cvpoint2f;
					cvpoint2f.x = list[1].toFloat();
					cvpoint2f.y = list[2].toFloat();
					gVariable::GlobalVar.global_type = "cv::Point2f";
					gVariable::GlobalVar.global_cvpoint2f_value = cvpoint2f;
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point3f")
			{
				if (strVar == key)
				{
					QStringList list = value.split(QRegExp("[(,,)]"));
					if (list.size() != 5 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true || list[4].contains(QRegExp("[a-zA-Z]")) == true)
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("cv::Point3f输入条件错误！");
						return "p_error";
					}
					cv::Point3f cvpoint3f;
					cvpoint3f.x = list[1].toFloat();
					cvpoint3f.y = list[2].toFloat();
					cvpoint3f.z = list[3].toFloat();
					gVariable::GlobalVar.global_type = "cv::Point3f";
					gVariable::GlobalVar.global_cvpoint3f_value = cvpoint3f;
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point3d")
			{
				if (strVar == key)
				{
					QStringList list = value.split(QRegExp("[(,,)]"));
					if (list.size() != 5 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true || list[4].contains(QRegExp("[a-zA-Z]")) == true)
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("cv::Point3d输入条件错误！");
						return "p_error";
					}
					cv::Point3d cvpoint3d;
					cvpoint3d.x = list[1].toDouble();
					cvpoint3d.y = list[2].toDouble();
					cvpoint3d.z = list[3].toDouble();
					gVariable::GlobalVar.global_type = "cv::Point3d";
					gVariable::GlobalVar.global_cvpoint3d_value = cvpoint3d;
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Float[]")
			{
				if (strVar == key)
				{
					if (value.contains(QRegExp("[0-9{,}]+$")) == false || value.contains(QRegExp("[，a-zA-Z]")) == true)
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("Float[]类型只能输入数字！");
						return "p_error";
					}
					gVariable::GlobalVar.global_type = "Float[]";
					gVariable::GlobalVar.global_array_float_value.reserve(1000);
					gVariable::GlobalVar.global_array_float_value.clear();
					if (value.mid(0, 1) != "{" || value.mid(value.length() - 1, 1) != "}")
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("Float[]类型未包含{}！");
						return "p_error";
					}
					QString s_float = value.mid(1, value.length() - 2);
					QStringList list_float = s_float.split(",", QString::SkipEmptyParts);
					for (int m = 0; m < list_float.count(); m++)
					{
						gVariable::GlobalVar.global_array_float_value.push_back(list_float[m].toFloat());
					}
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Double[]")
			{
				if (strVar == key)
				{
					if (value.contains(QRegExp("[0-9{,}]+$")) == false || value.contains(QRegExp("[a-zA-Z]")) == true)
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("Double[]类型只能输入数字！");
						return "p_error";
					}
					gVariable::GlobalVar.global_type = "Double[]";
					gVariable::GlobalVar.global_array_double_value.reserve(1000);
					gVariable::GlobalVar.global_array_double_value.clear();
					if (value.mid(0, 1) != "{" || value.mid(value.length() - 1, 1) != "}")
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("Double[]类型未包含{}！");
						return "p_error";
					}
					QString s_double = value.mid(1, value.length() - 2);
					QStringList list_double = s_double.split(",", QString::SkipEmptyParts);
					for (int m = 0; m < list_double.count(); m++)
					{
						gVariable::GlobalVar.global_array_double_value.push_back(list_double[m].toDouble());
					}
					gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
				}
			}
		}
		//更新全局变量
		QConfig::ToolBase[flowIndex]->RunAllToolLink();
		//更新列表
		int row_count = ui.tableWidget->rowCount();
		int intVarState = 0;
		for (int i = 0; i < row_count; i++)
		{
			if (ui.tableWidget->item(i, 1)->text() == strVar)
			{
				ui.tableWidget->item(i, 2)->setText(value);
				intVarState = 1;
			}
		}
		if (intVarState == 0)
		{
			return "p_error";
		}
	}
	return QString();
}

QString frmGlobalVariable::slot_GlobalValue(const QString strVar, const QString value, const int flowIndex)
{	
	//获取全局变量值
	QList<QString> global_keys;
	global_keys.reserve(300);
	global_keys.clear();
	global_keys = gVariable::global_variable_link.uniqueKeys();
	for (int k = 0; k < global_keys.length(); k++)
	{
		QString key = global_keys[k];
		if (gVariable::global_variable_link.value(key).global_type == "Int")
		{
			if (strVar == key)
			{
				if (value.contains(QRegExp("[0-9]+$")) == false || value.contains(QRegExp("[a-zA-Z{()}]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Int类型只能输入数字！");
					return "p_error";
				}
				gVariable::GlobalVar.global_type = "Int";
				gVariable::GlobalVar.global_int_value = value.toInt();
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "Double")
		{
			if (strVar == key)
			{
				if (value.contains(QRegExp("[0-9]+$")) == false || value.contains(QRegExp("[a-zA-Z{()}]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Double类型只能输入数字！");
					return "p_error";
				}
				gVariable::GlobalVar.global_type = "Double";
				gVariable::GlobalVar.global_double_value = value.toDouble();
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "QString")
		{
			if (strVar == key)
			{

				gVariable::GlobalVar.global_type = "QString";
				gVariable::GlobalVar.global_qstring_value = value;
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "Bool")
		{
			if (strVar == key)
			{
				bool state;
				if (value == "false")
				{
					state = false;
				}
				else if (value == "true")
				{
					state = true;
				}
				else
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Bool类型输入条件错误！");
					return "p_error";
				}
				gVariable::GlobalVar.global_type = "Bool";
				gVariable::GlobalVar.global_bool_value = state;
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "QPoint")
		{
			if (strVar == key)
			{
				QStringList list = value.split(QRegExp("[(,)]"));
				if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("QPoint输入条件错误！");
					return "p_error";
				}
				QPoint qpoint;
				qpoint.setX(list[1].toInt());
				qpoint.setY(list[2].toInt());
				gVariable::GlobalVar.global_type = "QPoint";
				gVariable::GlobalVar.global_qpoint_value = qpoint;
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "QPointF")
		{
			if (strVar == key)
			{
				QStringList list = value.split(QRegExp("[(,)]"));
				if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("QPointF输入条件错误！");
					return "p_error";
				}
				QPointF qpointf;
				qpointf.setX(list[1].toFloat());
				qpointf.setY(list[2].toFloat());
				gVariable::GlobalVar.global_type = "QPointF";
				gVariable::GlobalVar.global_qpointf_value = qpointf;
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "cv::Point")
		{
			if (strVar == key)
			{
				QStringList list = value.split(QRegExp("[(,)]"));
				if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("cv::Point输入条件错误！");
					return "p_error";
				}
				cv::Point cvpoint;
				cvpoint.x = list[1].toInt();
				cvpoint.y = list[2].toInt();
				gVariable::GlobalVar.global_type = "cv::Point";
				gVariable::GlobalVar.global_cvpoint_value = cvpoint;
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "cv::Point2f")
		{
			if (strVar == key)
			{
				QStringList list = value.split(QRegExp("[(,)]"));
				if (list.size() != 4 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("cv::Point2f输入条件错误！");
					return "p_error";
				}
				cv::Point2f cvpoint2f;
				cvpoint2f.x = list[1].toFloat();
				cvpoint2f.y = list[2].toFloat();
				gVariable::GlobalVar.global_type = "cv::Point2f";
				gVariable::GlobalVar.global_cvpoint2f_value = cvpoint2f;
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "cv::Point3f")
		{
			if (strVar == key)
			{
				QStringList list = value.split(QRegExp("[(,,)]"));
				if (list.size() != 5 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true || list[4].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("cv::Point3f输入条件错误！");
					return "p_error";
				}
				cv::Point3f cvpoint3f;
				cvpoint3f.x = list[1].toFloat();
				cvpoint3f.y = list[2].toFloat();
				cvpoint3f.z = list[3].toFloat();
				gVariable::GlobalVar.global_type = "cv::Point3f";
				gVariable::GlobalVar.global_cvpoint3f_value = cvpoint3f;
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "cv::Point3d")
		{
			if (strVar == key)
			{
				QStringList list = value.split(QRegExp("[(,,)]"));
				if (list.size() != 5 || list[0].contains(QRegExp("[a-zA-Z]")) == true || list[1].contains(QRegExp("[a-zA-Z]")) == true || list[2].contains(QRegExp("[a-zA-Z]")) == true || list[3].contains(QRegExp("[a-zA-Z]")) == true || list[4].contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("cv::Point3d输入条件错误！");
					return "p_error";
				}
				cv::Point3d cvpoint3d;
				cvpoint3d.x = list[1].toDouble();
				cvpoint3d.y = list[2].toDouble();
				cvpoint3d.z = list[3].toDouble();
				gVariable::GlobalVar.global_type = "cv::Point3d";
				gVariable::GlobalVar.global_cvpoint3d_value = cvpoint3d;
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "Float[]")
		{
			if (strVar == key)
			{
				if (value.contains(QRegExp("[0-9{,}]+$")) == false || value.contains(QRegExp("[，a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Float[]类型只能输入数字！");
					return "p_error";
				}
				gVariable::GlobalVar.global_type = "Float[]";
				gVariable::GlobalVar.global_array_float_value.reserve(1000);
				gVariable::GlobalVar.global_array_float_value.clear();
				if (value.mid(0, 1) != "{" || value.mid(value.length() - 1, 1) != "}")
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Float[]类型未包含{}！");
					return "p_error";
				}
				QString s_float = value.mid(1, value.length() - 2);
				QStringList list_float = s_float.split(",", QString::SkipEmptyParts);
				for (int m = 0; m < list_float.count(); m++)
				{
					gVariable::GlobalVar.global_array_float_value.push_back(list_float[m].toFloat());
				}
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
		else if (gVariable::global_variable_link.value(key).global_type == "Double[]")
		{
			if (strVar == key)
			{
				if (value.contains(QRegExp("[0-9{,}]+$")) == false || value.contains(QRegExp("[a-zA-Z]")) == true)
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Double[]类型只能输入数字！");
					return "p_error";
				}
				gVariable::GlobalVar.global_type = "Double[]";
				gVariable::GlobalVar.global_array_double_value.reserve(1000);
				gVariable::GlobalVar.global_array_double_value.clear();
				if (value.mid(0, 1) != "{" || value.mid(value.length() - 1, 1) != "}")
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("Double[]类型未包含{}！");
					return "p_error";
				}
				QString s_double = value.mid(1, value.length() - 2);
				QStringList list_double = s_double.split(",", QString::SkipEmptyParts);
				for (int m = 0; m < list_double.count(); m++)
				{
					gVariable::GlobalVar.global_array_double_value.push_back(list_double[m].toDouble());
				}
				gVariable::global_variable_link.insert(key, gVariable::GlobalVar);
			}
		}
	}
	//更新全局变量
	QConfig::ToolBase[flowIndex]->RunAllToolLink();
	//更新列表
	int row_count = ui.tableWidget->rowCount();
	int intVarState = 0;
	for (int i = 0; i < row_count; i++)
	{
		if (ui.tableWidget->item(i, 1)->text() == strVar)
		{
			ui.tableWidget->item(i, 2)->setText(value);
			intVarState = 1;
		}
	}
	if (intVarState == 0)
	{
		return "p_error";
	}
	return QString();
}

void frmGlobalVariable::on_btnAdd_clicked()
{
	int count = ui.tableWidget->rowCount();
	ui.tableWidget->setRowCount(count + 1);  //设置行数
	QTableWidgetItem* item_type = new QTableWidgetItem(ui.comboType->currentText());
	item_type->setFlags(item_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
	ui.tableWidget->setItem(count, 0, item_type);
	QTableWidgetItem* item_name = new QTableWidgetItem("Var" + QString::number(count));
	ui.tableWidget->setItem(count, 1, item_name);
	QTableWidgetItem* item_value;
	if (ui.comboType->currentText() == "Int")
	{
		item_value = new QTableWidgetItem("0");
	}
	else if (ui.comboType->currentText() == "Double")
	{
		item_value = new QTableWidgetItem("0.0000");
	}
	else if (ui.comboType->currentText() == "QString")
	{
		item_value = new QTableWidgetItem(QString());
	}
	else if (ui.comboType->currentText() == "Bool")
	{
		item_value = new QTableWidgetItem("false");
		QTableWidgetItem* item_remark = new QTableWidgetItem("false为假，true为真");
		ui.tableWidget->setItem(count, 3, item_remark);
	}
	else if (ui.comboType->currentText() == "QPoint")
	{
		item_value = new QTableWidgetItem("(0,0)");
		QTableWidgetItem* item_remark = new QTableWidgetItem("必须包含( )");
		ui.tableWidget->setItem(count, 3, item_remark);
	}
	else if (ui.comboType->currentText() == "QPointF")
	{
		item_value = new QTableWidgetItem("(0.0000,0.0000)");
		QTableWidgetItem* item_remark = new QTableWidgetItem("必须包含( )");
		ui.tableWidget->setItem(count, 3, item_remark);
	}
	else if (ui.comboType->currentText() == "cv::Point")
	{
		item_value = new QTableWidgetItem("(0,0)");
		QTableWidgetItem* item_remark = new QTableWidgetItem("必须包含( )");
		ui.tableWidget->setItem(count, 3, item_remark);
	}
	else if (ui.comboType->currentText() == "cv::Point2f")
	{
		item_value = new QTableWidgetItem("(0.0000,0.0000)");
		QTableWidgetItem* item_remark = new QTableWidgetItem("必须包含( )");
		ui.tableWidget->setItem(count, 3, item_remark);
	}
	else if (ui.comboType->currentText() == "cv::Point3f")
	{
		item_value = new QTableWidgetItem("(0.0000,0.0000,0.0000)");
		QTableWidgetItem* item_remark = new QTableWidgetItem("必须包含( )");
		ui.tableWidget->setItem(count, 3, item_remark);
	}
	else if (ui.comboType->currentText() == "cv::Point3d")
	{
		item_value = new QTableWidgetItem("(0.0000,0.0000,0.0000)");
		QTableWidgetItem* item_remark = new QTableWidgetItem("必须包含( )");
		ui.tableWidget->setItem(count, 3, item_remark);
	}
	else if (ui.comboType->currentText() == "Float[]")
	{
		item_value = new QTableWidgetItem("{0.0000,0.0000}");
		QTableWidgetItem* item_remark = new QTableWidgetItem("必须包含{ }");
		ui.tableWidget->setItem(count, 3, item_remark);
	}
	else if (ui.comboType->currentText() == "Double[]")
	{
		item_value = new QTableWidgetItem("{0.0000,0.0000}");
		QTableWidgetItem* item_remark = new QTableWidgetItem("必须包含{ }");
		ui.tableWidget->setItem(count, 3, item_remark);
	}
	ui.tableWidget->setItem(count, 2, item_value);
}

void frmGlobalVariable::on_btnDelete_clicked()
{
	int rowIndex = ui.tableWidget->currentRow();
	if (rowIndex != -1)
	{
		ui.tableWidget->removeRow(rowIndex);
	}
}

void frmGlobalVariable::on_btnMoveUp_clicked()
{
	int nRow = ui.tableWidget->currentRow();
	moveRow(ui.tableWidget, nRow, nRow - 1);
}

void frmGlobalVariable::on_btnMoveDown_clicked()
{
	int nRow = ui.tableWidget->currentRow();
	moveRow(ui.tableWidget, nRow, nRow + 2);
}

void frmGlobalVariable::moveRow(QTableWidget* pTable, int nFrom, int nTo)
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
