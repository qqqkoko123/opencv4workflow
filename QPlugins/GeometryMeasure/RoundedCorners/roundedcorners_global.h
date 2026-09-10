#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ROUNDEDCORNERS_LIB)
#  define ROUNDEDCORNERS_EXPORT Q_DECL_EXPORT
# else
#  define ROUNDEDCORNERS_EXPORT Q_DECL_IMPORT
# endif
#else
# define ROUNDEDCORNERS_EXPORT
#endif
