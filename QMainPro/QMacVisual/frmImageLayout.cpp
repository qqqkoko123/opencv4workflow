#include "frmImageLayout.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QDesktopWidget>
#include <QPainter>
#include "datavar.h"

frmImageLayout::frmImageLayout(QWidget* parent)
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
	this->setWindowIcon(QIcon(":/res/ico/osd.png"));
	//初始化标题栏
	initTitleBar();		
	//选项按钮
	btnGroupRadio = new QButtonGroup(this);
	btnGroupRadio->addButton(ui.radioImage1, 0);		
	connect(ui.radioImage1, SIGNAL(toggled(bool)), this, SLOT(slot_Image(bool)));
	btnGroupRadio->addButton(ui.radioImage2, 1);	
	connect(ui.radioImage2, SIGNAL(toggled(bool)), this, SLOT(slot_Image(bool)));
	btnGroupRadio->addButton(ui.radioImage3, 2);	
	connect(ui.radioImage3, SIGNAL(toggled(bool)), this, SLOT(slot_Image(bool)));
	btnGroupRadio->addButton(ui.radioImage4, 3);	
	connect(ui.radioImage4, SIGNAL(toggled(bool)), this, SLOT(slot_Image(bool)));
	btnGroupRadio->addButton(ui.radioImage6A, 4);	
	connect(ui.radioImage6A, SIGNAL(toggled(bool)), this, SLOT(slot_Image(bool)));
	btnGroupRadio->addButton(ui.radioImage6B, 5);	
	connect(ui.radioImage6B, SIGNAL(toggled(bool)), this, SLOT(slot_Image(bool)));
	btnGroupRadio->addButton(ui.radioImage9, 6);	
	connect(ui.radioImage9, SIGNAL(toggled(bool)), this, SLOT(slot_Image(bool)));
}

frmImageLayout::~frmImageLayout()
{
	this->deleteLater();
}

void frmImageLayout::initTitleBar()
{
	MyTitleBar* m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setBackgroundColor(3, 110, 95);
	m_titleBar->setStyleSheet("background-color: rgba(0, 0, 0,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/res/ico/osd.png");
	m_titleBar->setTitleContent("图像布局");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmImageLayout::paintEvent(QPaintEvent* event)
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

void frmImageLayout::onButtonCloseClicked()
{
	this->close();
}

void frmImageLayout::slot_Image(bool state)
{		
	switch (btnGroupRadio->checkedId())
	{
	case 0:		
		if (state == true)
		{
			dataVar::img_choose = 0;		
			emit sig_Image1();
		}		
		break;
	case 1:
		if (state == true)
		{
			dataVar::img_choose = 1;			
			emit sig_Image2();
		}		
		break;
	case 2:
		if (state == true)
		{
			dataVar::img_choose = 2;		
			emit sig_Image3();
		}	
		break;
	case 3:
		if (state == true)
		{
			dataVar::img_choose = 3;			
			emit sig_Image4();
		}	
		break;
	case 4:
		if (state == true)
		{
			dataVar::img_choose = 4;		
			emit sig_Image6A();
		}		
		break;
	case 5:
		if (state == true)
		{
			dataVar::img_choose = 5;			
			emit sig_Image6B();
		}		
		break;
	case 6:
		if (state == true)
		{
			dataVar::img_choose = 6;			
			emit sig_Image9();
		}		
		break;
	}
}
