#pragma once

#include <QGraphicsScene>

class QGraphicsScenes : public QGraphicsScene
{
    Q_OBJECT

public:
    QGraphicsScenes(QObject *parent = nullptr);
    void startCreate();

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void updatePoint(QPointF p, QList<QPointF> list, bool isCenter);
    void createFinished();

protected:
    QList<QPointF> Plist;
    bool PolygonFlg;
};
