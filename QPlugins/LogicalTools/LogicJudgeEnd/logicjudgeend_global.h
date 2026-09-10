#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LOGICJUDGEEND_LIB)
#  define LOGICJUDGEEND_EXPORT Q_DECL_EXPORT
# else
#  define LOGICJUDGEEND_EXPORT Q_DECL_IMPORT
# endif
#else
# define LOGICJUDGEEND_EXPORT
#endif
