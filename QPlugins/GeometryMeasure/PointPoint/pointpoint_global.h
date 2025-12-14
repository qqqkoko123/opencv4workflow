#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(POINTPOINT_LIB)
#  define POINTPOINT_EXPORT Q_DECL_EXPORT
# else
#  define POINTPOINT_EXPORT Q_DECL_IMPORT
# endif
#else
# define POINTPOINT_EXPORT
#endif
