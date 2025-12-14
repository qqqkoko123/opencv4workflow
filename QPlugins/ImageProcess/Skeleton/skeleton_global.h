#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SKELETON_LIB)
#  define SKELETON_EXPORT Q_DECL_EXPORT
# else
#  define SKELETON_EXPORT Q_DECL_IMPORT
# endif
#else
# define SKELETON_EXPORT
#endif
