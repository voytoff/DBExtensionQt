#ifndef DB_H
#define DB_H

#include "DBExtension_global.h"
#include "dbcrate.h"
#include "dbmodule.h"
#include <QObject>
#include <QList>
#include <QSqlDatabase>
#include <QSqlError>

class DBEXTENSION_EXPORT DB : public QObject {
  Q_OBJECT
public:
  explicit DB(const QString &hostName, QObject *parent = nullptr);
  explicit DB(const QString &connectionName, const QString &hostName, const int &hostPort, const QString &databaseName, const QString &userName, const QString &password, const int &timeout, QObject *parent = nullptr);
  static QSqlDatabase instance(const QString &connectionName);

private:
  QSqlDatabase db;
  void timeout(const int &sec);
  QString connectionName;

public slots:
  QSqlError lastError() const;
  bool open();
  void close();
  QList<dbCrate *> crates();
  dbCrate *crate(int id);
  QList<dbModule *> modules(int crate_id = 0);
  dbModule *module(int id);

signals:
};

#endif // DB_H
