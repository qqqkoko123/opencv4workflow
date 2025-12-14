#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

enum ButtonType
{
	MIN_BUTTON = 0,			//最小化和关闭按钮
	MIN_MAX_BUTTON ,		//最小化、最大化和关闭按钮
	ONLY_CLOSE_BUTTON		//只有关闭按钮
};

class MyTitleBar : public QWidget
{
	Q_OBJECT

public:
	MyTitleBar(QWidget *parent = NULL);
	~MyTitleBar();

	//设置标题栏背景色
	void setBackgroundColor(int r, int g, int b);
	//设置标题栏图标
	void setTitleIcon(QString filePath);
	//设置标题内容
	void setTitleContent(QString titleContent);
	//设置标题栏长度
	void setTitleWidth(int width);
	//设置标题栏上按钮类型
	void setButtonType(ButtonType buttonType);
	//设置标题栏中的标题是否会滚动;具体可以看效果
	void setTitleRoll();
	//保存最大化前窗口的位置及大小
	void saveRestoreInfo(const QPoint point, const QSize size);
	//获取最大化前窗口的位置及大小
	void getRestoreInfo(QPoint& point, QSize& size);

private:
	void paintEvent(QPaintEvent *event);
	void mouseDoubleClickEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	//初始化控件
	void initControl();
	//信号槽的绑定
	void initConnections();
	//加载样式文件
	void loadStyleSheet(const QString &sheetName);

signals:
	//按钮触发的信号
	void signalButtonMinClicked();
	void signalButtonRestoreClicked();
	void signalButtonMaxClicked();
	void signalButtonCloseClicked();

private slots:
	//按钮触发的槽函数
	void onButtonMinClicked();
	void onButtonRestoreClicked();
	void onButtonMaxClicked();
	void onButtonCloseClicked();
	void onRollTitle();

private:
	QLabel* m_pIcon;					//标题栏图标
	QLabel* m_pTitleContent;			//标题栏内容
	QPushButton* m_pButtonMin;			//最小化按钮
	QPushButton* m_pButtonRestore;		//最大化还原按钮
	QPushButton* m_pButtonMax;			//最大化按钮
	QPushButton* m_pButtonClose;		//关闭按钮	
	//标题栏背景色
	int m_colorR;
	int m_colorG;
	int m_colorB;
	//最大化、最小化变量
	QPoint m_restorePos;
	QSize m_restoreSize;
	//移动窗口的变量
	bool m_isPressed;
	QPoint m_startMovePos;
	//标题栏跑马灯效果时钟
	QTimer m_titleRollTimer;
	//标题栏内容
	QString m_titleContent;
	//按钮类型
	ButtonType m_buttonType;
};
