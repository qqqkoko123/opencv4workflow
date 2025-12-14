#include "frmLineLineI.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QGraphicsOpacityEffect>

#define M_PI 3.14159265358979323846

frmLineLineI::frmLineLineI(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/intersection.png"));
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

frmLineLineI::~frmLineLineI()
{
	this->deleteLater();
}

void frmLineLineI::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/intersection.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmLineLineI::paintEvent(QPaintEvent* event)
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

void frmLineLineI::onButtonCloseClicked()
{
	this->close();
}

void frmLineLineI::onRadioClick(bool state)
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

int frmLineLineI::Execute(const QString toolname)
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

int frmLineLineI::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		k1_buf = 0;
		k2_buf = 0;
		b1_buf = 0;
		b2_buf = 0;
		point1_1_buf = 0;
		point1_2_buf = 0;
		point2_1_buf = 0;
		point2_2_buf = 0;
		Intersection = cv::Point2f(0, 0);
		Angle = 0;
		point_keys.reserve(300);
		point_keys.clear();
		point_keys = gvariable.global_variable_link.uniqueKeys();
		//使用全局变量
		for (int p = 0; p < point_keys.length(); p++)
		{
			QString key = point_keys[p];
			//直线两点方式
			if (ui.radioTwoPoint->isChecked() == true)
			{
				if (gvariable.global_variable_link.value(key).global_type == "cv::Point")
				{
					if (key == ui.txtLinkLine1Point1->text())
					{
						p1_1 = gvariable.global_variable_link.value(key).global_cvpoint_value;
						p1_1f.x = p1_1.x;
						p1_1f.y = p1_1.y;
						point1_1_buf = 1;
					}
					if (key == ui.txtLinkLine1Point2->text())
					{
						p1_2 = gvariable.global_variable_link.value(key).global_cvpoint_value;
						p1_2f.x = p1_2.x;
						p1_2f.y = p1_2.y;
						point1_2_buf = 1;
					}
					if (key == ui.txtLinkLine2Point1->text())
					{
						p2_1 = gvariable.global_variable_link.value(key).global_cvpoint_value;
						p2_1f.x = p2_1.x;
						p2_1f.y = p2_1.y;
						point2_1_buf = 1;
					}
					if (key == ui.txtLinkLine2Point2->text())
					{
						p2_2 = gvariable.global_variable_link.value(key).global_cvpoint_value;
						p2_2f.x = p2_2.x;
						p2_2f.y = p2_2.y;
						point2_2_buf = 1;
					}
				}
				else if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
				{
					if (key == ui.txtLinkLine1Point1->text())
					{
						p1_1f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
						point1_1_buf = 1;
					}
					if (key == ui.txtLinkLine1Point2->text())
					{
						p1_2f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
						point1_2_buf = 1;
					}
					if (key == ui.txtLinkLine2Point1->text())
					{
						p2_1f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
						point2_1_buf = 1;
					}
					if (key == ui.txtLinkLine2Point2->text())
					{
						p2_2f = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
						point2_2_buf = 1;
					}
				}
			}
			//直线斜率/截距方式
			if (ui.radioPoints->isChecked() == true)
			{
				if (gvariable.global_variable_link.value(key).global_type == "Double")
				{
					if (key == ui.txtLinkLine1k->text())
					{
						line1_k = gvariable.global_variable_link.value(key).global_double_value;
						k1_buf = 1;
					}
					if (key == ui.txtLinkLine1b->text())
					{
						line1_b = gvariable.global_variable_link.value(key).global_double_value;
						b1_buf = 1;
					}
					if (key == ui.txtLinkLine2k->text())
					{
						line2_k = gvariable.global_variable_link.value(key).global_double_value;
						k2_buf = 1;
					}
					if (key == ui.txtLinkLine2b->text())
					{
						line2_b = gvariable.global_variable_link.value(key).global_double_value;
						b2_buf = 1;
					}
				}
			}
		}
		//使用工具变量
		if (point1_1_buf != 1 || point1_2_buf != 1 || point2_1_buf != 1 || point2_2_buf != 1)
		{
			int fit_index = 0;
			if (ui.radioTwoPoint->isChecked() == true)
			{
				if (point1_1_buf != 1)
				{
					strs.clear();
					strs = ui.txtLinkLine1Point1->text().split(".");
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
						p1_1f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Center;
					}
					else if (strs[1] == "垂足坐标")
					{
						p1_1f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Pedal;
					}
					else if (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")
					{
						p1_1f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Intersection;
					}
					else
					{
						p1_1f = cv::Point2f(0, 0);
					}
				}
				if (point1_2_buf != 1)
				{
					strs.clear();
					strs = ui.txtLinkLine1Point2->text().split(".");
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
						p1_2f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Center;
					}
					else if (strs[1] == "垂足坐标")
					{
						p1_2f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Pedal;
					}
					else if (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")
					{
						p1_2f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Intersection;
					}
					else
					{
						p1_2f = cv::Point2f(0, 0);
					}
				}
				if (point2_1_buf != 1)
				{
					strs.clear();
					strs = ui.txtLinkLine2Point1->text().split(".");
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
						p2_1f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Center;
					}
					else if (strs[1] == "垂足坐标")
					{
						p2_1f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Pedal;
					}
					else if (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")
					{
						p2_1f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Intersection;
					}
					else
					{
						p2_1f = cv::Point2f(0, 0);
					}
				}
				if (point2_2_buf != 1)
				{
					strs.clear();
					strs = ui.txtLinkLine2Point2->text().split(".");
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
						p2_2f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Center;
					}
					else if (strs[1] == "垂足坐标")
					{
						p2_2f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Pedal;
					}
					else if (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")
					{
						p2_2f = GetToolBase()->m_Tools[fit_index].PublicGeometry.Intersection;
					}
					else
					{
						p2_2f = cv::Point2f(0, 0);
					}
				}
			}
		}
		if (k1_buf != 1 || b1_buf != 1 || k2_buf != 1 || b2_buf != 1)
		{
			if (ui.radioPoints->isChecked() == true)
			{
				int fit_index = 0;
				if (k1_buf != 1)
				{
					strs.clear();
					strs = ui.txtLinkLine1k->text().split(".");
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
						line1_k = GetToolBase()->m_Tools[fit_index].PublicGeometry.k;
					}
					else
					{
						line1_k = 0;
					}
				}
				if (b1_buf != 1)
				{
					strs.clear();
					strs = ui.txtLinkLine1b->text().split(".");
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
						line1_b = GetToolBase()->m_Tools[fit_index].PublicGeometry.b;
					}
					else
					{
						line1_b = 0;
					}
				}
				if (k2_buf != 1)
				{
					strs.clear();
					strs = ui.txtLinkLine2k->text().split(".");
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
						line2_k = GetToolBase()->m_Tools[fit_index].PublicGeometry.k;
					}
					else
					{
						line2_k = 0;
					}
				}
				if (b2_buf != 1)
				{
					strs.clear();
					strs = ui.txtLinkLine2b->text().split(".");
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
						line2_b = GetToolBase()->m_Tools[fit_index].PublicGeometry.b;
					}
					else
					{
						line2_b = 0;
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
			int x1_1 = 100;
			int y1_1 = line1_k * x1_1 + line1_b;
			int x1_2 = 200;
			int y1_2 = line1_k * x1_2 + line1_b;
			int x2_1 = 100;
			int y2_1 = line2_k * x2_1 + line2_b;
			int x2_2 = 200;
			int y2_2 = line2_k * x2_2 + line2_b;
			//计算两直线交点和夹角
			cv::Vec4d l1 = cv::Vec4d(x1_1, y1_1, x1_2, y1_2);
			cv::Vec4d l2 = cv::Vec4d(x2_1, y2_1, x2_2, y2_2);
			cv::Vec4d par_result = lines_intersection(l1, l2);
			Intersection.x = par_result[1];
			Intersection.y = par_result[2];
			Angle = par_result[3];
			int w = srcImage.cols;
			int y_1 = int((-x1_1 * line1_k) + y1_1);
			int y_2 = int((w - x1_1) * line1_k + y1_1);
			cv::line(dstImage, cv::Point((w - 1), y_2), cv::Point(0, y_1), cv::Scalar(255, 10, 10), 1);
			int y_3 = int((-x2_1 * line2_k) + y2_1);
			int y_4 = int((w - x2_1) * line2_k + y2_1);
			cv::line(dstImage, cv::Point((w - 1), y_4), cv::Point(0, y_3), cv::Scalar(10, 255, 255), 1);
			cv::circle(dstImage, Intersection, 5, cv::Scalar(10, 255, 10), -1);
		}
		else
		{
			//计算两直线交点和夹角
			cv::Vec4d l1 = cv::Vec4d(p1_1f.x, p1_1f.y, p1_2f.x, p1_2f.y);
			cv::Vec4d l2 = cv::Vec4d(p2_1f.x, p2_1f.y, p2_2f.x, p2_2f.y);
			cv::Vec4d par_result = lines_intersection(l1, l2);
			Intersection.x = par_result[1];
			Intersection.y = par_result[2];
			Angle = par_result[3];
			cv::line(dstImage, p1_1f, p1_2f, cv::Scalar(10, 255, 255), 1);
			cv::line(dstImage, p2_1f, p2_2f, cv::Scalar(10, 255, 255), 1);
			cv::circle(dstImage, Intersection, 5, cv::Scalar(10, 255, 10), -1);
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Intersection = Intersection;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Angle = Angle;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmLineLineI::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
				ui.txtLinkLine1k->setText(str_link);
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
						ui.txtLinkLine1k->setText(str_link);
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
				ui.txtLinkLine1b->setText(str_link);
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
						ui.txtLinkLine1b->setText(str_link);
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
			if (strs.size() == 2 && strs[1] != "斜率")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && strs[1] == "斜率")
			{
				ui.txtLinkLine2k->setText(str_link);
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
						ui.txtLinkLine2k->setText(str_link);
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
			if (strs.size() == 2 && strs[1] != "截距")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && strs[1] == "截距")
			{
				ui.txtLinkLine2b->setText(str_link);
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
						ui.txtLinkLine2b->setText(str_link);
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
				ui.txtLinkLine1Point1->setText(str_link);
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
						ui.txtLinkLine1Point1->setText(str_link);
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
			if (strs.size() == 2 && (strs[1] != "中心坐标" && strs[1] != "垂足坐标" && (strs[0].mid(0, 4) != "线线交点" && strs[1] != "交点坐标")))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && (strs[1] == "中心坐标" || strs[1] == "垂足坐标" || (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")))
			{
				ui.txtLinkLine1Point2->setText(str_link);
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
						ui.txtLinkLine1Point2->setText(str_link);
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
			if (strs.size() == 2 && (strs[1] != "中心坐标" && strs[1] != "垂足坐标" && (strs[0].mid(0, 4) != "线线交点" && strs[1] != "交点坐标")))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && (strs[1] == "中心坐标" || strs[1] == "垂足坐标" || (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")))
			{
				ui.txtLinkLine2Point1->setText(str_link);
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
						ui.txtLinkLine2Point1->setText(str_link);
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
			if (strs.size() == 2 && (strs[1] != "中心坐标" && strs[1] != "垂足坐标" && (strs[0].mid(0, 4) != "线线交点" && strs[1] != "交点坐标")))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && (strs[1] == "中心坐标" || strs[1] == "垂足坐标" || (strs[0].mid(0, 4) == "线线交点" && strs[1] == "交点坐标")))
			{
				ui.txtLinkLine2Point2->setText(str_link);
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
						ui.txtLinkLine2Point2->setText(str_link);
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

int frmLineLineI::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmLineLineI::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.txtMsg->clear();
	ui.txtMsg->append("-> 两直线交点坐标为：" + QString::number(Intersection.x) + "," + QString::number(Intersection.y));
	ui.txtMsg->append("-> 两直线夹角为：" + QString::number(Angle));
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmLineLineI::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmLineLineI::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmLineLineI::on_btnLinkLine1k_clicked()
{
	QConfig::nFormState = 2;
}

void frmLineLineI::on_btnDelLinkLine1k_clicked()
{
	ui.txtLinkLine1k->clear();
}

void frmLineLineI::on_btnLinkLine1b_clicked()
{
	QConfig::nFormState = 3;
}

void frmLineLineI::on_btnDelLinkLine1b_clicked()
{
	ui.txtLinkLine1b->clear();
}

void frmLineLineI::on_btnLinkLine2k_clicked()
{
	QConfig::nFormState = 4;
}

void frmLineLineI::on_btnDelLinkLine2k_clicked()
{
	ui.txtLinkLine2k->clear();
}

void frmLineLineI::on_btnLinkLine2b_clicked()
{
	QConfig::nFormState = 5;
}

void frmLineLineI::on_btnDelLinkLine2b_clicked()
{
	ui.txtLinkLine2b->clear();
}

void frmLineLineI::on_btnLinkLine1Point1_clicked()
{
	QConfig::nFormState = 6;
}

void frmLineLineI::on_btnDelLinkLine1Point1_clicked()
{
	ui.txtLinkLine1Point1->clear();
}

void frmLineLineI::on_btnLinkLine1Point2_clicked()
{
	QConfig::nFormState = 7;
}

void frmLineLineI::on_btnDelLinkLine1Point2_clicked()
{
	ui.txtLinkLine1Point2->clear();
}

void frmLineLineI::on_btnLinkLine2Point1_clicked()
{
	QConfig::nFormState = 8;
}

void frmLineLineI::on_btnDelLinkLine2Point1_clicked()
{
	ui.txtLinkLine2Point1->clear();
}

void frmLineLineI::on_btnLinkLine2Point2_clicked()
{
	QConfig::nFormState = 9;
}

void frmLineLineI::on_btnDelLinkLine2Point2_clicked()
{
	ui.txtLinkLine2Point2->clear();
}

#pragma region 计算两直线交点和夹角
//计算两直线交点和夹角
cv::Vec4d frmLineLineI::lines_intersection(const cv::Vec4d l1, const cv::Vec4d l2)
{
	double x1 = l1[0], y1 = l1[1], x2 = l1[2], y2 = l1[3];
	double a1 = -(y2 - y1), b1 = x2 - x1, c1 = (y2 - y1) * x1 - (x2 - x1) * y1;
	double x3 = l2[0], y3 = l2[1], x4 = l2[2], y4 = l2[3];
	double a2 = -(y4 - y3), b2 = x4 - x3, c2 = (y4 - y3) * x3 - (x4 - x3) * y3;
	bool r = false;
	double x0 = 0, y0 = 0;
	double angle = 0;
	//判断相交
	if (b1 == 0 && b2 != 0) //l1垂直于x轴，l2倾斜于x轴
		r = true;
	else if (b1 != 0 && b2 == 0) //l1倾斜于x轴，l2垂直于x轴
		r = true;
	else if (b1 != 0 && b2 != 0 && a1 / b1 != a2 / b2)
		r = true;
	if (r)
	{
		//计算交点
		x0 = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
		y0 = (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2);
		//计算夹角
		double a = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2));
		double b = sqrt(pow(x4 - x0, 2) + pow(y4 - y0, 2));
		double c = sqrt(pow(x2 - x0, 2) + pow(y2 - y0, 2));
		angle = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / CV_PI;
	}
	return cv::Vec4d(r, x0, y0, angle);
}
#pragma endregion

QImage frmLineLineI::Mat2QImage(const cv::Mat& mat)
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
