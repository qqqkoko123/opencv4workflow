#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DELAYTOOL_LIB)
#  define DELAYTOOL_EXPORT Q_DECL_EXPORT
# else
#  define DELAYTOOL_EXPORT Q_DECL_IMPORT
# endif
#else
# define DELAYTOOL_EXPORT
#endif
