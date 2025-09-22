#include "frmQRcodeIdentify.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include "QGraphicsScenes.h"
#include <QGraphicsOpacityEffect>
#include <qrencode.h>
extern "C" {
#include <dmtx.h>
}
#include <QPrinterInfo>
frmQRcodeIdentify::frmQRcodeIdentify(QString toolName, QToolBase* toolBase, QWidget* parent)
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
	this->setWindowIcon(QIcon(":/resource/print.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	//ui.txtMsg->setGraphicsEffect(e);
}

frmQRcodeIdentify::~frmQRcodeIdentify()
{
	this->deleteLater();
}

void frmQRcodeIdentify::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/print.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
	onInit();
}

void frmQRcodeIdentify::paintEvent(QPaintEvent* event)
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

void frmQRcodeIdentify::onButtonCloseClicked()
{
	view_rect = false;
	this->close();
}
void frmQRcodeIdentify::onInit()
{
	ui.comboMode->clear();
	ui.comboMode->addItem(QString::null);
	ui.comboMode->addItems(GetPrinterList());
}
int frmQRcodeIdentify::Execute(const QString toolname)
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
	if (view_rect == true)
	{
		result = RunTestImage();
	}
	else
	{
		/*switch (ui.comboMode->currentIndex()) {
		case 0:
			result = RunToolPro();
			break;
		case 1:
			result = RunToolProDM();
			break;
		}*/
		RunToolPro();
	}
	if (result == -1)
	{
		return -1;
	}
	return 0;
}

int frmQRcodeIdentify::RunTestImage()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		//double mul_scale = ui.spinMulValue->value();
		//dstImage = dstImage.mul(dstImage, mul_scale);
		return 0;
	}
	catch (...)
	{
		return -1;
	}
}
void frmQRcodeIdentify::on_btnTestImage_2_clicked() 
{
	on_btnExecute_clicked();
}
int frmQRcodeIdentify::RunToolPro()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		vPoints.clear();
		strDecoded.clear();
		Code.clear();
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		if (dstImage.channels() == 3)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_BGR2GRAY);
		}
		else if (dstImage.channels() == 4)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2GRAY);
		}			
		////解码
		//for (int m = 0; m < 3; m++)
		//{			
		//	cv::Mat gray;
		//	double n;
		//	switch (m) {
		//	case 0:
		//		n = 1.0;
		//		break;
		//	case 1:
		//		n = 2.0;
		//		break;
		//	case 2:
		//		n = 3.0;
		//		break;		
		//	}			
		//	cv::resize(dstImage, gray, cv::Size((int)(dstImage.cols * n), (int)(dstImage.rows * n)));
		//	double mul_scale = ui.spinMulValue->value();
		//	gray = gray.mul(gray, mul_scale);
		//	strDecoded = detector->detectAndDecode(gray, vPoints);
		//	if (strDecoded.size() != 0)
		//	{
		//		break;
		//	}			
		//}
		//if (strDecoded.size() == 0)
		//{
		//	GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		//	GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		//}
		//else
		//{	
		//	if (dstImage.channels() == 1)
		//	{
		//		cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
		//	}
		//	else if (dstImage.channels() == 4)
		//	{
		//		cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
		//	}			
		//	double show_thickness = (dstImage.rows > dstImage.cols) ? (2.813 * dstImage.rows) / dstImage.cols :
		//		(2.813 * dstImage.cols) / dstImage.rows;
		//	double contour_thickness = show_thickness * 0.4;
		//	for (int i = 0; i < strDecoded.size(); i++)
		//	{
		//		cv::Point pt1 = cv::Point((int)vPoints[i].at<float>(0, 0), (int)vPoints[i].at<float>(0, 1));
		//		cv::Point pt2 = cv::Point((int)vPoints[i].at<float>(1, 0), (int)vPoints[i].at<float>(1, 1));
		//		cv::Point pt3 = cv::Point((int)vPoints[i].at<float>(2, 0), (int)vPoints[i].at<float>(2, 1));
		//		cv::Point pt4 = cv::Point((int)vPoints[i].at<float>(3, 0), (int)vPoints[i].at<float>(3, 1));		
		//		cv::line(dstImage, pt1, pt2, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
		//		cv::line(dstImage, pt2, pt3, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
		//		cv::line(dstImage, pt3, pt4, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
		//		cv::line(dstImage, pt4, pt1, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
		//		Code.push_back(QString::fromStdString(strDecoded[i]));
		//	}
		//	GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		//	GetToolBase()->m_Tools[tool_index].PublicDetect.Code = Code;
		//	GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		//}	
		// 生成 QRCode (200x200)
		//dstImage = generateQRCode(ui.txtLinkImage->text().toStdString(), ui.spinBox->value(), ui.spinBox_2->value());
		/*strDecoded.push_back(ui.txtLinkImage->text().toStdString());
		Code.push_back(QString::fromStdString(ui.txtLinkImage->text().toStdString()));
		if (strDecoded.size() == 0) {
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			return -1;
		}
		else {
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			GetToolBase()->m_Tools[tool_index].PublicDetect.Code = Code;
			GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
			return 0;
		}*/
		if (dstImage.empty()) {
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputViewImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputViewImage;
			GetToolBase()->m_Tools[tool_index].PublicResult.State = printToSpecificPrinter(GetToolBase()->m_Tools[image_index].PublicImage.OutputViewImage, ui.comboMode->currentText());
		}
		else {
            GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			GetToolBase()->m_Tools[tool_index].PublicResult.State = PrintImageToPrinter(GetToolBase()->m_Tools[image_index].PublicImage.OutputImage, ui.comboMode->currentText());
		}
		if (GetToolBase()->m_Tools[tool_index].PublicResult.State) {
			return 0;
		}
		else {
			return -1;
		}
		
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmQRcodeIdentify::RunToolProDM()
{
	try
	{
		//DmtxRegion* reg;
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		vPoints.clear();
		strDecoded.clear();
		Code.clear();
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
		if (dstImage.channels() == 3)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_BGR2GRAY);
		}
		else if (dstImage.channels() == 4)
		{
			cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2GRAY);
		}
		//DmtxImage* image;
		//image = dmtxImageCreate(dstImage.data, dstImage.cols, dstImage.rows, DmtxPack8bppK);//注意图片类型
		//DmtxDecode* dec = dmtxDecodeCreate(image, 1);//解码
		//// 设置关键参数以提升速度
		////dmtxDecodeSetProp(dec, DmtxPropScanGap, 5);      // 增加扫描间隔 (默认1)
		////dmtxDecodeSetProp(dec, DmtxPropEdgeMin, 100);    // 提高最小边缘阈值
		////dmtxDecodeSetProp(dec, DmtxPropEdgeMax, 255);    // 降低最大边缘阈值
		////dmtxDecodeSetProp(dec, DmtxPropSquareDevn, 0.5); // 增加正方形偏差容忍度 (默认0.2)
		////dmtxDecodeSetProp(dec, DmtxPropSymbolSize, DmtxSymbolSquareAuto); // 仅识别方形符号

		//// 存储识别结果
		////std::vector<std::string> decodedMessages = std::vector<std::string>();
		//double show_thickness = (dstImage.rows > dstImage.cols) ? (2.813 * dstImage.rows) / dstImage.cols :
		//	(2.813 * dstImage.cols) / dstImage.rows;
		//double contour_thickness = show_thickness * 0.4;
		//DmtxTime* timeout = new DmtxTime();
		//timeout->sec = 100; // 设置超时时间(毫秒)
		//// 循环检测所有DM码
		//while ((reg = dmtxRegionFindNext(dec, NULL)) != NULL) {
		//	DmtxMessage* msg = dmtxDecodeMatrixRegion(dec, reg, 1);//解码信息
		//	if (msg != NULL)
		//	{
		//		// 输出结果
		//		cv::Point pt1 = cv::Point(reg->topLoc.X, reg->topLoc.Y + 20);
		//		cv::Point pt2 = cv::Point(reg->leftLoc.X - 20, reg->leftLoc.Y);
		//		cv::Point pt3 = cv::Point(reg->bottomLoc.X, reg->bottomLoc.Y - 20);
		//		cv::Point pt4 = cv::Point(reg->rightLoc.X + 20, reg->rightLoc.Y);
		//		/*cv::line(dstImage, pt1, pt2, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
		//		cv::line(dstImage, pt2, pt3, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
		//		cv::line(dstImage, pt3, pt4, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
		//		cv::line(dstImage, pt4, pt1, cv::Scalar(0, 255, 0), cvRound(contour_thickness));*/

		//		//此处绘制矩形框，需要改进，没能和检测到的二维码矩形吻合？
		//		cv::rectangle(dstImage,cv::Rect(pt2.x,pt1.y,pt4.x-pt2.x,pt1.y-pt3.y), cv::Scalar(0, 255, 0), cvRound(contour_thickness));

		//		Code.push_back(QString::fromStdString(std::string((char*)msg->output)));
		//		 // 将解码内容转为字符串
		//		strDecoded.push_back(std::string((char*)msg->output));
		//		dmtxMessageDestroy(&msg);
		//	}
		//	dmtxRegionDestroy(&reg);
		//}
		//
		//
		//dmtxDecodeDestroy(&dec);
		//dmtxImageDestroy(&image);
		//
		//cin.get();

		// 生成 DataMatrix (200x200)
		//dstImage = generateDataMatrix(ui.txtLinkImage->text().toStdString(), ui.spinBox->value(), ui.spinBox_2->value());
		strDecoded.push_back(ui.txtLinkImage->text().toStdString());
		Code.push_back(QString::fromStdString(ui.txtLinkImage->text().toStdString()));
		if (strDecoded.size() == 0) {
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			return -1;
		}
		else {
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			GetToolBase()->m_Tools[tool_index].PublicDetect.Code = Code;
			GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
			return 0;
		}
		
	}
	catch (...)
	{
		GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		return -1;
	}
}

int frmQRcodeIdentify::ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link)
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

int frmQRcodeIdentify::ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link)
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

void frmQRcodeIdentify::on_btnExecute_clicked()
{
	ui.btnExecute->setEnabled(false);
	QApplication::processEvents();
	view_rect = false;
	switch (ui.comboMode->currentIndex()) {
	case 0:
		bool state = InitDetector();
		if (state == false)
		{
			QMessageBox msgBox(QMessageBox::Icon::NoIcon, "错误", "初始化二维码参数异常！");
			msgBox.setWindowIcon(QIcon(":/resource/error.png"));
			msgBox.exec();
			return;
		}
		break;
	}
	Execute(GetToolName());
	/*ui.txtMsg->clear();
	for (int i = 0; i < strDecoded.size(); i++)
	{
		if (i == 0)
		{
			ui.txtMsg->append("-> 二维码内容为：");
		}
		ui.txtMsg->append(QString::fromStdString(strDecoded[i]));
	}*/
	if (!dstImage.empty()) {
		QImage img(Mat2QImage(dstImage));
		view->DispImage(img);
	}
	else {
		view->DispImage(GetToolBase()->m_Tools[tool_index].PublicImage.OutputViewImage);
	}
	
	
	ui.btnExecute->setEnabled(true);
}

void frmQRcodeIdentify::on_btnLinkImage_clicked()
{
	QConfig::nFormState = 1;
}

void frmQRcodeIdentify::on_btnDelLinkImage_clicked()
{
	ui.txtLinkImage->clear();
}

void frmQRcodeIdentify::on_btnTestImage_clicked()
{
	view_rect = true;
	Execute(GetToolName());
	if (!dstImage.empty()) {
		QImage img(Mat2QImage(dstImage));
		view->DispImage(img);
	}
	else {
		view->DispImage(GetToolBase()->m_Tools[tool_index].PublicImage.OutputViewImage);
	}
	QApplication::processEvents();
}

bool frmQRcodeIdentify::InitDetector()
{
	try {
		QString detect_prototxt = QCoreApplication::applicationDirPath() + "/Parameters/Code/detect.prototxt";
		QString detect_caffemodel = QCoreApplication::applicationDirPath() + "/Parameters/Code/detect.caffemodel";
		QString sr_prototxt = QCoreApplication::applicationDirPath() + "/Parameters/Code/sr.prototxt";
		QString sr_caffemodel = QCoreApplication::applicationDirPath() + "/Parameters/Code/sr.caffemodel";
		detector = cv::makePtr<cv::wechat_qrcode::WeChatQRCode>(
			detect_prototxt.toStdString(),
			detect_caffemodel.toStdString(),
			sr_prototxt.toStdString(),
			sr_caffemodel.toStdString());
		return true;
	}
	catch (...)
	{
		return false;
	}
}
bool frmQRcodeIdentify::InitDetectorDM()
{
	try {
		return true;
	}
	catch (...)
	{
		return false;
	}
}
QImage frmQRcodeIdentify::Mat2QImage(const cv::Mat& mat)
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
// 生成 QR 码并返回 cv::Mat
cv::Mat frmQRcodeIdentify::generateQRCode(const std::string& text, int width, int height) {
	QRcode* qr = QRcode_encodeString(text.c_str(), 0, QR_ECLEVEL_L, QR_MODE_8, 1);
	if (!qr) {
		throw std::runtime_error("Failed to generate QR code");
	}

	// 计算缩放因子
	int margin = 2;
	int qr_size = qr->width + 2 * margin;
	int scale = width / qr_size;
	if (scale < 1) scale = 1;

	cv::Mat image = cv::Mat::ones(qr_size * scale, qr_size * scale, CV_8UC1) * 255;

	// 绘制二维码
	for (int y = 0; y < qr->width; ++y) {
		for (int x = 0; x < qr->width; ++x) {
			if (qr->data[y * qr->width + x] & 1) {
				cv::rectangle(image,
					cv::Point((x + margin) * scale, (y + margin) * scale),
					cv::Point((x + margin + 1) * scale - 1, (y + margin + 1) * scale - 1),
					cv::Scalar(0), cv::FILLED);
			}
		}
	}

	QRcode_free(qr);
	return image;
}

// 生成 DataMatrix 并返回 cv::Mat
cv::Mat frmQRcodeIdentify::generateDataMatrix(const std::string& text, int width, int height) {
	DmtxEncode* enc = dmtxEncodeCreate();
	if (!enc) {
		throw std::runtime_error("Failed to create DataMatrix encoder");
	}

	dmtxEncodeDataMatrix(enc, text.size(), (unsigned char*)text.c_str());

	// 创建 OpenCV Mat
	cv::Mat image(enc->image->height, enc->image->width, CV_8UC3, enc->image->pxl);

	// 转换为灰度图
	cv::cvtColor(image, image, cv::COLOR_RGB2GRAY);

	// 调整大小
	cv::resize(image, image, cv::Size(width, height), 0, 0, cv::INTER_NEAREST);

	dmtxEncodeDestroy(&enc);
	return image;
}
bool frmQRcodeIdentify::printToSpecificPrinter(const QImage& image, const QString& printerName) {
	QPrinter printer(QPrinter::HighResolution);

	// 设置特定打印机
	printer.setPrinterName(printerName);

	// 检查打印机是否有效
	if (printer.printerName().isEmpty()) {
		qDebug() << "指定的打印机不可用:" << printerName;
		return false;
	}

	QPainter painter;
	if (!painter.begin(&printer)) {
		//return false;
	}

	QRectF pageRect = printer.pageRect(QPrinter::DevicePixel);

	double scale = qMin(
		static_cast<double>(pageRect.width()) / image.width(),
		static_cast<double>(pageRect.height()) / image.height()
	) * 0.95;

	int scaledWidth = static_cast<int>(image.width() * scale);
	int scaledHeight = static_cast<int>(image.height() * scale);
	int posX = (pageRect.width() - scaledWidth) / 2;
	int posY = (pageRect.height() - scaledHeight) / 2;

	painter.drawImage(QRect(posX, posY, scaledWidth, scaledHeight), image);

	painter.end();
	return true;
}
// 获取系统中所有打印机的名称（返回 QStringList）
QStringList frmQRcodeIdentify::GetPrinterList() {
	QStringList printers;

	// 使用 Qt 的打印机信息类获取打印机列表
	QList<QPrinterInfo> availablePrinters = QPrinterInfo::availablePrinters();

	for (const QPrinterInfo& printerInfo : availablePrinters) {
		printers.append(printerInfo.printerName());
	}

	// 添加默认打印机（如果不在列表中）
	QPrinterInfo defaultPrinter = QPrinterInfo::defaultPrinter();
	if (!defaultPrinter.isNull() && !printers.contains(defaultPrinter.printerName())) {
		printers.prepend(defaultPrinter.printerName());
	}

	return printers;
}
// 打印 cv::Mat 到指定打印机
bool frmQRcodeIdentify::PrintImageToPrinter(const cv::Mat& image, const QString& printerName) {
	// 创建 QPrinter 对象
	QPrinter printer(QPrinter::HighResolution);
	printer.setPrinterName(printerName);

	// 设置打印方向
	printer.setOrientation(QPrinter::Portrait);

	// 设置页面边距（毫米）
	printer.setPageMargins(10, 10, 10, 10, QPrinter::Millimeter);

	// 创建 QPainter 对象
	QPainter painter;
	if (!painter.begin(&printer)) {
		//qDebug() << "无法在打印机上开始绘制";
		//return false;
	}

	// 将 cv::Mat 转换为 QImage
	QImage qImage = Mat2QImage(image);
	// 计算缩放比例以保持宽高比
	QRectF pageRect = printer.pageRect(QPrinter::DevicePixel);
	QRect imageRect = qImage.rect();

	double scaleX = static_cast<double>(pageRect.width()) / imageRect.width();
	double scaleY = static_cast<double>(pageRect.height()) / imageRect.height();
	double scale = qMin(scaleX, scaleY) * 0.9; // 留出边距

	int scaledWidth = static_cast<int>(imageRect.width() * scale);
	int scaledHeight = static_cast<int>(imageRect.height() * scale);

	// 计算居中位置
	int posX = (pageRect.width() - scaledWidth) / 2;
	int posY = (pageRect.height() - scaledHeight) / 2;

	// 绘制图像
	painter.drawImage(QRect(posX, posY, scaledWidth, scaledHeight), qImage);

	// 结束绘制
	painter.end();

	return true;
}
//全局变量控制
int QConfig::nFormState = 0;
