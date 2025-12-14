#pragma once
#pragma execution_character_set("utf-8")

#include <QListWidget>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QPoint>
#include <QLabel>
#include <QMenu>
#include <QListWidgetItem>
#include <QTabWidget>
#include <QTreeWidget>
#include <QPushButton>

class UiSkin {
public:
	UiSkin()
	{
		m_strBackgroundClr = "#ffffff";
		m_strBorderClr = "#3399ff";
		m_strHighLightClr = "#333333";
		m_strTextClr = "#666666";
		m_strItemHoverColor = "#d6f1c8";
		m_strItemSelectColor = "#a9e28b";
	}

public:
	QString m_strBackgroundClr;
	QString m_strBorderClr;
	QString m_strHighLightClr;
	QString m_strTextClr;
	QString m_strItemHoverColor;
	QString m_strItemSelectColor;
};

class QtDragListWidget;
class DragListItem
{
public:
	DragListItem()
	{
	}

	DragListItem(int id, QPixmap pixmap, QString title, QString describetitle, QString subtitle = "0ms") : m_nId(id), m_pixmap(pixmap), m_strTitle(title), m_strDescribeTitle(describetitle), m_strSubTitle(subtitle)
	{
	}

public:
	int m_nId;
	QPixmap m_pixmap;
	QString m_strTitle;
	QString m_strSubTitle;
	QString m_strDescribeTitle;
	QRect   m_rectItem;
	QRect   m_rectSub;
	QPixmap m_subPixmap;
	QString m_strStateTitle;
};

class DragListWidgetPrivate : public QWidget
{
	Q_OBJECT

public:
	explicit DragListWidgetPrivate(QWidget* parent = 0);
	~DragListWidgetPrivate();

	void AddItem(int id, DragListItem item);
	void AddItems(QMap<int, DragListItem> items);
	QString GetCurrentItemText();

public:
	QMap<int, DragListItem> m_items;
	int if_judge_index = 0;
	QMap<QString, QtDragListWidget*> m_states;
	int m_nIndex;
	QMap<QString, int> ItemContent;

signals:
	void signalItemClicked(int index);
	void sig_ActionProItem(int, QString, bool);

private:
	UiSkin      m_uiSkin;
	int         m_nHoverItem;
	int         m_nExchangeEndId;       //拖动交换位置
	int         m_nExchangeStartId;     //拖动起始位置
	bool        m_bInsertUpOrDown;
	int         m_nMarginSize;          //边距
	qreal       m_itemSize;             //item的size
	QTimer* m_timer;                    //针对拖拽的时间
	QMenu* m_menu;						//右键菜单	
	QPushButton* stateAction_buf;
	QtDragListWidget* qDragListWidget;
	QTabWidget* objTabName;
	QTreeWidget* objTreeName;
	QTimer* icon_timer;
	int pos_x = 0;
	QVector<QString> str_items = QVector<QString>(100);
	QList<QString> i_keys;
	QList<int> if_state;
	int pos_x_scale = 0;
	int left_line_state = 0;
	int if_state_buf_pos_x = 0;

private:
	void AddRightButtonMenu();
	void CalcWidgetHeight();
	void InsertItem(QPoint pos, DragListItem newItem);
	void DeleteItem(int index);
	//交换顺序
	void ExchangeItem(int index, DragListItem newItem, bool bUp = true);
	QPixmap GetDragCurorPixmap(int index);
	void OpenFunction(int index);

signals:
	void sig_DActivation(QString);

private slots:
	void SltDragPressCheck();
	void slot_IconCheck();
	void slot_Current();
	void slot_Previous();
	void slot_Next();
	void slot_DActivation();
	void slot_DisabledActivation(QString);
	void slot_Delete();

protected:
	bool m_bDragPress;
	void mouseDoubleClickEvent(QMouseEvent* e);
	void mousePressEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent*);
	void mouseMoveEvent(QMouseEvent* e);
	void leaveEvent(QEvent*);
	void dragEnterEvent(QDragEnterEvent* event) override;
	void dragMoveEvent(QDragMoveEvent* event) override;
	void dropEvent(QDropEvent* event) override;
	void paintEvent(QPaintEvent*);
	void drawItem(QPainter* painter, const DragListItem& item, const int draw_mode);
};

class QtDragListWidget : public QWidget
{
	Q_OBJECT

public:
	explicit QtDragListWidget(QWidget* parent = 0);
	~QtDragListWidget();

	int GetIfJudgeIndex() const;
	int GetAllToolCount() const;
	int GetCurrentItemId() const;
	QString GetCurrentItemText() const;
	QVector<QString> GetAllItemList() const, GetAllItemList_B1() const, GetAllItemList_B2() const, GetAllItemList_B3() const, GetAllItemList_B4() const, GetAllItemList_B5() const, GetAllItemList_B6() const, GetAllItemList_B7() const, GetAllItemList_B8() const, GetAllItemList_B9() const, GetAllItemList_B10() const;
	QVector<QString> GetAllItemList_B11() const, GetAllItemList_B12() const, GetAllItemList_B13() const, GetAllItemList_B14() const, GetAllItemList_B15() const, GetAllItemList_B16() const, GetAllItemList_B17() const, GetAllItemList_B18() const, GetAllItemList_B19() const, GetAllItemList_B20() const;
	QMap<QString, QtDragListWidget*> GetItemState() const, GetItemState_B1()const, GetItemState_B2() const, GetItemState_B3() const, GetItemState_B4() const, GetItemState_B5() const, GetItemState_B6() const, GetItemState_B7() const, GetItemState_B8() const, GetItemState_B9() const, GetItemState_B10() const;
	QMap<QString, QtDragListWidget*> GetItemState_B11() const, GetItemState_B12()const, GetItemState_B13() const, GetItemState_B14() const, GetItemState_B15() const, GetItemState_B16() const, GetItemState_B17() const, GetItemState_B18() const, GetItemState_B19() const, GetItemState_B20() const;
	void SetItemSubText(const QString itemName, const QString sunName);
	void SetItemSubIcon(const QString itemName, const QPixmap pm);
	void SetItemSubStateText(const QString itemName, const QString stateName);

private:
	QThread* h_this, * h_B1, * h_B2, * h_B3, * h_B4, * h_B5, * h_B6, * h_B7, * h_B8, * h_B9, * h_B10;
	QThread* h_B11, * h_B12, * h_B13, * h_B14, * h_B15, * h_B16, * h_B17, * h_B18, * h_B19, * h_B20;
	QThread* h_IconB1, * h_IconB2, * h_IconB3, * h_IconB4, * h_IconB5, * h_IconB6, * h_IconB7, * h_IconB8, * h_IconB9, * h_IconB10;
	QThread* h_IconB11, * h_IconB12, * h_IconB13, * h_IconB14, * h_IconB15, * h_IconB16, * h_IconB17, * h_IconB18, * h_IconB19, * h_IconB20;

signals:
	void signalItemClicked(int index);
	void sig_ActionProItem(int, QString, bool);
	void sig_ItemSubText_B1(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B2(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B3(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B4(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B5(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B6(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B7(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B8(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B9(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B10(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B11(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B12(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B13(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B14(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B15(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B16(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B17(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B18(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B19(const QString itemName, const QString subTitleStr);
	void sig_ItemSubText_B20(const QString itemName, const QString subTitleStr);

private slots:
	void slot_ItemSubText_B1(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B2(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B3(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B4(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B5(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B6(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B7(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B8(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B9(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B10(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B11(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B12(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B13(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B14(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B15(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B16(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B17(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B18(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B19(const QString itemName, const QString subTitleStr);
	void slot_ItemSubText_B20(const QString itemName, const QString subTitleStr);

public:
	void SetItemSubText_B1(const QString itemName, const QString sunName);
	void SetItemSubText_B2(const QString itemName, const QString sunName);
	void SetItemSubText_B3(const QString itemName, const QString sunName);
	void SetItemSubText_B4(const QString itemName, const QString sunName);
	void SetItemSubText_B5(const QString itemName, const QString sunName);
	void SetItemSubText_B6(const QString itemName, const QString sunName);
	void SetItemSubText_B7(const QString itemName, const QString sunName);
	void SetItemSubText_B8(const QString itemName, const QString sunName);
	void SetItemSubText_B9(const QString itemName, const QString sunName);
	void SetItemSubText_B10(const QString itemName, const QString sunName);
	void SetItemSubText_B11(const QString itemName, const QString sunName);
	void SetItemSubText_B12(const QString itemName, const QString sunName);
	void SetItemSubText_B13(const QString itemName, const QString sunName);
	void SetItemSubText_B14(const QString itemName, const QString sunName);
	void SetItemSubText_B15(const QString itemName, const QString sunName);
	void SetItemSubText_B16(const QString itemName, const QString sunName);
	void SetItemSubText_B17(const QString itemName, const QString sunName);
	void SetItemSubText_B18(const QString itemName, const QString sunName);
	void SetItemSubText_B19(const QString itemName, const QString sunName);
	void SetItemSubText_B20(const QString itemName, const QString sunName);
	void SetItemSubIcon_B1(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B2(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B3(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B4(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B5(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B6(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B7(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B8(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B9(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B10(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B11(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B12(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B13(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B14(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B15(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B16(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B17(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B18(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B19(const QString itemName, const QPixmap pm);
	void SetItemSubIcon_B20(const QString itemName, const QPixmap pm);

signals:
	void sig_ItemSubIcon_B1(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B2(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B3(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B4(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B5(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B6(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B7(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B8(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B9(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B10(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B11(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B12(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B13(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B14(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B15(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B16(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B17(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B18(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B19(const QString itemName, const QPixmap pm);
	void sig_ItemSubIcon_B20(const QString itemName, const QPixmap pm);

private slots:
	void slot_ItemSubIcon_B1(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B2(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B3(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B4(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B5(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B6(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B7(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B8(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B9(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B10(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B11(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B12(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B13(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B14(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B15(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B16(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B17(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B18(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B19(const QString itemName, const QPixmap pm);
	void slot_ItemSubIcon_B20(const QString itemName, const QPixmap pm);	

private slots:
	void slot_ActionProItem(int, QString, bool);

public:
	DragListWidgetPrivate* d;
};
