#include "GlobalVariable.h"
#include <QEvent>
#include <QMutex>
#include <QApplication>
#include <QFontDatabase>
#include <QDebug>
#include <QPainter>

IconHelper* IconHelper::self = NULL;
IconHelper* IconHelper::Instance()
{
	if (!self)
	{
		QMutex mutex;
		QMutexLocker locker(&mutex);
		if (!self)
		{
			self = new IconHelper;
		}
	}
	return self;
}

IconHelper::IconHelper(QObject*) : QObject(qApp)
{	
}

QPixmap IconHelper::getPixmap(QString& fileName)
{	
	QPixmap pix = QPixmap(fileName);
	return pix;
}

//全局变量控制
QVector<QToolBase*> QConfig::ToolBase = QVector<QToolBase*>(20);
