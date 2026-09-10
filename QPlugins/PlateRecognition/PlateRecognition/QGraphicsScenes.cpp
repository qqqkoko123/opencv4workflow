#include "QGraphicsScenes.h"
#include <QGraphicsSceneMouseEvent>

QGraphicsScenes::QGraphicsScenes(QObject* parent) : QGraphicsScene(parent)
{
	PolygonFlg = false;
}

void QGraphicsScenes::startCreate()
{
	PolygonFlg = true;
	Plist.clear();
}

void QGraphicsScenes::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	if (PolygonFlg)
	{
		QPointF p(event->scenePos().x(), event->scenePos().y());
		switch (event->buttons())
		{
		case Qt::LeftButton: {
			Plist.push_back(p);
			emit updatePoint(p, Plist, false);
		} break;
		case Qt::RightButton: {
			if (Plist.size() >= 3) {
				emit updatePoint(p, Plist, true);
				emit createFinished();
				PolygonFlg = false;
				Plist.clear();
			}
		} break;
		default: break;
		}
	}
	else {
		QGraphicsScene::mousePressEvent(event);
	}
}
