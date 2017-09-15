#ifndef DEVICEIO_GLOBAL_H
#define DEVICEIO_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QString>

#if defined(DEVICEIO_LIBRARY)
#  define DEVICEIOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DEVICEIOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DEVICEIO_GLOBAL_H
