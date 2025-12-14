#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SCRIPTEDIT_LIB)
#  define SCRIPTEDIT_EXPORT Q_DECL_EXPORT
# else
#  define SCRIPTEDIT_EXPORT Q_DECL_IMPORT
# endif
#else
# define SCRIPTEDIT_EXPORT
#endif
