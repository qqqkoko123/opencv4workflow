#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SHAPEMATCH_LIB)
#  define SHAPEMATCH_EXPORT Q_DECL_EXPORT
# else
#  define SHAPEMATCH_EXPORT Q_DECL_IMPORT
# endif
#else
# define SHAPEMATCH_EXPORT
#endif
