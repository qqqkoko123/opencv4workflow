#include "frmRegister.h"
#include <QDesktopWidget>
#include <QStyle>
#include "datavar.h"

frmRegister::frmRegister(QWidget *parent)
	: QWidget(parent)
{		
	ui.setupUi(this);	
	this->setWindowIcon(QIcon(":/Bitmaps/app.ico"));
	//若文件夹不存在，则创建
	QDir dir;
	if (!dir.exists(dataVar::path_P))
	{
		dir.mkdir(dataVar::path_P);
	}
	if (!dir.exists(dataVar::path_PF))
	{
		dir.mkdir(dataVar::path_PF);
	}
	if (!dir.exists(dataVar::path_L))
	{
		dir.mkdir(dataVar::path_L);
	}
	if (!dir.exists(dataVar::path_LA))
	{
		dir.mkdir(dataVar::path_LA);
	}
	if (!dir.exists(dataVar::path_Image))
	{
		dir.mkdir(dataVar::path_Image);
	}
	if (!dir.exists(dataVar::path_DB))
	{
		dir.mkdir(dataVar::path_DB);
	}
	QString key1 = getCpuSerialNumber();
	QString key2 = getDiskSerialNumber();
	str_key = key1.mid(0, 4) + "s" + key2.mid(3, key2.length() - 2) + "7" + key1.mid(key1.length() - 4, key1.length() - 1) + "6";
	ui.txtSerialNumber->setText(str_key);	
	QSettings settings("HKEY_CURRENT_USER\\Software\\MyApp", QSettings::NativeFormat);
	//读取注册表
	value = settings.value("sn_code", "error").toString();
	if (form_state != 1)
	{	
		m_timer = new QTimer(this);
		connect(m_timer, SIGNAL(timeout()), this, SLOT(form_statues()));
		m_timer->start(1);
	}		
}

void frmRegister::form_statues()
{		
	form_state = 1;
	m_timer->stop();
	m_timer->deleteLater();
	QString str_pw = GetKey(str_key);
	if (value == str_pw)
	{		
		this->close();			
		frmVisualLogo *fVisualLogo = new frmVisualLogo();			
	}	
	else
	{		
		this->close();			
		frmRegister *fRegister = new frmRegister();		
		//窗体移至屏幕中间
		fRegister->move(QApplication::desktop()->screen()->rect().center() - fRegister->rect().center());
		fRegister->show();			
	}
}

void frmRegister::on_btnCmdCheckID_clicked()
{	
	str_input = ui.txtAuthorizationCode->text();	
	QString str_pw = GetKey(str_key);
	if (str_input == str_pw)
	{
		QSettings settings("HKEY_CURRENT_USER\\Software\\MyApp", QSettings::NativeFormat);
		//写入注册表
		settings.setValue("sn_code", str_pw);
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "Registration is complete!");
		msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
		msgBox.exec();			
		this->close();
		this->deleteLater();
	}
	else
	{
		//QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "Wrong registration code!");
		//msgBox.setWindowIcon(QIcon(":/res/ico/error.png"));
		//msgBox.exec();		
		QSettings settings("HKEY_CURRENT_USER\\Software\\MyApp", QSettings::NativeFormat);
		//写入注册表
		settings.setValue("sn_code", str_pw);
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "Registration is complete!");
		msgBox.setWindowIcon(QIcon(":/res/ico/info.png"));
		msgBox.exec();
		this->close();
		this->deleteLater();
	}	
}

void frmRegister::on_btnCmdCheckID_pressed()
{
	ui.btnCmdCheckID->setStyleSheet("QPushButton{background-color: rgb(146, 217, 108);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}

void frmRegister::on_btnCmdCheckID_released()
{
	ui.btnCmdCheckID->setStyleSheet("QPushButton{background-color: rgb(85, 170, 127);color: rgb(0, 0, 0);border: 2px groove gray; border-radius: 8px;}");
}

QString frmRegister::GetKey(QString str)
{
	QString md5;
	QByteArray data;
	data = QCryptographicHash::hash(str.toUtf8(), QCryptographicHash::Md5);
	md5.append(data.toHex());
	QString str1 = md5.mid(0, 10);
	QString str2 = md5.mid(10);
	QString str_all = "5" + str1 + "1" + str2 + "2";
	return str_all;
}

QString frmRegister::getWMIC(const QString& cmd)
{
	//查询cpu序列号：wmic cpu get processorid
	//查询主板序列号：wmic baseboard get serialnumber
	//查询BIOS序列号：wmic bios get serialnumber
	//查看硬盘序列号：wmic diskdrive get serialnumber
	QProcess p;
	p.start(cmd);
	p.waitForFinished();
	QString result = QString::fromLocal8Bit(p.readAllStandardOutput());
	QStringList list = cmd.split(" ");
	result = result.remove(list.last(), Qt::CaseInsensitive);
	result = result.replace("\r", "");
	result = result.replace("\n", "");
	result = result.simplified();
	return result;
}

QString frmRegister::getCpuSerialNumber()
{
	return getWMIC("wmic cpu get processorid");
}

QString frmRegister::getMotherboardSerialNumber()
{
	return getWMIC("wmic baseboard get serialnumber");
}

QString frmRegister::getBIOSSerialNumber()
{
	return getWMIC("wmic bios get serialnumber");
}

QString frmRegister::getDiskSerialNumber()
{
	return getWMIC("wmic diskdrive get serialnumber");
}
