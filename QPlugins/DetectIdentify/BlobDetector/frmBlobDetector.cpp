#include "frmBlobDetector.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include "QGraphicsScenes.h"
#include "ImageItem.h"
#include <QColorDialog>

#define M_PI 3.14159265358979323846

frmBlobDetector::frmBlobDetector(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/blob.png"));
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//连接信号与槽		
	connect(this, &frmBlobDetector::sig_BlobValue, view->item, &ImageItem::slot_BlobValue);
	//初始化标题栏
	initTitleBar();
	ui.btnRoiColor->setStyleSheet("background-color: rgb(0, 255, 0)");
	color = QColor(0, 255, 0);	
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	rectangler_item = new RectangleRItem(110, 110, 200, 200, 0);
	circle_item = new CircleItem(110, 110, 100);
	polygon_item = new PolygonItem();
}

frmBlobDetector::~frmBlobDetector()
{
	view->deleteLater();
	rectangle_item->deleteLater();
	rectangler_item->deleteLater();
	circle_item->deleteLater();
	polygon_item->deleteLater();
	this->deleteLater();
}

void frmBlobDetector::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/blob.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmBlobDetector::paintEvent(QPaintEvent* event)
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

void frmBlobDetector::onButtonCloseClicked()
{
	this->close();
}

int frmBlobDetector::Execute(const QString toolname)
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

int frmBlobDetector::RunToolPro()
{
	try
	{
		//设置SimpleBlobDetector参数
		cv::SimpleBlobDetector::Params params;
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		dstRoiImage = cv::Mat();
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
				pts.clear();
				pts.push_back(cv::Point(vertices[0].x, vertices[0].y));
				pts.push_back(cv::Point(vertices[1].x, vertices[1].y));
				pts.push_back(cv::Point(vertices[2].x, vertices[2].y));
				pts.push_back(cv::Point(vertices[3].x, vertices[3].y));
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
				pts.clear();				
				for (int i = 0; i < listp_count; i++)
				{
					root_points[0][i] = cv::Point(m_polygon.list_p[i].x(), m_polygon.list_p[i].y());
					pts.push_back(cv::Point(m_polygon.list_p[i].x(), m_polygon.list_p[i].y()));
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
		//面积
		if (ui.checkArea->isChecked() == true)
		{
			params.filterByArea = true;
			params.minArea = ui.spinMinArea->value();
			params.maxArea = ui.spinMaxArea->value();
		}
		//灰度值
		if (ui.checkGrayscale->isChecked() == true)
		{
			params.filterByColor = true;
			switch (ui.comboColor->currentIndex()) {
			case 0:
				params.blobColor = 0;
				break;
			case 1:
				params.blobColor = 255;
				break;
			}
			params.minThreshold = ui.spinMinThreshold->value();
			params.maxThreshold = ui.spinMaxThreshold->value();
		}
		//圆度
		if (ui.checkCircularity->isChecked() == true)
		{
			params.filterByCircularity = true;
			params.minCircularity = ui.spinMinCircularity->value();
			params.maxCircularity = ui.spinMaxCircularity->value();
		}
		//凸度
		if (ui.checkConvexity->isChecked() == true)
		{
			params.filterByConvexity = true;
			params.minConvexity = ui.spinMinConvexity->value();
			params.maxConvexity = ui.spinMaxConvexity->value();
		}
		//惯性(直线的惯性接近于0，圆的惯性接近于1)
		if (ui.checkInertia->isChecked() == true)
		{
			params.filterByInertia = true;
			params.minInertiaRatio = ui.spinMinInertia->value();
			params.maxInertiaRatio = ui.spinMaxInertia->value();
		}
		//存储blob
		keypoints.reserve(1000000);
		keypoints.clear();
		//使用参数设置检测器		
		detector = cv::SimpleBlobDetector::create(params);
		//检测斑点
		detector->detect(dst, keypoints);		
		cv::drawKeypoints(srcImage, keypoints, dstImage, cv::Scalar(255, 0, 0), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		if (ui.checkUseROI->isChecked() == true && ui.checkViewROI->isChecked() == true)
		{
			dstRoiImage = dstImage.clone();
			GetToolBase()->m_Tools[tool_index].PublicImage.Name = "ROI图像";
			if (ui.comboROIShape->currentIndex() == 0)
			{
				cv::rectangle(dstRoiImage, rect, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			}
			else if (ui.comboROIShape->currentIndex() == 1)
			{				
				cv::polylines(dstRoiImage, pts, true, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			}
			else if (ui.comboROIShape->currentIndex() == 2)
			{
				cv::circle(dstRoiImage, cv::Point((int)m_circle.col, (int)m_circle.row), (int)m_circle.radius, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			}
			else if (ui.comboROIShape->currentIndex() == 3)
			{				
				cv::polylines(dstRoiImage, pts, true, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			}			
		}		
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicImage.Name = "图像";
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;		
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;	
		GetToolBase()->m_Tools[tool_index].PublicDetect.Quantity = keypoints.size();
		if (keypoints.size() == 0)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		}
		else
		{
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

int frmBlobDetector::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmBlobDetector::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmBlobDetector::InitSetToolData(const QVariant data)
{
	try
	{
		InitBlobDetectorData init_data;
		init_data = data.value<InitBlobDetectorData>();
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
			color = init_data.color;
			//设置按钮背景颜色
			QString style_color = "background-color: rgb(" + QString::number(color.red()) + "," + QString::number(color.green()) + "," + QString::number(color.blue()) + ")";
			ui.btnRoiColor->setStyleSheet(style_color);
		}		
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmBlobDetector::InitGetToolData()
{
	InitBlobDetectorData init_data;
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
			init_data.color = color;
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
			init_data.color = color;
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
			init_data.color = color;
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
			init_data.color = color;
		}
	}
	else
	{
		init_data.use_roi = false;
	}
	return QVariant::fromValue(init_data);
}

void frmBlobDetector::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	QString msg = "Blob检测返回个数为：" + QString::number(GetToolBase()->m_Tools[tool_index].PublicDetect.Quantity);
	emit sig_BlobValue(msg);
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmBlobDetector::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmBlobDetector::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmBlobDetector::on_btnAddROI_clicked()
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

void frmBlobDetector::on_btnDeleteROI_clicked()
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

void frmBlobDetector::on_btnRoiColor_clicked()
{
	QColorDialog dlg(this);
	dlg.setMinimumSize(547, 393);
	dlg.setWindowTitle("Color Editor");
	dlg.setCurrentColor(QColor(100, 111, 222));
	dlg.setWindowIcon(QIcon(":/resource/color_edit.png"));	
	if (dlg.exec() == QColorDialog::Accepted)
	{
		color = dlg.selectedColor();
		//设置按钮背景颜色
		ui.btnRoiColor->setAutoFillBackground(true);
		ui.btnRoiColor->setFlat(true);
		QPalette palette = ui.btnRoiColor->palette();
		palette.setColor(QPalette::Button, color);
		ui.btnRoiColor->setPalette(palette);
	}
}

QImage frmBlobDetector::Mat2QImage(const cv::Mat& mat)
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
