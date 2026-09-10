#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SOCKETTCPCLIENT_LIB)
#  define SOCKETTCPCLIENT_EXPORT Q_DECL_EXPORT
# else
#  define SOCKETTCPCLIENT_EXPORT Q_DECL_IMPORT
# endif
#else
# define SOCKETTCPCLIENT_EXPORT
#endif
