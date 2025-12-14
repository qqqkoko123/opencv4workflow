#include "frmExtensionLibrary.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPainter>
#include <QLibrary>
#include <QGraphicsOpacityEffect>

frmExtensionLibrary::frmExtensionLibrary(QString toolName, QToolBase* toolBase, QWidget* parent)
	: Toolnterface(toolName, toolBase, parent)
{
	ui.setupUi(this);
	toolTitleName = toolName;
	sToolBase = toolBase;
	sToolName = toolName;
	//FramelessWindowHint属性设置窗口去除边框
	//WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	//设置窗体在屏幕中间位置
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	//设置窗口背景透明
	setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/resource/extension_library.png"));
	//初始化标题栏
	initTitleBar();
	//连接信号与槽
	connect(this, SIGNAL(sig_Message()), this, SLOT(slot_Message()));
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtPath->setGraphicsEffect(e);
}

frmExtensionLibrary::~frmExtensionLibrary()
{
	this->deleteLater();
}

void frmExtensionLibrary::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/extension_library.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmExtensionLibrary::paintEvent(QPaintEvent* event)
{
	//设置背景色
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(160, 160, 160)));
	return QWidget::paintEvent(event);
}

void frmExtensionLibrary::onButtonCloseClicked()
{
	this->close();
}

int frmExtensionLibrary::Execute(const QString toolname)
{	
	if (frmPage == nullptr)
	{
		//子线程中操作GUI要用信号与槽
		emit sig_Message();
		return -2;
	}
	frmPage->Execute(toolname);
	return 0;
}

int frmExtensionLibrary::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		if (int_link == 1)
		{
			if (frmPage == nullptr)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未加载扩展库！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			frmPage->ExecuteLink(int_link, str_link, variable_link);
			strs.reserve(100);
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 1 || strs[1] != "图像")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			ui.txtLinkImage->setText(str_link);			
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmExtensionLibrary::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
{
	try
	{
		gvariable.global_variable_link = g_variable_link;
		if (frmPage != nullptr)
		{
			frmPage->ExecuteAllLink(g_variable_link);
		}		
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

typedef Toolnterface* (*Funs)(QString sToolName, QToolBase* toolBase);
int frmExtensionLibrary::InitSetToolData(const QVariant data)
{
	try
	{
		InitExtensionLibraryData init_data;
		init_data = data.value<InitExtensionLibraryData>();		
		str_img_link = init_data.image_link;
		dirPath = init_data.dirPath;
		//加载插件
		QLibrary mylib(dirPath);   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				frmPage = open(sToolName, sToolBase);	
				frmPage->ExecuteLink(0, str_img_link, gvariable.global_variable_link);
			}			
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmExtensionLibrary::InitGetToolData()
{
	InitExtensionLibraryData init_data;	
	init_data.image_link = ui.txtLinkImage->text();
	init_data.dirPath = dirPath;
	return QVariant::fromValue(init_data);
}

void frmExtensionLibrary::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmExtensionLibrary::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmExtensionLibrary::slot_Message()
{
	QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "未加载扩展库！");
	msgBox.setWindowIcon(QIcon(":/resource/error.png"));
	msgBox.exec();
	return;
}

void frmExtensionLibrary::on_btnPath_clicked()
{
	QString path_E = QDir::currentPath() + "/ExtLibrary/";
	QString file_name = QFileDialog::getOpenFileName(this,
		tr("打开扩展库"), path_E, "*.dll");
	if (!file_name.isNull())
	{				
		//加载插件
		QLibrary mylib(file_name);   //声明所用到的dll文件
		if (mylib.load())    //判断是否正确加载
		{			
			Funs open = (Funs)mylib.resolve("showDialog");
			if (open)
			{
				frmPage = open(sToolName, sToolBase);
				ui.txtLinkImage->clear();
				ui.txtPath->setText(file_name);
				dirPath = file_name;
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "打开扩展库完成！");
				msgBox.setWindowIcon(QIcon(":/resource/info.png"));
				msgBox.exec();
			}
			else
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "打开扩展库失败！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
			}
		}
		else
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "打开扩展库失败！");
			msgBox.setWindowIcon(QIcon(":/resource/error.png"));
			msgBox.exec();
		}
	}
}

void frmExtensionLibrary::on_btnSet_clicked()
{
	Execute(GetToolName());
	if (frmPage != nullptr)
	{
		frmPage->exec();
	}	
}

//全局变量控制
int QConfig::nFormState = 0;
