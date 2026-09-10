#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(GETCONTOURPOINTS_LIB)
#  define GETCONTOURPOINTS_EXPORT Q_DECL_EXPORT
# else
#  define GETCONTOURPOINTS_EXPORT Q_DECL_IMPORT
# endif
#else
# define GETCONTOURPOINTS_EXPORT
#endif
