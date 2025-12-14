#include "frmProcessSetUp.h"
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QComboBox>
#include <QDesktopWidget>
#include "datavar.h"
using namespace std;

frmProcessSetUp::frmProcessSetUp(QWidget*parent)
	: QDialog(parent)
{
	ui.setupUi(this);	
	this->setWindowIcon(QIcon(":/res/ico/process.png"));	
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
}

frmProcessSetUp::~frmProcessSetUp()	
{
	this->deleteLater();
}

void frmProcessSetUp::initTitleBar()
{	
	MyTitleBar* m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setBackgroundColor(3, 110, 95);
	m_titleBar->setStyleSheet("background-color: rgba(0, 0, 0,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/res/ico/process.png");
	m_titleBar->setTitleContent("流程设置");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmProcessSetUp::paintEvent(QPaintEvent* event)
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

void frmProcessSetUp::form_load()
{	
	ui.txtProject->setFocus();	
	//添加List	 	
	ItemModel = new QStandardItemModel(this);
	ui.listProcess->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
}

void frmProcessSetUp::onButtonCloseClicked()
{
	//信号与槽解除连接
	disconnect(ui.listProcess, SIGNAL(clicked(QModelIndex)), this, SLOT(slot_ListClick(QModelIndex)));	
	this->close();
}

void frmProcessSetUp::slot_CreateList()
{
	//获取子控件
	objTabName = dataVar::fProItemTab->findChild<QTabWidget*>("ProItemTabWidget");
	int count = objTabName->count();
	//添加List	 		
	ItemModel->removeRows(0, ItemModel->rowCount());
	for (int i = 0; i < count; i++)
	{
		QStandardItem* item = new QStandardItem(objTabName->tabText(i));
		ItemModel->appendRow(item);			
	}
	ui.listProcess->setModel(ItemModel);
	connect(ui.listProcess, SIGNAL(clicked(QModelIndex)), this, SLOT(slot_ListClick(QModelIndex)));	
}

void frmProcessSetUp::slot_ListClick(QModelIndex index)
{
	index_process_modify = index.row();
	ui.txtProcess->setText(index.data().toString());	
	str_name = index.data().toString();
}

void frmProcessSetUp::slot_SetProject(QString str_name)
{
	ui.txtProject->setText(str_name);
}

void frmProcessSetUp::on_btnProjectModify_clicked()
{	
	if (ui.txtProject->text() == QString())
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("项目名称不能为空！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "项目名称不能为空！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
		return;
	}
	else
	{
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log("项目名称修改完成！");
		dataVar::projectName = ui.txtProject->text();
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "项目名称修改完成！");
		msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
		msgBox.exec();
	}	
}

void frmProcessSetUp::on_btnProcessModify_clicked()
{
	//获取子控件
	objTabName = dataVar::fProItemTab->findChild<QTabWidget*>("ProItemTabWidget");
	int count = objTabName->count();
	for (int i = 0; i < count; i++)
	{		
		if (ui.txtProcess->text() == objTabName->tabText(i))
		{
			emit dataVar::fProItemTab->sig_WarnClick();
			emit dataVar::fProItemTab->sig_Log("已有相同流程名称！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "已有相同流程名称！");
			msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
			msgBox.exec();
			return;
		}
	}
	if (ui.txtProcess->text() == QString() || ui.txtProcess->text() == str_name)
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("未选择流程或流程未更改名称！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "未选择流程或流程未更改名称！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
		return;
	}
	else
	{
		QString str_modify = ui.txtProcess->text();
		//修改QListView内容	
		ItemModel->setItem(index_process_modify, new QStandardItem(str_modify));		
		//修改QTabWidget内容	
		objTabName = dataVar::fProItemTab->findChild<QTabWidget*>("ProItemTabWidget");  //获取子控件
		objTabName->setTabText(index_process_modify, str_modify);
		//修改QTreeWidget内容
		objTreeName = dataVar::fProItemTab->findChild<QTreeWidget*>("ProItemTreeWidget");  //获取子控件		
	    //遍历treeWidget
		QTreeWidgetItemIterator it(objTreeName);
		QString key_old_name;
		while (*it) 
		{
			if ((*it)->child(index_process_modify))
			{
				key_old_name = (*it)->child(index_process_modify)->text(0);
				(*it)->child(index_process_modify)->setText(0, str_modify);
				connect(this, &frmProcessSetUp::sig_UpdateQTreeWidget, dataVar::fProItemTab, &frmProItemTab::slot_UpdateQTreeWidget);
				emit sig_UpdateQTreeWidget(key_old_name, str_modify);
			}			
			++it;
		}		
		disconnect(this, &frmProcessSetUp::sig_UpdateQTreeWidget, dataVar::fProItemTab, &frmProItemTab::slot_UpdateQTreeWidget);
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log(key_old_name + " 修改名称为：" + str_modify);
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "流程名称修改完成！");
		msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
		msgBox.exec();
	}	
}
