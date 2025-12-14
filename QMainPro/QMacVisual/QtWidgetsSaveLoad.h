#pragma once

#include <QList>
#include <QDataStream>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTableWidget>
#include <QComboBox>
#include <QTreeWidgetItem>

struct InitImageSourceData
{
	int camera_index;
	QVector<QString> g_camera;
};
Q_DECLARE_METATYPE(InitImageSourceData);

struct InitCropImageData
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
Q_DECLARE_METATYPE(InitCropImageData);

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

struct InitSkeletonData
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
Q_DECLARE_METATYPE(InitSkeletonData);

struct InitBlobDetectorData
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
	QColor color;
};
Q_DECLARE_METATYPE(InitBlobDetectorData);

struct InitSelectShapeData
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
	QColor color;
};
Q_DECLARE_METATYPE(InitSelectShapeData);

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

struct InitColorIdentifyData
{
	bool use_roi;
	qreal x;
	qreal y;
	qreal width;
	qreal height;
	QColor color;
	QImage srcStandardImage;
};
Q_DECLARE_METATYPE(InitColorIdentifyData);

struct InitClassifierData
{
	QVector<int> type_key;
	QVector<QString> type_names;
	QString file_model;
};
Q_DECLARE_METATYPE(InitClassifierData);

struct InitCamShiftTrackData
{
	bool use_roi;
	qreal x;
	qreal y;
	qreal width;
	qreal height;
};
Q_DECLARE_METATYPE(InitCamShiftTrackData);

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

struct InitShapeMatchData
{
	bool use_roi;
	qreal x;
	qreal y;
	qreal width;
	qreal height;
	QColor color;
	QImage srcModelImage;
	QPointF datum_center;
	QString fileModelName;
};
Q_DECLARE_METATYPE(InitShapeMatchData);

struct InitMeasureCalibrationData
{
	double PixelEquivalentX;
	double PixelEquivalentY;
};
Q_DECLARE_METATYPE(InitMeasureCalibrationData);

struct InitGetContourPointsData
{
	bool use_roi;
	QString type;
	qreal x;
	qreal y;
	qreal width;
	qreal height;
	qreal R;
	QColor color;
};
Q_DECLARE_METATYPE(InitGetContourPointsData);

struct InitFindCircleData
{
	bool use_roi;
	QString type;
	qreal x;
	qreal y;
	qreal RadiusMin;
	qreal RadiusMax;
	int segment_line_num;
	QVector<QPointF> ring_s_points;
	QVector<QPointF> ring_b_points;
	QColor color;
};
Q_DECLARE_METATYPE(InitFindCircleData);

struct InitRoundedCornersData
{
	bool use_roi;
	QString type;
	qreal x;
	qreal y;
	qreal RadiusMin;
	qreal RadiusMax;
	int segment_line_num;
	QVector<QPointF> ring_s_points;
	QVector<QPointF> ring_b_points;
	QColor color;
};
Q_DECLARE_METATYPE(InitRoundedCornersData);

struct InitFindLineData
{
	bool use_roi;
	QString type;
	qreal x1;
	qreal y1;
	qreal x2;
	qreal y2;
	qreal height;
	float row;
	float col;
	float len1;
	float len2;
	float angle;
	QPointF pp1;
	QPointF pp2;
	int segment_line_num;
	QVector<QPointF> line_s_points;
	QVector<QPointF> line_b_points;
	QColor color;
};
Q_DECLARE_METATYPE(InitFindLineData);

struct InitEdgeWidthMeasureData
{
	bool use_roi;
	QString type;
	qreal x1;
	qreal y1;
	qreal x2;
	qreal y2;
	qreal height;
	float row;
	float col;
	float len1;
	float len2;
	float angle;
	QPointF pp1;
	QPointF pp2;
	int segment_line_num;
	QVector<QPointF> line_s_points;
	QVector<QPointF> line_b_points;
	QColor color;
};
Q_DECLARE_METATYPE(InitEdgeWidthMeasureData);

struct InitExportCsvData
{
	QVector<int> csv_key;
	QVector<QString> csv_names;
	QString dirPath;
};
Q_DECLARE_METATYPE(InitExportCsvData);

struct InitExtensionLibraryData
{
	QString image_link;
	QString dirPath;
};
Q_DECLARE_METATYPE(InitExtensionLibraryData);

struct InitLogicGotoData
{
	int goto_index;
	QVector<QString> g_tools;
};
Q_DECLARE_METATYPE(InitLogicGotoData);

struct InitGeneralIoData
{
	int io_index;
	QVector<QString> io_tools;
};
Q_DECLARE_METATYPE(InitGeneralIoData);

struct InitPlcCommunicateData
{
	int plc_index;
	QVector<QString> plc_tools;
	QVector<QString> plc_key;
	QVector<QString> mit_code;
	QVector<QString> mit_state;
	QVector<QString> mit_method;
	QVector<QString> mit_address;
	QVector<QString> mit_data;
};
Q_DECLARE_METATYPE(InitPlcCommunicateData);

struct InitSerialPortData
{
	int sport_index;
	QVector<QString> sport_tools;
};
Q_DECLARE_METATYPE(InitSerialPortData);

struct InitSocketTcpClientData
{
	int client_index;
	QVector<QString> client_tools;
};
Q_DECLARE_METATYPE(InitSocketTcpClientData);

struct InitSocketTcpServerData
{
	int server_index;
	QVector<QString> server_tools;
};
Q_DECLARE_METATYPE(InitSocketTcpServerData);

class WidgetInfo
{
public:
	//窗体界面控件序列化/反序列化
	QString control_name;
	QString qLabel_text;
	QString qLineEdit_text;
	QString qTextEdit_text;
	QString qPlainTextEdit_text;
	bool qCheckBox_checked;
	bool qRadioButton_checked;
	QString qComboBox_currentText;
	int qSpinBox_value;
	double qDoubleSpinBox_value;
	QVector<QString> qTableWidget_text;
	int row_count;
	//数据序列化/反序列化	
	QString tree_text = QString();
	QIcon tree_icon;
	QVector<QString> flowProItemList;
	int m_index;
	int m_nId;
	QPixmap m_pixmap;
	QString m_strTitle;
	QString m_strSubTitle;
	QString m_strDescribeTitle;
	QRect   m_rectItem;
	QRect   m_rectSub;
	QPixmap m_subPixmap;
	QMap<QString, int> itemContent;
	QList<QString> m_states;
	//仪器仪表
	QString global_key;
	QString global_ip;
	int global_port;
	int global_timeout;
	QString global_remark;
	QString global_serial_port;
	QString global_baud_rate;
	QString global_check_digit;
	QString global_data_bits;
	QString global_stop_bit;
	QString global_flowcontrol;
	QString global_protocol;
	QVector<QString> io_client_ip;
	QVector<QString> io_client_port;
	QVector<QString> mit_plc_client_ip;
	QVector<QString> mit_plc_client_port;
	QVector<QString> tcp_client_ip;
	QVector<QString> tcp_client_port;
	QString io_key_value;
	QString plc_key_value;
	QString serialport_key_value;
	QString server_key_value;
	QString client_key_value;
	int connect_state;
	QString ip_value;
	int port_value;
	int over_time_value;
	QString remark_value;	
	QString plc_type;
	QString mit_ip_value;
	int mit_port_value;
	int mit_over_time_value;
	QString mit_remark_value;	
	QString portname_value;
	int baudrate_value;
	QString parity_value;
	QString databits_value;
	QString stopbits_value;
	QString flowcontrol_value;
	QString protocol_value;
	//相机
	QString camera_key_value;
	int ccd_index;
	QVector<QString> camera_state;
	int global_exposure;
	double global_gain;
	double global_gamma;
	int global_contrast;
	QString global_trigger_mode;		
	QString camera_type;
	int mindvision_haldle_value;
	unsigned char mindvision_framebuffer_value;
	int time_out;

public:
	//工具的特定参数
	int camera_index;
	QVector<QString> g_camera;
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
	QColor color;
	QVector<QString> key;
	QVector<QString> global_pos_xy;
	QVector<QString> global_state;
	QVector<QString> global_content;
	QVector<QString> global_prefix;
	QVector<QString> global_OK_text;
	QVector<QString> global_NG_text;
	QVector<QColor> global_ok_color;
	QVector<QColor> global_ng_color;
	QColor contour_color;
	QImage srcStandardImage;
	QVector<int> type_key;
	QVector<QString> type_names;
	QString file_model;
	QImage srcModelImage;
	QPointF datum_center;
	bool use_roi;
	QString fileModelName;
	double PixelEquivalentX;
	double PixelEquivalentY;
	qreal RadiusMin;
	qreal RadiusMax;
	int segment_line_num;
	QVector<QPointF> ring_s_points;
	QVector<QPointF> ring_b_points;
	qreal x1;
	qreal y1;
	qreal x2;
	qreal y2;
	float row;
	float col;
	float len1;
	float len2;
	float angle;
	QPointF pp1;
	QPointF pp2;
	QVector<QPointF> line_s_points;
	QVector<QPointF> line_b_points;
	QVector<int> csv_key;
	QVector<QString> csv_names;
	QString dirPath;
	QString image_link;
	int goto_index;
	QVector<QString> g_tools;
	int io_index;
	QVector<QString> io_tools;
	int plc_index;
	QVector<QString> plc_tools;
	QVector<QString> plc_key;
	QVector<QString> mit_code;
	QVector<QString> mit_state;
	QVector<QString> mit_method;
	QVector<QString> mit_address;
	QVector<QString> mit_data;
	int sport_index;
	QVector<QString> sport_tools;
	int client_index;
	QVector<QString> client_tools;
	int server_index;
	QVector<QString> server_tools;

	//重载运算符
	friend QDataStream& operator << (QDataStream& dataStream, const WidgetInfo& wi)
	{
		dataStream << wi.control_name << wi.qLabel_text << wi.qLineEdit_text << wi.qTextEdit_text << wi.qPlainTextEdit_text << wi.qCheckBox_checked << wi.qRadioButton_checked << wi.qComboBox_currentText
			<< wi.qSpinBox_value << wi.qDoubleSpinBox_value << wi.qTableWidget_text << wi.row_count << wi.tree_text << wi.tree_icon << wi.flowProItemList;
		dataStream << wi.m_index << wi.m_nId << wi.m_pixmap << wi.m_strTitle << wi.m_strSubTitle << wi.m_strDescribeTitle << wi.m_rectItem << wi.m_rectSub << wi.m_subPixmap;
		dataStream << wi.itemContent << wi.m_states;
		dataStream << wi.global_key << wi.global_ip << wi.global_port << wi.global_timeout << wi.global_remark << wi.global_serial_port << wi.global_baud_rate << wi.global_check_digit << wi.global_data_bits << wi.global_stop_bit << wi.global_flowcontrol << wi.global_protocol;
		dataStream << wi.io_client_ip << wi.io_client_port << wi.mit_plc_client_ip << wi.mit_plc_client_port << wi.tcp_client_ip << wi.tcp_client_port;
		dataStream << wi.io_key_value << wi.plc_key_value << wi.serialport_key_value << wi.server_key_value << wi.client_key_value << wi.connect_state << wi.ip_value << wi.port_value << wi.over_time_value << wi.remark_value << wi.plc_type << wi.mit_ip_value << wi.mit_port_value
			<< wi.mit_over_time_value << wi.mit_remark_value << wi.portname_value << wi.baudrate_value << wi.parity_value << wi.databits_value << wi.stopbits_value << wi.flowcontrol_value << wi.protocol_value;
		dataStream << wi.camera_key_value << wi.ccd_index << wi.camera_state << wi.global_exposure << wi.global_gain << wi.global_gamma << wi.global_contrast << wi.global_trigger_mode << wi.camera_type << wi.mindvision_haldle_value << wi.mindvision_framebuffer_value << wi.time_out;
		dataStream << wi.camera_index << wi.g_camera << wi.type << wi.x << wi.y << wi.width << wi.height << wi.Lenth1 << wi.Lenth2 << wi.Pi << wi.R << wi.init_points << wi.list_ps << wi.color;
		dataStream << wi.key << wi.global_pos_xy << wi.global_state << wi.global_content << wi.global_prefix << wi.global_OK_text << wi.global_NG_text << wi.global_ok_color << wi.global_ng_color << wi.contour_color << wi.srcStandardImage << wi.type_key << wi.type_names << wi.file_model << wi.srcModelImage << wi.datum_center;
		dataStream << wi.use_roi << wi.fileModelName << wi.PixelEquivalentX << wi.PixelEquivalentY << wi.RadiusMin << wi.RadiusMax << wi.segment_line_num << wi.ring_s_points << wi.ring_b_points << wi.x1 << wi.y1 << wi.x2 << wi.y2 << wi.line_s_points << wi.line_b_points
			<< wi.row << wi.col << wi.len1 << wi.len2 << wi.angle << wi.pp1 << wi.pp2 << wi.csv_key << wi.csv_names << wi.dirPath << wi.image_link << wi.goto_index << wi.g_tools << wi.io_index << wi.io_tools;
		dataStream << wi.plc_index << wi.plc_tools << wi.plc_key << wi.mit_code << wi.mit_state << wi.mit_method << wi.mit_address << wi.mit_data << wi.sport_index << wi.sport_tools << wi.client_index << wi.client_tools << wi.server_index << wi.server_tools;
		return dataStream;
	}	

	//重载运算符
	friend QDataStream& operator >> (QDataStream& dataStream, WidgetInfo& wi)
	{
		dataStream >> wi.control_name >> wi.qLabel_text >> wi.qLineEdit_text >> wi.qTextEdit_text >> wi.qPlainTextEdit_text >> wi.qCheckBox_checked >> wi.qRadioButton_checked >> wi.qComboBox_currentText
			>> wi.qSpinBox_value >> wi.qDoubleSpinBox_value >> wi.qTableWidget_text >> wi.row_count >> wi.tree_text >> wi.tree_icon >> wi.flowProItemList;
		dataStream >> wi.m_index >> wi.m_nId >> wi.m_pixmap >> wi.m_strTitle >> wi.m_strSubTitle >> wi.m_strDescribeTitle >> wi.m_rectItem >> wi.m_rectSub >> wi.m_subPixmap;
		dataStream >> wi.itemContent >> wi.m_states;
		dataStream >> wi.global_key >> wi.global_ip >> wi.global_port >> wi.global_timeout >> wi.global_remark >> wi.global_serial_port >> wi.global_baud_rate >> wi.global_check_digit >> wi.global_data_bits >> wi.global_stop_bit >> wi.global_flowcontrol >> wi.global_protocol;
		dataStream >> wi.io_client_ip >> wi.io_client_port >> wi.mit_plc_client_ip >> wi.mit_plc_client_port >> wi.tcp_client_ip >> wi.tcp_client_port;
		dataStream >> wi.io_key_value >> wi.plc_key_value >> wi.serialport_key_value >> wi.server_key_value >> wi.client_key_value >> wi.connect_state >> wi.ip_value >> wi.port_value >> wi.over_time_value >> wi.remark_value >> wi.plc_type >> wi.mit_ip_value >> wi.mit_port_value
			>> wi.mit_over_time_value >> wi.mit_remark_value >> wi.portname_value >> wi.baudrate_value >> wi.parity_value >> wi.databits_value >> wi.stopbits_value >> wi.flowcontrol_value >> wi.protocol_value;
		dataStream >> wi.camera_key_value >> wi.ccd_index >> wi.camera_state >> wi.global_exposure >> wi.global_gain >> wi.global_gamma >> wi.global_contrast >> wi.global_trigger_mode >> wi.camera_type >> wi.mindvision_haldle_value >> wi.mindvision_framebuffer_value >> wi.time_out;
		dataStream >> wi.camera_index >> wi.g_camera >> wi.type >> wi.x >> wi.y >> wi.width >> wi.height >> wi.Lenth1 >> wi.Lenth2 >> wi.Pi >> wi.R >> wi.init_points >> wi.list_ps >> wi.color;
		dataStream >> wi.key >> wi.global_pos_xy >> wi.global_state >> wi.global_content >> wi.global_prefix >> wi.global_OK_text >> wi.global_NG_text >> wi.global_ok_color >> wi.global_ng_color >> wi.contour_color >> wi.srcStandardImage >> wi.type_key >> wi.type_names >> wi.file_model >> wi.srcModelImage >> wi.datum_center;
		dataStream >> wi.use_roi >> wi.fileModelName >> wi.PixelEquivalentX >> wi.PixelEquivalentY >> wi.RadiusMin >> wi.RadiusMax >> wi.segment_line_num >> wi.ring_s_points >> wi.ring_b_points >> wi.x1 >> wi.y1 >> wi.x2 >> wi.y2 >> wi.line_s_points >> wi.line_b_points
			>> wi.row >> wi.col >> wi.len1 >> wi.len2 >> wi.angle >> wi.pp1 >> wi.pp2 >> wi.csv_key >> wi.csv_names >> wi.dirPath >> wi.image_link >> wi.goto_index >> wi.g_tools >> wi.io_index >> wi.io_tools;
		dataStream >> wi.plc_index >> wi.plc_tools >> wi.plc_key >> wi.mit_code >> wi.mit_state >> wi.mit_method >> wi.mit_address >> wi.mit_data >> wi.sport_index >> wi.sport_tools >> wi.client_index >> wi.client_tools >> wi.server_index >> wi.server_tools;
		return dataStream;
	}	
};

class QtWidgetsSaveLoad
{
public:
	QtWidgetsSaveLoad();
	void addQLabel(QLabel* w);
	void addQLineEdit(QLineEdit* w);
	void addQTextEdit(QTextEdit* w);
	void addQCheckBox(QCheckBox* w);
	void addQRadioButton(QRadioButton* w);
	void addQComboBox(QComboBox* w);
	void addQSpinBox(QSpinBox* w);
	void addQDoubleSpinBox(QDoubleSpinBox* w);
	void addQTableWidget(QTableWidget* w);	
	void saveToFile(QList<QWidget*> parent);
	void loadFromFile(QList<QWidget*> parent);
	void loadFromFileFirst();
	void setFilenameWithPath(const QString& filenameWithPath);
	void saveToolParam(int index, QString tool_name, QVariant var);
	void saveToolParam2(int index, QString tool_name, QVariant var);
	void saveToolParam3(int index, QString tool_name, QVariant var);
	QList<WidgetInfo> widgetInfoList;
	QList<WidgetInfo> widgetInfoLists;
	QList<QList<WidgetInfo>> widgetInfoLists_save;
	QList<WidgetInfo> dataInfoList;	
	QList<WidgetInfo> dataToolList;	
	QVector<QVector<WidgetInfo>> dataToolTitleList;
	QList<WidgetInfo> dataIoLocalList;
	QList<WidgetInfo> dataIoRemoteList;
	QList<WidgetInfo> dataPlcLocalList;
	QList<WidgetInfo> dataPlcRemoteList;
	QList<WidgetInfo> dataSerialportLocalList;
	QList<WidgetInfo> dataSerialportRemoteList;
	QList<WidgetInfo> dataTcpLocalList;
	QList<WidgetInfo> dataServerRemoteList;
	QList<WidgetInfo> dataClientRemoteList;
	QList<WidgetInfo> dataCameraLocalList;
	QList<WidgetInfo> dataCameraRemoteList;

public:
	QVector<QVector<WidgetInfo>> dataImageSourceList;
	QVector<QVector<WidgetInfo>> dataCropImageList;
	QVector<QVector<WidgetInfo>> dataImageMorphologyList;
	QVector<QVector<WidgetInfo>> dataSkeletonList;
	QVector<QVector<WidgetInfo>> dataBlobDetectorList;
	QVector<QVector<WidgetInfo>> dataSelectShapeList;
	QVector<QVector<WidgetInfo>> dataImageViewList;
	QVector<QVector<WidgetInfo>> dataColorIdentifyList;
	QVector<QVector<WidgetInfo>> dataClassifierList;
	QVector<QVector<WidgetInfo>> dataCamShiftTrackList;
	QVector<QVector<WidgetInfo>> dataTemplateMatchList;
	QVector<QVector<WidgetInfo>> dataShapeMatchList;
	QVector<QVector<WidgetInfo>> dataMeasureCalibrationList;
	QVector<QVector<WidgetInfo>> dataGetContourPointsList;
	QVector<QVector<WidgetInfo>> dataFindCircleList;
	QVector<QVector<WidgetInfo>> dataRoundedCornersList;
	QVector<QVector<WidgetInfo>> dataFindLineList;
	QVector<QVector<WidgetInfo>> dataEdgeWidthMeasureList;
	QVector<QVector<WidgetInfo>> dataExportCsvList;
	QVector<QVector<WidgetInfo>> dataExtensionLibraryList;
	QVector<QVector<WidgetInfo>> dataLogicGotoList;
	QVector<QVector<WidgetInfo>> dataGeneralIoList;
	QVector<QVector<WidgetInfo>> dataPlcCommunicateList;
	QVector<QVector<WidgetInfo>> dataSerialPortList;
	QVector<QVector<WidgetInfo>> dataSocketTcpClientList;
	QVector<QVector<WidgetInfo>> dataSocketTcpServerList;

protected:
	QString filename;
	QString workPath;
	void gatherChildrenWidgetInfo(QList<QWidget*> parent);
	void saveParamToFileOne();
	void saveParamToFileTwo();
	void setChildrenWidgetValue(QList<QWidget*> parent);
};
