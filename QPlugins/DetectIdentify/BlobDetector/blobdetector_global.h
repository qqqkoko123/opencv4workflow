#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(BLOBDETECTOR_LIB)
#  define BLOBDETECTOR_EXPORT Q_DECL_EXPORT
# else
#  define BLOBDETECTOR_EXPORT Q_DECL_IMPORT
# endif
#else
# define BLOBDETECTOR_EXPORT
#endif
