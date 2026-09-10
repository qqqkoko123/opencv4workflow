#include "showcpumemory.h"
#include <QThread>
#include <QProcess>
#include <QLabel>
#include "datavar.h"

#define MB (1024 * 1024)
#define KB (1024)

ShowCpuMemory::ShowCpuMemory(QObject *parent) : QObject(parent)
{  
    memoryPercent = 0;
    memoryAll = 0;
    memoryUse = 0;
    labMemory = 0;    	
}

void ShowCpuMemory::SetLab(QLabel *labMemory)
{	
    this->labMemory = labMemory;	
	this->labMemory->setObjectName("CPU");
}

void ShowCpuMemory::GetCpuMemory()
{
	while (true)
	{		
		cpu = calCpuUsage();
		MEMORYSTATUSEX statex;
		statex.dwLength = sizeof(statex);
		GlobalMemoryStatusEx(&statex);
		memoryPercent = statex.dwMemoryLoad;
		memoryAll = statex.ullTotalPhys / MB;
		memoryFree = statex.ullAvailPhys / MB;
		memoryUse = memoryAll - memoryFree;
		QString msg = QString("CPU使用率: %1% | 内存使用率: %2%(已用 %3 MB/共 %4 MB) | ")
			.arg(cpu).arg(memoryPercent).arg(memoryUse).arg(memoryAll);
		labMemory->setText(msg);		
	}	
}

int ShowCpuMemory::calCpuUsage()
{
	HANDLE hEvent;
	bool res;
	static FILETIME preIdleTime;
	static FILETIME preKernelTime;
	static FILETIME preUserTime;
	FILETIME idleTime;
	FILETIME kernelTime;
	FILETIME userTime;
	res = GetSystemTimes(&idleTime, &kernelTime, &userTime);
	preIdleTime = idleTime;
	preKernelTime = kernelTime;
	preUserTime = userTime;
	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	WaitForSingleObject(hEvent, 1000);	//等待1000毫秒
	res = GetSystemTimes(&idleTime, &kernelTime, &userTime);
	long long idle = CompareFileTime(preIdleTime, idleTime);
	long long kernel = CompareFileTime(preKernelTime, kernelTime);
	long long user = CompareFileTime(preUserTime, userTime);
	auto nCpuRate = (int)ceil(100.0 * (kernel + user - idle) / (kernel + user));	
	return nCpuRate;
}

//时间转换
__int64 ShowCpuMemory::Filetime2Int64(const FILETIME* ftime)
{
	LARGE_INTEGER li;
	li.LowPart = ftime->dwLowDateTime;
	li.HighPart = ftime->dwHighDateTime;
	return li.QuadPart;
}

//两个时间相减运算
__int64 ShowCpuMemory::CompareFileTime(FILETIME preTime, FILETIME nowTime)
{
	return Filetime2Int64(&nowTime) - Filetime2Int64(&preTime);
}
