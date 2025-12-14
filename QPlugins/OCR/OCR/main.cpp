#include "OCR.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    OCR window;
    window.show();
    return app.exec();
}
