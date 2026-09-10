#include "manualThread.h"
#include <QThread>
#include "datavar.h"

manualThread::manualThread(QObject *parent) : QObject(parent)
{
	isStop = false;
	isPause = false;
}

void manualThread::funThread_A()
{
	while (true)
	{
		try
		{
			if (isStop == true)
			{
				break;
			}
			if (isPause == true)
			{
				QThread::msleep(10);
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::msleep(1);
				if (dataVar::runFinish_A == true)
				{
					dataVar::runFinish_A = false;					
					dataVar::fProItemTab->slot_CyclePro();
				}				
			}
		}
		catch(...){}		
	}	
}

//停止线程标志
void manualThread::setStopFlag(bool flag)
{
	isStop = flag;
}

//暂停线程标志
void manualThread::setPauseFlag(bool flag)
{
	isPause = flag;
}
