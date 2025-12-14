#include "QGraphicsViews.h"
#include <QScrollBar>
#include <QMenu>
#include "ControlItem.h"
#include "BaseItem.h"
#include <QFileDialog>
#include <QAction>
#include <QLabel>
#include "QGraphicsScenes.h"
#include <QHBoxLayout>
#include <QThread>
#include <QPushButton>
#include <QWidgetAction>
#include "ImageItem.h"
#include "qmutex.h"

QGraphicsViews::QGraphicsViews(QWidget* parent) : QGraphicsView(parent)
{
	this->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);//解决拖动是背景图片残影
	setDragMode(QGraphicsView::ScrollHandDrag);
	drawBg();
	// 隐藏水平/竖直滚动条
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setBackgroundBrush(Qt::gray);
	// 设置场景范围
	setSceneRect(INT_MIN / 2, INT_MIN / 2, INT_MAX, INT_MAX);
	// 反锯齿
	setRenderHints(QPainter::Antialiasing);
	item = new ImageItem;
	scene = new QGraphicsScenes;
	scene->addItem(item);
	this->setScene(scene);
	drawItem = new DrawItem;
	AddItems(drawItem);
	//显示灰度值
	GrayValue = new QLabel(this); 
	GrayValue->setObjectName("GrayValue_X");
	GrayValue->setStyleSheet("color:rgb(200,255,200); background-color:rgba(50,50,50,160); font: Microsoft YaHei;font-size: 15px;");
	GrayValue->setVisible(false);
	GrayValue->setFixedWidth(702);	
	//显示区域
	fWidget = new QWidget(this);	
	fWidget->setFixedHeight(25);	
	fWidget->setGeometry(2, 538, 702, 25);
	fWidget->setStyleSheet("background-color:rgba(0,0,0,0);");
	auto fLayout = new QHBoxLayout(fWidget);
	fLayout->setSpacing(0);
	fLayout->setMargin(0);	
	fLayout->addWidget(GrayValue);
	fLayout->addStretch();	
	connect(item, &ImageItem::RGBValue, this, [&](QString InfoVal) {
		GrayValue->setText(InfoVal);
		});
	//显示类别
	qClassifierValue = new QLabel(this);
	qClassifierValue->setObjectName("ClassifierValue");
	qClassifierValue->setStyleSheet("color:rgb(200,255,200); background-color:rgba(50,50,50,160); font: Microsoft YaHei;font-size: 15px;font-weight: bold;");
	qClassifierValue->setVisible(false);
	qClassifierValue->setFixedWidth(300);
	//显示区域
	fClassifierWidget = new QWidget(this);
	fClassifierWidget->setFixedHeight(25);
	fClassifierWidget->setGeometry(2, 2, 300, 25);
	fClassifierWidget->setStyleSheet("background-color:rgba(0,0,0,0);");
	auto fClarityLayout = new QHBoxLayout(fClassifierWidget);
	fClarityLayout->setSpacing(0);
	fClarityLayout->setMargin(0);
	fClarityLayout->addWidget(qClassifierValue);
	fClarityLayout->addStretch();
	connect(item, &ImageItem::ClassifierValue, this, [&](QString InfoVal) {
		qClassifierValue->setText(InfoVal);
		});
	SetType(false, false);
}

void QGraphicsViews::DispImage(QImage& Image)
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);	
	image = QPixmap::fromImage(Image);
	item->w = image.width();
	item->h = image.height();
	item->setPixmap(image);
	GetFit();
}

void QGraphicsViews::DispPoint(QVector<QPointF>& list, QColor color)
{
	drawItem->ClearAll();
	drawItem->AddRegion(list);
}

void QGraphicsViews::AddItems(BaseItem* item)
{
	item->scale = &ZoomValue;
	this->scene->addItem(item);
}

//设定信息模块是否显示
void QGraphicsViews::SetType(bool InfoFlg, bool GrayValueFlg)
{
	item->setAcceptHoverEvents(!InfoFlg);
	GrayValue->setVisible(!InfoFlg);
	qClassifierValue->setVisible(!InfoFlg);
}

void QGraphicsViews::ClearObj()
{
	foreach(auto item, scene->items())
	{
		if (item->type() == 10)
		{
			scene->removeItem(item);
		}
	}
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
	if (ZoomFit != s || PixX != column1 * s)
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
