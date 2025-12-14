#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(BRIGHTNESS_LIB)
#  define BRIGHTNESS_EXPORT Q_DECL_EXPORT
# else
#  define BRIGHTNESS_EXPORT Q_DECL_IMPORT
# endif
#else
# define BRIGHTNESS_EXPORT
#endif
