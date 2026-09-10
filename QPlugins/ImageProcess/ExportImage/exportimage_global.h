#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(Z_EXPORTIMAGE_LIB)
#  define Z_EXPORTIMAGE_EXPORT Q_DECL_EXPORT
# else
#  define Z_EXPORTIMAGE_EXPORT Q_DECL_IMPORT
# endif
#else
# define Z_EXPORTIMAGE_EXPORT
#endif
