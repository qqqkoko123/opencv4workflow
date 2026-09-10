#pragma once

#include <QDialog>
#include "ui_frmQRcodeIdentify.h"
#include <opencv2\opencv.hpp>
#include <opencv2\wechat_qrcode.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"
struct DmCodeResult {
	std::string content;
	cv::Rect bbox; // DM 码在原图中的 bounding box
};
class frmQRcodeIdentify : public Toolnterface
{
	Q_OBJECT

public:
	frmQRcodeIdentify(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmQRcodeIdentify();

	std::vector<DmCodeResult> decode_all_dm_codes(const cv::Mat& src);

private:
	void preprocessDmImage(const cv::Mat& src, cv::Mat& gray) const;
	cv::Rect detectContentRoi(const cv::Mat& gray) const;
	// imageUpscale: OpenCV 放大倍数；坐标会映射回原图。libdmtx 固定用 shrinkScale=1
	std::vector<DmCodeResult> decodeDmOnMat(const cv::Mat& gray, int imageUpscale = 1) const;
	bool appendDmResult(std::vector<DmCodeResult>& results, const DmCodeResult& item, int offsetX = 0, int offsetY = 0) const;
	void sortDmResultsByLayout(std::vector<DmCodeResult>& results) const;
	int decodeDmTrayGrid(const cv::Mat& gray, int rows, int cols, std::vector<DmCodeResult>& results) const;
	int tryDecodeDmCellPatch(const cv::Mat& normPatch, double mapBackScale, int offsetX, int offsetY, std::vector<DmCodeResult>& results) const;
	void decodeDmFallbackLimited(const cv::Mat& gray, std::vector<DmCodeResult>& results) const;

	Ui::frmQRcodeIdentifyClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);

private:
	void initTitleBar();
	void paintEvent(QPaintEvent* event);	

private slots:
	void onButtonCloseClicked();

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

private slots:	
	void on_btnExecute_clicked();
	void on_btnLinkImage_clicked();
	void on_btnDelLinkImage_clicked();
	void on_btnTestImage_clicked();

private:
	int RunTestImage();
	int RunToolPro();
	int RunToolProDM();
	bool InitDetector();
	bool InitDetectorDM();
	QImage Mat2QImage(const cv::Mat& mat);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	bool view_rect = false;
	cv::Ptr<cv::wechat_qrcode::WeChatQRCode> detector = nullptr;
	vector<cv::Mat> vPoints = vector<cv::Mat>(100);
	vector<string> strDecoded = vector<string>(100);
	vector<QString> Code = vector<QString>(100);
	int expectedDmCount = 8;
	int dmCellNormSide = 896;      // 每格归一化到该边长再解码（保证码模块像素够大）
	int dmMaxDecodeSide = 960;     // 单次 libdmtx 输入最大边长
	int dmDecodeTimeoutMs = 2800;  // 单次解码超时(ms)
	int dmMaxRegionsPerPass = 2;   // 每格最多解 2 个（防粘连）
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
