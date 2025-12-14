#include "ImageItem.h"
#include <QGraphicsSceneHoverEvent>

ImageItem::ImageItem(QWidget* parent) : QGraphicsPixmapItem(nullptr)
{
}

void ImageItem::hoverMoveEvent(QGraphicsSceneHoverEvent* event)
{
	QPointF mousePosition = event->pos();
	int R, G, B;
	int x, y;
	x = mousePosition.x();
	y = mousePosition.y();
	if (mousePosition.x() < 0)
	{
		x = 0;
	}
	if (mousePosition.y() < 0)
	{
		y = 0;
	}
	pixmap().toImage().pixelColor(x, y).getRgb(&R, &G, &B);	
	QString InfoVal = QString("W:%1,H:%2 | X:%3,Y:%4 | R:%5,G:%6,B:%7").arg(QString::number(w)).arg(QString::number(h))
		.arg(QString::number(x))
		.arg(QString::number(y))
		.arg(QString::number(R))
		.arg(QString::number(G))
		.arg(QString::number(B));
	emit RGBValue(InfoVal);
}

void ImageItem::slot_ClassifierValue(QString InfoVal)
{
	emit ClassifierValue(InfoVal);
}
