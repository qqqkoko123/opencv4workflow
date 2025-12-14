#pragma once

#include <QObject>

#pragma region 流程1线程
class autoThread_B1 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B1(QObject *parent = nullptr);
	//线程处理函数
	void funThread_B1();
	//设置线程中标志,用于停止线程
	void setStopFlag_B1(bool flag = true); 	

private:
	//线程工作标志
	bool isStop_B1; 	
};
#pragma endregion

#pragma region 流程2线程
class autoThread_B2 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B2(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B2();
	//设置线程中标志,用于停止线程
	void setStopFlag_B2(bool flag = true);	

private:
	//线程工作标志
	bool isStop_B2;	
};
#pragma endregion

#pragma region 流程3线程
class autoThread_B3 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B3(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B3();
	//设置线程中标志,用于停止线程
	void setStopFlag_B3(bool flag = true);	

private:
	//线程工作标志
	bool isStop_B3;	
};
#pragma endregion

#pragma region 流程4线程
class autoThread_B4 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B4(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B4();
	//设置线程中标志,用于停止线程
	void setStopFlag_B4(bool flag = true);	

private:
	//线程工作标志
	bool isStop_B4;	
};
#pragma endregion

#pragma region 流程5线程
class autoThread_B5 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B5(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B5();
	//设置线程中标志,用于停止线程
	void setStopFlag_B5(bool flag = true);	

private:
	//线程工作标志
	bool isStop_B5;	
};
#pragma endregion

#pragma region 流程6线程
class autoThread_B6 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B6(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B6();
	//设置线程中标志,用于停止线程
	void setStopFlag_B6(bool flag = true);	

private:
	//线程工作标志
	bool isStop_B6;	
};
#pragma endregion

#pragma region 流程7线程
class autoThread_B7 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B7(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B7();
	//设置线程中标志,用于停止线程
	void setStopFlag_B7(bool flag = true);	

private:
	//线程工作标志
	bool isStop_B7;	
};
#pragma endregion

#pragma region 流程8线程
class autoThread_B8 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B8(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B8();
	//设置线程中标志,用于停止线程
	void setStopFlag_B8(bool flag = true);	

private:
	//线程工作标志
	bool isStop_B8;
};
#pragma endregion

#pragma region 流程9线程
class autoThread_B9 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B9(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B9();
	//设置线程中标志,用于停止线程
	void setStopFlag_B9(bool flag = true);	

private:
	//线程工作标志
	bool isStop_B9;	
};
#pragma endregion

#pragma region 流程10线程
class autoThread_B10 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B10(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B10();
	//设置线程中标志,用于停止线程
	void setStopFlag_B10(bool flag = true);

private:
	//线程工作标志
	bool isStop_B10;
};
#pragma endregion

#pragma region 流程11线程
class autoThread_B11 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B11(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B11();
	//设置线程中标志,用于停止线程
	void setStopFlag_B11(bool flag = true);

private:
	//线程工作标志
	bool isStop_B11;
};
#pragma endregion

#pragma region 流程12线程
class autoThread_B12 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B12(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B12();
	//设置线程中标志,用于停止线程
	void setStopFlag_B12(bool flag = true);

private:
	//线程工作标志
	bool isStop_B12;
};
#pragma endregion

#pragma region 流程13线程
class autoThread_B13 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B13(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B13();
	//设置线程中标志,用于停止线程
	void setStopFlag_B13(bool flag = true);

private:
	//线程工作标志
	bool isStop_B13;
};
#pragma endregion

#pragma region 流程14线程
class autoThread_B14 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B14(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B14();
	//设置线程中标志,用于停止线程
	void setStopFlag_B14(bool flag = true);

private:
	//线程工作标志
	bool isStop_B14;
};
#pragma endregion

#pragma region 流程15线程
class autoThread_B15 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B15(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B15();
	//设置线程中标志,用于停止线程
	void setStopFlag_B15(bool flag = true);

private:
	//线程工作标志
	bool isStop_B15;
};
#pragma endregion

#pragma region 流程16线程
class autoThread_B16 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B16(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B16();
	//设置线程中标志,用于停止线程
	void setStopFlag_B16(bool flag = true);

private:
	//线程工作标志
	bool isStop_B16;
};
#pragma endregion

#pragma region 流程17线程
class autoThread_B17 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B17(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B17();
	//设置线程中标志,用于停止线程
	void setStopFlag_B17(bool flag = true);

private:
	//线程工作标志
	bool isStop_B17;
};
#pragma endregion

#pragma region 流程18线程
class autoThread_B18 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B18(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B18();
	//设置线程中标志,用于停止线程
	void setStopFlag_B18(bool flag = true);

private:
	//线程工作标志
	bool isStop_B18;
};
#pragma endregion

#pragma region 流程19线程
class autoThread_B19 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B19(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B19();
	//设置线程中标志,用于停止线程
	void setStopFlag_B19(bool flag = true);

private:
	//线程工作标志
	bool isStop_B19;
};
#pragma endregion

#pragma region 流程20线程
class autoThread_B20 : public QObject
{
	Q_OBJECT

public:
	explicit autoThread_B20(QObject* parent = nullptr);
	//线程处理函数
	void funThread_B20();
	//设置线程中标志,用于停止线程
	void setStopFlag_B20(bool flag = true);

private:
	//线程工作标志
	bool isStop_B20;
};
#pragma endregion