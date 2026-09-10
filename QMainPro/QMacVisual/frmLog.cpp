#include "frmLog.h"
#include "ui_frmLog.h"
#include <QDateTime>
#include "clogmodel.h"
#include "savelog.h"
#include "datavar.h"
#include "qmutex.h"

FrmLog::FrmLog(QWidget* parent) :
	QWidget(parent)
{
	ui.setupUi(this);
	//设置是否开启日志上下文打印比如行号、函数等
	SaveLog::Instance()->setUseContext(false);
	SaveLog::Instance()->setName(QString());
	//设置文件存储目录
	SaveLog::Instance()->setPath(dataVar::path_LA);
	m_pInfoModel = new CLogModel(this);
	m_pWarnModel = new CLogModel(this);
	m_pErrorModel = new CLogModel(this);
	ui.listView->setModel(m_pInfoModel);
	ui.listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.listView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel); //按像素移动	
	SaveLog::Instance()->start();
	connect(ui.btnInfo, &QToolButton::clicked, this, &FrmLog::slot_InfoClick);
	connect(ui.btnWarn, &QToolButton::clicked, this, &FrmLog::slot_WarnClick);
	connect(ui.btnError, &QToolButton::clicked, this, &FrmLog::slot_ErrorClick);
	p_timer = new QTimer(this);
	connect(p_timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
	p_timer->start(300);
	h_this = QThread::currentThread();
	connect(this, &FrmLog::sig_Message_Info, m_pInfoModel, &CLogModel::insert, Qt::BlockingQueuedConnection);
	connect(this, &FrmLog::sig_Message_Warn, m_pWarnModel, &CLogModel::insert, Qt::BlockingQueuedConnection);
	connect(this, &FrmLog::sig_Message_Error, m_pErrorModel, &CLogModel::insert, Qt::BlockingQueuedConnection);	
}

FrmLog::~FrmLog()
{
	SaveLog::Instance()->stop();
}

QSize FrmLog::sizeHint() const
{
	return QSize(860, 150);
}

void FrmLog::slot_InfoClick()
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);
	ui.listView->setStyleSheet("color: rgb(0, 0, 255);");
	m_currentLogType = LogType::Info;
	ui.listView->setModel(m_pInfoModel);
}

void FrmLog::slot_WarnClick()
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);
	ui.listView->setStyleSheet("color: rgb(172, 100, 50);");
	m_currentLogType = LogType::Warn;
	ui.listView->setModel(m_pWarnModel);
}

void FrmLog::slot_ErrorClick()
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);
	ui.listView->setStyleSheet("color: rgb(255, 0, 0);");
	m_currentLogType = LogType::Error;
	ui.listView->setModel(m_pErrorModel);
}

void FrmLog::timerEvent()
{
	ui.btnInfo->setText(QString("提示(%1)").arg(m_pInfoModel->length()));	
	ui.btnWarn->setText(QString("警告(%1)").arg(m_pWarnModel->length()));
	ui.btnError->setText(QString("错误(%1)").arg(m_pErrorModel->length()));
}

void FrmLog::slot_Message(const QString strMsg)
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);
	if (m_pInfoModel->length() > 500)
	{
		m_pInfoModel->clear();
	}
	if (m_pWarnModel->length() > 500)
	{
		m_pWarnModel->clear();
	}
	if (m_pErrorModel->length() > 500)
	{
		m_pErrorModel->clear();
	}
	QString typeMsg, logTypeMsg;
	QString time, msg;
	QByteArray buffer;
	const char* data;
	switch (m_currentLogType) {
	case LogType::Info:
		logTypeMsg = "INFO";
		typeMsg = "  -";
		time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
		msg = time + " " + "[" + logTypeMsg + "]" + typeMsg + "  " + strMsg;
		m_pInfoModel->insert(0, msg);
		ui.btnInfo->setText(QString("提示(%1)").arg(m_pInfoModel->length()));
		buffer = msg.toUtf8();
		data = buffer.constData();
		qInfo(data);
		break;
	case LogType::Warn:
		logTypeMsg = "WARN";
		typeMsg = "  -";
		time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
		msg = time + " " + "[" + logTypeMsg + "]" + typeMsg + "  " + strMsg;
		m_pWarnModel->insert(0, msg);
		ui.btnWarn->setText(QString("警告(%1)").arg(m_pWarnModel->length()));
		buffer = msg.toUtf8();
		data = buffer.constData();
		qWarning(data);
		break;
	case LogType::Error:
		logTypeMsg = "ERROR";
		typeMsg = "  -";
		time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
		msg = time + " " + "[" + logTypeMsg + "]" + typeMsg + "  " + strMsg;
		m_pErrorModel->insert(0, msg);
		ui.btnError->setText(QString("错误(%1)").arg(m_pErrorModel->length()));
		buffer = msg.toUtf8();
		data = buffer.constData();
		qCritical(data);
		break;
	default:
		break;
	}
}

void FrmLog::slot_Message_Info(const QString strMsg)
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);	
	h_info = QThread::currentThread();
	QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
	QString msg = time + " " + "[INFO]" + "  -" + "  " + strMsg;	
	if (h_this != h_info)
	{
		emit sig_Message_Info(0, msg);
	}
	else
	{
		m_pInfoModel->insert(0, msg);
	}
	QByteArray buffer = msg.toUtf8();
	const char* data = buffer.constData();
	qInfo(data);
}

void FrmLog::slot_Message_Warn(const QString strMsg)
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);
	h_warn = QThread::currentThread();
	QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
	QString msg = time + " " + "[WARN]" + "  -" + "  " + strMsg;
	if (h_this != h_warn)
	{
		emit sig_Message_Warn(0, msg);
	}
	else
	{
		m_pWarnModel->insert(0, msg);
	}
	QByteArray buffer = msg.toUtf8();
	const char* data = buffer.constData();
	qInfo(data);
}

void FrmLog::slot_Message_Error(const QString strMsg)
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);
	h_error = QThread::currentThread();
	QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
	QString msg = time + " " + "[ERROR]" + "  -" + "  " + strMsg;
	if (h_this != h_error)
	{
		emit sig_Message_Error(0, msg);
	}
	else
	{
		m_pErrorModel->insert(0, msg);
	}
	QByteArray buffer = msg.toUtf8();
	const char* data = buffer.constData();
	qInfo(data);
}
