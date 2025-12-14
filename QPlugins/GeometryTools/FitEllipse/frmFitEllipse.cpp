#include "frmFitEllipse.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QGraphicsOpacityEffect>

frmFitEllipse::frmFitEllipse(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/fit_ellipse.png"));
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

frmFitEllipse::~frmFitEllipse()
{
	this->deleteLater();
}

void frmFitEllipse::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/fit_ellipse.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmFitEllipse::paintEvent(QPaintEvent* event)
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

void frmFitEllipse::onButtonCloseClicked()
{
	this->close();
}

int frmFitEllipse::Execute(const QString toolname)
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

int frmFitEllipse::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		Center = cv::Point2f(0, 0);
		Angle = 0;
		Length1 = 0;
		Length2 = 0;
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
		//拟合椭圆   
		cv::RotatedRect fit_ellipse;
		if (strs[1] == "重心")
		{
			fit_ellipse = cv::fitEllipse(GetToolBase()->m_Tools[fit_index].PublicDetect.CenterPoints);
		}
		else if (strs[1] == "点集")
		{
			fit_ellipse = cv::fitEllipse(GetToolBase()->m_Tools[fit_index].PublicGeometry.BorderPoints);
		}	
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -2;
		}
		if (dstImage.channels() == 1)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
		}
		else if (dstImage.channels() == 4)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
		}
		cv::ellipse(dstImage, fit_ellipse, cv::Scalar(255, 10, 10), 1);
		Center = fit_ellipse.center;
		//Angle是椭圆中心center发出的平行于x轴的射线，顺时针旋转，与椭圆短轴的夹角，取值范围：[0 ~ 180]
		Angle = fit_ellipse.angle;
		if (fit_ellipse.size.width > fit_ellipse.size.height)
		{
			Length1 = fit_ellipse.size.width;
			Length2 = fit_ellipse.size.height;
		}
		else
		{
			Length2 = fit_ellipse.size.width;
			Length1 = fit_ellipse.size.height;
		}
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Center = Center;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Angle = Angle;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Length1 = Length1;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Length2 = Length2;
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

int frmFitEllipse::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmFitEllipse::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmFitEllipse::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.txtMsg->clear();
	ui.txtMsg->append("-> 椭圆的中心坐标为：" + QString::number(Center.x) + "," + QString::number(Center.y));
	ui.txtMsg->append("-> 椭圆的角度为：" + QString::number(Angle) + "°");
	ui.txtMsg->append("-> 椭圆的长轴长度为：" + QString::number(Length1));
	ui.txtMsg->append("-> 椭圆的短轴长度为：" + QString::number(Length2));
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmFitEllipse::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmFitEllipse::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmFitEllipse::on_btnLinkContour_clicked()
{
	QConfig::nFormState = 2;
}

void frmFitEllipse::on_btnDelLinkContour_clicked()
{
	ui.txtLinkContour->clear();
}

QImage frmFitEllipse::Mat2QImage(const cv::Mat& mat)
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
