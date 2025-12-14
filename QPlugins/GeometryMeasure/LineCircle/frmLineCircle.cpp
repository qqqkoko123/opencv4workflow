#include "frmLineCircle.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QGraphicsOpacityEffect>

frmLineCircle::frmLineCircle(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/line_circle.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//选项按钮
	btnGroupRadio = new QButtonGroup(this);
	btnGroupRadio->addButton(ui.radioPoints, 0);
	connect(ui.radioPoints, SIGNAL(toggled(bool)), this, SLOT(onRadioClick(bool)));
	btnGroupRadio->addButton(ui.radioTwoPoint, 1);
	connect(ui.radioTwoPoint, SIGNAL(toggled(bool)), this, SLOT(onRadioClick(bool)));
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmLineCircle::~frmLineCircle()
{
	this->deleteLater();
}

void frmLineCircle::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/line_circle.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmLineCircle::paintEvent(QPaintEvent* event)
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

void frmLineCircle::onButtonCloseClicked()
{
	this->close();
}

void frmLineCircle::onRadioClick(bool state)
{
	switch (btnGroupRadio->checkedId())
	{
	case 0:
		ui.stackedWidget->setCurrentIndex(0);
		break;
	case 1:
		ui.stackedWidget->setCurrentIndex(1);
		break;
	}
}

int frmLineCircle::Execute(const QString toolname)
{	
	bool link_state = false;
	image_index = 0;
	QString str = ui.txtLinkImage->text();
	strs.reserve(100);
	strs.clear();
	strs = str.split(".");
	if (strs.size() == 1)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
	for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
	{
		if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
		{
			//获取的图像在工具数组中的索引
			image_index = i;
			link_state = true;
		}
		if (GetToolBase()->m_Tools[i].PublicToolName == toolname)
		{
			//工具在工具数组中的索引
			tool_index = i;
		}
	}	
	if (link_state == false)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -2;
	}
	int result = RunToolPro();
	if (result == -1)
	{
		return -1;
	}
	return 0;
}

int frmLineCircle::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		k_buf = 0;
		b_buf = 0;
		point_buf1 = 0;
		point_buf2 = 0;
		circle_point_buf = 0;
		circle_radius_buf = 0;
		Intersections.clear();		
		point_keys.reserve(300);
		point_keys.clear();
		point_keys = gvariable.global_variable_link.uniqueKeys();
		//使用全局变量
		for (int p = 0; p < point_keys.length(); p++)
		{
			QString key = point_keys[p];			
			if (gvariable.global_variable_link.value(key).global_type == "cv::Point")
			{
				if (key == ui.txtLinkCircleCPoint->text())
				{
					cir_p = gvariable.global_variable_link.value(key).global_cvpoint_value;
					cir_pf.x = cir_p.x;
					cir_pf.y = cir_p.y;
					circle_point_buf = 1;
				}
				//直线两点方式
				if (ui.radioTwoPoint->isChecked() == true)
				{
					if (key == ui.txtLinkPoint1->text())
					{
						p1 = gvariable.global_variable_link.value(key).global_cvpoint_value;
						p1f.x = p1.x;
						p1f.y = p1.y;
						point_buf1 = 1;
					}
					if (key == ui.txtLinkPoint2->text())
					{
						p2 = gvariable.global_variable_link.value(key).global_cvpoint_value;
						p2f.x = p2.x;
						p2f.y = p2.y;
						point_buf2 = 1;
					}
				}
			}
			else if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
			{
				if (key == ui.txtLinkCircleCPoint->text())
				{
					cir_pf = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
					circle_point_buf = 1;
				}
				//直线两点方式
				if (ui.radioTwoPoint->isChecked() == true)
				{
					if (key == ui.txtLinkPoint1->text())
					{
						p1f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
						point_buf1 = 1;
					}
					if (key == ui.txtLinkPoint2->text())
					{
						p2f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
						point_buf2 = 1;
					}
				}
			}
			else if (gvariable.global_variable_link.value(key).global_type == "Double")
			{
				if (key == ui.txtLinkCircleRadius->text())
				{
					radius = gvariable.global_variable_link.value(key).global_double_value;
					circle_radius_buf = 1;
				}
				//直线斜率/截距方式
				if (ui.radioPoints->isChecked() == true)
				{
					if (key == ui.txtLinkLinek->text())
					{
						k = gvariable.global_variable_link.value(key).global_double_value;
						k_buf = 1;
					}
					if (key == ui.txtLinkLineb->text())
					{
						b = gvariable.global_variable_link.value(key).global_double_value;
						b_buf = 1;
					}
				}
			}
		}
		//使用工具变量
		if (circle_point_buf != 1 || point_buf1 != 1 || point_buf2 != 1)
		{
			int fit_index = 0;
			if (circle_point_buf != 1)
			{
				strs.clear();
				strs = ui.txtLinkCircleCPoint->text().split(".");
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
						fit_index = i;
						link_state = true;
					}
				}		
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "中心坐标")
				{
					cir_pf = GetToolBase()->m_Tools[fit_index].PublicGeometry.Center;
				}
				else if (strs[1] == "垂足坐标")
				{
					cir_pf = GetToolBase()->m_Tools[fit_index].PublicGeometry.Pedal;
				}
				else if (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")
				{
					cir_pf = GetToolBase()->m_Tools[fit_index].PublicGeometry.Intersection;
				}
				else
				{
					cir_pf = cv::Point2f(0, 0);
				}
			}
			if (ui.radioTwoPoint->isChecked() == true)
			{
				if (point_buf1 != 1)
				{
					strs.clear();
					strs = ui.txtLinkPoint1->text().split(".");
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
							fit_index = i;
							link_state = true;
						}
					}				
					if (link_state == false)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -2;
					}
					if (strs[1] == "中心坐标")
					{
						p1f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Center;
					}
					else if (strs[1] == "垂足坐标")
					{
						p1f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Pedal;
					}
					else if (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")
					{
						p1f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Intersection;
					}
					else
					{
						p1f = cv::Point2f(0, 0);
					}
				}
				if (point_buf2 != 1)
				{
					strs.clear();
					strs = ui.txtLinkPoint2->text().split(".");
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
							fit_index = i;
							link_state = true;
						}
					}		
					if (link_state == false)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -2;
					}
					if (strs[1] == "中心坐标")
					{
						p2f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Center;
					}
					else if (strs[1] == "垂足坐标")
					{
						p2f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Pedal;
					}
					else if (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")
					{
						p2f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Intersection;
					}
					else
					{
						p2f = cv::Point2f(0, 0);
					}
				}
			}
		}
		if (circle_radius_buf != 1 || k_buf != 1 || b_buf != 1)
		{
			int fit_index = 0;
			if (circle_radius_buf != 1)
			{
				strs.clear();
				strs = ui.txtLinkCircleRadius->text().split(".");
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
						fit_index = i;
						link_state = true;
					}
				}		
				if (link_state == false)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
				if (strs[1] == "距离")
				{
					radius = GetToolBase()->m_Tools[fit_index].PublicGeometry.Distance;
				}
				else if (strs[1] == "半径")
				{
					radius = GetToolBase()->m_Tools[fit_index].PublicGeometry.Radius;
				}
				else if (strs[1] == "长轴长度")
				{
					radius = GetToolBase()->m_Tools[fit_index].PublicGeometry.Length1;
				}
				else if (strs[1] == "短轴长度")
				{
					radius = GetToolBase()->m_Tools[fit_index].PublicGeometry.Length2;
				}
				else
				{
					radius = 0;
				}
			}
			if (ui.radioPoints->isChecked() == true)
			{
				if (k_buf != 1 || b_buf != 1)
				{					
					if (k_buf != 1)
					{
						strs.clear();
						strs = ui.txtLinkLinek->text().split(".");
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
								fit_index = i;
								link_state = true;
							}
						}	
						if (link_state == false)
						{
							GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
							return -2;
						}
						if (strs[1] == "斜率")
						{
							k = GetToolBase()->m_Tools[fit_index].PublicGeometry.k;
						}
						else
						{
							k = 0;
						}
					}
					if (b_buf != 1)
					{
						strs.clear();
						strs = ui.txtLinkLineb->text().split(".");
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
								fit_index = i;
								link_state = true;
							}
						}	
						if (link_state == false)
						{
							GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
							return -2;
						}
						if (strs[1] == "截距")
						{
							b = GetToolBase()->m_Tools[fit_index].PublicGeometry.b;
						}
						else
						{
							b = 0;
						}
					}
				}
			}
		}		
		if (dstImage.channels() == 1)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
		}
		else if (dstImage.channels() == 4)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
		}
		if (ui.radioPoints->isChecked() == true)
		{
			int x0 = 100;
			int y0 = k * x0 + b;
			int x1 = 200;
			int y1 = k * x1 + b;
			//参数
			cir_ellipse.a = radius;
			cir_ellipse.b = radius;
			cir_ellipse.angle = 360;
			cir_ellipse.center = cir_pf;
			cv::Point2f ipoint1 = cv::Point2f();	
			cv::Point2f ipoint2 = cv::Point2f();
			ipoint1 = FindIntersections(cir_ellipse, k, b, 1);	
			ipoint2 = FindIntersections(cir_ellipse, k, b, 0);
			if (ipoint1 != ipoint2)
			{
				Intersections.push_back(ipoint1);
				Intersections.push_back(ipoint2);				
			}
			else
			{
				if (ipoint1 != cv::Point2f())
				{
					double dis = CalcPPDist(cir_pf, ipoint1);
					if (dis - radius < 0.5)
					{
						Intersections.push_back(ipoint1);
					}					
				}			
			}			
			int w = srcImage.cols;
			int y_1 = int((-x0 * k) + y0);
			int y_2 = int((w - x0) * k + y0);
			cv::line(dstImage, cv::Point((w - 1), y_2), cv::Point(0, y_1), cv::Scalar(10, 255, 255), 1);
			cv::circle(dstImage, cir_pf, radius, cv::Scalar(255, 10, 10), 1);
			for (int n = 0; n < Intersections.size(); n++)
			{
				cv::circle(dstImage, Intersections[n], 5, cv::Scalar(10, 255, 10), -1);
			}		
		}
		else
		{
			double k_convert = 0, b_convert = 0;
			k_convert = (p1f.y - p2f.y) / (p1f.x - p2f.x);
			b_convert = p1f.y - k_convert * p1f.x;
			//参数
			cir_ellipse.a = radius;
			cir_ellipse.b = radius;
			cir_ellipse.angle = 360;
			cir_ellipse.center = cir_pf;
			cv::Point2f ipoint1 = cv::Point2f();
			cv::Point2f ipoint2 = cv::Point2f();
			ipoint1 = FindIntersections(cir_ellipse, k_convert, b_convert, 1);
			ipoint2 = FindIntersections(cir_ellipse, k_convert, b_convert, 0);
			if (ipoint1 != ipoint2)
			{
				Intersections.push_back(ipoint1);
				Intersections.push_back(ipoint2);
			}
			else
			{
				if (ipoint1 != cv::Point2f())
				{
					double dis = CalcPPDist(cir_pf, ipoint1);
					if (dis - radius < 0.5)
					{
						Intersections.push_back(ipoint1);
					}
				}
			}
			cv::line(dstImage, p1f, p2f, cv::Scalar(10, 255, 255), 1);
			cv::circle(dstImage, cir_pf, radius, cv::Scalar(255, 10, 10), 1);
			for (int n = 0; n < Intersections.size(); n++)
			{
				cv::circle(dstImage, Intersections[n], 5, cv::Scalar(10, 255, 10), -1);
			}			
		}		
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Intersections = Intersections;		
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmLineCircle::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		if (int_link == 1)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 1 || strs[1] != "图像")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			ui.txtLinkImage->setText(str_link);
		}
		else if (int_link == 2)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && strs[1] != "斜率")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && strs[1] == "斜率")
			{
				ui.txtLinkLinek->setText(str_link);
				return 0;
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
						ui.txtLinkLinek->setText(str_link);
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
			if (strs.size() == 2 && strs[1] != "截距")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && strs[1] == "截距")
			{
				ui.txtLinkLineb->setText(str_link);
				return 0;
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
						ui.txtLinkLineb->setText(str_link);
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
			if (strs.size() == 2 && (strs[1] != "中心坐标" && strs[1] != "垂足坐标" && (strs[0].mid(0, 4) != "线线交点" && strs[1] != "交点坐标")))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && (strs[1] == "中心坐标" || strs[1] == "垂足坐标" || (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")))
			{
				ui.txtLinkPoint1->setText(str_link);
				return 0;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point" || gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtLinkPoint1->setText(str_link);
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
			if (strs.size() == 2 && (strs[1] != "中心坐标" && strs[1] != "垂足坐标" && (strs[0].mid(0, 4) != "线线交点" && strs[1] != "交点坐标")))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && (strs[1] == "中心坐标" || strs[1] == "垂足坐标" || (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")))
			{
				ui.txtLinkPoint2->setText(str_link);
				return 0;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point" || gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtLinkPoint2->setText(str_link);
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
			if (strs.size() == 2 && (strs[1] != "中心坐标" && strs[1] != "垂足坐标" && (strs[0].mid(0, 4) != "线线交点" && strs[1] != "交点坐标")))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && (strs[1] == "中心坐标" || strs[1] == "垂足坐标" || (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")))
			{
				ui.txtLinkCircleCPoint->setText(str_link);
				return 0;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point" || gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == str_link)
					{
						ui.txtLinkCircleCPoint->setText(str_link);
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
			if (strs.size() == 2 && (strs[1] != "距离" && strs[1] != "半径" && strs[1] != "长轴长度" && strs[1] != "短轴长度"))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && (strs[1] == "距离" || strs[1] == "半径" || strs[1] == "长轴长度" || strs[1] == "短轴长度"))
			{
				ui.txtLinkCircleRadius->setText(str_link);
				return 0;
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
						ui.txtLinkCircleRadius->setText(str_link);
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

int frmLineCircle::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmLineCircle::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.txtMsg->clear();
	for (int i = 0; i < Intersections.size(); i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 线圆的交点坐标为: ");
		}
		ui.txtMsg->append(QString::number(GetToolBase()->m_Tools[tool_index].PublicGeometry.Intersections[i].x, 'f', 3) + "," + QString::number(GetToolBase()->m_Tools[tool_index].PublicGeometry.Intersections[i].y, 'f', 3));
	}
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmLineCircle::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmLineCircle::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmLineCircle::on_btnLinkLinek_clicked()
{
	QConfig::nFormState = 2;
}

void frmLineCircle::on_btnDelLinkLinek_clicked()
{
	ui.txtLinkLinek->clear();
}

void frmLineCircle::on_btnLinkLineb_clicked()
{
	QConfig::nFormState = 3;
}

void frmLineCircle::on_btnDelLinkLineb_clicked()
{
	ui.txtLinkLineb->clear();
}

void frmLineCircle::on_btnLinkPoint1_clicked()
{
	QConfig::nFormState = 4;
}

void frmLineCircle::on_btnDelLinkPoint1_clicked()
{
	ui.txtLinkPoint1->clear();
}

void frmLineCircle::on_btnLinkPoint2_clicked()
{
	QConfig::nFormState = 5;
}

void frmLineCircle::on_btnDelLinkPoint2_clicked()
{
	ui.txtLinkPoint2->clear();
}

void frmLineCircle::on_btnLinkCircleCPoint_clicked()
{
	QConfig::nFormState = 6;
}

void frmLineCircle::on_btnDelLinkCircleCPoint_clicked()
{
	ui.txtLinkCircleCPoint->clear();
}

void frmLineCircle::on_btnLinkCircleRadius_clicked()
{
	QConfig::nFormState = 7;
}

void frmLineCircle::on_btnDelLinkCircleRadius_clicked()
{
	ui.txtLinkCircleRadius->clear();
}

#pragma region 计算两点距离
//计算两点距离
double frmLineCircle::CalcPPDist(const cv::Point2f startPoint, const cv::Point2f endPoint)
{
	try
	{
		double x = abs(endPoint.x - startPoint.x);
		double y = abs(endPoint.y - startPoint.y);
		return sqrt(x * x + y * y);
	}
	catch (...)
	{
		return -1;
	}
}
#pragma endregion

//判断点是否在椭圆内
bool frmLineCircle::JudgePoint(const Ellipse& e, const double x, const double y)
{
	double a = e.a;
	double b = e.b;
	double angle = e.angle;
	double m = e.center.x;
	double n = e.center.y;
	double t1 = pow((x - m) * cos(angle) + (y - n) * sin(angle), 2);
	double t2 = pow((m - x) * sin(angle) + (y - n) * cos(angle), 2);
	return t1 / (a * a) + t2 / (b * b) < 1;
}

//线圆交点(flag为1是正斜率，flag为0是负斜率)
cv::Point2f frmLineCircle::FindIntersections(const Ellipse& e, const double& k, const double& b, const int flag)
{
	double x = (e.center.x / k + e.center.y - b) / (1 / k + k);
	double y = k * x + b;
	double step = 5;
	if (!flag)step = -step;
	double minstep = 0.01;
	while (abs(step) > minstep)
	{
		while (JudgePoint(e, x + step, k * (x + step) + b)) 
		{
			x = x + step;
		}
		step = step / 2;
	}
	cv::Point2f p;
	p.x = x;
	p.y = k * x + b;
	return p;
}

QImage frmLineCircle::Mat2QImage(const cv::Mat& mat)
{
	if (mat.empty())
	{
		return QImage();
	}
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		uchar* pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar* pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	else if (mat.type() == CV_8UC3)
	{
		const uchar* pSrc = (const uchar*)mat.data;
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		const uchar* pSrc = (const uchar*)mat.data;
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		return QImage();
	}
}

//全局变量控制
int QConfig::nFormState = 0;
