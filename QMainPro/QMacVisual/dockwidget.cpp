#include "dockwidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QAction>
#include <QApplication>
#include <QMouseEvent>
#include <QtDebug>

DockWidget::DockWidget(const QString &title, QWidget *parent) : QDockWidget(title, parent)
{      
    m_pHeadWidget = new DockHeadWidget(title, this);
    m_pHeadWidget->setMinimumHeight(28);
    m_pHeadWidget->openFloatAcceptMousePress();
    this->setTitleBarWidget(m_pHeadWidget);   
    connect(this, &QDockWidget::topLevelChanged, this, &DockWidget::doTopLevelChanged);
    connect(m_pHeadWidget, &DockHeadWidget::sigClose, this, &DockWidget::close);
    connect(m_pHeadWidget, &DockHeadWidget::sigClose, this, &DockWidget::sigClose);
    connect(m_pHeadWidget, &DockHeadWidget::sigToggleFloat, this, [this](){
        this->setFloating(!this->isFloating());
    });   
}

void DockWidget::doTopLevelChanged(bool topLevel)
{
    m_pHeadWidget->setFloating(topLevel);
}

bool DockWidget::event(QEvent *e)
{
    if (e->type() == QEvent::ActivationChange)
    {
        if(this->isFloating() && QApplication::activeWindow() != this)
        {
            this->hide();
        }
    }
    return QDockWidget::event(e);
}

DockHeadWidget::DockHeadWidget(QWidget *parent) : QWidget(parent)
{
    //按钮样式
    QString btnStyle(
        "QWidget{"
        "border: none;"
        "}"
        "QPushButton:hover{"
        "background-color: rgba(243, 235, 197,100);"
        "}"
        "QPushButton:pressed{"
        "background-color: rgba(243, 235, 197,100);"
        "}"
    );
    this->setAttribute(Qt::WA_StyledBackground);
    m_pTitle = new QLabel(this);
    m_pTitle->setObjectName("pTitle");
    m_pBtnFloat = new QPushButton("", this);
    m_pBtnFloat->setIcon(QIcon(":/Bitmaps/arrow_2.png"));   
    m_pBtnFloat->setToolTip("隐藏");
    m_pBtnFloat->setStyleSheet(btnStyle);
    auto *pBtnCls = new QPushButton("", this);
    pBtnCls->setIcon(QIcon(":/Bitmaps/close_2.png"));
    pBtnCls->setToolTip("关闭");
    pBtnCls->setStyleSheet(btnStyle);
    m_pTitle->setProperty("type", "xblack");
    m_pBtnFloat->setProperty("type", "xblack");
    pBtnCls->setProperty("type", "xblack");
    m_pBtnFloat->setFixedSize(20, 20);
    pBtnCls->setFixedSize(20, 20);
    auto *hlay = new QHBoxLayout(this);
    hlay->setContentsMargins(3,0,3,0);
    hlay->setSpacing(3);
    hlay->addWidget(m_pTitle, 1);
    hlay->addSpacing(20);
    hlay->addWidget(m_pBtnFloat);
    hlay->addWidget(pBtnCls);
    connect(pBtnCls, &QPushButton::clicked, this, &DockHeadWidget::sigClose);
    connect(m_pBtnFloat, &QPushButton::clicked, this, &DockHeadWidget::sigToggleFloat);
}

DockHeadWidget::DockHeadWidget(const QString &title, QWidget *parent) : DockHeadWidget(parent)
{
    setTitle(title);
}

DockHeadWidget::~DockHeadWidget()
{
    this->deleteLater();
}

void DockHeadWidget::setFloating(bool is_float)
{
    if (is_float)
    {
        m_pBtnFloat->setToolTip("显示");
        m_pBtnFloat->setIcon(QIcon(":/Bitmaps/arrow_1.png"));
    }
    else
    {
        m_pBtnFloat->setToolTip("隐藏");
        m_pBtnFloat->setIcon(QIcon(":/Bitmaps/arrow_2.png"));
    }
}

void DockHeadWidget::setTitle(const QString &name)
{
    m_pTitle->setText(name);
}

void DockHeadWidget::mousePressEvent(QMouseEvent *e)
{
    auto *w = qobject_cast<DockWidget *>( this->parentWidget() ) ;
    if(m_bAcceptMousePress && w && w->isFloating())
        e->accept();
    else
        QWidget::mousePressEvent(e);
}
