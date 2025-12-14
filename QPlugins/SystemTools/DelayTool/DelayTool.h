#pragma once
#pragma execution_character_set("utf-8")

#include "delaytool_global.h"
#include "maininterface.h"
#include "qdialog.h"
#include "QToolBase.h"

class DELAYTOOL_EXPORT DelayTool
    : public QObject
    , public MainInterface
{
    Q_OBJECT
    Q_INTERFACES(MainInterface)
    Q_PLUGIN_METADATA(IID MainInterface_iid)

public:
    DelayTool();

    virtual QString name() override;
    virtual QString information() override;
};

extern "C" Q_DECL_EXPORT QDialog * showDialog(QString toolName, QToolBase * toolBase);
