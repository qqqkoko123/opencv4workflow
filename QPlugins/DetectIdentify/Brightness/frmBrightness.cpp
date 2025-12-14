#include "frmBrightness.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include "ImageItem.h"

frmBrightness::frmBrightness(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/brightness.png"));
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//连接信号与槽		
	connect(this, &frmBrightness::sig_BrightnessValue, view->item, &ImageItem::slot_BrightnessValue);
	//初始化标题栏
	initTitleBar();		
}

frmBrightness::~frmBrightness()
{
	this->deleteLater();
}

void frmBrightness::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/brightness.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmBrightness::paintEvent(QPaintEvent* event)
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

void frmBrightness::onButtonCloseClicked()
{
	this->close();
}

int frmBrightness::Execute(const QString toolname)
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

int frmBrightness::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		srcImage.copyTo(dstImage);
		float cast, da;
		bool state = DetectBrightness(srcImage, cast, da);
		if (state == false)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		if (cast < ui.spinMinBrightness->value() || cast > ui.spinMaxBrightness->value())
		{
			state = false;
		}
		else
		{
			state = true;
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		GetToolBase()->m_Tools[tool_index].PublicDetect.Brightness = cast;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = state;
		return 0;
	}
	catch (...)
	{		
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmBrightness::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmBrightness::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmBrightness::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	QString msg = "图像亮度值为：" + QString::number(GetToolBase()->m_Tools[tool_index].PublicDetect.Brightness, 'f', 2);
	emit sig_BrightnessValue(msg);
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmBrightness::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmBrightness::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

//cast小于1表示比较正常，大于1表示存在亮度异常；当cast异常时，da大于0表示过亮，da小于0表示过暗
bool frmBrightness::DetectBrightness(const cv::Mat src_mat, float& cast, float& da)
{
	try
	{
		cv::Mat gary_img;
		if (src_mat.channels() == 3)
		{
			cv::cvtColor(src_mat, gary_img, cv::COLOR_BGR2GRAY);
		}
		else if (src_mat.channels() == 4)
		{
			cv::cvtColor(src_mat, gary_img, cv::COLOR_RGBA2GRAY);
		}
		else
		{
			src_mat.copyTo(gary_img);
		}
		float a = 0;
		int Hist[256];
		for (int i = 0; i < 256; i++)
		{
			Hist[i] = 0;
		}
		for (int i = 0; i < gary_img.rows; i++)
		{
			for (int j = 0; j < gary_img.cols; j++)
			{
				a += float(gary_img.at<uchar>(i, j) - 128);
				int x = gary_img.at<uchar>(i, j);
				Hist[x]++;
			}
		}
		da = a / float(gary_img.rows * src_mat.cols);
		float D = abs(da);
		float Ma = 0;
		for (int i = 0; i < 256; i++)
		{
			Ma += abs(i - 128 - da) * Hist[i];
		}
		Ma /= float((gary_img.rows * gary_img.cols));
		float M = abs(Ma);
		float K = D / M;
		if (M == 0)
		{
			cast = 0;
		}
		else
		{
			cast = K;
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}

QImage frmBrightness::Mat2QImage(const cv::Mat& mat)
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
