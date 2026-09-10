#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(COLORIDENTIFY_LIB)
#  define COLORIDENTIFY_EXPORT Q_DECL_EXPORT
# else
#  define COLORIDENTIFY_EXPORT Q_DECL_IMPORT
# endif
#else
# define COLORIDENTIFY_EXPORT
#endif
