#include "frmExportCsv.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QPainter>
#include <QTextStream>
#include <QDateTime>
#include <QGraphicsOpacityEffect>

frmExportCsv::frmExportCsv(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/export_csv.png"));
	//初始化标题栏
	initTitleBar();
	//连接信号与槽			
	connect(ui.comboType, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_CurrentIndexChanged(int)));
	ui.comboType->setCurrentIndex(1);
	QTimer* p_timer = new QTimer(this);
	connect(p_timer, SIGNAL(timeout()), this, SLOT(timerEvent()));
	p_timer->start(10 * 60 * 1000);  //10分钟
	//设置表格列宽	
	ui.tableWidgetContent->setColumnWidth(0, 503);
	//设置表格行间距
	ui.tableWidgetContent->verticalHeader()->setDefaultSectionSize(15);
	ui.tableWidgetContent->verticalHeader()->setMinimumSectionSize(15);
	//隐藏水平header
	ui.tableWidgetContent->verticalHeader()->setVisible(false);
	ui.tableWidgetContent->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行
	ui.tableWidgetContent->setSelectionMode(QAbstractItemView::SingleSelection);  //设置只能单选
	connect(ui.tableWidgetContent, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(slot_DoubleClicked(int, int)));
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtStoragePath->setGraphicsEffect(e);
}

frmExportCsv::~frmExportCsv()
{
	this->deleteLater();
}

void frmExportCsv::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/export_csv.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmExportCsv::paintEvent(QPaintEvent* event)
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

void frmExportCsv::onButtonCloseClicked()
{
	this->close();
}

void frmExportCsv::timerEvent()
{
	int day = 0;
	day = 0 - ui.spinImageTime->value();
	FindFileForDelete(ui.txtStoragePath->toPlainText(), day);
}

int frmExportCsv::Execute(const QString toolname)
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

int frmExportCsv::RunToolPro()
{
	try
	{
		QDateTime dateTime(QDateTime::currentDateTime());
		bool state;
		if (!QFile::exists(dirPath + "/" + dateTime.toString("yyyyMMdd") + ".csv"))
		{
			typeNames.insert(0, "时间");
			state = WriteCSV(dirPath + "/" + dateTime.toString("yyyyMMdd") + ".csv", typeNames);
		}
		else
		{
			typeContents.clear();
			typeContents.insert(0, dateTime.toString("hh:mm:ss.zzz"));
			int table_contour_count = ui.tableWidgetContent->rowCount();
			vector<int> value_buf;
			value_buf.resize(table_contour_count);
			for (int m = 0; m < table_contour_count; m++)
			{
				//使用全局变量
				var_keys.reserve(300);
				var_keys.clear();
				var_keys = gvariable.global_variable_link.uniqueKeys();
				for (int p = 0; p < var_keys.length(); p++)
				{
					QString key = var_keys[p];
					if (gvariable.global_variable_link.value(key).global_type == "Int")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							QString str_text = QString::number(gvariable.global_variable_link.value(key).global_int_value);
							typeContents.insert(m + 1, str_text);
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "Double")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							QString str_text = QString::number(gvariable.global_variable_link.value(key).global_double_value, 'f', 4);
							typeContents.insert(m + 1, str_text);
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "QString")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							QString str_text = gvariable.global_variable_link.value(key).global_qstring_value;
							typeContents.insert(m + 1, str_text);
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "Bool")
					{
						if (gvariable.global_variable_link.value(key).global_bool_value == true)
						{
							typeContents.insert(m + 1, "OK");
							value_buf[m] = 1;
							break;
						}
						else
						{
							typeContents.insert(m + 1, "NG");
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "QPoint")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							QPoint p_text = gvariable.global_variable_link.value(key).global_qpoint_value;
							typeContents.insert(m + 1, "(" + QString::number(p_text.x()) + "，" + QString::number(p_text.y()) + ")");
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "QPointF")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							QPointF p_text = gvariable.global_variable_link.value(key).global_qpointf_value;
							typeContents.insert(m + 1, "(" + QString::number(p_text.x(), 'f', 4) + "，" + QString::number(p_text.y(), 'f', 4) + ")");
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "cv::Point")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							cv::Point p_text = gvariable.global_variable_link.value(key).global_cvpoint_value;
							typeContents.insert(m + 1, "(" + QString::number(p_text.x) + "，" + QString::number(p_text.y) + ")");
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "cv::Point2f")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							cv::Point2f p_text = gvariable.global_variable_link.value(key).global_cvpoint2f_value;
							typeContents.insert(m + 1, "(" + QString::number(p_text.x, 'f', 4) + "，" + QString::number(p_text.y, 'f', 4) + ")");
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "cv::Point3f")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							cv::Point3f p_text = gvariable.global_variable_link.value(key).global_cvpoint3f_value;
							typeContents.insert(m + 1, "(" + QString::number(p_text.x, 'f', 4) + "，" + QString::number(p_text.y, 'f', 4) + "，" + QString::number(p_text.z, 'f', 4) + ")");
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "cv::Point3d")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							cv::Point3d p_text = gvariable.global_variable_link.value(key).global_cvpoint3d_value;
							typeContents.insert(m + 1, "(" + QString::number(p_text.x, 'f', 4) + "，" + QString::number(p_text.y, 'f', 4) + "，" + QString::number(p_text.z, 'f', 4) + ")");
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "Float[]")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							QString str_text;
							for (int n = 0; n < gvariable.global_variable_link.value(key).global_array_float_value.size(); n++)
							{
								str_text += QString::number(gvariable.global_variable_link.value(key).global_array_float_value[n], 'f', 4) + " ";
							}
							typeContents.insert(m + 1, str_text);
							value_buf[m] = 1;
							break;
						}
					}
					else if (gvariable.global_variable_link.value(key).global_type == "Double[]")
					{
						if (key == ui.tableWidgetContent->item(m, 0)->text())
						{
							QString str_text;
							for (int n = 0; n < gvariable.global_variable_link.value(key).global_array_double_value.size(); n++)
							{
								str_text += QString::number(gvariable.global_variable_link.value(key).global_array_double_value[n], 'f', 4) + " ";
							}
							typeContents.insert(m + 1, str_text);
							value_buf[m] = 1;
							break;
						}
					}
				}
				//使用工具变量
				if (value_buf[m] != 1)
				{
					strs.clear();
					strs = ui.tableWidgetContent->item(m, 0)->text().split(".");
					if (strs.size() == 1)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -1;
					}
					bool link_state = false;
					int text_index = 0;
					for (int n = 0; n < GetToolBase()->m_Tools.size(); n++)
					{
						if (GetToolBase()->m_Tools[n].PublicToolName == strs[0])
						{
							//获取的工具在工具数组中的索引
							text_index = n;
							link_state = true;
						}
					}
					if (link_state == false)
					{
						GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
						return -2;
					}
					QString text_content;
					if (strs[1] == "条形码" || strs[1] == "二维码")
					{
						for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicDetect.Code.size(); n++)
						{
							text_content += GetToolBase()->m_Tools[text_index].PublicDetect.Code[n] + " ";
						}
					}
					else if (strs[1] == "斑点个数")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicDetect.Quantity);
					}
					else if (strs[1] == "字符")
					{
						text_content = GetToolBase()->m_Tools[text_index].PublicDetect.Character;
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
					else if (strs[1] == "面积")
					{
						for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicDetect.Areas.size(); n++)
						{
							text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicDetect.Areas[n], 'f', 1) + " ";
						}
					}
					else if (strs[1] == "像素当量X")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.PixelEquivalentX, 'f', 4);
					}
					else if (strs[1] == "像素当量Y")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.PixelEquivalentY, 'f', 4);
					}
					else if (strs[1] == "角度" || strs[1] == "夹角")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Angle, 'f', 3);
					}
					else if (strs[1] == "距离" || strs[1] == "边缘宽度")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Distance, 'f', 4);
					}
					else if (strs[1] == "斜率")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.k, 'f', 4);
					}
					else if (strs[1] == "截距")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.b, 'f', 4);
					}
					else if (strs[1] == "半径")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Radius, 'f', 3);
					}
					else if (strs[1] == "长轴长度")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Length1, 'f', 4);
					}
					else if (strs[1] == "短轴长度")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Length2, 'f', 4);
					}
					else if (strs[1] == "旋转中心")
					{
						text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.RotateCenter.x, 'f', 4) + "，" + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.RotateCenter.y, 'f', 4) + ")";
					}
					else if (strs[1] == "基准点1")
					{
						text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.DatumPoint1.x, 'f', 4) + "，" + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.DatumPoint1.y, 'f', 4) + ")";
					}
					else if (strs[1] == "基准点2")
					{
						text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.DatumPoint2.x, 'f', 4) + "，" + QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.DatumPoint2.y, 'f', 4) + ")";
					}
					else if (strs[1] == "基准角度")
					{
						text_content = QString::number(GetToolBase()->m_Tools[text_index].PublicCalib.DatumAngle, 'f', 4);
					}
					else if (strs[1] == "匹配基准中心")
					{
						text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.DatumCenter.x, 'f', 4) + "，" + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.DatumCenter.y, 'f', 4) + ")";
					}
					else if (strs[1] == "匹配中心坐标")
					{
						for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicTPosition.Center.size(); n++)
						{
							text_content += "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.Center[n].x, 'f', 4) + "，" + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.Center[n].y, 'f', 4) + ")" + " ";
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
					else if (strs[1] == "世界坐标点")
					{
						text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.WorldCoordinatePoint.x, 'f', 4) + "，" + QString::number(GetToolBase()->m_Tools[text_index].PublicTPosition.WorldCoordinatePoint.y, 'f', 4) + ")";
					}
					else if (strs[1] == "中心坐标" || strs[1] == "圆心坐标")
					{
						text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Center.x, 'f', 4) + "，" + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Center.y, 'f', 4) + ")";
					}
					else if (strs[1] == "垂足坐标")
					{
						text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Pedal.x, 'f', 4) + "，" + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Pedal.y, 'f', 4) + ")";
					}
					else if (strs[1] == "交点坐标")
					{
						if (strs[0].mid(0, 4) == "线线交点")
						{
							text_content = "(" + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Intersection.x, 'f', 4) + "，" + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Intersection.y, 'f', 4) + ")";
						}
						else if (strs[0].mid(0, 4) == "线圆交点")
						{
							for (int n = 0; n < GetToolBase()->m_Tools[text_index].PublicGeometry.Intersections.size(); n++)
							{
								text_content += QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Intersections[n].x, 'f', 4) + "，" + QString::number(GetToolBase()->m_Tools[text_index].PublicGeometry.Intersections[n].y, 'f', 4) + " ";
							}
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
					typeContents.insert(m + 1, text_content);
				}
			}
			state = WriteCSV(dirPath + "/" + dateTime.toString("yyyyMMdd") + ".csv", typeContents);
		}
		GetToolBase()->m_Tools[tool_index].PublicResult.State = state;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmExportCsv::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
{
	try
	{
		gvariable.global_variable_link = variable_link;
		if (int_link == 1)
		{
			int table_count = ui.tableWidgetContent->rowCount();
			for (int m = 0; m < table_count; m++)
			{
				strs.reserve(100);
				strs.clear();
				strs = str_link.split(".");
				if (strs.size() == 2 && strs[1] != "条形码" && strs[1] != "二维码" && strs[1] != "斑点个数" && strs[1] != "字符" && strs[1] != "类别" && strs[1] != "相似度" && strs[1] != "亮度" && strs[1] != "清晰度" && strs[1] != "面积" && strs[1] != "像素当量X" && strs[1] != "像素当量Y" && strs[1] != "角度" && strs[1] != "距离" && strs[1] != "斜率" && strs[1] != "截距" && strs[1] != "半径" && strs[1] != "长轴长度" && strs[1] != "短轴长度" && strs[1] != "旋转中心" && strs[1] != "基准点1" && strs[1] != "基准点2" && strs[1] != "基准角度" && strs[1] != "匹配基准中心" && strs[1] != "匹配中心坐标" && strs[1] != "匹配角度" && strs[1] != "匹配分数" && strs[1] != "世界坐标点" && strs[1] != "中心坐标" && strs[1] != "垂足坐标" && strs[1] != "交点坐标" && strs[1] != "平面参数" && strs[1] != "点到平面距离" && strs[1] != "边缘宽度" && strs[1] != "圆心坐标" && strs[1] != "夹角" && strs[1] != "接收数据" && strs[1] != "发送数据" && strs[1] != "寄存器数据")
				{
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "输入的链接错误！");
					msgBox.setWindowIcon(QIcon(":/resource/error.png"));
					msgBox.exec();
					return -1;
				}
				if (str_link == ui.tableWidgetContent->item(m, 0)->text())
				{
					QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "已存在该文本内容！");
					msgBox.setWindowIcon(QIcon(":/resource/error.png"));
					msgBox.exec();
					return -1;
				}
			}
			ui.tableWidgetContent->item(text_index_row, 0)->setText(str_link);
		}
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

int frmExportCsv::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

int frmExportCsv::InitSetToolData(const QVariant data)
{
	try
	{
		InitExportCsvData init_data;
		init_data = data.value<InitExportCsvData>();
		for (int m = 0; m < init_data.csv_key.count(); m++)
		{			
			typeNames.insert(init_data.csv_key[m], init_data.csv_names[m]);
		}		
		dirPath = init_data.dirPath;
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}

QVariant frmExportCsv::InitGetToolData()
{
	InitExportCsvData init_data;
	QList<int> text_keys;
	text_keys.reserve(100);
	text_keys.clear();
	text_keys = typeNames.uniqueKeys();
	for (int m = 0; m < text_keys.count(); m++)
	{
		int key = text_keys[m];
		init_data.csv_key.append(key);
		init_data.csv_names.append(typeNames.value(key));
	}	
	init_data.dirPath = dirPath;
	return QVariant::fromValue(init_data);
}

void frmExportCsv::on_btnStoragePath_clicked()
{
	QString path_Csv = QDir::currentPath();
	dirPath = QFileDialog::getExistingDirectory(this, tr("打开存储路径"), path_Csv);
	if (false == dirPath.isEmpty())
	{
		ui.txtStoragePath->setText(dirPath);
	}
}

void frmExportCsv::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	Execute(GetToolName());
	ui.btnExecute->setEnabled(true);
}

void frmExportCsv::slot_CurrentIndexChanged(int index)
{
	typeNames.clear();
	ui.comboTypeBuf->clear();
	switch (index) {
	case 0:
		ui.comboTypeBuf->addItem("第2列标题名称");
		break;
	case 1:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		break;
	case 2:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		break;
	case 3:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		break;
	case 4:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		break;
	case 5:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		ui.comboTypeBuf->addItem("第7列标题名称");
		break;
	case 6:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		ui.comboTypeBuf->addItem("第7列标题名称");
		ui.comboTypeBuf->addItem("第8列标题名称");
		break;
	case 7:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		ui.comboTypeBuf->addItem("第7列标题名称");
		ui.comboTypeBuf->addItem("第8列标题名称");
		ui.comboTypeBuf->addItem("第9列标题名称");
		break;
	case 8:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		ui.comboTypeBuf->addItem("第7列标题名称");
		ui.comboTypeBuf->addItem("第8列标题名称");
		ui.comboTypeBuf->addItem("第9列标题名称");
		ui.comboTypeBuf->addItem("第10列标题名称");
		break;
	case 9:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		ui.comboTypeBuf->addItem("第7列标题名称");
		ui.comboTypeBuf->addItem("第8列标题名称");
		ui.comboTypeBuf->addItem("第9列标题名称");
		ui.comboTypeBuf->addItem("第10列标题名称");
		ui.comboTypeBuf->addItem("第11列标题名称");
		break;
	case 10:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		ui.comboTypeBuf->addItem("第7列标题名称");
		ui.comboTypeBuf->addItem("第8列标题名称");
		ui.comboTypeBuf->addItem("第9列标题名称");
		ui.comboTypeBuf->addItem("第10列标题名称");
		ui.comboTypeBuf->addItem("第11列标题名称");
		ui.comboTypeBuf->addItem("第12列标题名称");
		break;
	case 11:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		ui.comboTypeBuf->addItem("第7列标题名称");
		ui.comboTypeBuf->addItem("第8列标题名称");
		ui.comboTypeBuf->addItem("第9列标题名称");
		ui.comboTypeBuf->addItem("第10列标题名称");
		ui.comboTypeBuf->addItem("第11列标题名称");
		ui.comboTypeBuf->addItem("第12列标题名称");
		ui.comboTypeBuf->addItem("第13列标题名称");
		break;
	case 12:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		ui.comboTypeBuf->addItem("第7列标题名称");
		ui.comboTypeBuf->addItem("第8列标题名称");
		ui.comboTypeBuf->addItem("第9列标题名称");
		ui.comboTypeBuf->addItem("第10列标题名称");
		ui.comboTypeBuf->addItem("第11列标题名称");
		ui.comboTypeBuf->addItem("第12列标题名称");
		ui.comboTypeBuf->addItem("第13列标题名称");
		ui.comboTypeBuf->addItem("第14列标题名称");
		break;
	case 13:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		ui.comboTypeBuf->addItem("第7列标题名称");
		ui.comboTypeBuf->addItem("第8列标题名称");
		ui.comboTypeBuf->addItem("第9列标题名称");
		ui.comboTypeBuf->addItem("第10列标题名称");
		ui.comboTypeBuf->addItem("第11列标题名称");
		ui.comboTypeBuf->addItem("第12列标题名称");
		ui.comboTypeBuf->addItem("第13列标题名称");
		ui.comboTypeBuf->addItem("第14列标题名称");
		ui.comboTypeBuf->addItem("第15列标题名称");
		break;
	case 14:
		ui.comboTypeBuf->addItem("第2列标题名称");
		ui.comboTypeBuf->addItem("第3列标题名称");
		ui.comboTypeBuf->addItem("第4列标题名称");
		ui.comboTypeBuf->addItem("第5列标题名称");
		ui.comboTypeBuf->addItem("第6列标题名称");
		ui.comboTypeBuf->addItem("第7列标题名称");
		ui.comboTypeBuf->addItem("第8列标题名称");
		ui.comboTypeBuf->addItem("第9列标题名称");
		ui.comboTypeBuf->addItem("第10列标题名称");
		ui.comboTypeBuf->addItem("第11列标题名称");
		ui.comboTypeBuf->addItem("第12列标题名称");
		ui.comboTypeBuf->addItem("第13列标题名称");
		ui.comboTypeBuf->addItem("第14列标题名称");
		ui.comboTypeBuf->addItem("第15列标题名称");
		ui.comboTypeBuf->addItem("第16列标题名称");
		break;
	}
}

void frmExportCsv::on_btnWrite_clicked()
{
	QMessageBox msgBox(QMessageBox::Icon::NoIcon, "提示", "当前列标题写入完成！");
	msgBox.setWindowIcon(QIcon(":/resource/info.png"));
	switch (ui.comboTypeBuf->currentIndex()) {
	case 0:
		typeNames.insert(1, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 1:
		typeNames.insert(2, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 2:
		typeNames.insert(3, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 3:
		typeNames.insert(4, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 4:
		typeNames.insert(5, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 5:
		typeNames.insert(6, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 6:
		typeNames.insert(7, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 7:
		typeNames.insert(8, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 8:
		typeNames.insert(9, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 9:
		typeNames.insert(10, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 10:
		typeNames.insert(11, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 11:
		typeNames.insert(12, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 12:
		typeNames.insert(13, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 13:
		typeNames.insert(14, ui.txtTypeName->text());
		msgBox.exec();
		break;
	case 14:
		typeNames.insert(15, ui.txtTypeName->text());
		msgBox.exec();
		break;
	}
}

void frmExportCsv::on_comboTypeBuf_currentIndexChanged(int index)
{
	ui.txtTypeName->clear();
}

void frmExportCsv::slot_DoubleClicked(int row, int column)
{
	QConfig::nFormState = 1;
	text_index_row = row;
}

void frmExportCsv::on_btnAddContent_clicked()
{
	int index = ui.comboType->currentIndex();
	int count = ui.tableWidgetContent->rowCount();
	if (count > index)
	{
		QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "内容列数超过指定个数！");
		msgBox.setWindowIcon(QIcon(":/resource/error.png"));
		msgBox.exec();
		return;
	}
	ui.tableWidgetContent->setRowCount(count + 1);  //设置行数	
	QTableWidgetItem* item_name = new QTableWidgetItem("内容链接地址" + QString::number(count + 1));
	item_name->setFlags(item_name->flags() & (~Qt::ItemIsEditable));  //设置列不可编辑	
	item_name->setTextAlignment(Qt::AlignLeft);
	item_name->setTextAlignment(Qt::AlignVCenter);
	ui.tableWidgetContent->setItem(count, 0, item_name);
}

void frmExportCsv::on_btnDeleteContent_clicked()
{
	int rowIndex = ui.tableWidgetContent->currentRow();
	if (rowIndex != -1)
	{
		ui.tableWidgetContent->removeRow(rowIndex);
	}
}

void frmExportCsv::on_btnMoveUp_clicked()
{
	int nRow = ui.tableWidgetContent->currentRow();
	moveRow(ui.tableWidgetContent, nRow, nRow - 1);
}

void frmExportCsv::on_btnMoveDown_clicked()
{
	int nRow = ui.tableWidgetContent->currentRow();
	moveRow(ui.tableWidgetContent, nRow, nRow + 2);
}

void frmExportCsv::moveRow(QTableWidget* pTable, int nFrom, int nTo) const
{
	if (pTable == NULL) return;
	pTable->setFocus();
	if (nFrom == nTo) return;
	if (nFrom < 0 || nTo < 0) return;
	int nRowCount = pTable->rowCount();
	if (nFrom >= nRowCount || nTo > nRowCount) return;
	if (nTo < nFrom) nFrom++; pTable->insertRow(nTo);
	int nCol = pTable->columnCount();
	for (int i = 0; i < nCol; i++)
	{
		pTable->setItem(nTo, i, pTable->takeItem(nFrom, i));
	}
	if (nFrom < nTo)
	{
		nTo--;
	}
	pTable->removeRow(nFrom); pTable->selectRow(nTo);
}

bool frmExportCsv::WriteCSV(const QString pathName, const QMap<int, QString> vector_str)
{
	try
	{
		QString tmpStr;
		tmpStr.reserve(100);
		tmpStr.clear();
		int count = vector_str.size();
		for (int i = 0; i < count; i++)
		{
			tmpStr.append(vector_str[i]);
			if (i < (count - 1))
			{
				tmpStr.append(',');
			}
			else
			{
				tmpStr.append('\n');
			}
		}
		QFile file(pathName);
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
		{
			return false;
		}
		else
		{
			QTextStream in(&file);
			in << tmpStr;
			file.close();
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}

#pragma region 删除N天前的文件
//删除N天前的文件
bool frmExportCsv::FindFileForDelete(const QString path, const int day)
{
	try
	{
		QDateTime now = QDateTime::currentDateTime();
		QDateTime dateTime1 = now.addDays(day);
		QDateTime dateTime2;
		QDir dir(path);
		QFileInfoList fileList = dir.entryInfoList();
		for (QFileInfo f : fileList)
		{
			if (f.baseName() == "")
			{
				continue;
			}
			dateTime2 = f.created();
			if (dateTime2 < dateTime1)
			{
				dir.remove(f.absoluteFilePath());
			}
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

//全局变量控制
int QConfig::nFormState = 0;
