#include "frmFitCircle.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QGraphicsOpacityEffect>

frmFitCircle::frmFitCircle(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/fit_circle.png"));
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

frmFitCircle::~frmFitCircle()
{
	this->deleteLater();
}

void frmFitCircle::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/fit_circle.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmFitCircle::paintEvent(QPaintEvent* event)
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

void frmFitCircle::onButtonCloseClicked()
{
	this->close();
}

int frmFitCircle::Execute(const QString toolname)
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

int frmFitCircle::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		Center = cv::Point2f(0, 0);
		Radius = 0;
		strs.clear();
		strs = ui.txtLinkContour->text().split(".");
		if (strs.size() == 1)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		bool link_state = false;
		int fit_index = 0;
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
		//拟合圆    
		Box fit_circle{0};		
		if (strs[1] == "重心")
		{
			fit_circle = fitCircle(GetToolBase()->m_Tools[fit_index].PublicDetect.CenterPoints);
		}
		else if(strs[1] == "点集")
		{
			fit_circle = fitCircle(GetToolBase()->m_Tools[fit_index].PublicGeometry.BorderPoints);
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -2;
		}
		Center.x = fit_circle.x;
		Center.y = fit_circle.y;
		Radius = fit_circle.r;		
		if (dstImage.channels() == 1)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
		}
		else if (dstImage.channels() == 4)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
		}
		cv::circle(dstImage, Center, Radius, cv::Scalar(255, 10, 10), 1);
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Center = Center;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Radius = Radius;
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

int frmFitCircle::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
			if (strs.size() == 1 || (strs[1] != "重心" && strs[1] != "点集"))
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			ui.txtLinkContour->setText(str_link);
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmFitCircle::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmFitCircle::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.txtMsg->clear();
	ui.txtMsg->append("-> 圆的中心坐标为：" + QString::number(Center.x) + "," + QString::number(Center.y));
	ui.txtMsg->append("-> 圆的半径为：" + QString::number(Radius));
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmFitCircle::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmFitCircle::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmFitCircle::on_btnLinkContour_clicked()
{
	QConfig::nFormState = 2;
}

void frmFitCircle::on_btnDelLinkContour_clicked()
{
	ui.txtLinkContour->clear();
}

Box frmFitCircle::fitCircle(const std::vector<cv::Point2f>& points) 
{
	Box box;
	box.x = 0.0f;
	box.y = 0.0f;
	box.r = 0.0f;
	if (points.size() < 3)
	{
		return box;
	}
	int i = 0;
	double X1 = 0;
	double Y1 = 0;
	double X2 = 0;
	double Y2 = 0;
	double X3 = 0;
	double Y3 = 0;
	double X1Y1 = 0;
	double X1Y2 = 0;
	double X2Y1 = 0;
	int Sum = points.size();
	for (i = 0; i < Sum; i++)
	{
		X1 = X1 + points[i].x;
		Y1 = Y1 + points[i].y;
		X2 = X2 + points[i].x * points[i].x;
		Y2 = Y2 + points[i].y * points[i].y;
		X3 = X3 + points[i].x * points[i].x * points[i].x;
		Y3 = Y3 + points[i].y * points[i].y * points[i].y;
		X1Y1 = X1Y1 + points[i].x * points[i].y;
		X1Y2 = X1Y2 + points[i].x * points[i].y * points[i].y;
		X2Y1 = X2Y1 + points[i].x * points[i].x * points[i].y;
	}
	double C, D, E, G, H, N;
	double a, b, c;
	N = points.size();
	C = N * X2 - X1 * X1;
	D = N * X1Y1 - X1 * Y1;
	E = N * X3 + N * X1Y2 - (X2 + Y2) * X1;
	G = N * Y2 - Y1 * Y1;
	H = N * X2Y1 + N * Y3 - (X2 + Y2) * Y1;
	a = (H * D - E * G) / (C * G - D * D);
	b = (H * C - E * D) / (D * D - G * C);
	c = -(a * X1 + b * Y1 + X2 + Y2) / N;
	double A, B, R;
	A = a / (-2);
	B = b / (-2);
	R = sqrt(a * a + b * b - 4 * c) / 2;
	box.x = A;
	box.y = B;
	box.r = R;
	return box;
}

QImage frmFitCircle::Mat2QImage(const cv::Mat& mat)
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
