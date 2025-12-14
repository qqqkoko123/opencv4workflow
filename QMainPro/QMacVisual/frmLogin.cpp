#include "frmLogin.h"
#include <QMessageBox>
#include <QTime>
#include "datavar.h"
using namespace std;

frmLogin::frmLogin(QWidget*parent)
	: BaseWindow(parent)
{
	ui.setupUi(this);	
	this->setWindowIcon(QIcon(":/res/ico/user.png"));	
	connect(this, &frmLogin::sendInStateSignal, dataVar::m_pWindow, &MainWindow::slot_LoginBtnState);
	connect(this, &frmLogin::sendOutStateSignal, dataVar::m_pWindow, &MainWindow::slot_LogoutBtnState);
	//初始化标题栏
	initTitleBar();	
	//设置Tab顺序
	ui.txtUserName->setFocus();
	setTabOrder(ui.txtUserName, ui.txtUserPW);
	setTabOrder(ui.txtUserPW, ui.btnLogout);
	setTabOrder(ui.btnLogout, ui.btnLogin);	
	form_load();		
	ui.txtUserPW->setEchoMode(QLineEdit::Password);
}

frmLogin::~frmLogin()	
{
	this->deleteLater();
}

void frmLogin::initTitleBar()
{			
	m_titleBar->setBackgroundColor(3, 110, 95);
	m_titleBar->setStyleSheet("background-color: rgba(0, 0, 0,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/res/ico/user.png");
	m_titleBar->setTitleContent("用户登录");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmLogin::paintEvent(QPaintEvent* event)
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

void frmLogin::form_load()
{	
	//SQLite数据库操作	
	QFileInfo file(dataVar::path_DB + "MyDataBase.db");
	if (!file.exists())
	{		
		dataVar::bol_connect = dataVar::sqlite.CreateConnectDB(dataVar::soft_key, dataVar::path_DB + "MyDataBase.db", dataVar::database);
		if (dataVar::bol_connect == true)
		{			
			dataVar::sqlite.CreateTable(dataVar::soft_key, "LoginTable");
			dataVar::sqlite.InsertData(dataVar::soft_key, "LoginTable", "fz_lcl", "666666");
		}		
	}
	if (dataVar::login_state == 1)
	{
		ui.txtUserName->setText(dataVar::user_name);
	}	
}

void frmLogin::on_btnLogout_clicked()
{
	if (dataVar::login_state == 1)
	{			
		dataVar::startTime = QDateTime();
		emit sendOutStateSignal();
		dataVar::login_state = 0;		
		dataVar::admin_login_state = 0;
		emit dataVar::fProItemTab->sig_InfoClick();
		emit dataVar::fProItemTab->sig_Log("用户名: " + dataVar::user_name + "已注销！");
		dataVar::user_name = QString();
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "已注销！");
		msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
		msgBox.exec();				
	}
	else
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("请登录后再注销！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "请登录后再注销！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));		
		msgBox.exec();		
	}
}

void frmLogin::on_btnLogout_pressed()
{
	ui.btnLogout->setStyleSheet("QPushButton{background-color: rgb(255, 207, 130);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}

void frmLogin::on_btnLogout_released()
{
	ui.btnLogout->setStyleSheet("QPushButton{background-color: rgb(255, 163, 97);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}

void frmLogin::on_btnLogin_clicked()
{
	if (dataVar::login_state == 1)
	{
		emit dataVar::fProItemTab->sig_WarnClick();
		emit dataVar::fProItemTab->sig_Log("用户名: " + dataVar::user_name + "已登录！");
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "用户名: " + dataVar::user_name + "已登录！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
		return;
	}
	if (dataVar::bol_connect == false)
	{
		dataVar::bol_connect = dataVar::sqlite.CreateConnectDB(dataVar::soft_key, dataVar::path_DB + "/MyDataBase.db", dataVar::database);
	}	
	if (dataVar::bol_connect == true)
	{
		if (ui.txtUserName->text() == "" || ui.txtUserPW->text() == "")
		{
			emit dataVar::fProItemTab->sig_WarnClick();
			emit dataVar::fProItemTab->sig_Log("用户名或用户密码不能为空！");
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "用户名或用户密码不能为空！");
			msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));			
			msgBox.exec();		
			return;
		}
		else
		{
			QString password;
			bol_query = dataVar::sqlite.QueryData(dataVar::soft_key, ui.txtUserName->text(), password);
			if (bol_query == true && password == ui.txtUserPW->text() && password != "")
			{					
				emit sendInStateSignal();
				dataVar::login_state = 1;
				if (ui.txtUserName->text() == "fz_lcl")
				{
					dataVar::admin_login_state = 1;
				}
				ui.txtUserPW->setText("");
				dataVar::user_name = ui.txtUserName->text();	
				dataVar::startTime = QDateTime::currentDateTime();
				emit dataVar::fProItemTab->sig_InfoClick();
				emit dataVar::fProItemTab->sig_Log("用户名: " + dataVar::user_name + "登录成功！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "登录成功！");
				msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));				
				msgBox.exec();			
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

void frmLogin::on_btnLogin_pressed()
{
	ui.btnLogin->setStyleSheet("QPushButton{background-color: rgb(146, 217, 108);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}

void frmLogin::on_btnLogin_released()
{
	ui.btnLogin->setStyleSheet("QPushButton{background-color: rgb(85, 170, 127);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}
