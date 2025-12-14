#pragma once
#pragma execution_character_set("utf-8")

#include "extlibrarycase_global.h"
#include "maininterface.h"
#include "qdialog.h"
#include "QToolBase.h"

class EXTLIBRARYCASE_EXPORT ExtLibraryCase
    : public QObject
    , public MainInterface
{
    Q_OBJECT
    Q_INTERFACES(MainInterface)
    Q_PLUGIN_METADATA(IID MainInterface_iid)

public:
    ExtLibraryCase();    
};

extern "C" Q_DECL_EXPORT QDialog * showDialog(QString toolName, QToolBase * toolBase);
