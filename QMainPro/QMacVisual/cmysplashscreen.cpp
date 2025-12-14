#include "cmysplashscreen.h"
#include <QTime>
#include <QTimer>
#include <QApplication>
#include "datavar.h"

CMySplashScreen::CMySplashScreen(QPixmap& pixmap, int time) :
	QSplashScreen(pixmap),
	elapseTime(time)
{	
	mRoundBar = new QRoundProgressBar(this);
	//设置进度条的位置
	mRoundBar->setGeometry(0, 0, pixmap.width(), pixmap.height());
	mRoundBar->setBarStyle(QRoundProgressBar::StyleDonut);
	//设置进度条的范围
	mRoundBar->setRange(0, 100);
	QPalette palette;
	palette.setBrush(QPalette::Window, Qt::NoBrush);	
	palette.setBrush(QPalette::AlternateBase, Qt::NoBrush);
	palette.setBrush(QPalette::Highlight, QBrush(QColor(130, 130, 160)));
	palette.setColor(QPalette::Text, QColor(230, 230, 255));
	palette.setBrush(QPalette::Base, QColor(45, 45, 45));
	mRoundBar->setPalette(palette);	
	mRoundBar->setValue(0);
	generateAscendRandomNumber();
	setProgress();
}

CMySplashScreen::~CMySplashScreen()
{
	mRoundBar->deleteLater();
}

void CMySplashScreen::setProgress()
{
	int tempTime = elapseTime / 100;
	for (int i = 0; i < 100; i++)
	{
		QTimer::singleShot(i * tempTime, this, SLOT(slotUpdateProgress()));		
	}	
	QTimer::singleShot(elapseTime, this, SLOT(close()));	
}

void CMySplashScreen::slotUpdateProgress()
{	
	static int num = 0;
	mRoundBar->setValue(numbersList[num]);
	num++;	
	if (num == 99)
	{		
		dataVar::app_state = false;
	}
}

void CMySplashScreen::generateAscendRandomNumber()
{
	int i;
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	//生成100个大小在[0,99]之间的随机数
	for (i = 0; i < 100; i++)
	{
		numbersList.append(qrand() % 100);
	}
	//递增排序
	qSort(numbersList.begin(), numbersList.end());
}
