#include "autoThread.h"
#include <QThread>
#include "datavar.h"

#pragma region 流程1线程
autoThread_B1::autoThread_B1(QObject *parent) : QObject(parent)
{
	isStop_B1 = false;	
}

void autoThread_B1::funThread_B1()
{
	while (true)
	{
		try
		{
			if (isStop_B1 == true)
			{
				break;
			}			
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B1 == true)
				{
					dataVar::runFinish_B1 = false;							
					dataVar::fProItemTab->ProgramAutoFlow_B1();									
				}				
			}
		}
		catch(...){}		
	}	
}

//停止线程标志
void autoThread_B1::setStopFlag_B1(bool flag)
{
	isStop_B1 = flag;
}
#pragma endregion

#pragma region 流程2线程
autoThread_B2::autoThread_B2(QObject* parent) : QObject(parent)
{
	isStop_B2 = false;	
}

void autoThread_B2::funThread_B2()
{
	while (true)
	{
		try
		{
			if (isStop_B2 == true)
			{
				break;
			}			
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B2 == true)
				{
					dataVar::runFinish_B2 = false;					
					dataVar::fProItemTab->ProgramAutoFlow_B2();					
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B2::setStopFlag_B2(bool flag)
{
	isStop_B2 = flag;
}
#pragma endregion

#pragma region 流程3线程
autoThread_B3::autoThread_B3(QObject* parent) : QObject(parent)
{
	isStop_B3 = false;	
}

void autoThread_B3::funThread_B3()
{
	while (true)
	{
		try
		{
			if (isStop_B3 == true)
			{
				break;
			}			
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B3 == true)
				{
					dataVar::runFinish_B3 = false;					
					dataVar::fProItemTab->ProgramAutoFlow_B3();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B3::setStopFlag_B3(bool flag)
{
	isStop_B3 = flag;
}
#pragma endregion

#pragma region 流程4线程
autoThread_B4::autoThread_B4(QObject* parent) : QObject(parent)
{
	isStop_B4 = false;	
}

void autoThread_B4::funThread_B4()
{
	while (true)
	{
		try
		{
			if (isStop_B4 == true)
			{
				break;
			}			
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B4 == true)
				{
					dataVar::runFinish_B4 = false;					
					dataVar::fProItemTab->ProgramAutoFlow_B4();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B4::setStopFlag_B4(bool flag)
{
	isStop_B4 = flag;
}
#pragma endregion

#pragma region 流程5线程
autoThread_B5::autoThread_B5(QObject* parent) : QObject(parent)
{
	isStop_B5 = false;	
}

void autoThread_B5::funThread_B5()
{
	while (true)
	{
		try
		{
			if (isStop_B5 == true)
			{
				break;
			}			
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B5 == true)
				{
					dataVar::runFinish_B5 = false;					
					dataVar::fProItemTab->ProgramAutoFlow_B5();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B5::setStopFlag_B5(bool flag)
{
	isStop_B5 = flag;
}
#pragma endregion

#pragma region 流程6线程
autoThread_B6::autoThread_B6(QObject* parent) : QObject(parent)
{
	isStop_B6 = false;	
}

void autoThread_B6::funThread_B6()
{
	while (true)
	{
		try
		{
			if (isStop_B6 == true)
			{
				break;
			}			
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B6 == true)
				{
					dataVar::runFinish_B6 = false;					
					dataVar::fProItemTab->ProgramAutoFlow_B6();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B6::setStopFlag_B6(bool flag)
{
	isStop_B6 = flag;
}
#pragma endregion

#pragma region 流程7线程
autoThread_B7::autoThread_B7(QObject* parent) : QObject(parent)
{
	isStop_B7 = false;	
}

void autoThread_B7::funThread_B7()
{
	while (true)
	{
		try
		{
			if (isStop_B7 == true)
			{
				break;
			}			
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B7 == true)
				{
					dataVar::runFinish_B7 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B7();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B7::setStopFlag_B7(bool flag)
{
	isStop_B7 = flag;
}
#pragma endregion

#pragma region 流程8线程
autoThread_B8::autoThread_B8(QObject* parent) : QObject(parent)
{
	isStop_B8 = false;	
}

void autoThread_B8::funThread_B8()
{
	while (true)
	{
		try
		{
			if (isStop_B8 == true)
			{
				break;
			}			
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B8 == true)
				{
					dataVar::runFinish_B8 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B8();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B8::setStopFlag_B8(bool flag)
{
	isStop_B8 = flag;
}
#pragma endregion

#pragma region 流程9线程
autoThread_B9::autoThread_B9(QObject* parent) : QObject(parent)
{
	isStop_B9 = false;	
}

void autoThread_B9::funThread_B9()
{
	while (true)
	{
		try
		{
			if (isStop_B9 == true)
			{
				break;
			}			
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B9 == true)
				{
					dataVar::runFinish_B9 = false;					
					dataVar::fProItemTab->ProgramAutoFlow_B9(); 
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B9::setStopFlag_B9(bool flag)
{
	isStop_B9 = flag;
}
#pragma endregion

#pragma region 流程10线程
autoThread_B10::autoThread_B10(QObject* parent) : QObject(parent)
{
	isStop_B10 = false;
}

void autoThread_B10::funThread_B10()
{
	while (true)
	{
		try
		{
			if (isStop_B10 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B10 == true)
				{
					dataVar::runFinish_B10 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B10();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B10::setStopFlag_B10(bool flag)
{
	isStop_B10 = flag;
}
#pragma endregion

#pragma region 流程11线程
autoThread_B11::autoThread_B11(QObject* parent) : QObject(parent)
{
	isStop_B11 = false;
}

void autoThread_B11::funThread_B11()
{
	while (true)
	{
		try
		{
			if (isStop_B11 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B11 == true)
				{
					dataVar::runFinish_B11 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B11();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B11::setStopFlag_B11(bool flag)
{
	isStop_B11 = flag;
}
#pragma endregion

#pragma region 流程12线程
autoThread_B12::autoThread_B12(QObject* parent) : QObject(parent)
{
	isStop_B12 = false;
}

void autoThread_B12::funThread_B12()
{
	while (true)
	{
		try
		{
			if (isStop_B12 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B12 == true)
				{
					dataVar::runFinish_B12 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B12();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B12::setStopFlag_B12(bool flag)
{
	isStop_B12 = flag;
}
#pragma endregion

#pragma region 流程13线程
autoThread_B13::autoThread_B13(QObject* parent) : QObject(parent)
{
	isStop_B13 = false;
}

void autoThread_B13::funThread_B13()
{
	while (true)
	{
		try
		{
			if (isStop_B13 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B13 == true)
				{
					dataVar::runFinish_B13 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B13();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B13::setStopFlag_B13(bool flag)
{
	isStop_B13 = flag;
}
#pragma endregion

#pragma region 流程14线程
autoThread_B14::autoThread_B14(QObject* parent) : QObject(parent)
{
	isStop_B14 = false;
}

void autoThread_B14::funThread_B14()
{
	while (true)
	{
		try
		{
			if (isStop_B14 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B14 == true)
				{
					dataVar::runFinish_B14 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B14();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B14::setStopFlag_B14(bool flag)
{
	isStop_B14 = flag;
}
#pragma endregion

#pragma region 流程15线程
autoThread_B15::autoThread_B15(QObject* parent) : QObject(parent)
{
	isStop_B15 = false;
}

void autoThread_B15::funThread_B15()
{
	while (true)
	{
		try
		{
			if (isStop_B15 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B15 == true)
				{
					dataVar::runFinish_B15 = false;			
					dataVar::fProItemTab->ProgramAutoFlow_B15();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B15::setStopFlag_B15(bool flag)
{
	isStop_B15 = flag;
}
#pragma endregion

#pragma region 流程16线程
autoThread_B16::autoThread_B16(QObject* parent) : QObject(parent)
{
	isStop_B16 = false;
}

void autoThread_B16::funThread_B16()
{
	while (true)
	{
		try
		{
			if (isStop_B16 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B16 == true)
				{
					dataVar::runFinish_B16 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B16();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B16::setStopFlag_B16(bool flag)
{
	isStop_B16 = flag;
}
#pragma endregion

#pragma region 流程17线程
autoThread_B17::autoThread_B17(QObject* parent) : QObject(parent)
{
	isStop_B17 = false;
}

void autoThread_B17::funThread_B17()
{
	while (true)
	{
		try
		{
			if (isStop_B17 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B17 == true)
				{
					dataVar::runFinish_B17 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B17();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B17::setStopFlag_B17(bool flag)
{
	isStop_B17 = flag;
}
#pragma endregion

#pragma region 流程18线程
autoThread_B18::autoThread_B18(QObject* parent) : QObject(parent)
{
	isStop_B18 = false;
}

void autoThread_B18::funThread_B18()
{
	while (true)
	{
		try
		{
			if (isStop_B18 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B18 == true)
				{
					dataVar::runFinish_B18 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B18();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B18::setStopFlag_B18(bool flag)
{
	isStop_B18 = flag;
}
#pragma endregion

#pragma region 流程19线程
autoThread_B19::autoThread_B19(QObject* parent) : QObject(parent)
{
	isStop_B19 = false;
}

void autoThread_B19::funThread_B19()
{
	while (true)
	{
		try
		{
			if (isStop_B19 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B19 == true)
				{
					dataVar::runFinish_B19 = false;				
					dataVar::fProItemTab->ProgramAutoFlow_B19();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B19::setStopFlag_B19(bool flag)
{
	isStop_B19 = flag;
}
#pragma endregion

#pragma region 流程20线程
autoThread_B20::autoThread_B20(QObject* parent) : QObject(parent)
{
	isStop_B20 = false;
}

void autoThread_B20::funThread_B20()
{
	while (true)
	{
		try
		{
			if (isStop_B20 == true)
			{
				break;
			}
			else
			{
				//防止线程占用大量CPU性能              
				QThread::usleep(100);
				if (dataVar::runFinish_B20 == true)
				{
					dataVar::runFinish_B20 = false;					
					dataVar::fProItemTab->ProgramAutoFlow_B20();
				}
			}
		}
		catch (...) {}
	}
}

//停止线程标志
void autoThread_B20::setStopFlag_B20(bool flag)
{
	isStop_B20 = flag;
}
#pragma endregion