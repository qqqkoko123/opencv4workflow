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

	//��������PLC��
	bool Connect(QString key, QString ip = "192.168.3.39", int port = 8192);
	//�Ͽ�����PLC��
	void Disconnect(QString key);
	//д��16λ�Ĵ�����
	bool Write1D(QString key, QString device, short value);
	//д��32λ�Ĵ�����
	bool Write2D(QString key, QString device, int value);
	//��ȡ16λ�Ĵ�����
	bool Read1D(QString key, QString device, short& value);
	//��ȡ32λ�Ĵ�����
	bool Read2D(QString key, QString device, int& value);
	//��λ�����̵���M��
	bool SetM(QString key, QString device);
	//��λ�����̵���M��
	bool RstM(QString key, QString device);
	//��λ����̵���L��
	bool SetL(QString key, QString device);
	//��λ����̵���L��
	bool RstL(QString key, QString device);

private:
	//˫��ת�������֣�
	void DWordToSWord(int int32Num, int &int16Num_L, int &int16Num_H);
	//��������ת˫�֣�
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
