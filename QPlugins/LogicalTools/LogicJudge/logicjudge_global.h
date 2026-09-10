#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LOGICJUDGE_LIB)
#  define LOGICJUDGE_EXPORT Q_DECL_EXPORT
# else
#  define LOGICJUDGE_EXPORT Q_DECL_IMPORT
# endif
#else
# define LOGICJUDGE_EXPORT
#endif
