#include "frmCamShiftTrack.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>

frmCamShiftTrack::frmCamShiftTrack(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/track.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	rectangle_item = new RectangleItem(10, 10, 200, 200);
}

frmCamShiftTrack::~frmCamShiftTrack()
{
	view->deleteLater();
	rectangle_item->deleteLater();
	this->deleteLater();
}

void frmCamShiftTrack::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/track.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmCamShiftTrack::paintEvent(QPaintEvent* event)
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

void frmCamShiftTrack::onButtonCloseClicked()
{
	this->close();
}

int frmCamShiftTrack::Execute(const QString toolname)
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

int frmCamShiftTrack::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		if (ui.comboROIShape->currentIndex() == 0)
		{
			if (rectangle_item->rect_init_state == false)
			{
				srcImage.copyTo(dstImage);
				return -1;
			}
			rectangle_item->GetRect(MRect);
			rect = cv::Rect(MRect.col, MRect.row, MRect.width, MRect.height);
		}
		cv::RotatedRect trackBox;
		bool state = CamShiftCheck(srcImage, rect, dstImage, trackBox, ui.spinSMin->value(), ui.spinKSize->value(), ui.spinLineW->value());
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		GetToolBase()->m_Tools[tool_index].PublicTPosition.CvRotatedRect = trackBox;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = state;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmCamShiftTrack::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmCamShiftTrack::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmCamShiftTrack::InitSetToolData(const QVariant data)
{
	try
	{
		InitCamShiftTrackData init_data;
		init_data = data.value<InitCamShiftTrackData>();
		if (init_data.use_roi == true)
		{
			view->ClearObj();
			rectangle_item = new RectangleItem(init_data.x, init_data.y, init_data.width, init_data.height);
			rectangle_item->rect_init_state = true;
			view->AddItems(rectangle_item);
		}	
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmCamShiftTrack::InitGetToolData()
{
	InitCamShiftTrackData init_data;
	if (ui.checkUseROI->isChecked() == true)
	{
		init_data.use_roi = true;
		if (rectangle_item->rect_init_state == false)
		{
			return -1;
		}
		rectangle_item->GetRect(MRect);
		init_data.x = MRect.col;
		init_data.y = MRect.row;
		init_data.width = MRect.width;
		init_data.height = MRect.height;		
	}
	else
	{
		init_data.use_roi = false;
	}
	return QVariant::fromValue(init_data);
}

void frmCamShiftTrack::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmCamShiftTrack::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmCamShiftTrack::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmCamShiftTrack::on_btnAddROI_clicked()
{
	view->ClearObj();
	switch (ui.comboROIShape->currentIndex()) {
	case 0:
		rectangle_item = new RectangleItem(10, 10, 200, 200);
		rectangle_item->rect_init_state = true;
		view->AddItems(rectangle_item);
		break;
	}
}

void frmCamShiftTrack::on_btnDeleteROI_clicked()
{
	rectangle_item->rect_init_state = false;
	view->ClearObj();
}

bool frmCamShiftTrack::CamShiftCheck(cv::Mat src_mat, cv::Rect rect, cv::Mat& dst_mat, cv::RotatedRect& trackBox, const int smin, const int ksize, const int line_width) const
{
	try
	{
		if (src_mat.channels() == 1)
		{
			cv::cvtColor(src_mat, src_mat, cv::COLOR_GRAY2BGR);
		}
		else if (src_mat.channels() == 4)
		{
			cv::cvtColor(src_mat, src_mat, cv::COLOR_RGBA2BGR);
		}
		int vmin = 10, vmax = 256;
		int hsize = 256;
		float hranges[] = { 0,180 };
		const float* phranges = hranges;
		cv::Mat hsv, hue, mask, hist, backproj;
		cv::cvtColor(src_mat, hsv, cv::COLOR_BGR2HSV);
		cv::inRange(hsv, cv::Scalar(0, smin, vmin), cv::Scalar(180, 256, vmax), mask);
		int ch[] = { 0, 0 };
		hue.create(hsv.size(), hsv.depth());
		cv::mixChannels(&hsv, 1, &hue, 1, ch, 1);
		cv::Mat roi(hue, rect), maskroi(mask, rect);
		cv::calcHist(&roi, 1, 0, maskroi, hist, 1, &hsize, &phranges);
		cv::normalize(hist, hist, 0, 255, cv::NORM_MINMAX);
		cv::calcBackProject(&hue, 1, 0, hist, backproj, &phranges);
		cv::medianBlur(backproj, backproj, 2 * ksize - 1);
		backproj &= mask;
		trackBox = cv::CamShift(backproj, rect, cv::TermCriteria(cv::TermCriteria::EPS | cv::TermCriteria::COUNT, 10, 1));
		if (rect.area() <= 1)
		{
			int cols = backproj.cols, rows = backproj.rows, r = (MIN(cols, rows) + 5) / 6;
			rect = cv::Rect(rect.x - r, rect.y - r, rect.x + r, rect.y + r) & cv::Rect(0, 0, cols, rows);
		}
		//绘制旋转矩形
		dst_mat = src_mat.clone();
		cv::Point2f vertices[4];
		trackBox.points(vertices);
		cv::Point point_1 = (cv::Point)vertices[0];
		cv::Point point_2 = (cv::Point)vertices[1];
		cv::Point point_3 = (cv::Point)vertices[2];
		cv::Point point_4 = (cv::Point)vertices[3];
		cv::line(dst_mat, point_1, point_2, cv::Scalar(0, 255, 0), line_width);
		cv::line(dst_mat, point_1, point_4, cv::Scalar(0, 255, 0), line_width);
		cv::line(dst_mat, point_2, point_3, cv::Scalar(0, 255, 0), line_width);
		cv::line(dst_mat, point_3, point_4, cv::Scalar(0, 255, 0), line_width);
		return true;
	}
	catch (...)
	{
		return false;
	}
}

QImage frmCamShiftTrack::Mat2QImage(const cv::Mat& mat)
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
