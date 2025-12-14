#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LOGICGOTO_LIB)
#  define LOGICGOTO_EXPORT Q_DECL_EXPORT
# else
#  define LOGICGOTO_EXPORT Q_DECL_IMPORT
# endif
#else
# define LOGICGOTO_EXPORT
#endif
