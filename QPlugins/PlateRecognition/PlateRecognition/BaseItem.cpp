#include "BaseItem.h"
#include <math.h>
#include <QtDebug>
#include <QThread>

#define M_PI 3.14159265358979323846
qreal BaseItem::ContrSize = 8;

void BaseItem::SetIndex(int num)
{
	if (ControlList.length() > 0)
	{
		ControlList[0]->index = num;
	}
}

void BaseItem::SetScale(double value)
{

}

BaseItem::BaseItem(QPointF center, ItemType type) :center(center), types(type)
{
	setHandlesChildEvents(false);//设置后才能将事件传递到子元素
	noSelected.setColor(QColor(0, 100, 200));
	noSelected.setWidth(LineWidth);
	isSelected.setColor(QColor(0, 180, 0));
	isSelected.setWidth(LineWidth);
	fillColor = QColor(0, 160, 230, 50); //填充颜色
	thisPen = noSelected;
	if (type != AutoItem)       //模式选择 自定义模式用于显示亚像素轮廓和Region  不设定任何属性
	{
		this->setFlags(QGraphicsItem::ItemIsSelectable |
			QGraphicsItem::ItemIsMovable |
			QGraphicsItem::ItemIsFocusable);
	}
}

void BaseItem::focusInEvent(QFocusEvent* event)
{
	Q_UNUSED(event);
	thisPen = isSelected;
	for (int i = 1; i < ControlList.length(); i++)
	{
		ControlList[i]->setVisible(true);
	}
}

void BaseItem::focusOutEvent(QFocusEvent* event)
{
	Q_UNUSED(event);
	thisPen = noSelected;
	for (int i = 1; i < ControlList.length(); i++)
	{
		ControlList[i]->setVisible(false);
	}
}

void BaseItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	//缩放控制点尺寸
	for (int i = 0; i < ControlList.size(); i++)
	{
		ControlList[i]->setScale(1 / (*scale));
	}	
	painter->save();
	painter->setBrush(Qt::NoBrush);
	QFont font;
	font.setPointSizeF(15 / (*scale)); //字体大小
	painter->setFont(font);
	painter->setPen(Qt::black);
	painter->drawText(ControlList[0]->GetPoint() + QPointF(-ContrSize / (*scale), -(ContrSize + 3) / (*scale)), ItemDiscrib);
	painter->restore();
	//子类绘制时状态
	LineWidth = 2 / (*scale);
	thisPen.setWidthF(LineWidth);
	painter->setPen(thisPen);
}

//******绘制结果数据******
DrawItem::DrawItem() :BaseItem(QPointF(0, 0), AutoItem)
{
	returnRec = QRectF(0, 0, 10000, 10000);
}

void DrawItem::Refresh()
{
	this->update();
}

QRectF DrawItem::boundingRect() const
{
	//当不设定Rect时超出区域会发生不显示的情况
	return returnRec;
}

void DrawItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	LineWidth = 2 / (*scale);
	DrawPen.setWidthF(LineWidth);
	DrawPen.setColor(QColor(255, 0, 0));
	painter->setPen(DrawPen);
	for (int i = 0; i < LineList.size(); i++)
	{
		if (LineList[i].size() <= 1)
		{
		}
		else
		{
			for (int j = 0; j < LineList[i].size() - 1; j++)
			{
				painter->drawLine(LineList[i][j], LineList[i][j - 1]);
			}
		}
	}
	for (auto item : ROIList)
	{
		for (auto p : item)
		{
			painter->drawPoint(p);
		}
	}
}

#pragma region 矩形
RectangleItem::RectangleItem(qreal x, qreal y, qreal width, qreal height) :BaseItem(QPointF(x, y), Rectangle)
{
	ControlList << new ControlItem(this, QPointF(x + width / 2, y + height / 2), 0);
	ControlList << new ControlItem(this, QPointF(x, y), 1);
	ControlList << new ControlItem(this, QPointF(x + width, y), 2);
	ControlList << new ControlItem(this, QPointF(x + width, y + height), 3);
	ControlList << new ControlItem(this, QPointF(x, y + height), 4);
}

QRectF RectangleItem::boundingRect() const
{
	return  QRectF(ControlList[1]->GetPoint(), ControlList[3]->GetPoint());
}

bool RectangleItem::UpDate(int index)
{
	QPointF Pf = ControlList[index]->GetPoint();
	//角点分情况
	switch (index)
	{
	case 1:
		ControlList[2]->SetPoint(QPointF(ControlList[2]->GetPoint().x(), Pf.y()));
		ControlList[4]->SetPoint(QPointF(Pf.x(), ControlList[4]->GetPoint().y()));
		break;
	case 2:
		ControlList[1]->SetPoint(QPointF(ControlList[1]->GetPoint().x(), Pf.y()));
		ControlList[3]->SetPoint(QPointF(Pf.x(), ControlList[3]->GetPoint().y()));
		break;
	case 3:
		ControlList[2]->SetPoint(QPointF(Pf.x(), ControlList[2]->GetPoint().y()));
		ControlList[4]->SetPoint(QPointF(ControlList[4]->GetPoint().x(), Pf.y()));
		break;
	case 4:
		ControlList[1]->SetPoint(QPointF(Pf.x(), ControlList[1]->GetPoint().y()));
		ControlList[3]->SetPoint(QPointF(ControlList[3]->GetPoint().x(), Pf.y()));
		break;
	default:
		break;
	}
	//中心点
	ControlList[0]->SetPoint(QPointF((ControlList[1]->GetPoint().x() + ControlList[2]->GetPoint().x()) / 2, (ControlList[2]->GetPoint().y() + ControlList[3]->GetPoint().y()) / 2));
	return true;
}

void RectangleItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QThread::msleep(10);
	Q_UNUSED(option);
	Q_UNUSED(widget);
	BaseItem::paint(painter, option, widget);
	QRectF ret(ControlList[1]->GetPoint(), ControlList[3]->GetPoint());
	painter->drawRect(ret);
}

void RectangleItem::SetRect(MRectangle MRect)
{
	QPointF set = this->mapFromScene(MRect.col, MRect.row);
	ControlList[0]->SetPoint(set + QPointF(MRect.width / 2, MRect.height / 2));
	ControlList[1]->SetPoint(set);
	ControlList[2]->SetPoint(set + QPointF(MRect.width, 0));
	ControlList[3]->SetPoint(set + QPointF(MRect.width, MRect.height));
	ControlList[4]->SetPoint(set + QPointF(0, MRect.height));
	this->setFocus();
}

void RectangleItem::GetRect(MRectangle& MRect)
{
	QPointF GetRec = this->mapToScene(ControlList[1]->x(), ControlList[1]->y());
	MRect.col = GetRec.x();
	MRect.row = GetRec.y();
	MRect.width = ControlList[2]->GetPoint().x() - ControlList[1]->GetPoint().x();
	MRect.height = ControlList[3]->GetPoint().y() - ControlList[1]->GetPoint().y();
}
#pragma endregion

#pragma region 旋转矩形
RectangleRItem::RectangleRItem(qreal x, qreal y, qreal Lenth1, qreal Lenth2, qreal Pi) :BaseItem(QPointF(x, y), RectangleR)
{
	angle = Pi;
	lenth1 = Lenth1 / 2;
	lenth2 = Lenth2 / 2;
	qreal s = sin(-angle);
	qreal c = cos(-angle);
	Pa1 = center + QPointF(0 * c - lenth2 * s, 0 * s + lenth2 * c);
	Pa2 = center + QPointF(lenth1 * c - 0 * s, lenth1 * s + 0 * c);
	Pa3 = center + QPointF(0 * c + lenth2 * s, 0 * s - lenth2 * c);
	Pa4 = center + QPointF(-lenth1 * c - 0 * s, -lenth1 * s + 0 * c);
	PArrow = center + QPointF((lenth1 + 20) * c - 0 * s, (lenth1 + 20) * s + 0 * c);
	//中心
	ControlList << new ControlItem(this, center, 0);
	//中心线控制点
	ControlList << new ControlItem(this, Pa1, 1);
	ControlList << new ControlItem(this, Pa2, 2);
	ControlList << new ControlItem(this, Pa3, 3);
	ControlList << new ControlItem(this, Pa4, 4);
}

QRectF RectangleRItem::boundingRect() const
{
	qreal tmp = (lenth1 > lenth2 ? lenth2 : lenth1);
	return QRectF(center.x() - tmp, center.y() - tmp, tmp * 2, tmp * 2);
}

bool RectangleRItem::UpDate(int index)
{
	QPointF Pf = ControlList[index]->GetPoint();
	qreal dx = Pf.x() - center.x();
	qreal dy = Pf.y() - center.y();
	if (dx >= 0 && dy < 0)
	{
		angle = atan2((-1) * (dy), dx);
	}
	else if (dx < 0 && dy < 0)
	{
		angle = atan2((-1) * dy, dx);
	}
	else if (dx < 0 && dy >= 0)
	{
		angle = M_PI * 2 + atan2((-1) * dy, dx);
	}
	else if (dx >= 0 && dy >= 0)
	{
		angle = M_PI * 2 - atan2(dy, dx);
	}
	//角度补偿 角度方向逆时针 控制点排列方向 顺时针
	switch (index)
	{
	case 1:
		angle += M_PI / 2;
		break;
	case 3:
		angle += M_PI * 3 / 2;
		break;
	case 4:
		angle += M_PI;
		break;
	}
	qreal s = sin(-angle);
	qreal c = cos(-angle);
	if (index == 2 || index == 4)
	{
		lenth1 = sqrt(dx * dx + dy * dy);
	}
	else if (index == 1 || index == 3)
	{
		lenth2 = sqrt(dx * dx + dy * dy);
	}
	Pa1 = center + QPointF(0 * c - lenth2 * s, 0 * s + lenth2 * c);
	Pa2 = center + QPointF(lenth1 * c - 0 * s, lenth1 * s + 0 * c);
	Pa3 = center + QPointF(0 * c + lenth2 * s, 0 * s - lenth2 * c);
	Pa4 = center + QPointF(-lenth1 * c - 0 * s, -lenth1 * s + 0 * c);
	PArrow = center + QPointF((lenth1 + 20) * c - 0 * s, (lenth1 + 20) * s + 0 * c);
	ControlList[1]->SetPoint(Pa1);
	ControlList[2]->SetPoint(Pa2);
	ControlList[3]->SetPoint(Pa3);
	ControlList[4]->SetPoint(Pa4);
	return true;
}

void RectangleRItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QThread::msleep(10);
	Q_UNUSED(option);
	Q_UNUSED(widget);
	BaseItem::paint(painter, option, widget);
	//画角度方向线
	painter->drawLine(PArrow, Pa2);
	//绘制方向箭头
	float l = 15.0;//箭头长度
	double atn1 = atan2((PArrow.y() - Pa2.y()), (PArrow.x() - Pa2.x()));
	double atn2 = atan2((PArrow.x() - Pa2.x()), (PArrow.y() - Pa2.y()));
	QPointF Arrow1(PArrow.x() - l * cos(atn1 - 0.5), PArrow.y() - l * sin(atn1 - 0.5));
	QPointF Arrow2(PArrow.x() - l * sin(atn2 - 0.5), PArrow.y() - l * cos(atn2 - 0.5));
	painter->drawLine(PArrow, Arrow1);
	painter->drawLine(PArrow, Arrow2);
	//绘制旋转矩形
	painter->save();
	painter->translate(center);
	painter->rotate(-angle * 180 / M_PI);
	painter->drawRect(QRectF(-lenth1, -lenth2, lenth1 * 2, lenth2 * 2));
	painter->restore();
}

void RectangleRItem::GetRotatedRect(MRotatedRect& MRRect)
{
	QPointF GetRRect = this->mapToScene(ControlList[0]->x(), ControlList[0]->y());
	MRRect.col = GetRRect.x();
	MRRect.row = GetRRect.y();
	MRRect.phi = angle;
	MRRect.lenth1 = lenth1;
	MRRect.lenth2 = lenth2;
}
#pragma endregion

#pragma region 多边形
PolygonItem::PolygonItem() :BaseItem(QPointF(0, 0), Polygon)
{
	init_points.clear();
	list_ps.clear();
	ControlList << new ControlItem(this, center, 0);
	ControlList[0]->setVisible(false);
	Finished = false;
}

QPointF PolygonItem::getCentroid(QList<QPointF> list)
{
	qreal x = 0;
	qreal y = 0;
	for (auto& temp : list)
	{
		x += temp.x();
		y += temp.y();
	}
	x = x / list.size();
	y = y / list.size();
	return QPointF(x, y);
}

void PolygonItem::getMaxLength()
{
	QVector<qreal> vec;
	vec.reserve(200);
	vec.clear();
	for (int i = 1; i < ControlList.length(); i++)
	{
		qreal dis = sqrt(pow(center.x() - ControlList[i]->x(), 2) + pow(center.y() - ControlList[i]->y(), 2));
		vec.append(dis);
	}
	qreal ret = 0;
	for (auto& temp : vec)
	{
		if (temp > ret) {
			ret = temp;
		}
	}
	Radius = ret;
}

void PolygonItem::pushPoint(QPointF p, QList<QPointF> list, bool isCenter)
{
	if (!Finished)
	{
		center = getCentroid(list);
		getMaxLength();
		if (isCenter)
		{
			ControlList[0]->SetPoint(center);
			ControlList[0]->setVisible(true);
			Finished = true;
		}
		else
		{
			auto tmp = new ControlItem(this, p, ControlList.length());
			tmp->setVisible(true);
			ControlList << tmp;
			init_points.append(p);
			list_ps.append(list);
		}		
		this->update();
	}
}

QRectF PolygonItem::boundingRect() const
{
	return QRectF(center.x() - Radius, center.y() - Radius, Radius * 2, Radius * 2);
}

bool PolygonItem::UpDate(int index)
{
	Q_UNUSED(index);
	QList<QPointF> list;
	list.reserve(200);
	list.clear();
	for (int i = 1; i < ControlList.length(); i++)
	{
		list << ControlList[i]->GetPoint();
	}
	center = getCentroid(list);
	ControlList[0]->SetPoint(center);
	return true;
}

void PolygonItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QThread::msleep(10);
	Q_UNUSED(option);
	Q_UNUSED(widget);
	thisPen.setWidthF(LineWidth);
	painter->setPen(thisPen);
	if (Finished)
	{
		for (int i = 1; i < ControlList.length() - 1; i++)
		{
			painter->drawLine(ControlList[i]->GetPoint(), ControlList[i + 1]->GetPoint());
		}
		painter->drawLine(ControlList[ControlList.length() - 1]->GetPoint(), ControlList[1]->GetPoint());
	}
	else
	{
		for (int i = 1; i < ControlList.length() - 1; i++)
		{
			painter->drawLine(ControlList[i]->GetPoint(), ControlList[i + 1]->GetPoint());
		}
	}
}

void PolygonItem::GetPolygon(MPolygon& mpolygon)
{
	QList<QPointF> list_p;
	list_p.reserve(200);
	list_p.clear();
	for (int i = 1; i < ControlList.length(); i++)
	{
		list_p.append(mapToScene(ControlList[i]->GetPoint()));
	}
	mpolygon.list_p = list_p;
	mpolygon.points = init_points;
	mpolygon.list_ps = list_ps;
}
#pragma endregion

#pragma region 椭圆
EllipseItem::EllipseItem(qreal x, qreal y, qreal Lenth1, qreal Lenth2, qreal Pi) :RectangleRItem(x, y, Lenth1, Lenth2, Pi)
{
}

void EllipseItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QThread::msleep(10);
	Q_UNUSED(option);
	Q_UNUSED(widget);
	BaseItem::paint(painter, option, widget);
	painter->drawLine(center, Pa2);
	painter->save();
	painter->translate(center);
	painter->rotate(-angle * 180 / M_PI);
	painter->drawEllipse(QRectF(-lenth1, -lenth2, lenth1 * 2, lenth2 * 2));
	painter->restore();
}
#pragma endregion

#pragma region 圆
CircleItem::CircleItem(qreal x, qreal y, qreal R) :BaseItem(QPointF(x, y), Circle)
{
	Radius = R;
	ControlList << new ControlItem(this, center, 0);
	ControlList << new ControlItem(this, center + QPointF(R, 0), 1);
}

QRectF CircleItem::boundingRect() const
{
	return QRectF(center.x() - Radius, center.y() - Radius, Radius * 2, Radius * 2);
}

bool CircleItem::UpDate(int index)
{
	QPointF Pf = ControlList[index]->GetPoint();
	QPointF tmp = Pf - center;
	Radius = sqrt(tmp.x() * tmp.x() + tmp.y() * tmp.y());
	return true;
}

void CircleItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QThread::msleep(10);
	Q_UNUSED(option);
	Q_UNUSED(widget);
	BaseItem::paint(painter, option, widget);
	painter->drawEllipse(QRectF(center.x() - Radius, center.y() - Radius, Radius * 2, Radius * 2));
}

void CircleItem::GetCircle(MCircle& Cir)
{
	QPointF GetRec = this->mapToScene(ControlList[0]->x(), ControlList[0]->y());
	Cir.col = GetRec.x();
	Cir.row = GetRec.y();
	Cir.radius = Radius;
}
#pragma endregion

#pragma region 同心圆
ConcentricCircleItem::ConcentricCircleItem(qreal x, qreal y, qreal radiusMin, qreal radiusMax) :BaseItem(QPointF(x, y), Concentric_Circle)
{
	RadiusMax = radiusMax;
	RadiusMin = radiusMin > radiusMax ? radiusMax : radiusMin;
	ControlList << new ControlItem(this, center, 0);
	ControlList << new ControlItem(this, center + QPointF(RadiusMin, 0), 1);
	ControlList << new ControlItem(this, center + QPointF(RadiusMax, 0), 2);
}

QRectF ConcentricCircleItem::boundingRect() const
{
	return QRectF(center.x() - RadiusMax, center.y() - RadiusMax, RadiusMax * 2, RadiusMax * 2);
}

bool ConcentricCircleItem::UpDate(int index)
{
	QPointF Pf = ControlList[index]->GetPoint();
	QPointF tmp = Pf - center;
	qreal R = sqrt(tmp.x() * tmp.x() + tmp.y() * tmp.y());
	if (index == 1)
	{
		if (R > RadiusMax)
			return false;
		RadiusMin = R;
	}
	else if (index == 2)
	{
		if (R < RadiusMin)
			return false;
		RadiusMax = R;
	}
	return true;
}

void ConcentricCircleItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QThread::msleep(10);
	Q_UNUSED(option);
	Q_UNUSED(widget);
	BaseItem::paint(painter, option, widget);
	QPainterPath pth;
	pth.addEllipse(QRectF(center.x() - RadiusMin, center.y() - RadiusMin, RadiusMin * 2, RadiusMin * 2));
	pth.addEllipse(QRectF(center.x() - RadiusMax, center.y() - RadiusMax, RadiusMax * 2, RadiusMax * 2));
	painter->setBrush(QBrush(fillColor));
	painter->drawPath(pth);
	//绘制分割线	
	painter->setPen(QPen(QColor(10, 255, 255, 255), 1));
	QLine line;
	double angle = 0;
	ring_small_points.clear();
	ring_big_points.clear();
	for (int i = 0; i <= segment_line_num; i++)
	{
		QPointF pf_min, pf_max;
		if (0 <= angle && angle < 90)
		{
			line = QLine(QPoint(center.x() + cos(angle * M_PI / 180) * RadiusMin, center.y() - sin(angle * M_PI / 180) * RadiusMin), QPoint(center.x() + cos(angle * M_PI / 180) * RadiusMax, center.y() - sin(angle * M_PI / 180) * RadiusMax));
			pf_min = this->mapToScene(QPointF(center.x() + cos(angle * M_PI / 180) * RadiusMin, center.y() - sin(angle * M_PI / 180) * RadiusMin));
			ring_small_points.push_back(pf_min);
			pf_max = this->mapToScene(QPointF(center.x() + cos(angle * M_PI / 180) * RadiusMax, center.y() - sin(angle * M_PI / 180) * RadiusMax));
			ring_big_points.push_back(pf_max);
		}
		else if (90 <= angle && angle < 180)
		{
			line = QLine(QPoint(center.x() - sin((angle - 90) * M_PI / 180) * RadiusMin, center.y() - cos((angle - 90) * M_PI / 180) * RadiusMin), QPoint(center.x() - sin((angle - 90) * M_PI / 180) * RadiusMax, center.y() - cos((angle - 90) * M_PI / 180) * RadiusMax));
			pf_min = this->mapToScene(QPointF(center.x() - sin((angle - 90) * M_PI / 180) * RadiusMin, center.y() - cos((angle - 90) * M_PI / 180) * RadiusMin));
			ring_small_points.push_back(pf_min);
			pf_max = this->mapToScene(QPointF(center.x() - sin((angle - 90) * M_PI / 180) * RadiusMax, center.y() - cos((angle - 90) * M_PI / 180) * RadiusMax));
			ring_big_points.push_back(pf_max);
		}
		else if (180 <= angle && angle < 270)
		{
			line = QLine(QPoint(center.x() - cos((angle - 180) * M_PI / 180) * RadiusMin, center.y() + sin((angle - 180) * M_PI / 180) * RadiusMin), QPoint(center.x() - cos((angle - 180) * M_PI / 180) * RadiusMax, center.y() + sin((angle - 180) * M_PI / 180) * RadiusMax));
			pf_min = this->mapToScene(QPointF(center.x() - cos((angle - 180) * M_PI / 180) * RadiusMin, center.y() + sin((angle - 180) * M_PI / 180) * RadiusMin));
			ring_small_points.push_back(pf_min);
			pf_max = this->mapToScene(QPointF(center.x() - cos((angle - 180) * M_PI / 180) * RadiusMax, center.y() + sin((angle - 180) * M_PI / 180) * RadiusMax));
			ring_big_points.push_back(pf_max);
		}
		else if (270 <= angle && angle < 360)
		{
			line = QLine(QPoint(center.x() + sin((angle - 270) * M_PI / 180) * RadiusMin, center.y() + cos((angle - 270) * M_PI / 180) * RadiusMin), QPoint(center.x() + sin((angle - 270) * M_PI / 180) * RadiusMax, center.y() + cos((angle - 270) * M_PI / 180) * RadiusMax));
			pf_min = this->mapToScene(QPointF(center.x() + sin((angle - 270) * M_PI / 180) * RadiusMin, center.y() + cos((angle - 270) * M_PI / 180) * RadiusMin));
			ring_small_points.push_back(pf_min);
			pf_max = this->mapToScene(QPointF(center.x() + sin((angle - 270) * M_PI / 180) * RadiusMax, center.y() + cos((angle - 270) * M_PI / 180) * RadiusMax));
			ring_big_points.push_back(pf_max);
		}
		painter->drawLine(line);
		angle = angle + (360.0 / (double)segment_line_num);
	}
}

void ConcentricCircleItem::GetConcentricCircle(CCircle& CCir)
{
	QPointF GetCCircle = this->mapToScene(ControlList[0]->x(), ControlList[0]->y());
	CCir.col = GetCCircle.x();
	CCir.row = GetCCircle.y();
	CCir.small_radius = RadiusMin;
	CCir.big_radius = RadiusMax;
}
#pragma endregion

#pragma region 直线
LineItem::LineItem(qreal x1, qreal y1, qreal x2, qreal y2) :BaseItem(QPointF((x1 + x2) / 2, (y1 + y2) / 2), LineObj)
{
	ControlList << new ControlItem(this, center, 0);
	ControlList << new ControlItem(this, QPointF(x1, y1), 1);
	ControlList << new ControlItem(this, QPointF(x2, y2), 2);
	P1 = QPointF(x1, y1);
	P2 = QPointF(x2, y2);
}

bool LineItem::UpDate(int index)
{
	if (index == 1)
	{
		P1 = ControlList[1]->GetPoint();
	}
	else if (index == 2)
	{
		P2 = ControlList[2]->GetPoint();
	}
	ControlList[0]->SetPoint(QPointF((P1.x() + P2.x()) / 2, (P1.y() + P2.y()) / 2));
	return true;
}

void LineItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QThread::msleep(10);
	Q_UNUSED(option);
	Q_UNUSED(widget);
	BaseItem::paint(painter, option, widget);
	painter->drawLine(P1, P2);
}
#pragma endregion

#pragma region 卡尺
Caliper::Caliper(qreal x1, qreal y1, qreal x2, qreal y2, qreal height) :BaseItem(QPointF((x1 + x2) / 2, (y1 + y2) / 2), LineObj)
{	
	P1 = QPointF(x1, y1);
	P2 = QPointF(x2, y2);
	Height = height;
	ControlList << new ControlItem(this, center, 0);
	ControlList << new ControlItem(this, QPointF(x1, y1), 1);
	ControlList << new ControlItem(this, QPointF(x2, y2), 2);
	qreal dx = P1.x() - P2.x();
	qreal dy = P1.y() - P2.y();
	if (dx >= 0 && dy < 0)
	{
		angle = atan2((-1) * (dy), dx);
	}
	else if (dx < 0 && dy < 0)
	{
		angle = atan2((-1) * dy, dx);
	}
	else if (dx < 0 && dy >= 0)
	{
		angle = M_PI * 2 + atan2((-1) * dy, dx);
	}
	else if (dx >= 0 && dy >= 0)
	{
		angle = M_PI * 2 - atan2(dy, dx);
	}
	Lenth = sqrt(dx * dx + dy * dy);
	qreal s = sin(angle);
	qreal c = cos(angle);
	ControlList << new ControlItem(this, center + QPointF(s * Height / 2, c * Height / 2), 3);			
}

QRectF Caliper::boundingRect() const
{
	int min = Lenth < Height ? Lenth : Height;
	int size = min < 5 ? 5 : min;
	QPointF c = (P1 + P2) / 2;
	return QRectF(c.x() - size, c.y() - size, size, size);
}

bool Caliper::UpDate(int index)
{
	if (index == 1)
	{
		P1 = ControlList[1]->GetPoint();
	}
	else if (index == 2)
	{
		P2 = ControlList[2]->GetPoint();
	}
	else if (index == 3)
	{
		QPointF Pf = ControlList[3]->GetPoint();
		qreal dx = Pf.x() - center.x();
		qreal dy = Pf.y() - center.y();
		Height = sqrt(dx * dx + dy * dy) * 2;
	}
	center = QPointF((P1.x() + P2.x()) / 2, (P1.y() + P2.y()) / 2);
	ControlList[0]->SetPoint(center);
	qreal dx = P1.x() - P2.x();
	qreal dy = P1.y() - P2.y();
	if (dx >= 0 && dy < 0)
	{
		angle = atan2((-1) * (dy), dx);
	}
	else if (dx < 0 && dy < 0)
	{
		angle = atan2((-1) * dy, dx);
	}
	else if (dx < 0 && dy >= 0)
	{
		angle = M_PI * 2 + atan2((-1) * dy, dx);
	}
	else if (dx >= 0 && dy >= 0)
	{
		angle = M_PI * 2 - atan2(dy, dx);
	}
	qreal s = sin(angle);
	qreal c = cos(angle);
	ControlList[3]->SetPoint(center + QPointF(s * Height / 2, c * Height / 2));
	Lenth = sqrt(dx * dx + dy * dy);
	return true;
}

void Caliper::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	QThread::msleep(10);
	Q_UNUSED(option);
	Q_UNUSED(widget);
	BaseItem::paint(painter, option, widget);	
	//绘制分割线	
	QLine line;
	painter->setPen(QPen(QColor(10, 255, 255, 255), 1));
	double angle_buf = 180 * angle / M_PI;
	line_small_points.clear();
	line_big_points.clear();
	for (int i = 0; i <= segment_line_num; i++)
	{
		QPointF pf_min, pf_max;
		if (0 <= angle_buf && angle_buf < 90)
		{
			QPoint RecPS, RecPE, Ps, Pe;
			RecPS = QPoint(P1.x() - 0.5 * (double)Height * sin(angle), P1.y() - 0.5 * (double)Height * cos(angle));
			RecPE = QPoint(P2.x() - 0.5 * (double)Height * sin(angle), P2.y() - 0.5 * (double)Height * cos(angle));
			Ps = QPoint(RecPS.x() + ((double)Height / (double)segment_line_num) * i * sin(angle), RecPS.y() + ((double)Height / (double)segment_line_num) * i * cos(angle));
			Pe = QPoint(RecPE.x() + ((double)Height / (double)segment_line_num) * i * sin(angle), RecPE.y() + ((double)Height / (double)segment_line_num) * i * cos(angle));
			line = QLine(Ps, Pe);
			pf_min = this->mapToScene(QPointF(Ps.x(), Ps.y()));
			line_small_points.push_back(pf_min);
			pf_max = this->mapToScene(QPointF(Pe.x(), Pe.y()));
			line_big_points.push_back(pf_max);
		}
		else if (90 <= angle_buf && angle_buf < 180)
		{
			QPoint RecPS, RecPE, Ps, Pe;
			RecPS = QPoint(P1.x() + 0.5 * (double)Height * cos((angle_buf - 90) * M_PI / 180), P1.y() - 0.5 * (double)Height * sin((angle_buf - 90) * M_PI / 180));
			RecPE = QPoint(P2.x() + 0.5 * (double)Height * cos((angle_buf - 90) * M_PI / 180), P2.y() - 0.5 * (double)Height * sin((angle_buf - 90) * M_PI / 180));
			Ps = QPoint(RecPS.x() - ((double)Height / (double)segment_line_num) * i * cos((angle_buf - 90) * M_PI / 180), RecPS.y() + ((double)Height / (double)segment_line_num) * i * sin((angle_buf - 90) * M_PI / 180));
			Pe = QPoint(RecPE.x() - ((double)Height / (double)segment_line_num) * i * cos((angle_buf - 90) * M_PI / 180), RecPE.y() + ((double)Height / (double)segment_line_num) * i * sin((angle_buf - 90) * M_PI / 180));
			line = QLine(Ps, Pe);
			pf_min = this->mapToScene(QPointF(Ps.x(), Ps.y()));
			line_small_points.push_back(pf_min);
			pf_max = this->mapToScene(QPointF(Pe.x(), Pe.y()));
			line_big_points.push_back(pf_max);
		}
		else if (180 <= angle_buf && angle_buf < 270)
		{
			QPoint RecPS, RecPE, Ps, Pe;
			RecPS = QPoint(P1.x() - 0.5 * (double)Height * sin((angle_buf - 180) * M_PI / 180), P1.y() - 0.5 * (double)Height * cos((angle_buf - 180) * M_PI / 180));
			RecPE = QPoint(P2.x() - 0.5 * (double)Height * sin((angle_buf - 180) * M_PI / 180), P2.y() - 0.5 * (double)Height * cos((angle_buf - 180) * M_PI / 180));
			Ps = QPoint(RecPS.x() + ((double)Height / (double)segment_line_num) * i * sin((angle_buf - 180) * M_PI / 180), RecPS.y() + ((double)Height / (double)segment_line_num) * i * cos((angle_buf - 180) * M_PI / 180));
			Pe = QPoint(RecPE.x() + ((double)Height / (double)segment_line_num) * i * sin((angle_buf - 180) * M_PI / 180), RecPE.y() + ((double)Height / (double)segment_line_num) * i * cos((angle_buf - 180) * M_PI / 180));
			line = QLine(Ps, Pe);
			pf_min = this->mapToScene(QPointF(Ps.x(), Ps.y()));
			line_small_points.push_back(pf_min);
			pf_max = this->mapToScene(QPointF(Pe.x(), Pe.y()));
			line_big_points.push_back(pf_max);
		}
		else if (270 <= angle_buf && angle_buf < 360)
		{
			QPoint RecPS, RecPE, Ps, Pe;
			RecPS = QPoint(P1.x() - 0.5 * (double)Height * cos((angle_buf - 270) * M_PI / 180), P1.y() + 0.5 * (double)Height * sin((angle_buf - 270) * M_PI / 180));
			RecPE = QPoint(P2.x() - 0.5 * (double)Height * cos((angle_buf - 270) * M_PI / 180), P2.y() + 0.5 * (double)Height * sin((angle_buf - 270) * M_PI / 180));
			Ps = QPoint(RecPS.x() + ((double)Height / (double)segment_line_num) * i * cos((angle_buf - 270) * M_PI / 180), RecPS.y() - ((double)Height / (double)segment_line_num) * i * sin((angle_buf - 270) * M_PI / 180));
			Pe = QPoint(RecPE.x() + ((double)Height / (double)segment_line_num) * i * cos((angle_buf - 270) * M_PI / 180), RecPE.y() - ((double)Height / (double)segment_line_num) * i * sin((angle_buf - 270) * M_PI / 180));
			line = QLine(Ps, Pe);
			pf_min = this->mapToScene(QPointF(Ps.x(), Ps.y()));
			line_small_points.push_back(pf_min);
			pf_max = this->mapToScene(QPointF(Pe.x(), Pe.y()));
			line_big_points.push_back(pf_max);
		}
		painter->drawLine(line);
	}
	painter->setPen(QPen(QColor(0, 0, 255, 255), 3));
	painter->drawLine(P1, P2);	
	//绘制方向箭头
	float l = 22.0;//箭头长度
	double atn1 = atan2((P2.y() - P1.y()), (P2.x() - P1.x()));
	double atn2 = atan2((P2.x() - P1.x()), (P2.y() - P1.y()));
	QPointF Arrow1(P2.x() - l * cos(atn1 - 0.5), P2.y() - l * sin(atn1 - 0.5));
	QPointF Arrow2(P2.x() - l * sin(atn2 - 0.5), P2.y() - l * cos(atn2 - 0.5));
	painter->drawLine(P2, Arrow1);
	painter->drawLine(P2, Arrow2);
	painter->save();
	painter->translate(center);
	painter->setBrush(QBrush(fillColor));
	painter->rotate(-angle * 180 / M_PI);
	QPen tp = painter->pen();
	tp.setWidthF(0);
	tp.setColor(fillColor);
	painter->setPen(tp);
	thisPen.setWidthF(0);
	painter->drawRect(-Lenth / 2, -abs(Height / 2), Lenth, abs(Height));
	painter->restore();
}

void Caliper::GetCaliper(CaliperP& CP)
{			
	QPointF GetCenter = this->mapToScene(center.x(), center.y());
	CP.col = GetCenter.x();
	CP.row = GetCenter.y();
	CP.len1 = Lenth;
	CP.len2 = Height;
	CP.angle = angle;
	CP.x1 = P1.x();
	CP.y1 = P1.y();
	CP.x2 = P2.x();
	CP.y2 = P2.y();
	CP.height = Height;
	CP.pp1 = this->mapToScene(P1.x(), P1.y());
	CP.pp2 = this->mapToScene(P2.x(), P2.y());
}

void Caliper::SetCaliper(QPointF p1, QPointF p2)
{	
	P1 = p1;
	P2 = p2;
	ControlList[1] = new ControlItem(this, P1, 1);
	ControlList[2] = new ControlItem(this, P2, 2);
	UpDate(0);
	UpDate(1);
	UpDate(2);
	UpDate(3);	
}
#pragma endregion
