#include "frmLinearCalculation.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPainter>
#include <QGraphicsOpacityEffect>

#define M_PI 3.14159265358979323846

frmLinearCalculation::frmLinearCalculation(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/affine.png"));
	//初始化标题栏
	initTitleBar();
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmLinearCalculation::~frmLinearCalculation()
{
	this->deleteLater();
}

void frmLinearCalculation::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/affine.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmLinearCalculation::paintEvent(QPaintEvent* event)
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

void frmLinearCalculation::onButtonCloseClicked()
{
	this->close();
}

void frmLinearCalculation::on_comboMethod_currentIndexChanged(int index)
{
	switch (index) {
	case 0:
		ui.stackedWidget->setCurrentIndex(0);
		ui.checkUseERTCalib->setChecked(false);
		ui.btnLinkERTCalib->setEnabled(false);
		ui.btnDelLinkERTCalib->setEnabled(false);
		break;
	case 1:
		ui.stackedWidget->setCurrentIndex(1);
		ui.checkUseERTCalib->setChecked(false);
		ui.btnLinkERTCalib->setEnabled(false);
		ui.btnDelLinkERTCalib->setEnabled(false);
		break;
	case 2:
		ui.stackedWidget->setCurrentIndex(2);
		ui.checkUseERTCalib->setChecked(true);
		ui.btnLinkERTCalib->setEnabled(true);
		ui.btnDelLinkERTCalib->setEnabled(true);
		break;
	}
}

int frmLinearCalculation::Execute(const QString toolname)
{	
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
		return -1;
	}
	return 0;
}

int frmLinearCalculation::RunToolPro()
{
	try
	{
		EstimateAffine.clear();
		method_npoint_buf = 0;
		method1_point_buf1 = 0;
		method1_point_buf2 = 0;
		method1_point_buf3 = 0;
		method1_angle_buf = 0;
		method2_point_buf1 = 0;
		method2_point_buf2 = 0;
		method2_point_buf3 = 0;
		method2_angle_buf = 0;
		method3_point_buf = 0;
		WorldCoordinatePoint = cv::Point2f(0, 0);
		MovingDistanceX = 0;
		MovingDistanceY = 0;
		value_keys.reserve(300);
		value_keys.clear();
		value_keys = gvariable.global_variable_link.uniqueKeys();
		//使用全局变量
		for (int k = 0; k < value_keys.length(); k++)
		{
			QString key = value_keys[k];
			if (gvariable.global_variable_link.value(key).global_type == "Double[]")
			{
				if (key == ui.txtLinkERTCalib->text())
				{
					EstimateAffine = gvariable.global_variable_link.value(key).global_array_double_value;
					method_npoint_buf = 1;
				}
			}
			else if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
			{
				if (key == ui.txtLinkRotateCenter->text())
				{
					method1_p1f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
					method1_point_buf1 = 1;
				}
				if (key == ui.txtLinkDatumPoint->text())
				{
					method1_p2f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
					method1_point_buf2 = 1;
				}
				if (key == ui.txtLinkCurrentPoint->text())
				{
					method1_p3f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
					method1_point_buf3 = 1;
				}
				if (key == ui.txtLinkDatumPoint1->text())
				{
					method2_p1f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
					method2_point_buf1 = 1;
				}
				if (key == ui.txtLinkDatumPoint2->text())
				{
					method2_p2f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
					method2_point_buf2 = 1;
				}
				if (key == ui.txtLinkCurrentPoint1->text())
				{
					method2_p3f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
					method2_point_buf3 = 1;
				}
				if (key == ui.txtLinkImagePoint->text())
				{
					method3_pf = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
					method3_point_buf = 1;
				}
			}
			else if (gvariable.global_variable_link.value(key).global_type == "Double")
			{
				if (key == ui.txtLinkRotateAngle->text())
				{
					method1_angle = gvariable.global_variable_link.value(key).global_double_value;
					method1_angle_buf = 1;
				}
				if (key == ui.txtLinkRotateAngle1->text())
				{
					method2_angle = gvariable.global_variable_link.value(key).global_double_value;
					method2_angle_buf = 1;
				}
			}
		}
		//使用工具变量
		if (method_npoint_buf != 1)
		{
			int calc_index = 0;
			strs.clear();
			strs = ui.txtLinkERTCalib->text().split(".");
			if (strs.size() == 1)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
			bool link_state = false;
			for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
			{
				if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
				{
					calc_index = i;
					link_state = true;
				}
			}
			if (link_state == false)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -2;
			}
			if (strs[1] == "N点标定参数")
			{
				EstimateAffine = GetToolBase()->m_Tools[calc_index].PublicCalib.EstimateAffine;
			}
			else
			{
				EstimateAffine = { 0 };
			}
		}
		if (method1_point_buf1 != 1 || method1_point_buf2 != 1 || method1_point_buf3 != 1 || method2_point_buf1 != 1 || method2_point_buf2 != 1 || method2_point_buf3 != 1 || method3_point_buf != 1)
		{
			int calc_index = 0;
			if (method1_point_buf1 != 1)
			{
				strs.clear();
				strs = ui.txtLinkRotateCenter->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				bool link_state = false;
				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
				{
					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
					{
						calc_index = i;
						link_state = true;
					}
				}
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "旋转中心")
				{
					method1_p1f = GetToolBase()->m_Tools[calc_index].PublicCalib.RotateCenter;
				}
				else
				{
					method1_p1f = cv::Point2f(0, 0);
				}
			}
			if (method1_point_buf2 != 1)
			{
				strs.clear();
				strs = ui.txtLinkDatumPoint->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				bool link_state = false;
				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
				{
					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
					{
						calc_index = i;
						link_state = true;
					}
				}
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "基准点1")
				{
					method1_p2f = GetToolBase()->m_Tools[calc_index].PublicCalib.DatumPoint1;
				}
				else
				{
					method1_p2f = cv::Point2f(0, 0);
				}
			}
			if (method1_point_buf3 != 1)
			{
				strs.clear();
				strs = ui.txtLinkCurrentPoint->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				bool link_state = false;
				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
				{
					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
					{
						calc_index = i;
						link_state = true;
					}
				}
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "匹配中心坐标")
				{
					method1_p3f = GetToolBase()->m_Tools[calc_index].PublicTPosition.Center[0];
				}
				else if (strs[1] == "中心坐标")
				{
					method1_p3f = GetToolBase()->m_Tools[calc_index].PublicGeometry.Center;
				}
				else if (strs[1] == "交点")
				{
					method1_p3f = GetToolBase()->m_Tools[calc_index].PublicGeometry.Intersection;
				}
				else
				{
					method1_p3f = cv::Point2f(0, 0);
				}
			}
			if (method2_point_buf1 != 1)
			{
				strs.clear();
				strs = ui.txtLinkDatumPoint1->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				bool link_state = false;
				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
				{
					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
					{
						calc_index = i;
						link_state = true;
					}
				}
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "基准点1")
				{
					method2_p1f = GetToolBase()->m_Tools[calc_index].PublicCalib.DatumPoint1;
				}
				else
				{
					method2_p1f = cv::Point2f(0, 0);
				}
			}
			if (method2_point_buf2 != 1)
			{
				strs.clear();
				strs = ui.txtLinkDatumPoint2->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				bool link_state = false;
				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
				{
					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
					{
						calc_index = i;
						link_state = true;
					}
				}
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "基准点2")
				{
					method2_p2f = GetToolBase()->m_Tools[calc_index].PublicCalib.DatumPoint2;
				}
				else
				{
					method2_p2f = cv::Point2f(0, 0);
				}
			}
			if (method2_point_buf3 != 1)
			{
				strs.clear();
				strs = ui.txtLinkCurrentPoint1->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				bool link_state = false;
				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
				{
					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
					{
						calc_index = i;
						link_state = true;
					}
				}
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "匹配中心坐标")
				{
					method2_p3f = GetToolBase()->m_Tools[calc_index].PublicTPosition.Center[0];
				}
				else if (strs[1] == "中心坐标")
				{
					method2_p3f = GetToolBase()->m_Tools[calc_index].PublicGeometry.Center;
				}
				else if (strs[1] == "交点")
				{
					method2_p3f = GetToolBase()->m_Tools[calc_index].PublicGeometry.Intersection;
				}
				else
				{
					method2_p3f = cv::Point2f(0, 0);
				}
			}
			if (method3_point_buf != 1)
			{
				strs.clear();
				strs = ui.txtLinkImagePoint->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				bool link_state = false;
				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
				{
					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
					{
						calc_index = i;
						link_state = true;
					}
				}
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "匹配中心坐标")
				{
					method3_pf = GetToolBase()->m_Tools[calc_index].PublicTPosition.Center[0];
				}
				else if (strs[1] == "中心坐标")
				{
					method3_pf = GetToolBase()->m_Tools[calc_index].PublicGeometry.Center;
				}
				else if (strs[1] == "交点")
				{
					method3_pf = GetToolBase()->m_Tools[calc_index].PublicGeometry.Intersection;
				}
				else
				{
					method3_pf = cv::Point2f(0, 0);
				}
			}
		}
		if (method1_angle_buf != 1 || method2_angle_buf != 1)
		{
			int calc_index = 0;
			if (method1_angle_buf != 1)
			{
				strs.clear();
				strs = ui.txtLinkRotateAngle->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				bool link_state = false;
				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
				{
					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
					{
						calc_index = i;
						link_state = true;
					}
				}
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "角度")
				{
					method1_angle = GetToolBase()->m_Tools[calc_index].PublicGeometry.Angle;
				}
				else if (strs[1] == "匹配角度")
				{
					method1_angle = GetToolBase()->m_Tools[calc_index].PublicTPosition.Angle[0];
				}
				else
				{
					method1_angle = 0;
				}
			}
			if (method2_angle_buf != 1)
			{
				strs.clear();
				strs = ui.txtLinkRotateAngle1->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				bool link_state = false;
				for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
				{
					if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
					{
						calc_index = i;
						link_state = true;
					}
				}
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "角度")
				{
					method2_angle = GetToolBase()->m_Tools[calc_index].PublicGeometry.Angle;
				}
				else if (strs[1] == "匹配角度")
				{
					method2_angle = GetToolBase()->m_Tools[calc_index].PublicTPosition.Angle[0];
				}
				else
				{
					method2_angle = 0;
				}
			}
		}
		switch (ui.comboMethod->currentIndex()) {
		case 0:
			CalcMoveDisUseRC(method1_p1f.x, method1_p1f.y, method1_p2f.x, method1_p2f.y, method1_p3f.x, method1_p3f.y, method1_angle, MovingDistanceX, MovingDistanceY);
			break;
		case 1:
			CalcMoveDisNoUseRC(method2_p1f.x, method2_p1f.y, method2_p2f.x, method2_p2f.y, method2_p3f.x, method2_p3f.y, method2_angle, MovingDistanceX, MovingDistanceY);
			break;
		case 2:
			WorldCoordinatePoint = ImageC_To_MachineC(method3_pf, EstimateAffine[0], EstimateAffine[1], EstimateAffine[2], EstimateAffine[3], EstimateAffine[4], EstimateAffine[5]);
			break;
		}
		GetToolBase()->m_Tools[tool_index].PublicTPosition.MovingDistanceX = MovingDistanceX;
		GetToolBase()->m_Tools[tool_index].PublicTPosition.MovingDistanceY = MovingDistanceY;
		GetToolBase()->m_Tools[tool_index].PublicTPosition.WorldCoordinatePoint = WorldCoordinatePoint;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmLinearCalculation::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		if (int_link == 1)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 1 || strs[1] != "N点标定参数")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			ui.txtLinkERTCalib->setText(str_link);
		}
		else if (int_link == 2)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && strs[1] != "旋转中心")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtLinkRotateCenter->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 3)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && strs[1] != "基准点1")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtLinkDatumPoint->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 4)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && (strs[1] != "匹配中心坐标" && strs[1] != "中心坐标" && strs[1] != "交点"))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtLinkCurrentPoint->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 5)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && (strs[1] != "角度" && strs[1] != "匹配角度"))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "Double")
				{
					if (key == str_link)
					{
						ui.txtLinkRotateAngle->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 6)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && strs[1] != "基准点1")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtLinkDatumPoint1->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 7)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && strs[1] != "基准点2")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtLinkDatumPoint2->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 8)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && (strs[1] != "匹配中心坐标" && strs[1] != "中心坐标" && strs[1] != "交点"))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtLinkCurrentPoint1->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 9)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && (strs[1] != "角度" && strs[1] != "匹配角度"))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "Double")
				{
					if (key == str_link)
					{
						ui.txtLinkRotateAngle1->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		else if (int_link == 10)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && (strs[1] != "匹配中心坐标" && strs[1] != "中心坐标" && strs[1] != "交点"))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtLinkImagePoint->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}			
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmLinearCalculation::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
{
	try
	{
		gvariable.global_variable_link = g_variable_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

void frmLinearCalculation::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.txtMsg->clear();
	switch (ui.comboMethod->currentIndex()) {
	case 0:
		ui.txtMsg->append("-> Robot移动量X为：" + QString::number(MovingDistanceX));
		ui.txtMsg->append("-> Robot移动量Y为：" + QString::number(MovingDistanceY));
		break;
	case 1:
		ui.txtMsg->append("-> Robot移动量X为：" + QString::number(MovingDistanceX));
		ui.txtMsg->append("-> Robot移动量Y为：" + QString::number(MovingDistanceY));
		break;
	case 2:
		ui.txtMsg->append("-> 世界坐标点为：" + QString::number(WorldCoordinatePoint.x) + "," + QString::number(WorldCoordinatePoint.y));
		break;
	}
	ui.btnExecute->setEnabled(true);
}

void frmLinearCalculation::on_btnLinkERTCalib_clicked()
{
	QConfig::nFormState = 1;
}

void frmLinearCalculation::on_btnDelLinkERTCalib_clicked()
{
	ui.txtLinkERTCalib->clear();
}

void frmLinearCalculation::on_btnLinkRotateCenter_clicked()
{
	QConfig::nFormState = 2;
}

void frmLinearCalculation::on_btnDelLinkRotateCenter_clicked()
{
	ui.txtLinkRotateCenter->clear();
}

void frmLinearCalculation::on_btnLinkDatumPoint_clicked()
{
	QConfig::nFormState = 3;
}

void frmLinearCalculation::on_btnDelLinkDatumPoint_clicked()
{
	ui.txtLinkDatumPoint->clear();
}

void frmLinearCalculation::on_btnLinkCurrentPoint_clicked()
{
	QConfig::nFormState = 4;
}

void frmLinearCalculation::on_btnDelLinkCurrentPoint_clicked()
{
	ui.txtLinkCurrentPoint->clear();
}

void frmLinearCalculation::on_btnLinkRotateAngle_clicked()
{
	QConfig::nFormState = 5;
}

void frmLinearCalculation::on_btnDelLinkRotateAngle_clicked()
{
	ui.txtLinkRotateAngle->clear();
}

void frmLinearCalculation::on_btnLinkDatumPoint1_clicked()
{
	QConfig::nFormState = 6;
}

void frmLinearCalculation::on_btnDelLinkDatumPoint1_clicked()
{
	ui.txtLinkDatumPoint1->clear();
}

void frmLinearCalculation::on_btnLinkDatumPoint2_clicked()
{
	QConfig::nFormState = 7;
}

void frmLinearCalculation::on_btnDelLinkDatumPoint2_clicked()
{
	ui.txtLinkDatumPoint2->clear();
}

void frmLinearCalculation::on_btnLinkCurrentPoint1_clicked()
{
	QConfig::nFormState = 8;
}

void frmLinearCalculation::on_btnDelLinkCurrentPoint1_clicked()
{
	ui.txtLinkCurrentPoint1->clear();
}

void frmLinearCalculation::on_btnLinkRotateAngle1_clicked()
{
	QConfig::nFormState = 9;
}

void frmLinearCalculation::on_btnDelLinkRotateAngle1_clicked()
{
	ui.txtLinkRotateAngle1->clear();
}

void frmLinearCalculation::on_btnLinkImagePoint_clicked()
{
	QConfig::nFormState = 10;
}

void frmLinearCalculation::on_btnDelLinkImagePoint_clicked()
{
	ui.txtLinkImagePoint->clear();
}

#pragma region 计算Robot移动量(使用旋转中心)
//CDx和CDy表示为了将机器人姿态调整到与训练时一致，需要的移动量
//(rx0,ry0)为标准的旋转中心，(X0,Y0)为标准的工件(Mark)坐标点，(X1,Y1)为工件移动后新的(Mark)坐标点，angle为旋转角度
//新的旋转中心：rx = rx0 + CDx; ry = ry0 + CDy
bool frmLinearCalculation::CalcMoveDisUseRC(const double rx0, const double ry0, const double X0, const double Y0, const double X1, const double Y1, const double angle, double& CDx, double& CDy)
{
	try
	{
		CDx = cos((M_PI / 180) * angle) * (rx0 - X0) - sin((M_PI / 180) * angle) * (ry0 - Y0) + X1 - rx0;
		CDy = cos((M_PI / 180) * angle) * (ry0 - Y0) + sin((M_PI / 180) * angle) * (rx0 - X0) + Y1 - ry0;
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

#pragma region 计算Robot移动量(不使用旋转中心)
//CDx和CDy表示为了将机器人姿态调整到与训练时一致，需要的移动量
//(X0,Y0)为标准的工件(Mark)坐标点，(X1,Y1)为旋转angle角度后的坐标点(与(X0,Y0)有相同的旋转中心)，(X2,Y2)为工件移动后新的(Mark)坐标点，angle为旋转角度
bool frmLinearCalculation::CalcMoveDisNoUseRC(const double X0, const double Y0, const double X1, const double Y1, const double X2, const double Y2, const double angle, double& CDx, double& CDy)
{
	try
	{
		double MDx = X1 - X0;
		double MDy = Y1 - Y0;
		double StDx = -0.5 * (MDx * (cos((M_PI / 180) * angle) - 1) + MDy * sin((M_PI / 180) * angle)) / (1 - cos((M_PI / 180) * angle));
		double StDy = 0.5 * (MDx * sin((M_PI / 180) * angle) - MDy * (cos((M_PI / 180) * angle) - 1)) / (1 - cos((M_PI / 180) * angle));
		double MDx_2 = X2 - X0;
		double MDy_2 = Y2 - Y0;
		CDx = (cos((M_PI / 180) * angle) - 1) * StDx - sin((M_PI / 180) * angle) * StDy + MDx_2;
		CDy = (cos((M_PI / 180) * angle) - 1) * StDy + sin((M_PI / 180) * angle) * StDx + MDy_2;
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

#pragma region 图像坐标转换为世界坐标
//图像坐标转换为世界坐标
cv::Point2f frmLinearCalculation::ImageC_To_MachineC(const cv::Point2f pPoint, const double A, const double B, const double C, const double D, const double E, const double F)
{
	try
	{
		cv::Point2f tPoint = cv::Point2f();
		tPoint.x = static_cast<float>(A * pPoint.x + B * pPoint.y + C);
		tPoint.y = static_cast<float>(D * pPoint.x + E * pPoint.y + F);
		return tPoint;
	}
	catch (...)
	{
		return cv::Point2f();
	}
}
#pragma endregion

//全局变量控制
int QConfig::nFormState = 0;
