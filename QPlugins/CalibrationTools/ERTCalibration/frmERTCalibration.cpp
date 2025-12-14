#include "frmERTCalibration.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QDesktopWidget>
#include <QPalette>
#include "BaseItem.h"
#include <QGraphicsOpacityEffect>

#define M_PI 3.14159265358979323846

frmERTCalibration::frmERTCalibration(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/ert_calib.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);	
	concentric_circle_item = new ConcentricCircleItem(220, 220, 100, 200);
	//设置表格列宽	
	ui.tableWidget->setColumnWidth(0, 107);
	ui.tableWidget->setColumnWidth(1, 107);
	ui.tableWidget->setColumnWidth(2, 107);
	ui.tableWidget->setColumnWidth(3, 107);
	//设置禁止编辑
	ui.tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
	ui.tableWidget->horizontalHeader()->setDisabled(true);
	ui.tableWidget->verticalHeader()->setDisabled(true);
	//设置表格列宽	
	ui.tableWidgetR->setColumnWidth(0, 145);
	ui.tableWidgetR->setColumnWidth(1, 145);
	//设置禁止编辑
	ui.tableWidgetR->setSelectionMode(QAbstractItemView::NoSelection);
	ui.tableWidgetR->horizontalHeader()->setDisabled(true);
	ui.tableWidgetR->verticalHeader()->setDisabled(true);
	//设置表格列宽	
	ui.tableWidgetR2->setColumnWidth(0, 145);
	ui.tableWidgetR2->setColumnWidth(1, 145);
	//设置禁止编辑
	ui.tableWidgetR2->setSelectionMode(QAbstractItemView::NoSelection);
	ui.tableWidgetR2->horizontalHeader()->setDisabled(true);
	ui.tableWidgetR2->verticalHeader()->setDisabled(true);
	//选项按钮
	btnGroupRadio = new QButtonGroup(this);
	btnGroupRadio->addButton(ui.radioNinePoints, 0);
	connect(ui.radioNinePoints, SIGNAL(toggled(bool)), this, SLOT(onRadioClick(bool)));
	btnGroupRadio->addButton(ui.radioRotateCenter, 1);
	connect(ui.radioRotateCenter, SIGNAL(toggled(bool)), this, SLOT(onRadioClick(bool)));
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
	QGraphicsOpacityEffect* e2 = new QGraphicsOpacityEffect(this);
	e2->setOpacity(0.5);
	ui.txtFindCirMsg->setGraphicsEffect(e2);
}

frmERTCalibration::~frmERTCalibration()
{
	view->deleteLater();
	concentric_circle_item->deleteLater();
	this->deleteLater();
}

void frmERTCalibration::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/ert_calib.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void frmERTCalibration::paintEvent(QPaintEvent* event)
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

void frmERTCalibration::onButtonCloseClicked()
{
	get_cir_center = false;
	view_points = false;
	this->close();
}

void frmERTCalibration::onRadioClick(bool state)
{
	switch (btnGroupRadio->checkedId())
	{
	case 0:
		ui.stackedWidget->setCurrentIndex(0);
		break;
	case 1:
		ui.stackedWidget->setCurrentIndex(1);
		break;
	}
}

void frmERTCalibration::on_comboCalibMethod_currentIndexChanged(int index)
{
	switch (index) {
	case 0:
		ui.stackedWidgetC->setCurrentIndex(0);		
		break;
	case 1:
		ui.stackedWidgetC->setCurrentIndex(1);
		break;
	}
}

int frmERTCalibration::Execute(const QString toolname)
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
	int result;
	if (get_cir_center == true)
	{
		result = RunFindCirclePro();
	}
	else
	{
		result = RunToolPro();
	}
	if (result == -1)
	{
		return -1;
	}
	return 0;
}

int frmERTCalibration::RunFindCirclePro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		Center = cv::Point2f(0, 0);
		Radius = 0;
		dstImage = cv::Mat();	
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
		xy.clear();
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
		int result = FindBorderPoints(dstImage, concentric_circle_item->ring_small_points, concentric_circle_item->ring_big_points, xy, ui.spinThreshold->value(), direction, in_out_circle, ui.spinSegment->value());
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
		return 0;
	}
	catch (...)
	{		
		return -1;
	}
}

int frmERTCalibration::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;		
		EstimateAffine.clear();
		PixelEquivalentX = 0;
		PixelEquivalentY = 0;
		RotateCenter = cv::Point2f(0, 0);
		DatumPoint1 = cv::Point2f(0, 0);
		DatumPoint2 = cv::Point2f(0, 0);
		DatumAngle = 0;
		dstImage = cv::Mat();	
		srcImage.copyTo(dstImage);
		//九点标定
		std::vector<double> m_xPixel(9);
		std::vector<double> m_yPixel(9);
		std::vector<double> m_xPos(9);
		std::vector<double> m_yPos(9);
		//图像坐标X
		m_xPixel[0] = ui.spinImageX1->value();
		m_xPixel[1] = ui.spinImageX2->value();
		m_xPixel[2] = ui.spinImageX3->value();
		m_xPixel[3] = ui.spinImageX4->value();
		m_xPixel[4] = ui.spinImageX5->value();
		m_xPixel[5] = ui.spinImageX6->value();
		m_xPixel[6] = ui.spinImageX7->value();
		m_xPixel[7] = ui.spinImageX8->value();
		m_xPixel[8] = ui.spinImageX9->value();
		//图像坐标Y
		m_yPixel[0] = ui.spinImageY1->value();
		m_yPixel[1] = ui.spinImageY2->value();
		m_yPixel[2] = ui.spinImageY3->value();
		m_yPixel[3] = ui.spinImageY4->value();
		m_yPixel[4] = ui.spinImageY5->value();
		m_yPixel[5] = ui.spinImageY6->value();
		m_yPixel[6] = ui.spinImageY7->value();
		m_yPixel[7] = ui.spinImageY8->value();
		m_yPixel[8] = ui.spinImageY9->value();
		//机械坐标X
		m_xPos[0] = ui.spinMachineX1->value();
		m_xPos[1] = ui.spinMachineX2->value();
		m_xPos[2] = ui.spinMachineX3->value();
		m_xPos[3] = ui.spinMachineX4->value();
		m_xPos[4] = ui.spinMachineX5->value();
		m_xPos[5] = ui.spinMachineX6->value();
		m_xPos[6] = ui.spinMachineX7->value();
		m_xPos[7] = ui.spinMachineX8->value();
		m_xPos[8] = ui.spinMachineX9->value();
		//机械坐标Y
		m_yPos[0] = ui.spinMachineY1->value();
		m_yPos[1] = ui.spinMachineY2->value();
		m_yPos[2] = ui.spinMachineY3->value();
		m_yPos[3] = ui.spinMachineY4->value();
		m_yPos[4] = ui.spinMachineY5->value();
		m_yPos[5] = ui.spinMachineY6->value();
		m_yPos[6] = ui.spinMachineY7->value();
		m_yPos[7] = ui.spinMachineY8->value();
		m_yPos[8] = ui.spinMachineY9->value();
		for (int i = 0; i < m_xPixel.size(); i++)
		{
			points_image[i].x = static_cast<float>(m_xPixel[i]);
			points_image[i].y = static_cast<float>(m_yPixel[i]);
			points_robot[i].x = static_cast<float>(m_xPos[i]);
			points_robot[i].y = static_cast<float>(m_yPos[i]);
		}
		bool state = NinePointsCalib(points_image, points_robot, A, B, C, D, E, F);
		if (state == false)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			return -1;
		}
		//N点标定参数
		EstimateAffine.push_back(A);
		EstimateAffine.push_back(B);
		EstimateAffine.push_back(C);
		EstimateAffine.push_back(D);
		EstimateAffine.push_back(E);
		EstimateAffine.push_back(F);
		//像素当量
		double p1p2_mac_x = std::abs(m_xPos[0] - m_xPos[1]);
		double p1p2_img_x = std::abs(m_xPixel[0] - m_xPixel[1]);
		double p1p2_equivalent = p1p2_mac_x / p1p2_img_x;
		double p3p4_mac_x = std::abs(m_xPos[2] - m_xPos[3]);
		double p3p4_img_x = std::abs(m_xPixel[2] - m_xPixel[3]);
		double p3p4_equivalent = p3p4_mac_x / p3p4_img_x;
		PixelEquivalentX = 0.5 * (p1p2_equivalent + p3p4_equivalent);
		double p2p3_mac_x = std::abs(m_xPos[1] - m_xPos[2]);
		double p2p3_img_x = std::abs(m_xPixel[1] - m_xPixel[2]);
		double p2p3_equivalent = p2p3_mac_x / p2p3_img_x;
		double p5p6_mac_x = std::abs(m_xPos[4] - m_xPos[5]);
		double p5p6_img_x = std::abs(m_xPixel[4] - m_xPixel[5]);
		double p5p6_equivalent = p5p6_mac_x / p5p6_img_x;
		PixelEquivalentY = 0.5 * (p2p3_equivalent + p5p6_equivalent);
		//基准点1
		if (ui.checkUseRotateC->isChecked() == true)
		{			
			switch (ui.comboCalibMethod->currentIndex()) {
			case 0:
				DatumPoint1.x = ui.spinImageRX1->value();
				DatumPoint1.y = ui.spinImageRY1->value();
				break;
			case 1:
				DatumPoint1.x = ui.spinImgRX1->value();
				DatumPoint1.y = ui.spinImgRY1->value();
				break;
			}						
		}
		else
		{			
			DatumPoint1.x = m_xPixel[0];
			DatumPoint1.y = m_yPixel[0];			
		}
		//计算机械标准点坐标
		MacDatumPoint1 = ImageC_To_MachineC(DatumPoint1, A, B, C, D, E, F);
		//基准点2
		if (ui.checkUseRotateC->isChecked() == true)
		{			
			DatumPoint2.x = ui.spinImgRX2->value();
			DatumPoint2.y = ui.spinImgRY2->value();		
		}
		else
		{
			DatumPoint2 = cv::Point2f(0, 0);;
		}
		//基准角度
		if (ui.checkUseRotateC->isChecked() == true)
		{
			DatumAngle = ui.spinStandardAngle->value();
		}
		else
		{
			DatumAngle = 0;
		}
		//旋转中心
		if (ui.checkUseRotateC->isChecked() == true)
		{			
			switch (ui.comboCalibMethod->currentIndex()) {
			case 0:
				state = CalcRotationCenter(ui.spinImageRX1->value(), ui.spinImageRY1->value(), ui.spinImageRX2->value(), ui.spinImageRY2->value(), ui.spinImageRX3->value(), ui.spinImageRY3->value(), rx0, ry0);
				RotateCenter.x = rx0;
				RotateCenter.y = ry0;				
				break;
			case 1:
				state = CalcRotationCenter(ui.spinImageRX1->value(), ui.spinImageRY1->value(), ui.spinImageRX2->value(), ui.spinImageRY2->value(), ui.spinRotateAngle->value(), rx0, ry0);
				RotateCenter.x = rx0;
				RotateCenter.y = ry0;				
				break;
			}
			if (state == false)
			{
				GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
				return -1;
			}
		}
		GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;	
		GetToolBase()->m_Tools[tool_index].PublicCalib.EstimateAffine = EstimateAffine;
		GetToolBase()->m_Tools[tool_index].PublicCalib.RotateCenter = RotateCenter;
		GetToolBase()->m_Tools[tool_index].PublicCalib.PixelEquivalentX = PixelEquivalentX;
		GetToolBase()->m_Tools[tool_index].PublicCalib.PixelEquivalentY = PixelEquivalentY;
		GetToolBase()->m_Tools[tool_index].PublicCalib.DatumPoint1 = DatumPoint1;
		GetToolBase()->m_Tools[tool_index].PublicCalib.DatumPoint2 = DatumPoint2;
		GetToolBase()->m_Tools[tool_index].PublicCalib.DatumAngle = DatumAngle;
		GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		return 0;
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmERTCalibration::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmERTCalibration::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmERTCalibration::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	get_cir_center = false;	
	Execute(GetToolName());
	ui.txtMsg->clear();
	for (int i = 0; i < EstimateAffine.size(); i++)
	{
		switch (i) {
		case 0:
			ui.txtMsg->append("-> N点标定参数A为：" + QString::number(EstimateAffine[i]));
			break;
		case 1:
			ui.txtMsg->append("-> N点标定参数B为：" + QString::number(EstimateAffine[i]));
			break;
		case 2:
			ui.txtMsg->append("-> N点标定参数C为：" + QString::number(EstimateAffine[i]));
			break;
		case 3:
			ui.txtMsg->append("-> N点标定参数D为：" + QString::number(EstimateAffine[i]));
			break;
		case 4:
			ui.txtMsg->append("-> N点标定参数E为：" + QString::number(EstimateAffine[i]));
			break;
		case 5:
			ui.txtMsg->append("-> N点标定参数F为：" + QString::number(EstimateAffine[i]));
			break;
		}
	}
	if (EstimateAffine.size() != 0)
	{
		if (ui.checkUseRotateC->isChecked() == true)
		{
			ui.txtMsg->append("-> 旋转中心为：" + QString::number(RotateCenter.x) + "," + QString::number(RotateCenter.y));
		}
		ui.txtMsg->append("-> 像素当量X为：" + QString::number(PixelEquivalentX));
		ui.txtMsg->append("-> 像素当量Y为：" + QString::number(PixelEquivalentY));
		ui.txtMsg->append("-> 基准点1对应的机械标准点坐标为：" + QString::number(MacDatumPoint1.x) + "," + QString::number(MacDatumPoint1.y));
		ui.txtMsg->append("-> 基准点1为：" + QString::number(DatumPoint1.x) + "," + QString::number(DatumPoint1.y));
		if (ui.checkUseRotateC->isChecked() == true)
		{
			ui.txtMsg->append("-> 基准点2为：" + QString::number(DatumPoint2.x) + "," + QString::number(DatumPoint2.y));
			ui.txtMsg->append("-> 基准角度为：" + QString::number(DatumAngle));
		}
	}	
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	ui.btnExecute->setEnabled(true);
}

void frmERTCalibration::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmERTCalibration::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmERTCalibration::on_btnAddROI_clicked()
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

void frmERTCalibration::on_btnDeleteROI_clicked()
{
	concentric_circle_item->concentric_circle_init_state = false;
	view->ClearObj();
}

void frmERTCalibration::on_btnGetCenter_clicked()
{
	get_cir_center = true;
	view_points = true;
	Execute(GetToolName());
	ui.txtFindCirMsg->clear();
	ui.txtFindCirMsg->append("-> 圆的中心坐标为：" + QString::number(Center.x) + "," + QString::number(Center.y));
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
	QApplication::processEvents();
}

void frmERTCalibration::on_spinSegment_valueChanged(int value)
{
	concentric_circle_item->segment_line_num = value;
}

//寻找边界点
//threshold_delta为阈值；direction的值为0时代表“从白到黑”寻找边界点，direction的值为1时代表“从黑到白”寻找边界点
//in_out_circle值为0时，从内往外扫描，值为1时，从外往内扫描；segment_num为分割线数量
int frmERTCalibration::FindBorderPoints(const cv::Mat& src_mat, const std::vector<QPointF> ring_small_points, const std::vector<QPointF> ring_big_points, std::vector<QPointF>& xy, const int threshold_delta, const int direction, const int in_out_circle, const int segment_num)
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
QPointF frmERTCalibration::FindCrosspointimprove(const QList<float>& lineTiDu, const QList<QPointF>& ijRecord, const int direction, const int threshold_delta)
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

Box frmERTCalibration::fitCircle(const std::vector<cv::Point2f>& points)
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

#pragma region 九点标定
//九点标定
bool frmERTCalibration::NinePointsCalib(const std::vector<cv::Point2f> points_image, const std::vector<cv::Point2f> points_robot, double& A, double& B, double& C, double& D, double& E, double& F)
{	
	try
	{
		cv::Mat warpMat = cv::estimateAffine2D(points_image, points_robot);
		if (!warpMat.empty())
		{
			A = warpMat.at<double>(0, 0);
			B = warpMat.at<double>(0, 1);
			C = warpMat.at<double>(0, 2);
			D = warpMat.at<double>(1, 0);
			E = warpMat.at<double>(1, 1);
			F = warpMat.at<double>(1, 2);
		}
		else
		{
			return false;
		}
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

#pragma region 图像坐标转换为世界坐标
//图像坐标转换为世界坐标
cv::Point2f frmERTCalibration::ImageC_To_MachineC(const cv::Point2f pPoint, const double A, const double B, const double C, const double D, const double E, const double F)
{
	try
	{
		cv::Point2f tPoint = cv::Point2f();
		tPoint.x = static_cast<float>(A * pPoint.x + B * pPoint.y + C);
		tPoint.y = static_cast<float>(D * pPoint.x + E * pPoint.y + F);
		return tPoint;
	}
	catch (...)
	{
		return cv::Point2f();
	}
}
#pragma endregion

#pragma region 计算旋转中心(旋转中心在相机视野范围内)
//计算旋转中心(旋转中心在相机视野范围内)
//(rx0,ry0)为旋转中心，(X1,Y1)、(X2,Y2)和(X3,Y3)为工件在视野中旋转的三个坐标
bool frmERTCalibration::CalcRotationCenter(const double X1, const double Y1, const double X2, const double Y2, const double X3, const double Y3, double& rx0, double& ry0)
{	
	try
	{
		double u = (pow((X1), 2) - pow((X2), 2) + pow((Y1), 2) - pow((Y2), 2)) / (2 * X1 - 2 * X2);
		double k1 = (Y1 - Y2) / (X1 - X2);
		double v = (pow((X1), 2) - pow((X3), 2) + pow((Y1), 2) - pow((Y3), 2)) / (2 * X1 - 2 * X3);
		double k2 = (Y1 - Y3) / (X1 - X3);
		rx0 = v - (u - v) * k2 / (k1 - k2);
		ry0 = (u - v) / (k1 - k2);
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

#pragma region 计算旋转中心(旋转中心在相机视野范围外)
//计算旋转中心(旋转中心在相机视野范围外)
//(rx0,ry0)为旋转中心，(X1,Y1)及(X2,Y2)为工件在视野中旋转角度angle的前后坐标
bool frmERTCalibration::CalcRotationCenter(const double X1, const double Y1, const double X2, const double Y2, const double angle, double& rx0, double& ry0)
{	
	try
	{
		double d = sqrt(pow((X2 - X1), 2) + pow((Y2 - Y1), 2));
		double R = (d / 2) / sin((M_PI / 180) * (angle / 2));
		double Xt = (1 - R / d) * X1 + (R / d) * X2;
		double Yt = (1 - R / d) * Y1 + (R / d) * Y2;
		rx0 = cos((M_PI / 180) * (90 - angle / 2)) * (Xt - X1) - sin((M_PI / 180) * (90 - angle / 2)) * (Yt - Y1) + X1;
		ry0 = cos((M_PI / 180) * (90 - angle / 2)) * (Yt - Y1) + sin((M_PI / 180) * (90 - angle / 2)) * (Xt - X1) + Y1;
		return true;
	}
	catch (...)
	{
		return false;
	}
}
#pragma endregion

QImage frmERTCalibration::Mat2QImage(const cv::Mat& mat)
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
