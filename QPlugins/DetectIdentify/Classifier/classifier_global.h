#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(Z_CLASSIFIER_LIB)
#  define Z_CLASSIFIER_EXPORT Q_DECL_EXPORT
# else
#  define Z_CLASSIFIER_EXPORT Q_DECL_IMPORT
# endif
#else
# define Z_CLASSIFIER_EXPORT
#endif
