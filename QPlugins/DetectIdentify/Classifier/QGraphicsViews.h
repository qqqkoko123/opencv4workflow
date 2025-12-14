#pragma once
#pragma execution_character_set("utf-8")

#include <QGraphicsView>
#include <QScrollBar>
#include "BaseItem.h"

class QLabel;
class QMouseEvent;
class QGraphicsScenes;
class ImageItem;

class QGraphicsViews : public QGraphicsView
{
	Q_OBJECT

public:
	QGraphicsViews(QWidget* parent = nullptr);
	void SetToFit(qreal val);
	void ClearObj();
	QGraphicsScenes* scene;
	DrawItem* drawItem;	
	ImageItem* item;

public slots:
	void DispImage(QImage& Image); //显示图片
	void DispPoint(QVector<QPointF>& list, QColor color = QColor(0, 255, 0));//显示点集合
	void AddItems(BaseItem* item); //添加ROI	
	void SetType(bool InfoFlg, bool GrayValueFlg);//设定显示信息

protected:
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
	virtual void mouseDoubleClickEvent(QMouseEvent* event) override;
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	virtual void wheelEvent(QWheelEvent* event) override;
	virtual void resizeEvent(QResizeEvent* event) override;
	virtual void drawBackground(QPainter* painter, const QRectF& rect) override;
	virtual void paintEvent(QPaintEvent* event) override;
	virtual void contextMenuEvent(QContextMenuEvent* event) override;   //右键菜单

private:
	void OnZoomInImage();
	void OnZoomOutImage();
	void OnFitImage();
	void ZoomFrame(double value);
	void GetFit();
	QScrollBar* pHbar;
	QScrollBar* pVbar;
	double ZoomValue = 1;
	double ZoomFit = 1;
	double PixX = 0;
	double PixY = 0;
	QPixmap image;
	QWidget* fWidget;	
	QLabel* GrayValue; //显示灰度值
	QWidget* fClassifierWidget;
	QLabel* qClassifierValue; //显示类别

private:
	int MRSize = 8; //拖拽区域大小
	QColor color1 = QColor(30, 30, 30);           //颜色1
	QColor color2 = QColor(50, 50, 50, 255);      //颜色2
	QPixmap bgPix = QPixmap(36, 36);              //背景图片
	void drawBg();
};
