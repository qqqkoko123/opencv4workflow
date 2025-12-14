#include "FlowListWidget.h"
#include <QApplication>
#include <QTimer>
#include "GlobalVariable.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDrag>
#include <QMessageBox>
#include <QScrollArea>
#include <QScrollBar>
#include <QHBoxLayout>
#include <QDebug>
#include <QWidgetAction>
#include "datavar.h"
#include "qmutex.h"

#define ITEM_V_SPACE 2
#define MARGIN_LEFT  2
#define DRAG_DATA QStringLiteral("drag/treeitem")

DragListWidgetPrivate::DragListWidgetPrivate(QWidget* parent) : QWidget(parent)
{
	m_nIndex = -1;
	m_nHoverItem = -1;
	m_nExchangeEndId = -1;
	m_nExchangeStartId = -1;
	m_bDragPress = false;
	m_bInsertUpOrDown = false;
	m_nMarginSize = 12;
	m_itemSize = 46;
	this->setAcceptDrops(true);
	this->setMouseTracking(true);
	icon_timer = new QTimer(this);
	connect(icon_timer, SIGNAL(timeout()), this, SLOT(slot_IconCheck()));
	m_timer = new QTimer(this);
	m_timer->setInterval(750);
	m_timer->setSingleShot(true);
	connect(m_timer, SIGNAL(timeout()), this, SLOT(SltDragPressCheck()));
	//添加右键菜单
	AddRightButtonMenu();
}

DragListWidgetPrivate::~DragListWidgetPrivate()
{
	ItemContent.clear();
}

void DragListWidgetPrivate::AddItem(int id, DragListItem item)
{
	m_items.insert(id, item);
	CalcWidgetHeight();
	this->update();
}

void DragListWidgetPrivate::AddItems(QMap<int, DragListItem> items)
{
	m_items = items;
	CalcWidgetHeight();
	this->update();
}

QString DragListWidgetPrivate::GetCurrentItemText()
{
	if (-1 != m_nIndex)
	{
		return m_items.value(m_nIndex).m_strTitle;
	}
	return QString();
}

void DragListWidgetPrivate::AddRightButtonMenu()
{
	m_menu = new QMenu(this);
	//菜单样式
	QString menuStyle(
		"QMenu::item{"
		"color: rgb(0, 0, 0);"
		"padding-up: 2px;"
		"padding-down: 2px;"
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
		"min-height: 26px;"
		"}"
		"QPushButton::hover{"
		"background-color: rgba(176, 190, 225, 200);"
		"}"
		"QPushButton::selected{"
		"background-color: rgba(176, 190, 255, 255);"
		"}"
	);
	m_menu->setStyleSheet(menuStyle);
	QPushButton* currentAction_buf = new QPushButton(m_menu);
	currentAction_buf->setStyleSheet(buttonStyle);
	currentAction_buf->setText("运行当前工具");
	currentAction_buf->setIconSize(QSize(20, 22));
	currentAction_buf->setIcon(QIcon(":/res/ico/current.png"));
	QWidgetAction* currentAction = new QWidgetAction(this);
	currentAction->setDefaultWidget(currentAction_buf);
	connect(currentAction_buf, &QPushButton::clicked, this, &DragListWidgetPrivate::slot_Current);
	connect(currentAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(currentAction);
	QPushButton* previousAction_buf = new QPushButton(m_menu);
	previousAction_buf->setStyleSheet(buttonStyle);
	previousAction_buf->setText("上移");
	previousAction_buf->setIconSize(QSize(20, 20));
	previousAction_buf->setIcon(QIcon(":/res/ico/previous.png"));
	QWidgetAction* previousAction = new QWidgetAction(this);
	previousAction->setDefaultWidget(previousAction_buf);
	connect(previousAction_buf, &QPushButton::clicked, this, &DragListWidgetPrivate::slot_Previous);
	connect(previousAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(previousAction);
	QPushButton* nextAction_buf = new QPushButton(m_menu);
	nextAction_buf->setStyleSheet(buttonStyle);
	nextAction_buf->setText("下移");
	nextAction_buf->setIconSize(QSize(20, 20));
	nextAction_buf->setIcon(QIcon(":/res/ico/next.png"));
	QWidgetAction* nextAction = new QWidgetAction(this);
	nextAction->setDefaultWidget(nextAction_buf);
	connect(nextAction_buf, &QPushButton::clicked, this, &DragListWidgetPrivate::slot_Next);
	connect(nextAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(nextAction);
	stateAction_buf = new QPushButton(m_menu);
	stateAction_buf->setStyleSheet(buttonStyle);
	stateAction_buf->setText("禁用");
	stateAction_buf->setIconSize(QSize(21, 21));
	stateAction_buf->setIcon(QIcon(":/res/ico/disable.png"));
	QWidgetAction* stateAction = new QWidgetAction(this);
	stateAction->setDefaultWidget(stateAction_buf);
	connect(stateAction_buf, &QPushButton::clicked, this, &DragListWidgetPrivate::slot_DActivation);
	connect(this, SIGNAL(sig_DActivation(QString)), this, SLOT(slot_DisabledActivation(QString)));
	connect(stateAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(stateAction);
	QPushButton* deleteAction_buf = new QPushButton(m_menu);
	deleteAction_buf->setStyleSheet(buttonStyle);
	deleteAction_buf->setText("删除");
	deleteAction_buf->setIconSize(QSize(22, 22));
	deleteAction_buf->setIcon(QIcon(":/res/ico/del.png"));
	QWidgetAction* deleteAction = new QWidgetAction(this);
	deleteAction->setDefaultWidget(deleteAction_buf);
	connect(deleteAction_buf, &QPushButton::clicked, this, &DragListWidgetPrivate::slot_Delete);
	connect(deleteAction_buf, &QPushButton::clicked, m_menu, &QMenu::close);
	m_menu->addAction(deleteAction);
}

void DragListWidgetPrivate::slot_Current()
{
	icon_timer->stop();
	DragListItem itemState = m_items.value(m_nExchangeStartId);
	emit sig_ActionProItem(2, GetCurrentItemText(), false);
	m_nExchangeStartId = -1;
}

void DragListWidgetPrivate::slot_Previous()
{
	icon_timer->stop();
	DragListItem itemState = m_items.value(m_nExchangeStartId);
	//先判断当前是否是第一行
	if (m_nExchangeStartId <= 1)
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "已经是第一行了！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
		return;
	}
	DragListItem item = m_items.value(m_nExchangeStartId);
	m_items.remove(m_nExchangeStartId);
	ExchangeItem(m_nExchangeStartId - 1, item);
	m_nExchangeStartId = -1;
}

void DragListWidgetPrivate::slot_Next()
{
	icon_timer->stop();
	DragListItem itemState = m_items.value(m_nExchangeStartId);
	//先判断当前是否是最后一项
	if (m_nExchangeStartId >= m_items.size())
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "已经是最后一行了！");
		msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
		msgBox.exec();
		return;
	}
	DragListItem item = m_items.value(m_nExchangeStartId);
	m_items.remove(m_nExchangeStartId);
	ExchangeItem(m_nExchangeStartId + 1, item, false);
	m_nExchangeStartId = -1;
}

void DragListWidgetPrivate::slot_DActivation()
{
	emit sig_DActivation(stateAction_buf->text());
}

void DragListWidgetPrivate::slot_DisabledActivation(QString text_name)
{
	icon_timer->stop();
	DragListItem itemState = m_items.value(m_nExchangeStartId);
	if (text_name == "禁用")
	{
		objTabName = dataVar::fProItemTab->findChild<QTabWidget*>("ProItemTabWidget");
		QString flowPageName = objTabName->tabText(objTabName->currentIndex());
		QMap<QString, QtDragListWidget*>::iterator iter = dataVar::FlowProMap.begin();
		while (iter != dataVar::FlowProMap.end())
		{
			if (iter.key() == flowPageName)
			{
				qDragListWidget = iter.value();
				break;
			}
			iter++;
		}
		m_states.insert(itemState.m_strTitle, qDragListWidget);
		QPixmap pim = QPixmap(":/res/ico/disable_2.png");
		qDragListWidget->SetItemSubIcon(itemState.m_strTitle, pim);
		qDragListWidget->SetItemSubStateText(itemState.m_strTitle, "禁用");
	}
	else if (text_name == "激活")
	{
		objTabName = dataVar::fProItemTab->findChild<QTabWidget*>("ProItemTabWidget");
		QString flowPageName = objTabName->tabText(objTabName->currentIndex());
		QMap<QString, QtDragListWidget*>::iterator iter = dataVar::FlowProMap.begin();
		while (iter != dataVar::FlowProMap.end())
		{
			if (iter.key() == flowPageName)
			{
				qDragListWidget = iter.value();
				break;
			}
			iter++;
		}
		m_states.remove(itemState.m_strTitle);
		qDragListWidget->SetItemSubIcon(itemState.m_strTitle, QPixmap());
		qDragListWidget->SetItemSubStateText(itemState.m_strTitle, "激活");
	}
	m_nExchangeStartId = -1;
}

void DragListWidgetPrivate::slot_Delete()
{
	icon_timer->stop();
	DragListItem itemState = m_items.value(m_nExchangeStartId);
	DeleteItem(m_nExchangeStartId);
	m_nExchangeStartId = -1;
}

void DragListWidgetPrivate::CalcWidgetHeight()
{
	int nHeight = 10;
	nHeight = nHeight + (m_items.size() + 1) * m_itemSize;
	this->setMinimumHeight(nHeight);
}

void DragListWidgetPrivate::InsertItem(QPoint pos, DragListItem newItem)
{
	int index = -1;
	foreach(DragListItem item, m_items)
	{
		if (item.m_rectItem.contains(pos))
		{
			index = m_bInsertUpOrDown ? item.m_nId : (item.m_nId + 1);
			break;
		}
	}
	if (-1 == index)
	{
		newItem.m_nId = m_items.size() + 1;
		m_nIndex = newItem.m_nId;
		this->AddItem(m_nIndex, newItem);
	}
	//重新排序
	else
	{
		QList<DragListItem> items = m_items.values();
		m_items.clear();
		foreach(DragListItem item, items)
		{
			if (item.m_nId >= index)
			{
				item.m_nId = item.m_nId + 1;
			}
			m_items.insert(item.m_nId, item);
		}
		newItem.m_nId = index;
		m_nIndex = newItem.m_nId;
		m_items.insert(index, newItem);
		//插入时处理激活/禁用图标
		for (int m = 1; m <= m_items.size(); m++)
		{
			if (m_items.value(m).m_strStateTitle == "禁用")
			{
				QPixmap pim = QPixmap(":/res/ico/disable_2.png");
				qDragListWidget->SetItemSubIcon(m_items.value(m).m_strTitle, pim);
			}
		}
		CalcWidgetHeight();
		this->update();
		if_judge_index = 0;
	}
}

void DragListWidgetPrivate::DeleteItem(int index)
{
	if (!m_items.contains(index))
		return;
	DragListItem itemDel = m_items.value(index);
	if (QMessageBox::Yes == QMessageBox::question(this,
		"提示",
		QString("是否确认删除[%1. %2]？").
		arg(itemDel.m_nId).arg(itemDel.m_strTitle),
		QMessageBox::Yes | QMessageBox::No))
	{
		ItemContent.remove(itemDel.m_strTitle);
		m_items.remove(index);
		emit sig_ActionProItem(1, itemDel.m_strTitle, false);
	}
	else
	{
		return;
	}
	QList<DragListItem> items = m_items.values();
	if (items.count() == 0)
	{
		ItemContent.clear();
	}
	if_judge_index = 0;
	m_items.clear();
	foreach(DragListItem item, items)
	{
		if (item.m_nId > index)
		{
			item.m_nId = item.m_nId - 1;
		}
		m_items.insert(item.m_nId, item);
	}
	CalcWidgetHeight();
	this->update();
}

void DragListWidgetPrivate::ExchangeItem(int index, DragListItem newItem, bool bUp)
{
	QList<DragListItem> items = m_items.values();
	m_items.clear();
	foreach(DragListItem item, items)
	{
		//首先判断是向上插入还是向下插入
		if (bUp)
		{
			if (item.m_nId >= index && item.m_nId < m_nExchangeStartId)
			{
				item.m_nId = item.m_nId + 1;
			}
		}
		else
		{
			if (item.m_nId > m_nExchangeStartId && (item.m_nId <= index) && item.m_nId > 1)
			{
				item.m_nId = item.m_nId - 1;
			}
		}
		m_items.insert(item.m_nId, item);
	}
	newItem.m_nId = index;
	m_items.insert(index, newItem);
	CalcWidgetHeight();
	emit sig_ActionProItem(10, QString(), false);
	this->update();
}

//设置拖拽时鼠标的形状为当前item
QPixmap DragListWidgetPrivate::GetDragCurorPixmap(int index)
{
	DragListItem item = m_items.value(index);
	int nWidth = this->width() - 20;
	QPixmap pixmap(nWidth, m_itemSize);
	pixmap.fill(Qt::transparent);
	QPainter painter(&pixmap);
	painter.setPen(m_uiSkin.m_strBorderClr);
	painter.setBrush(QColor("#ffffff"));
	painter.drawRect(1, 1, pixmap.width() - 2, pixmap.height() - 2);
	//设置图标
	int nXoffset = m_nMarginSize;
	QRect rectPixmap(nXoffset, (m_itemSize - item.m_pixmap.height()) / 2, item.m_pixmap.width(), item.m_pixmap.height());
	painter.drawPixmap(rectPixmap, item.m_pixmap);
	//绘制文本
	QFont font("Microsoft YaHei");
	font.setPixelSize(16);
	painter.setFont(font);
	painter.setPen("#333333");
	nXoffset = item.m_pixmap.width() + m_nMarginSize;
	painter.drawText(nXoffset, 0, nWidth - m_nMarginSize - item.m_pixmap.width(), m_itemSize / 2, Qt::AlignBottom, QString("%1. %2").arg(item.m_nId).arg(item.m_strTitle));
	//设置subtile
	painter.setPen("#666666");
	font.setPixelSize(12);
	painter.setFont(font);
	painter.drawText(nXoffset, m_itemSize / 2, nWidth - m_nMarginSize - item.m_pixmap.width(), m_itemSize / 2, Qt::AlignTop, item.m_strSubTitle);
	return pixmap;
}

void DragListWidgetPrivate::OpenFunction(int index)
{
	//获取子控件
	objTabName = dataVar::fProItemTab->findChild<QTabWidget*>("ProItemTabWidget");
	objTreeName = dataVar::fProItemTab->findChild<QTreeWidget*>("ProItemTreeWidget");
	int flow = objTabName->currentIndex();  //索引号
	int flow_index = 0;
	QTreeWidgetItemIterator it(objTreeName);  //遍历treeWidget
	QList<QTreeWidgetItem*> pro_keys = dataVar::fProItemTab->m_pro_value.uniqueKeys();
	for (int i = 0; i < (*it)->childCount(); i++)
	{
		QTreeWidgetItem* key = pro_keys[i];
		if ((*it)->child(flow) == pro_keys[i])
		{
			flow_index = dataVar::fProItemTab->m_pro_value.values(key).at(0);
		}
	}
	DragListItem item = m_items.value(index);
	QString itemInfo = item.m_strTitle;
	QConfig::ToolBase[flow_index]->GetToolDlg(itemInfo);
}

void DragListWidgetPrivate::SltDragPressCheck()
{
	if (-1 != m_nExchangeStartId)
	{
		m_bDragPress = true;
		DragListItem item = m_items.value(m_nExchangeStartId);
		QByteArray itemData;
		QDataStream dataStream(&itemData, QIODevice::WriteOnly);
		dataStream << item.m_pixmap << item.m_strTitle;
		QMimeData* mimeData = new QMimeData();
		mimeData->setData(DRAG_DATA, itemData);
		mimeData->setText(item.m_strTitle);
		QDrag* drag = new QDrag(this);
		drag->setMimeData(mimeData);
		QPixmap pixmapDrag = GetDragCurorPixmap(m_nExchangeStartId);
		drag->setPixmap(pixmapDrag);
		drag->exec(Qt::MoveAction);
		delete drag;
		drag = NULL;
	}
}

void DragListWidgetPrivate::slot_IconCheck()
{
	bool icon_state = false;
	DragListItem itemState = m_items.value(m_nExchangeStartId);
	QMap<QString, QtDragListWidget*>::iterator iter_state = m_states.begin();
	while (iter_state != m_states.end())
	{
		if (iter_state.key() == itemState.m_strTitle)
		{
			icon_state = true;
			stateAction_buf->setText("激活");
			stateAction_buf->setIcon(QIcon(":/res/ico/activate.png"));
			break;
		}
		iter_state++;
	}
	if (icon_state == false)
	{
		stateAction_buf->setText("禁用");
		stateAction_buf->setIcon(QIcon(":/res/ico/disable.png"));
	}
}

void DragListWidgetPrivate::mouseDoubleClickEvent(QMouseEvent* e)
{
	if (Qt::LeftButton != e->button())
		return;
	foreach(DragListItem item, m_items)
	{
		if (item.m_rectItem.contains(e->pos()))
		{
			if (m_nIndex != item.m_nId)
			{
				m_nIndex = item.m_nId;
				this->update();
			}
			//打开功能
			OpenFunction(m_nIndex);
		}
	}
}

void DragListWidgetPrivate::mousePressEvent(QMouseEvent* e)
{
	icon_timer->stop();
	m_nExchangeStartId = -1;
	foreach(DragListItem item, m_items)
	{
		if (item.m_rectItem.contains(e->pos()))
		{
			m_nIndex = item.m_nId;
			m_nExchangeStartId = item.m_nId;
			if (Qt::LeftButton == e->button())
			{
				//绘制拖拽的item
				if (m_timer->isActive())
				{
					m_timer->stop();
				}
				m_timer->start();
			}
			//右键菜单
			else if (Qt::RightButton == e->button())
			{
				icon_timer->start(100);
				this->update();
				m_menu->exec(QCursor::pos());
			}
		}
	}
}

void DragListWidgetPrivate::mouseReleaseEvent(QMouseEvent*)
{
	m_nExchangeStartId = -1;
	m_nExchangeEndId = -1;
	m_bDragPress = false;
	if (m_timer->isActive())
	{
		m_timer->stop();
	}
	this->setCursor(Qt::ArrowCursor);
}

void DragListWidgetPrivate::mouseMoveEvent(QMouseEvent* e)
{
	//先定位id
	m_nHoverItem = -1;
	m_nExchangeEndId = -1;
	foreach(DragListItem item, m_items)
	{
		if (item.m_rectItem.contains(e->pos()))
		{
			m_nHoverItem = item.m_nId;
		}
	}
	this->update();
}

void DragListWidgetPrivate::leaveEvent(QEvent*)
{
	m_nHoverItem = -1;
	m_nExchangeEndId = -1;
	this->update();
}

void DragListWidgetPrivate::dragEnterEvent(QDragEnterEvent* event)
{
	if (event->mimeData()->hasFormat(DRAG_DATA))
	{
		if (children().contains(event->source()))
		{
			event->setDropAction(Qt::MoveAction);
			event->accept();
		}
		else
		{
			event->acceptProposedAction();
		}
	}
	else if (event->mimeData()->hasText())
	{
		event->acceptProposedAction();
	}
	else
	{
		event->ignore();
	}
}

void DragListWidgetPrivate::dragMoveEvent(QDragMoveEvent* event)
{
	if (event->mimeData()->hasFormat(DRAG_DATA))
	{
		foreach(DragListItem item, m_items)
		{
			if (item.m_rectItem.contains(event->pos()))
			{
				//判断是向上插入还是向下插入
				int nOffset = (event->pos().y() - item.m_rectItem.y());
				m_bInsertUpOrDown = (nOffset < (m_itemSize / 2));
				m_nExchangeEndId = item.m_nId;
				break;
			}
			else
			{
				m_nExchangeEndId = -1;
			}
		}
		//如果都没有插入最后一行
		if (-1 == m_nExchangeEndId)
		{
			m_nExchangeEndId = m_items.size();
		}
		this->update();
		event->setDropAction(Qt::MoveAction);
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

void DragListWidgetPrivate::dropEvent(QDropEvent* event)
{
	if (event->mimeData()->hasFormat(DRAG_DATA))
	{
		bool state_icon = false;
		bool isAddItem = false;
		QStringList CurrentItemsList;
		if (-1 != m_nExchangeStartId && m_bDragPress)
		{
			if (m_items.value(m_nExchangeStartId).m_strStateTitle == "禁用")
			{
				state_icon = true;
			}
			m_items.remove(m_nExchangeStartId);
			QList<DragListItem> items = m_items.values();
			m_items.clear();
			foreach(DragListItem item, items)
			{
				CurrentItemsList.push_back(item.m_strTitle);
				if (item.m_nId > m_nExchangeStartId)
				{
					item.m_nId = item.m_nId - 1;
				}
				m_items.insert(item.m_nId, item);
			}
		}
		else
		{
			QList<DragListItem> items = m_items.values();
			foreach(DragListItem item, items)
			{
				CurrentItemsList.push_back(item.m_strTitle);
			}
			isAddItem = true;
		}
		m_nExchangeStartId = -1;
		m_nExchangeEndId = -1;
		QByteArray pieceData = event->mimeData()->data(DRAG_DATA);
		QDataStream dataStream(&pieceData, QIODevice::ReadOnly);
		QPixmap pixmap;
		QString strText;
		dataStream >> pixmap >> strText;
		int n = 0;
		QString _ItemName = strText;
		QString tempName = strText;
		//同一流程相同工具限制个数
		int tool_count;
		if (strText == "判断语句")
		{
			tool_count = 1;
		}
		else
		{
			tool_count = 30;
		}
		while (n < tool_count)
		{
			if (CurrentItemsList.contains(tempName))
			{
				tempName = _ItemName + QString::number(n + 1);
			}
			else
			{
				break;
			}
			n++;
		}
		if (n < tool_count)
		{
			strText = tempName;
		}
		else
		{
			if (strText == "判断语句")
			{
				emit dataVar::fProItemTab->sig_WarnClick();
				emit dataVar::fProItemTab->sig_Log("一个流程只能新建一个“判断语句”，类似功能可使用“跳转语句”或“脚本编辑”工具！");
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "警告", "一个流程只能新建一个“判断语句”，类似功能可使用“跳转语句”或“脚本编辑”工具！");
				msgBox.setWindowIcon(QIcon(":/res/ico/warn.png"));
				msgBox.exec();
			}
			return;
		}
		if (true == isAddItem) emit  sig_ActionProItem(0, strText, isAddItem);
		InsertItem(event->pos(), DragListItem(0, pixmap, strText, ""));
		if (state_icon == true)
		{
			qDragListWidget->SetItemSubStateText(strText, "禁用");
		}
		if (event->source() == this)
		{
			event->setDropAction(Qt::MoveAction);
			event->accept();
		}
		else
		{
			event->acceptProposedAction();
		}
		emit sig_ActionProItem(0, strText, false);
		ItemContent.insert(strText, event->pos().x() - 100);
		if_judge_index = 0;
		//插入时处理激活/禁用图标
		for (int m = 1; m <= m_items.size(); m++)
		{
			QString str = m_items.value(m).m_strStateTitle;
			if (m_items.value(m).m_strStateTitle == "禁用")
			{
				QPixmap pim = QPixmap(":/res/ico/disable_2.png");
				qDragListWidget->SetItemSubIcon(m_items.value(m).m_strTitle, pim);
			}
		}
	}
	else if (event->mimeData()->hasText())
	{
		event->acceptProposedAction();
	}
	else
	{
		event->ignore();
	}
}

void DragListWidgetPrivate::paintEvent(QPaintEvent* event)
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);
	try
	{
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing);
		painter.setPen(Qt::NoPen);
		painter.setBrush(QColor(m_uiSkin.m_strBackgroundClr));
		painter.drawRect(this->rect());
		//item
		painter.save();
		QRect rect(MARGIN_LEFT, 1, 1, 1);
		str_items.clear();
		QList<DragListItem> items_buf = m_items.values();
		foreach(DragListItem item_buf, items_buf)
		{
			str_items.append(item_buf.m_strTitle);
		}	
		if_state.reserve(100);
		if_state.clear();
		for (int p = 0; p < str_items.count(); p++)
		{
			if (str_items[p].mid(0, 4) == "判断语句")
			{
				if_state.append(p);
			}
		}		
		int j = 0;
		foreach(DragListItem item, m_items)
		{			
			rect = QRect(rect.left(), rect.bottom() + 2, this->width() - MARGIN_LEFT - 2, m_itemSize);
			item.m_rectItem = rect;
			item.m_rectSub = QRect(rect.right() - 32, rect.top() + (m_itemSize - 16) / 2 - 15, 32, 32);
			m_items.insert(item.m_nId, item);
			//绘制item			
			i_keys.reserve(100);
			i_keys.clear();
			i_keys = ItemContent.uniqueKeys();
			//各工具拖入时的坐标
			for (int p = 0; p < i_keys.length(); p++)
			{
				QString key = i_keys[p];
				if (key == item.m_strTitle)
				{
					pos_x = ItemContent.value(key);
					break;
				}
			}
			int if_state_buf = 0;
			int state_buf = 0;
			//判断语句的个数
			for (int p = 0; p < if_state.count(); p++)
			{
				if (j > if_state[p])
				{
					++state_buf;
					if_state_buf = state_buf;
				}				
			}		
			//左边线的绘制
			if (if_state_buf == 1 && ItemContent.value(str_items[str_items.count() -1]) < 20)
			{
				left_line_state = 1;
			}
			else
			{
				left_line_state = 0;
			}
			//判断语句后面是否存在非子集
			if (if_state_buf == 1)
			{
				if ((j >= if_state[0] + 1) && ItemContent.value(str_items[j]) < 20)
				{
					if_state_buf_pos_x = j + 1;		
					if (if_judge_index == 0)
					{
						if_judge_index = j;
					}					
				}
				else
				{
					if_state_buf_pos_x = 0;					
				}
			}			
			if (if_state_buf_pos_x == j + 1)
			{
				for (int p = 0; p < str_items.count(); p++)
				{
					if (p >= if_state_buf_pos_x)
					{
						pos_x = 0;
						ItemContent.insert(str_items[p], 0);
					}				
				}
			}	
			//绘制模式
			pos_x_scale = if_state_buf * 20;
			if (pos_x_scale != 0 && pos_x >= pos_x_scale)
			{
				drawItem(&painter, item, 2);
			}
			else
			{
				pos_x_scale = 0;
				drawItem(&painter, item, 1);
			}
			++j;
		}
		painter.restore();
		return QWidget::paintEvent(event);
	}
	catch (std::exception ex)
	{
		emit dataVar::fProItemTab->sig_ErrorClick();
		emit dataVar::fProItemTab->sig_Log(ex.what());		
	}
}

void DragListWidgetPrivate::drawItem(QPainter* painter, const DragListItem& item, const int draw_mode)
{
	painter->save();
	QString strColor = m_uiSkin.m_strTextClr;
	QString strSubClr = "#999999";
	if (-1 != m_nExchangeEndId)
	{
		painter->setPen(m_uiSkin.m_strBorderClr);
		//左边边线
		if (draw_mode == 1)  //正常模式
		{
			painter->drawLine(item.m_rectItem.topLeft(), item.m_rectItem.bottomLeft());
		}
		else  //右移模式
		{
			if (left_line_state == 1)
			{
				painter->drawLine(item.m_rectItem.topLeft(), item.m_rectItem.bottomLeft());
			}
			painter->drawLine(QPoint(item.m_rectItem.topLeft().x() + pos_x_scale, item.m_rectItem.topLeft().y()), QPoint(item.m_rectItem.bottomLeft().x() + pos_x_scale, item.m_rectItem.bottomLeft().y()));
		}
		//拖动移入的标线
		if (m_bInsertUpOrDown)
		{
			if (m_nExchangeEndId == item.m_nId)
			{
				painter->setPen("#00ff00");
				if (draw_mode == 1)  //正常模式
				{
					painter->drawLine(item.m_rectItem.topLeft(), item.m_rectItem.topRight());
				}
				else  //右移模式
				{
					painter->drawLine(QPoint(item.m_rectItem.topLeft().x() + pos_x_scale, item.m_rectItem.topLeft().y()), item.m_rectItem.topRight());
				}
			}
			painter->setPen(m_uiSkin.m_strBorderClr);
			if (draw_mode == 1)  //正常模式
			{
				painter->drawLine(item.m_rectItem.bottomLeft(), item.m_rectItem.bottomRight());
			}
			else  //右移模式
			{
				painter->drawLine(QPoint(item.m_rectItem.bottomLeft().x() + pos_x_scale, item.m_rectItem.bottomLeft().y()), item.m_rectItem.bottomRight());
			}
		}
		else
		{
			painter->setPen((m_nExchangeEndId == item.m_nId) ? "#ff0000" : m_uiSkin.m_strBorderClr);
			if (draw_mode == 1)  //正常模式
			{
				painter->drawLine(item.m_rectItem.bottomLeft(), item.m_rectItem.bottomRight());
			}
			else  //右移模式
			{
				painter->drawLine(QPoint(item.m_rectItem.bottomLeft().x() + pos_x_scale, item.m_rectItem.bottomLeft().y()), item.m_rectItem.bottomRight());
			}
		}
	}
	else
	{
		painter->setPen(m_uiSkin.m_strBorderClr);
		//左边边线
		if (draw_mode == 1)  //正常模式
		{
			painter->drawLine(item.m_rectItem.topLeft(), item.m_rectItem.bottomLeft());
			painter->drawLine(item.m_rectItem.bottomLeft(), item.m_rectItem.bottomRight());
		}
		else  //右移模式
		{
			if (left_line_state == 1)
			{
				painter->drawLine(item.m_rectItem.topLeft(), item.m_rectItem.bottomLeft());
			}
			painter->drawLine(QPoint(item.m_rectItem.topLeft().x() + pos_x_scale, item.m_rectItem.topLeft().y()), QPoint(item.m_rectItem.bottomLeft().x() + pos_x_scale, item.m_rectItem.bottomLeft().y()));
			painter->drawLine(QPoint(item.m_rectItem.bottomLeft().x() + pos_x_scale, item.m_rectItem.bottomLeft().y()), item.m_rectItem.bottomRight());
		}
		if ((m_nIndex == item.m_nId) || (m_nHoverItem == item.m_nId))
		{
			QString itemClr = (m_nIndex == item.m_nId) ? m_uiSkin.m_strItemSelectColor : m_uiSkin.m_strItemHoverColor;
			painter->save();
			painter->setPen(Qt::NoPen);
			painter->setBrush(QColor(itemClr));
			if (draw_mode == 1)
			{
				painter->drawRect(item.m_rectItem.left() + 1, item.m_rectItem.top() + 1, item.m_rectItem.width() - 2, item.m_rectItem.height() - 2);
			}
			else
			{
				painter->drawRect(item.m_rectItem.left() + pos_x_scale + 1, item.m_rectItem.top() + 1, item.m_rectItem.width() - 2, item.m_rectItem.height() - 2);
			}
			painter->restore();
			strColor = m_uiSkin.m_strHighLightClr;
			strSubClr = "#363636";
		}
	}
	//绘制列表item
	painter->setPen("#363636");
	int nXoffset;
	if (draw_mode == 1)
	{
		nXoffset = item.m_rectItem.left() + m_nMarginSize / 2;
	}
	else
	{
		nXoffset = item.m_rectItem.left() + m_nMarginSize / 2 + pos_x_scale;
	}
	QRect rectPixmap(nXoffset, item.m_rectItem.top() + (m_itemSize - item.m_pixmap.height()) / 2, item.m_pixmap.width() - 6, item.m_pixmap.height() - 6);
	painter->drawPixmap(rectPixmap, item.m_pixmap);
	//绘制流程完成状态图标
	painter->drawPixmap(item.m_rectSub, item.m_subPixmap);
	//绘制文本
	QFont font("Microsoft YaHei");
	font.setPixelSize(16);
	painter->setFont(font);
	if (draw_mode == 1)
	{
		nXoffset = item.m_rectItem.left() + 22 + m_nMarginSize * 2;
	}
	else
	{
		nXoffset = item.m_rectItem.left() + 22 + pos_x_scale + m_nMarginSize * 2;
	}
	painter->drawText(nXoffset, item.m_rectItem.top() + 7, item.m_rectItem.width() - m_nMarginSize - item.m_pixmap.width(), item.m_rectItem.height() / 2, Qt::AlignBottom, QString("%1. %2").arg(item.m_nId).arg(item.m_strTitle));
	//设置subtile
	painter->setPen(strSubClr);
	font.setPixelSize(13);
	painter->setFont(font);
	nXoffset = item.m_rectItem.left() + 10 + pos_x_scale + m_nMarginSize * 2;
	painter->drawText(nXoffset + item.m_rectItem.width() / 2 + 16, item.m_rectItem.top() + 22, item.m_rectItem.width() - m_nMarginSize - item.m_pixmap.width(), item.m_rectItem.height() / 2, Qt::AlignBottom, item.m_strSubTitle);
	painter->restore();
}

QtDragListWidget::QtDragListWidget(QWidget* parent) : QWidget(parent)
{
	this->d = new DragListWidgetPrivate(this);	
	connect(d, SIGNAL(sig_ActionProItem(int, QString, bool)), this, SLOT(slot_ActionProItem(int, QString, bool)));
	QScrollArea* scrollArea = new QScrollArea(this);
	scrollArea->setWidget(this->d);
	dataVar::dragD[dataVar::dragNumber] = d;
	//设置属性
	scrollArea->setWidgetResizable(true);
	scrollArea->horizontalScrollBar()->setVisible(false);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scrollArea->setStyleSheet("QScrollBar:vertical{"
		"background:#FFFFFF;"  //背景色  
		"padding-top:20px;"    //上预留位置(放置向上箭头）  
		"padding-bottom:20px;" //下预留位置(放置向下箭头）  
		"padding-left:2px;"    //左预留位置 
		"padding-right:2px;"   //右预留位置 
		"border-left:1px solid #d7d7d7;}" //左分割线  
		"QScrollBar::handle:vertical{" //滑块样式  
		"background:#dbdbdb;"  //滑块颜色  
		"border-radius:6px;"   //边角圆
		"min-height:20px;}"    //滑块最小高度
		"QScrollBar::handle:vertical:hover{" //鼠标触及滑块样式  
		"background:#d0d0d0;}" //滑块颜色  
		"QScrollBar::add-line:vertical{" //向下箭头样式  
		"background:url(:/res/ico/down.png) center no-repeat;}"
		"QScrollBar::sub-line:vertical{" //向上箭头样式
		"background:url(:/res/ico/up.png) center no-repeat;}");
	QHBoxLayout* horlayout = new QHBoxLayout(this);
	horlayout->setContentsMargins(1, 1, 1, 1);
	horlayout->setSpacing(0);
	horlayout->addWidget(scrollArea);
	connect(this->d, SIGNAL(signalItemClicked(int)), this, SIGNAL(signalItemClicked(int)));
	h_this = QThread::currentThread();
	connect(this, &QtDragListWidget::sig_ItemSubText_B1, this, &QtDragListWidget::slot_ItemSubText_B1, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B2, this, &QtDragListWidget::slot_ItemSubText_B2, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B3, this, &QtDragListWidget::slot_ItemSubText_B3, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B4, this, &QtDragListWidget::slot_ItemSubText_B4, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B5, this, &QtDragListWidget::slot_ItemSubText_B5, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B6, this, &QtDragListWidget::slot_ItemSubText_B6, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B7, this, &QtDragListWidget::slot_ItemSubText_B7, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B8, this, &QtDragListWidget::slot_ItemSubText_B8, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B9, this, &QtDragListWidget::slot_ItemSubText_B9, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B10, this, &QtDragListWidget::slot_ItemSubText_B10, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B11, this, &QtDragListWidget::slot_ItemSubText_B11, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B12, this, &QtDragListWidget::slot_ItemSubText_B12, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B13, this, &QtDragListWidget::slot_ItemSubText_B13, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B14, this, &QtDragListWidget::slot_ItemSubText_B14, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B15, this, &QtDragListWidget::slot_ItemSubText_B15, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B16, this, &QtDragListWidget::slot_ItemSubText_B16, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B17, this, &QtDragListWidget::slot_ItemSubText_B17, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B18, this, &QtDragListWidget::slot_ItemSubText_B18, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B19, this, &QtDragListWidget::slot_ItemSubText_B19, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubText_B20, this, &QtDragListWidget::slot_ItemSubText_B20, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B1, this, &QtDragListWidget::slot_ItemSubIcon_B1, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B2, this, &QtDragListWidget::slot_ItemSubIcon_B2, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B3, this, &QtDragListWidget::slot_ItemSubIcon_B3, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B4, this, &QtDragListWidget::slot_ItemSubIcon_B4, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B5, this, &QtDragListWidget::slot_ItemSubIcon_B5, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B6, this, &QtDragListWidget::slot_ItemSubIcon_B6, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B7, this, &QtDragListWidget::slot_ItemSubIcon_B7, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B8, this, &QtDragListWidget::slot_ItemSubIcon_B8, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B9, this, &QtDragListWidget::slot_ItemSubIcon_B9, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B10, this, &QtDragListWidget::slot_ItemSubIcon_B10, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B11, this, &QtDragListWidget::slot_ItemSubIcon_B11, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B12, this, &QtDragListWidget::slot_ItemSubIcon_B12, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B13, this, &QtDragListWidget::slot_ItemSubIcon_B13, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B14, this, &QtDragListWidget::slot_ItemSubIcon_B14, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B15, this, &QtDragListWidget::slot_ItemSubIcon_B15, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B16, this, &QtDragListWidget::slot_ItemSubIcon_B16, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B17, this, &QtDragListWidget::slot_ItemSubIcon_B17, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B18, this, &QtDragListWidget::slot_ItemSubIcon_B18, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B19, this, &QtDragListWidget::slot_ItemSubIcon_B19, Qt::BlockingQueuedConnection);
	connect(this, &QtDragListWidget::sig_ItemSubIcon_B20, this, &QtDragListWidget::slot_ItemSubIcon_B20, Qt::BlockingQueuedConnection);
}

QtDragListWidget::~QtDragListWidget()
{

}

int QtDragListWidget::GetIfJudgeIndex() const
{
	return d->if_judge_index;
}

int QtDragListWidget::GetAllToolCount() const
{
	return d->m_items.size();
}

int QtDragListWidget::GetCurrentItemId() const
{
	return d->m_nIndex;
}

QString QtDragListWidget::GetCurrentItemText() const
{
	return d->GetCurrentItemText();
}

#pragma region GetAllItemList
QVector<QString> QtDragListWidget::GetAllItemList() const
{
	int items_count = d->m_items.size();
	QVector<QString> TempItemList;
	TempItemList.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList[i] = d->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList;
}

QVector<QString> QtDragListWidget::GetAllItemList_B1() const
{
	int items_count = dataVar::dragD[0]->m_items.size();
	QVector<QString> TempItemList_B1;
	TempItemList_B1.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B1[i] = dataVar::dragD[0]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B1;
}

QVector<QString> QtDragListWidget::GetAllItemList_B2() const
{
	int items_count = dataVar::dragD[1]->m_items.size();
	QVector<QString> TempItemList_B2;
	TempItemList_B2.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B2[i] = dataVar::dragD[1]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B2;
}

QVector<QString> QtDragListWidget::GetAllItemList_B3() const
{
	int items_count = dataVar::dragD[2]->m_items.size();
	QVector<QString> TempItemList_B3;
	TempItemList_B3.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B3[i] = dataVar::dragD[2]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B3;
}

QVector<QString> QtDragListWidget::GetAllItemList_B4() const
{
	int items_count = dataVar::dragD[3]->m_items.size();
	QVector<QString> TempItemList_B4;
	TempItemList_B4.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B4[i] = dataVar::dragD[3]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B4;
}

QVector<QString> QtDragListWidget::GetAllItemList_B5() const
{
	int items_count = dataVar::dragD[4]->m_items.size();
	QVector<QString> TempItemList_B5;
	TempItemList_B5.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B5[i] = dataVar::dragD[4]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B5;
}

QVector<QString> QtDragListWidget::GetAllItemList_B6() const
{
	int items_count = dataVar::dragD[5]->m_items.size();
	QVector<QString> TempItemList_B6;
	TempItemList_B6.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B6[i] = dataVar::dragD[5]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B6;
}

QVector<QString> QtDragListWidget::GetAllItemList_B7() const
{
	int items_count = dataVar::dragD[6]->m_items.size();
	QVector<QString> TempItemList_B7;
	TempItemList_B7.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B7[i] = dataVar::dragD[6]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B7;
}

QVector<QString> QtDragListWidget::GetAllItemList_B8() const
{
	int items_count = dataVar::dragD[7]->m_items.size();
	QVector<QString> TempItemList_B8;
	TempItemList_B8.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B8[i] = dataVar::dragD[7]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B8;
}

QVector<QString> QtDragListWidget::GetAllItemList_B9() const
{
	int items_count = dataVar::dragD[8]->m_items.size();
	QVector<QString> TempItemList_B9;
	TempItemList_B9.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B9[i] = dataVar::dragD[8]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B9;
}

QVector<QString> QtDragListWidget::GetAllItemList_B10() const
{
	int items_count = dataVar::dragD[9]->m_items.size();
	QVector<QString> TempItemList_B10;
	TempItemList_B10.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B10[i] = dataVar::dragD[9]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B10;
}

QVector<QString> QtDragListWidget::GetAllItemList_B11() const
{
	int items_count = dataVar::dragD[10]->m_items.size();
	QVector<QString> TempItemList_B11;
	TempItemList_B11.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B11[i] = dataVar::dragD[10]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B11;
}

QVector<QString> QtDragListWidget::GetAllItemList_B12() const
{
	int items_count = dataVar::dragD[11]->m_items.size();
	QVector<QString> TempItemList_B12;
	TempItemList_B12.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B12[i] = dataVar::dragD[11]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B12;
}

QVector<QString> QtDragListWidget::GetAllItemList_B13() const
{
	int items_count = dataVar::dragD[12]->m_items.size();
	QVector<QString> TempItemList_B13;
	TempItemList_B13.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B13[i] = dataVar::dragD[12]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B13;
}

QVector<QString> QtDragListWidget::GetAllItemList_B14() const
{
	int items_count = dataVar::dragD[13]->m_items.size();
	QVector<QString> TempItemList_B14;
	TempItemList_B14.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B14[i] = dataVar::dragD[13]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B14;
}

QVector<QString> QtDragListWidget::GetAllItemList_B15() const
{
	int items_count = dataVar::dragD[14]->m_items.size();
	QVector<QString> TempItemList_B15;
	TempItemList_B15.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B15[i] = dataVar::dragD[14]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B15;
}

QVector<QString> QtDragListWidget::GetAllItemList_B16() const
{
	int items_count = dataVar::dragD[15]->m_items.size();
	QVector<QString> TempItemList_B16;
	TempItemList_B16.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B16[i] = dataVar::dragD[15]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B16;
}

QVector<QString> QtDragListWidget::GetAllItemList_B17() const
{
	int items_count = dataVar::dragD[16]->m_items.size();
	QVector<QString> TempItemList_B17;
	TempItemList_B17.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B17[i] = dataVar::dragD[16]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B17;
}

QVector<QString> QtDragListWidget::GetAllItemList_B18() const
{
	int items_count = dataVar::dragD[17]->m_items.size();
	QVector<QString> TempItemList_B18;
	TempItemList_B18.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B18[i] = dataVar::dragD[17]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B18;
}

QVector<QString> QtDragListWidget::GetAllItemList_B19() const
{
	int items_count = dataVar::dragD[18]->m_items.size();
	QVector<QString> TempItemList_B19;
	TempItemList_B19.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B19[i] = dataVar::dragD[18]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B19;
}

QVector<QString> QtDragListWidget::GetAllItemList_B20() const
{
	int items_count = dataVar::dragD[19]->m_items.size();
	QVector<QString> TempItemList_B20;
	TempItemList_B20.resize(items_count);
	for (int i = 0; i < items_count; i++)
	{
		TempItemList_B20[i] = dataVar::dragD[19]->m_items.value(i + 1).m_strTitle;
	}
	return TempItemList_B20;
}
#pragma endregion

#pragma region GetItemState
QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState() const
{
	return d->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B1() const
{
	return dataVar::dragD[0]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B2() const
{
	return dataVar::dragD[1]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B3() const
{
	return dataVar::dragD[2]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B4() const
{
	return dataVar::dragD[3]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B5() const
{
	return dataVar::dragD[4]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B6() const
{
	return dataVar::dragD[5]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B7() const
{
	return dataVar::dragD[6]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B8() const
{
	return dataVar::dragD[7]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B9() const
{
	return dataVar::dragD[8]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B10() const
{
	return dataVar::dragD[9]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B11() const
{
	return dataVar::dragD[10]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B12() const
{
	return dataVar::dragD[11]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B13() const
{
	return dataVar::dragD[12]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B14() const
{
	return dataVar::dragD[13]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B15() const
{
	return dataVar::dragD[14]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B16() const
{
	return dataVar::dragD[15]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B17() const
{
	return dataVar::dragD[16]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B18() const
{
	return dataVar::dragD[17]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B19() const
{
	return dataVar::dragD[18]->m_states;
}

QMap<QString, QtDragListWidget*> QtDragListWidget::GetItemState_B20() const
{
	return dataVar::dragD[19]->m_states;
}
#pragma endregion

void QtDragListWidget::SetItemSubStateText(const QString itemName, const QString stateName)
{
	QMap<int, DragListItem>::iterator iter = d->m_items.begin();
	while (iter != d->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strStateTitle = stateName;
			d->update();
			break;
		}
		iter++;
	}
}

#pragma region 绘制流程工具运行时间
void QtDragListWidget::SetItemSubText(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = d->m_items.begin();
	while (iter != d->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			d->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B1(const QString itemName, const QString subTitleStr)
{
	h_B1 = QThread::currentThread();
	if (h_this != h_B1)
	{
		emit sig_ItemSubText_B1(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[0]->m_items.begin();
		while (iter != dataVar::dragD[0]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[0]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B1(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[0]->m_items.begin();
	while (iter != dataVar::dragD[0]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[0]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B2(const QString itemName, const QString subTitleStr)
{
	h_B2 = QThread::currentThread();
	if (h_this != h_B2)
	{
		emit sig_ItemSubText_B2(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[1]->m_items.begin();
		while (iter != dataVar::dragD[1]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[1]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B2(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[1]->m_items.begin();
	while (iter != dataVar::dragD[1]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[1]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B3(const QString itemName, const QString subTitleStr)
{
	h_B3 = QThread::currentThread();
	if (h_this != h_B3)
	{
		emit sig_ItemSubText_B3(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[2]->m_items.begin();
		while (iter != dataVar::dragD[2]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[2]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B3(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[2]->m_items.begin();
	while (iter != dataVar::dragD[2]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[2]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B4(const QString itemName, const QString subTitleStr)
{
	h_B4 = QThread::currentThread();
	if (h_this != h_B4)
	{
		emit sig_ItemSubText_B4(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[3]->m_items.begin();
		while (iter != dataVar::dragD[3]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[3]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B4(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[3]->m_items.begin();
	while (iter != dataVar::dragD[3]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[3]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B5(const QString itemName, const QString subTitleStr)
{
	h_B5 = QThread::currentThread();
	if (h_this != h_B5)
	{
		emit sig_ItemSubText_B5(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[4]->m_items.begin();
		while (iter != dataVar::dragD[4]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[4]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B5(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[4]->m_items.begin();
	while (iter != dataVar::dragD[4]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[4]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B6(const QString itemName, const QString subTitleStr)
{
	h_B6 = QThread::currentThread();
	if (h_this != h_B6)
	{
		emit sig_ItemSubText_B6(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[5]->m_items.begin();
		while (iter != dataVar::dragD[5]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[5]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B6(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[5]->m_items.begin();
	while (iter != dataVar::dragD[5]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[5]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B7(const QString itemName, const QString subTitleStr)
{
	h_B7 = QThread::currentThread();
	if (h_this != h_B7)
	{
		emit sig_ItemSubText_B7(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[6]->m_items.begin();
		while (iter != dataVar::dragD[6]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[6]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B7(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[6]->m_items.begin();
	while (iter != dataVar::dragD[6]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[6]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B8(const QString itemName, const QString subTitleStr)
{
	h_B8 = QThread::currentThread();
	if (h_this != h_B8)
	{
		emit sig_ItemSubText_B8(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[7]->m_items.begin();
		while (iter != dataVar::dragD[7]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[7]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B8(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[7]->m_items.begin();
	while (iter != dataVar::dragD[7]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[7]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B9(const QString itemName, const QString subTitleStr)
{
	h_B9 = QThread::currentThread();
	if (h_this != h_B9)
	{
		emit sig_ItemSubText_B9(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[8]->m_items.begin();
		while (iter != dataVar::dragD[8]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[8]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B9(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[8]->m_items.begin();
	while (iter != dataVar::dragD[8]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[8]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B10(const QString itemName, const QString subTitleStr)
{
	h_B10 = QThread::currentThread();
	if (h_this != h_B10)
	{
		emit sig_ItemSubText_B10(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[9]->m_items.begin();
		while (iter != dataVar::dragD[9]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[9]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B10(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[9]->m_items.begin();
	while (iter != dataVar::dragD[9]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[9]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B11(const QString itemName, const QString subTitleStr)
{
	h_B11 = QThread::currentThread();
	if (h_this != h_B11)
	{
		emit sig_ItemSubText_B11(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[10]->m_items.begin();
		while (iter != dataVar::dragD[10]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[10]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B11(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[10]->m_items.begin();
	while (iter != dataVar::dragD[10]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[10]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B12(const QString itemName, const QString subTitleStr)
{
	h_B12 = QThread::currentThread();
	if (h_this != h_B12)
	{
		emit sig_ItemSubText_B12(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[11]->m_items.begin();
		while (iter != dataVar::dragD[11]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[11]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B12(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[11]->m_items.begin();
	while (iter != dataVar::dragD[11]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[11]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B13(const QString itemName, const QString subTitleStr)
{
	h_B13 = QThread::currentThread();
	if (h_this != h_B13)
	{
		emit sig_ItemSubText_B13(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[12]->m_items.begin();
		while (iter != dataVar::dragD[12]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[12]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B13(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[12]->m_items.begin();
	while (iter != dataVar::dragD[12]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[12]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B14(const QString itemName, const QString subTitleStr)
{
	h_B14 = QThread::currentThread();
	if (h_this != h_B14)
	{
		emit sig_ItemSubText_B14(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[13]->m_items.begin();
		while (iter != dataVar::dragD[13]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[13]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B14(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[13]->m_items.begin();
	while (iter != dataVar::dragD[13]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[13]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B15(const QString itemName, const QString subTitleStr)
{
	h_B15 = QThread::currentThread();
	if (h_this != h_B15)
	{
		emit sig_ItemSubText_B15(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[14]->m_items.begin();
		while (iter != dataVar::dragD[14]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[14]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B15(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[14]->m_items.begin();
	while (iter != dataVar::dragD[14]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[14]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B16(const QString itemName, const QString subTitleStr)
{
	h_B16 = QThread::currentThread();
	if (h_this != h_B16)
	{
		emit sig_ItemSubText_B16(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[15]->m_items.begin();
		while (iter != dataVar::dragD[15]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[15]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B16(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[15]->m_items.begin();
	while (iter != dataVar::dragD[15]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[15]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B17(const QString itemName, const QString subTitleStr)
{
	h_B17 = QThread::currentThread();
	if (h_this != h_B17)
	{
		emit sig_ItemSubText_B17(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[16]->m_items.begin();
		while (iter != dataVar::dragD[16]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[16]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B17(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[16]->m_items.begin();
	while (iter != dataVar::dragD[16]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[16]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B18(const QString itemName, const QString subTitleStr)
{
	h_B18 = QThread::currentThread();
	if (h_this != h_B18)
	{
		emit sig_ItemSubText_B18(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[17]->m_items.begin();
		while (iter != dataVar::dragD[17]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[17]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B18(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[17]->m_items.begin();
	while (iter != dataVar::dragD[17]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[17]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B19(const QString itemName, const QString subTitleStr)
{
	h_B19 = QThread::currentThread();
	if (h_this != h_B19)
	{
		emit sig_ItemSubText_B19(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[18]->m_items.begin();
		while (iter != dataVar::dragD[18]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[18]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubText_B19(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[18]->m_items.begin();
	while (iter != dataVar::dragD[18]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[18]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubText_B20(const QString itemName, const QString subTitleStr)
{
	h_B20 = QThread::currentThread();
	if (h_this != h_B20)
	{
		emit sig_ItemSubText_B20(itemName, subTitleStr);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[19]->m_items.begin();
		while (iter != dataVar::dragD[19]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_strSubTitle = subTitleStr;
				dataVar::dragD[19]->update();
				break;
			}
			iter++;
		}
	}
}

void QtDragListWidget::slot_ItemSubText_B20(const QString itemName, const QString subTitleStr)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[19]->m_items.begin();
	while (iter != dataVar::dragD[19]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_strSubTitle = subTitleStr;
			dataVar::dragD[19]->update();
			break;
		}
		iter++;
	}
}
#pragma endregion

#pragma region 绘制流程执行状态图标
void QtDragListWidget::SetItemSubIcon(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = d->m_items.begin();
	while (iter != d->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			d->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B1(const QString itemName, const QPixmap pm)
{
	h_IconB1 = QThread::currentThread();
	if (h_this != h_IconB1)
	{
		emit sig_ItemSubIcon_B1(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[0]->m_items.begin();
		while (iter != dataVar::dragD[0]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[0]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B1(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[0]->m_items.begin();
	while (iter != dataVar::dragD[0]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[0]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B2(const QString itemName, const QPixmap pm)
{
	h_IconB2 = QThread::currentThread();
	if (h_this != h_IconB2)
	{
		emit sig_ItemSubIcon_B2(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[1]->m_items.begin();
		while (iter != dataVar::dragD[1]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[1]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B2(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[1]->m_items.begin();
	while (iter != dataVar::dragD[1]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[1]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B3(const QString itemName, const QPixmap pm)
{
	h_IconB3 = QThread::currentThread();
	if (h_this != h_IconB3)
	{
		emit sig_ItemSubIcon_B3(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[2]->m_items.begin();
		while (iter != dataVar::dragD[2]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[2]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B3(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[2]->m_items.begin();
	while (iter != dataVar::dragD[2]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[2]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B4(const QString itemName, const QPixmap pm)
{
	h_IconB4 = QThread::currentThread();
	if (h_this != h_IconB4)
	{
		emit sig_ItemSubIcon_B4(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[3]->m_items.begin();
		while (iter != dataVar::dragD[3]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[3]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B4(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[3]->m_items.begin();
	while (iter != dataVar::dragD[3]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[3]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B5(const QString itemName, const QPixmap pm)
{
	h_IconB5 = QThread::currentThread();
	if (h_this != h_IconB5)
	{
		emit sig_ItemSubIcon_B5(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[4]->m_items.begin();
		while (iter != dataVar::dragD[4]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[4]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B5(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[4]->m_items.begin();
	while (iter != dataVar::dragD[4]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[4]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B6(const QString itemName, const QPixmap pm)
{
	h_IconB6 = QThread::currentThread();
	if (h_this != h_IconB6)
	{
		emit sig_ItemSubIcon_B6(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[5]->m_items.begin();
		while (iter != dataVar::dragD[5]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[5]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B6(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[5]->m_items.begin();
	while (iter != dataVar::dragD[5]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[5]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B7(const QString itemName, const QPixmap pm)
{
	h_IconB7 = QThread::currentThread();
	if (h_this != h_IconB7)
	{
		emit sig_ItemSubIcon_B7(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[6]->m_items.begin();
		while (iter != dataVar::dragD[6]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[6]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B7(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[6]->m_items.begin();
	while (iter != dataVar::dragD[6]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[6]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B8(const QString itemName, const QPixmap pm)
{
	h_IconB8 = QThread::currentThread();
	if (h_this != h_IconB8)
	{
		emit sig_ItemSubIcon_B8(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[7]->m_items.begin();
		while (iter != dataVar::dragD[7]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[7]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B8(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[7]->m_items.begin();
	while (iter != dataVar::dragD[7]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[7]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B9(const QString itemName, const QPixmap pm)
{
	h_IconB9 = QThread::currentThread();
	if (h_this != h_IconB9)
	{
		emit sig_ItemSubIcon_B9(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[8]->m_items.begin();
		while (iter != dataVar::dragD[8]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[8]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B9(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[8]->m_items.begin();
	while (iter != dataVar::dragD[8]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[8]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B10(const QString itemName, const QPixmap pm)
{
	h_IconB10 = QThread::currentThread();
	if (h_this != h_IconB10)
	{
		emit sig_ItemSubIcon_B10(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[9]->m_items.begin();
		while (iter != dataVar::dragD[9]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[9]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B10(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[9]->m_items.begin();
	while (iter != dataVar::dragD[9]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[9]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B11(const QString itemName, const QPixmap pm)
{
	h_IconB11 = QThread::currentThread();
	if (h_this != h_IconB11)
	{
		emit sig_ItemSubIcon_B11(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[10]->m_items.begin();
		while (iter != dataVar::dragD[10]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[10]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B11(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[10]->m_items.begin();
	while (iter != dataVar::dragD[10]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[10]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B12(const QString itemName, const QPixmap pm)
{
	h_IconB12 = QThread::currentThread();
	if (h_this != h_IconB12)
	{
		emit sig_ItemSubIcon_B12(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[11]->m_items.begin();
		while (iter != dataVar::dragD[11]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[11]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B12(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[11]->m_items.begin();
	while (iter != dataVar::dragD[11]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[11]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B13(const QString itemName, const QPixmap pm)
{
	h_IconB13 = QThread::currentThread();
	if (h_this != h_IconB13)
	{
		emit sig_ItemSubIcon_B13(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[12]->m_items.begin();
		while (iter != dataVar::dragD[12]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[12]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B13(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[12]->m_items.begin();
	while (iter != dataVar::dragD[12]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[12]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B14(const QString itemName, const QPixmap pm)
{
	h_IconB14 = QThread::currentThread();
	if (h_this != h_IconB14)
	{
		emit sig_ItemSubIcon_B14(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[13]->m_items.begin();
		while (iter != dataVar::dragD[13]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[13]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B14(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[13]->m_items.begin();
	while (iter != dataVar::dragD[13]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[13]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B15(const QString itemName, const QPixmap pm)
{
	h_IconB15 = QThread::currentThread();
	if (h_this != h_IconB15)
	{
		emit sig_ItemSubIcon_B15(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[14]->m_items.begin();
		while (iter != dataVar::dragD[14]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[14]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B15(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[14]->m_items.begin();
	while (iter != dataVar::dragD[14]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[14]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B16(const QString itemName, const QPixmap pm)
{
	h_IconB16 = QThread::currentThread();
	if (h_this != h_IconB16)
	{
		emit sig_ItemSubIcon_B16(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[15]->m_items.begin();
		while (iter != dataVar::dragD[15]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[15]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B16(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[15]->m_items.begin();
	while (iter != dataVar::dragD[15]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[15]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B17(const QString itemName, const QPixmap pm)
{
	h_IconB17 = QThread::currentThread();
	if (h_this != h_IconB17)
	{
		emit sig_ItemSubIcon_B17(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[16]->m_items.begin();
		while (iter != dataVar::dragD[16]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[16]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B17(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[16]->m_items.begin();
	while (iter != dataVar::dragD[16]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[16]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B18(const QString itemName, const QPixmap pm)
{
	h_IconB18 = QThread::currentThread();
	if (h_this != h_IconB18)
	{
		emit sig_ItemSubIcon_B18(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[17]->m_items.begin();
		while (iter != dataVar::dragD[17]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[17]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B18(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[17]->m_items.begin();
	while (iter != dataVar::dragD[17]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[17]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B19(const QString itemName, const QPixmap pm)
{
	h_IconB19 = QThread::currentThread();
	if (h_this != h_IconB19)
	{
		emit sig_ItemSubIcon_B19(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[18]->m_items.begin();
		while (iter != dataVar::dragD[18]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[18]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B19(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[18]->m_items.begin();
	while (iter != dataVar::dragD[18]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[18]->update();
			break;
		}
		iter++;
	}
}

void QtDragListWidget::SetItemSubIcon_B20(const QString itemName, const QPixmap pm)
{
	h_IconB20 = QThread::currentThread();
	if (h_this != h_IconB20)
	{
		emit sig_ItemSubIcon_B20(itemName, pm);
	}
	else
	{
		QMap<int, DragListItem>::iterator iter = dataVar::dragD[19]->m_items.begin();
		while (iter != dataVar::dragD[19]->m_items.end())
		{
			if (iter.value().m_strTitle == itemName)
			{
				iter.value().m_subPixmap = pm;
				dataVar::dragD[19]->update();
				break;
			}
			iter++;
		}
	}	
}

void QtDragListWidget::slot_ItemSubIcon_B20(const QString itemName, const QPixmap pm)
{
	QMap<int, DragListItem>::iterator iter = dataVar::dragD[19]->m_items.begin();
	while (iter != dataVar::dragD[19]->m_items.end())
	{
		if (iter.value().m_strTitle == itemName)
		{
			iter.value().m_subPixmap = pm;
			dataVar::dragD[19]->update();
			break;
		}
		iter++;
	}
}
#pragma endregion

void QtDragListWidget::slot_ActionProItem(int nType, QString addName, bool isAdd)
{
	emit sig_ActionProItem(nType, addName, isAdd);
}
