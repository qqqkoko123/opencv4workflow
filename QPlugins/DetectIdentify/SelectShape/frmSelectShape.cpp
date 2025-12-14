#include "frmSelectShape.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QColorDialog>
#include "QGraphicsScenes.h"
#include <QGraphicsOpacityEffect>

#define M_PI 3.14159265358979323846

frmSelectShape::frmSelectShape(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/shape.png"));
	connect(ui.comboCMode, SIGNAL(currentIndexChanged(int)), this, SLOT(slotCModeChanged(int)));
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//初始化标题栏
	initTitleBar();
	ui.btnRoiColor->setStyleSheet("background-color: rgb(0, 255, 0)");
	color = QColor(0, 255, 0);
	//设置表格列宽	
	ui.tableWidgetType->setColumnWidth(0, 355);
	//设置表格行间距
	ui.tableWidgetType->verticalHeader()->setDefaultSectionSize(15);
	ui.tableWidgetType->verticalHeader()->setMinimumSectionSize(15);
	//隐藏水平header
	ui.tableWidgetType->verticalHeader()->setVisible(false);
	ui.tableWidgetType->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行
	ui.tableWidgetType->setSelectionMode(QAbstractItemView::SingleSelection);  //设置只能单选
	connect(ui.tableWidgetType, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_DoubleClicked(int, int)));
	rectangle_item = new RectangleItem(10, 10, 200, 200);
	rectangler_item = new RectangleRItem(110, 110, 200, 200, 0);
	circle_item = new CircleItem(110, 110, 100);
	polygon_item = new PolygonItem();
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmSelectShape::~frmSelectShape()
{
	view->deleteLater();
	rectangle_item->deleteLater();
	rectangler_item->deleteLater();
	circle_item->deleteLater();
	polygon_item->deleteLater();
	this->deleteLater();
}

void frmSelectShape::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/shape.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmSelectShape::paintEvent(QPaintEvent* event)
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

void frmSelectShape::onButtonCloseClicked()
{
	view_contours = false;
	this->close();
}

void frmSelectShape::slotCModeChanged(int index)
{
	switch (index) {
	case 0:
		ui.stackedWidget->setCurrentIndex(0);
		break;
	case 1:
		break;
	case 2:
		ui.stackedWidget->setCurrentIndex(1);
		break;
	case 3:
		ui.stackedWidget->setCurrentIndex(2);
		break;
	case 4:
		ui.stackedWidget->setCurrentIndex(3);
		break;
	case 5:
		ui.stackedWidget->setCurrentIndex(4);
		break;
	case 6:
		ui.stackedWidget->setCurrentIndex(5);
		break;
	case 7:
		ui.stackedWidget->setCurrentIndex(6);
		break;
	case 8:
		ui.stackedWidget->setCurrentIndex(7);
		break;
	case 9:
		ui.stackedWidget->setCurrentIndex(8);
		break;
	case 10:
		ui.stackedWidget->setCurrentIndex(9);
		break;
	case 11:
		ui.stackedWidget->setCurrentIndex(10);
		break;
	case 12:
		ui.stackedWidget->setCurrentIndex(11);
		break;
	case 13:
		ui.stackedWidget->setCurrentIndex(12);
		break;
	case 14:
		ui.stackedWidget->setCurrentIndex(13);
		break;
	case 15:
		ui.stackedWidget->setCurrentIndex(14);
		break;
	}
}

int frmSelectShape::Execute(const QString toolname)
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

int frmSelectShape::RunToolPro()
{
	try
	{
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
		dst.copyTo(dstImage);
		table_count = ui.tableWidgetType->rowCount();
		if (table_count == 0)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		int mode = 0;
		switch (ui.comboMode->currentIndex()) {
		case 0:
			mode = 0;
			break;
		case 1:
			mode = 1;
			break;
		case 2:
			mode = 2;
			break;
		case 3:
			mode = 3;
			break;
		}
		int method = 1;
		switch (ui.comboMethod->currentIndex()) {
		case 0:
			method = 1;
			break;
		case 1:
			method = 2;
			break;
		case 2:
			method = 3;
			break;
		case 3:
			method = 4;
			break;
		}
		QStringList toolNames;
		toolNames.reserve(100);
		toolNames.clear();
		toolNames << "area" << "max_area" << "contlength" << "vertices" << "circle_radius" << "rectangularity" << "inner_width" << "inner_height" << "row" << "column" << "rect2_len1" << "rect2_len2" << "rect2_phi" << "ellipse_lena" << "ellipse_lenb" << "ellipse_phi";
		all_contours.clear();
		all_contours_buf_or.clear();
		areas.clear();
		center_points.clear();
		bool state = false;
		cycle_count = 0;
		for (int m = 0; m < table_count; m++)
		{
			cycle_count = m + 1;
			c_mode = ui.tableWidgetType->item(m, 0)->text();
			switch (toolNames.indexOf(c_mode)) {
			case 0:
				min_feature_value = ui.spinMinArea->value();
				max_feature_value = ui.spinMaxArea->value();
				break;
			case 1:
				min_feature_value = 0;
				max_feature_value = 0;
				break;
			case 2:
				min_feature_value = ui.spinMinLength->value();
				max_feature_value = ui.spinMaxLength->value();
				break;
			case 3:
				min_feature_value = 0;
				max_feature_value = ui.spinVertices->value();
				break;
			case 4:
				min_feature_value = ui.spinMinRadius->value();
				max_feature_value = ui.spinMaxRadius->value();
				break;
			case 5:
				min_feature_value = ui.spinMinRectangularity->value();
				max_feature_value = ui.spinMaxRectangularity->value();
				break;
			case 6:
				min_feature_value = ui.spinMinRectW->value();
				max_feature_value = ui.spinMaxRectW->value();
				break;
			case 7:
				min_feature_value = ui.spinMinRectH->value();
				max_feature_value = ui.spinMaxRectH->value();
				break;
			case 8:
				min_feature_value = ui.spinMinRow->value();
				max_feature_value = ui.spinMaxRow->value();
				break;
			case 9:
				min_feature_value = ui.spinMinColumn->value();
				max_feature_value = ui.spinMaxColumn->value();
				break;
			case 10:
				min_feature_value = ui.spinMinRectLen1->value();
				max_feature_value = ui.spinMaxRectLen1->value();
				break;
			case 11:
				min_feature_value = ui.spinMinRectLen2->value();
				max_feature_value = ui.spinMaxRectLen2->value();
				break;
			case 12:
				min_feature_value = ui.spinMinRectPhi->value();
				max_feature_value = ui.spinMaxRectPhi->value();
				break;
			case 13:
				min_feature_value = ui.spinMinEllipseLena->value();
				max_feature_value = ui.spinMaxEllipseLena->value();
				break;
			case 14:
				min_feature_value = ui.spinMinEllipseLenb->value();
				max_feature_value = ui.spinMaxEllipseLenb->value();
				break;
			case 15:
				min_feature_value = ui.spinMinEllipsePhi->value();
				max_feature_value = ui.spinMaxEllipsePhi->value();
				break;
			}
			contours.clear();
			state = SelectCShape(dstImage, contours, areas, center_points, min_feature_value, max_feature_value, mode, method, c_mode);
			if (state == false)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
		}		
		if (ui.checkUseROI->isChecked() == true && ui.checkViewROI->isChecked() == true)
		{
			dstRoiImage = srcImage.clone();
			if (dstRoiImage.channels() == 1)
			{
				cv::cvtColor(dstRoiImage, dstRoiImage, cv::COLOR_GRAY2BGR);
			}						
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
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dst;
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputRoiImage = dstRoiImage;
		GetToolBase()->m_Tools[tool_index].PublicDetect.Contours = all_contours;
		GetToolBase()->m_Tools[tool_index].PublicDetect.Areas = areas;
		GetToolBase()->m_Tools[tool_index].PublicDetect.CenterPoints = center_points;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = state;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmSelectShape::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmSelectShape::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmSelectShape::InitSetToolData(const QVariant data)
{
	try
	{
		InitSelectShapeData init_data;
		init_data = data.value<InitSelectShapeData>();
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

QVariant frmSelectShape::InitGetToolData()
{
	InitSelectShapeData init_data;
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

void frmSelectShape::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	view_contours = true;
	Execute(GetToolName());
	ui.txtMsg->clear();
	int count = GetToolBase()->m_Tools[tool_index].PublicDetect.Areas.size();
	for (int i = 0; i < count; i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 轮廓的个数为: " + QString::number(count));
			ui.txtMsg->append("-> 轮廓的面积为: ");
		}
		ui.txtMsg->append(QString::number(GetToolBase()->m_Tools[tool_index].PublicDetect.Areas[i]));
	}
	for (int i = 0; i < count; i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 轮廓的重心为: ");
		}
		ui.txtMsg->append(QString::number(GetToolBase()->m_Tools[tool_index].PublicDetect.CenterPoints[i].x, 'f', 3) + "," + QString::number(GetToolBase()->m_Tools[tool_index].PublicDetect.CenterPoints[i].y, 'f', 3));
	}
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmSelectShape::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmSelectShape::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmSelectShape::on_btnAddType_clicked()
{
	int table_count = ui.tableWidgetType->rowCount();
	for (int m = 0; m < table_count; m++)
	{
		if (ui.comboCMode->currentText() == ui.tableWidgetType->item(m, 0)->text())
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "形状特征类别不能重复！");
			msgBox.setWindowIcon(QIcon(":/resource/error.png"));
			msgBox.exec();
			return;
		}
	}
	int count = ui.tableWidgetType->rowCount();
	ui.tableWidgetType->setRowCount(count + 1);  //设置行数	
	QTableWidgetItem* item_name = new QTableWidgetItem(ui.comboCMode->currentText());
	item_name->setFlags(item_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
	item_name->setTextAlignment(Qt::AlignLeft);
	item_name->setTextAlignment(Qt::AlignVCenter);
	ui.tableWidgetType->setItem(count, 0, item_name);
}

void frmSelectShape::on_btnDeleteType_clicked()
{
	int rowIndex = ui.tableWidgetType->currentRow();
	if (rowIndex != -1)
	{
		ui.tableWidgetType->removeRow(rowIndex);
	}
}

void frmSelectShape::slot_DoubleClicked(int row, int column)
{
	QString m_ToolNames_buf = ui.tableWidgetType->item(row, 0)->text();
	if (m_ToolNames_buf == "area")
	{
		ui.stackedWidget->setCurrentIndex(0);
	}
	else if (m_ToolNames_buf == "contlength")
	{
		ui.stackedWidget->setCurrentIndex(1);
	}
	else if (m_ToolNames_buf == "vertices")
	{
		ui.stackedWidget->setCurrentIndex(2);
	}
	else if (m_ToolNames_buf == "circle_radius")
	{
		ui.stackedWidget->setCurrentIndex(3);
	}
	else if (m_ToolNames_buf == "rectangularity")
	{
		ui.stackedWidget->setCurrentIndex(4);
	}
	else if (m_ToolNames_buf == "inner_width")
	{
		ui.stackedWidget->setCurrentIndex(5);
	}
	else if (m_ToolNames_buf == "inner_height")
	{
		ui.stackedWidget->setCurrentIndex(6);
	}
	else if (m_ToolNames_buf == "row")
	{
		ui.stackedWidget->setCurrentIndex(7);
	}
	else if (m_ToolNames_buf == "column")
	{
		ui.stackedWidget->setCurrentIndex(8);
	}
	else if (m_ToolNames_buf == "rect2_len1")
	{
		ui.stackedWidget->setCurrentIndex(9);
	}
	else if (m_ToolNames_buf == "rect2_len2")
	{
		ui.stackedWidget->setCurrentIndex(10);
	}
	else if (m_ToolNames_buf == "rect2_phi")
	{
		ui.stackedWidget->setCurrentIndex(11);
	}
	else if (m_ToolNames_buf == "ellipse_lena")
	{
		ui.stackedWidget->setCurrentIndex(12);
	}
	else if (m_ToolNames_buf == "ellipse_lenb")
	{
		ui.stackedWidget->setCurrentIndex(13);
	}
	else if (m_ToolNames_buf == "ellipse_phi")
	{
		ui.stackedWidget->setCurrentIndex(14);
	}
}

void frmSelectShape::on_btnAddROI_clicked()
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

void frmSelectShape::on_btnDeleteROI_clicked()
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

void frmSelectShape::on_btnRoiColor_clicked()
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

#pragma region 轮廓特征选择
//RetrievalModes的类型有：RETR_EXTERNAL(只检测最外层轮廓)、RETR_CCOMP(提取所有轮廓，并且将其组织为双层结构)、RETR_LIST(提取所有轮廓，并且放置在list中)、RETR_TREE(提取所有轮廓，并重新建立网状的轮廓结构)
//ContourApproximationModes的类型有：CHAIN_APPROX_NONE、CHAIN_APPROX_SIMPLE、CHAIN_APPROX_TC89_L1、CHAIN_APPROX_TC89_KCOS
bool frmSelectShape::SelectCShape(cv::Mat& src_gray_mat, vector<vector<cv::Point>>& use_vvp, vector<double>& area, vector<cv::Point2f>& center_point, const double min_feature_value, const double max_feature_value, const int mode, const int method, const QString find_mode)
{
	try
	{
		cv::Mat gray;
		if (src_gray_mat.channels() == 3)
		{
			cv::cvtColor(src_gray_mat, gray, cv::COLOR_BGR2GRAY);
		}
		else if (src_gray_mat.channels() == 4)
		{
			cv::cvtColor(src_gray_mat, gray, cv::COLOR_RGBA2GRAY);
		}		
		else
		{
			src_gray_mat.copyTo(gray);
		}
		vector<vector<cv::Point>> vvp_contours = vector<vector<cv::Point>>(10000);
		vvp_contours.clear();
		vector<cv::Vec4i> hierarchy;
		//从二值图像检索轮廓并返回检索到的轮廓的数目
		cv::findContours(gray, vvp_contours, hierarchy, mode, method);
		int ksize = vvp_contours.size();
		vector<double> m00(ksize);
		vector<double> m10(ksize);
		vector<double> m01(ksize);
		vector<cv::Point2f> Gravity(ksize);
		vector<cv::Moments> hu(ksize);
		vector<cv::Point> contour = vector<cv::Point>(1000000);
		if (find_mode == "area")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				//计算连通轮廓的面积
				double select_area = cv::contourArea(contour);
				//进行面积筛选
				if (select_area >= min_feature_value && select_area <= max_feature_value)
				{
					//添加筛选后的连通轮廓
					use_vvp.push_back(contour);
				}
			}
		}
		else if (find_mode == "max_area")
		{
			double max_area = 0;
			int index = 0;
			//遍历每个连通轮廓
			for (int i = 0; i < ksize; i++)
			{
				//选取最大的面积轮廓
				if (cv::contourArea(vvp_contours[i]) > max_area)
				{
					max_area = cv::contourArea(vvp_contours[i]);
					index = i;
				}
			}
			//添加筛选后的连通轮廓
			use_vvp.push_back(vvp_contours[index]);
		}
		else if (find_mode == "contlength")
		{
			//遍历每个连通轮廓
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				//计算连通轮廓的长度
				double len = cv::arcLength(contour, false);
				//进行长度筛选
				if (len >= min_feature_value && len <= max_feature_value)
				{
					//添加筛选后的连通轮廓
					use_vvp.push_back(contour);
				}
			}
		}
		else if (find_mode == "vertices")
		{
			//遍历每个连通轮廓
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				vector<cv::Point> approx_Curve(ksize);
				//几何逼近
				cv::approxPolyDP(contour, approx_Curve, arcLength(contour, false) * ui.spinApprox->value(), true);
				//approx_Curve.Size 代表顶点个数，即多边形边数
				if (approx_Curve.size() == (int)max_feature_value)
				{
					//添加筛选后的连通轮廓
					use_vvp.push_back(contour);
				}
			}
		}
		else if (find_mode == "circle_radius")
		{
			//遍历每个连通轮廓
			for (int i = 0; i < ksize; i++)
			{
				if (vvp_contours[i].size() >= 5)
				{
					//假设如果轮廓为圆，即面积为:PI*R^2
					double area = cv::contourArea(vvp_contours[i]);
					//假设如果轮廓为圆，即周长为:PI*R*2
					double length = cv::arcLength(vvp_contours[i], true);
					//假设如果轮廓为圆: 面积/周长=R/2；即半径为： 面积*2/周长
					double r = (area / length) * 2;
					//假设轮廓为圆： 面积/(周长的平方)=1/(4*PI)常数
					double c = (area / (length * length)) * 10;
					//满足"圆"的条件进行筛选
					if (c >= ui.spinMinCircularity->value() && c <= ui.spinMaxCircularity->value())
					{
						//通过半径进行筛选
						if (min_feature_value <= r && r <= max_feature_value)
						{
							//提取筛选后的“圆”轮廓
							use_vvp.push_back(vvp_contours[i]);
						}
					}
				}				
			}
		}
		else if (find_mode == "rectangularity")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				if (vvp_contours[i].size() >= 5)
				{
					//计算连通轮廓的面积
					double select_area = cv::contourArea(contour);
					cv::RotatedRect rect = cv::minAreaRect(vvp_contours[i]);
					double rectangularity = select_area / rect.size.area();
					//进行矩形度筛选
					if (rectangularity >= min_feature_value && rectangularity <= max_feature_value)
					{
						//添加筛选后的连通轮廓
						use_vvp.push_back(contour);
					}
				}				
			}
		}
		else if (find_mode == "inner_width")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				if (vvp_contours[i].size() >= 5)
				{
					cv::Rect rect = cv::boundingRect(vvp_contours[i]);
					//进行筛选
					if (rect.width >= min_feature_value && rect.width <= max_feature_value)
					{
						//添加筛选后的连通轮廓
						use_vvp.push_back(contour);
					}
				}				
			}
		}
		else if (find_mode == "inner_height")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				if (vvp_contours[i].size() >= 5)
				{
					cv::Rect rect = cv::boundingRect(vvp_contours[i]);
					//进行筛选
					if (rect.height >= min_feature_value && rect.height <= max_feature_value)
					{
						//添加筛选后的连通轮廓
						use_vvp.push_back(contour);
					}
				}				
			}
		}
		else if (find_mode == "row")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				hu[i] = cv::moments(contour, false);
				m00[i] = hu[i].m00;
				m10[i] = hu[i].m10;
				m01[i] = hu[i].m01;
				double X = m10[i] / m00[i];
				double Y = m01[i] / m00[i];
				Gravity[i] = cv::Point2f((float)X, (float)Y);
				//进行筛选
				if (Gravity[i].y >= min_feature_value && Gravity[i].y <= max_feature_value)
				{
					//添加筛选后的连通轮廓
					use_vvp.push_back(contour);
				}
			}
		}
		else if (find_mode == "column")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				hu[i] = cv::moments(contour, false);
				m00[i] = hu[i].m00;
				m10[i] = hu[i].m10;
				m01[i] = hu[i].m01;
				double X = m10[i] / m00[i];
				double Y = m01[i] / m00[i];
				Gravity[i] = cv::Point2f((float)X, (float)Y);
				//进行筛选
				if (Gravity[i].x >= min_feature_value && Gravity[i].x <= max_feature_value)
				{
					//添加筛选后的连通轮廓
					use_vvp.push_back(contour);
				}
			}
		}
		else if (find_mode == "rect2_len1")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				if (vvp_contours[i].size() >= 5)
				{
					cv::RotatedRect  rect = cv::minAreaRect(vvp_contours[i]);
					double len = rect.size.width;
					if (rect.size.width < rect.size.height)
					{
						len = rect.size.height * 0.5;
					}
					//进行筛选
					if (len >= min_feature_value && len <= max_feature_value)
					{
						//添加筛选后的连通轮廓
						use_vvp.push_back(contour);
					}
				}				
			}
		}
		else if (find_mode == "rect2_len2")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				if (vvp_contours[i].size() >= 5)
				{
					cv::RotatedRect  rect = cv::minAreaRect(vvp_contours[i]);
					double len = rect.size.height;
					if (rect.size.width < rect.size.height)
					{
						len = rect.size.width * 0.5;
					}
					//进行筛选
					if (len >= min_feature_value && len <= max_feature_value)
					{
						//添加筛选后的连通轮廓
						use_vvp.push_back(contour);
					}
				}				
			}
		}
		else if (find_mode == "rect2_phi")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				if (vvp_contours[i].size() >= 5)
				{
					cv::RotatedRect  rect = cv::minAreaRect(vvp_contours[i]);
					float angle = 0;
					if (angle < 0) angle += 180;
					if (rect.size.width < rect.size.height)
					{
						angle = rect.angle;
						angle -= 90;
						if (angle < 0) angle += 180;
					}
					else
					{
						angle = rect.angle;
					}
					//进行筛选
					if (angle >= min_feature_value && angle <= max_feature_value)
					{
						//添加筛选后的连通轮廓
						use_vvp.push_back(contour);
					}
				}				
			}
		}
		else if (find_mode == "ellipse_lena")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				if (vvp_contours[i].size() >= 10)
				{
					cv::RotatedRect  rect = cv::fitEllipse(vvp_contours[i]);
					double len = rect.size.width;
					if (rect.size.width < rect.size.height)
					{
						len = rect.size.height * 0.5;
					}
					//进行筛选
					if (len >= min_feature_value && len <= max_feature_value)
					{
						//添加筛选后的连通轮廓
						use_vvp.push_back(contour);
					}
				}				
			}
		}
		else if (find_mode == "ellipse_lenb")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				if (vvp_contours[i].size() >= 10)
				{
					cv::RotatedRect  rect = cv::fitEllipse(vvp_contours[i]);
					double len = rect.size.height;
					if (rect.size.width < rect.size.height)
					{
						len = rect.size.width * 0.5;
					}
					//进行筛选
					if (len >= min_feature_value && len <= max_feature_value)
					{
						//添加筛选后的连通轮廓
						use_vvp.push_back(contour);
					}
				}				
			}
		}
		else if (find_mode == "ellipse_phi")
		{
			for (int i = 0; i < ksize; i++)
			{
				contour.clear();
				contour = vvp_contours[i];
				if (vvp_contours[i].size() >= 10)
				{
					cv::RotatedRect  rect = cv::fitEllipse(vvp_contours[i]);
					float angle = 0;
					if (angle < 0) angle += 180;
					if (rect.size.width < rect.size.height)
					{
						angle = rect.angle;
						angle -= 90;
						if (angle < 0) angle += 180;
					}
					else
					{
						angle = rect.angle;
					}
					//进行筛选
					if (angle >= min_feature_value && angle <= max_feature_value)
					{
						//添加筛选后的连通轮廓
						use_vvp.push_back(contour);
					}
				}				
			}
		}
		all_contours_buf_and.clear();
		switch (ui.comboType->currentIndex())
		{
		case 0:
			if (all_contours.size() == 0)
			{
				all_contours = use_vvp;
			}
			else
			{
				for (int i = 0; i < all_contours.size(); i++)
				{
					for (int j = 0; j < use_vvp.size(); j++)
					{
						if (use_vvp[j] == all_contours[i])
						{
							all_contours_buf_and.push_back(all_contours[i]);
						}
					}
				}
				all_contours = all_contours_buf_and;
			}
			break;
		case 1:			
			if (all_contours.size() == 0)
			{
				all_contours = use_vvp;
				all_contours_buf_or = use_vvp;
			}
			else
			{
				for (int i = 0; i < use_vvp.size(); i++)
				{
					all_contours_buf_or.push_back(use_vvp[i]);
				}
				for (int i = 0; i < all_contours.size(); i++)
				{
					for (int j = 0; j < use_vvp.size(); j++)
					{
						if (use_vvp[j] == all_contours[i])
						{
							int k = 0;
							for (int m = 0; m < all_contours_buf_or.size(); m++)
							{
								if (all_contours_buf_or[m] == use_vvp[j])
								{
									k = m;
								}
							}
							all_contours_buf_or.erase(all_contours_buf_or.begin() + k, all_contours_buf_or.begin() + k +1);
						}
					}
				}
				all_contours = all_contours_buf_or;
			}
			break;
		}
		int vvp_size = all_contours.size();
		area.resize(vvp_size);
		center_point.resize(vvp_size);
		for (int i = 0; i < vvp_size; i++)
		{
			contour.clear();
			contour = all_contours[i];
			//计算多边形和光栅形状的最高达三阶的所有矩；矩用来计算形状的重心、面积，主轴和其它形状特征
			hu[i] = cv::moments(contour, false);
			m00[i] = hu[i].m00;
			m10[i] = hu[i].m10;
			m01[i] = hu[i].m01;
			double X = m10[i] / m00[i];
			double Y = m01[i] / m00[i];
			Gravity[i] = cv::Point2f((float)X, (float)Y);
			area[i] = m00[i];
			center_point[i] = Gravity[i];
		}
		if (view_contours == true && cycle_count == table_count)
		{
			if (gray.channels() == 1)
			{
				cv::cvtColor(gray, gray, cv::COLOR_GRAY2BGR);
			}			
			gray.copyTo(src_gray_mat);
			cv::drawContours(src_gray_mat, all_contours, -1, cv::Scalar(255, 0, 0), 2, cv::LINE_8);
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

QImage frmSelectShape::Mat2QImage(const cv::Mat& mat)
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
