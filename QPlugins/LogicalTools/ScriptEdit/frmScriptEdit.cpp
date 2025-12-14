#include "frmScriptEdit.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPainter>
#include <QStyleFactory>
#include <QHeaderView>
#include <QGraphicsOpacityEffect>
#include "qmutex.h"

QScriptValue ConvertToPoint(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 2)
		{
			QConfig::tool_result = -2;
			QString error = "ConvertToPoint输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		QPoint p = q_var.toPoint();
		if (context->argument(1).toString() == "x")
		{
			return p.x();
		}
		else if (context->argument(1).toString() == "y")
		{
			return p.y();
		}
		QConfig::tool_result = -2;
		QString error = "ConvertToPoint获取的参数只能输入\"x\"和\"y\"！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ConvertToPoint输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ConvertToPoint2f(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 2)
		{
			QConfig::tool_result = -2;
			QString error = "ConvertToPoint2f输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		QPointF p = q_var.toPointF();
		if (context->argument(1).toString() == "x")
		{
			return p.x();
		}
		else if (context->argument(1).toString() == "y")
		{
			return p.y();
		}
		QConfig::tool_result = -2;
		QString error = "ConvertToPoint2f获取的参数只能输入\"x\"和\"y\"！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ConvertToPoint2f输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ConvertToPoint3f(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 2)
		{
			QConfig::tool_result = -2;
			QString error = "ConvertToPoint3f输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		if (q_var.userType() == qMetaTypeId<Point3f>())
		{
			Point3f p3f = q_var.value<Point3f>();
			if (context->argument(1).toString() == "x")
			{
				return p3f.x;
			}
			else if (context->argument(1).toString() == "y")
			{
				return p3f.y;
			}
			else if (context->argument(1).toString() == "z")
			{
				return p3f.z;
			}
		}
		QConfig::tool_result = -2;
		QString error = "ConvertToPoint3f获取的参数只能输入\"x\"、\"y\"和\"z\"！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ConvertToPoint3f输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ConvertToPoint3d(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 2)
		{
			QConfig::tool_result = -2;
			QString error = "ConvertToPoint3d输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		if (q_var.userType() == qMetaTypeId<Point3d>())
		{
			Point3d p3d = q_var.value<Point3d>();
			if (context->argument(1).toString() == "x")
			{
				return p3d.x;
			}
			else if (context->argument(1).toString() == "y")
			{
				return p3d.y;
			}
			else if (context->argument(1).toString() == "z")
			{
				return p3d.z;
			}
		}
		QConfig::tool_result = -2;
		QString error = "ConvertToPoint3d获取的参数只能输入\"x\"、\"y\"和\"z\"！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ConvertToPoint3d输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ConvertToArrayFloat(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 2)
		{
			QConfig::tool_result = -2;
			QString error = "ConvertToArrayFloat输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		if (q_var.userType() == qMetaTypeId<ArrayFloat>())
		{
			ArrayFloat array_float = q_var.value<ArrayFloat>();
			int count = array_float.g_array_f.size();
			if (count != 0)
			{
				if (context->argument(1).toInt32() < count)
				{
					return array_float.g_array_f[context->argument(1).toInt32()];
				}
			}
		}
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayFloat索引超出数组范围或输入参数错误！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayFloat输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ConvertToArrayDouble(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 2)
		{
			QConfig::tool_result = -2;
			QString error = "ConvertToArrayDouble输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		if (q_var.userType() == qMetaTypeId<ArrayDouble>())
		{
			ArrayDouble array_double = q_var.value<ArrayDouble>();
			int count = array_double.g_array_d.size();
			if (count != 0)
			{
				if (context->argument(1).toInt32() < count)
				{
					return array_double.g_array_d[context->argument(1).toInt32()];
				}
			}
		}
		else if (q_var.userType() == qMetaTypeId<ToolArrayDouble>())
		{
			ToolArrayDouble array_d = q_var.value<ToolArrayDouble>();
			int count = array_d.t_array_d.size();
			if (count != 0)
			{
				if (context->argument(1).toInt32() < count)
				{
					return array_d.t_array_d[context->argument(1).toInt32()];
				}
			}
		}
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayDouble索引超出数组范围或输入参数错误！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayDouble输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ConvertToArrayQString(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 2)
		{
			QConfig::tool_result = -2;
			QString error = "ConvertToArrayQString输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		if (q_var.userType() == qMetaTypeId<ArrayQString>())
		{
			ArrayQString array_qstring = q_var.value<ArrayQString>();
			int count = array_qstring.t_array_string.size();
			if (count != 0)
			{
				if (context->argument(1).toInt32() < count)
				{
					return array_qstring.t_array_string[context->argument(1).toInt32()];
				}
			}
		}
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayQString索引超出数组范围或输入参数错误！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayQString输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ConvertToArrayCvPoint2f(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 3)
		{
			QConfig::tool_result = -2;
			QString error = "ConvertToArrayCvPoint2f输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		if (q_var.userType() == qMetaTypeId<ArrayCvPoint2f>())
		{
			ArrayCvPoint2f array_cpoints = q_var.value<ArrayCvPoint2f>();
			int count = array_cpoints.t_array_points.size();
			if (count != 0)
			{
				if (context->argument(1).toInt32() < count)
				{
					if (context->argument(2).toString() == "x")
					{
						return array_cpoints.t_array_points[context->argument(1).toInt32()].x;
					}
					else if (context->argument(2).toString() == "y")
					{
						return array_cpoints.t_array_points[context->argument(1).toInt32()].y;
					}
				}
			}
		}
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayCvPoint2f索引超出数组范围或输入参数错误！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayCvPoint2f输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ConvertToArrayInt(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 2)
		{
			QConfig::tool_result = -2;
			QString error = "ConvertToArrayInt输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		if (q_var.userType() == qMetaTypeId<ArrayInt>())
		{
			ArrayInt array_int = q_var.value<ArrayInt>();
			int count = array_int.t_array_int.size();
			if (count != 0)
			{
				if (context->argument(1).toInt32() < count)
				{
					return array_int.t_array_int[context->argument(1).toInt32()];
				}
			}
		}
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayInt索引超出数组范围或输入参数错误！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayInt输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ConvertToArrayBool(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 2)
		{
			QConfig::tool_result = -2;
			QString error = "ConvertToArrayBool输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		if (q_var.userType() == qMetaTypeId<ArrayBool>())
		{
			ArrayBool array_bool = q_var.value<ArrayBool>();
			int count = array_bool.t_array_bool.size();
			if (count != 0)
			{
				if (context->argument(1).toInt32() < count)
				{
					return array_bool.t_array_bool[context->argument(1).toInt32()];
				}
			}
		}
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayBool索引超出数组范围或输入参数错误！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ConvertToArrayBool输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue GetArraySize(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 1)
		{
			QConfig::tool_result = -2;
			QString error = "ArraySize输入参数错误！";
			context->throwError(error);
			return error;
		}
		QVariant q_var = context->argument(0).toVariant();
		if (q_var.userType() == qMetaTypeId<ArrayFloat>())
		{
			ArrayFloat array_float = q_var.value<ArrayFloat>();
			int count = array_float.g_array_f.size();
			return count;
		}
		else if (q_var.userType() == qMetaTypeId<ArrayDouble>())
		{
			ArrayDouble array_double = q_var.value<ArrayDouble>();
			int count = array_double.g_array_d.size();
			return count;
		}
		else if (q_var.userType() == qMetaTypeId<ArrayQString>())
		{
			ArrayQString array_qstring = q_var.value<ArrayQString>();
			int count = array_qstring.t_array_string.size();
			return count;
		}
		else if (q_var.userType() == qMetaTypeId<ToolArrayDouble>())
		{
			ToolArrayDouble array_d = q_var.value<ToolArrayDouble>();
			int count = array_d.t_array_d.size();
			return count;
		}
		else if (q_var.userType() == qMetaTypeId<ArrayCvPoint2f>())
		{
			ArrayCvPoint2f array_cpoints = q_var.value<ArrayCvPoint2f>();
			int count = array_cpoints.t_array_points.size();
			return count;
		}
		else if (q_var.userType() == qMetaTypeId<ArrayInt>())
		{
			ArrayInt array_int = q_var.value<ArrayInt>();
			int count = array_int.t_array_int.size();
			return count;
		}
		else if (q_var.userType() == qMetaTypeId<ArrayBool>())
		{
			ArrayBool array_bool = q_var.value<ArrayBool>();
			int count = array_bool.t_array_bool.size();
			return count;
		}
		QConfig::tool_result = -2;
		QString error = "ArraySize输入参数错误！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ArraySize输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue LogInfo(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 1)
		{
			QConfig::tool_result = -2;
			QString error = "LogInfo输入参数错误！";
			context->throwError(error);		
			return error;
		}
		QToolBase* flowToolBase = nullptr;	
		switch (QConfig::g_flow_index) {
		case 0:
			flowToolBase = QConfig::flowToolBase_B1;
			break;
		case 1:
			flowToolBase = QConfig::flowToolBase_B2;
			break;
		case 2:
			flowToolBase = QConfig::flowToolBase_B3;
			break;
		case 3:
			flowToolBase = QConfig::flowToolBase_B4;
			break;
		case 4:
			flowToolBase = QConfig::flowToolBase_B5;
			break;
		case 5:
			flowToolBase = QConfig::flowToolBase_B6;
			break;
		case 6:
			flowToolBase = QConfig::flowToolBase_B7;
			break;
		case 7:
			flowToolBase = QConfig::flowToolBase_B8;
			break;
		case 8:
			flowToolBase = QConfig::flowToolBase_B9;
			break;
		case 9:
			flowToolBase = QConfig::flowToolBase_B10;
			break;
		case 10:
			flowToolBase = QConfig::flowToolBase_B11;
			break;
		case 11:
			flowToolBase = QConfig::flowToolBase_B12;
			break;
		case 12:
			flowToolBase = QConfig::flowToolBase_B13;
			break;
		case 13:
			flowToolBase = QConfig::flowToolBase_B14;
			break;
		case 14:
			flowToolBase = QConfig::flowToolBase_B15;
			break;
		case 15:
			flowToolBase = QConfig::flowToolBase_B16;
			break;
		case 16:
			flowToolBase = QConfig::flowToolBase_B17;
			break;
		case 17:
			flowToolBase = QConfig::flowToolBase_B18;
			break;
		case 18:
			flowToolBase = QConfig::flowToolBase_B19;
			break;
		case 19:
			flowToolBase = QConfig::flowToolBase_B20;
			break;
		}
		if (flowToolBase == nullptr)
		{
			QConfig::tool_result = -2;
			QString error = "QToolBase指针为空！";
			context->throwError(error);
			return -2;
		}
		else
		{
			emit flowToolBase->sig_Info(context->argument(0).toString());
		}		
		return context->argument(0).toString();
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "LogInfo输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue LogWarn(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 1)
		{
			QConfig::tool_result = -2;
			QString error = "LogWarn输入参数错误！";
			context->throwError(error);
			return error;
		}
		QToolBase* flowToolBase = nullptr;		
		switch (QConfig::g_flow_index) {
		case 0:
			flowToolBase = QConfig::flowToolBase_B1;
			break;
		case 1:
			flowToolBase = QConfig::flowToolBase_B2;
			break;
		case 2:
			flowToolBase = QConfig::flowToolBase_B3;
			break;
		case 3:
			flowToolBase = QConfig::flowToolBase_B4;
			break;
		case 4:
			flowToolBase = QConfig::flowToolBase_B5;
			break;
		case 5:
			flowToolBase = QConfig::flowToolBase_B6;
			break;
		case 6:
			flowToolBase = QConfig::flowToolBase_B7;
			break;
		case 7:
			flowToolBase = QConfig::flowToolBase_B8;
			break;
		case 8:
			flowToolBase = QConfig::flowToolBase_B9;
			break;
		case 9:
			flowToolBase = QConfig::flowToolBase_B10;
			break;
		case 10:
			flowToolBase = QConfig::flowToolBase_B11;
			break;
		case 11:
			flowToolBase = QConfig::flowToolBase_B12;
			break;
		case 12:
			flowToolBase = QConfig::flowToolBase_B13;
			break;
		case 13:
			flowToolBase = QConfig::flowToolBase_B14;
			break;
		case 14:
			flowToolBase = QConfig::flowToolBase_B15;
			break;
		case 15:
			flowToolBase = QConfig::flowToolBase_B16;
			break;
		case 16:
			flowToolBase = QConfig::flowToolBase_B17;
			break;
		case 17:
			flowToolBase = QConfig::flowToolBase_B18;
			break;
		case 18:
			flowToolBase = QConfig::flowToolBase_B19;
			break;
		case 19:
			flowToolBase = QConfig::flowToolBase_B20;
			break;
		}
		if (flowToolBase == nullptr)
		{
			QConfig::tool_result = -2;
			QString error = "QToolBase指针为空！";
			context->throwError(error);
			return -2;
		}
		else
		{
			emit flowToolBase->sig_Warn(context->argument(0).toString());
		}		
		return context->argument(0).toString();
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "LogWarn输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue LogError(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 1)
		{
			QConfig::tool_result = -2;
			QString error = "LogError输入参数错误！";
			context->throwError(error);
			return error;
		}
		QToolBase* flowToolBase = nullptr;		
		switch (QConfig::g_flow_index) {
		case 0:
			flowToolBase = QConfig::flowToolBase_B1;
			break;
		case 1:
			flowToolBase = QConfig::flowToolBase_B2;
			break;
		case 2:
			flowToolBase = QConfig::flowToolBase_B3;
			break;
		case 3:
			flowToolBase = QConfig::flowToolBase_B4;
			break;
		case 4:
			flowToolBase = QConfig::flowToolBase_B5;
			break;
		case 5:
			flowToolBase = QConfig::flowToolBase_B6;
			break;
		case 6:
			flowToolBase = QConfig::flowToolBase_B7;
			break;
		case 7:
			flowToolBase = QConfig::flowToolBase_B8;
			break;
		case 8:
			flowToolBase = QConfig::flowToolBase_B9;
			break;
		case 9:
			flowToolBase = QConfig::flowToolBase_B10;
			break;
		case 10:
			flowToolBase = QConfig::flowToolBase_B11;
			break;
		case 11:
			flowToolBase = QConfig::flowToolBase_B12;
			break;
		case 12:
			flowToolBase = QConfig::flowToolBase_B13;
			break;
		case 13:
			flowToolBase = QConfig::flowToolBase_B14;
			break;
		case 14:
			flowToolBase = QConfig::flowToolBase_B15;
			break;
		case 15:
			flowToolBase = QConfig::flowToolBase_B16;
			break;
		case 16:
			flowToolBase = QConfig::flowToolBase_B17;
			break;
		case 17:
			flowToolBase = QConfig::flowToolBase_B18;
			break;
		case 18:
			flowToolBase = QConfig::flowToolBase_B19;
			break;
		case 19:
			flowToolBase = QConfig::flowToolBase_B20;
			break;
		}
		if (flowToolBase == nullptr)
		{
			QConfig::tool_result = -2;
			QString error = "QToolBase指针为空！";
			context->throwError(error);
			return -2;
		}
		else
		{
			emit flowToolBase->sig_Error(context->argument(0).toString());
		}		
		return context->argument(0).toString();
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "LogError输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue GetCurrentTime(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 0)
		{
			QConfig::tool_result = -2;
			QString error = "GetCurrentTime输入参数错误！";
			context->throwError(error);
			return error;
		}
		QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
		return time;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "GetCurrentTime输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ProjectSetGlobalValue(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 2)
		{
			QConfig::tool_result = -2;
			QString error = "ProjectSetGlobalValue输入参数错误！";
			context->throwError(error);
			return error;
		}
		QToolBase* flowToolBase = nullptr;	
		switch (QConfig::g_flow_index) {
		case 0:
			flowToolBase = QConfig::flowToolBase_B1;
			break;
		case 1:
			flowToolBase = QConfig::flowToolBase_B2;
			break;
		case 2:
			flowToolBase = QConfig::flowToolBase_B3;
			break;
		case 3:
			flowToolBase = QConfig::flowToolBase_B4;
			break;
		case 4:
			flowToolBase = QConfig::flowToolBase_B5;
			break;
		case 5:
			flowToolBase = QConfig::flowToolBase_B6;
			break;
		case 6:
			flowToolBase = QConfig::flowToolBase_B7;
			break;
		case 7:
			flowToolBase = QConfig::flowToolBase_B8;
			break;
		case 8:
			flowToolBase = QConfig::flowToolBase_B9;
			break;
		case 9:
			flowToolBase = QConfig::flowToolBase_B10;
			break;
		case 10:
			flowToolBase = QConfig::flowToolBase_B11;
			break;
		case 11:
			flowToolBase = QConfig::flowToolBase_B12;
			break;
		case 12:
			flowToolBase = QConfig::flowToolBase_B13;
			break;
		case 13:
			flowToolBase = QConfig::flowToolBase_B14;
			break;
		case 14:
			flowToolBase = QConfig::flowToolBase_B15;
			break;
		case 15:
			flowToolBase = QConfig::flowToolBase_B16;
			break;
		case 16:
			flowToolBase = QConfig::flowToolBase_B17;
			break;
		case 17:
			flowToolBase = QConfig::flowToolBase_B18;
			break;
		case 18:
			flowToolBase = QConfig::flowToolBase_B19;
			break;
		case 19:
			flowToolBase = QConfig::flowToolBase_B20;
			break;
		}		
		if (flowToolBase == nullptr)
		{
			QConfig::tool_result = -2;
			return -2;
		}
		else
		{
			QString result = emit flowToolBase->sig_SetGlobalValue(context->argument(0).toString(), context->argument(1).toString(), QConfig::g_flow_index);
			if (result == "p_error")
			{
				QConfig::tool_result = -2;
				QString error = "ProjectSetGlobalValue输入参数错误！";
				context->throwError(error);
				return -2;
			}
		}		
		return context->argument(1).toString();
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "ProjectSetGlobalValue输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue ProjectGetGlobalValue(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 1)
		{
			QConfig::tool_result = -2;
			QString error = "ProjectGetGlobalValue输入参数错误！";
			context->throwError(error);
			return error;
		}
		//获取全局变量值
		QList<QString> global_keys;
		global_keys.reserve(300);
		global_keys.clear();
		global_keys = gVariable::global_variable_link.uniqueKeys();
		for (int k = 0; k < global_keys.length(); k++)
		{
			QString key = global_keys[k];
			if (gVariable::global_variable_link.value(key).global_type == "Int")
			{
				if (context->argument(0).toString() == key)
				{
					return gVariable::global_variable_link.value(key).global_int_value;
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Double")
			{
				if (context->argument(0).toString() == key)
				{
					return gVariable::global_variable_link.value(key).global_double_value;
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "QString")
			{
				if (context->argument(0).toString() == key)
				{
					return gVariable::global_variable_link.value(key).global_qstring_value;
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Bool")
			{
				if (context->argument(0).toString() == key)
				{
					return gVariable::global_variable_link.value(key).global_bool_value;
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "QPoint")
			{
				if (context->argument(0).toString() == key)
				{
					QPoint g_point = gVariable::global_variable_link.value(key).global_qpoint_value;
					return engine->toScriptValue(QVariant(g_point));
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "QPointF")
			{
				if (context->argument(0).toString() == key)
				{
					QPointF g_pointf = gVariable::global_variable_link.value(key).global_qpointf_value;
					return engine->toScriptValue(QVariant(g_pointf));
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point")
			{
				if (context->argument(0).toString() == key)
				{
					cv::Point g_cvpoint = gVariable::global_variable_link.value(key).global_cvpoint_value;
					QPoint g_point = QPoint(g_cvpoint.x, g_cvpoint.y);
					return engine->toScriptValue(QVariant(g_point));
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point2f")
			{
				if (context->argument(0).toString() == key)
				{
					cv::Point2f g_cvpoint2f = gVariable::global_variable_link.value(key).global_cvpoint2f_value;
					QPointF g_pointf = QPointF(g_cvpoint2f.x, g_cvpoint2f.y);
					return engine->toScriptValue(QVariant(g_pointf));
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point3f")
			{
				if (context->argument(0).toString() == key)
				{
					cv::Point3f g_cvpoint3f = gVariable::global_variable_link.value(key).global_cvpoint3f_value;
					Point3f point3f;
					point3f.x = g_cvpoint3f.x;
					point3f.y = g_cvpoint3f.y;
					point3f.z = g_cvpoint3f.z;
					QVariant g_point3f;
					g_point3f.setValue(point3f);
					return engine->toScriptValue(g_point3f);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point3d")
			{
				if (context->argument(0).toString() == key)
				{
					cv::Point3d g_cvpoint3d = gVariable::global_variable_link.value(key).global_cvpoint3d_value;
					Point3d point3d;
					point3d.x = g_cvpoint3d.x;
					point3d.y = g_cvpoint3d.y;
					point3d.z = g_cvpoint3d.z;
					QVariant g_point3d;
					g_point3d.setValue(point3d);
					return engine->toScriptValue(g_point3d);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Float[]")
			{
				if (context->argument(0).toString() == key)
				{
					vector<float> g_array_float = gVariable::global_variable_link.value(key).global_array_float_value;
					ArrayFloat array_float;
					array_float.g_array_f.reserve(300);
					array_float.g_array_f.clear();
					for (int n = 0; n < g_array_float.size(); n++)
					{
						array_float.g_array_f.append(g_array_float[n]);
					}
					QVariant g_a_float;
					g_a_float.setValue(array_float);
					return engine->toScriptValue(g_a_float);
				}
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Double[]")
			{
				if (context->argument(0).toString() == key)
				{
					vector<double> g_array_double = gVariable::global_variable_link.value(key).global_array_double_value;
					ArrayDouble array_double;
					array_double.g_array_d.reserve(300);
					array_double.g_array_d.clear();
					for (int n = 0; n < g_array_double.size(); n++)
					{
						array_double.g_array_d.append(g_array_double[n]);
					}
					QVariant g_a_double;
					g_a_double.setValue(array_double);
					return engine->toScriptValue(g_a_double);
				}
			}
		}
		QConfig::tool_result = -2;		
		QString error = "ProjectGetGlobalValue输入参数错误！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;	
		QString error = "ProjectGetGlobalValue输入参数错误！";
		context->throwError(error);
		return error;
	}
}

QScriptValue GetFlowToolValue(QScriptContext* context, QScriptEngine* engine)
{
	try
	{
		int c_size = context->argumentCount();
		if (c_size != 1)
		{
			QConfig::tool_result = -2;
			QString error = "GetFlowToolValue输入参数错误！";
			context->throwError(error);
			return error;
		}
		//获取工具变量值
		int f_index = 0;
		QStringList f_strs;
		f_strs.reserve(100);
		f_strs.clear();
		f_strs = context->argument(0).toString().split(".");
		if (f_strs.size() == 1)
		{
			QConfig::tool_result = -2;
			QString error = "GetFlowToolValue输入参数错误！";
			context->throwError(error);
			return -2;
		}
		QToolBase* flowToolBase = nullptr;		
		switch (QConfig::g_flow_index) {
		case 0:
			flowToolBase = QConfig::flowToolBase_B1;
			break;
		case 1:
			flowToolBase = QConfig::flowToolBase_B2;
			break;
		case 2:
			flowToolBase = QConfig::flowToolBase_B3;
			break;
		case 3:
			flowToolBase = QConfig::flowToolBase_B4;
			break;
		case 4:
			flowToolBase = QConfig::flowToolBase_B5;
			break;
		case 5:
			flowToolBase = QConfig::flowToolBase_B6;
			break;
		case 6:
			flowToolBase = QConfig::flowToolBase_B7;
			break;
		case 7:
			flowToolBase = QConfig::flowToolBase_B8;
			break;
		case 8:
			flowToolBase = QConfig::flowToolBase_B9;
			break;
		case 9:
			flowToolBase = QConfig::flowToolBase_B10;
			break;
		case 10:
			flowToolBase = QConfig::flowToolBase_B11;
			break;
		case 11:
			flowToolBase = QConfig::flowToolBase_B12;
			break;
		case 12:
			flowToolBase = QConfig::flowToolBase_B13;
			break;
		case 13:
			flowToolBase = QConfig::flowToolBase_B14;
			break;
		case 14:
			flowToolBase = QConfig::flowToolBase_B15;
			break;
		case 15:
			flowToolBase = QConfig::flowToolBase_B16;
			break;
		case 16:
			flowToolBase = QConfig::flowToolBase_B17;
			break;
		case 17:
			flowToolBase = QConfig::flowToolBase_B18;
			break;
		case 18:
			flowToolBase = QConfig::flowToolBase_B19;
			break;
		case 19:
			flowToolBase = QConfig::flowToolBase_B20;
			break;
		}
		if (flowToolBase == nullptr)
		{
			QConfig::tool_result = -2;
			QString error = "QToolBase指针为空！";
			context->throwError(error);
			return -2;
		}		
		bool link_state = false;
		for (int i = 0; i < flowToolBase->m_Tools.size(); i++)
		{
			if (flowToolBase->m_Tools[i].PublicToolName == f_strs[0])
			{
				f_index = i;
				link_state = true;
			}
		}
		if (link_state == false)
		{
			QConfig::tool_result = -2;
			QString error = "GetFlowToolValue输入参数错误！";
			context->throwError(error);
			return -2;
		}
		if (f_strs[1] == "状态")
		{
			return flowToolBase->m_Tools[f_index].PublicResult.State;
		}
		else if (f_strs[1] == "条形码" || f_strs[1] == "二维码")
		{
			ArrayQString barcode;
			barcode.t_array_string.reserve(100);
			barcode.t_array_string.clear();
			barcode.t_array_string = flowToolBase->m_Tools[f_index].PublicDetect.Code;
			QVariant t_barcode;
			t_barcode.setValue(barcode);
			return engine->toScriptValue(t_barcode);
		}
		else if (f_strs[1] == "斑点个数")
		{
			return flowToolBase->m_Tools[f_index].PublicDetect.Quantity;
		}
		else if (f_strs[1] == "类别")
		{
			return flowToolBase->m_Tools[f_index].PublicDetect.Category;
		}
		else if (f_strs[1] == "相似度")
		{
			return flowToolBase->m_Tools[f_index].PublicDetect.Score;
		}
		else if (f_strs[1] == "亮度")
		{
			return flowToolBase->m_Tools[f_index].PublicDetect.Brightness;
		}
		else if (f_strs[1] == "清晰度")
		{
			return flowToolBase->m_Tools[f_index].PublicDetect.Clarity;
		}
		else if (f_strs[1] == "面积")
		{
			ToolArrayDouble area;
			area.t_array_d.reserve(10000);
			area.t_array_d.clear();
			area.t_array_d = flowToolBase->m_Tools[f_index].PublicDetect.Areas;
			QVariant t_area;
			t_area.setValue(area);
			return engine->toScriptValue(t_area);
		}
		else if (f_strs[1] == "重心")
		{
			ArrayCvPoint2f center_points;
			center_points.t_array_points.reserve(10000);
			center_points.t_array_points.clear();
			center_points.t_array_points = flowToolBase->m_Tools[f_index].PublicDetect.CenterPoints;
			QVariant t_center_points;
			t_center_points.setValue(center_points);
			return engine->toScriptValue(t_center_points);
		}
		else if (f_strs[1] == "N点标定参数")
		{
			ToolArrayDouble estimate_affine;
			estimate_affine.t_array_d.reserve(10);
			estimate_affine.t_array_d.clear();
			estimate_affine.t_array_d = flowToolBase->m_Tools[f_index].PublicCalib.EstimateAffine;
			QVariant t_estimate_affine;
			t_estimate_affine.setValue(estimate_affine);
			return engine->toScriptValue(t_estimate_affine);
		}
		else if (f_strs[1] == "旋转中心")
		{
			cv::Point2f t_cvpoint2f = flowToolBase->m_Tools[f_index].PublicCalib.RotateCenter;
			QPointF t_pointf = QPointF(t_cvpoint2f.x, t_cvpoint2f.y);
			return engine->toScriptValue(QVariant(t_pointf));
		}
		else if (f_strs[1] == "像素当量X")
		{
			return flowToolBase->m_Tools[f_index].PublicCalib.PixelEquivalentX;
		}
		else if (f_strs[1] == "像素当量Y")
		{
			return flowToolBase->m_Tools[f_index].PublicCalib.PixelEquivalentY;
		}
		else if (f_strs[1] == "基准点1")
		{
			cv::Point2f t_cvpoint2f = flowToolBase->m_Tools[f_index].PublicCalib.DatumPoint1;
			QPointF t_pointf = QPointF(t_cvpoint2f.x, t_cvpoint2f.y);
			return engine->toScriptValue(QVariant(t_pointf));
		}
		else if (f_strs[1] == "基准点2")
		{
			cv::Point2f t_cvpoint2f = flowToolBase->m_Tools[f_index].PublicCalib.DatumPoint2;
			QPointF t_pointf = QPointF(t_cvpoint2f.x, t_cvpoint2f.y);
			return engine->toScriptValue(QVariant(t_pointf));
		}
		else if (f_strs[1] == "基准角度")
		{
			return flowToolBase->m_Tools[f_index].PublicCalib.DatumAngle;
		}
		else if (f_strs[1] == "匹配中心坐标")
		{
			ArrayCvPoint2f center_points;
			center_points.t_array_points.reserve(1000);
			center_points.t_array_points.clear();
			center_points.t_array_points = flowToolBase->m_Tools[f_index].PublicTPosition.Center;
			QVariant t_center_points;
			t_center_points.setValue(center_points);
			return engine->toScriptValue(t_center_points);
		}
		else if (f_strs[1] == "匹配角度")
		{
			ToolArrayDouble temp_angle;
			temp_angle.t_array_d.reserve(1000);
			temp_angle.t_array_d.clear();
			temp_angle.t_array_d = flowToolBase->m_Tools[f_index].PublicTPosition.Angle;
			QVariant t_temp_angle;
			t_temp_angle.setValue(temp_angle);
			return engine->toScriptValue(t_temp_angle);
		}
		else if (f_strs[1] == "匹配分数")
		{
			ToolArrayDouble temp_score;
			temp_score.t_array_d.reserve(1000);
			temp_score.t_array_d.clear();
			temp_score.t_array_d = flowToolBase->m_Tools[f_index].PublicTPosition.OutScore;
			QVariant t_temp_score;
			t_temp_score.setValue(temp_score);
			return engine->toScriptValue(t_temp_score);
		}
		else if (f_strs[1] == "匹配基准中心")
		{
			cv::Point2f t_cvpoint2f = flowToolBase->m_Tools[f_index].PublicTPosition.DatumCenter;
			QPointF t_pointf = QPointF(t_cvpoint2f.x, t_cvpoint2f.y);
			return engine->toScriptValue(QVariant(t_pointf));
		}
		else if (f_strs[1] == "移动量X")
		{
			return flowToolBase->m_Tools[f_index].PublicTPosition.MovingDistanceX;
		}
		else if (f_strs[1] == "移动量Y")
		{
			return flowToolBase->m_Tools[f_index].PublicTPosition.MovingDistanceY;
		}
		else if (f_strs[1] == "世界坐标点")
		{
			cv::Point2f t_cvpoint2f = flowToolBase->m_Tools[f_index].PublicTPosition.WorldCoordinatePoint;
			QPointF t_pointf = QPointF(t_cvpoint2f.x, t_cvpoint2f.y);
			return engine->toScriptValue(QVariant(t_pointf));
		}
		else if (f_strs[1] == "中心坐标" || f_strs[1] == "圆心坐标")
		{
			cv::Point2f t_cvpoint2f = flowToolBase->m_Tools[f_index].PublicGeometry.Center;
			QPointF t_pointf = QPointF(t_cvpoint2f.x, t_cvpoint2f.y);
			return engine->toScriptValue(QVariant(t_pointf));
		}
		else if (f_strs[1] == "半径")
		{
			return flowToolBase->m_Tools[f_index].PublicGeometry.Radius;
		}
		else if (f_strs[1] == "斜率")
		{
			return flowToolBase->m_Tools[f_index].PublicGeometry.k;
		}
		else if (f_strs[1] == "截距")
		{
			return flowToolBase->m_Tools[f_index].PublicGeometry.b;
		}
		else if (f_strs[1] == "角度" || f_strs[1] == "夹角")
		{
			return flowToolBase->m_Tools[f_index].PublicGeometry.Angle;
		}
		else if (f_strs[1] == "长轴长度")
		{
			return flowToolBase->m_Tools[f_index].PublicGeometry.Length1;
		}
		else if (f_strs[1] == "短轴长度")
		{
			return flowToolBase->m_Tools[f_index].PublicGeometry.Length2;
		}
		else if (f_strs[1] == "点集")
		{
			ArrayCvPoint2f a_points;
			a_points.t_array_points.reserve(1000000);
			a_points.t_array_points.clear();
			a_points.t_array_points = flowToolBase->m_Tools[f_index].PublicGeometry.BorderPoints;
			QVariant t_a_points;
			t_a_points.setValue(a_points);
			return engine->toScriptValue(t_a_points);
		}
		else if (f_strs[0].mid(0, 4) == "线圆交点" && f_strs[1] == "交点坐标")
		{
			ArrayCvPoint2f i_points;
			i_points.t_array_points.reserve(10);
			i_points.t_array_points.clear();
			i_points.t_array_points = flowToolBase->m_Tools[f_index].PublicGeometry.Intersections;
			QVariant t_i_points;
			t_i_points.setValue(i_points);
			return engine->toScriptValue(t_i_points);
		}
		else if (f_strs[1] == "距离" || f_strs[1] == "边缘宽度")
		{
			return flowToolBase->m_Tools[f_index].PublicGeometry.Distance;
		}
		else if (f_strs[1] == "垂足坐标")
		{
			cv::Point2f t_cvpoint2f = flowToolBase->m_Tools[f_index].PublicGeometry.Pedal;
			QPointF t_pointf = QPointF(t_cvpoint2f.x, t_cvpoint2f.y);
			return engine->toScriptValue(QVariant(t_pointf));
		}
		else if (f_strs[0].mid(0, 4) == "线线交点" && f_strs[1] == "交点坐标")
		{
			cv::Point2f t_cvpoint2f = flowToolBase->m_Tools[f_index].PublicGeometry.Intersection;
			QPointF t_pointf = QPointF(t_cvpoint2f.x, t_cvpoint2f.y);
			return engine->toScriptValue(QVariant(t_pointf));
		}
		else if (f_strs[1] == "平面参数")
		{
			ToolArrayDouble tool_flatness;
			tool_flatness.t_array_d.reserve(10);
			tool_flatness.t_array_d.clear();
			tool_flatness.t_array_d = flowToolBase->m_Tools[f_index].PublicThreeD.Flatness;
			QVariant t_temp_flat;
			t_temp_flat.setValue(tool_flatness);
			return engine->toScriptValue(t_temp_flat);
		}
		else if (f_strs[1] == "点到平面距离")
		{
			return flowToolBase->m_Tools[f_index].PublicThreeD.Distance;
		}
		else if (f_strs[1] == "接收数据")
		{
			return flowToolBase->m_Tools[f_index].PublicCommunication.InputData;
		}
		else if (f_strs[1] == "发送数据")
		{
			return flowToolBase->m_Tools[f_index].PublicCommunication.OutputData;
		}
		else if (f_strs[1] == "寄存器读取数据")
		{
			ArrayInt array_register;
			array_register.t_array_int.reserve(1000);
			array_register.t_array_int.clear();
			array_register.t_array_int = flowToolBase->m_Tools[f_index].PublicCommunication.RegisterReadData;
			QVariant t_register;
			t_register.setValue(array_register);
			return engine->toScriptValue(t_register);
		}
		else if (f_strs[1] == "寄存器写入数据")
		{
			ArrayInt array_register;
			array_register.t_array_int.reserve(1000);
			array_register.t_array_int.clear();
			array_register.t_array_int = flowToolBase->m_Tools[f_index].PublicCommunication.RegisterWriteData;
			QVariant t_register;
			t_register.setValue(array_register);
			return engine->toScriptValue(t_register);
		}
		else if (f_strs[1] == "输入点")
		{
			ArrayBool array_input;
			array_input.t_array_bool.reserve(8);
			array_input.t_array_bool.clear();
			array_input.t_array_bool = flowToolBase->m_Tools[f_index].PublicCommunication.InPutIoX;
			QVariant t_input;
			t_input.setValue(array_input);
			return engine->toScriptValue(t_input);
		}
		QConfig::tool_result = -2;
		QString error = "GetFlowToolValue输入参数错误！";
		context->throwError(error);
		return error;
	}
	catch (...)
	{
		QConfig::tool_result = -2;
		QString error = "GetFlowToolValue输入参数错误！";
		context->throwError(error);
		return error;
	}
}

frmScriptEdit::frmScriptEdit(QString toolName, QToolBase* toolBase, QWidget* parent)
	: Toolnterface(toolName, toolBase, parent)
{
	ui.setupUi(this);
	toolTitleName = toolName;
	//FramelessWindowHint属性设置窗口去除边框
	//WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	//设置窗体在屏幕中间位置
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	//设置窗口背景透明
	setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/resource/script_edit.png"));
	//初始化标题栏
	initTitleBar();
	highlighter = new Highlighter(ui.plainTextEdit->document());
	QFont font = ui.plainTextEdit->font();
	font.setPointSize(10);
	font.setFamily("Microsoft YaHei");
	ui.plainTextEdit->setFont(font);
	completer = new QCompleter(this);
	completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
	completer->setCaseSensitivity(Qt::CaseInsensitive);
	completer->setWrapAround(false);
	ui.plainTextEdit->setCompleter(completer);
	ui.plainTextEdit->setStyleSheet("QPlainTextEdit{background-color: rgb(220, 220, 220);}"
		"QScrollBar:vertical{" //设置滚动条样式
		"background:#FFFFF2;"  //背景色  
		"padding-top:20px;"    //上预留位置(放置向上箭头）  
		"padding-bottom:20px;" //下预留位置(放置向下箭头）  
		"padding-left:2px;"    //左预留位置 
		"padding-right:2px;"   //右预留位置 
		"border-left:1px solid #d7d7d7;}" //左分割线  
		"QScrollBar::handle:vertical{" //滑块样式  
		"background:#dbdbdb;"  //滑块颜色  
		"border-radius:6px;"   //边角圆
		"min-height:20px;}"    //滑块最小高度
		"QScrollBar::handle:vertical:hover{" //鼠标触及滑块样式  
		"background:#d0d0d0;}" //滑块颜色  
		"QScrollBar::add-line:vertical{" //向下箭头样式  
		"background:url(:/resource/down.png) center no-repeat;}"
		"QScrollBar::sub-line:vertical{" //向上箭头样式
		"background:url(:/resource/up.png) center no-repeat;}"
		"QScrollBar:horizontal{"
		"background:#FFFFF2;"
		"padding-top:20px;"
		"padding-bottom:20px;"
		"padding-left:2px;"
		"padding-right:2px;"
		"border-left:1px solid #d7d7d7; }"
		"QScrollBar::handle:horizontal{"
		"background:#dbdbdb;"
		"border-radius:6px;"
		"min-height:20px; }"
		"QScrollBar::handle:horizontal:hover{"
		"background:#d0d0d0; }"
		"QScrollBar::add-line:horizontal{"
		"background:url(:/resource/right.png) center no-repeat; }"
		"QScrollBar::sub-line:horizontal{"
		"background:url(:/resource/left.png) center no-repeat; }");
	ToolsTreeWidgetInit();
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.75);
	ui.plainTextExample->setGraphicsEffect(e);
	QGraphicsOpacityEffect* e2 = new QGraphicsOpacityEffect(this);
	e2->setOpacity(0.75);
	ui.txtMsg->setGraphicsEffect(e2);
	form_load();
	connect(ui.tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_DoubleClicked(int, int)));
	connect(this, SIGNAL(accepted()), this, SLOT(slot_Accepted()));
	connect(this, &frmScriptEdit::sig_ScriptError, this, &frmScriptEdit::slot_ScriptError);
	QScriptValue fun = script_engine.newFunction(LogInfo);
	script_engine.globalObject().setProperty("LogInfo", fun);
	QScriptValue fun2 = script_engine.newFunction(LogWarn);
	script_engine.globalObject().setProperty("LogWarn", fun2);
	QScriptValue fun3 = script_engine.newFunction(LogError);
	script_engine.globalObject().setProperty("LogError", fun3);
	QScriptValue fun4 = script_engine.newFunction(GetCurrentTime);
	script_engine.globalObject().setProperty("GetCurrentTime", fun4);
	QScriptValue fun5 = script_engine.newFunction(ProjectSetGlobalValue);
	script_engine.globalObject().setProperty("ProjectSetGlobalValue", fun5);
	QScriptValue fun6 = script_engine.newFunction(ProjectGetGlobalValue);
	script_engine.globalObject().setProperty("ProjectGetGlobalValue", fun6);
	QScriptValue fun7 = script_engine.newFunction(GetFlowToolValue);
	script_engine.globalObject().setProperty("GetFlowToolValue", fun7);
	QScriptValue fun8 = script_engine.newFunction(ConvertToPoint);
	script_engine.globalObject().setProperty("ConvertToPoint", fun8);
	QScriptValue fun9 = script_engine.newFunction(ConvertToPoint2f);
	script_engine.globalObject().setProperty("ConvertToPoint2f", fun9);
	QScriptValue fun10 = script_engine.newFunction(ConvertToPoint3f);
	script_engine.globalObject().setProperty("ConvertToPoint3f", fun10);
	QScriptValue fun11 = script_engine.newFunction(ConvertToPoint3d);
	script_engine.globalObject().setProperty("ConvertToPoint3d", fun11);
	QScriptValue fun12 = script_engine.newFunction(ConvertToArrayFloat);
	script_engine.globalObject().setProperty("ConvertToArrayFloat", fun12);
	QScriptValue fun13 = script_engine.newFunction(ConvertToArrayDouble);
	script_engine.globalObject().setProperty("ConvertToArrayDouble", fun13);
	QScriptValue fun14 = script_engine.newFunction(GetArraySize);
	script_engine.globalObject().setProperty("GetArraySize", fun14);
	QScriptValue fun15 = script_engine.newFunction(ConvertToArrayQString);
	script_engine.globalObject().setProperty("ConvertToArrayQString", fun15);
	QScriptValue fun16 = script_engine.newFunction(ConvertToArrayCvPoint2f);
	script_engine.globalObject().setProperty("ConvertToArrayCvPoint2f", fun16);
	QScriptValue fun17 = script_engine.newFunction(ConvertToArrayInt);
	script_engine.globalObject().setProperty("ConvertToArrayInt", fun17);
	QScriptValue fun18 = script_engine.newFunction(ConvertToArrayBool);
	script_engine.globalObject().setProperty("ConvertToArrayBool", fun18);
}

frmScriptEdit::~frmScriptEdit()
{
	script_engine.collectGarbage();  //释放内存
	highlighter->deleteLater();
	highlighter = nullptr;
	this->deleteLater();
}

void frmScriptEdit::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/script_edit.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmScriptEdit::paintEvent(QPaintEvent* event)
{
	//设置背景色
	QPainter painter(this);
	QPainterPath pathBack;
	pathBack.setFillRule(Qt::WindingFill);
	pathBack.addRoundedRect(QRect(0, 0, this->width(), this->height()), 3, 3);
	painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
	painter.fillPath(pathBack, QBrush(QColor(160, 160, 160)));
	return QWidget::paintEvent(event);
}

void frmScriptEdit::form_load()
{
	//设置表格列宽	
	ui.tableWidget->setColumnWidth(0, 45);
	ui.tableWidget->setColumnWidth(1, 202);
	ui.tableWidget->setColumnWidth(2, 310);
	ui.tableWidget->setColumnWidth(3, 242);
	//隐藏水平header
	ui.tableWidget->verticalHeader()->setVisible(false);
	//设置整行选中
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.tableWidget->horizontalHeader()->setDisabled(true);
	//添加List	 	
	ItemModel = new QStandardItemModel(this);
	ui.listProcess->setEditTriggers(QAbstractItemView::NoEditTriggers);  //禁止编辑
}

void frmScriptEdit::ToolsTreeWidgetInit()
{
	ToolTreeWidget = new QTreeWidget(this);
	QGridLayout* ToolGLayout = new QGridLayout(ui.ToolTreeFrame);
	ToolGLayout->setContentsMargins(0, 0, 0, 0);
	ToolGLayout->setSpacing(5);
	ToolGLayout->addWidget(ToolTreeWidget, 0, 0);
	ToolTreeWidget->setIconSize(QSize(22, 22));
	//显示虚线
	ToolTreeWidget->setStyle(QStyleFactory::create("windows"));
	//更换系统默认图标
	ToolTreeWidget->setStyleSheet("QTreeWidget::branch:has-children:!has-siblings:closed,\
	QWidget{border: 1px;border-style: solid;border-color: #d9d9d9}\
	QTreeWidget::item{color: #363636}\
	QTreeWidget::item{height: 30px}\
	QTreeWidget::branch:closed:has-children:!has-siblings{border-style: none; border-image: none; image: url(:/resource/unfold.png);}\
	QTreeWidget::branch:closed:has-children:has-siblings{border-image: none; image: url(:/resource/unfold.png);}\
	QTreeWidget::branch:open:has-children:!has-siblings{border-image: none; image: url(:/resource/fold.png);}\
	QTreeWidget::branch:open:has-children:has-siblings{border-image: none; image: url(:/resource/fold.png);}");
	//设置字体及字体大小
	QFont font("Microsoft YaHei");
	font.setPixelSize(16);
	ToolTreeWidget->setFont(font);
	ToolTreeWidget->header()->setVisible(false);
	ToolTreeWidget->clear();
	this->setAcceptDrops(false);
	//方法列表
	ToolsPair toolPair;
	//Visual方法	
	toolPair.first = "Vision方法";
	ToolNameList.push_back("设置全局变量值");
	ToolNameList.push_back("获取当前时间");
	ToolNameList.push_back("GetArraySize");
	ToolNameList.push_back("ConvertToPoint");
	ToolNameList.push_back("ConvertToPoint2f");
	ToolNameList.push_back("ConvertToPoint3f");
	ToolNameList.push_back("ConvertToPoint3d");
	ToolNameList.push_back("ConvertToArrayInt");
	ToolNameList.push_back("ConvertToArrayBool");
	ToolNameList.push_back("ConvertToArrayFloat");
	ToolNameList.push_back("ConvertToArrayDouble");
	ToolNameList.push_back("ConvertToArrayQString");
	ToolNameList.push_back("ConvertToArrayCvPoint2f");
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//Log方法		
	toolPair.first = "Log方法";
	ToolNameList.push_back("LogInfo");
	ToolNameList.push_back("LogWarn");
	ToolNameList.push_back("LogError");
	toolPair.second = ToolNameList;
	ToolNamesVec.push_back(toolPair);
	ToolNameList.clear();
	//循环处理图标	
	for (int i = 0; i < ToolNamesVec.size(); i++)
	{
		QString toolBoxName = ToolNamesVec[i].first;
		QStringList toolList = QStringList::fromStdList(ToolNamesVec[i].second);
		QTreeWidgetItem* itemParent = new QTreeWidgetItem(ToolTreeWidget);
		itemParent->setText(0, toolBoxName);
		itemParent->setIcon(0, QIcon(":/resource/tool.ico"));
		itemParent->setFlags(Qt::NoItemFlags | Qt::ItemIsEnabled);
		for (int j = 0; j < toolList.count(); j++)
		{
			QTreeWidgetItem* treeItem = new QTreeWidgetItem(itemParent, QStringList(toolList[j]));
			QPixmap pixmap = GetIcon(GetIconName(toolList[j]));
			treeItem->setIcon(0, pixmap);
		}
	}
	ToolTreeWidget->expandAll();
	connect(ToolTreeWidget, &QTreeWidget::itemDoubleClicked, this, &frmScriptEdit::slot_ItemDoubleClicked);
}

//获取图标
QPixmap frmScriptEdit::GetIcon(QString fileName)
{
	return IconHelpers::Instance()->getPixmap(fileName);
}

//获取图标路径
QString frmScriptEdit::GetIconName(QString Name)
{
	QString IconName;
	if (Name.contains("设置全局变量值")) IconName = ":/resource/setvar.png";
	if (Name.contains("获取当前时间")) IconName = ":/resource/time.png";
	if (Name.contains("GetArraySize")) IconName = ":/resource/size.png";
	if (Name.contains("ConvertToPoint")) IconName = ":/resource/convert_1.png";
	if (Name.contains("ConvertToPoint2f")) IconName = ":/resource/convert_2.png";
	if (Name.contains("ConvertToPoint3f")) IconName = ":/resource/convert_3.png";
	if (Name.contains("ConvertToPoint3d")) IconName = ":/resource/convert_4.png";
	if (Name.contains("ConvertToArrayInt")) IconName = ":/resource/convert_5.png";
	if (Name.contains("ConvertToArrayBool")) IconName = ":/resource/convert_6.png";
	if (Name.contains("ConvertToArrayFloat")) IconName = ":/resource/convert_7.png";
	if (Name.contains("ConvertToArrayDouble")) IconName = ":/resource/convert_8.png";
	if (Name.contains("ConvertToArrayQString")) IconName = ":/resource/convert_9.png";
	if (Name.contains("ConvertToArrayCvPoint2f")) IconName = ":/resource/convert_10.png";
	if (Name.contains("LogInfo")) IconName = ":/resource/info.png";
	if (Name.contains("LogWarn")) IconName = ":/resource/warn.png";
	if (Name.contains("LogError")) IconName = ":/resource/error.png";
	if (Name.contains("全局变量")) IconName = ":/resource/var.ico";
	if (Name.contains("获取图像")) IconName = ":/resource/image_source.png";
	if (Name.contains("图像显示")) IconName = ":/resource/image_view.ico";
	if (Name.contains("导出图像")) IconName = ":/resource/export_image.png";
	if (Name.contains("斑点分析")) IconName = ":/resource/blob.png";
	if (Name.contains("预处理")) IconName = ":/resource/morphology.png";
	if (Name.contains("图像拼接")) IconName = ":/resource/image_splice.png";
	if (Name.contains("图像修复")) IconName = ":/resource/repair.png";
	if (Name.contains("图像细化")) IconName = ":/resource/skeleton.png";
	if (Name.contains("图像翻转")) IconName = ":/resource/flip.png";
	if (Name.contains("图像旋转")) IconName = ":/resource/rotate.png";
	if (Name.contains("透视变换")) IconName = ":/resource/perspective.png";
	if (Name.contains("裁切图像")) IconName = ":/resource/crop.png";
	if (Name.contains("创建ROI")) IconName = ":/resource/roi.png";
	if (Name.contains("条形码识别")) IconName = ":/resource/barcode.png";
	if (Name.contains("二维码识别")) IconName = ":/resource/qrcode.png";
	if (Name.contains("字符识别")) IconName = ":/resource/ocr.png";
	if (Name.contains("分类器")) IconName = ":/resource/classifier.png";
	if (Name.contains("颜色识别")) IconName = ":/resource/color_r.png";
	if (Name.contains("亮度检测")) IconName = ":/resource/brightness.png";
	if (Name.contains("图像清晰度")) IconName = ":/resource/clarity.png";
	if (Name.contains("轮廓特征选择")) IconName = ":/resource/shape.png";
	if (Name.contains("N点标定")) IconName = ":/resource/ert_calib.png";
	if (Name.contains("畸变标定")) IconName = ":/resource/distortion_calib.png";
	if (Name.contains("测量标定")) IconName = ":/resource/measure_calib.png";
	if (Name.contains("灰度匹配")) IconName = ":/resource/match.png";
	if (Name.contains("形状匹配")) IconName = ":/resource/shape_match.png";
	if (Name.contains("目标跟踪")) IconName = ":/resource/track.png";
	if (Name.contains("线性计算")) IconName = ":/resource/affine.png";
	if (Name.contains("线圆交点")) IconName = ":/resource/line_circle.png";
	if (Name.contains("点+点")) IconName = ":/resource/point_point.png";
	if (Name.contains("点+线")) IconName = ":/resource/point_l.png";
	if (Name.contains("线线交点")) IconName = ":/resource/intersection.png";
	if (Name.contains("查找圆缺角")) IconName = ":/resource/rounded_c.png";
	if (Name.contains("寻找圆")) IconName = ":/resource/find_circle.png";
	if (Name.contains("寻找直线")) IconName = ":/resource/find_line.png";
	if (Name.contains("拟合圆")) IconName = ":/resource/fit_circle.png";
	if (Name.contains("拟合椭圆")) IconName = ":/resource/fit_ellipse.png";
	if (Name.contains("拟合直线")) IconName = ":/resource/fit_line.png";
	if (Name.contains("获取边界点")) IconName = ":/resource/border_point.png";
	if (Name.contains("边缘宽度测量")) IconName = ":/resource/edge.png";
	if (Name.contains("拟合平面")) IconName = ":/resource/flatness.png";
	if (Name.contains("扩展库")) IconName = ":/resource/extension_library.png";
	if (Name.contains("跳转语句")) IconName = ":/resource/goto.png";
	if (Name.contains("判断语句")) IconName = ":/resource/logic_judge.png";
	if (Name.contains("结束语句")) IconName = ":/resource/end.png";
	if (Name.contains("脚本编辑")) IconName = ":/resource/script_edit.png";
	if (Name.contains("TCP/IP服务器")) IconName = ":/resource/server.png";
	if (Name.contains("TCP/IP客户端")) IconName = ":/resource/client.png";
	if (Name.contains("PLC通信")) IconName = ":/resource/plc_communicate.png";
	if (Name.contains("串口通信")) IconName = ":/resource/serial_port.png";
	if (Name.contains("通用I/O")) IconName = ":/resource/general_io.png";
	if (Name.contains("延时")) IconName = ":/resource/delay.png";
	if (Name.contains("导出CSV")) IconName = ":/resource/export_csv.png";
	if (Name.contains("YoloV13")) IconName = ":/resource/classifier.png";
	if (Name.contains("OCR")) IconName = ":/resource/ocr.png";
	if (Name.contains("二维码生成")) IconName = ":/resource/qrcode.png";
	return IconName;
}

void frmScriptEdit::slot_Accepted()
{
	slot_CreateList();
}

void frmScriptEdit::onButtonCloseClicked()
{
	//信号与槽解除连接
	disconnect(ui.listProcess, SIGNAL(clicked(QModelIndex)), this, SLOT(slot_ListClick(QModelIndex)));
	this->close();
}

void frmScriptEdit::slot_CreateList()
{
	QVector<QString> FlowProItemList;
	FlowProItemList.reserve(100);
	FlowProItemList.clear();
	int item_id = 0;
	script_keys.reserve(300);
	script_keys.clear();
	script_keys = gvariable.scriptedit_variable_link.uniqueKeys();
	for (int k = 0; k < script_keys.length(); k++)
	{
		if (script_keys[k] = GetToolBase());
		{
			FlowProItemList = gvariable.scriptedit_variable_link.value(script_keys[k]).flow_pro_item_list;
			item_id = FlowProItemList.indexOf(toolTitleName);
			QConfig::g_flow_index = gvariable.scriptedit_variable_link.value(script_keys[k]).item_id;
			switch (QConfig::g_flow_index) {
			case 0:
				QConfig::flowToolBase_B1 = GetToolBase();
				break;
			case 1:
				QConfig::flowToolBase_B2 = GetToolBase();
				break;
			case 2:
				QConfig::flowToolBase_B3 = GetToolBase();
				break;
			case 3:
				QConfig::flowToolBase_B4 = GetToolBase();
				break;
			case 4:
				QConfig::flowToolBase_B5 = GetToolBase();
				break;
			case 5:
				QConfig::flowToolBase_B6 = GetToolBase();
				break;
			case 6:
				QConfig::flowToolBase_B7 = GetToolBase();
				break;
			case 7:
				QConfig::flowToolBase_B8 = GetToolBase();
				break;
			case 8:
				QConfig::flowToolBase_B9 = GetToolBase();
				break;
			case 9:
				QConfig::flowToolBase_B10 = GetToolBase();
				break;
			case 10:
				QConfig::flowToolBase_B11 = GetToolBase();
				break;
			case 11:
				QConfig::flowToolBase_B12 = GetToolBase();
				break;
			case 12:
				QConfig::flowToolBase_B13 = GetToolBase();
				break;
			case 13:
				QConfig::flowToolBase_B14 = GetToolBase();
				break;
			case 14:
				QConfig::flowToolBase_B15 = GetToolBase();
				break;
			case 15:
				QConfig::flowToolBase_B16 = GetToolBase();
				break;
			case 16:
				QConfig::flowToolBase_B17 = GetToolBase();
				break;
			case 17:
				QConfig::flowToolBase_B18 = GetToolBase();
				break;
			case 18:
				QConfig::flowToolBase_B19 = GetToolBase();
				break;
			case 19:
				QConfig::flowToolBase_B20 = GetToolBase();
				break;
			}
			break;
		}
	}
	//添加List	 		
	ItemModel->removeRows(0, ItemModel->rowCount());
	//添加全局变量
	QStandardItem* item = new QStandardItem("全局变量");
	QPixmap pixmap = GetIcon(GetIconName("全局变量"));
	item->setIcon(pixmap);
	ItemModel->appendRow(item);
	for (int i = 0; i < item_id; i++)
	{
		//添加流程
		QStandardItem* item_s = new QStandardItem(FlowProItemList[i]);
		QPixmap pixmap = GetIcon(GetIconName(FlowProItemList[i]));
		item_s->setIcon(pixmap);
		ItemModel->appendRow(item_s);
	}
	ui.listProcess->setModel(ItemModel);
	connect(ui.listProcess, SIGNAL(clicked(QModelIndex)), this, SLOT(slot_ListClick(QModelIndex)));
	QModelIndex qindex = ItemModel->index(0, 0);
	ui.listProcess->setCurrentIndex(qindex);
	ui.listProcess->clicked(qindex);
}

void frmScriptEdit::slot_ListClick(QModelIndex index)
{
	index_process_modify = index.row();
	tool_name = index.data().toString();
	//提取不含数字字符串	
	int str_count = 0;
	for (int k = 0; k < tool_name.length(); k++)
	{
		if (!(tool_name[k] > '0' && tool_name[k] < '9'))
		{
			++str_count;
		}
	}
	QString str_name_buf = tool_name.mid(0, str_count);
	QStringList toolNames;
	toolNames.reserve(100);
	toolNames.clear();
	toolNames << "全局变量" << "获取图像" << "图像显示" << "导出图像" << "预处理" << "图像拼接" << "图像修复" << "图像细化" << "图像翻转" << "图像旋转" << "透视变换" << "裁切图像" << "创建ROI" << "条形码识别" << "斑点分析" << "二维码识别"
		<< "字符识别" << "分类器" << "颜色识别" << "亮度检测" << "图像清晰度" << "轮廓特征选择" << "N点标定" << "畸变标定" << "测量标定" << "灰度匹配" << "形状匹配" << "目标跟踪" << "线性计算" << "寻找圆" << "寻找直线" << "拟合圆" << "拟合椭圆" << "拟合直线" << "获取边界点"
		<< "线圆交点" << "点+点" << "点+线" << "线线交点" << "查找圆缺角" << "边缘宽度测量" << "拟合平面" << "扩展库" << "跳转语句" << "判断语句" << "结束语句" << "脚本编辑" << "TCP/IP服务器" << "TCP/IP客户端" << "PLC通信" << "串口通信" << "通用I/O" << "延时" << "导出CSV" << "YoloV" << "OCR" << "二维码生成" << "自动打印";
	//清空Table
	int rowNum = ui.tableWidget->rowCount();
	for (int i = rowNum - 1; i >= 0; i--)
	{
		ui.tableWidget->removeRow(i);
	}
	switch (toolNames.indexOf(str_name_buf)) {
#pragma region 全局变量
	case 0:
		//全局变量		
		g_keys.reserve(300);
		g_keys.clear();
		g_keys = gVariable::global_variable_link.uniqueKeys();
		row_count = g_keys.length();
		ui.tableWidget->setRowCount(row_count);  //设置行数	
		for (int k = 0; k < row_count; k++)
		{
			QString key = g_keys[k];
			item_number = new QTableWidgetItem(QString::number(k + 1));
			item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			item_number->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(k, 0, item_number);
			if (gVariable::global_variable_link.value(key).global_type == "Int")
			{
				item_variable_name = new QTableWidgetItem(key);
				item_variable_value = new QTableWidgetItem(QString::number(gVariable::global_variable_link.value(key).global_int_value));
				item_variable_type = new QTableWidgetItem("Int");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Double")
			{
				item_variable_name = new QTableWidgetItem(key);
				item_variable_value = new QTableWidgetItem(QString::number(gVariable::global_variable_link.value(key).global_double_value));
				item_variable_type = new QTableWidgetItem("Double");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "QString")
			{
				item_variable_name = new QTableWidgetItem(key);
				item_variable_value = new QTableWidgetItem(gVariable::global_variable_link.value(key).global_qstring_value);
				item_variable_type = new QTableWidgetItem("QString");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Bool")
			{
				item_variable_name = new QTableWidgetItem(key);
				bool g_state = gVariable::global_variable_link.value(key).global_bool_value;
				if (g_state == true)
				{
					item_variable_value = new QTableWidgetItem("true");
				}
				else
				{
					item_variable_value = new QTableWidgetItem("false");
				}
				item_variable_type = new QTableWidgetItem("Bool");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "QPoint")
			{
				item_variable_name = new QTableWidgetItem(key);
				QPoint g_point = gVariable::global_variable_link.value(key).global_qpoint_value;
				QString item_value = "(" + QString::number(g_point.x()) + "," + QString::number(g_point.y()) + ")";
				item_variable_value = new QTableWidgetItem(item_value);
				item_variable_type = new QTableWidgetItem("QPoint");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "QPointF")
			{
				item_variable_name = new QTableWidgetItem(key);
				QPointF g_pointf = gVariable::global_variable_link.value(key).global_qpointf_value;
				QString item_value = "(" + QString::number(g_pointf.x()) + "," + QString::number(g_pointf.y()) + ")";
				item_variable_value = new QTableWidgetItem(item_value);
				item_variable_type = new QTableWidgetItem("QPointF");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point")
			{
				item_variable_name = new QTableWidgetItem(key);
				cv::Point g_cvpoint = gVariable::global_variable_link.value(key).global_cvpoint_value;
				QString item_value = "(" + QString::number(g_cvpoint.x) + "," + QString::number(g_cvpoint.y) + ")";
				item_variable_value = new QTableWidgetItem(item_value);
				item_variable_type = new QTableWidgetItem("cv::Point");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point2f")
			{
				item_variable_name = new QTableWidgetItem(key);
				cv::Point2f g_cvpoint2f = gVariable::global_variable_link.value(key).global_cvpoint2f_value;
				QString item_value = "(" + QString::number(g_cvpoint2f.x) + "," + QString::number(g_cvpoint2f.y) + ")";
				item_variable_value = new QTableWidgetItem(item_value);
				item_variable_type = new QTableWidgetItem("cv::Point2f");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point3f")
			{
				item_variable_name = new QTableWidgetItem(key);
				cv::Point3f g_cvpoint3f = gVariable::global_variable_link.value(key).global_cvpoint3f_value;
				QString item_value = "(" + QString::number(g_cvpoint3f.x) + "," + QString::number(g_cvpoint3f.y) + "," + QString::number(g_cvpoint3f.z) + ")";
				item_variable_value = new QTableWidgetItem(item_value);
				item_variable_type = new QTableWidgetItem("cv::Point3f");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "cv::Point3d")
			{
				item_variable_name = new QTableWidgetItem(key);
				cv::Point3d g_cvpoint3d = gVariable::global_variable_link.value(key).global_cvpoint3d_value;
				QString item_value = "(" + QString::number(g_cvpoint3d.x) + "," + QString::number(g_cvpoint3d.y) + "," + QString::number(g_cvpoint3d.z) + ")";
				item_variable_value = new QTableWidgetItem(item_value);
				item_variable_type = new QTableWidgetItem("cv::Point3d");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Float[]")
			{
				item_variable_name = new QTableWidgetItem(key);
				vector<float> g_array_float = gVariable::global_variable_link.value(key).global_array_float_value;
				QString item_value;
				for (int n = 0; n < g_array_float.size(); n++)
				{
					if (n == 0)
					{
						item_value = "{" + QString::number(g_array_float[n]) + ",";
					}
					if (n > 0 && n <= g_array_float.size() - 2)
					{
						item_value = item_value + QString::number(g_array_float[n]) + ",";
					}
					if (n == g_array_float.size() - 1)
					{
						item_value = item_value + QString::number(g_array_float[n]) + "}";
					}
				}
				item_variable_value = new QTableWidgetItem(item_value);
				item_variable_type = new QTableWidgetItem("Float[]");
			}
			else if (gVariable::global_variable_link.value(key).global_type == "Double[]")
			{
				item_variable_name = new QTableWidgetItem(key);
				vector<double> g_array_double = gVariable::global_variable_link.value(key).global_array_double_value;
				QString item_value;
				for (int n = 0; n < g_array_double.size(); n++)
				{
					if (n == 0)
					{
						item_value = "{" + QString::number(g_array_double[n]) + ",";
					}
					if (n > 0 && n <= g_array_double.size() - 2)
					{
						item_value = item_value + QString::number(g_array_double[n]) + ",";
					}
					if (n == g_array_double.size() - 1)
					{
						item_value = item_value + QString::number(g_array_double[n]) + "}";
					}
				}
				item_variable_value = new QTableWidgetItem(item_value);
				item_variable_type = new QTableWidgetItem("Double[]");
			}
			item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			item_variable_name->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(k, 1, item_variable_name);
			item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			item_variable_value->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(k, 2, item_variable_value);
			item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
			item_variable_type->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(k, 3, item_variable_type);
		}
		break;
#pragma endregion

#pragma region 图像处理
	case 1:
		//获取图像		
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 2:
		//图像显示		
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 3:
		//导出图像		
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 4:
		//预处理		
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 5:
		//图像拼接		
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 6:
		//图像修复
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 7:
		//图像细化
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 8:
		//图像翻转
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 9:
		//图像旋转
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 10:
		//透视变换
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 11:
		//裁切图像
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 12:
		//创建ROI
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 检测识别
	case 13:
		//条形码识别
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".条形码");
						item_variable_value = new QTableWidgetItem("PublicDetect.Code");
						item_variable_type = new QTableWidgetItem("vector<QString>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 14:
		//斑点分析		
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".斑点个数");
						item_variable_value = new QTableWidgetItem("PublicDetect.Quantity");
						item_variable_type = new QTableWidgetItem("Int");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 15:
		//二维码识别
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".二维码");
						item_variable_value = new QTableWidgetItem("PublicDetect.Code");
						item_variable_type = new QTableWidgetItem("vector<QString>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 16:
		//字符识别

		break;
	case 17:
		//分类器
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".类别");
						item_variable_value = new QTableWidgetItem("PublicDetect.Category");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 18:
		//颜色识别
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".相似度");
						item_variable_value = new QTableWidgetItem("PublicDetect.Score");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 19:
		//亮度检测
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".亮度");
						item_variable_value = new QTableWidgetItem("PublicDetect.Brightness");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 20:
		//图像清晰度
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".清晰度");
						item_variable_value = new QTableWidgetItem("PublicDetect.Clarity");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 21:
		//轮廓特征选择
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".面积");
						item_variable_value = new QTableWidgetItem("PublicDetect.Areas");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".重心");
						item_variable_value = new QTableWidgetItem("PublicDetect.CenterPoints");
						item_variable_type = new QTableWidgetItem("vector<cv::Point2f>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 标定工具
	case 22:
		//N点标定
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(8);  //设置行数	
				for (int k = 0; k < 8; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".N点标定参数");
						item_variable_value = new QTableWidgetItem("PublicCalib.EstimateAffine");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".旋转中心");
						item_variable_value = new QTableWidgetItem("PublicCalib.RotateCenter");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".像素当量X");
						item_variable_value = new QTableWidgetItem("PublicCalib.PixelEquivalentX");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".像素当量Y");
						item_variable_value = new QTableWidgetItem("PublicCalib.PixelEquivalentY");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".基准点1");
						item_variable_value = new QTableWidgetItem("PublicCalib.DatumPoint1");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 5:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".基准点2");
						item_variable_value = new QTableWidgetItem("PublicCalib.DatumPoint2");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 6:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".基准角度");
						item_variable_value = new QTableWidgetItem("PublicCalib.DatumAngle");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 7:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 23:
		//畸变标定
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 24:
		//测量标定
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".像素当量X");
						item_variable_value = new QTableWidgetItem("PublicCalib.PixelEquivalentX");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".像素当量Y");
						item_variable_value = new QTableWidgetItem("PublicCalib.PixelEquivalentY");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 对位工具
	case 25:
		//灰度匹配		
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(5);  //设置行数	
				for (int k = 0; k < 5; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".匹配中心坐标");
						item_variable_value = new QTableWidgetItem("PublicTPosition.Center");
						item_variable_type = new QTableWidgetItem("vector<cv::Point2f>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".匹配角度");
						item_variable_value = new QTableWidgetItem("PublicTPosition.Angle");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".匹配分数");
						item_variable_value = new QTableWidgetItem("PublicTPosition.OutScore");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".匹配基准中心");
						item_variable_value = new QTableWidgetItem("PublicTPosition.DatumCenter");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 26:
		//形状匹配		
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(5);  //设置行数	
				for (int k = 0; k < 5; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".匹配中心坐标");
						item_variable_value = new QTableWidgetItem("PublicTPosition.Center");
						item_variable_type = new QTableWidgetItem("vector<cv::Point2f>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".匹配角度");
						item_variable_value = new QTableWidgetItem("PublicTPosition.Angle");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".匹配分数");
						item_variable_value = new QTableWidgetItem("PublicTPosition.OutScore");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".匹配基准中心");
						item_variable_value = new QTableWidgetItem("PublicTPosition.DatumCenter");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 27:
		//目标跟踪
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 28:
		//线性计算
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".移动量X");
						item_variable_value = new QTableWidgetItem("PublicTPosition.MovingDistanceX");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".移动量Y");
						item_variable_value = new QTableWidgetItem("PublicTPosition.MovingDistanceY");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".世界坐标点");
						item_variable_value = new QTableWidgetItem("PublicTPosition.WorldCoordinatePoint");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 几何工具/测量
	case 29:
		//寻找圆
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".中心坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Center");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".半径");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Radius");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 30:
		//寻找直线
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".斜率");
						item_variable_value = new QTableWidgetItem("PublicGeometry.k");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".截距");
						item_variable_value = new QTableWidgetItem("PublicGeometry.b");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 31:
		//拟合圆
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".中心坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Center");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".半径");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Radius");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 32:
		//拟合椭圆
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(5);  //设置行数	
				for (int k = 0; k < 5; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".中心坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Center");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".角度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Angle");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".长轴长度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Length1");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".短轴长度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Length2");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 4:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 33:
		//拟合直线
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".斜率");
						item_variable_value = new QTableWidgetItem("PublicGeometry.k");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".截距");
						item_variable_value = new QTableWidgetItem("PublicGeometry.b");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 34:
		//获取边界点
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".点集");
						item_variable_value = new QTableWidgetItem("PublicGeometry.BorderPoints");
						item_variable_type = new QTableWidgetItem("vector<cv::Point2f>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 35:
		//线圆交点
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".交点坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Intersections");
						item_variable_type = new QTableWidgetItem("vector<cv::Point2f>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 36:
		//点+点	
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".中心坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Center");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".角度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Angle");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".距离");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Distance");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 37:
		//点+线
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".垂足坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Pedal");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".距离");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Distance");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 38:
		//线线交点
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".交点坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Intersection");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".夹角");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Angle");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 39:
		//查找圆缺角
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(4);  //设置行数	
				for (int k = 0; k < 4; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".圆心坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Center");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".垂足坐标");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Pedal");
						item_variable_type = new QTableWidgetItem("cv::Point2f");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".角度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Angle");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 3:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 40:
		//边缘宽度测量
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".边缘宽度");
						item_variable_value = new QTableWidgetItem("PublicGeometry.Distance");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 三维检测
	case 41:
		//拟合平面
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".平面参数");
						item_variable_value = new QTableWidgetItem("PublicThreeD.Flatness");
						item_variable_type = new QTableWidgetItem("vector<Double>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".点到平面距离");
						item_variable_value = new QTableWidgetItem("PublicThreeD.Distance");
						item_variable_type = new QTableWidgetItem("Double");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 逻辑工具
	case 42:
		//扩展库		
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 43:
		//跳转语句
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 44:
		//判断语句
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 45:
		//结束语句
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 46:
		//脚本编辑
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 通讯工具
	case 47:
		//TCP/IP服务器
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".接收数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.InputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".发送数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.OutputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 48:
		//TCP/IP客户端
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".接收数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.InputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".发送数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.OutputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 49:
		//PLC通信
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".寄存器读取数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.RegisterReadData");
						item_variable_type = new QTableWidgetItem("QVector<int>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".寄存器写入数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.RegisterWriteData");
						item_variable_type = new QTableWidgetItem("QVector<int>");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 50:
		//串口通信
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(3);  //设置行数	
				for (int k = 0; k < 3; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".接收数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.InputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".发送数据");
						item_variable_value = new QTableWidgetItem("PublicCommunication.OutputData");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 2:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 51:
		//通用I/O
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".输入点");
						item_variable_value = new QTableWidgetItem("PublicCommunication.InPutIoX");
						item_variable_type = new QTableWidgetItem("QVector<Bool>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

#pragma region 系统工具
	case 52:
		//延时		
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 53:
		//导出CSV
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(1);  //设置行数	
				for (int k = 0; k < 1; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 54:
		//YoloV13
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".类别");
						item_variable_value = new QTableWidgetItem("PublicDetect.Category");
						item_variable_type = new QTableWidgetItem("QString");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 55:
		//OCR识别
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".识别内容");
						item_variable_value = new QTableWidgetItem("PublicDetect.Code");
						item_variable_type = new QTableWidgetItem("vector<QString>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 56:
		//二维码生成
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".二维码");
						item_variable_value = new QTableWidgetItem("PublicDetect.Code");
						item_variable_type = new QTableWidgetItem("vector<QString>");
						break;
					case 1:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
	case 57:
		//自动打印
		for (int j = 0; j < GetToolBase()->m_Tools.size(); j++)
		{
			QString toolName;
			toolName = GetToolBase()->m_Tools[j].PublicToolName;
			if (tool_name == toolName)
			{
				ui.tableWidget->setRowCount(2);  //设置行数	
				for (int k = 0; k < 2; k++)
				{
					item_number = new QTableWidgetItem(QString::number(k + 1));
					item_number->setFlags(item_number->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_number->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 0, item_number);
					switch (k) {
					/*case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".二维码");
						item_variable_value = new QTableWidgetItem("PublicDetect.Code");
						item_variable_type = new QTableWidgetItem("vector<QString>");
						break;*/
					case 0:
						item_variable_name = new QTableWidgetItem(GetToolBase()->m_Tools[j].PublicToolName + ".状态");
						item_variable_value = new QTableWidgetItem("PublicResult.State");
						item_variable_type = new QTableWidgetItem("Bool");
						break;
					}
					item_variable_name->setFlags(item_variable_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_name->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 1, item_variable_name);
					item_variable_value->setFlags(item_variable_value->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_value->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 2, item_variable_value);
					item_variable_type->setFlags(item_variable_type->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
					item_variable_type->setTextAlignment(Qt::AlignCenter);
					ui.tableWidget->setItem(k, 3, item_variable_type);
				}
			}
		}
		break;
#pragma endregion

	}
}

void frmScriptEdit::slot_DoubleClicked(int row, int column)
{
	script_link = ui.tableWidget->item(row, 1)->text();
	if (ui.listProcess->currentIndex().row() == 0)
	{
		QString str_fun = "ProjectGetGlobalValue(\"" + script_link + "\");\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else
	{
		QString str_fun = "GetFlowToolValue(\"" + script_link + "\");" + "\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
}

int frmScriptEdit::Execute(const QString toolname)
{
	//加锁
	static QMutex mutex;
	QMutexLocker locker(&mutex);
	for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
	{
		if (GetToolBase()->m_Tools[i].PublicToolName == toolname)
		{
			//工具在工具数组中的索引
			tool_index = i;
		}
	}
	int result = RunToolPro();
	if (result == -1)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
	else if (result == -2)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -2;
	}
	return 0;
}

int frmScriptEdit::RunToolPro()
{	
	try
	{
		script_keys.reserve(300);
		script_keys.clear();
		script_keys = gvariable.scriptedit_variable_link.uniqueKeys();
		for (int k = 0; k < script_keys.length(); k++)
		{
			if (script_keys[k] = GetToolBase());
			{				
				QConfig::g_flow_index = gvariable.scriptedit_variable_link.value(script_keys[k]).item_id;
			}
		}
		QString str_code = "(function(){" + ui.plainTextEdit->toPlainText() + "});";		
		QScriptValue fun_all = script_engine.evaluate(str_code);
		QScriptValue result = fun_all.call(QScriptValue());
		if (script_engine.hasUncaughtException())
		{
			emit sig_ScriptError(&script_engine, str_code, result);
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -2;
		}		
		if (QConfig::tool_result == -2)
		{							
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			QConfig::tool_result = 0;
			return -2;
		}	
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{		
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

void frmScriptEdit::slot_ScriptError(QScriptEngine* script_engine, QString str_code, QScriptValue result)
{
	ui.txtMsg->clear();
	QScriptSyntaxCheckResult check = script_engine->checkSyntax(str_code);
	QTextCharFormat fmt;
	fmt.setForeground(QColor(180, 0, 0));
	ui.txtMsg->mergeCurrentCharFormat(fmt);
	if (check.state() != QScriptSyntaxCheckResult::Valid)
	{
		QString error("Error on line %1 column %2\nMessage: %3");
		error = error.arg(QString::number(check.errorLineNumber()),
			QString::number(check.errorColumnNumber()), check.errorMessage());
		ui.txtMsg->append(">> 编译异常信息：" + error);
	}
	else
	{
		int errlinenumber = script_engine->uncaughtExceptionLineNumber();
		QString error("Error on line %1\nMessage: %2");
		error = error.arg(QString::number(errlinenumber), result.toString());
		ui.txtMsg->append(">> 编译异常信息：" + error);
	}	
}

int frmScriptEdit::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gVariable::global_variable_link = variable_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmScriptEdit::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
{
	try
	{
		gVariable::global_variable_link = g_variable_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmScriptEdit::ExecuteScriptEditLink(const QMap<QToolBase*, gVariable::ScriptEdit_Var> scriptedit_var_link)
{
	try
	{
		gvariable.scriptedit_variable_link = scriptedit_var_link;
		slot_CreateList();
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

void frmScriptEdit::slot_ItemDoubleClicked(QTreeWidgetItem* item, int column)
{
	if (item->text(0) == "设置全局变量值")
	{		
		QString str_fun = "ProjectSetGlobalValue(\"变量名\", \"值\");\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "获取当前时间")
	{
		QString str_fun = "GetCurrentTime()";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "GetArraySize")
	{
		QString str_fun = "GetArraySize(Array);\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "ConvertToPoint")
	{
		QString str_fun = "ConvertToPoint(Point, \"x\");\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "ConvertToPoint2f")
	{
		QString str_fun = "ConvertToPoint2f(Point2f, \"x\");\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "ConvertToPoint3f")
	{
		QString str_fun = "ConvertToPoint3f(Point3f, \"x\");\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "ConvertToPoint3d")
	{
		QString str_fun = "ConvertToPoint3d(Point3d, \"x\");\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "ConvertToArrayInt")
	{
		QString str_fun = "ConvertToArrayInt(ArrayInt, 0);\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "ConvertToArrayBool")
	{
		QString str_fun = "ConvertToArrayBool(ArrayBool, 0);\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "ConvertToArrayFloat")
	{
		QString str_fun = "ConvertToArrayFloat(ArrayFloat, 0);\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "ConvertToArrayDouble")
	{
		QString str_fun = "ConvertToArrayDouble(ArrayDouble, 0);\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "ConvertToArrayQString")
	{
		QString str_fun = "ConvertToArrayQString(ArrayQString, 0);\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "ConvertToArrayCvPoint2f")
	{
		QString str_fun = "ConvertToArrayCvPoint2f(ArrayCvPoint2f, 0, \"x\");\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "LogInfo")
	{		
		QString str_fun = "LogInfo(\"内容\");\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "LogWarn")
	{		
		QString str_fun = "LogWarn(\"内容\");\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
	else if (item->text(0) == "LogError")
	{		
		QString str_fun = "LogError(\"内容\");\n";
		ui.plainTextEdit->insertPlainText(str_fun);
	}
}

void frmScriptEdit::on_btnCompile_clicked()
{	
	QString str_code = "(function(){" + ui.plainTextEdit->toPlainText() + "});";
	QScriptValue result = script_engine.evaluate(str_code);
	ui.txtMsg->clear();
	if (script_engine.hasUncaughtException())
	{
		QScriptSyntaxCheckResult check = script_engine.checkSyntax(str_code);
		QTextCharFormat fmt;
		fmt.setForeground(QColor(180, 0, 0));
		ui.txtMsg->mergeCurrentCharFormat(fmt);
		if (check.state() != QScriptSyntaxCheckResult::Valid)
		{
			QString error("Error on line %1 column %2\nMessage: %3");
			error = error.arg(QString::number(check.errorLineNumber()),
				QString::number(check.errorColumnNumber()), check.errorMessage());
			ui.txtMsg->append(">> 编译异常信息：" + error);
		}
		else
		{
			int errlinenumber = script_engine.uncaughtExceptionLineNumber();
			QString error("Error on line %1\nMessage: %2");
			error = error.arg(QString::number(errlinenumber), result.toString());
			ui.txtMsg->append(">> 编译异常信息：" + error);
		}		
	}
	else
	{		
		QTextCharFormat fmt;
		fmt.setForeground(QColor(0, 150, 0));
		ui.txtMsg->mergeCurrentCharFormat(fmt);
		ui.txtMsg->append(">> 编译正常！");
	}
}

void frmScriptEdit::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	slot_CreateList();
	ui.btnExecute->setEnabled(true);
}

IconHelpers* IconHelpers::self = NULL;
IconHelpers* IconHelpers::Instance()
{
	if (!self)
	{
		QMutex mutex;
		QMutexLocker locker(&mutex);
		if (!self)
		{
			self = new IconHelpers;
		}
	}
	return self;
}

IconHelpers::IconHelpers(QObject*) : QObject(qApp)
{
}

QPixmap IconHelpers::getPixmap(QString& fileName)
{
	QPixmap pix = QPixmap(fileName);
	return pix;
}

//全局变量控制
QToolBase* QConfig::flowToolBase_B1 = nullptr;
QToolBase* QConfig::flowToolBase_B2 = nullptr;
QToolBase* QConfig::flowToolBase_B3 = nullptr;
QToolBase* QConfig::flowToolBase_B4 = nullptr;
QToolBase* QConfig::flowToolBase_B5 = nullptr;
QToolBase* QConfig::flowToolBase_B6 = nullptr;
QToolBase* QConfig::flowToolBase_B7 = nullptr;
QToolBase* QConfig::flowToolBase_B8 = nullptr;
QToolBase* QConfig::flowToolBase_B9 = nullptr;
QToolBase* QConfig::flowToolBase_B10 = nullptr;
QToolBase* QConfig::flowToolBase_B11 = nullptr;
QToolBase* QConfig::flowToolBase_B12 = nullptr;
QToolBase* QConfig::flowToolBase_B13 = nullptr;
QToolBase* QConfig::flowToolBase_B14 = nullptr;
QToolBase* QConfig::flowToolBase_B15 = nullptr;
QToolBase* QConfig::flowToolBase_B16 = nullptr;
QToolBase* QConfig::flowToolBase_B17 = nullptr;
QToolBase* QConfig::flowToolBase_B18 = nullptr;
QToolBase* QConfig::flowToolBase_B19 = nullptr;
QToolBase* QConfig::flowToolBase_B20 = nullptr;
int QConfig::tool_result = 0;
int QConfig::g_flow_index = 0;
