#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(IMAGEROTATE_LIB)
#  define IMAGEROTATE_EXPORT Q_DECL_EXPORT
# else
#  define IMAGEROTATE_EXPORT Q_DECL_IMPORT
# endif
#else
# define IMAGEROTATE_EXPORT
#endif
