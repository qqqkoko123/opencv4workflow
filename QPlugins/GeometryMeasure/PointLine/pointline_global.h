#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(POINTLINE_LIB)
#  define POINTLINE_EXPORT Q_DECL_EXPORT
# else
#  define POINTLINE_EXPORT Q_DECL_IMPORT
# endif
#else
# define POINTLINE_EXPORT
#endif
