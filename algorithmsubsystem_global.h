#ifndef ALGORITHMSUBSYSTEM_GLOBAL_H
#define ALGORITHMSUBSYSTEM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ALGORITHMSUBSYSTEM_LIBRARY)
#  define ALGORITHMSUBSYSTEMSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ALGORITHMSUBSYSTEMSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ALGORITHMSUBSYSTEM_GLOBAL_H
