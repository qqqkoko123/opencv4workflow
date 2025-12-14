#pragma once

#include <QSplashScreen>
#include <QPixmap>
#include <QProgressBar>
#include <QList>
#include <QtGlobal>
#include "QRoundProgressBar.h"

class CMySplashScreen : public QSplashScreen
{
	Q_OBJECT

public:
	CMySplashScreen(QPixmap& pixmap, int time);
	~CMySplashScreen();

private:
	//进度条
	QRoundProgressBar* mRoundBar;	
	//随机数列表
	QList<int> numbersList;
	//启动界面停留的时间
	int elapseTime;

private:
	//设置进度条
	void setProgress();
	//生成递增的随机数
	void generateAscendRandomNumber();

private slots:
	//更新进度条
	void slotUpdateProgress();
};
