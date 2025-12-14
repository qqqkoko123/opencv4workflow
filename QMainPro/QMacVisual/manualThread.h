#pragma once

#include <QObject>

class manualThread : public QObject
{
	Q_OBJECT

public:
	explicit manualThread(QObject *parent = nullptr);
	//线程处理函数
	void funThread_A();
	//设置线程中标志,用于停止线程
	void setStopFlag(bool flag = true); 
	void setPauseFlag(bool flag = true);

private:
	//线程工作标志
	bool isStop; 
	bool isPause;
};
