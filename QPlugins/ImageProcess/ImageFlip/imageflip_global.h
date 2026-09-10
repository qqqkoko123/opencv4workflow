#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(IMAGEFLIP_LIB)
#  define IMAGEFLIP_EXPORT Q_DECL_EXPORT
# else
#  define IMAGEFLIP_EXPORT Q_DECL_IMPORT
# endif
#else
# define IMAGEFLIP_EXPORT
#endif
