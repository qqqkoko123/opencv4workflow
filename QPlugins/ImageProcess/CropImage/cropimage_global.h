#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CROPIMAGE_LIB)
#  define CROPIMAGE_EXPORT Q_DECL_EXPORT
# else
#  define CROPIMAGE_EXPORT Q_DECL_IMPORT
# endif
#else
# define CROPIMAGE_EXPORT
#endif
