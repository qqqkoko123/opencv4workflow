#include "frmSkeleton.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include "QGraphicsScenes.h"
#include "BaseItem.h"

#define M_PI 3.14159265358979323846

frmSkeleton::frmSkeleton(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/skeleton.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);	
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	rectangler_item = new RectangleRItem(110, 110, 200, 200, 0);
	circle_item = new CircleItem(110, 110, 100);
	polygon_item = new PolygonItem();
}

frmSkeleton::~frmSkeleton()
{
	view->deleteLater();
	rectangle_item->deleteLater();
	rectangler_item->deleteLater();
	circle_item->deleteLater();
	polygon_item->deleteLater();
	this->deleteLater();
}

void frmSkeleton::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/skeleton.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmSkeleton::paintEvent(QPaintEvent* event)
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

void frmSkeleton::onButtonCloseClicked()
{
	this->close();
}

int frmSkeleton::Execute(const QString toolname)
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

int frmSkeleton::RunToolPro()
{
	try
	{		
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		if (ui.checkUseROI->isChecked() == true)
		{					
			if (ui.comboROIShape->currentIndex() == 0)
			{		
				if (rectangle_item->rect_init_state == false)
				{
					return -1;
				}
				rectangle_item->GetRect(m_rectangle);
				rect = cv::Rect(m_rectangle.col, m_rectangle.row, m_rectangle.width, m_rectangle.height);
				mask = cv::Mat::zeros(srcImage.size(), CV_8UC1);
				mask(rect).setTo(255);
				dst = cv::Mat();
				srcImage.copyTo(dst, mask);
			}
			else if (ui.comboROIShape->currentIndex() == 1)
			{
				if (rectangler_item->rrect_init_state == false)
				{
					return -1;
				}
				rectangler_item->GetRotatedRect(m_rotatedrect);
				mask = cv::Mat::zeros(srcImage.size(), CV_8UC1);
				cv::RotatedRect rrect = cv::RotatedRect(cv::Point2f(m_rotatedrect.col, m_rotatedrect.row), cv::Size2f(m_rotatedrect.lenth1 * 2, m_rotatedrect.lenth2 * 2), -m_rotatedrect.phi * 180 / M_PI);
				cv::Point2f vertices[4];
				rrect.points(vertices);
				cv::Point root_points[1][4];
				root_points[0][0] = cv::Point(vertices[0].x, vertices[0].y);
				root_points[0][1] = cv::Point(vertices[1].x, vertices[1].y);
				root_points[0][2] = cv::Point(vertices[2].x, vertices[2].y);
				root_points[0][3] = cv::Point(vertices[3].x, vertices[3].y);
				const cv::Point* ppt[1] = { root_points[0] };
				int npt[] = { 4 };
				cv::fillPoly(mask, ppt, npt, 1, cv::Scalar(255));
				dst = cv::Mat();
				srcImage.copyTo(dst, mask);
			}
			else if (ui.comboROIShape->currentIndex() == 2)
			{
				if (circle_item->circle_init_state == false)
				{
					return -1;
				}
				circle_item->GetCircle(m_circle);
				mask = cv::Mat::zeros(srcImage.size(), CV_8UC1);
				cv::circle(mask, cv::Point((int)m_circle.col, (int)m_circle.row), (int)m_circle.radius, cv::Scalar(255), -1);
				dst = cv::Mat();
				srcImage.copyTo(dst, mask);
			}
			else if (ui.comboROIShape->currentIndex() == 3)
			{
				if (polygon_item->polygon_init_state == false)
				{
					return -1;
				}
				polygon_item->GetPolygon(m_polygon);
				mask = cv::Mat::zeros(srcImage.size(), CV_8UC1);
				int listp_count = m_polygon.list_p.count();
				cv::Point** root_points = new cv::Point * [1];				
				root_points[0] = new cv::Point[listp_count];
				for (int i = 0; i < listp_count; i++)
				{
					root_points[0][i] = cv::Point(m_polygon.list_p[i].x(), m_polygon.list_p[i].y());
				}
				const cv::Point* ppt[1] = { root_points[0] };
				int npt[] = { listp_count };
				cv::fillPoly(mask, ppt, npt, 1, cv::Scalar(255));
				dst = cv::Mat();
				srcImage.copyTo(dst, mask);		
				delete[] root_points[0];
				root_points[0] = nullptr;
				delete[] root_points;
				root_points = nullptr;					
			}
		}
		else
		{		
			dst = cv::Mat();
			srcImage.copyTo(dst);
		}		
		bool state = ImgThin(dst, dstImage, ui.spinIterateNum->value());	
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;		
		GetToolBase()->m_Tools[tool_index].PublicResult.State = state;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmSkeleton::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmSkeleton::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmSkeleton::InitSetToolData(const QVariant data)
{
	try
	{
		InitSkeletonData init_data;
		init_data = data.value<InitSkeletonData>();
		if (init_data.use_roi == true)
		{
			view->ClearObj();
			if (init_data.type == "rectangle")
			{
				rectangle_item = new RectangleItem(init_data.x, init_data.y, init_data.width, init_data.height);
				rectangle_item->rect_init_state = true;
				view->AddItems(rectangle_item);
			}
			else if (init_data.type == "rotate_rectangle")
			{
				rectangler_item = new RectangleRItem(init_data.x, init_data.y, init_data.Lenth1 * 2, init_data.Lenth2 * 2, init_data.Pi);
				rectangler_item->rrect_init_state = true;
				view->AddItems(rectangler_item);
			}
			else if (init_data.type == "circle")
			{
				circle_item = new CircleItem(init_data.x, init_data.y, init_data.R);
				circle_item->circle_init_state = true;
				view->AddItems(circle_item);
			}
			else if (init_data.type == "polygon")
			{
				view->scene->startCreate();
				polygon_item = new PolygonItem();
				polygon_item->polygon_init_state = true;
				view->scene->addItem(polygon_item);
				connect(view->scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), polygon_item, SLOT(pushPoint(QPointF, QList<QPointF>, bool)), Qt::DirectConnection);
				region_buf = 1;
				for (int i = 0; i <= init_data.list_ps.size(); i++)
				{
					if (i == init_data.list_ps.size())
					{
						emit view->scene->updatePoint(init_data.init_points[i - 1], init_data.list_ps[i - 1], true);
					}
					else
					{
						emit view->scene->updatePoint(init_data.init_points[i], init_data.list_ps[i], false);
					}
				}
			}
		}		
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmSkeleton::InitGetToolData()
{
	InitSkeletonData init_data;
	if (ui.checkUseROI->isChecked() == true)
	{
		init_data.use_roi = true;
		if (ui.comboROIShape->currentIndex() == 0)
		{
			if (rectangle_item->rect_init_state == false)
			{
				return -1;
			}
			rectangle_item->GetRect(m_rectangle);
			init_data.type = "rectangle";
			init_data.x = m_rectangle.col;
			init_data.y = m_rectangle.row;
			init_data.width = m_rectangle.width;
			init_data.height = m_rectangle.height;
		}
		else if (ui.comboROIShape->currentIndex() == 1)
		{
			if (rectangler_item->rrect_init_state == false)
			{
				return -1;
			}
			rectangler_item->GetRotatedRect(m_rotatedrect);
			init_data.type = "rotate_rectangle";
			init_data.x = m_rotatedrect.col;
			init_data.y = m_rotatedrect.row;
			init_data.Lenth1 = m_rotatedrect.lenth1;
			init_data.Lenth2 = m_rotatedrect.lenth2;
			init_data.Pi = m_rotatedrect.phi;
		}
		else if (ui.comboROIShape->currentIndex() == 2)
		{
			if (circle_item->circle_init_state == false)
			{
				return -1;
			}
			circle_item->GetCircle(m_circle);
			init_data.type = "circle";
			init_data.x = m_circle.col;
			init_data.y = m_circle.row;
			init_data.R = m_circle.radius;
		}
		else if (ui.comboROIShape->currentIndex() == 3)
		{
			if (polygon_item->polygon_init_state == false)
			{
				return -1;
			}
			polygon_item->GetPolygon(m_polygon);
			init_data.type = "polygon";
			init_data.init_points = m_polygon.points;
			init_data.list_ps = m_polygon.list_ps;
		}
	}
	else
	{
		init_data.use_roi = false;
	}
	return QVariant::fromValue(init_data);
}

void frmSkeleton::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmSkeleton::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmSkeleton::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmSkeleton::on_btnAddROI_clicked()
{	
	view->ClearObj();
	switch (ui.comboROIShape->currentIndex()) {
	case 0:				
		rectangle_item = new RectangleItem(10, 10, 200, 200);
		rectangle_item->rect_init_state = true;
		view->AddItems(rectangle_item);
		break;
	case 1:
		rectangler_item = new RectangleRItem(110, 110, 200, 200, 0);
		rectangler_item->rrect_init_state = true;
		view->AddItems(rectangler_item);
		break;
	case 2:
		circle_item = new CircleItem(110, 110, 100);
		circle_item->circle_init_state = true;
		view->AddItems(circle_item);
		break;
	case 3:
		if (region_buf == 1)
		{
			disconnect(view->scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), polygon_item, SLOT(pushPoint(QPointF, QList<QPointF>, bool)));
		}
		view->scene->startCreate();
		polygon_item = new PolygonItem();
		polygon_item->polygon_init_state = true;
		view->scene->addItem(polygon_item);
		connect(view->scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), polygon_item, SLOT(pushPoint(QPointF, QList<QPointF>, bool)));
		region_buf = 1;
		break;
	}
}

void frmSkeleton::on_btnDeleteROI_clicked()
{
	rectangle_item->rect_init_state = false;
	rectangler_item->rrect_init_state = false;
	circle_item->circle_init_state = false;
	polygon_item->polygon_init_state = false;
	view->ClearObj();
	switch (ui.comboROIShape->currentIndex()) {
	case 3:
		region_buf = 0;
		disconnect(view->scene, SIGNAL(updatePoint(QPointF, QList<QPointF>, bool)), polygon_item, SLOT(pushPoint(QPointF, QList<QPointF>, bool)));
		break;
	}
}

bool frmSkeleton::ImgThin(cv::Mat& src, cv::Mat& dst, const int intera) const
{
	try
	{
		if (intera == 0)
		{
			src.copyTo(dst);
			return true;
		}
		if (src.channels() == 3)
		{
			cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);
		}
		else if(src.channels() == 4)
		{
			cv::cvtColor(src, src, cv::COLOR_RGBA2GRAY);
		}
		cv::threshold(src, src, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
		src.copyTo(dst);
		int i, j, n;
		int width, height;
		width = src.cols - 1;
		//之所以减1，是方便处理8邻域，防止越界
		height = src.rows - 1;
		int step = src.step;
		int  p2, p3, p4, p5, p6, p7, p8, p9;
		uchar* img;
		bool ifEnd;
		int A1;
		cv::Mat tmpimg;
		//n表示迭代次数
		for (n = 0; n < intera; n++)
		{
			dst.copyTo(tmpimg);
			ifEnd = false;
			img = tmpimg.data;
			for (i = 1; i < height; i++)
			{
				img += step;
				for (j = 1; j < width; j++)
				{
					uchar* p = img + j;
					A1 = 0;
					if (p[0] > 0)
					{
						if (p[-step] == 0 && p[-step + 1] > 0) //p2,p3 
						{
							A1++;
						}
						if (p[-step + 1] == 0 && p[1] > 0) //p3,p4 
						{
							A1++;
						}
						if (p[1] == 0 && p[step + 1] > 0) //p4,p5 
						{
							A1++;
						}
						if (p[step + 1] == 0 && p[step] > 0) //p5,p6 
						{
							A1++;
						}
						if (p[step] == 0 && p[step - 1] > 0) //p6,p7 
						{
							A1++;
						}
						if (p[step - 1] == 0 && p[-1] > 0) //p7,p8 
						{
							A1++;
						}
						if (p[-1] == 0 && p[-step - 1] > 0) //p8,p9 
						{
							A1++;
						}
						if (p[-step - 1] == 0 && p[-step] > 0) //p9,p2 
						{
							A1++;
						}
						p2 = p[-step] > 0 ? 1 : 0;
						p3 = p[-step + 1] > 0 ? 1 : 0;
						p4 = p[1] > 0 ? 1 : 0;
						p5 = p[step + 1] > 0 ? 1 : 0;
						p6 = p[step] > 0 ? 1 : 0;
						p7 = p[step - 1] > 0 ? 1 : 0;
						p8 = p[-1] > 0 ? 1 : 0;
						p9 = p[-step - 1] > 0 ? 1 : 0;
						if ((p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) > 1 && (p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) < 7 && A1 == 1)
						{
							if ((p2 == 0 || p4 == 0 || p6 == 0) && (p4 == 0 || p6 == 0 || p8 == 0)) //p2*p4*p6=0 && p4*p6*p8==0
							{
								dst.at<uchar>(i, j) = 0; //满足删除条件，设置当前像素为0
								ifEnd = true;
							}
						}
					}
				}
			}
			dst.copyTo(tmpimg);
			img = tmpimg.data;
			for (i = 1; i < height; i++)
			{
				img += step;
				for (j = 1; j < width; j++)
				{
					A1 = 0;
					uchar* p = img + j;
					if (p[0] > 0)
					{
						if (p[-step] == 0 && p[-step + 1] > 0) //p2,p3 
						{
							A1++;
						}
						if (p[-step + 1] == 0 && p[1] > 0) //p3,p4 
						{
							A1++;
						}
						if (p[1] == 0 && p[step + 1] > 0) //p4,p5 
						{
							A1++;
						}
						if (p[step + 1] == 0 && p[step] > 0) //p5,p6 
						{
							A1++;
						}
						if (p[step] == 0 && p[step - 1] > 0) //p6,p7 
						{
							A1++;
						}
						if (p[step - 1] == 0 && p[-1] > 0) //p7,p8 
						{
							A1++;
						}
						if (p[-1] == 0 && p[-step - 1] > 0) //p8,p9 
						{
							A1++;
						}
						if (p[-step - 1] == 0 && p[-step] > 0) //p9,p2 
						{
							A1++;
						}
						p2 = p[-step] > 0 ? 1 : 0;
						p3 = p[-step + 1] > 0 ? 1 : 0;
						p4 = p[1] > 0 ? 1 : 0;
						p5 = p[step + 1] > 0 ? 1 : 0;
						p6 = p[step] > 0 ? 1 : 0;
						p7 = p[step - 1] > 0 ? 1 : 0;
						p8 = p[-1] > 0 ? 1 : 0;
						p9 = p[-step - 1] > 0 ? 1 : 0;
						if ((p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) > 1 && (p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) < 7 && A1 == 1)
						{
							if ((p2 == 0 || p4 == 0 || p8 == 0) && (p2 == 0 || p6 == 0 || p8 == 0)) //p2*p4*p8=0 && p2*p6*p8==0
							{
								dst.at<uchar>(i, j) = 0; //满足删除条件，设置当前像素为0
								ifEnd = true;
							}
						}
					}
				}
			}
			if (!ifEnd) break;
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}

QImage frmSkeleton::Mat2QImage(const cv::Mat& mat)
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
