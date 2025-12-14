#include "frmFindLine.h"
#include <QMessageBox>
#include <QColorDialog>
#include <QDesktopWidget>
#include "BaseItem.h"
#include <QGraphicsOpacityEffect>

#define M_PI 3.14159265358979323846

frmFindLine::frmFindLine(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/find_line.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	ui.btnRoiColor->setStyleSheet("background-color: rgb(0, 0, 255)");
	color = QColor(0, 0, 255);
	caliper_item = new Caliper(10, 160, 200, 160, 300);
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);	
}

frmFindLine::~frmFindLine()
{
	view->deleteLater();
	caliper_item->deleteLater();
	this->deleteLater();
}

void frmFindLine::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/find_line.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmFindLine::paintEvent(QPaintEvent* event)
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

void frmFindLine::onButtonCloseClicked()
{
	view_points = false;
	this->close();
}

int frmFindLine::Execute(const QString toolname)
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

int frmFindLine::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		k = 0;
		b = 0;
		dstImage = cv::Mat();
		dstRoiImage = cv::Mat();
		srcImage.copyTo(dstImage);
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
		line_small_points.clear();
		line_big_points.clear();
		switch (ui.comboScanDirection->currentIndex()) {
		case 0:
			scan_direction = 0;
			line_small_points = caliper_item->line_small_points;
			line_big_points = caliper_item->line_big_points;
			break;
		case 1:
			scan_direction = 1;
			line_big_points = caliper_item->line_small_points;
			line_small_points = caliper_item->line_big_points;
			break;
		case 2:
			scan_direction = 0;
			line_small_points = caliper_item->line_small_points;
			line_big_points = caliper_item->line_big_points;
			break;
		case 3:
			scan_direction = 1;
			line_big_points = caliper_item->line_small_points;
			line_small_points = caliper_item->line_big_points;
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
		xy.clear();
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
				for (int p = 0; p < line_small_points.size(); p++)
				{
					cv::Point2f point_small_buf = cv::Point2f(line_small_points[p].x(), line_small_points[p].y());
					cv::Point2f point_small = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, point_small_buf);
					line_small_points[p] = QPointF(point_small.x, point_small.y);
					cv::Point2f point_big_buf = cv::Point2f(line_big_points[p].x(), line_big_points[p].y());
					cv::Point2f point_big = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, point_big_buf);
					line_big_points[p] = QPointF(point_big.x, point_big.y);
				}			
			}
			else
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -2;
			}
		}		
		int result = FindBorderPoints(dstImage, line_small_points, line_big_points, xy, ui.spinThreshold->value(), direction, scan_direction, ui.spinSegment->value());
		if (result == -1)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		//拟合直线
		vector<cv::Point2f> new_xy(xy.size());
		for (int i = 0; i < xy.size(); i++)
		{
			new_xy[i].x = xy[i].x();
			new_xy[i].y = xy[i].y();
		}
		int w = srcImage.cols;
		cv::Vec4f fitline;
		cv::fitLine(new_xy, fitline, cv::DIST_L2, 0, 0.01, 0.01);
		float vx = fitline[0];
		float vy = fitline[1];
		float x = fitline[2];
		float y = fitline[3];		
		double x1_1 = w - 1;
		double y1_1 = (w - x) * vy / vx + y;
		double x1_2 = 0;
		double y1_2 = (-x * vy / vx) + y;
		//剔除点		
		select_xy.clear();
		cull_xy.clear();
		for (int i = 0; i < new_xy.size(); i++)
		{
			//计算点到直线的距离
			double distance = GetDistP2L(new_xy[i], cv::Point2f(x1_1, y1_1), cv::Point2f(x1_2, y1_2));
			if (distance > ui.spinCullDistance->value())
			{
				cull_xy.push_back(new_xy[i]);
			}
			else
			{
				select_xy.push_back(new_xy[i]);
			}
		}
		//剔除点后再次拟合直线	
		cv::fitLine(select_xy, fitline, cv::DIST_L2, 0, 0.01, 0.01);
		if (dstImage.channels() == 1)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
		}
		else if (dstImage.channels() == 4)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
		}
		vx = fitline[0];
		vy = fitline[1];
		x = fitline[2];
		y = fitline[3];
		k = vy / vx;
		b = y - k * x;
		int y1 = int((-x * vy / vx) + y);
		int y2 = int((w - x) * vy / vx + y);
		cv::line(dstImage, cv::Point((w - 1), y2), cv::Point(0, y1), cv::Scalar(255, 10, 10), 1);
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
			for (int i = 0; i < line_small_points.size(); i++)
			{
				cv::line(dstRoiImage, cv::Point(line_small_points[i].x(), line_small_points[i].y()), cv::Point(line_big_points[i].x(), line_big_points[i].y()), cv::Scalar(223, 231, 255), 1);
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
			cv::RotatedRect rrect = cv::RotatedRect(cv::Point2f(caliper_p.col, caliper_p.row), cv::Size2f(caliper_p.len1, caliper_p.len2), -(caliper_p.angle * 180 / M_PI));
			cv::Point2f vertices[4];
			rrect.points(vertices);
			if (ui.checkUseFollow->isChecked() == true)
			{				
				cv::Point2f point_1 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[0]);
				cv::Point2f point_2 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[1]);
				cv::Point2f point_3 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[2]);
				cv::Point2f point_4 = AffineTransformPoint(match_origin_point, 0, match_current_point, match_current_angle, vertices[3]);
				cv::line(dstRoiImage, point_1, point_2, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstRoiImage, point_2, point_3, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstRoiImage, point_3, point_4, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstRoiImage, point_1, point_4, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			}
			else
			{				
				cv::line(dstRoiImage, cv::Point(vertices[0].x, vertices[0].y), cv::Point(vertices[1].x, vertices[1].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstRoiImage, cv::Point(vertices[0].x, vertices[0].y), cv::Point(vertices[3].x, vertices[3].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstRoiImage, cv::Point(vertices[1].x, vertices[1].y), cv::Point(vertices[2].x, vertices[2].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
				cv::line(dstRoiImage, cv::Point(vertices[2].x, vertices[2].y), cv::Point(vertices[3].x, vertices[3].y), cv::Scalar(color.blue(), color.green(), color.red()), ui.spinRoiW->value());
			}			
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
		GetToolBase()->m_Tools[tool_index].PublicGeometry.k = k;
		GetToolBase()->m_Tools[tool_index].PublicGeometry.b = b;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmFindLine::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmFindLine::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmFindLine::InitSetToolData(const QVariant data)
{
	try
	{
		InitFindLineData init_data;
		init_data = data.value<InitFindLineData>();
		if (init_data.use_roi == true)
		{
			view->ClearObj();
			if (init_data.type == "caliper_p")
			{
				caliper_item = new Caliper(init_data.x1, init_data.y1, init_data.x2, init_data.y2, init_data.height);
				caliper_item->caliper_init_state = true;
				caliper_item->segment_line_num = init_data.segment_line_num;
				view->AddItems(caliper_item);
				caliper_item->line_small_points.clear();
				caliper_item->line_big_points.clear();
				for (int i = 0; i < init_data.line_s_points.size(); i++)
				{
					caliper_item->line_small_points.push_back(init_data.line_s_points[i]);
					caliper_item->line_big_points.push_back(init_data.line_b_points[i]);
				}
				caliper_item->SetCaliper(init_data.pp1, init_data.pp2);
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

QVariant frmFindLine::InitGetToolData()
{
	InitFindLineData init_data;
	if (ui.checkUseROI->isChecked() == true)
	{
		init_data.use_roi = true;
		if (ui.comboROIShape->currentIndex() == 0)
		{
			if (caliper_item->caliper_init_state == false)
			{
				return -1;
			}
			caliper_item->GetCaliper(caliper_p);
			init_data.type = "caliper_p";
			init_data.x1 = caliper_p.x1;
			init_data.y1 = caliper_p.y1;
			init_data.x2 = caliper_p.x2;
			init_data.y2 = caliper_p.y2;
			init_data.height = caliper_p.height;
			init_data.row = caliper_p.row;
			init_data.col = caliper_p.col;
			init_data.len1 = caliper_p.len1;
			init_data.len2 = caliper_p.len2;
			init_data.angle = caliper_p.angle;
			init_data.pp1 = caliper_p.pp1;
			init_data.pp2 = caliper_p.pp2;
			init_data.segment_line_num = caliper_item->segment_line_num;
			init_data.color = color;
			for (int i = 0; i < caliper_item->line_small_points.size(); i++)
			{
				init_data.line_s_points.append(caliper_item->line_small_points[i]);
				init_data.line_b_points.append(caliper_item->line_big_points[i]);
			}
		}
	}
	else
	{
		init_data.use_roi = false;
	}
	return QVariant::fromValue(init_data);
}

void frmFindLine::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	view_points = true;	
	Execute(GetToolName());
	ui.txtMsg->clear();
	ui.txtMsg->append("-> 直线的斜率为：" + QString::number(k));
	ui.txtMsg->append("-> 直线的截距为：" + QString::number(b));
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);	
	ui.btnExecute->setEnabled(true);
}

void frmFindLine::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmFindLine::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmFindLine::on_btnLinkFollow_clicked()
{
	QConfig::nFormState = 2;
}

void frmFindLine::on_btnDelLinkFollow_clicked()
{
	ui.txtLinkFollow->clear();
}

void frmFindLine::on_btnAddROI_clicked()
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

void frmFindLine::on_btnDeleteROI_clicked()
{	
	caliper_item->caliper_init_state = false;
	view->ClearObj();
}

void frmFindLine::on_btnRoiColor_clicked()
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

void frmFindLine::on_spinSegment_valueChanged(int value)
{
	caliper_item->segment_line_num = value;
}

//寻找边界点
//threshold_delta为阈值；direction的值为0时代表“从白到黑”寻找边界点，direction的值为1时代表“从黑到白”寻找边界点
//in_out_circle值为0时，从内往外扫描，值为1时，从外往内扫描；segment_num为分割线数量
int frmFindLine::FindBorderPoints(const cv::Mat& src_mat, const std::vector<QPointF> line_small_points, const std::vector<QPointF> line_big_points, std::vector<QPointF>& xy, const int threshold_delta, const int direction, const int in_out_circle, const int segment_num)
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
		distance = pow((line_small_points[0].x() - line_big_points[0].x()), 2) + pow((line_small_points[0].y() - line_big_points[0].y()), 2);
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
					x_point = (n * (line_big_points[k].x() - line_small_points[k].x())) / distance + line_small_points[k].x();
					y_point = (n * (line_big_points[k].y() - line_small_points[k].y())) / distance + line_small_points[k].y();
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
					x_point = (n * (line_small_points[k].x() - line_big_points[k].x())) / distance + line_big_points[k].x();
					y_point = (n * (line_small_points[k].y() - line_big_points[k].y())) / distance + line_big_points[k].y();
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
QPointF frmFindLine::FindCrosspointimprove(const QList<float>& lineTiDu, const QList<QPointF>& ijRecord, const int direction, const int threshold_delta)
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
double frmFindLine::GetDistP2L(const cv::Point2f pointP, const cv::Point2f pointA, const cv::Point2f pointB)
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

cv::Point2f frmFindLine::AffineTransformPoint(const cv::Point2f match_origin_point, const double match_origin_angle, const cv::Point2f match_current_point, const double match_current_angle, const cv::Point2f input_point)
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

QImage frmFindLine::Mat2QImage(const cv::Mat& mat)
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
