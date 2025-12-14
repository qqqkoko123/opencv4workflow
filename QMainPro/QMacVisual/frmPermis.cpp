#include "frmPermis.h"
#include <QMessageBox>
#include "datavar.h"
using namespace std;

frmPermis::frmPermis(QWidget*parent)
	: BaseWindow(parent)
{
	ui.setupUi(this);	
	this->setWindowIcon(QIcon(":/Bitmaps/permis.png"));		
	//初始化标题栏
	initTitleBar();	
	//设置Tab顺序
	ui.txtUserName->setFocus();
	setTabOrder(ui.txtUserName, ui.txtUserPW);
	setTabOrder(ui.txtUserPW, ui.btnAdd);
	setTabOrder(ui.btnAdd, ui.btnDelete);
	setTabOrder(ui.btnDelete, ui.btnQuery);	
}

frmPermis::~frmPermis()	
{
	this->deleteLater();
}

void frmPermis::initTitleBar()
{	
	m_titleBar->setBackgroundColor(3, 110, 95);
	m_titleBar->setStyleSheet("background-color: rgba(0, 0, 0,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/Bitmaps/permis.png");
	m_titleBar->setTitleContent("权限管理");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmPermis::paintEvent(QPaintEvent* event)
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

void frmPermis::on_btnAdd_clicked()
{	
	if (dataVar::login_state == 1)
	{		
		if (dataVar::bol_connect == true)
		{
			if (ui.txtUserName->text() == "" || ui.txtUserPW->text() == "")
			{
				emit dataVar::fProItemTab->sig_WarnClick();
				emit dataVar::fProItemTab->sig_Log("用户名或用户密码不能为空！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "用户名或用户密码不能为空！");
				msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
				msgBox.exec();				
			}
			else
			{
				//添加前先查询是否已存在该用户				
				QSqlQuery query;
				query.exec("SELECT * FROM LoginTable");
				while (query.next())
				{
					QString user_name = query.value(0).toString();	
					if (user_name == ui.txtUserName->text())
					{
						emit dataVar::fProItemTab->sig_WarnClick();
						emit dataVar::fProItemTab->sig_Log("已存在该用户无法添加！");
						QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "已存在该用户无法添加！");
						msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
						msgBox.exec();
						return;
					}					
				}
				bol_add = dataVar::sqlite.InsertData(dataVar::soft_key, "LoginTable", ui.txtUserName->text(), ui.txtUserPW->text());
				if (bol_add == true)
				{
					emit dataVar::fProItemTab->sig_InfoClick();
					emit dataVar::fProItemTab->sig_Log("用户名: " + ui.txtUserName->text() + "添加成功！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "用户名添加成功！");
					msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
					msgBox.exec();					
				}
				else
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("用户名: " + ui.txtUserName->text() + "添加失败！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "用户名添加失败！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();					
				}
			}
		}
		else
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("数据库连接失败！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "数据库连接失败！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();
		}
	}
	else
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("请登录后再添加！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "请登录后再添加！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();		
	}
}

void frmPermis::on_btnAdd_pressed()
{
	ui.btnAdd->setStyleSheet("QPushButton{background-color: rgb(146, 217, 108);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}

void frmPermis::on_btnAdd_released()
{
	ui.btnAdd->setStyleSheet("QPushButton{background-color: rgb(85, 170, 127);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}

void frmPermis::on_btnDelete_clicked()
{
	if (dataVar::login_state == 1)
	{		
		if (dataVar::bol_connect == true)
		{
			if (ui.txtUserName->text() == "" || ui.txtUserPW->text() == "")
			{
				emit dataVar::fProItemTab->sig_WarnClick();
				emit dataVar::fProItemTab->sig_Log("用户名或用户密码不能为空！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "用户名或用户密码不能为空！");
				msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
				msgBox.exec();				
			}
			else
			{
				QString password;
				bol_query = dataVar::sqlite.QueryData(dataVar::soft_key, ui.txtUserName->text(), password);
				if (bol_query == true && password == ui.txtUserPW->text() && password != "")
				{
					if (ui.txtUserName->text() == "fz_lcl")
					{
						emit dataVar::fProItemTab->sig_ErrorClick();
						emit dataVar::fProItemTab->sig_Log("无法删除该用户！");
						QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "无法删除该用户！");
						msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
						msgBox.exec();
					}
					else
					{
						bol_delete = dataVar::sqlite.DeleteData(dataVar::soft_key, ui.txtUserName->text());
						if (bol_delete == true)
						{
							emit dataVar::fProItemTab->sig_InfoClick();
							emit dataVar::fProItemTab->sig_Log("用户名: " + ui.txtUserName->text() + "删除成功！");
							QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "用户名删除成功！");
							msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
							msgBox.exec();							
						}
						else
						{
							emit dataVar::fProItemTab->sig_ErrorClick();
							emit dataVar::fProItemTab->sig_Log("用户名删除失败！");
							QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "用户名删除失败！");
							msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
							msgBox.exec();						
						}
					}					
				}
				else
				{
					emit dataVar::fProItemTab->sig_ErrorClick();
					emit dataVar::fProItemTab->sig_Log("用户名或用户密码错误！");
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "用户名或用户密码错误！");
					msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
					msgBox.exec();					
				}
			}
		}
		else
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("数据库连接失败！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "数据库连接失败！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();		
		}
	}
	else
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("请登录后再删除！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "请登录后再删除！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();		
	}
}

void frmPermis::on_btnDelete_pressed()
{
	ui.btnDelete->setStyleSheet("QPushButton{background-color: rgb(255, 85, 185);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}

void frmPermis::on_btnDelete_released()
{
	ui.btnDelete->setStyleSheet("QPushButton{background-color: rgb(255, 85, 127);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}

void frmPermis::on_btnQuery_clicked()
{
	if (dataVar::admin_login_state == 1)
	{		
		ui.txtQuery->clear();		
		if (dataVar::bol_connect == true)
		{
			QSqlQuery query;
			query.exec("SELECT * FROM LoginTable");
			while (query.next())
			{
				QString user_name = query.value(0).toString();
				QString password = query.value(1).toString();
				ui.txtQuery->append("user: " + user_name + ", " + "pw: " + password);
			}
		}
		else
		{
			emit dataVar::fProItemTab->sig_ErrorClick();
			emit dataVar::fProItemTab->sig_Log("数据库连接失败！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "数据库连接失败！");
			msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
			msgBox.exec();			
		}
	}
	else
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("超级管理员权限才能查询！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "超级管理员权限才能查询！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
	}	
}

void frmPermis::on_btnQuery_pressed()
{
	ui.btnQuery->setStyleSheet("QPushButton{background-color: rgb(146, 217, 108);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}

void frmPermis::on_btnQuery_released()
{
	ui.btnQuery->setStyleSheet("QPushButton{background-color: rgb(85, 170, 127);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}
