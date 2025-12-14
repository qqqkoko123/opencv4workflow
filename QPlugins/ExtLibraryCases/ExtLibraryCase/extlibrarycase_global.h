#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(EXTLIBRARYCASE_LIB)
#  define EXTLIBRARYCASE_EXPORT Q_DECL_EXPORT
# else
#  define EXTLIBRARYCASE_EXPORT Q_DECL_IMPORT
# endif
#else
# define EXTLIBRARYCASE_EXPORT
#endif
