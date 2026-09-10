#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PERSPECTIVETRANSFORM_LIB)
#  define PERSPECTIVETRANSFORM_EXPORT Q_DECL_EXPORT
# else
#  define PERSPECTIVETRANSFORM_EXPORT Q_DECL_IMPORT
# endif
#else
# define PERSPECTIVETRANSFORM_EXPORT
#endif
