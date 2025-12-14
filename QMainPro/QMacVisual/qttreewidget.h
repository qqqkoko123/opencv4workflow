#pragma once
#pragma execution_character_set("utf-8")

#include <QTreeWidget>

class QtTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	explicit QtTreeWidget(QWidget* parent = 0);
	~QtTreeWidget();

private:
	QPixmap SetDragCurorPixmap(QPixmap pixmap, QString strText);

protected:
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	void startDrag(Qt::DropActions supportedActions) override;
};
