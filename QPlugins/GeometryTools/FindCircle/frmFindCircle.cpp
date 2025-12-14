#include "frmFindCircle.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QDesktopWidget>
#include "BaseItem.h"
#include <QGraphicsOpacityEffect>

#define M_PI 3.14159265358979323846

frmFindCircle::frmFindCircle(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/find_circle.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	ui.btnRoiColor->setStyleSheet("background-color: rgb(0, 0, 255)");
	color = QColor(0, 0, 255);
	concentric_circle_item = new ConcentricCircleItem(220, 220, 100, 200);
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmFindCircle::~frmFindCircle()
{
	view->deleteLater();
	concentric_circle_item->deleteLater();
	this->deleteLater();
}

void frmFindCircle::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/find_circle.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmFindCircle::paintEvent(QPaintEvent* event)
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

void frmFindCircle::onButtonCloseClicked()
{
	view_points = false;
	this->close();
}

int frmFindCircle::Execute(const QString toolname)
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

int frmFindCircle::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		Center = cv::Point2f(0, 0);
		Radius = 0;
		dstImage = cv::Mat();
		dstRoiImage = cv::Mat();
		srcImage.copyTo(dstImage);
		if (concentric_circle_item->concentric_circle_init_state == false)
		{
			return -1;
		}
		concentric_circle_item->GetConcentricCircle(c_circle);
		switch (ui.comboScanDirection->currentIndex()) {
		case 0:
			in_out_circle = 0;
			break;
		case 1:
			in_out_circle = 1;
			break;
		}
		switch (ui.comboGrayDirection->currentIndex()) {
		case 0:
			direction = 0;
			break;
		case 1:
			direction = 1;
			break;
		}
		for (int i = 0; i < concentric_circle_item->ring_small_points.size(); i++)
		{
			if (concentric_circle_item->ring_big_points[i].x() < 0 || concentric_circle_item->ring_small_points[i].x() < 0 || concentric_circle_item->ring_big_points[i].y() < 0 || concentric_circle_item->ring_small_points[i].y() < 0)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
			if (concentric_circle_item->ring_big_points[i].x() > dstImage.cols || concentric_circle_item->ring_small_points[i].x() > dstImage.cols || concentric_circle_item->ring_big_points[i].y() > dstImage.rows || concentric_circle_item->ring_small_points[i].y() > dstImage.rows)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
		}
		xy.clear();
		ring_small_points.clear();
		ring_big_points.clear();
		ring_small_points = concentric_circle_item->ring_small_points;
		ring_big_points = concentric_circle_item->ring_big_points;
		//位置跟随
		if (ui.checkUseFollow->isChecked() == true)
		{
			strs.clear();
			strs = ui.txtLinkFollow->text().split(".");
			if (strs.size() == 1)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
			bool link_state = false;
			int f_index = 0;
			for (int i = 0; i < GetToolBase()->m_Tools.size(); i++)
			{
				if (GetToolBase()->m_Tools[i].PublicToolName == strs[0])
				{
					f_index = i;
					link_state = true;
				}
			}
			if (link_state == false)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -2;
			}
			if (strs[1] == "匹配基准中心")
			{
				if (GetToolBase()->m_Tools[f_index].PublicTPosition.Center.size() == 0)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				match_origin_point = GetToolBase()->m_Tools[f_index].PublicTPosition.DatumCenter;
				match_origin_angle = 0;
				match_current_point = GetToolBase()->m_Tools[f_index].PublicTPosition.Center[0];
				match_current_angle = GetToolBase()->m_Tools[f_index].PublicTPosition.Angle[0];
				for (int p = 0; p < ring_small_points.size(); p++)
				{
					cv::Point2f point_small_buf = cv::Point2f(ring_small_points[p].x(), ring_small_points[p].y());
					cv::Point2f point_small = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, point_small_buf);
					ring_small_points[p] = QPointF(point_small.x, point_small.y);
					cv::Point2f point_big_buf = cv::Point2f(ring_big_points[p].x(), ring_big_points[p].y());
					cv::Point2f point_big = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, point_big_buf);
					ring_big_points[p] = QPointF(point_big.x, point_big.y);
				}
			}
			else
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -2;
			}
		}
		int result = FindBorderPoints(dstImage, ring_small_points, ring_big_points, xy, ui.spinThreshold->value(), direction, in_out_circle, ui.spinSegment->value());
		if (result == -1)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		//拟合圆    
		Box fit_circle{ 0 };
		vector<cv::Point2f> new_xy(xy.size());
		for (int i = 0; i < xy.size(); i++)
		{
			new_xy[i].x = xy[i].x();
			new_xy[i].y = xy[i].y();
		}
		fit_circle = fitCircle(new_xy);
		Center.x = fit_circle.x;
		Center.y = fit_circle.y;
		Radius = fit_circle.r;
		//剔除点		
		select_xy.clear();
		cull_xy.clear();
		for (int i = 0; i < new_xy.size(); i++)
		{
			//计算两点之间的距离
			float distance;
			distance = powf((new_xy[i].x - Center.x), 2) + powf((new_xy[i].y - Center.y), 2);
			distance = sqrtf(distance);
			if (Radius - distance > ui.spinCullDistance->value())
			{
				cull_xy.push_back(new_xy[i]);
			}
			else
			{
				select_xy.push_back(new_xy[i]);
			}
		}
		fit_circle = fitCircle(select_xy);
		Center.x = fit_circle.x;
		Center.y = fit_circle.y;
		Radius = fit_circle.r;
		if (dstImage.channels() == 1)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
		}
		else if (dstImage.channels() == 4)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
		}
		cv::circle(dstImage, Center, Radius, cv::Scalar(37, 193, 255), 2);
		if (ui.checkViewROI->isChecked() == true)
		{
			dstRoiImage = dstImage.clone();
			if (dstRoiImage.channels() == 1)
			{
				cv::cvtColor(dstRoiImage, dstRoiImage, cv::COLOR_GRAY2BGR);
			}
			else if (dstRoiImage.channels() == 4)
			{
				cv::cvtColor(dstRoiImage, dstRoiImage, cv::COLOR_RGBA2BGR);
			}
			GetToolBase()->m_Tools[tool_index].PublicImage.Name = "ROI图像";
			for (int i = 0; i < ring_small_points.size(); i++)
			{
				cv::line(dstRoiImage, cv::Point(ring_small_points[i].x(), ring_small_points[i].y()), cv::Point(ring_big_points[i].x(), ring_big_points[i].y()), cv::Scalar(223, 231, 255), 1);
			}
			for (int n = 0; n < select_xy.size(); n++)
			{
				cv::line(dstRoiImage, cv::Point(select_xy[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
				cv::line(dstRoiImage, cv::Point(select_xy[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
			}
			for (int n = 0; n < cull_xy.size(); n++)
			{
				cv::line(dstRoiImage, cv::Point(cull_xy[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
				cv::line(dstRoiImage, cv::Point(cull_xy[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
			}
			cv::Point2f cir_center = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, cv::Point2f(c_circle.col, c_circle.row));
			cv::circle(dstRoiImage, cv::Point(cir_center.x, cir_center.y), c_circle.big_radius, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			cv::circle(dstRoiImage, cv::Point(cir_center.x, cir_center.y), c_circle.small_radius, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
		}
		else
		{
			if (view_points == true)
			{
				for (int n = 0; n < select_xy.size(); n++)
				{
					cv::line(dstImage, cv::Point(select_xy[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(select_xy[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(select_xy[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), select_xy[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(211, 0, 141), ui.spinRoiW->value());
				}
				for (int n = 0; n < cull_xy.size(); n++)
				{
					cv::line(dstImage, cv::Point(cull_xy[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
					cv::line(dstImage, cv::Point(cull_xy[n].x - cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy[n].y + sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Point(cull_xy[n].x + cos(45 * M_PI / 180) * ui.spinCrossL->value(), cull_xy[n].y - sin(45 * M_PI / 180) * ui.spinCrossL->value()), cv::Scalar(0, 0, 255), ui.spinRoiW->value());
				}
			}
			GetToolBase()->m_Tools[tool_index].PublicImage.Name = "图像";
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Center = Center;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.Radius = Radius;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmFindCircle::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
			if (strs.size() == 1 || strs[1] != "匹配基准中心")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			ui.txtLinkFollow->setText(str_link);
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmFindCircle::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmFindCircle::InitSetToolData(const QVariant data)
{
	try
	{
		InitFindCircleData init_data;
		init_data = data.value<InitFindCircleData>();
		if (init_data.use_roi == true)
		{
			view->ClearObj();
			if (init_data.type == "c_circle")
			{
				concentric_circle_item = new ConcentricCircleItem(init_data.x, init_data.y, init_data.RadiusMin, init_data.RadiusMax);
				concentric_circle_item->concentric_circle_init_state = true;
				concentric_circle_item->segment_line_num = init_data.segment_line_num;
				view->AddItems(concentric_circle_item);		
				concentric_circle_item->ring_small_points.clear();
				concentric_circle_item->ring_big_points.clear();
				for (int i = 0; i < init_data.ring_s_points.size(); i++)
				{
					concentric_circle_item->ring_small_points.push_back(init_data.ring_s_points[i]);
					concentric_circle_item->ring_big_points.push_back(init_data.ring_b_points[i]);
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

QVariant frmFindCircle::InitGetToolData()
{
	InitFindCircleData init_data;
	if (ui.checkUseROI->isChecked() == true)
	{
		init_data.use_roi = true;
		if (ui.comboROIShape->currentIndex() == 0)
		{
			if (concentric_circle_item->concentric_circle_init_state == false)
			{
				return -1;
			}
			concentric_circle_item->GetConcentricCircle(c_circle);			
			init_data.type = "c_circle";
			init_data.x = c_circle.col;
			init_data.y = c_circle.row;
			init_data.RadiusMin = c_circle.small_radius;
			init_data.RadiusMax = c_circle.big_radius;
			init_data.segment_line_num = concentric_circle_item->segment_line_num;
			init_data.color = color;					
			for (int i = 0; i < concentric_circle_item->ring_small_points.size(); i++)
			{
				init_data.ring_s_points.append(concentric_circle_item->ring_small_points[i]);
				init_data.ring_b_points.append(concentric_circle_item->ring_big_points[i]);
			}
		}		
	}
	else
	{
		init_data.use_roi = false;
	}
	return QVariant::fromValue(init_data);
}

void frmFindCircle::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	view_points = true;
	Execute(GetToolName());
	ui.txtMsg->clear();
	ui.txtMsg->append("-> 圆的中心坐标为：" + QString::number(Center.x) + "," + QString::number(Center.y));
	ui.txtMsg->append("-> 圆的半径为：" + QString::number(Radius));
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmFindCircle::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmFindCircle::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmFindCircle::on_btnLinkFollow_clicked()
{
	QConfig::nFormState = 2;
}

void frmFindCircle::on_btnDelLinkFollow_clicked()
{
	ui.txtLinkFollow->clear();
}

void frmFindCircle::on_btnAddROI_clicked()
{
	view->ClearObj();
	concentric_circle_item = new ConcentricCircleItem(220, 220, 100, 200);
	concentric_circle_item->concentric_circle_init_state = true;
	switch (ui.comboROIShape->currentIndex()) {
	case 0:
		concentric_circle_item->segment_line_num = ui.spinSegment->value();
		view->AddItems(concentric_circle_item);
		break;
	}
}

void frmFindCircle::on_btnDeleteROI_clicked()
{
	concentric_circle_item->concentric_circle_init_state = false;
	view->ClearObj();
}

void frmFindCircle::on_btnRoiColor_clicked()
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

void frmFindCircle::on_spinSegment_valueChanged(int value)
{
	concentric_circle_item->segment_line_num = value;
}

//寻找边界点
//threshold_delta为阈值；direction的值为0时代表“从白到黑”寻找边界点，direction的值为1时代表“从黑到白”寻找边界点
//in_out_circle值为0时，从内往外扫描，值为1时，从外往内扫描；segment_num为分割线数量
int frmFindCircle::FindBorderPoints(const cv::Mat& src_mat, const std::vector<QPointF> ring_small_points, const std::vector<QPointF> ring_big_points, std::vector<QPointF>& xy, const int threshold_delta, const int direction, const int in_out_circle, const int segment_num)
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
		int i, j;
		for (i = 0; i < ww * hh * 4; i += 4)
		{
			rgbValues[i / 4] = pData[i];
		}
		vector<unsigned char> buffer8(bytes);
		buffer8 = rgbValues;
		//边界点                   
		vector<QPointF> backPoint(segment_num);
		vector<QPointF> backOutPoint(segment_num);
		//寻找边界点		
		int m = 0;
		//计算两点间的距离
		double distance;
		distance = pow((ring_small_points[0].x() - ring_big_points[0].x()), 2) + pow((ring_small_points[0].y() - ring_big_points[0].y()), 2);
		distance = sqrt(distance);
		//线图像上每一个点灰度颜色
		QList<float> temparrclor = QList<float>();
		temparrclor.reserve(5000);
		//线图像上每一个点坐标
		QList<QPointF> position = QList<QPointF>();
		position.reserve(5000);
		for (int k = 0; k < segment_num; k++)
		{
			temparrclor.clear();
			position.clear();
			float x_point;
			float y_point;
			if (in_out_circle == 0)
			{
				for (int n = 0; n < (int)distance; n++)
				{
					x_point = (n * (ring_big_points[k].x() - ring_small_points[k].x())) / distance + ring_small_points[k].x();
					y_point = (n * (ring_big_points[k].y() - ring_small_points[k].y())) / distance + ring_small_points[k].y();
					float tempf = abs(y_point - (int)y_point);
					QPointF tempPt = QPointF(x_point, y_point);
					float avgGrey = (float)buffer8[(int)y_point * ww + (int)x_point];
					float avgGrey1 = (float)buffer8[(int)(y_point + 1) * ww + (int)x_point];
					float grey = avgGrey * (1 - tempf) + avgGrey1 * tempf;
					//插值灰度
					temparrclor.push_back(grey);
					position.push_back(tempPt);
				}
			}
			else if (in_out_circle == 1)
			{
				for (int n = 0; n < (int)distance; n++)
				{
					x_point = (n * (ring_small_points[k].x() - ring_big_points[k].x())) / distance + ring_big_points[k].x();
					y_point = (n * (ring_small_points[k].y() - ring_big_points[k].y())) / distance + ring_big_points[k].y();
					float tempf = abs(y_point - (int)y_point);
					QPointF tempPt = QPointF(x_point, y_point);
					float avgGrey = (float)buffer8[(int)y_point * ww + (int)x_point];
					float avgGrey1 = (float)buffer8[(int)(y_point + 1) * ww + (int)x_point];
					float grey = avgGrey * (1 - tempf) + avgGrey1 * tempf;
					//插值灰度
					temparrclor.push_back(grey);
					position.push_back(tempPt);
				}
			}
			//找穿越点
			QPointF return_point = FindCrosspointimprove(temparrclor, position, direction, threshold_delta);
			if (return_point != QPointF(0, 0))
			{
				backPoint[m] = return_point;
				m += 1;
			}
		}
		backOutPoint.resize(m);
		for (int n = 0; n < m; n++)
		{
			backOutPoint[n] = backPoint[n];
		}
		xy = backOutPoint;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

//梯度和求穿越点
QPointF frmFindCircle::FindCrosspointimprove(const QList<float>& lineTiDu, const QList<QPointF>& ijRecord, const int direction, const int threshold_delta)
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

Box frmFindCircle::fitCircle(const std::vector<cv::Point2f>& points)
{
	Box box;
	box.x = 0.0f;
	box.y = 0.0f;
	box.r = 0.0f;
	if (points.size() < 3)
	{
		return box;
	}
	int i = 0;
	double X1 = 0;
	double Y1 = 0;
	double X2 = 0;
	double Y2 = 0;
	double X3 = 0;
	double Y3 = 0;
	double X1Y1 = 0;
	double X1Y2 = 0;
	double X2Y1 = 0;
	int Sum = points.size();
	for (i = 0; i < Sum; i++)
	{
		X1 = X1 + points[i].x;
		Y1 = Y1 + points[i].y;
		X2 = X2 + points[i].x * points[i].x;
		Y2 = Y2 + points[i].y * points[i].y;
		X3 = X3 + points[i].x * points[i].x * points[i].x;
		Y3 = Y3 + points[i].y * points[i].y * points[i].y;
		X1Y1 = X1Y1 + points[i].x * points[i].y;
		X1Y2 = X1Y2 + points[i].x * points[i].y * points[i].y;
		X2Y1 = X2Y1 + points[i].x * points[i].x * points[i].y;
	}
	double C, D, E, G, H, N;
	double a, b, c;
	N = points.size();
	C = N * X2 - X1 * X1;
	D = N * X1Y1 - X1 * Y1;
	E = N * X3 + N * X1Y2 - (X2 + Y2) * X1;
	G = N * Y2 - Y1 * Y1;
	H = N * X2Y1 + N * Y3 - (X2 + Y2) * Y1;
	a = (H * D - E * G) / (C * G - D * D);
	b = (H * C - E * D) / (D * D - G * C);
	c = -(a * X1 + b * Y1 + X2 + Y2) / N;
	double A, B, R;
	A = a / (-2);
	B = b / (-2);
	R = sqrt(a * a + b * b - 4 * c) / 2;
	box.x = A;
	box.y = B;
	box.r = R;
	return box;
}

cv::Point2f frmFindCircle::AffineTransformPoint(const cv::Point2f match_origin_point, const double match_origin_angle, const cv::Point2f match_current_point, const double match_current_angle, const cv::Point2f input_point)
{
	try
	{
		//获取旋转矩阵
		cv::Mat rotMat = cv::getRotationMatrix2D(match_origin_point, (match_current_angle - match_origin_angle), 1.0);
		//转换成3*3矩阵
		cv::Mat rotMat2 = cv::Mat::zeros(3, 3, CV_32FC1);
		rotMat2.at<float>(0, 0) = (float)rotMat.at<double>(0, 0);
		rotMat2.at<float>(0, 1) = (float)rotMat.at<double>(0, 1);
		rotMat2.at<float>(0, 2) = (float)rotMat.at<double>(0, 2);
		rotMat2.at<float>(1, 0) = (float)rotMat.at<double>(1, 0);
		rotMat2.at<float>(1, 1) = (float)rotMat.at<double>(1, 1);
		rotMat2.at<float>(1, 2) = (float)rotMat.at<double>(1, 2);
		rotMat2.at<float>(2, 2) = 1;
		//平移矩阵
		cv::Mat t_mat = cv::Mat::zeros(3, 3, CV_32FC1);
		t_mat.at<float>(0, 0) = 1;
		t_mat.at<float>(0, 2) = match_current_point.x - match_origin_point.x;
		t_mat.at<float>(1, 1) = 1;
		t_mat.at<float>(1, 2) = match_current_point.y - match_origin_point.y;
		t_mat.at<float>(2, 2) = 1;
		//平移矩阵*旋转矩阵，得到仿射变换阵
		cv::Mat resMat = t_mat * rotMat2;
		double a11 = (double)resMat.at<float>(0, 0);
		double a12 = (double)resMat.at<float>(0, 1);
		double a13 = (double)resMat.at<float>(0, 2);
		double a21 = (double)resMat.at<float>(1, 0);
		double a22 = (double)resMat.at<float>(1, 1);
		double a23 = (double)resMat.at<float>(1, 2);
		cv::Point2f out_point;
		out_point = cv::Point2f((input_point.x * a11 + input_point.y * a12 + a13), (input_point.x * a21 + input_point.y * a22 + a23));
		return out_point;
	}
	catch (...)
	{
		return cv::Point2f(0, 0);
	}
}

QImage frmFindCircle::Mat2QImage(const cv::Mat& mat)
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
