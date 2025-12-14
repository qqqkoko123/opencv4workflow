#include "QToolBase.h"
#include <QDebug>
#include "datavar.h"
#include "frmProItemTab.h"

QToolBase::QToolBase()
{	
	m_Tools.reserve(100);
	m_FlowSortList.reserve(100);
	m_Tools.clear();
	m_FlowSortList.clear();
}

QToolBase::~QToolBase()
{	
}

bool QToolBase::RunToolFlow_B1(const QString toolname)
{	
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B1 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();					
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B1 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B1();
				}
			}
			if (-1 == nResult)
			{		
				dataVar::fProItemTab->slot_ToolWrong_B1(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B1 = true;
				}		
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B1(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B1();
				}
				return false;
			}
			else
			{						
				dataVar::fProItemTab->slot_ToolRunFinish_B1(toolname);
			}				
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B2(const QString toolname)
{	
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B2 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B2 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B2();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B2(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B2 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B2(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B2();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B2(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B3(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B3 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B3 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B3();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B3(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B3 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B3(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B3();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B3(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B4(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B4 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B4 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B4();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B4(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B4 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B4(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B4();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B4(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B5(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B5 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B5 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B5();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B5(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B5 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B5(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B5();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B5(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B6(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B6 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B6 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B6();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B6(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B6 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B6(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B6();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B6(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B7(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B7 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B7 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B7();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B7(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B7 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B7(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B7();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B7(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B8(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B8 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B8 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B8();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B8(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B8 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B8(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B8();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B8(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B9(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B9 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B9 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B9();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B9(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B9 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B9(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B9();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B9(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B10(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B10 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B10 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B10();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B10(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B10 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B10(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B10();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B10(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B11(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{	
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B11 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B11 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B11();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B11(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B11 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B11(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B11();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B11(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B12(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B12 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B12 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B12();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B12(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B12 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B12(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B12();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B12(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B13(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B13 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B13 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B13();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B13(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B13 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B13(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B13();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B13(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B14(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B14 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B14 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B14();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B14(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B14 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B14(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B14();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B14(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B15(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B15 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B15 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B15();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B15(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B15 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B15(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B15();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B15(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B16(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B16 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B16 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B16();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B16(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B16 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B16(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B16();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B16(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B17(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B17 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B17 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B17();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B17(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B17 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B17(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B17();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B17(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B18(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B18 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B18 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B18();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B18(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B18 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B18(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B18();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B18(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B19(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B19 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B19 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B19();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B19(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B19 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B19(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B19();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B19(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolFlow_B20(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			//耗时计算
			clock_t startTime, endTime;
			startTime = clock();
			nResult = m_Tools[i].PublicToolDlg->Execute(toolname);
			endTime = clock();
			//流程运行时间
			dataVar::nCostTime_B20 = endTime - startTime;
			if (dataVar::m_a_state == 1)
			{
				if (dataVar::stopThread_A == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
			}
			else if (dataVar::m_a_state == 2)
			{
				if (dataVar::stopThread_B20 == 1)
				{
					dataVar::fProItemTab->Stop_Thread_B20();
				}
			}
			if (-1 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B20(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::runFinish_A = true;
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::runFinish_B20 = true;
				}
				//报错继续流转
				//return false;
			}
			else if (-2 == nResult)
			{
				dataVar::fProItemTab->slot_ToolWrong_B20(toolname);
				if (dataVar::m_a_state == 1)
				{
					dataVar::fProItemTab->Stop_Thread_A();
				}
				else if (dataVar::m_a_state == 2)
				{
					dataVar::fProItemTab->Stop_Thread_B20();
				}
				return false;
			}
			else
			{
				dataVar::fProItemTab->slot_ToolRunFinish_B20(toolname);
			}			
			break;
		}
	}
	return true;
}

bool QToolBase::RunToolLink(const QString toolname, const int int_link, const QString str_link)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			nResult = m_Tools[i].PublicToolDlg->ExecuteLink(int_link, str_link, gVariable::global_variable_link);
			if (-1 == nResult)
			{
				return false;
			}
			break;
		}
	}	
	return true;
}

bool QToolBase::RunAllToolLink()
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{
		nResult = m_Tools[i].PublicToolDlg->ExecuteAllLink(gVariable::global_variable_link);		
	}
	return true;
}

bool QToolBase::RunGotoToolLink()
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{
		//提取不含数字字符串
		int str_count = 0;
		for (int k = 0; k < m_Tools[i].PublicToolName.length(); k++)
		{
			if (!(m_Tools[i].PublicToolName[k] > '0' && m_Tools[i].PublicToolName[k] < '9'))
			{
				++str_count;
			}
		}
		QString str_name_buf = m_Tools[i].PublicToolName.mid(0, str_count);		
		if (str_name_buf == "跳转语句")
		{
			nResult = m_Tools[i].PublicToolDlg->ExecuteGotoLink(gVariable::goto_variable_link);
		}			
	}
	return true;
}

bool QToolBase::RunCommunicationLink(const QString toolname)
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{
		//提取不含数字字符串
		int str_count = 0;
		for (int k = 0; k < m_Tools[i].PublicToolName.length(); k++)
		{
			if (!(m_Tools[i].PublicToolName[k] > '0' && m_Tools[i].PublicToolName[k] < '9'))
			{
				++str_count;
			}
		}
		QString str_name_buf = m_Tools[i].PublicToolName.mid(0, str_count);
		if (str_name_buf == "获取图像" || toolname == "通讯工具") // || str_name_buf == "YoloV13" || str_name_buf == "OCR"
		{
			nResult = m_Tools[i].PublicToolDlg->ExecuteCameraLink(gVariable::camera_variable_link);
		}
		if (str_name_buf == "通用I/O" || toolname == "通讯工具")
		{
			nResult = m_Tools[i].PublicToolDlg->ExecuteGeneralIoLink(gVariable::generalio_variable_link);
		}
		if (str_name_buf == "PLC通信" || toolname == "通讯工具")
		{
			nResult = m_Tools[i].PublicToolDlg->ExecutePlcCommunicateLink(gVariable::plccommunicate_variable_link);
		}
		if (str_name_buf == "串口通信" || toolname == "通讯工具")
		{
			nResult = m_Tools[i].PublicToolDlg->ExecuteSerialPortLink(gVariable::serialport_variable_link);
		}
		if (str_name_buf == "TCP/IP服务器" || toolname == "通讯工具")
		{
			nResult = m_Tools[i].PublicToolDlg->ExecuteSocketTcpServerLink(gVariable::sockettcpserver_variable_link);
		}
		if (str_name_buf == "TCP/IP客户端" || toolname == "通讯工具")
		{
			nResult = m_Tools[i].PublicToolDlg->ExecuteSocketTcpClientLink(gVariable::sockettcpclient_variable_link);
		}
	}
	return true;
}

bool QToolBase::RunScriptEditToolLink()
{
	int nResult = -10000;
	for (int i = 0; i < m_Tools.size(); i++)
	{
		nResult = m_Tools[i].PublicToolDlg->ExecuteScriptEditLink(gVariable::scriptedit_variable_link);		
	}
	return true;
}

bool QToolBase::AddTool(const QString toolname)
{	
	for (int i = 0; i < m_Tools.size(); i++)
	{
		if (m_Tools[i].PublicToolName == toolname)
		{
			return false;
		}
	}
	VisionTOOL tool;
	tool.PublicToolName = toolname;
	m_Tools.push_back(tool);
	return true;
}

bool QToolBase::AddToolInfo(const QString toolname, const VisionToolINFO toolinfo)
{
	for (int i = 0; i < m_Tools.size(); i++)
	{
		if (m_Tools[i].PublicToolName == toolname)
		{
			m_Tools[i].PublicInfo = toolinfo;
		}
	}
	return true;
}

bool QToolBase::AddToolDlg(const QString toolname, Toolnterface* toolDlg)
{
	for (int i = 0; i < m_Tools.size(); i++)
	{
		if (m_Tools[i].PublicToolName == toolname)
		{
			m_Tools[i].PublicToolDlg = toolDlg;
			return true;
		}
	}
	return false;
}

bool QToolBase::GetToolDlg(const QString toolname)
{	
	for (int i = 0; i < m_Tools.size(); i++)
	{		
		if (m_Tools[i].PublicToolName == toolname)
		{
			m_Tools[i].PublicToolDlg->accept();
			m_Tools[i].PublicToolDlg->exec();			
			return true;
		}
	}
	return false;
}
