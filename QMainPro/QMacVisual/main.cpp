#include "frmRegister.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
#include <QSharedMemory>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//程序只允许运行一次
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
	QSharedMemory memory("QMacVisual");
	if (!memory.create(1))
	{
		return 0;
	}	
	//更改程序启动后任务栏图标
	a.setWindowIcon(QIcon(":/Bitmaps/app.ico"));
	QApplication::setAttribute(Qt::AA_Use96Dpi);
	//Opengl渲染方式
	QApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
	QApplication::setAttribute(Qt::AA_UseOpenGLES);
	QApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
	QFile fi(":/res/default.qss");
	fi.open(QIODevice::ReadOnly);
	QTextStream stream(&fi);
	a.setStyleSheet(stream.readAll());
	fi.close();
	frmRegister w;		
	return a.exec();
}
