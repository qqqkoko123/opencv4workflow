#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(YOLOV13_LIB)
#  define YoloV13_EXPORT Q_DECL_EXPORT
# else
#  define YoloV13_EXPORT Q_DECL_IMPORT
# endif
#else
# define YoloV13_EXPORT
#endif
