#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(IMAGEVIEW_LIB)
#  define IMAGEVIEW_EXPORT Q_DECL_EXPORT
# else
#  define IMAGEVIEW_EXPORT Q_DECL_IMPORT
# endif
#else
# define IMAGEVIEW_EXPORT
#endif
