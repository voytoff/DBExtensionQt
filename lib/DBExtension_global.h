#ifndef DBEXTENSION_GLOBAL_H
#define DBEXTENSION_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QString>

#if defined(DBEXTENSION_LIBRARY)
#define DBEXTENSION_EXPORT Q_DECL_EXPORT
#else
#define DBEXTENSION_EXPORT Q_DECL_IMPORT
#endif

const QString Plugin = "QMARIADB"; // "QMYSQL"
const QString HostName = "127.0.0.1";
const int HostPort = 3306;
const QString DatabaseName = "106org";
const QString UserName = "root";
const QString Password = "1234";

#endif // DBEXTENSION_GLOBAL_H
