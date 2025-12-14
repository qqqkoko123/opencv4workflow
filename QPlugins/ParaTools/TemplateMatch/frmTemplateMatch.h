#pragma once

#include <QDialog>
#include "ui_frmTemplateMatch.h"
#include <opencv2\opencv.hpp>
#include <opencv2/imgproc/types_c.h>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitTemplateMatchData
{
	bool use_roi;
	qreal x;
	qreal y;
	qreal width;
	qreal height;
	QColor color;
	QImage srcModelImage;
	QPointF datum_center;
};
Q_DECLARE_METATYPE(InitTemplateMatchData);

struct s_TemplData
{
	vector<cv::Mat> vecPyramid;
	vector<cv::Scalar> vecTemplMean;
	vector<double> vecTemplNorm;
	vector<double> vecInvArea;
	vector<bool> vecResultEqual1;
	bool bIsPatternLearned;

	void clear()
	{
		vector<cv::Mat>().swap(vecPyramid);
		vector<double>().swap(vecTemplNorm);
		vector<double>().swap(vecInvArea);
		vector<cv::Scalar>().swap(vecTemplMean);
		vector<bool>().swap(vecResultEqual1);
	}

	void resize(int iSize)
	{
		vecTemplMean.resize(iSize);
		vecTemplNorm.resize(iSize, 0);
		vecInvArea.resize(iSize, 1);
		vecResultEqual1.resize(iSize, false);
	}

	s_TemplData()
	{
		bIsPatternLearned = false;
	}
};

struct s_MatchParameter
{
	cv::Point2d pt;
	double dMatchScore;
	double dMatchAngle;
	cv::Rect rectRoi;
	double dAngleStart;
	double dAngleEnd;
	cv::RotatedRect rectR;
	cv::Rect rectBounding;
	bool bDelete;
	double vecResult[3][3];
	int iMaxScoreIndex;
	bool bPosOnBorder;
	cv::Point2d ptSubPixel;
	double dNewAngle;

	s_MatchParameter(cv::Point2f ptMinMax, double dScore, double dAngle)
	{
		pt = ptMinMax;
		dMatchScore = dScore;
		dMatchAngle = dAngle;
		bDelete = false;
		dNewAngle = 0.0;
		bPosOnBorder = false;
	}

	s_MatchParameter()
	{
		double dMatchScore = 0;
		double dMatchAngle = 0;
	}

	~s_MatchParameter()
	{

	}
};

struct s_SingleTargetMatch
{
	cv::Point2d ptLT, ptRT, ptRB, ptLB, ptCenter;
	double dMatchedAngle;
	double dMatchScore;
};

class frmTemplateMatch : public Toolnterface
{
	Q_OBJECT

public:
	frmTemplateMatch(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmTemplateMatch();

private:
	Ui::frmTemplateMatchClass ui;

public:
	virtual int Execute(const QString toolname);
	virtual int ExecuteLink(const int int_link, const QString str_link, const QMap<QString, gVariable::Global_Var> variable_link = QMap<QString, gVariable::Global_Var>());
	virtual int ExecuteAllLink(const QMap<QString, gVariable::Global_Var> g_variable_link);
	virtual int InitSetToolData(const QVariant data);
	virtual QVariant InitGetToolData();

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
	void on_btnAddROI_clicked();
	void on_btnDeleteROI_clicked();
	void on_btnAddROI_2_clicked();
	void on_btnDeleteROI_2_clicked();
	void on_btnCreateROI_clicked();
	void on_btnDeleteModel_clicked();
	void on_btnRoiColor_clicked();
	void on_comboMode_currentIndexChanged(int index);
	void on_comboViewMode_currentIndexChanged(int index);

private:
	int RunToolPro();
	bool Save_Mat(const string path, const string mat_name, const cv::Mat src_mat);
	cv::Mat Load_Mat(const QString path, const string mat_name);
	QImage Mat2QImage(const cv::Mat& mat);	
	cv::Mat QImageToMat(const QImage& image);
	int MatchTemplate(const cv::Mat source, const cv::Mat model, cv::Mat& out_source, const bool use_roi, const MRectangle m_rectangle, vector<cv::Point2f>& center, vector<double>& angle, vector<double>& out_score, const int num_levels, const int match_mode, const int angle_start_end, const int num_matches, const double max_overlap, const double int_score, const bool show_result, const int thickness);
	void LearnPattern(const cv::Mat model, const int num_levels);
	inline int _mm_hsum_epi32(const __m128i V) const;
	inline int IM_Conv_SIMD(const unsigned char* pCharKernel, const unsigned char* pCharConv, const int iLength) const;
	int Template(cv::Mat& matSrc, s_TemplData* pTemplData, cv::Mat& matResult, const int iLayer) const;
	void CCOEFF_Denominator(cv::Mat& matSrc, s_TemplData* pTemplData, cv::Mat& matResult, const int iLayer) const;
	bool SubPixEsimation(vector<s_MatchParameter>* vec, double* dNewX, double* dNewY, double* dNewAngle, double dAngleStep, int iMaxScoreIndex) const;
	cv::Size GetBestRotationSize(const cv::Size sizeSrc, const cv::Size sizeDst, double dRAngle) const;
	cv::Point2f ptRotatePt2f(const cv::Point2f ptInput, const cv::Point2f ptOrg, const double dAngle) const;
	cv::Point GetNextMaxLoc(const cv::Mat& matResult, const cv::Point ptMaxLoc, const double dMinValue, const int iTemplateW, const int iTemplateH, double& dMaxValue, const double dMaxOverlap);
	void FilterWithScore(vector<s_MatchParameter>* vec, double dScore) const;
	void GetRotatedROI(cv::Mat& matSrc, cv::Size size, cv::Point2f ptLT, double dAngle, cv::Mat& matROI) const;
	void FilterWithRotatedRect(vector<s_MatchParameter>* vec, int iMethod = CV_TM_CCOEFF_NORMED, double dMaxOverLap = 0) const;
	void SortPtWithCenter(vector<cv::Point2f>& vecSort) const;
	void DrawMarkCross(const cv::Mat& matDraw, const int iX, const int iY, const int iLength, const cv::Scalar color, const int iThickness);

private:		
	gVariable gvariable;
	QGraphicsViews* view;	
	QStringList strs;
	int match_mode;
	bool contour_view;
	cv::Mat srcImage;
	cv::Mat dstImage;
	cv::Mat dstRoiImage;
	cv::Mat model;
	cv::Mat model_buf;
	int image_index = 0;
	int tool_index = 0;
	QColor color;
	RectangleItem* rectangle_item;	
	MRectangle m_rectangle;
	cv::Rect rect;
	cv::Mat mask;
	cv::Mat dst;
	bool use_roi;
	cv::Point2f DatumCenter;
	bool calcDatumCenter = false;
	//定义输出数据
	vector<cv::Point2f> center = vector<cv::Point2f>(1000);	
	vector<double> angle = vector<double>(1000);
	vector<double> out_score = vector<double>(1000);	

private:
	s_TemplData m_TemplData;
	vector<s_SingleTargetMatch> m_vecSingleTargetData = vector<s_SingleTargetMatch>(1000);
	vector<cv::Point2f> center_buf = vector<cv::Point2f>(1000);	
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
