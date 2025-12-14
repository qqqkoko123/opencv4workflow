#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(IMAGECLARITY_LIB)
#  define IMAGECLARITY_EXPORT Q_DECL_EXPORT
# else
#  define IMAGECLARITY_EXPORT Q_DECL_IMPORT
# endif
#else
# define IMAGECLARITY_EXPORT
#endif
