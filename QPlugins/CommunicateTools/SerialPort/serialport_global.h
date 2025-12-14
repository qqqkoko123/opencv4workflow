#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SERIALPORT_LIB)
#  define SERIALPORT_EXPORT Q_DECL_EXPORT
# else
#  define SERIALPORT_EXPORT Q_DECL_IMPORT
# endif
#else
# define SERIALPORT_EXPORT
#endif
