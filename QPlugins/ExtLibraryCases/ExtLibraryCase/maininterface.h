#pragma once

#include <qstring.h>
#include <QtPlugin>

class MainInterface
{
public:
    virtual ~MainInterface(){}       
};

#define MainInterface_iid "com.Interface.MainInterface"
Q_DECLARE_INTERFACE(MainInterface, MainInterface_iid)

