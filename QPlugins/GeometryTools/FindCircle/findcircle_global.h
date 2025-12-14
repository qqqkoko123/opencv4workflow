#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FINDCIRCLE_LIB)
#  define FINDCIRCLE_EXPORT Q_DECL_EXPORT
# else
#  define FINDCIRCLE_EXPORT Q_DECL_IMPORT
# endif
#else
# define FINDCIRCLE_EXPORT
#endif
