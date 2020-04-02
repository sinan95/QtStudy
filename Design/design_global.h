#ifndef DESIGN_GLOBAL_H
#define DESIGN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DESIGN_LIBRARY)
#  define DESIGNSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DESIGNSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DESIGN_GLOBAL_H
