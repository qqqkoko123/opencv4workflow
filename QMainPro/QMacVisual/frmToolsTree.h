#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_frmToolsTree.h"
#include <QGridLayout>
#include "qttreewidget.h"
#include "maininterface.h"

typedef std::pair<QString, std::list<QString> > ToolsPair;

class frmToolsTree : public QWidget
{
    Q_OBJECT

public:
    frmToolsTree(QWidget* parent = Q_NULLPTR);

private:
    Ui::frmToolsTreeClass ui;

private:   
    void ToolsTreeWidgetInit();
    QString GetIconName(QString Name);
    QPixmap GetIcon(QString fileName);

private:
    QtTreeWidget* ToolTreeWidget;  
    std::vector<ToolsPair> ToolNamesVec;
    std::list<QString> ToolNameList;

private:
    int LoadPlugins(QString str);
    void PopulateTree(QString str, QObject* pluginInterface, MainInterface* i);
};
