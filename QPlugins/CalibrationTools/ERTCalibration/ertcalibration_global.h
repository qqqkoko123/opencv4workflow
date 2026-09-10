#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ERTCALIBRATION_LIB)
#  define ERTCALIBRATION_EXPORT Q_DECL_EXPORT
# else
#  define ERTCALIBRATION_EXPORT Q_DECL_IMPORT
# endif
#else
# define ERTCALIBRATION_EXPORT
#endif
