#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(IMAGEREPAIR_LIB)
#  define IMAGEREPAIR_EXPORT Q_DECL_EXPORT
# else
#  define IMAGEREPAIR_EXPORT Q_DECL_IMPORT
# endif
#else
# define IMAGEREPAIR_EXPORT
#endif
