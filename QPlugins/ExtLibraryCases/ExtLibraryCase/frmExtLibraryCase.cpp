#include "frmExtLibraryCase.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QColorDialog>

/*
 * ①知道了轮廓的周长和面积，如果该轮廓是圆的话，那么面积/（周长乘周长）=Pi*R*R/(2*Pi*R*2*Pi*R)=1/(4*Pi)为常数；
 * ②进行反推，如果满足这个面积比周长平方为常数(1/(4*Pi))那么就判定为圆；
 * ③实际中，图像处理的轮廓满足不了100%准确，所以这里给出一个范围：在区间[0.063,1/(4*Pi)]，这里比值越接近区间的右侧，表示轮廓越接近圆，反正则越不接近圆；
 * ④当轮廓提取之后，这时候存在一部分误判，因为很小的轮廓往往会被误判为圆，这时需要对小轮廓进行筛选；
 * ⑤因为这些误判都在满足前提条件“圆”，那么可以用面积/周长=Pi*R*R/(2*Pi*R)=R/2为半径的一半，可以用半径来筛选“圆”。
*/

frmExtLibraryCase::frmExtLibraryCase(QString toolName, QToolBase* toolBase, QWidget* parent)
	: Toolnterface(toolName, toolBase, parent)
{
	ui.setupUi(this);
	//FramelessWindowHint属性设置窗口去除边框
	//WindowMinimizeButtonHint 属性设置在窗口最小化时，点击任务栏窗口可以显示出原窗口
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	//设置窗体在屏幕中间位置
	QDesktopWidget* desktop = QApplication::desktop();
	move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
	//设置窗口背景透明
	setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowIcon(QIcon(":/resource/dll.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
}

frmExtLibraryCase::~frmExtLibraryCase()
{
	this->deleteLater();
}

void frmExtLibraryCase::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/dll.png");
	m_titleBar->setTitleContent("扩展库示例");
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmExtLibraryCase::paintEvent(QPaintEvent* event)
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

void frmExtLibraryCase::onButtonCloseClicked()
{
	this->close();
}

int frmExtLibraryCase::Execute(const QString toolname)
{	
	bool link_state = false;
	image_index = 0;	
	strs.reserve(100);
	strs.clear();
	strs = image_link.split(".");
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

int frmExtLibraryCase::RunToolPro()
{
	try
	{		
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		cv::Mat gray_src;
		if (srcImage.channels() == 3)
		{
			cv::cvtColor(srcImage, gray_src, cv::COLOR_BGR2GRAY);
			srcImage.copyTo(dstImage);
		}
		else if (srcImage.channels() == 4)
		{
			cv::cvtColor(srcImage, gray_src, cv::COLOR_RGBA2GRAY);
			srcImage.copyTo(dstImage);
		}		
		else
		{
			srcImage.copyTo(gray_src);
			srcImage.copyTo(dstImage);
		}
		//使用不同级别掩码的中值滤波
		cv::medianBlur(gray_src, gray_src, 5);
		//canny轮廓检测
		cv::Canny(gray_src, gray_src, 120, 180);
		//膨胀(避免轮廓的不连续)
		cv::dilate(gray_src, gray_src, 1);
		//存储筛选过后"圆"的轮廓
		std::vector<std::vector<cv::Point>> cricle_vvp;
		cricle_vvp.reserve(1000);
		cricle_vvp.clear();
		//轮廓的提取
		vector<vector<cv::Point>> contours;
		contours.reserve(1000);
		contours.clear();
		vector<cv::Vec4i> hierarchy;
		hierarchy.reserve(1000);
		hierarchy.clear();
		findContours(gray_src, contours, hierarchy, cv::RetrievalModes::RETR_EXTERNAL, cv::ContourApproximationModes::CHAIN_APPROX_NONE);
		//遍历所有轮廓
		for (int i = 0; i < hierarchy.size(); i++)
		{
			//假设如果轮廓为圆，即面积为:PI*R^2
			double area = contourArea(contours[i]);
			//假设如果轮廓为圆，即周长为:PI*R*2
			double length = arcLength(contours[i], true);
			//假设如果轮廓为圆: 面积/周长=R/2；即半径为： 面积*2/周长
			double r = (area / length) * 2;
			//假设轮廓为圆： 面积/(周长的平方)=1/(4*PI)常数
			double c = (area / (length * length));
			//满足"圆"的条件进行筛选
			if (c > 0.063 && c < 0.08)
			{
				//通过半径进行筛选
				if (4 < r && r < 20)
				{
					//提取筛选后的"圆"轮廓
					cricle_vvp.push_back(contours[i]);
				}
			}
		}
		//遍历所有"圆"的轮廓
		for (int i = 0; i < cricle_vvp.size(); i++)
		{
			//获取"圆"的轮廓的外接矩形
			cv::Rect rect = cv::boundingRect(cricle_vvp[i]);
			//绘制矩形			
			cv::rectangle(dstImage, rect, cv::Scalar(0, 0, 255), 2);
		}
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

int frmExtLibraryCase::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		image_link = str_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmExtLibraryCase::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmExtLibraryCase::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

QImage frmExtLibraryCase::Mat2QImage(const cv::Mat& mat)
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
