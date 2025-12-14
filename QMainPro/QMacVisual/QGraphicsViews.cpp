#include "QGraphicsViews.h"
#include <QScrollBar>
#include <QMenu>
#include <QWheelEvent>
#include <QAction>
#include <QLabel>
#include <QHBoxLayout>
#include "qmutex.h"
#include <QApplication>
#include <QWidgetAction>
#include <QPushButton>
#include <QTimer>
#include "dockwidget.h"
#include "datavar.h"

QGraphicsViews::QGraphicsViews(QWidget* parent) : QGraphicsView(parent)
{
	this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate); //解决拖动是背景图片残影
	setDragMode(QGraphicsView::ScrollHandDrag);
	drawBg();
	//反锯齿
	setRenderHints(QPainter::Antialiasing);
	//隐藏水平/竖直滚动条
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setBackgroundBrush(Qt::gray);
	//以鼠标中心进行缩放
	setMouseTracking(true);
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	setResizeAnchor(QGraphicsView::AnchorUnderMouse);
	//设置场景范围
	setSceneRect(INT_MIN / 2, INT_MIN / 2, INT_MAX, INT_MAX);	
	scene = new QGraphicsScene(this);
	this->setScene(scene);			
}

void QGraphicsViews::DispImage(const QImage& Image)
{	
	image = QPixmap::fromImage(Image);	
	GetFit();	
}

void QGraphicsViews::SetToFit(qreal val)
{		
	ZoomFrame(val / ZoomValue);
	ZoomValue = val;
	QScrollBar* pHbar = this->horizontalScrollBar();
	pHbar->setSliderPosition(PixX);
	QScrollBar* pVbar = this->verticalScrollBar();
	pVbar->setSliderPosition(PixY);
}

void QGraphicsViews::ZoomFrame(double value)
{
	this->scale(value, value);
}

void QGraphicsViews::GetFit()
{
	if (this->width() < 1 || image.width() < 1)
	{
		return;
	}
	//图片自适应方法
	double winWidth = this->width();
	double winHeight = this->height();
	double ScaleWidth = (image.width() + 1) / winWidth;
	double ScaleHeight = (image.height() + 1) / winHeight;
	double row1, column1;
	double s = 0;
	if (ScaleWidth >= ScaleHeight)
	{
		row1 = -(1) * ((winHeight * ScaleWidth) - image.height()) / 2;
		column1 = 0;
		s = 1 / ScaleWidth;
	}
	else
	{
		row1 = 0;
		column1 = -(1.0) * ((winWidth * ScaleHeight) - image.width()) / 2;
		s = 1 / ScaleHeight;
	}
	if (ZoomFit != s || PixX != column1 * s || PixY != row1 * s)
	{
		ZoomFit = s;
		PixX = column1 * s;
		PixY = row1 * s;
		SetToFit(s);
	}	
}

void QGraphicsViews::drawBg()
{
	bgPix.fill(color1);
	QPainter painter(&bgPix);
	painter.fillRect(0, 0, 18, 18, color2);
	painter.fillRect(18, 18, 18, 18, color2);
	painter.end();
}

void QGraphicsViews::mousePressEvent(QMouseEvent* event)
{
	QGraphicsView::mousePressEvent(event);
}

void QGraphicsViews::resizeEvent(QResizeEvent* event)
{
	GetFit();
	QGraphicsView::resizeEvent(event);
}

void QGraphicsViews::mouseReleaseEvent(QMouseEvent* event)
{
	QGraphicsView::mouseReleaseEvent(event);
}

void QGraphicsViews::mouseDoubleClickEvent(QMouseEvent* event)
{	
	SetToFit(ZoomFit);
	QGraphicsView::mouseDoubleClickEvent(event);
}

void QGraphicsViews::mouseMoveEvent(QMouseEvent* event)
{	
	QGraphicsView::mouseMoveEvent(event);
}

void QGraphicsViews::wheelEvent(QWheelEvent* event)
{
	if ((event->delta() > 0) && (ZoomValue >= 50)) //最大放大到原始图像的50倍
	{
		return;
	}
	else if ((event->delta() < 0) && (ZoomValue <= 0.02))
	{
		return;
	}
	else
	{
		if (event->delta() > 0) //鼠标滚轮向前滚动
		{
			ZoomValue *= 1.1; //每次放大10%
			ZoomFrame(1.1);
		}
		else
		{
			ZoomFrame(0.9);
			ZoomValue *= 0.9; //每次缩小10%
		}
	}
}

void QGraphicsViews::drawBackground(QPainter* painter, const QRectF& rect)
{	
	Q_UNUSED(rect);	
	painter->drawPixmap(QPoint(), image);		
}

void QGraphicsViews::paintEvent(QPaintEvent* event)
{	
	QPainter paint(this->viewport());
	paint.drawTiledPixmap(QRect(QPoint(0, 0), QPoint(this->width(), this->height())), bgPix);  //绘制背景
	QGraphicsView::paintEvent(event);		
}

//右键菜单
void QGraphicsViews::contextMenuEvent(QContextMenuEvent* event)
{
	QPoint pos = event->pos();
	pos = this->mapToGlobal(pos);
	QMenu* menu = new QMenu(this);
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
		"}"
		"QPushButton::hover{"
		"background-color: rgba(176, 190, 225, 200);"
		"}"
		"QPushButton::selected{"
		"background-color: rgba(176, 190, 255, 255);"
		"}"
	);
	menu->setStyleSheet(menuStyle);	
	QPushButton* zoomInAction_buf = new QPushButton(menu);
	zoomInAction_buf->setStyleSheet(buttonStyle);
	zoomInAction_buf->setText("放大");
	zoomInAction_buf->setIconSize(QSize(23, 23));	
	zoomInAction_buf->setIcon(QIcon(":/res/ico/zoom.png"));
	QWidgetAction* zoomInAction = new QWidgetAction(this);
	zoomInAction->setDefaultWidget(zoomInAction_buf);	
	connect(zoomInAction_buf, &QPushButton::clicked, this, &QGraphicsViews::OnZoomInImage);
	connect(zoomInAction_buf, &QPushButton::clicked, menu, &QMenu::close);
	menu->addAction(zoomInAction);
	menu->addSeparator();	
	QPushButton* zoomOutAction_buf = new QPushButton(menu);
	zoomOutAction_buf->setStyleSheet(buttonStyle);
	zoomOutAction_buf->setText("缩小");
	zoomOutAction_buf->setIconSize(QSize(23, 23));
	zoomOutAction_buf->setIcon(QIcon(":/res/ico/zoom_out.png"));
	QWidgetAction* zoomOutAction = new QWidgetAction(this);
	zoomOutAction->setDefaultWidget(zoomOutAction_buf);
	connect(zoomOutAction_buf, &QPushButton::clicked, this, &QGraphicsViews::OnZoomOutImage);
	connect(zoomOutAction_buf, &QPushButton::clicked, menu, &QMenu::close);
	menu->addAction(zoomOutAction);
	menu->addSeparator();	
	QPushButton* presetAction_buf = new QPushButton(menu);
	presetAction_buf->setStyleSheet(buttonStyle);
	presetAction_buf->setText("自适应图像");
	presetAction_buf->setIconSize(QSize(22, 22));
	presetAction_buf->setIcon(QIcon(":/res/ico/fit.png"));
	QWidgetAction* presetAction = new QWidgetAction(this);
	presetAction->setDefaultWidget(presetAction_buf);
	connect(presetAction_buf, &QPushButton::clicked, this, &QGraphicsViews::OnFitImage);
	connect(presetAction_buf, &QPushButton::clicked, menu, &QMenu::close);
	menu->addAction(presetAction);	
	menu->exec(pos);
}

void QGraphicsViews::OnZoomInImage()
{
	double tmp_buf = ZoomValue;
	tmp_buf *= 1.1;
	double tmp = tmp_buf / ZoomValue;
	ZoomValue *= tmp;	
	this->scale(tmp, tmp);	
}

void QGraphicsViews::OnZoomOutImage()
{
	double tmp_buf = ZoomValue;
	tmp_buf *= 0.9;
	double tmp = tmp_buf / ZoomValue;
	ZoomValue *= tmp;	
	this->scale(tmp, tmp);
}

void QGraphicsViews::OnFitImage()
{
	SetToFit(ZoomFit);
}
