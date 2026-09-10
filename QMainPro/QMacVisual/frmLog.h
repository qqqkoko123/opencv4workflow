#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_frmLog.h"
#include <QWidget>

class CLogModel;

enum class LogType {
    Debug, Info, Warn, Error, Fatal
};

class FrmLog : public QWidget
{
    Q_OBJECT

public:
    explicit FrmLog(QWidget *parent = Q_NULLPTR);   
    ~FrmLog();   
    QSize sizeHint() const override;   

private:
    Ui::frmLogClass ui;

public slots:
    void slot_InfoClick();
    void slot_WarnClick();
    void slot_ErrorClick();
    void slot_Message(const QString strMsg);   
    void slot_Message_Info(const QString strMsg);
    void slot_Message_Warn(const QString strMsg);
    void slot_Message_Error(const QString strMsg);

private slots:
    void timerEvent();  

signals:
    bool sig_Message_Info(int index, const QString item);
    bool sig_Message_Warn(int index, const QString item);
    bool sig_Message_Error(int index, const QString item);  

private:    
    LogType m_currentLogType = LogType::Info;
    CLogModel *m_pInfoModel = nullptr;
    CLogModel *m_pWarnModel = nullptr;
    CLogModel *m_pErrorModel = nullptr;  
    QTimer* p_timer;
    QThread* h_this, * h_info, * h_warn, * h_error;
};
