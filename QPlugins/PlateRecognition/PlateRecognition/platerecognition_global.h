#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PLATERECOGNITION_LIB)
#  define PLATERECOGNITION_EXPORT Q_DECL_EXPORT
# else
#  define PLATERECOGNITION_EXPORT Q_DECL_IMPORT
# endif
#else
# define PLATERECOGNITION_EXPORT
#endif
