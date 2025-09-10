#pragma once

#include <QDialog>
#include "ui_frmImageView.h"
#include <opencv2\opencv.hpp>
#include "mytitlebar.h"
#include "QGraphicsViews.h"
#include "Toolnterface.h"

struct InitImageViewData
{
	QVector<QString> key;
	QVector<QString> global_pos_xy;
	QVector<QString> global_state;
	QVector<QString> global_content;
	QVector<QString> global_prefix;
	QVector<QColor> global_ok_color;
	QVector<QColor> global_ng_color;
	QVector<QString> global_OK_text;
	QVector<QString> global_NG_text;
	QColor contour_color;
};
Q_DECLARE_METATYPE(InitImageViewData);

class frmImageView : public Toolnterface
{
	Q_OBJECT

public:
	frmImageView(QString toolName, QToolBase* toolBase, QWidget* parent = Q_NULLPTR);
	~frmImageView();

private:
	Ui::frmImageViewClass ui;

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
	void on_btnLinkImage_clicked();
	void on_btnDelLinkImage_clicked();
	void on_btnColor_clicked();
	void on_btnExecute_clicked();
	void on_btnAddContour_clicked();
	void on_btnDeleteContour_clicked();
	void slot_DoubleClicked(int, int);
	void on_btnOkColor_clicked();	
	void on_btnNgColor_clicked();
	void on_btnAddText_clicked();
	void on_btnDeleteText_clicked();
	void slot_TextDoubleClicked(int, int);
	void on_btnBack_clicked();	
	void on_btnLinkPos_XY_clicked();	
	void on_btnDelLinkPos_XY_clicked();		
	void on_btnLinkState_clicked();	
	void on_btnDelLinkState_clicked();
	void on_btnLinkContent_clicked();	
	void on_btnDelLinkContent_clicked();	
	void on_btnSave_clicked();

protected:
	MyTitleBar* m_titleBar;
	QString toolTitleName;

private:
	int RunToolPro();
	QImage GetErrorImage(int tool_index);
	bool WriteString(QImage& img, const QString str_msg, const QPoint str_pos, const QColor font_color, const int font_size, const bool font_bold) const;
	QImage Mat2QImage(const cv::Mat& mat);
	cv::Mat QImageToMat(const QImage& image);

private:	
	gVariable gvariable;
	QGraphicsViews* view;
	QStringList strs;
	cv::Mat srcImage;
	cv::Mat dstImage;
	QColor color, ok_color, ng_color;	
	int image_index = 0;
	int tool_index = 0;
	int getImage_index = 0;
	int contour_index = 0;
	int contour_index_row;
	int text_index = 0;
	int text_index_row;
	QList<QString> keys;
	QList<QString> text_keys;
	QPoint text_pos;
	bool text_state;
	int text_state_buf;
	QString text_content;
	int text_content_buf;
	QImage out_img;
	QList<int> m_process_text_buf;
	QList<int> m_process_contour_buf;
	QString content_buf;

private:
	QVector<QString> getViewMsg = QVector<QString>(100);
	bool v_state;

private:
	typedef struct TEXTCONTENT
	{
		QString global_pos_xy;
		QString global_state;
		QString global_content;
		QString global_prefix;
		QColor global_ok_color;
		QColor global_ng_color;
		QString global_OKtext;
		QString global_NGtext;
	} Text_Content;
	Text_Content TextContent;
	QMap<QString, Text_Content> global_text_content;
};

//全局变量控制
class QConfig
{
public:
	static int nFormState;		
};
