#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DISTORTIONCALIBRATION_LIB)
#  define DISTORTIONCALIBRATION_EXPORT Q_DECL_EXPORT
# else
#  define DISTORTIONCALIBRATION_EXPORT Q_DECL_IMPORT
# endif
#else
# define DISTORTIONCALIBRATION_EXPORT
#endif
