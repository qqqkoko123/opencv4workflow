#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(EXPORTCSV_LIB)
#  define EXPORTCSV_EXPORT Q_DECL_EXPORT
# else
#  define EXPORTCSV_EXPORT Q_DECL_IMPORT
# endif
#else
# define EXPORTCSV_EXPORT
#endif
