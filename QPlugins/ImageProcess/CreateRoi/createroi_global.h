#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CREATEROI_LIB)
#  define CREATEROI_EXPORT Q_DECL_EXPORT
# else
#  define CREATEROI_EXPORT Q_DECL_IMPORT
# endif
#else
# define CREATEROI_EXPORT
#endif
