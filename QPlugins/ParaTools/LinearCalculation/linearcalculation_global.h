#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LINEARCALCULATION_LIB)
#  define LINEARCALCULATION_EXPORT Q_DECL_EXPORT
# else
#  define LINEARCALCULATION_EXPORT Q_DECL_IMPORT
# endif
#else
# define LINEARCALCULATION_EXPORT
#endif
