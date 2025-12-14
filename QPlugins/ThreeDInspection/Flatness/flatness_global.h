#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(FLATNESS_LIB)
#  define FLATNESS_EXPORT Q_DECL_EXPORT
# else
#  define FLATNESS_EXPORT Q_DECL_IMPORT
# endif
#else
# define FLATNESS_EXPORT
#endif
