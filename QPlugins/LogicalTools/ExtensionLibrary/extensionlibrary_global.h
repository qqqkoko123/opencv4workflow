#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(EXTENSIONLIBRARY_LIB)
#  define EXTENSIONLIBRARY_EXPORT Q_DECL_EXPORT
# else
#  define EXTENSIONLIBRARY_EXPORT Q_DECL_IMPORT
# endif
#else
# define EXTENSIONLIBRARY_EXPORT
#endif
