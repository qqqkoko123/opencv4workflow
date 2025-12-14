#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FITELLIPSE_LIB)
#  define FITELLIPSE_EXPORT Q_DECL_EXPORT
# else
#  define FITELLIPSE_EXPORT Q_DECL_IMPORT
# endif
#else
# define FITELLIPSE_EXPORT
#endif
