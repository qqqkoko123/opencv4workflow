#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SOCKETTCPSERVER_LIB)
#  define SOCKETTCPSERVER_EXPORT Q_DECL_EXPORT
# else
#  define SOCKETTCPSERVER_EXPORT Q_DECL_IMPORT
# endif
#else
# define SOCKETTCPSERVER_EXPORT
#endif
