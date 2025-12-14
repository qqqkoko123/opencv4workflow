#include "PlcTcpSocket.h"

#pragma region MitTcpSocket
#pragma region ASCII
MitTcpSocket::MitTcpSocket(void)
{
	m_connected = false;
	return;
}

MitTcpSocket::~MitTcpSocket(void)
{	
	m_connected = false;
}

//连接服务器
bool MitTcpSocket::Connect(QString key, QString ip, int port)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		if (!m_connected)
		{
			m_socket.connectToHost(QHostAddress(ip), port);
			m_connected = m_socket.waitForConnected();
		}
		if (m_connected == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	catch (...)
	{
		return false;
	}
}

void MitTcpSocket::Disconnect(QString key)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return;
	}
	if (m_connected == true)
	{
		m_connected = false;
		m_socket.close();
		m_socket.deleteLater();
	}
}

//置位辅助继电器M
bool MitTcpSocket::SetM(QString key, QString device)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		QByteArray RData;
		RData.resize(257);
		//Set with the QnA-compatible 3E frame command.
		int lengthM = device.length();
		switch (lengthM)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		QString SData = "500000FF03FF000019001014010001M*" + device + "00011";
		//发送数据
		m_socket.write(SData.toUtf8().data());
		//阻塞函数
		m_socket.waitForReadyRead(15);
		//接收状态，防止读取的时候出现该状态
		RData = m_socket.readAll();
		return true;
	}
	catch (...)
	{
		return false;
	}
}

//复位辅助继电器M
bool MitTcpSocket::RstM(QString key, QString device)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		QByteArray RData;
		RData.resize(257);
		//Set with the QnA-compatible 3E frame command.
		int lengthM = device.length();
		switch (lengthM)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		QString SData = "500000FF03FF000019001014010001M*" + device + "00010";
		//发送数据
		m_socket.write(SData.toUtf8().data());
		//阻塞函数
		m_socket.waitForReadyRead(15);
		//接收状态，防止读取的时候出现该状态
		RData = m_socket.readAll();
		return true;
	}
	catch (...)
	{
		return false;
	}
}

//置位锁存继电器L
bool MitTcpSocket::SetL(QString key, QString device)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		QByteArray RData;
		RData.resize(257);
		//Set with the QnA-compatible 3E frame command.
		int lengthL = device.length();
		switch (lengthL)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		QString SData = "500000FF03FF000019001014010001L*" + device + "00011";
		//发送数据
		m_socket.write(SData.toUtf8().data());
		//阻塞函数
		m_socket.waitForReadyRead(15);
		//接收状态，防止读取的时候出现该状态
		RData = m_socket.readAll();
		return true;
	}
	catch (...)
	{
		return false;
	}
}

//复位锁存继电器L
bool MitTcpSocket::RstL(QString key, QString device)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		QByteArray RData;
		RData.resize(257);
		//Set with the QnA-compatible 3E frame command.
		int lengthL = device.length();
		switch (lengthL)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		QString SData = "500000FF03FF000019001014010001L*" + device + "00010";
		//发送数据
		m_socket.write(SData.toUtf8().data());
		//阻塞函数
		m_socket.waitForReadyRead(15);
		//接收状态，防止读取的时候出现该状态
		RData = m_socket.readAll();
		return true;
	}
	catch (...)
	{
		return false;
	}
}

//写入16位寄存器
bool MitTcpSocket::Write1D(QString key, QString device, short value)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		QByteArray RData;
		RData.resize(257);
		//Set with the QnA-compatible 3E frame command.
		int length_1D = device.length();
		switch (length_1D)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		//十进制转十六进制(保留8位，不足补0)		
		QString strNumD = QString("%1").arg(value, 8, 16, QLatin1Char('0'));
		int lengthRec = strNumD.length();
		strNumD = strNumD.mid(lengthRec - 4);
		QString SData = "500000FF03FF00001C001014010000D*" + device + "0001" + strNumD;
		//发送数据
		m_socket.write(SData.toUtf8().data());
		//阻塞函数
		m_socket.waitForReadyRead(15);
		//接收状态，防止读取的时候出现该状态
		RData = m_socket.readAll();
		return true;
	}
	catch (...)
	{
		return false;
	}
}

//读取16位寄存器
bool MitTcpSocket::Read1D(QString key, QString device, short &value)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		QByteArray RData;
		RData.resize(26);
		//Set with the QnA-compatible 3E frame command.
		int length_1D = device.length();
		switch (length_1D)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		QString SData = "500000FF03FF000018001004010000D*" + device + "0001";
		//发送数据
		m_socket.write(SData.toUtf8().data());
		//阻塞函数
		m_socket.waitForReadyRead(15);
		//接收数据
		RData = m_socket.readAll();
		QString strRData = RData;
		int lengthRec = strRData.length();
		strRData = strRData.mid(lengthRec - 4);
		//十六进制转十进制
		value = strRData.toInt(0, 16);
		if (value >= 32768)
		{
			value -= 65536;
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}

//写入32位寄存器
bool MitTcpSocket::Write2D(QString key, QString device, int value)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		QByteArray RData;
		RData.resize(257);
		int intNumD_L = 0;
		int intNumD_H = 0;
		//Set with the QnA-compatible 3E frame command.
		int length_1D = device.length();
		switch (length_1D)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		//双字转两个单字
		DWordToSWord(value, intNumD_L, intNumD_H);
		//十进制转十六进制(保留8位，不足补0)		
		QString strNumD_L = QString("%1").arg(intNumD_L, 8, 16, QLatin1Char('0'));
		strNumD_L = strNumD_L.right(4);
		QString strNumD_H = QString("%1").arg(intNumD_H, 8, 16, QLatin1Char('0'));
		strNumD_H = strNumD_H.right(4);
		QString SData = "500000FF03FF000020001014010000D*" + device + "0002" + strNumD_L + strNumD_H;
		//发送数据
		m_socket.write(SData.toUtf8().data());
		//阻塞函数
		m_socket.waitForReadyRead(15);
		//接收状态，防止读取的时候出现该状态
		RData = m_socket.readAll();
		return true;
	}
	catch (...)
	{
		return false;
	}
}

//双字转两个单字
void MitTcpSocket::DWordToSWord(int int32Num, int &int16Num_L, int &int16Num_H)
{
	try
	{
		vector<short> nn(2);
		int iv = int32Num;
		//long long长度是64位
		long long lv = iv;
		uint uv = static_cast<uint>((lv + 65536LL * 65536LL) % (65536LL * 65536LL));
		//转成无符号范围的数             
		ulong ul = uv;
		uv = static_cast<uint>(ul % 65536);
		iv = static_cast<uint>(uv);
		//将超出 32768 一半的数转成负值 
		if ((iv >= 32768))
			iv -= 65536;
		nn[0] = static_cast<short>(iv);
		uv = static_cast<uint>(ul / 65536);
		iv = static_cast<int>(uv);
		//将超出 32768 一半的数转成负值 
		if ((iv >= 32768))
			iv -= 65536;
		nn[1] = static_cast<short>(iv);
		int16Num_L = nn[0];
		int16Num_H = nn[1];
	}
	catch (...){}	
}

//读取32位寄存器
bool MitTcpSocket::Read2D(QString key, QString device, int &value)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		QByteArray RData;
		RData.resize(30);
		//Set with the QnA-compatible 3E frame command.
		int length_1D = device.length();
		switch (length_1D)
		{
		case 1:
			device = "00000" + device;
			break;
		case 2:
			device = "0000" + device;
			break;
		case 3:
			device = "000" + device;
			break;
		case 4:
			device = "00" + device;
			break;
		case 5:
			device = "0" + device;
			break;
		}
		QString SData = "500000FF03FF000018001004010000D*" + device + "0002";
		//发送数据
		m_socket.write(SData.toUtf8().data());
		//阻塞函数
		m_socket.waitForReadyRead(15);
		//接收数据
		RData = m_socket.readAll();
		QString strRData = RData;
		int lengthRec = strRData.length();
		QString strRData_H = strRData.mid(lengthRec - 4);
		//十六进制转十进制
		int NumD_H = strRData_H.toInt(0, 16);
		if (NumD_H >= 32768)
		{
			NumD_H -= 65536;
		}
		QString strRData_L = strRData.mid(lengthRec - 8, 4);
		//十六进制转十进制
		int NumD_L = strRData_L.toInt(0, 16);
		if (NumD_L >= 32768)
		{
			NumD_L -= 65536;
		}
		//两个单字双字转
		SWordToDWord(NumD_L, NumD_H, value);
		return true;
	}
	catch (...)
	{
		return false;
	}
}

//两个单字转双字
void MitTcpSocket::SWordToDWord(int int16Num_L, int int16Num_H, int &int32Num)
{
	try
	{
		vector<int> iData(2);
		vector<long long> uData(2);
		//低16位值
		iData[0] = int16Num_L;
		//高16位值
		iData[1] = int16Num_H;
		//转成无符号 0-65535 范围的数
		uData[0] = (iData[0] + 65536) % 65536;
		//同上
		uData[1] = (iData[1] + 65536) % 65536;
		long long lData = uData[1] * 65536 + uData[0];
		//转成32位无符号范围的数
		//将超出 2^32 一半的数转成负值 
		if ((lData >= 65536L * 32768L))
		{
			lData -= 65536L * 65536L;
		}
		int32Num = static_cast<int>(lData);
	}
	catch (...){}	
}
#pragma endregion

#pragma region Binary
MitTcpSocket_Binary::MitTcpSocket_Binary(void)
{
	m_connected = false;
	m_socket = 0;
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0)
	{
		printf("can`t start winsock %d", wsResult);
		return;
	}
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket == INVALID_SOCKET)
	{
		m_socket = 0;
		printf("can`t create socket, Err:%d", WSAGetLastError());
		return;
	}
	return;
}


MitTcpSocket_Binary::~MitTcpSocket_Binary(void)
{	
	WSACleanup();
	m_connected = false;
}

bool MitTcpSocket_Binary::Connect_Binary(QString key, string ip /* = "192.168.3.39" */, int port /* = 8192 */)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		if (!m_connected)
		{
			SOCKADDR_IN hint;
			hint.sin_family = AF_INET;
			hint.sin_addr.s_addr = inet_addr(ip.c_str());
			hint.sin_port = htons(port);
			if (::connect(m_socket, (SOCKADDR*)&hint, sizeof(hint)) == SOCKET_ERROR)
			{
				m_socket = 0;
				printf("can`t connect socket, Err:%d", WSAGetLastError());
				return false;
			}
			m_connected = true;
		}
		return m_connected;
	}
	catch (...)
	{
		return false;
	}	
}

void MitTcpSocket_Binary::Disconnect_Binary(QString key)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return;
	}
	if (m_socket > 0)
	{
		closesocket(m_socket);
		m_socket = 0;
	}
}

string& MitTcpSocket_Binary::std_string_format(string& _str, const char * _Format, ...)
{
	try
	{
		string tmp;
		va_list marker = NULL;
		va_start(marker, _Format);
		size_t num_of_chars = _vscprintf(_Format, marker);
		if (num_of_chars > tmp.capacity()) {
			tmp.resize(num_of_chars + 1);
		}
		vsprintf_s((char *)tmp.data(), tmp.capacity(), _Format, marker);
		va_end(marker);
		_str = tmp.c_str();
		return _str;
	}
	catch (...)
	{
		return _str;
	}
}

string MitTcpSocket_Binary::Int16ToHexConvert(short va)
{
	try
	{
		UINT16 num = (UINT16)va;
		string temp;
		std_string_format(temp, "%02X", num);
		string xx = temp.substr(2, 2) + temp.substr(0, 2);
		return xx;
	}
	catch (...)
	{
		return string();
	}	
}

string MitTcpSocket_Binary::Int32ToHexConvert(INT32 va)
{
	try
	{
		string temp;
		std_string_format(temp, "%04X", va);
		string xx = temp.substr(2, 2) + temp.substr(0, 2);
		return xx;
	}
	catch (...)
	{
		return string();
	}	
}

string MitTcpSocket_Binary::Int48ToHexConvert(INT64 va)
{
	try
	{
		string temp;
		std_string_format(temp, "%06X", va);
		string xx = temp.substr(4, 2) + temp.substr(2, 2) + temp.substr(0, 2);
		return xx;
	}
	catch (...)
	{
		return string();
	}	
}

string MitTcpSocket_Binary::Int64ToHexConvert(INT64 va)
{
	try
	{
		string temp;
		std_string_format(temp, "%08X", va);
		string xx = temp.substr(6, 2) + temp.substr(4, 2) + temp.substr(2, 2) + temp.substr(0, 2);
		return xx;
	}
	catch (...)
	{
		return string();
	}	
}

string MitTcpSocket_Binary::Int32ToHexConvert2(INT32 va)
{
	try
	{
		string temp;
		std_string_format(temp, "%04X", va);
		string xx = temp.substr(6, 2) + temp.substr(4, 2) + temp.substr(2, 2) + temp.substr(0, 2);
		return xx;
	}
	catch (...) 
	{
		return string();
	}	
}

#define MAX_BUFF 1024

bool MitTcpSocket_Binary::SendMessg(string msg)
{
	try
	{
		if (m_socket == 0) return false;
		if (!m_connected) return false;
		mutex.lock();
		int count = msg.length() / 2;
		byte datas[MAX_BUFF] = { 0 };
		for (int i = 0; i < count; i++)
		{
			long num = strtol(msg.substr(i * 2, 2).data(), NULL, 16);
			datas[i] = num;
		}
		int retLen = send(m_socket, (const char*)datas, count, 0);
		mutex.unlock();
		if (retLen <= 0)
		{
			printf("send error, ErrCode:%d", WSAGetLastError());
			return false;
		}
		return true;
	}
	catch (...)
	{
		return false;
	}	
}

string MitTcpSocket_Binary::ReceiveMsg()
{
	try
	{
		if (m_socket == 0) return "";
		if (!m_connected) return "";
		string re = "";
		byte buffer[MAX_BUFF] = { 0 };
		int retLen = recv(m_socket, (char*)buffer, MAX_BUFF, 0);
		if (retLen > 0)
		{
			for (int i = 0; i < MAX_BUFF; i++)
			{
				string temp;
				std_string_format(temp, "%02X", buffer[i]);
				re += temp;
			}
		}
		else
		{
			int errCode = WSAGetLastError();
			if (retLen < 0 && errCode != EAGAIN && errCode != EWOULDBLOCK && errCode != EINTR)
			{
				printf("socket closed, ErrCode:%d", WSAGetLastError());
				return "";
			}
		}
		return re;
	}
	catch (...) 
	{
		return string();
	}	
}

bool MitTcpSocket_Binary::Write1D_Binary(QString key, string device, short value)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		string sendStr = "500000FFFF0300";
		int len = 8 + 1 * 6;
		string temp = Int32ToHexConvert(len);
		sendStr += temp;
		sendStr += "100002140000";
		sendStr += Int32ToHexConvert(1);
		string name = Int48ToHexConvert(strtol(device.data(), NULL, 10));
		string va;
		if (value >= 0)
		{
			va = Int32ToHexConvert(value);
		}
		else
		{
			va = Int16ToHexConvert(value);
		}
		sendStr += name + "A8" + va;
		SendMessg(sendStr);
		string strRead = ReceiveMsg();
		if (strRead.length() > 20 && strRead.substr(18, 4) == "0000")
			return true;
		return false;
	}
	catch (...)
	{
		return false;
	}	
}

bool MitTcpSocket_Binary::Write2D_Binary(QString key, string device, INT32 value)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		string sendStr = "500000FFFF0300";
		string temp = "";
		int len = 8 + 1 * 8;
		temp = Int32ToHexConvert(len);
		sendStr += temp;
		sendStr += "100002140000";
		sendStr += "0001"; //1.ToString("X4");  
		string name = Int48ToHexConvert(strtoul(device.data(), NULL, 10));
		string va;
		if (value >= 0)
		{
			va = Int64ToHexConvert(value);
		}
		else
		{
			va = Int32ToHexConvert2(value);
		}
		sendStr += name + "A8" + va;
		SendMessg(sendStr);
		string strRead = ReceiveMsg();
		if (strRead.length() > 20 && strRead.substr(18, 4) == "0000")
			return true;
		return false;
	}
	catch (...)
	{
		return false;
	}	
}

short MitTcpSocket_Binary::Read1D_Binary(QString key, string device)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		string sendStr = "500000FFFF0300";
		string temp = "";
		int len = 12;
		temp = Int32ToHexConvert(len);
		sendStr += temp;
		sendStr += "100001040000";
		string name = Int48ToHexConvert(strtoul(device.data(), NULL, 10));
		sendStr += name + "A8" + Int32ToHexConvert(1);
		SendMessg(sendStr);
		string strRead = ReceiveMsg();
		if (strRead.length() > 20 && strRead.substr(18, 4) == "0000")
		{
			short va = 0;
			strRead.erase(0, 22);
			string strTemp1 = "";
			string strTemp2 = "";
			strTemp1 = strRead.substr(0, 2);
			strTemp2 = strRead.substr(2, 2);
			strTemp2 += strTemp1;
			va = strtol(strTemp2.data(), NULL, 16);
			return va;
		}
		return 0;
	}
	catch (...)
	{
		return 0;
	}	
}

int MitTcpSocket_Binary::Read2D_Binary(QString key, string device)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		string sendStr = "500000FFFF0300";
		int len = 12;
		string temp = Int32ToHexConvert(len);
		sendStr += temp;
		sendStr += "100001040000";
		string name = Int48ToHexConvert(strtoul(device.data(), NULL, 10));
		sendStr += name + "A8" + Int32ToHexConvert(2);
		SendMessg(sendStr);
		string strRead = ReceiveMsg();
		if (strRead.length() > 20 && strRead.substr(18, 4) == "0000")
		{
			strRead.erase(0, 22);
			string strTemp1 = strRead.substr(0, 8);
			string strTemp2 = strTemp1.substr(6, 2) + strTemp1.substr(4, 2) + strTemp1.substr(2, 2) + strTemp1.substr(0, 2);
			long long va = strtoll(strTemp2.data(), NULL, 16);
			return va;
		}
		return 0;
	}
	catch (...)
	{
		return 0;
	}	
}

bool MitTcpSocket_Binary::ReadM_Binary(QString key, string device)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		bool re = false;
		string sendStr = "500000FFFF0300";
		int len = 12;
		string temp = Int32ToHexConvert(len);
		sendStr += temp;
		string startName = Int48ToHexConvert(strtol(device.data(), NULL, 10));
		sendStr += "100001040100" + startName + "90";
		sendStr += Int32ToHexConvert(1);
		SendMessg(sendStr);
		string strRead = ReceiveMsg();
		if (strRead.length() > 20 && strRead.substr(18, 4) == "0000")
		{
			strRead.erase(0, 22);
			re = strRead.substr(0, 1) == "1";
			return re;
		}
		return re;
	}
	catch (...)
	{
		return false;
	}	
}

bool MitTcpSocket_Binary::WriteM_Binary(QString key, string device, bool value)
{
	if (key != "59226f4700f1cc8a5de755d501af308d2d2")
	{
		return false;
	}
	try
	{
		string sendStr = "500000FFFF0300";
		int len = 13;
		string temp = Int32ToHexConvert(len);
		sendStr += temp;
		string startDev = Int48ToHexConvert(strtol(device.data(), NULL, 10));
		sendStr += "100001140100" + startDev + "90";
		sendStr += Int32ToHexConvert(1);
		sendStr += value ? "10" : "00";
		SendMessg(sendStr);
		string strRead = ReceiveMsg();
		if (strRead.length() > 20 && strRead.substr(18, 4) == "0000")
			return true;
		return false;
	}
	catch (...)
	{
		return false;
	}	
}
#pragma endregion
#pragma endregion
