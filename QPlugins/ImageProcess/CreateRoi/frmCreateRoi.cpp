#include "frmCreateRoi.h"
#include <QMessageBox>
#include <QDesktopWidget>

frmCreateRoi::frmCreateRoi(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/roi.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
}

frmCreateRoi::~frmCreateRoi()
{
	this->deleteLater();
}

void frmCreateRoi::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/roi.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmCreateRoi::paintEvent(QPaintEvent* event)
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

void frmCreateRoi::onButtonCloseClicked()
{
	view_contour = false;
	this->close();
}

int frmCreateRoi::Execute(const QString toolname)
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

int frmCreateRoi::RunToolPro()
{
	try
	{
		bool link_state = false;
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		strs.clear();
		strs = ui.txtLinkContour->text().split(".");
		if (strs.size() == 1)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		if (strs[1] == "轮廓")
		{
			for (int n = 0; n < GetToolBase()->m_Tools.size(); n++)
			{
				if (GetToolBase()->m_Tools[n].PublicToolName == strs[0])
				{
					//获取的轮廓在工具数组中的索引
					contour_index = n;
					link_state = true;
				}
			}
			if (link_state == false)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -2;
			}
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -2;
		}
		//单个轮廓的最小和最大外接矩形
		all_contours = mergeContours(GetToolBase()->m_Tools[contour_index].PublicDetect.Contours);
		if (all_contours.size() == 1)
		{
			rect = cv::boundingRect(all_contours[0]);
			rrect = cv::minAreaRect(all_contours[0]);
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		//显示轮廓
		if (view_contour == true)
		{
			srcImage.copyTo(dstImage);
			if (dstImage.channels() == 1)
			{
				cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
			}
			else if (dstImage.channels() == 4)
			{
				cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
			}
			cv::drawContours(dstImage, GetToolBase()->m_Tools[contour_index].PublicDetect.Contours, -1, cv::Scalar(255, 0, 0), 2, cv::LINE_8);
			if (ui.comboType->currentIndex() == 0)
			{
				cv::rectangle(dstImage, rect, cv::Scalar(0, 0, 255), 2);
			}
			else if (ui.comboType->currentIndex() == 1)
			{
				cv::Point2f vertices[4];
				rrect.points(vertices);
				cv::Point root_points[1][4];
				root_points[0][0] = cv::Point(vertices[0].x, vertices[0].y);
				root_points[0][1] = cv::Point(vertices[1].x, vertices[1].y);
				root_points[0][2] = cv::Point(vertices[2].x, vertices[2].y);
				root_points[0][3] = cv::Point(vertices[3].x, vertices[3].y);
				pts.clear();
				pts.push_back(cv::Point(vertices[0].x, vertices[0].y));
				pts.push_back(cv::Point(vertices[1].x, vertices[1].y));
				pts.push_back(cv::Point(vertices[2].x, vertices[2].y));
				pts.push_back(cv::Point(vertices[3].x, vertices[3].y));
				cv::polylines(dstImage, pts, true, cv::Scalar(0, 0, 255), 2);
			}
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = srcImage;
		GetToolBase()->m_Tools[tool_index].PublicImageProcess.CvRect = rect;
		GetToolBase()->m_Tools[tool_index].PublicImageProcess.CvRotatedRect = rrect;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

//合并轮廓
vector<vector<cv::Point>> frmCreateRoi::mergeContours(const vector<vector<cv::Point>> contours)
{
	vector<vector<cv::Point>> allcontours;
	vector<cv::Point> contourslist;
	int count = contours.size();
	for (int i = 0; i < count; i++) {
		vector<cv::Point> vec_i;
		vec_i = contours[i];
		contourslist.insert(contourslist.end(), vec_i.begin(), vec_i.end());
	}	
	allcontours.emplace_back(contourslist);
	return allcontours;
}

int frmCreateRoi::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
			if (strs.size() == 1 || strs[1] != "轮廓")
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

int frmCreateRoi::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmCreateRoi::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	view_contour = true;
	Execute(GetToolName());
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmCreateRoi::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmCreateRoi::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmCreateRoi::on_btnLinkContour_clicked()
{
	QConfig::nFormState = 2;
}

void frmCreateRoi::on_btnDelLinkContour_clicked()
{
	ui.txtLinkContour->clear();
}

QImage frmCreateRoi::Mat2QImage(const cv::Mat& mat)
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
