#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LINECIRCLE_LIB)
#  define LINECIRCLE_EXPORT Q_DECL_EXPORT
# else
#  define LINECIRCLE_EXPORT Q_DECL_IMPORT
# endif
#else
# define LINECIRCLE_EXPORT
#endif
