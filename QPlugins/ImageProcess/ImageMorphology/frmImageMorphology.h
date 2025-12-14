#pragma once

#include <QDialog>
#include "ui_frmImageMorphology.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitImageMorphologyData
{
	bool use_roi;
	QString type;
	qreal x;
	qreal y;
	qreal width;
	qreal height;
	qreal Lenth1;
	qreal Lenth2;
	qreal Pi;
	qreal R;
	QList<QPointF> init_points;
	QList<QList<QPointF>> list_ps;
};
Q_DECLARE_METATYPE(InitImageMorphologyData);

class frmImageMorphology : public Toolnterface
{
	Q_OBJECT

public:
	frmImageMorphology(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmImageMorphology();

private:
	Ui::frmImageMorphologyClass ui;

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
	void on_btnAddType_clicked();
	void on_btnDeleteType_clicked();
	void on_btnMoveUp_clicked();
	void on_btnMoveDown_clicked();
	void on_btnThresholdBack_clicked();
	void on_btnAdaptiveBack_clicked();
	void on_btnBlurBack_clicked();
	void on_btnMedianBlurBack_clicked();
	void on_btnGaussianBlurBack_clicked();
	void on_btnBilateralBack_clicked();
	void on_btnBoxBack_clicked();
	void on_btnSobelBack_clicked();
	void on_btnCannyBack_clicked();
	void on_btnLaplaceBack_clicked();
	void on_btnErodeBack_clicked();
	void on_btnDilateBack_clicked();
	void on_btnOpenBack_clicked();
	void on_btnCloseBack_clicked();
	void on_btnTophatBack_clicked();
	void on_btnBlackhatBack_clicked();
	void on_btnGradientBack_clicked();
	void on_btnHitmissBack_clicked();
	void on_btnLightBack_clicked();
	void on_btnLaplacianBack_clicked();
	void on_btnContrastBack_clicked();
	void on_btnGammaBack_clicked();
	void on_btnMulBack_clicked();
	void on_btnEmphasizeBack_clicked();
	void on_btnUnevenLightBack_clicked();
	void on_btnFillUpBack_clicked();
	void on_btnShapeTransBack_clicked();
	void on_btnThreshBack_clicked();	
	void on_btnChannelBack_clicked();
	void slot_DoubleClicked(int, int);
	void timerEvent();

private slots:
	void slot_grayAc();
	void slot_channelAc();
	void slot_fillUpAc();
	void slot_shapeTransAc();
	void slot_thresholdAc();
	void slot_connectionAc();
	void slot_adaptiveAc();
	void slot_threshAc();	
	void slot_entropySegAc();
	void slot_iterationAc();
	void slot_meanAc();
	void slot_medianAc();
	void slot_gaussAc();
	void slot_bilateralAc();
	void slot_boxAc();
	void slot_scharrAc();
	void slot_cannyAc();
	void slot_laplaceAc();
	void slot_sobelAc();
	void slot_erodeAc();
	void slot_dilateAc();
	void slot_openAc();
	void slot_closeAc();
	void slot_tophatAc();
	void slot_bottomhatAc();
	void slot_gradientAc();
	void slot_hitmissAc();		
	void slot_contrastAc();
	void slot_brightnessAc();	
	void slot_sharpenAc();
	void slot_gammaCorrectionAc();
	void slot_histogramAc();
	void slot_whiteBalanceAc();
	void slot_emphasizeAc();
	void slot_mulAc();
	void slot_unevenLightAc();

private:	
	void form_load();
	int RunToolPro();
	void moveRow(QTableWidget* pTable, int nFrom, int nTo) const;
	bool Preprocess(const QString m_ToolNames, cv::Mat src_mat, cv::Mat& dst_mat) const;
	QImage Mat2QImage(const cv::Mat& mat);	

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;
	int image_index = 0;
	int tool_index = 0;
	int region_buf = 0;
	RectangleItem* rectangle_item;
	RectangleRItem* rectangler_item;
	CircleItem* circle_item;
	PolygonItem* polygon_item;
	MRectangle m_rectangle;
	MRotatedRect m_rotatedrect;
	MCircle m_circle;
	MPolygon m_polygon;
	cv::Rect rect;
	cv::Mat mask;
	cv::Mat dst;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;
};
