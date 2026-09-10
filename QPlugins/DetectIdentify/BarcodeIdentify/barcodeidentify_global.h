#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(BARCODEIDENTIFY_LIB)
#  define BARCODEIDENTIFY_EXPORT Q_DECL_EXPORT
# else
#  define BARCODEIDENTIFY_EXPORT Q_DECL_IMPORT
# endif
#else
# define BARCODEIDENTIFY_EXPORT
#endif
