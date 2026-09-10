#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "mainwindow.h"
#include "datavar.h"

class MainWindow;
class QMenu;
class HeadWidget;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);

    //head's function
    void setLogo(const QString &imgFile = "", const QString &name = "");
    void setTitle(const QString &info = "");
    void setEnabelHeadMove(bool can_move = true); //是否启动移动
    //mainwindow's function
    void setToolDockWidget(QWidget *w);
    void setFlowDockWidget(QWidget *w);
    void setLogDockWidget(QWidget *w);
    void setCenterWidget(QWidget *w); //设置中心界面
    void setStatusInfo(const QString &info); //设置对应的状态信息

private slots:
    void doClose();
    void doToggleMaximized();    
    void doColorMenu(const QPoint &pos);   
    void slot_Login();
    void slot_Permis();
    void slot_About();   

private:     
    QMenu *m_pColorMenu = nullptr;
    HeadWidget *m_pHeadWidget = nullptr;     

signals:
    void sig_Quit();
};
