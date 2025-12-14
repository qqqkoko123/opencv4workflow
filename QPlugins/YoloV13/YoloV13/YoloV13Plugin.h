#pragma once

#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#include "./QToolBase.h"

class YoloV13Plugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface" FILE "yolov13plugin.json")
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    explicit YoloV13Plugin(QObject *parent = nullptr);
    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget* parent) override;
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool initialized;
};
