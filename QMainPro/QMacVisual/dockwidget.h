#pragma once
#pragma execution_character_set("utf-8")

#include <QDockWidget>

class QLabel;
class QPushButton;
class DockHeadWidget;

class DockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit DockWidget(const QString &title = "", QWidget *parent = nullptr);

private slots:
    void doTopLevelChanged(bool topLevel);

signals:
    void sigClose();

protected:
    bool event(QEvent *e) override;

private:
    DockHeadWidget *m_pHeadWidget = nullptr;    
};

class DockHeadWidget : public QWidget
{
    Q_OBJECT

public:
    DockHeadWidget(QWidget *parent = nullptr);
    DockHeadWidget(const QString &title, QWidget *parent = nullptr);
    ~DockHeadWidget();

    void setFloating(bool is_float);
    void setTitle(const QString &name);

    //开启浮点时,拦截鼠标按下,防止移动
    void openFloatAcceptMousePress(bool is_open = true)
    {
        m_bAcceptMousePress = is_open;
    }

signals:
    void sigClose();
    void sigToggleFloat();

protected:
    void mousePressEvent(QMouseEvent *e) override;

private:
    bool m_bAcceptMousePress = false;
    QLabel *m_pTitle = nullptr;
    QPushButton *m_pBtnFloat = nullptr;   
};

