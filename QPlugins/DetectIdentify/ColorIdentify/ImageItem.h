#pragma once

#include <QGraphicsPixmapItem>

//通过鼠标点选获取当前灰度值
class ImageItem :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    explicit ImageItem(QWidget *parent = nullptr);

protected:
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

public:
    int w;
    int h;

public slots:
    void slot_ScoreValue(QString InfoVal);

signals:
    void RGBValue(QString InfoVal);
    void ScoreValue(QString InfoVal);
};
