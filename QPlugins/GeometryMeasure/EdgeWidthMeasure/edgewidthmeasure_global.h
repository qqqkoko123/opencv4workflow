#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(Z_EDGEWIDTHMEASURE_LIB)
#  define Z_EDGEWIDTHMEASURE_EXPORT Q_DECL_EXPORT
# else
#  define Z_EDGEWIDTHMEASURE_EXPORT Q_DECL_IMPORT
# endif
#else
# define Z_EDGEWIDTHMEASURE_EXPORT
#endif
