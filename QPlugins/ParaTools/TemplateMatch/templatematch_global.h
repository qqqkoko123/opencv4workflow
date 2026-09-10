#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TEMPLATEMATCH_LIB)
#  define TEMPLATEMATCH_EXPORT Q_DECL_EXPORT
# else
#  define TEMPLATEMATCH_EXPORT Q_DECL_IMPORT
# endif
#else
# define TEMPLATEMATCH_EXPORT
#endif
