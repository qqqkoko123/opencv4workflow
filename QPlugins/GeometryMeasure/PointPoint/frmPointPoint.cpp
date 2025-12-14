#include "frmPointPoint.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QGraphicsOpacityEffect>

#define M_PI 3.14159265358979323846

frmPointPoint::frmPointPoint(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/point_point.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);	
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmPointPoint::~frmPointPoint()
{
	this->deleteLater();
}

void frmPointPoint::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/point_point.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmPointPoint::paintEvent(QPaintEvent* event)
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

void frmPointPoint::onButtonCloseClicked()
{
	this->close();
}

int frmPointPoint::Execute(const QString toolname)
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

int frmPointPoint::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		point_buf1 = 0;
		point_buf2 = 0;
		Center = cv::Point2f(0,0);
		Angle = 0;
		Distance = 0;
		point_keys.reserve(300);
		point_keys.clear();
		point_keys = gvariable.global_variable_link.uniqueKeys();
		//使用全局变量
		for (int k = 0; k < point_keys.length(); k++)
		{
			QString key = point_keys[k];
			if (gvariable.global_variable_link.value(key).global_type == "cv::Point")
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
			else if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
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
		//使用工具变量
		if (point_buf1 != 1 || point_buf2 != 1)
		{
			int fit_index = 0;
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
				else
				{
					p2f = cv::Point2f(0, 0);
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
		cv::line(dstImage, p1f, p2f, cv::Scalar(255, 10, 10), 1);
		Distance = CalcPPDist(p1f, p2f);
		Center.x = 0.5 * (p1f.x + p2f.x);
		Center.y = 0.5 * (p1f.y + p2f.y);
		Angle = CalcLineHorizontalAngle(p1f, p2f);
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Center = Center;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Angle = Angle;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Distance = Distance;
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

int frmPointPoint::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
			if (strs.size() == 2 && (strs[1] != "中心坐标" && strs[1] != "垂足坐标"))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && (strs[1] == "中心坐标" || strs[1] == "垂足坐标"))
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
		else if (int_link == 3)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && (strs[1] != "中心坐标" && strs[1] != "垂足坐标"))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			if (strs.size() == 2 && (strs[1] == "中心坐标" || strs[1] == "垂足坐标"))
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
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmPointPoint::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmPointPoint::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.txtMsg->clear();
	ui.txtMsg->append("-> 线段的中心坐标为：" + QString::number(Center.x) + "," + QString::number(Center.y));
	ui.txtMsg->append("-> 线段的角度为：" + QString::number(Angle) + "°");
	ui.txtMsg->append("-> 线段的长度为：" + QString::number(Distance));
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmPointPoint::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmPointPoint::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmPointPoint::on_btnLinkPoint1_clicked()
{
	QConfig::nFormState = 2;
}

void frmPointPoint::on_btnDelLinkPoint1_clicked()
{
	ui.txtLinkPoint1->clear();
}

void frmPointPoint::on_btnLinkPoint2_clicked()
{
	QConfig::nFormState = 3;
}

void frmPointPoint::on_btnDelLinkPoint2_clicked()
{
	ui.txtLinkPoint2->clear();
}

#pragma region 计算两点距离
//计算两点距离
double frmPointPoint::CalcPPDist(const cv::Point2f startPoint, const cv::Point2f endPoint)
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

#pragma region 计算直线和水平线的夹角
//计算直线和水平线的夹角
double frmPointPoint::CalcLineHorizontalAngle(const cv::Point2f line_pointf1, const cv::Point2f line_pointf2)
{
	try
	{
		cv::Point2f line1_pointf1 = cv::Point2f(0, 0);
		cv::Point2f line1_pointf2 = cv::Point2f(100, 0);
		double a = atan2(line1_pointf2.y - line1_pointf1.y, line1_pointf2.x - line1_pointf1.x);
		double b = atan2(line_pointf2.y - line_pointf1.y, line_pointf2.x - line_pointf1.x);
		return (180 * (float)(b - a)) / M_PI;
	}
	catch (...)
	{
		return -1;
	}
}
#pragma endregion

QImage frmPointPoint::Mat2QImage(const cv::Mat& mat)
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
