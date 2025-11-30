#include "frmImageView.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QColorDialog>

frmImageView::frmImageView(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/view.ico"));
	//初始化标题栏
	initTitleBar();
	ui.btnColor->setStyleSheet("background-color: rgb(0, 255, 0)");
	ui.btnOkColor->setStyleSheet("background-color: rgb(0, 255, 0)");
	ui.btnNgColor->setStyleSheet("background-color: rgb(255, 0, 0)");
	color = QColor(0, 255, 0);
	ok_color = QColor(0, 255, 0);
	ng_color = QColor(255, 0, 0);
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//设置表格列宽	
	ui.tableWidgetContour->setColumnWidth(0, 338);
	//设置表格行间距
	ui.tableWidgetContour->verticalHeader()->setDefaultSectionSize(15);
	ui.tableWidgetContour->verticalHeader()->setMinimumSectionSize(15);
	//隐藏水平header
	ui.tableWidgetContour->verticalHeader()->setVisible(false);
	ui.tableWidgetContour->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行
	ui.tableWidgetContour->setSelectionMode(QAbstractItemView::SingleSelection);  //设置只能单选
	connect(ui.tableWidgetContour, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_DoubleClicked(int, int)));
	//设置表格列宽	
	ui.tableWidgetText->setColumnWidth(0, 338);
	//设置表格行间距
	ui.tableWidgetText->verticalHeader()->setDefaultSectionSize(15);
	ui.tableWidgetText->verticalHeader()->setMinimumSectionSize(15);
	//隐藏水平header
	ui.tableWidgetText->verticalHeader()->setVisible(false);
	ui.tableWidgetText->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行
	ui.tableWidgetText->setSelectionMode(QAbstractItemView::SingleSelection);  //设置只能单选
	connect(ui.tableWidgetText, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_TextDoubleClicked(int, int)));
}

frmImageView::~frmImageView()
{
	this->deleteLater();
}

void frmImageView::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/view.ico");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmImageView::paintEvent(QPaintEvent* event)
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

void frmImageView::onButtonCloseClicked()
{
	this->close();
}

int frmImageView::Execute(const QString toolname)
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
		if (GetToolBase()->m_Tools[i].PublicToolName == "获取图像")
		{
			getImage_index = i;
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
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
	GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
	return 0;
}

int frmImageView::RunToolPro()
{
	try
	{
		if (GetToolBase()->m_Tools[image_index].PublicImage.Name == "ROI图像")
		{
			srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputRoiImage;
		}
		else
		{
			srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		}
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		if (ui.checkViewContour->isChecked() == true)
		{
			int table_contour_count = ui.tableWidgetContour->rowCount();
			if (dstImage.channels() == 1)
			{
				cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
			}
			else if (dstImage.channels() == 4)
			{
				cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
			}
			for (int m = 0; m < table_contour_count; m++)
			{
				strs.clear();
				strs = ui.tableWidgetContour->item(m, 0)->text().split(".");
				if (strs.size() == 1)
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -1;
				}
				if (strs[1] == "轮廓")
				{
					bool link_state = false;
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
					if (ui.checkViewContourC->isChecked() == true)
					{
						for (int i = 0; i < GetToolBase()->m_Tools[contour_index].PublicDetect.Contours.size(); i++)
						{
							cv::Point start1 = cv::Point((int)(GetToolBase()->m_Tools[contour_index].PublicDetect.CenterPoints[i].x - ui.spinCrossSize->value()), (int)GetToolBase()->m_Tools[contour_index].PublicDetect.CenterPoints[i].y);
							cv::Point end1 = cv::Point((int)(GetToolBase()->m_Tools[contour_index].PublicDetect.CenterPoints[i].x + ui.spinCrossSize->value()), (int)GetToolBase()->m_Tools[contour_index].PublicDetect.CenterPoints[i].y);
							cv::line(dstImage, start1, end1, cv::Scalar(color.blue(), color.green(), color.red()), 2);
							cv::Point start2 = cv::Point((int)GetToolBase()->m_Tools[contour_index].PublicDetect.CenterPoints[i].x, (int)GetToolBase()->m_Tools[contour_index].PublicDetect.CenterPoints[i].y - ui.spinCrossSize->value());
							cv::Point end2 = cv::Point((int)GetToolBase()->m_Tools[contour_index].PublicDetect.CenterPoints[i].x, (int)GetToolBase()->m_Tools[contour_index].PublicDetect.CenterPoints[i].y + ui.spinCrossSize->value());
							cv::line(dstImage, start2, end2, cv::Scalar(color.blue(), color.green(), color.red()), 2);
						}
					}
					cv::drawContours(dstImage, GetToolBase()->m_Tools[contour_index].PublicDetect.Contours, -1, cv::Scalar(color.blue(), color.green(), color.red()), ui.spinContour->value(), cv::LINE_8);
				}
				else
				{
					GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
					return -2;
				}
			}
			out_img = Mat2QImage(dstImage);
		}
		if (ui.checkViewText->isChecked() == true)
		{
			/*if (ui.checkViewContour->isChecked() == false)
			{
				if (dstImage.channels() == 1)
				{
					cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
				}
				else if (dstImage.channels() == 4)
				{
					cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
				}
				
			}*/
			out_img = Mat2QImage(dstImage);
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			text_keys.reserve(100);
			text_keys.clear();
			text_keys = global_text_content.uniqueKeys();
			if (text_keys.count() == 0)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
			if (GetToolBase()->m_Tools[image_index].PublicResult.State == false && GetToolBase()->m_Tools[image_index].PublicToolName != "亮度检测")
			{
				// 如果NG显示最近一个状态为成功的图像		
				out_img = frmImageView::GetErrorImage(image_index);
			}
			getViewMsg.clear();
			for (int m = 0; m < text_keys.count(); m++)
			{
				text_state_buf = 0;
				text_content_buf = 0;
				text_pos.setX(0);
				text_pos.setY(0);
				text_state = false;
				text_content.clear();
				//使用全局变量
				for (int k = 0; k < keys.length(); k++)
				{
					QString key = keys[k];
					if (key == global_text_content.value(text_keys[m]).global_pos_xy)
					{
						text_pos = gvariable.global_variable_link.value(key).global_qpoint_value;
					}
					else if (key == global_text_content.value(text_keys[m]).global_state)
					{
						text_state_buf = 1;
						text_state = gvariable.global_variable_link.value(key).global_bool_value;
					}
					else if (key == global_text_content.value(text_keys[m]).global_content)
					{
						text_content_buf = 1;
						if (gvariable.global_variable_link.value(key).global_type == "Int")
						{
							text_content = QString::number(gvariable.global_variable_link.value(key).global_int_value);
						}
						else if (gvariable.global_variable_link.value(key).global_type == "Double")
						{
							text_content = QString::number(gvariable.global_variable_link.value(key).global_double_value, 'f', 4);
						}
						else if (gvariable.global_variable_link.value(key).global_type == "QString")
						{
							text_content = gvariable.global_variable_link.value(key).global_qstring_value;
						}
						else if (gvariable.global_variable_link.value(key).global_type == "Bool")
						{
							text_content = QString::number(gvariable.global_variable_link.value(key).global_bool_value);
						}
						else if (gvariable.global_variable_link.value(key).global_type == "QPoint")
						{
							text_content = "(" + QString::number(gvariable.global_variable_link.value(key).global_qpoint_value.x()) + "," + QString::number(gvariable.global_variable_link.value(key).global_qpoint_value.y()) + ")";
						}
						else if (gvariable.global_variable_link.value(key).global_type == "QPointF")
						{
							text_content = "(" + QString::number(gvariable.global_variable_link.value(key).global_qpointf_value.x(), 'f', 4) + "," + QString::number(gvariable.global_variable_link.value(key).global_qpointf_value.y(), 'f', 4) + ")";
						}
						else if (gvariable.global_variable_link.value(key).global_type == "cv::Point")
						{
							text_content = "(" + QString::number(gvariable.global_variable_link.value(key).global_cvpoint_value.x) + "," + QString::number(gvariable.global_variable_link.value(key).global_cvpoint_value.y) + ")";
						}
						else if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
						{
							text_content = "(" + QString::number(gvariable.global_variable_link.value(key).global_cvpoint2f_value.x, 'f', 4) + "," + QString::number(gvariable.global_variable_link.value(key).global_cvpoint2f_value.y, 'f', 4) + ")";
						}
						else if (gvariable.global_variable_link.value(key).global_type == "cv::Point3f")
						{
							text_content = "(" + QString::number(gvariable.global_variable_link.value(key).global_cvpoint3f_value.x, 'f', 4) + "," + QString::number(gvariable.global_variable_link.value(key).global_cvpoint3f_value.y, 'f', 4) + "," + QString::number(gvariable.global_variable_link.value(key).global_cvpoint3f_value.z, 'f', 4) + ")";
						}
						else if (gvariable.global_variable_link.value(key).global_type == "cv::Point3d")
						{
							text_content = "(" + QString::number(gvariable.global_variable_link.value(key).global_cvpoint3d_value.x, 'f', 4) + "," + QString::number(gvariable.global_variable_link.value(key).global_cvpoint3d_value.y, 'f', 4) + "," + QString::number(gvariable.global_variable_link.value(key).global_cvpoint3d_value.z, 'f', 4) + ")";
						}
						else if (gvariable.global_variable_link.value(key).global_type == "Float[]")
						{
							for (int n = 0; n < gvariable.global_variable_link.value(key).global_array_float_value.size(); n++)
							{
								text_content += QString::number(gvariable.global_variable_link.value(key).global_array_float_value[n], 'f', 4) + " ";
							}
						}
						else if (gvariable.global_variable_link.value(key).global_type == "Double[]")
						{
							for (int n = 0; n < gvariable.global_variable_link.value(key).global_array_double_value.size(); n++)
							{
								text_content += QString::number(gvariable.global_variable_link.value(key).global_array_double_value[n], 'f', 4) + " ";
							}
						}
					}
				}
				//使用工具变量
				if (text_state_buf == 0)
				{
					strs.clear();
					strs = global_text_content.value(text_keys[m]).global_state.split(".");
					if (strs.size() == 1)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
					if (strs[1] == "状态")
					{
						bool link_state = false;
						for (int n = 0; n < GetToolBase()->m_Tools.size(); n++)
						{
							if (GetToolBase()->m_Tools[n].PublicToolName == strs[0])
							{
								//获取的文本在工具数组中的索引
								text_index = n;
								link_state = true;
							}
						}
						if (link_state == false)
						{
							GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
							return -2;
						}
						text_state = GetToolBase()->m_Tools[text_index].PublicResult.State;
					}
					else
					{
						text_state = false;
					}
				}
				if (text_content_buf == 0)
				{
					strs.clear();
					strs = global_text_content.value(text_keys[m]).global_content.split(".");
					if (strs.size() == 1)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
					if (strs[1] != QString() && strs[1] != "图像" && strs[1] != "旋转矩形")
					{
						bool link_state = false;
						for (int n = 0; n < GetToolBase()->m_Tools.size(); n++)
						{
							if (GetToolBase()->m_Tools[n].PublicToolName == strs[0])
							{
								//获取的文本在工具数组中的索引
								text_index = n;
								link_state = true;
							}
						}
						if (link_state == false)
						{
							GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
							return -2;
						}
						if (strs[1] == "状态")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicResult.State);
						}
						else if (strs[1] == "斑点个数")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicDetect.Quantity);
						}
						else if (strs[1] == "类别")
						{
							text_content = GetToolBase()->m_Tools[text_index].PublicDetect.Category;
						}
						else if (strs[1] == "相似度")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicDetect.Score, 'f', 3);
						}
						else if (strs[1] == "亮度")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicDetect.Brightness, 'f', 3);
						}
						else if (strs[1] == "清晰度")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicDetect.Clarity, 'f', 3);
						}
						else if (strs[1] == "轮廓")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicDetect.Contours.size());
						}
						else if (strs[1] == "面积")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicDetect.Areas.size(); n++)
							{
								text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicDetect.Areas[n], 'f', 1) + " ";
							}
						}
						else if (strs[1] == "重心")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicDetect.CenterPoints.size(); n++)
							{
								text_content += "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicDetect.CenterPoints[n].x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicDetect.CenterPoints[n].y, 'f', 4) + ")" + " ";
							}
						}
						else if (strs[1] == "平面参数")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicThreeD.Flatness.size(); n++)
							{
								text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicThreeD.Flatness[n], 'f', 5) + " ";
							}
						}
						else if (strs[1] == "点到平面距离")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicThreeD.Distance, 'f', 3);
						}
						else if (strs[1] == "条形码" || strs[1] == "二维码" || strs[1] == "识别内容")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicDetect.Code.size(); n++)
							{
								text_content += GetToolBase()->m_Tools[text_index].PublicDetect.Code[n] + " ";
							}
						}
						else if (strs[1] == "字符")
						{
							text_content = GetToolBase()->m_Tools[text_index].PublicDetect.Character;
						}
						else if (strs[1] == "匹配中心坐标")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicTPosition.Center.size(); n++)
							{
								text_content += "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.Center[n].x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.Center[n].y, 'f', 4) + ")" + " ";
							}
						}
						else if (strs[1] == "匹配角度")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicTPosition.Angle.size(); n++)
							{
								text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.Angle[n], 'f', 4) + " ";
							}
						}
						else if (strs[1] == "匹配分数")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicTPosition.OutScore.size(); n++)
							{
								text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.OutScore[n], 'f', 2) + " ";
							}
						}
						else if (strs[1] == "匹配基准中心")
						{
							text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.DatumCenter.x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.DatumCenter.y, 'f', 4) + ")";
						}
						else if (strs[1] == "中心坐标" || strs[1] == "圆心坐标")
						{
							text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Center.x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Center.y, 'f', 4) + ")";
						}
						else if (strs[1] == "半径")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Radius, 'f', 3);
						}
						else if (strs[1] == "角度" || strs[1] == "夹角")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Angle, 'f', 3);
						}
						else if (strs[1] == "长轴长度")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Length1, 'f', 4);
						}
						else if (strs[1] == "短轴长度")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Length2, 'f', 4);
						}
						else if (strs[1] == "斜率")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.k, 'f', 4);
						}
						else if (strs[1] == "截距")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.b, 'f', 4);
						}
						else if (strs[1] == "距离" || strs[1] == "边缘宽度")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicGeometry.DistanceList.size(); n++)
							{
								if (n == GetToolBase()->m_Tools[text_index].PublicGeometry.DistanceList.size() - 1)
								{
									text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.DistanceList[n], 'f', 4);
								}
								else
								{
									text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.DistanceList[n], 'f', 4) + "、";
								}
							}
						}
						else if (strs[1] == "垂足坐标")
						{
							text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Pedal.x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Pedal.y, 'f', 4) + ")";
						}
						else if (strs[1] == "交点坐标")
						{
							if (strs[0].mid(0, 4) == "线线交点")
							{
								text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Intersection.x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Intersection.y, 'f', 4) + ")";
							}
							else if (strs[0].mid(0, 4) == "线圆交点")
							{
								for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicGeometry.Intersections.size(); n++)
								{
									text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Intersections[n].x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Intersections[n].y, 'f', 4) + " ";
								}
							}
						}
						else if (strs[1] == "N点标定参数")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicCalib.EstimateAffine.size(); n++)
							{
								text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.EstimateAffine[n], 'f', 5) + " ";
							}
						}
						else if (strs[1] == "旋转中心")
						{
							text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.RotateCenter.x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.RotateCenter.y, 'f', 4) + ")";
						}
						else if (strs[1] == "基准点1")
						{
							text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.DatumPoint1.x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.DatumPoint1.y, 'f', 4) + ")";
						}
						else if (strs[1] == "基准点2")
						{
							text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.DatumPoint2.x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.DatumPoint2.y, 'f', 4) + ")";
						}
						else if (strs[1] == "像素当量X")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.PixelEquivalentX, 'f', 4);
						}
						else if (strs[1] == "像素当量Y")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.PixelEquivalentY, 'f', 4);
						}
						else if (strs[1] == "基准角度")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.DatumAngle, 'f', 4);
						}
						else if (strs[1] == "移动量X")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.MovingDistanceX, 'f', 4);
						}
						else if (strs[1] == "移动量Y")
						{
							text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.MovingDistanceY, 'f', 4);
						}
						else if (strs[1] == "世界坐标点")
						{
							text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.WorldCoordinatePoint.x, 'f', 4) + "," + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.WorldCoordinatePoint.y, 'f', 4) + ")";
						}
						else if (strs[1] == "接收数据")
						{
							text_content = GetToolBase()->m_Tools[text_index].PublicCommunication.InputData;
						}
						else if (strs[1] == "发送数据")
						{
							text_content = GetToolBase()->m_Tools[text_index].PublicCommunication.OutputData;
						}
						else if (strs[1] == "寄存器读取数据")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicCommunication.RegisterReadData.size(); n++)
							{
								text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicCommunication.RegisterReadData[n]) + " ";
							}
						}
						else if (strs[1] == "寄存器写入数据")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicCommunication.RegisterWriteData.size(); n++)
							{
								text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicCommunication.RegisterWriteData[n]) + " ";
							}
						}
						else
						{
							text_content = QString();
						}
					}
				}
				if (text_state == true)
				{
					getViewMsg.append(global_text_content.value(text_keys[m]).global_prefix + text_content + " 结果为:"+ui.txtOKtext->text());
					WriteString(out_img, global_text_content.value(text_keys[m]).global_prefix + text_content + " 结果为:"+ui.txtOKtext->text(), text_pos, global_text_content.value(text_keys[m]).global_ok_color, ui.spinTextSize->value(), ui.checkBoldFont->isChecked());
				}
				else
				{
					if (text_content == NULL)
					{
						text_content = QString();
					}
					getViewMsg.append(global_text_content.value(text_keys[m]).global_prefix + text_content + " 结果为:"+ ui.txtNGtext->text());
					WriteString(out_img, global_text_content.value(text_keys[m]).global_prefix + text_content + " 结果为:" + ui.txtNGtext->text(), text_pos, global_text_content.value(text_keys[m]).global_ng_color, ui.spinTextSize->value(), ui.checkBoldFont->isChecked());
				}
			}
			v_state = true;
		}
		else
		{
			v_state = false;
		}
		if (ui.checkViewText->isChecked() == false && ui.checkViewContour->isChecked() == false)
		{
			out_img = Mat2QImage(srcImage);
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputViewImage = out_img;
		GetToolBase()->m_Tools[tool_index].PublicScreen.ScreenNumber = ui.comboScreenNum->currentIndex();
		GetToolBase()->m_Tools[tool_index].PublicImageProcess.GetViewMsg.clear();
		GetToolBase()->m_Tools[tool_index].PublicImageProcess.GetViewMsg = getViewMsg;
		GetToolBase()->m_Tools[tool_index].PublicImageProcess.ViewMsgState = v_state;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		if (GetToolBase()->m_Tools[image_index].PublicResult.State == false)
		{
			// 如果NG显示最近一个状态为成功的图像		
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputViewImage = frmImageView::GetErrorImage(image_index);
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputViewImage = out_img;
		}
		return -1;
	}
}
QImage frmImageView::GetErrorImage(int tool_index)
{
	int error_index = 0;
	if(tool_index - 1 >= error_index && GetToolBase()->m_Tools[tool_index - 1].PublicResult.State)
	{
		if (!GetToolBase()->m_Tools[tool_index].PublicImage.OutputViewImage.isNull()) {
			return GetToolBase()->m_Tools[tool_index - 1].PublicImage.OutputViewImage;
		}
		else {
			return Mat2QImage(GetToolBase()->m_Tools[tool_index - 1].PublicImage.OutputImage);
		}
		
	}
	else if(tool_index - 1 >= 0)
	{
		return frmImageView::GetErrorImage(tool_index - 1);
	}
	else {
		return QImage();
	}
}
int frmImageView::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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
			int table_count = ui.tableWidgetContour->rowCount();
			for (int m = 0; m < table_count; m++)
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
				if (str_link == ui.tableWidgetContour->item(m, 0)->text())
				{
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "已存在该轮廓对象！");
					msgBox.setWindowIcon(QIcon(":/resource/error.png"));
					msgBox.exec();
					return -1;
				}
			}
			ui.tableWidgetContour->item(contour_index_row, 0)->setText(str_link);
		}
		else if (int_link == 3)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "请输入全局变量QPoint类型！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			//使用全局变量
			keys.reserve(300);
			keys.clear();
			keys = gvariable.global_variable_link.uniqueKeys();
			int var_state_buf = 0;
			for (int p = 0; p < keys.length(); p++)
			{
				QString key = keys[p];
				if (gvariable.global_variable_link.value(key).global_type == "QPoint")
				{
					if (key == str_link)
					{
						ui.txtPos_XY->setText(str_link);
						var_state_buf = 1;
					}
				}
			}
			if (var_state_buf == 0)
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
		}
		else if (int_link == 4)
		{
			strs.clear();
			strs = str_link.split(".");
			if (strs.size() == 2 && strs[1] != "状态")
			{
				QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
				msgBox.setWindowIcon(QIcon(":/resource/error.png"));
				msgBox.exec();
				return -1;
			}
			ui.txtState->setText(str_link);
		}
		else if (int_link == 5)
		{
			int table_count = ui.tableWidgetText->rowCount();
			for (int m = 0; m < table_count; m++)
			{
				if (str_link == ui.tableWidgetText->item(m, 0)->text())
				{
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "已存在该文本内容！");
					msgBox.setWindowIcon(QIcon(":/resource/error.png"));
					msgBox.exec();
					return -1;
				}
			}
			ui.txtContent->setText(str_link);
			ui.tableWidgetText->item(text_index_row, 0)->setText(str_link);
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmImageView::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmImageView::InitSetToolData(const QVariant data)
{
	try
	{
		InitImageViewData init_data;
		init_data = data.value<InitImageViewData>();
		for (int m = 0; m < init_data.key.count(); m++)
		{
			TextContent.global_pos_xy = init_data.global_pos_xy[m];
			TextContent.global_state = init_data.global_state[m];
			TextContent.global_content = init_data.global_content[m];
			TextContent.global_prefix = init_data.global_prefix[m];
			TextContent.global_ok_color = init_data.global_ok_color[m];
			TextContent.global_ng_color = init_data.global_ng_color[m];
			TextContent.global_OKtext = init_data.global_OK_text[m];
			TextContent.global_NGtext = init_data.global_NG_text[m];
			global_text_content.insert(init_data.key[m], TextContent);
		}	
		color = init_data.contour_color;
		//设置按钮背景颜色
		QString style_color = "background-color: rgb(" + QString::number(color.red()) + "," + QString::number(color.green()) + "," + QString::number(color.blue()) + ")";
		ui.btnColor->setStyleSheet(style_color);
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmImageView::InitGetToolData()
{
	InitImageViewData init_data;
	text_keys.reserve(100);
	text_keys.clear();
	text_keys = global_text_content.uniqueKeys();	
	for (int m = 0; m < text_keys.count(); m++)
	{
		QString key = text_keys[m];
		init_data.key.append(key);
		init_data.global_pos_xy.append(global_text_content.value(key).global_pos_xy);
		init_data.global_state.append(global_text_content.value(key).global_state);
		init_data.global_content.append(global_text_content.value(key).global_content);
		init_data.global_prefix.append(global_text_content.value(key).global_prefix);
		init_data.global_ok_color.append(global_text_content.value(key).global_ok_color);
		init_data.global_ng_color.append(global_text_content.value(key).global_ng_color);
		init_data.global_OK_text.append(global_text_content.value(key).global_OKtext);
		init_data.global_NG_text.append(global_text_content.value(key).global_NGtext);
	}	
	init_data.contour_color = color;
	return QVariant::fromValue(init_data);
}

void frmImageView::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmImageView::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmImageView::slot_DoubleClicked(int row, int column)
{
	QConfig::nFormState = 2;
	contour_index_row = row;
}

void frmImageView::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	view->DispImage(out_img);
	ui.btnExecute->setEnabled(true);
}

void frmImageView::on_btnColor_clicked()
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
		ui.btnColor->setAutoFillBackground(true);
		ui.btnColor->setFlat(true);
		QPalette palette = ui.btnColor->palette();
		palette.setColor(QPalette::Button, color);
		ui.btnColor->setPalette(palette);
	}
}

void frmImageView::on_btnAddContour_clicked()
{
	int count = ui.tableWidgetContour->rowCount();
	ui.tableWidgetContour->setRowCount(count + 1);  //设置行数	
	//删除流程后重新计算
	int i = 0;
	if (m_process_contour_buf.count() != 0)
	{
		//按升序排序
		qSort(m_process_contour_buf.begin(), m_process_contour_buf.end());
		//最小值
		i = m_process_contour_buf[0];
		m_process_contour_buf.removeAt(0);
	}
	else
	{
		i = count + 1;
	}
	QTableWidgetItem* item_name = new QTableWidgetItem("轮廓链接地址" + QString::number(i));
	item_name->setFlags(item_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
	item_name->setTextAlignment(Qt::AlignLeft);
	item_name->setTextAlignment(Qt::AlignVCenter);
	ui.tableWidgetContour->setItem(count, 0, item_name);
}

void frmImageView::on_btnDeleteContour_clicked()
{
	int rowIndex = ui.tableWidgetContour->currentRow();
	if (rowIndex != -1)
	{
		QString str = ui.tableWidgetContour->item(rowIndex, 0)->text();
		if (str.mid(0, 6) == "轮廓链接地址")
		{
			int flow = str.mid(6, str.length()).toInt();
			m_process_contour_buf.append(flow);
		}
		ui.tableWidgetContour->removeRow(rowIndex);
	}
}

void frmImageView::on_btnOkColor_clicked()
{
	QColorDialog dlg(this);
	dlg.setMinimumSize(547, 393);
	dlg.setWindowTitle("Color Editor");
	dlg.setCurrentColor(QColor(100, 111, 222));
	dlg.setWindowIcon(QIcon(":/resource/color_edit.png"));
	if (dlg.exec() == QColorDialog::Accepted)
	{
		ok_color = dlg.selectedColor();
		//设置按钮背景颜色		
		QString style_ok_color = "background-color: rgb(" + QString::number(ok_color.red()) + "," + QString::number(ok_color.green()) + "," + QString::number(ok_color.blue()) + ")";
		ui.btnOkColor->setStyleSheet(style_ok_color);		
	}
}

void frmImageView::on_btnNgColor_clicked()
{
	QColorDialog dlg(this);
	dlg.setMinimumSize(547, 393);
	dlg.setWindowTitle("Color Editor");
	dlg.setCurrentColor(QColor(100, 111, 222));
	dlg.setWindowIcon(QIcon(":/resource/color_edit.png"));
	if (dlg.exec() == QColorDialog::Accepted)
	{
		ng_color = dlg.selectedColor();
		//设置按钮背景颜色		
		QString style_ng_color = "background-color: rgb(" + QString::number(ng_color.red()) + "," + QString::number(ng_color.green()) + "," + QString::number(ng_color.blue()) + ")";
		ui.btnNgColor->setStyleSheet(style_ng_color);
	}
}

void frmImageView::on_btnAddText_clicked()
{
	int count = ui.tableWidgetText->rowCount();
	if (count >= 20)
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "最多添加20个文本链接地址！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	ui.tableWidgetText->setRowCount(count + 1);  //设置行数	
	//删除流程后重新计算
	int i = 0;
	if (m_process_text_buf.count() != 0)
	{
		//按升序排序
		qSort(m_process_text_buf.begin(), m_process_text_buf.end());
		//最小值
		i = m_process_text_buf[0];
		m_process_text_buf.removeAt(0);
	}
	else
	{
		i = count + 1;
	}
	QTableWidgetItem* item_name = new QTableWidgetItem("文本链接地址" + QString::number(i));
	item_name->setFlags(item_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
	item_name->setTextAlignment(Qt::AlignLeft);
	item_name->setTextAlignment(Qt::AlignVCenter);
	ui.tableWidgetText->setItem(count, 0, item_name);
}

void frmImageView::on_btnDeleteText_clicked()
{
	int rowIndex = ui.tableWidgetText->currentRow();
	if (rowIndex != -1)
	{
		QString str = ui.tableWidgetText->item(rowIndex, 0)->text();
		if (str.mid(0, 6) == "文本链接地址")
		{
			int flow = str.mid(6, str.length()).toInt();
			m_process_text_buf.append(flow);
		}
		global_text_content.remove(str);
		ui.tableWidgetText->removeRow(rowIndex);
	}
}

void frmImageView::slot_TextDoubleClicked(int row, int column)
{
	QString str = ui.tableWidgetText->item(row, 0)->text();
	if (str.mid(0, 6) == "文本链接地址")
	{
		content_buf = QString();
		ui.txtPos_XY->clear();
		ui.txtState->clear();
		ui.txtContent->clear();
		ui.txtPrefix->clear();
		QString style_ok_color = "background-color: rgb(" + QString::number(ok_color.red()) + "," + QString::number(ok_color.green()) + "," + QString::number(ok_color.blue()) + ")";
		ui.btnOkColor->setStyleSheet(style_ok_color);
		QString style_ng_color = "background-color: rgb(" + QString::number(ng_color.red()) + "," + QString::number(ng_color.green()) + "," + QString::number(ng_color.blue()) + ")";
		ui.btnNgColor->setStyleSheet(style_ng_color);
	}
	else
	{
		text_keys.reserve(100);
		text_keys.clear();
		text_keys = global_text_content.uniqueKeys();
		for (int k = 0; k < text_keys.length(); k++)
		{
			QString key = text_keys[k];
			if (key == str)
			{
				ui.txtPos_XY->setText(global_text_content.value(key).global_pos_xy);
				ui.txtState->setText(global_text_content.value(key).global_state);
				ui.txtContent->setText(global_text_content.value(key).global_content);
				content_buf = global_text_content.value(key).global_content;
				ui.txtPrefix->setText(global_text_content.value(key).global_prefix);
				ui.txtOKtext->setText(global_text_content.value(key).global_OKtext);
				ui.txtNGtext->setText(global_text_content.value(key).global_NGtext);
				ok_color = global_text_content.value(key).global_ok_color;
				ng_color = global_text_content.value(key).global_ng_color;
				QString style_ok_color = "background-color: rgb(" + QString::number(ok_color.red()) + "," + QString::number(ok_color.green()) + "," + QString::number(ok_color.blue()) + ")";
				ui.btnOkColor->setStyleSheet(style_ok_color);
				QString style_ng_color = "background-color: rgb(" + QString::number(ng_color.red()) + "," + QString::number(ng_color.green()) + "," + QString::number(ng_color.blue()) + ")";
				ui.btnNgColor->setStyleSheet(style_ng_color);			
			}
		}
	}
	ui.stackedWidget->setCurrentIndex(1);
	text_index_row = row;
}

void frmImageView::on_btnSave_clicked()
{
	if (ui.txtPos_XY->text() == QString() || ui.txtState->text() == QString() || ui.txtContent->text() == QString())
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "参数保存失败！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	TextContent.global_pos_xy = ui.txtPos_XY->text();
	TextContent.global_state = ui.txtState->text();
	TextContent.global_content = ui.txtContent->text();
	TextContent.global_prefix = ui.txtPrefix->text();
	TextContent.global_ok_color = ok_color;
	TextContent.global_ng_color = ng_color;
	TextContent.global_OKtext = ui.txtOKtext->text();
	TextContent.global_NGtext = ui.txtNGtext->text();
	if (content_buf != QString() && content_buf != ui.txtContent->text())
	{
		global_text_content.remove(content_buf);
		global_text_content.insert(ui.txtContent->text(), TextContent);
	}
	else
	{
		global_text_content.insert(ui.txtContent->text(), TextContent);
	}		
	QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "参数保存完成！");
	msgBox.setWindowIcon(QIcon(":/resource/info.png"));
	msgBox.exec();
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageView::on_btnBack_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

void frmImageView::on_btnLinkPos_XY_clicked()
{
	QConfig::nFormState = 3;
}

void frmImageView::on_btnDelLinkPos_XY_clicked()
{
	ui.txtPos_XY->clear();
}

void frmImageView::on_btnLinkState_clicked()
{
	QConfig::nFormState = 4;
}

void frmImageView::on_btnDelLinkState_clicked()
{
	ui.txtState->clear();
}

void frmImageView::on_btnLinkContent_clicked()
{
	QConfig::nFormState = 5;
}

void frmImageView::on_btnDelLinkContent_clicked()
{
	ui.txtContent->clear();
}

//显示信息
//bool frmImageView::WriteString(QImage& img, const QString str_msg, const QPoint str_pos, const QColor font_color, const int font_size, const bool font_bold) const
//{
//	try
//	{
//		//实例QPainter
//		QPainter painter(&img);
//		//设置画刷模式
//		painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
//		QPen pen = painter.pen();
//		pen.setColor(font_color);
//		QFont font = painter.font();
//		font.setBold(font_bold); //加粗
//		font.setPixelSize(font_size); //改变字体大小
//		font.setFamily("Microsoft YaHei");//设置字体
//		painter.setPen(pen);
//		painter.setFont(font);
//		//将文字绘制在图片指定位置
//		painter.drawText(str_pos, str_msg);
//		return true;
//	}
//	catch (...)
//	{
//		return false;
//	}
//}
bool frmImageView::WriteString(QImage& img, const QString str_msg, const QPoint str_pos, const QColor font_color, const int font_size, const bool font_bold) const
{
	// 确保图像有效且可写
	if (img.isNull() || img.format() == QImage::Format_Invalid) {
		qDebug() << "Invalid image format";
		return false;
	}

	// 确保图像格式支持绘制操作
	if (img.format() != QImage::Format_ARGB32 &&
		img.format() != QImage::Format_RGB32) {
		img = img.convertToFormat(QImage::Format_ARGB32);
	}

	try
	{
		// 初始化 QPainter
		QPainter painter(&img);
		if (!painter.isActive()) {
			qDebug() << "QPainter failed to initialize";
			return false;
		}

		// 使用安全的合成模式
		painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

		// 设置字体
		QFont font("Microsoft YaHei", font_size);
		font.setBold(font_bold);
		painter.setFont(font);

		// 设置画笔颜色
		painter.setPen(font_color);

		// 添加抗锯齿
		painter.setRenderHint(QPainter::Antialiasing);
		painter.setRenderHint(QPainter::TextAntialiasing);

		// 绘制文本
		painter.drawText(str_pos, str_msg);

		return true;
	}
	catch (const std::exception& e)
	{
		qCritical() << "Exception in WriteString:" << e.what();
	}
	catch (...)
	{
		qCritical() << "Unknown exception in WriteString";
	}
	return false;
}
#pragma region QImage与Mat相互转换
//将Mat转化为QImage
QImage frmImageView::Mat2QImage(const cv::Mat& mat)
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

//将QImage转化为Mat
cv::Mat frmImageView::QImageToMat(const QImage& image)
{
	cv::Mat mat;
	if (image.isNull())
	{
		return cv::Mat();
	}
	switch (image.format())
	{
	case QImage::Format_ARGB32_Premultiplied:
	{
		mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
		break;
	}
	case QImage::Format_RGB888:
	{
		mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
		cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
		break;
	}
	case QImage::Format_Indexed8:
	{
		mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
		break;
	}
	case QImage::Format_Grayscale8:
	{
		mat = cv::Mat(image.height(), image.width(), CV_8UC1, const_cast<uchar*>(image.bits()), static_cast<size_t>(image.bytesPerLine()));
		break;
	}
	}
	return mat;
}
#pragma endregion

//全局变量控制
int QConfig::nFormState = 0;
