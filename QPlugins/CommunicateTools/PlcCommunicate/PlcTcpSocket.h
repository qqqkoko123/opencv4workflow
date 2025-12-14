#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <QtWidgets/QWidget>
#include <sstream>
#include <winsock2.h>
#include <QMutex>
#include <QString>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include <vector>
using namespace std;

#pragma region MitTcpSocket
#pragma region ASCII
class MitTcpSocket : public QWidget
{
public:
	MitTcpSocket(void);
	~MitTcpSocket(void);

	//连接三菱PLC；
	bool Connect(QString key, QString ip = "192.168.3.39", int port = 8192);
	//断开三菱PLC；
	void Disconnect(QString key);
	//写入16位寄存器；
	bool Write1D(QString key, QString device, short value);
	//写入32位寄存器；
	bool Write2D(QString key, QString device, int value);
	//读取16位寄存器；
	bool Read1D(QString key, QString device, short& value);
	//读取32位寄存器；
	bool Read2D(QString key, QString device, int& value);
	//置位辅助继电器M；
	bool SetM(QString key, QString device);
	//复位辅助继电器M；
	bool RstM(QString key, QString device);
	//置位锁存继电器L；
	bool SetL(QString key, QString device);
	//复位锁存继电器L；
	bool RstL(QString key, QString device);

private:
	//双字转两个单字；
	void DWordToSWord(int int32Num, int &int16Num_L, int &int16Num_H);
	//两个单字转双字；
	void SWordToDWord(int int16Num_L, int int16Num_H, int &int32Num);

private:
	QTcpSocket m_socket;
	bool m_connected;
};
#pragma endregion

#pragma region Binary
class MitTcpSocket_Binary : public QWidget
{
public:
	MitTcpSocket_Binary(void);
	~MitTcpSocket_Binary(void);

	bool Connect_Binary(QString key, string ip = "192.168.3.39", int port = 8192);
	void Disconnect_Binary(QString key);
	bool Write1D_Binary(QString key, string device, short value);
	bool Write2D_Binary(QString key, string device, INT32 value);
	short Read1D_Binary(QString key, string device);
	int Read2D_Binary(QString key, string device);
	bool ReadM_Binary(QString key, string device);
	bool WriteM_Binary(QString key, string device, bool value);

private:
	string Int16ToHexConvert(short value);
	string Int32ToHexConvert(INT32 value);
	string Int48ToHexConvert(INT64 value);
	string Int64ToHexConvert(INT64 value);
	string Int32ToHexConvert2(INT32 value);
	bool SendMessg(string msg);
	string ReceiveMsg();
	string& std_string_format(string& _str, const char * _Fromat, ...);

private:
	SOCKET m_socket;
	bool m_connected;
	QMutex mutex;
};
#pragma endregion
#pragma endregion
