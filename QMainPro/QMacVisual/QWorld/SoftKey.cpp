#include "QWorld.h"
#include <QCryptographicHash>
#include <QString>

#pragma region Èí¼şËø
//Èí¼şËø
QString SoftKey::GetKey(QString key)
{	
	try
	{
		QString md5;
		QByteArray data;
		data = QCryptographicHash::hash(key.toUtf8(), QCryptographicHash::Md5);
		md5.append(data.toHex());
		QString str1 = md5.mid(0, 10);
		QString str2 = md5.mid(10);
		QString str_all = "5" + str1 + "1" + str2 + "2";
		return str_all;		
	}
	catch (...)
	{
		return QString();
	}
}
#pragma endregion
