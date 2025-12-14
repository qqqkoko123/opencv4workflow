#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CAMSHIFTTRACK_LIB)
#  define CAMSHIFTTRACK_EXPORT Q_DECL_EXPORT
# else
#  define CAMSHIFTTRACK_EXPORT Q_DECL_IMPORT
# endif
#else
# define CAMSHIFTTRACK_EXPORT
#endif
