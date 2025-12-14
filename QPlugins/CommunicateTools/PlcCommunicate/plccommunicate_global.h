#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PLCCOMMUNICATE_LIB)
#  define PLCCOMMUNICATE_EXPORT Q_DECL_EXPORT
# else
#  define PLCCOMMUNICATE_EXPORT Q_DECL_IMPORT
# endif
#else
# define PLCCOMMUNICATE_EXPORT
#endif
