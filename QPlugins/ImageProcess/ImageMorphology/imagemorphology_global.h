#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(IMAGEMORPHOLOGY_LIB)
#  define IMAGEMORPHOLOGY_EXPORT Q_DECL_EXPORT
# else
#  define IMAGEMORPHOLOGY_EXPORT Q_DECL_IMPORT
# endif
#else
# define IMAGEMORPHOLOGY_EXPORT
#endif
