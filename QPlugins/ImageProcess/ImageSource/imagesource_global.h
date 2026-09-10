#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(A_IMAGESOURCE_LIB)
#  define A_IMAGESOURCE_EXPORT Q_DECL_EXPORT
# else
#  define A_IMAGESOURCE_EXPORT Q_DECL_IMPORT
# endif
#else
# define A_IMAGESOURCE_EXPORT
#endif
