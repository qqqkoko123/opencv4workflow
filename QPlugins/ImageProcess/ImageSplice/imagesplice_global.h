#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(IMAGESPLICE_LIB)
#  define IMAGESPLICE_EXPORT Q_DECL_EXPORT
# else
#  define IMAGESPLICE_EXPORT Q_DECL_IMPORT
# endif
#else
# define IMAGESPLICE_EXPORT
#endif
