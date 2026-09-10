#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QRCODEIDENTIFY_LIB)
#  define QRCODEIDENTIFY_EXPORT Q_DECL_EXPORT
# else
#  define QRCODEIDENTIFY_EXPORT Q_DECL_IMPORT
# endif
#else
# define QRCODEIDENTIFY_EXPORT
#endif
