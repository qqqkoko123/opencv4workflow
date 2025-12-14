#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(MEASURECALIBRATION_LIB)
#  define MEASURECALIBRATION_EXPORT Q_DECL_EXPORT
# else
#  define MEASURECALIBRATION_EXPORT Q_DECL_IMPORT
# endif
#else
# define MEASURECALIBRATION_EXPORT
#endif
