#include "frmMeasureCalibration.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QDesktopWidget>
#include <QGraphicsOpacityEffect>

#define M_PI 3.14159265358979323846

frmMeasureCalibration::frmMeasureCalibration(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/measure_calib.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	caliper_item = new Caliper(10, 160, 200, 160, 300);
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmMeasureCalibration::~frmMeasureCalibration()
{
	view->deleteLater();
	caliper_item->deleteLater();
	this->deleteLater();
}

void frmMeasureCalibration::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/measure_calib.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmMeasureCalibration::paintEvent(QPaintEvent* event)
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

void frmMeasureCalibration::onButtonCloseClicked()
{
	view_state = false;
	this->close();
}

void frmMeasureCalibration::on_comboMode_currentIndexChanged(int index)
{
	switch (index) {
	case 0:
		ui.stackedWidget->setCurrentIndex(0);
		ui.groupROI->setEnabled(false);
		break;
	case 1:
		ui.stackedWidget->setCurrentIndex(1);
		ui.groupROI->setEnabled(true);
		break;
	}
}

int frmMeasureCalibration::Execute(const QString toolname)
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

int frmMeasureCalibration::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		if (view_state == true)
		{
			k = 0;
			b = 0;
			switch (ui.comboMode->currentIndex()) {
			case 0:
				PixelEquivalentX = ui.spinPixelX->value();
				PixelEquivalentY = ui.spinPixelY->value();
				break;
			case 1:
				if (caliper_item->caliper_init_state == false)
				{
					return -1;
				}
				caliper_item->GetCaliper(caliper_p);
				for (int i = 0; i < caliper_item->line_small_points.size(); i++)
				{
					if (caliper_item->line_big_points[i].x() < 0 || caliper_item->line_small_points[i].x() < 0 || caliper_item->line_big_points[i].y() < 0 || caliper_item->line_small_points[i].y() < 0)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
					if (caliper_item->line_big_points[i].x() > dstImage.cols || caliper_item->line_small_points[i].x() > dstImage.cols || caliper_item->line_big_points[i].y() > dstImage.rows || caliper_item->line_small_points[i].y() > dstImage.rows)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
				}
				switch (ui.comboGrayDirection->currentIndex()) {
				case 0:
					direction = 0;
					break;
				case 1:
					direction = 1;
					break;
				}
				xy1.clear();
				xy2.clear();
				int result = GetEdgeWidth(dstImage, caliper_item->line_small_points, caliper_item->line_big_points, xy1, xy2, ui.spinThreshold->value(), direction, ui.spinThreshold->value(), direction, ui.spinSegment->value());
				if (result == -1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				//拟合直线1
				vector<cv::Point2f> new_xy1(xy1.size());
				for (int i = 0; i < xy1.size(); i++)
				{
					new_xy1[i].x = xy1[i].x();
					new_xy1[i].y = xy1[i].y();
				}
				int w = srcImage.cols;
				cv::Vec4f fitline1;
				cv::fitLine(new_xy1, fitline1, cv::DIST_L2, 0, 0.01, 0.01);
				float vx1 = fitline1[0];
				float vy1 = fitline1[1];
				float x1 = fitline1[2];
				float y1 = fitline1[3];
				double x1_1 = w - 1;
				double y1_1 = (w - x1) * vy1 / vx1 + y1;
				double x1_2 = 0;
				double y1_2 = (-x1 * vy1 / vx1) + y1;
				//剔除点1	
				select_xy1.clear();
				cull_xy1.clear();
				for (int i = 0; i < new_xy1.size(); i++)
				{
					//计算点到直线的距离
					double distance = GetDistP2L(new_xy1[i], cv::Point2f(x1_1, y1_1), cv::Point2f(x1_2, y1_2));
					if (distance > ui.spinCullDistance->value())
					{
						cull_xy1.push_back(new_xy1[i]);
					}
					else
					{
						select_xy1.push_back(new_xy1[i]);
					}
				}
				//剔除点后再次拟合直线1
				cv::fitLine(select_xy1, fitline1, cv::DIST_L2, 0, 0.01, 0.01);
				vx1 = fitline1[0];
				vy1 = fitline1[1];
				x1 = fitline1[2];
				y1 = fitline1[3];
				x1_1 = w - 1;
				y1_1 = (w - x1) * vy1 / vx1 + y1;
				x1_2 = 0;
				y1_2 = (-x1 * vy1 / vx1) + y1;
				//拟合直线2
				vector<cv::Point2f> new_xy2(xy2.size());
				for (int i = 0; i < xy2.size(); i++)
				{
					new_xy2[i].x = xy2[i].x();
					new_xy2[i].y = xy2[i].y();
				}
				cv::Vec4f fitline2;
				cv::fitLine(new_xy2, fitline2, cv::DIST_L2, 0, 0.01, 0.01);
				float vx2 = fitline2[0];
				float vy2 = fitline2[1];
				float x2 = fitline2[2];
				float y2 = fitline2[3];
				double x2_1 = w - 1;
				double y2_1 = (w - x2) * vy2 / vx2 + y2;
				double x2_2 = 0;
				double y2_2 = (-x2 * vy2 / vx2) + y2;
				//剔除点2	
				select_xy2.clear();
				cull_xy2.clear();
				for (int i = 0; i < new_xy2.size(); i++)
				{
					//计算点到直线的距离
					double distance = GetDistP2L(new_xy2[i], cv::Point2f(x2_1, y2_1), cv::Point2f(x2_2, y2_2));
					if (distance > ui.spinCullDistance->value())
					{
						cull_xy2.push_back(new_xy2[i]);
					}
					else
					{
						select_xy2.push_back(new_xy2[i]);
					}
				}
				//输出结果
				vector<double> out_distances(select_xy2.size());
				for (int i = 0; i < select_xy2.size(); i++)
				{
					//计算点到直线的距离
					double distance = GetDistP2L(select_xy2[i], cv::Point2f(x1_1, y1_1), cv::Point2f(x1_2, y1_2));
					out_distances[i] = distance;
				}
				//去除最大最小值求平均值
				switch (ui.comboXYDirection->currentIndex()) {
				case 0:
					PixelEquivalentX = (double)ui.spinActualSize->value() / Average(out_distances, out_distances.size());
					break;
				case 1:
					PixelEquivalentY = (double)ui.spinActualSize->value() / Average(out_distances, out_distances.size());
					break;
				}
				if (dstImage.channels() == 1)
				{
					cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
				}
				else if (dstImage.channels() == 4)
				{
					cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
				}
				for (int n = 0; n < select_xy1.size(); n++)
				{
					cv::line(dstImage, cv::Point(select_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(select_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
				}
				for (int n = 0; n < cull_xy1.size(); n++)
				{
					cv::line(dstImage, cv::Point(cull_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(cull_xy1[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy1[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy1[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
				}
				for (int n = 0; n < select_xy2.size(); n++)
				{
					cv::line(dstImage, cv::Point(select_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(select_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
				}
				for (int n = 0; n < cull_xy2.size(); n++)
				{
					cv::line(dstImage, cv::Point(cull_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(cull_xy2[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy2[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy2[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
				}
				cv::RotatedRect rrect = cv::RotatedRect(cv::Point2f(caliper_p.col, caliper_p.row), cv::Size2f(caliper_p.len1, caliper_p.len2), -(caliper_p.angle * 180 / M_PI));
				cv::Point2f vertices[4];
				rrect.points(vertices);
				cv::line(dstImage, cv::Point(vertices[0].x, vertices[0].y), cv::Point(vertices[1].x, vertices[1].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstImage, cv::Point(vertices[0].x, vertices[0].y), cv::Point(vertices[3].x, vertices[3].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstImage, cv::Point(vertices[1].x, vertices[1].y), cv::Point(vertices[2].x, vertices[2].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstImage, cv::Point(vertices[2].x, vertices[2].y), cv::Point(vertices[3].x, vertices[3].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				GetToolBase()->m_Tools[tool_index].PublicImage.Name = "图像";
				break;
			}
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			GetToolBase()->m_Tools[tool_index].PublicCalib.PixelEquivalentX = PixelEquivalentX;
			GetToolBase()->m_Tools[tool_index].PublicCalib.PixelEquivalentY = PixelEquivalentY;
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

int frmMeasureCalibration::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmMeasureCalibration::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmMeasureCalibration::InitSetToolData(const QVariant data)
{
	try
	{
		InitMeasureCalibrationData init_data;
		init_data = data.value<InitMeasureCalibrationData>();		
		PixelEquivalentX = init_data.PixelEquivalentX;
		PixelEquivalentY = init_data.PixelEquivalentY;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmMeasureCalibration::InitGetToolData()
{
	InitMeasureCalibrationData init_data;	
	init_data.PixelEquivalentX = PixelEquivalentX;
	init_data.PixelEquivalentY = PixelEquivalentY;
	return QVariant::fromValue(init_data);
}

void frmMeasureCalibration::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	view_state = true;
	Execute(GetToolName());
	ui.txtMsg->clear();
	ui.txtMsg->append("X方向的像素当量为：" + QString::number(PixelEquivalentX));
	ui.txtMsg->append("Y方向的像素当量为：" + QString::number(PixelEquivalentY));
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmMeasureCalibration::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmMeasureCalibration::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmMeasureCalibration::on_btnAddROI_clicked()
{
	view->ClearObj();
	caliper_item = new Caliper(10, 160, 200, 160, 300);
	caliper_item->caliper_init_state = true;
	switch (ui.comboROIShape->currentIndex()) {
	case 0:
		caliper_item->segment_line_num = ui.spinSegment->value();
		view->AddItems(caliper_item);
		break;
	}
}

void frmMeasureCalibration::on_btnDeleteROI_clicked()
{
	caliper_item->caliper_init_state = false;
	view->ClearObj();
}

void frmMeasureCalibration::on_spinSegment_valueChanged(int value)
{
	caliper_item->segment_line_num = value;
}

//获取边缘宽度
//threshold_delta为阈值；direction的值为0时代表“从白到黑”寻找边界点，direction的值为1时代表“从黑到白”寻找边界点
//segment_num为分割线数量	
int frmMeasureCalibration::GetEdgeWidth(const cv::Mat& src_mat, const std::vector<QPointF> line_small_points, const std::vector<QPointF> line_big_points, vector<QPointF>& edge_points1, vector<QPointF>& edge_points2, const int threshold_delta1, const int direction1, const int threshold_delta2, const int direction2, const int segment_num)
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
		int ww = gray.cols;
		int hh = gray.rows;
		int bytes = ww * hh;
		vector<unsigned char> rgbValues(bytes);
		QPixmap pixmap = QPixmap::fromImage(Mat2QImage(gray));
		QImage img = pixmap.toImage();
		unsigned char* pData = img.bits();
		for (int i = 0; i < ww * hh * 4; i += 4)
		{
			rgbValues[i / 4] = pData[i];
		}
		vector<unsigned char> buffer8(bytes);
		buffer8 = rgbValues;
		//边界点                   
		vector<QPointF> backPoint1(segment_num);
		vector<QPointF> backOutPoint1(segment_num);
		vector<QPointF> backPoint2(segment_num);
		vector<QPointF> backOutPoint2(segment_num);
		//寻找边界点		
		int m1 = 0;
		int m2 = 0;
		//计算两点间的距离
		double distance;
		distance = pow((line_small_points[0].x() - line_big_points[0].x()), 2) + pow((line_small_points[0].y() - line_big_points[0].y()), 2);
		distance = sqrt(distance);
		//线图像上每一个点灰度颜色
		QList<float> temparrclor1 = QList<float>();
		temparrclor1.reserve(5000);
		QList<float> temparrclor2 = QList<float>();
		temparrclor2.reserve(5000);
		//线图像上每一个点坐标
		QList<QPointF> position1 = QList<QPointF>();
		position1.reserve(5000);
		QList<QPointF> position2 = QList<QPointF>();
		position2.reserve(5000);
		for (int k = 0; k < segment_num; k++)
		{
			temparrclor1.clear();
			position1.clear();
			float x_point1;
			float y_point1;
			//从line_small_points往line_big_points扫描
			for (int n = 0; n < (int)distance; n++)
			{
				x_point1 = (n * (line_big_points[k].x() - line_small_points[k].x())) / distance + line_small_points[k].x();
				y_point1 = (n * (line_big_points[k].y() - line_small_points[k].y())) / distance + line_small_points[k].y();
				float tempf = abs(y_point1 - (int)y_point1);
				QPointF tempPt = QPointF(x_point1, y_point1);
				float avgGrey = (float)buffer8[(int)y_point1 * ww + (int)x_point1];
				float avgGrey1 = (float)buffer8[(int)(y_point1 + 1) * ww + (int)x_point1];
				float grey = avgGrey * (1 - tempf) + avgGrey1 * tempf;
				//插值灰度
				temparrclor1.push_back(grey);
				position1.push_back(tempPt);
			}
			//找穿越点
			QPointF return_point1 = FindCrosspointimprove(temparrclor1, position1, direction1, threshold_delta1);
			if (return_point1 != QPointF(0, 0))
			{
				backPoint1[m1] = return_point1;
				m1 += 1;
			}
			temparrclor2.clear();
			position2.clear();
			float x_point2;
			float y_point2;
			//从line_big_points往line_small_points扫描
			for (int n = 0; n < (int)distance; n++)
			{
				x_point2 = (n * (line_small_points[k].x() - line_big_points[k].x())) / distance + line_big_points[k].x();
				y_point2 = (n * (line_small_points[k].y() - line_big_points[k].y())) / distance + line_big_points[k].y();
				float tempf = abs(y_point2 - (int)y_point2);
				QPointF tempPt = QPointF(x_point2, y_point2);
				float avgGrey = (float)buffer8[(int)y_point2 * ww + (int)x_point2];
				float avgGrey1 = (float)buffer8[(int)(y_point2 + 1) * ww + (int)x_point2];
				float grey = avgGrey * (1 - tempf) + avgGrey1 * tempf;
				//插值灰度
				temparrclor2.push_back(grey);
				position2.push_back(tempPt);
			}
			//找穿越点
			QPointF return_point2 = FindCrosspointimprove(temparrclor2, position2, direction2, threshold_delta2);
			if (return_point2 != QPointF(0, 0))
			{
				backPoint2[m2] = return_point2;
				m2 += 1;
			}
		}
		backOutPoint1.resize(m1);
		for (int n = 0; n < m1; n++)
		{
			backOutPoint1[n] = backPoint1[n];
		}
		edge_points1 = backOutPoint1;
		backOutPoint2.resize(m2);
		for (int n = 0; n < m2; n++)
		{
			backOutPoint2[n] = backPoint2[n];
		}
		edge_points2 = backOutPoint2;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

//梯度和求穿越点
QPointF frmMeasureCalibration::FindCrosspointimprove(const QList<float>& lineTiDu, const QList<QPointF>& ijRecord, const int direction, const int threshold_delta)
{
	try
	{
		//梯度和求穿越点，使用五个一组
		QList<float> deltatemp = QList<float>();
		deltatemp.reserve(5000);
		deltatemp.clear();
		QList<float> fenzuaverage = QList<float>();
		fenzuaverage.reserve(5000);
		fenzuaverage.clear();
		for (int i = 0; i < lineTiDu.size() - 1; i++)
		{
			float grey1 = lineTiDu[i + 1];
			float delta = (lineTiDu[i] - grey1);
			if (abs(delta) < 5)
				delta = 0;
			deltatemp.push_back(delta);
		}
		int fenzuC = deltatemp.size() / 5;
		for (int i = 0; i < fenzuC * 5; i += 5)
		{
			float sum5 = deltatemp[i] + deltatemp[i + 1] + deltatemp[i + 2] + deltatemp[i + 3] + deltatemp[i + 4];
			float aver = sum5 / 5;
			if (abs(aver) < 5)
				aver = 0;
			fenzuaverage.push_back(aver);
		}
		if (fenzuaverage.size() == 0) return QPointF();
		int crosspoint = 0;
		int crosspoint1 = 0;
		//从白到黑寻找
		if (direction == 0)
		{
			for (int iii = fenzuaverage.size() - 1; iii >= 0; iii--) //排除起点和终点
			{
				if (fenzuaverage[iii] > 0)
				{
					crosspoint = 5 * (iii);
					break;
				}
			}
			float maxVar = deltatemp[crosspoint];
			for (int m = -5; m < 5; m++)
			{
				int tempint = crosspoint + m;
				if (crosspoint == 0)
					tempint = 0;
				if (deltatemp[tempint] >= maxVar)
				{
					maxVar = deltatemp[tempint];
					crosspoint1 = tempint;
				}
			}
		}
		//从黑到白寻找
		else if (direction == 1)
		{
			for (int iii = 0; iii <= fenzuaverage.size() - 1; iii++) //排除起点和终点
			{
				if (fenzuaverage[iii] < 0)
				{
					crosspoint = 5 * (iii);
					break;
				}
			}
			float minVar = deltatemp[crosspoint];
			for (int m = -5; m < 5; m++)
			{
				int tempint = crosspoint + m;
				if (crosspoint == 0)
					tempint = 0;
				if (deltatemp[tempint] <= minVar)
				{
					minVar = deltatemp[tempint];
					crosspoint1 = tempint;
				}
			}
		}
		//阈值判别
		if (fenzuaverage[crosspoint / 5] * 5 >= threshold_delta || fenzuaverage[crosspoint / 5] * 5 <= -threshold_delta)
		{
			//穿越点的index对应坐标(crosspoint1为线图像中穿越点index)
			return ijRecord[crosspoint1];
		}
		else
		{
			return QPointF(0, 0); //没有穿越点，返回（0,0）
		}
	}
	catch (...)
	{
		return QPointF(0, 0); //没有穿越点，返回（0,0）
	}
}

//计算点到直线的距离(P为线外一点，AB为线段两个端点)
double frmMeasureCalibration::GetDistP2L(const cv::Point2f pointP, const cv::Point2f pointA, const cv::Point2f pointB)
{
	//求直线方程
	double A = 0, B = 0, C = 0;
	A = pointA.y - pointB.y;
	B = pointB.x - pointA.x;
	C = pointA.x * pointB.y - pointA.y * pointB.x;
	double distance = 0;
	distance = ((double)abs(A * pointP.x + B * pointP.y + C)) / ((double)sqrtf(A * A + B * B));
	return distance;
}

//去除最大最小值求平均值
double frmMeasureCalibration::Average(const vector<double> arrays, const int n)
{
	double max = arrays[0];
	double min = arrays[0];
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arrays[i];
		max = max < arrays[i] ? arrays[i] : max;
		min = min > arrays[i] ? arrays[i] : min;
	}
	return (sum - max - min) / (n - 2);
}

QImage frmMeasureCalibration::Mat2QImage(const cv::Mat& mat)
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
