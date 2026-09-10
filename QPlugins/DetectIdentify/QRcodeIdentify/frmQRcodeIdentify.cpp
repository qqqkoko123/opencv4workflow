#include "frmQRcodeIdentify.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include "QGraphicsScenes.h"
#include <QGraphicsOpacityEffect>
#include <algorithm>
#include <cmath>
extern "C" {
#include <dmtx.h>
}
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
	this->setWindowIcon(QIcon(":/resource/qrcode.png"));
	//初始化标题栏
	initTitleBar();
	//图像显示
	view = new QGraphicsViews;
	ui.imageLayout->addWidget(view);
	//父类如果有样式表，背景色设置方法
	QGraphicsOpacityEffect* e = new QGraphicsOpacityEffect(this);
	e->setOpacity(0.5);
	ui.txtMsg->setGraphicsEffect(e);
}

frmQRcodeIdentify::~frmQRcodeIdentify()
{
	this->deleteLater();
}
void frmQRcodeIdentify::preprocessDmImage(const cv::Mat& src, cv::Mat& gray) const
{
	if (src.channels() == 3)
		cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
	else if (src.channels() == 4)
		cv::cvtColor(src, gray, cv::COLOR_BGRA2GRAY);
	else
		gray = src.clone();
}

cv::Rect frmQRcodeIdentify::detectContentRoi(const cv::Mat& gray) const
{
	cv::Rect full(0, 0, gray.cols, gray.rows);
	if (gray.empty())
		return full;

	cv::Mat blur, bin;
	cv::GaussianBlur(gray, blur, cv::Size(5, 5), 0);
	cv::threshold(blur, bin, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(bin, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	cv::Rect best;
	int bestArea = 0;
	for (const auto& c : contours)
	{
		cv::Rect r = cv::boundingRect(c);
		const int area = r.area();
		if (area > bestArea && area > gray.cols * gray.rows / 50)
		{
			bestArea = area;
			best = r;
		}
	}
	if (bestArea <= 0)
		return full;

	const int padX = std::max(8, best.width / 40);
	const int padY = std::max(8, best.height / 40);
	best.x = std::max(0, best.x - padX);
	best.y = std::max(0, best.y - padY);
	best.width = std::min(gray.cols - best.x, best.width + padX * 2);
	best.height = std::min(gray.rows - best.y, best.height + padY * 2);
	return best;
}

std::vector<DmCodeResult> frmQRcodeIdentify::decodeDmOnMat(const cv::Mat& gray, int imageUpscale) const
{
	std::vector<DmCodeResult> results;
	if (gray.empty() || gray.cols < 20 || gray.rows < 20)
		return results;

	const int upReq = (std::max)(1, imageUpscale);
	cv::Mat work;
	cv::resize(gray, work, cv::Size(), (double)upReq, (double)upReq, cv::INTER_LINEAR);

	// 硬性限制：libdmtx 输入不超过 dmMaxDecodeSide，否则单次要扫几分钟
	const int maxSide = std::max(work.cols, work.rows);
	if (maxSide > dmMaxDecodeSide)
	{
		const double shrink = (double)dmMaxDecodeSide / maxSide;
		cv::resize(work, work, cv::Size(), shrink, shrink, cv::INTER_AREA);
	}

	const double toGray = (double)gray.cols / work.cols;
	if (!work.isContinuous())
		work = work.clone();

	DmtxImage* img = dmtxImageCreate(work.data, work.cols, work.rows, DmtxPack8bppK);
	if (!img)
		return results;

	DmtxDecode* dec = dmtxDecodeCreate(img, 1);
	if (!dec)
	{
		dmtxImageDestroy(&img);
		return results;
	}

	const int workSide = std::max(work.cols, work.rows);
	int scanGap = 2;
	if (workSide > 900)
		scanGap = 3;
	dmtxDecodeSetProp(dec, DmtxPropScanGap, scanGap);

	int foundRegions = 0;
	DmtxRegion* reg = nullptr;
	while ((reg = dmtxRegionFindNext(dec, nullptr)) != nullptr)
	{
		DmtxMessage* msg = dmtxDecodeMatrixRegion(dec, reg, DmtxUndefined);
		if (msg && msg->output)
		{
			const char* text = reinterpret_cast<char*>(msg->output);
			size_t len = (msg->outputIdx > 0) ? static_cast<size_t>(msg->outputIdx) : std::strlen(text);
			if (len > 0)
			{
				DmCodeResult res;
				res.content = std::string(text, len);
				int min_x = std::min({ reg->topLoc.X, reg->rightLoc.X, reg->bottomLoc.X, reg->leftLoc.X });
				int max_x = std::max({ reg->topLoc.X, reg->rightLoc.X, reg->bottomLoc.X, reg->leftLoc.X });
				int min_y = std::min({ reg->topLoc.Y, reg->rightLoc.Y, reg->bottomLoc.Y, reg->leftLoc.Y });
				int max_y = std::max({ reg->topLoc.Y, reg->rightLoc.Y, reg->bottomLoc.Y, reg->leftLoc.Y });
				res.bbox = cv::Rect(
					(int)(min_x * toGray), (int)(min_y * toGray),
					std::max(1, (int)((max_x - min_x) * toGray)),
					std::max(1, (int)((max_y - min_y) * toGray)));
				results.push_back(res);
				++foundRegions;
			}
			dmtxMessageDestroy(&msg);
		}
		dmtxRegionDestroy(&reg);

		if (foundRegions >= dmMaxRegionsPerPass)
			break;
	}

	dmtxDecodeDestroy(&dec);
	dmtxImageDestroy(&img);
	return results;
}

bool frmQRcodeIdentify::appendDmResult(std::vector<DmCodeResult>& results, const DmCodeResult& item, int offsetX, int offsetY) const
{
	if (item.content.empty())
		return false;

	DmCodeResult r = item;
	r.bbox.x += offsetX;
	r.bbox.y += offsetY;

	for (const auto& exist : results)
	{
		if (exist.content == r.content)
			return false;
		cv::Point c1(r.bbox.x + r.bbox.width / 2, r.bbox.y + r.bbox.height / 2);
		cv::Point c2(exist.bbox.x + exist.bbox.width / 2, exist.bbox.y + exist.bbox.height / 2);
		int dist2 = (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
		int minSide = std::min(r.bbox.width + exist.bbox.width, r.bbox.height + exist.bbox.height);
		if (minSide > 0 && dist2 < minSide * minSide)
			return false;
	}
	results.push_back(r);
	return true;
}

void frmQRcodeIdentify::sortDmResultsByLayout(std::vector<DmCodeResult>& results) const
{
	std::sort(results.begin(), results.end(), [](const DmCodeResult& a, const DmCodeResult& b)
	{
		if (std::abs(a.bbox.y - b.bbox.y) > 40)
			return a.bbox.y < b.bbox.y;
		return a.bbox.x < b.bbox.x;
	});
}

int frmQRcodeIdentify::tryDecodeDmCellPatch(const cv::Mat& normPatch, double mapBackScale, int offsetX, int offsetY, std::vector<DmCodeResult>& results) const
{
	if (normPatch.empty() || mapBackScale <= 0)
		return 0;

	auto mapAndAppend = [&](const std::vector<DmCodeResult>& part) -> int
	{
		int n = 0;
		for (DmCodeResult one : part)
		{
			one.bbox.x = (int)(one.bbox.x / mapBackScale);
			one.bbox.y = (int)(one.bbox.y / mapBackScale);
			one.bbox.width = std::max(1, (int)(one.bbox.width / mapBackScale));
			one.bbox.height = std::max(1, (int)(one.bbox.height / mapBackScale));
			if (appendDmResult(results, one, offsetX, offsetY))
				++n;
		}
		return n;
	};

	if (mapAndAppend(decodeDmOnMat(normPatch, 1)) > 0)
		return 1;

	cv::Mat enhanced;
	cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE(2.5, cv::Size(8, 8));
	clahe->apply(normPatch, enhanced);
	if (mapAndAppend(decodeDmOnMat(enhanced, 1)) > 0)
		return 1;

	const int block = (std::max)(15, ((std::min)(normPatch.cols, normPatch.rows) / 16) | 1);
	cv::Mat bin;
	cv::adaptiveThreshold(enhanced, bin, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, block, 5);
	if (mapAndAppend(decodeDmOnMat(bin, 1)) > 0)
		return 1;
	cv::bitwise_not(bin, bin);
	if (mapAndAppend(decodeDmOnMat(bin, 1)) > 0)
		return 1;

	if (mapAndAppend(decodeDmOnMat(normPatch, 2)) > 0)
		return 1;

	return 0;
}

int frmQRcodeIdentify::decodeDmTrayGrid(const cv::Mat& gray, int rows, int cols, std::vector<DmCodeResult>& results) const
{
	if (rows <= 0 || cols <= 0 || gray.empty())
		return 0;

	int added = 0;
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
		{
			int x0 = c * gray.cols / cols;
			int x1 = (c + 1) * gray.cols / cols;
			int y0 = r * gray.rows / rows;
			int y1 = (r + 1) * gray.rows / rows;
			const int padX = (x1 - x0) / 5;
			const int padY = (y1 - y0) / 5;
			x0 = std::max(0, x0 - padX);
			y0 = std::max(0, y0 - padY);
			x1 = std::min(gray.cols, x1 + padX);
			y1 = std::min(gray.rows, y1 + padY);
			if (x1 - x0 < 32 || y1 - y0 < 32)
				continue;

			cv::Mat patch = gray(cv::Rect(x0, y0, x1 - x0, y1 - y0)).clone();
			const int ms = std::max(patch.cols, patch.rows);
			const double normScale = (double)dmCellNormSide / (double)ms;
			cv::Mat norm;
			cv::resize(patch, norm, cv::Size(), normScale, normScale, cv::INTER_CUBIC);

			added += tryDecodeDmCellPatch(norm, normScale, x0, y0, results);
			if ((int)results.size() >= expectedDmCount)
				return added;
		}
	}
	return added;
}

void frmQRcodeIdentify::decodeDmFallbackLimited(const cv::Mat& gray, std::vector<DmCodeResult>& results) const
{
	if ((int)results.size() >= expectedDmCount)
		return;

	const int maxSide = 1100;
	const int side = std::max(gray.cols, gray.rows);
	double scale = 1.0;
	cv::Mat small = gray;
	if (side > maxSide)
	{
		scale = (double)maxSide / side;
		cv::resize(gray, small, cv::Size(), scale, scale, cv::INTER_AREA);
	}

	std::vector<DmCodeResult> part = decodeDmOnMat(small, 2);
	const double inv = 1.0 / scale;
	for (DmCodeResult one : part)
	{
		one.bbox.x = (int)(one.bbox.x * inv);
		one.bbox.y = (int)(one.bbox.y * inv);
		one.bbox.width = std::max(1, (int)(one.bbox.width * inv));
		one.bbox.height = std::max(1, (int)(one.bbox.height * inv));
		appendDmResult(results, one, 0, 0);
	}
}

std::vector<DmCodeResult> frmQRcodeIdentify::decode_all_dm_codes(const cv::Mat& src)
{
	std::vector<DmCodeResult> results;
	cv::Mat gray;
	preprocessDmImage(src, gray);
	if (gray.empty())
		return results;

	// 只在有效内容区（托盘）上分格，避免黑边/背景把格子切歪
	const cv::Rect content = detectContentRoi(gray);
	cv::Mat roiGray = gray(content);

	decodeDmTrayGrid(roiGray, 5, 2, results);
	if ((int)results.size() < expectedDmCount)
		decodeDmTrayGrid(roiGray, 2, 4, results);
	if ((int)results.size() < 4)
		decodeDmTrayGrid(roiGray, 2, 5, results);

	// 坐标从 content 局部映射回全图
	if (content.x != 0 || content.y != 0)
	{
		for (auto& item : results)
		{
			item.bbox.x += content.x;
			item.bbox.y += content.y;
		}
	}

	if ((int)results.size() < 3)
		decodeDmFallbackLimited(gray, results);

	sortDmResultsByLayout(results);
	return results;
}
void frmQRcodeIdentify::initTitleBar()
{
	m_titleBar = new MyTitleBar(this);
	m_titleBar->move(0, 0);
	connect(m_titleBar, SIGNAL(signalButtonCloseClicked()), this, SLOT(onButtonCloseClicked()));
	m_titleBar->setStyleSheet("background-color: rgba(178, 178, 178,0);color:white;font-size:16px");
	m_titleBar->setTitleIcon(":/resource/qrcode.png");
	m_titleBar->setTitleContent(toolTitleName);
	m_titleBar->setButtonType(ONLY_CLOSE_BUTTON);
	m_titleBar->setTitleWidth(this->width());
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
		switch (ui.comboMode->currentIndex()) {
		case 0:
			result = RunToolPro();
			break;
		case 1:
			result = RunToolProDM();
			break;
		}
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
		double mul_scale = ui.spinMulValue->value();
		dstImage = dstImage.mul(dstImage, mul_scale);
		return 0;
	}
	catch (...)
	{
		return -1;
	}
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
		//解码
		for (int m = 0; m < 3; m++)
		{			
			cv::Mat gray;
			double n;
			switch (m) {
			case 0:
				n = 1.0;
				break;
			case 1:
				n = 2.0;
				break;
			case 2:
				n = 3.0;
				break;		
			}			
			cv::resize(dstImage, gray, cv::Size((int)(dstImage.cols * n), (int)(dstImage.rows * n)));
			double mul_scale = ui.spinMulValue->value();
			gray = gray.mul(gray, mul_scale);
			strDecoded = detector->detectAndDecode(gray, vPoints);
			if (strDecoded.size() != 0)
			{
				break;
			}			
		}
		if (strDecoded.size() == 0)
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		}
		else
		{	
			if (dstImage.channels() == 1)
			{
				cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
			}
			else if (dstImage.channels() == 4)
			{
				cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);
			}			
			double show_thickness = (dstImage.rows > dstImage.cols) ? (2.813 * dstImage.rows) / dstImage.cols :
				(2.813 * dstImage.cols) / dstImage.rows;
			double contour_thickness = show_thickness * 0.4;
			for (int i = 0; i < strDecoded.size(); i++)
			{
				cv::Point pt1 = cv::Point((int)vPoints[i].at<float>(0, 0), (int)vPoints[i].at<float>(0, 1));
				cv::Point pt2 = cv::Point((int)vPoints[i].at<float>(1, 0), (int)vPoints[i].at<float>(1, 1));
				cv::Point pt3 = cv::Point((int)vPoints[i].at<float>(2, 0), (int)vPoints[i].at<float>(2, 1));
				cv::Point pt4 = cv::Point((int)vPoints[i].at<float>(3, 0), (int)vPoints[i].at<float>(3, 1));		
				cv::line(dstImage, pt1, pt2, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
				cv::line(dstImage, pt2, pt3, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
				cv::line(dstImage, pt3, pt4, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
				cv::line(dstImage, pt4, pt1, cv::Scalar(0, 255, 0), cvRound(contour_thickness));
				Code.push_back(QString::fromStdString(strDecoded[i]));
			}
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			GetToolBase()->m_Tools[tool_index].PublicDetect.Code = Code;
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

int frmQRcodeIdentify::RunToolProDM()
{
	try
	{
		srcImage = GetToolBase()->m_Tools[image_index].PublicImage.OutputImage;
		vPoints.clear();
		strDecoded.clear();
		Code.clear();
		dstImage = cv::Mat();
		srcImage.copyTo(dstImage);
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
		//if (strDecoded.size() == 0) {
		//	GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
		//	GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		//	return -1;
		//}
		//else {
		//	GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
		//	GetToolBase()->m_Tools[tool_index].PublicDetect.Code = Code;
		//	GetToolBase()->m_Tools[tool_index].PublicResult.State = true;
		//	return 0;
		//}
		std::vector<DmCodeResult> results = decode_all_dm_codes(srcImage);

		strDecoded.clear();
		Code.clear();
		for (size_t i = 0; i < results.size(); ++i)
		{
			strDecoded.push_back(results[i].content);
			Code.push_back(QString::fromStdString(results[i].content));
		}

		if (dstImage.channels() == 1)
			cv::cvtColor(dstImage, dstImage, cv::COLOR_GRAY2BGR);
		else if (dstImage.channels() == 4)
			cv::cvtColor(dstImage, dstImage, cv::COLOR_RGBA2BGR);

		for (size_t i = 0; i < results.size(); ++i)
		{
			const DmCodeResult& res = results[i];
			cv::rectangle(dstImage, res.bbox, cv::Scalar(0, 255, 0), 2);
			QString label = QString("[%1] %2").arg(i + 1).arg(QString::fromStdString(res.content));
			int textY = std::max(15, res.bbox.y - 5);
			std::string labelUtf8 = label.toStdString();
			cv::putText(dstImage, labelUtf8, cv::Point(res.bbox.x, textY),
				cv::FONT_HERSHEY_SIMPLEX, 0.55, cv::Scalar(0, 0, 255), 2);
		}

		if (results.size() > 0)
		{
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			GetToolBase()->m_Tools[tool_index].PublicDetect.Code = Code;
			GetToolBase()->m_Tools[tool_index].PublicDetect.Quantity = static_cast<int>(results.size());
			GetToolBase()->m_Tools[tool_index].PublicResult.State = (results.size() > 0);
			return (results.size() > 0) ? 0 : -1;
		}
		else
		{
			GetToolBase()->m_Tools[tool_index].PublicResult.State = false;
			GetToolBase()->m_Tools[tool_index].PublicImage.OutputImage = dstImage;
			return -1;
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
	ui.txtMsg->clear();
	if (ui.comboMode->currentIndex() == 1)
	{
		ui.txtMsg->append(QString::fromUtf8("-> 识别到 %1 个 DM 码（目标 %2 个）")
			.arg(strDecoded.size()).arg(expectedDmCount));
		for (int i = 0; i < (int)strDecoded.size(); ++i)
			ui.txtMsg->append(QString("[%1] %2").arg(i + 1).arg(QString::fromStdString(strDecoded[i])));
	}
	else
	{
		for (int i = 0; i < (int)strDecoded.size(); i++)
		{
			if (i == 0)
				ui.txtMsg->append("-> 二维码内容为：");
			ui.txtMsg->append(QString::fromStdString(strDecoded[i]));
		}
	}
	
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
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
	QImage img(Mat2QImage(dstImage));
	view->DispImage(img);
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

//全局变量控制
int QConfig::nFormState = 0;
