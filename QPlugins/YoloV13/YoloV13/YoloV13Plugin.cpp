#include "YoloV13.h"
#include "YoloV13Plugin.h"

#include <QtCore/QtPlugin>

YoloV13Plugin::YoloV13Plugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}
void YoloV13Plugin::initialize(QDesignerFormEditorInterface * /*core*/)
{
    if (initialized)
        return;

    initialized = true;
}

bool YoloV13Plugin::isInitialized() const
{
    return initialized;
}

QWidget *YoloV13Plugin::createWidget(QWidget *parent)
{
    return new YoloV13(parent);
}

QString YoloV13Plugin::name() const
{
    return "YoloV13";
}

QString YoloV13Plugin::group() const
{
    return "My Plugins";
}

QIcon YoloV13Plugin::icon() const
{
    return QIcon();
}

QString YoloV13Plugin::toolTip() const
{
    return QString();
}

QString YoloV13Plugin::whatsThis() const
{
    return QString();
}


bool YoloV13Plugin::isContainer() const
{
    return false;
}

QString YoloV13Plugin::domXml() const
{
    return "<widget class=\"YoloV13\" name=\"YoloV13\">\n"
        " <property name=\"geometry\">\n"
        "  <rect>\n"
        "   <x>0</x>\n"
        "   <y>0</y>\n"
        "   <width>100</width>\n"
        "   <height>100</height>\n"
        "  </rect>\n"
        " </property>\n"
        "</widget>\n";
}

QString YoloV13Plugin::includeFile() const
{
    return "YoloV13.h";
}
