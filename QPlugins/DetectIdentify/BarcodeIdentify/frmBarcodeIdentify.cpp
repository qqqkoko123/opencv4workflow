#include "frmBarcodeIdentify.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include "QGraphicsScenes.h"
#include <QGraphicsOpacityEffect>

frmBarcodeIdentify::frmBarcodeIdentify(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/barcode.png"));
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);	
	//初始化标题栏
	initTitleBar();	
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmBarcodeIdentify::~frmBarcodeIdentify()
{
	this->deleteLater();
}

void frmBarcodeIdentify::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/barcode.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmBarcodeIdentify::paintEvent(QPaintEvent* event)
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

void frmBarcodeIdentify::onButtonCloseClicked()
{
	view_rect = false;
	this->close();
}

int frmBarcodeIdentify::Execute(const QString toolname)
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
	int result;
	if (view_rect == true)
	{
		result = RunTestImage();
	}
	else
	{
		result = RunToolPro();
	}	
	if (result == -1)
	{
		return -1;
	}
	return 0;
}

int frmBarcodeIdentify::RunTestImage()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;				
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		double mul_scale = ui.spinMulValue->value();
		dstImage = dstImage.mul(dstImage, mul_scale);
		return 0;
	}
	catch (...)
	{		
		return -1;
	}
}

int frmBarcodeIdentify::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;		
		strDecoded.clear();
		decoded_format.clear();
		vPoints.clear();	
		Code.clear();
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		if (dstImage.channels() == 3)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_BGR2GRAY);
		}
		else if (dstImage.channels() == 4)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2GRAY);
		}
		//解码
		for (int m = 0; m < 3; m++)
		{
			cv::Mat gray, imageSobelX, imageSobelY, imageSobelOut, dst_mat;
			double n;
			switch (m) {
			case 0:
				n = 1.0;
				break;
			case 1:
				n = 2.0;
				break;			
			case 2:
				n = 3.0;
				break;
			}
			cv::resize(dstImage, gray, cv::Size((int)(dstImage.cols * n), (int)(dstImage.rows * n)));				
			double mul_scale = ui.spinMulValue->value();
			gray = gray.mul(gray, mul_scale);
			detector->detectAndDecode(gray, strDecoded, decoded_format, vPoints);
			if (strDecoded.size() != 0 && strDecoded[0] != "")
			{
				break;
			}
		}
		if (strDecoded.size() == 0 || strDecoded[0] == "")
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		}
		else
		{
			if (dstImage.channels() == 1)
			{
				cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
			}
			else if (dstImage.channels() == 4)
			{
				cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
			}
			double show_thickness = (dstImage.rows > dstImage.cols) ? (2.813 * dstImage.rows) / dstImage.cols :
				(2.813 * dstImage.cols) / dstImage.rows;
			double contour_thickness = show_thickness * 0.4;
			for (int i = 0; i < vPoints.size(); i += 4)
			{
				cv::Point pt1 = vPoints[i];
				cv::Point pt2 = vPoints[i+1];
				cv::Point pt3 = vPoints[i+2];
				cv::Point pt4 = vPoints[i+3];
				cv::line(dstImage, pt1, pt2, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
				cv::line(dstImage, pt2, pt3, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
				cv::line(dstImage, pt3, pt4, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
				cv::line(dstImage, pt4, pt1, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
			}			
			for (int i = 0; i < strDecoded.size(); i++)
			{				
				Code.push_back(QString::fromStdString(strDecoded[i]));
			}
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			GetToolBase()->m_Tools[tool_index].PublicDetect.Code = Code;
			GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		}
		return 0;
	}
	catch (...)
	{		
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmBarcodeIdentify::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmBarcodeIdentify::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmBarcodeIdentify::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	view_rect = false;
	bool state = InitDetector();
	if (state == false)
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "初始化条形码参数异常！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	Execute(GetToolName());
	ui.txtMsg->clear();
	for (int i = 0; i < strDecoded.size(); i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 条形码内容为：");
		}
		ui.txtMsg->append(QString::fromStdString(strDecoded[i]));
	}	
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmBarcodeIdentify::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmBarcodeIdentify::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmBarcodeIdentify::on_btnTestImage_clicked()
{
	view_rect = true;
	Execute(GetToolName());
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	QApplication::processEvents();
}

bool frmBarcodeIdentify::InitDetector()
{
	try {		
		QString sr_prototxt = QCoreApplication::applicationDirPath() + "/Parameters/Code/sr.prototxt";
		QString sr_caffemodel = QCoreApplication::applicationDirPath() + "/Parameters/Code/sr.caffemodel";
		detector = cv::makePtr<cv::barcode::BarcodeDetector>(			
			sr_prototxt.toStdString(),
			sr_caffemodel.toStdString());
		return true;
	}
	catch (...)
	{
		return false;
	}
}

QImage frmBarcodeIdentify::Mat2QImage(const cv::Mat& mat)
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
