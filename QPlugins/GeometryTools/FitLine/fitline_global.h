#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FITLINE_LIB)
#  define FITLINE_EXPORT Q_DECL_EXPORT
# else
#  define FITLINE_EXPORT Q_DECL_IMPORT
# endif
#else
# define FITLINE_EXPORT
#endif
