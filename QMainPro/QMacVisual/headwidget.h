#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include <QPushButton>

class QLabel;

class HeadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HeadWidget(QWidget *parent = nullptr);

    void setLogo(const QString &imgFile = "", const QString &name = "");
    void setTitle(const QString &info = "");
    void setBgColor(const QString &color);

    //是否开启“按下”,进行移动窗体(在mouseMoveEvent里面实现)
    void setEnabelMove(bool can_move = true)
    {
        m_bEnabelMove = can_move;
    }

signals:
    void sigMinimized();
    void sigToggleMaximized();    
    void sigClose();
    void sigColor(const QPoint &pos);

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    bool m_bEnabelMove = true; //是否开启移动
    bool m_bMouseIsMove = false; //是否移动
    bool m_bPressed = false;  //鼠标是否按下
    QPoint m_pressedMousePos;
    QPoint m_pressedWidgetPos;
    QLabel *m_pLogo = nullptr;
    QLabel *m_pName = nullptr;
    QLabel *m_pInfo = nullptr;
    QPushButton* pBtnMax = nullptr;

public slots:
    void min_maxState();
    void shot_Quit();
};

