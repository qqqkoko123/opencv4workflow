#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(GENERALIO_LIB)
#  define GENERALIO_EXPORT Q_DECL_EXPORT
# else
#  define GENERALIO_EXPORT Q_DECL_IMPORT
# endif
#else
# define GENERALIO_EXPORT
#endif
