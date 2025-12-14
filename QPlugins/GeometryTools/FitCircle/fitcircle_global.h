#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FITCIRCLE_LIB)
#  define FITCIRCLE_EXPORT Q_DECL_EXPORT
# else
#  define FITCIRCLE_EXPORT Q_DECL_IMPORT
# endif
#else
# define FITCIRCLE_EXPORT
#endif
