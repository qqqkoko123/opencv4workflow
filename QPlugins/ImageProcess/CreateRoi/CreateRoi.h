#pragma once
#pragma execution_character_set("utf-8")

#include "createroi_global.h"
#include "maininterface.h"
#include "qdialog.h"
#include "QToolBase.h"

class CREATEROI_EXPORT CreateRoi
    : public QObject
    , public MainInterface
{
    Q_OBJECT
    Q_INTERFACES(MainInterface)
    Q_PLUGIN_METADATA(IID MainInterface_iid)

public:
    CreateRoi();

    virtual QString name() override;
    virtual QString information() override;
};

extern "C" Q_DECL_EXPORT QDialog * showDialog(QString toolName, QToolBase * toolBase);

extern "C" Q_DECL_EXPORT int ShowFormState();

extern "C" Q_DECL_EXPORT void SetFormState();
