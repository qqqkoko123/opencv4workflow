#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LINELINEI_LIB)
#  define LINELINEI_EXPORT Q_DECL_EXPORT
# else
#  define LINELINEI_EXPORT Q_DECL_IMPORT
# endif
#else
# define LINELINEI_EXPORT
#endif
