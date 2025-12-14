#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FINDLINE_LIB)
#  define FINDLINE_EXPORT Q_DECL_EXPORT
# else
#  define FINDLINE_EXPORT Q_DECL_IMPORT
# endif
#else
# define FINDLINE_EXPORT
#endif
