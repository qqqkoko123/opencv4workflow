#include "frmImageClarity.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include "ImageItem.h"

frmImageClarity::frmImageClarity(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/clarity.png"));
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//连接信号与槽	
	connect(this, SIGNAL(sig_PathMessage()), this, SLOT(slot_PathMessage()));	
	connect(this, &frmImageClarity::sig_ClarityValue, view->item, &ImageItem::slot_ClarityValue);
	//初始化标题栏
	initTitleBar();	
}

frmImageClarity::~frmImageClarity()
{
	this->deleteLater();
}

void frmImageClarity::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/clarity.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmImageClarity::paintEvent(QPaintEvent* event)
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

void frmImageClarity::onButtonCloseClicked()
{
	this->close();
}

int frmImageClarity::Execute(const QString toolname)
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

int frmImageClarity::RunToolPro()
{
	try
	{
		QDir dir(imgsPath);		
		if (imgsPath.isEmpty())
		{
			//子线程中操作GUI要用信号与槽
			emit sig_PathMessage();
			return -1;
		}
		//获取所有文件名		
		imgsPathBuf = dir.fromNativeSeparators(imgsPath); //  "\\"转为"/" 	
		imgsPathBuf = imgsPathBuf + "/";
		if (!dir.exists())
		{
			//子线程中操作GUI要用信号与槽
			emit sig_PathMessage();
			return -1;
		}
		dir.setFilter(QDir::Files);
		dir.setSorting(QDir::Name);
		dir.setNameFilters(QString("*.jpg;*.png;*.bmp").split(";"));
		mImgNames.reserve(1000);
		mImgNames.clear();
		mImgNames = dir.entryList();
		if (mImgNames.size() == 0)
		{
			//子线程中操作GUI要用信号与槽
			emit sig_PathMessage();
			return -1;			
		}		
		vector<double> claritys;
		claritys.reserve(1000);
		claritys.clear();
		//循环处理图像
		for (int j = 0; j < mImgNames.size(); j++)
		{
			cv::String file_name = imgsPathBuf.toStdString() + mImgNames[j].toStdString();
			cv::Mat src = cv::imread(file_name, cv::ImreadModes::IMREAD_ANYCOLOR);
			double clarity;
			switch (ui.comboClarity->currentIndex()) {
			case 0:
				clarity = CalcClarityTenengrad(src);
				break;
			case 1:
				clarity = CalcClarityLaplacian(src);
				break;
			case 2:
				clarity = CalcClarity(src);
				break;
			}					
			claritys.push_back(clarity);
		}
		int max_index = GetMaxAndIndex(claritys);
		cv::String file_name = imgsPathBuf.toStdString() + mImgNames[max_index].toStdString();
		dstImage = cv::imread(file_name, cv::ImreadModes::IMREAD_ANYCOLOR);
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		GetToolBase()->m_Tools[tool_index].PublicDetect.Clarity = claritys[max_index];
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;		
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmImageClarity::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmImageClarity::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmImageClarity::slot_PathMessage()
{
	QMessageBox::warning(this, "提示", "加载图像文件夹失败！", QMessageBox::Ok);
	return;
}

void frmImageClarity::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	QString msg = "图像清晰度最优值为：" + QString::number(GetToolBase()->m_Tools[tool_index].PublicDetect.Clarity, 'f', 2);
	emit sig_ClarityValue(msg);
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmImageClarity::on_btnSelectPath_clicked()
{
	QString path_C = QDir::currentPath();
	QString dirPath = QFileDialog::getExistingDirectory(this, tr("打开图片文件夹"), path_C);
	if (false == dirPath.isEmpty())
	{
		imgsPath = dirPath;			
		ui.txtFolderPath->setText(dirPath);
	}
}

//使用SMD灰度差分绝对值之和计算一幅图像的清晰度
double frmImageClarity::CalcClarity(const cv::Mat src_mat)
{
	try
	{
		cv::Mat gray;
		if (src_mat.channels() == 3)
		{
			cv::cvtColor(src_mat, gray, cv::COLOR_BGR2GRAY);
		}
		else if (src_mat.channels() == 4)
		{
			cv::cvtColor(src_mat, gray, cv::COLOR_RGBA2GRAY);
		}		
		else
		{
			src_mat.copyTo(gray);
		}
		double temp = 0;
		double DR = 0;
		int i, j;
		int height = gray.rows;
		int width = gray.cols;
		int step = gray.step / sizeof(uchar);
		uchar* data = (uchar*)gray.data;
		double num = width * height;
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				temp += cv::sqrt((cv::pow((double)(data[(i + 1) * step + j] - data[i * step + j]), 2) + cv::pow((double)(data[i * step + j + 1] - data[i * step + j]), 2)));
				temp += cv::abs(data[(i + 1) * step + j] - data[i * step + j]) + cv::abs(data[i * step + j + 1] - data[i * step + j]);
			}
		}
		DR = temp / num;
		return DR;
	}
	catch (...)
	{
		return -1;
	}
}

//使用Tenengrad梯度法计算一幅图像的清晰度
double frmImageClarity::CalcClarityTenengrad(const cv::Mat src_mat)
{
	try
	{
		cv::Mat gray;
		if (src_mat.channels() == 3)
		{
			cv::cvtColor(src_mat, gray, cv::COLOR_BGR2GRAY);
		}
		else if (src_mat.channels() == 4)
		{
			cv::cvtColor(src_mat, gray, cv::COLOR_RGBA2GRAY);
		}
		else
		{
			src_mat.copyTo(gray);
		}
		cv::Mat imageSobel;
		cv::Sobel(gray, imageSobel, CV_16U, 1, 1);
		//图像的平均灰度
		double meanValue = 0.0;
		meanValue = cv::mean(imageSobel)[0];
		return meanValue;
	}
	catch (...)
	{
		return -1;
	}
}

//使用Laplacian梯度法计算一幅图像的清晰度
double frmImageClarity::CalcClarityLaplacian(const cv::Mat src_mat)
{
	try
	{
		cv::Mat gray;
		if (src_mat.channels() == 3)
		{
			cv::cvtColor(src_mat, gray, cv::COLOR_BGR2GRAY);
		}
		else if (src_mat.channels() == 4)
		{
			cv::cvtColor(src_mat, gray, cv::COLOR_RGBA2GRAY);
		}
		else
		{
			src_mat.copyTo(gray);
		}
		cv::Mat imageLaplacian;
		cv::Laplacian(gray, imageLaplacian, CV_16U);
		//图像的平均灰度
		double meanValue = 0.0;
		meanValue = cv::mean(imageLaplacian)[0];
		return meanValue;
	}
	catch (...)
	{
		return -1;
	}
}

//定义变量存最大值的索引
int frmImageClarity::GetMaxAndIndex(const std::vector<double> pa)
{
	try
	{
		//定义一个大小为2的数组来存最大值和最小值
		vector<double> max_and_min(2);
		int index = -1;
		if (pa.size() != 0)
		{
			max_and_min[0] = pa[0];
			index = 0;
			for (int i = 0; i < pa.size(); i++)
			{
				if (max_and_min[0] < pa[i])
				{
					index = i;
					max_and_min[0] = pa[i];
				}
			}
		}
		return index;
	}
	catch (...)
	{
		return -1;
	}
}

QImage frmImageClarity::Mat2QImage(const cv::Mat& mat)
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
