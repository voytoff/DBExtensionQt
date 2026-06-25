#include "db.h"
#include "DBExtension_global.h"
#include <QSqlQuery>

DB::DB(const QString &connectionName, QObject *parent)
  : DB(connectionName, HostName, HostPort, DatabaseName, UserName, Password, 5) {}

DB::DB(const QString &connectionName,
       const QString &hostName,
       const int &hostPort,
       const QString &databaseName,
       const QString &userName,
       const QString &password,
       const int &timeout,
       QObject *parent)
  : QObject{parent}
  , connectionName(connectionName) {

  db = QSqlDatabase::addDatabase(Plugin, connectionName);
  db.setHostName(hostName);
  db.setPort(hostPort);
  db.setDatabaseName(databaseName);
  db.setUserName(userName);
  db.setPassword(password);
  this->timeout(timeout);
}

void DB::timeout(const int & sec) {
  db.setConnectOptions(QString("MYSQL_OPT_CONNECT_TIMEOUT=%1").arg(sec));
}

QSqlDatabase DB::instance(const QString &connectionName) {
  return QSqlDatabase::database(connectionName);
}

QSqlError DB::lastError() const {
  return db.lastError();
}

bool DB::open() {
  return db.open();
}

void DB::close() {
  if (db.isOpen())
    db.close();
}

dbCrate *DB::crate(int id) {
  auto query = new QSqlQuery();
  // Подготавливаем запрос
  query->prepare("SELECT * FROM crate WHERE id=:id");
  query->bindValue(":id", id);

  if (!query->exec()) return nullptr;
  if (query->next()) {
    auto p = new dbCrate(query);
    p->init();
    return p;
  }

  return nullptr;
}

QList<dbCrate*> DB::crates() {
  auto query = new QSqlQuery();
  // Подготавливаем запрос
  query->prepare("SELECT * FROM crate");

  if (!query->exec()) return {};
  QList<dbCrate*> result;
  // Построчно читаем результаты
  while (query->next()) {
    auto p = new dbCrate(query);
    p->init();
    result.append(p);
  }

  return result;
}

dbModule *DB::module(int id) {
  QSqlQuery query;
  // Подготавливаем запрос
  query.prepare("SELECT * FROM module WHERE id=:id");
  query.bindValue(":id", id);

  if (!query.exec()) return nullptr;
  if (query.next()) {
    auto p = new dbModule(&query);
    p->init();
    return p;
  }

  return nullptr;
}

QList<dbModule*> DB::modules(int crate_id) {
  QSqlQuery query;
  // Подготавливаем запрос
  QString sql("SELECT * FROM module");
  if (crate_id > 0)
    sql.append(" WHERE crate_id=:crate_id");
  query.prepare(sql);
  if (crate_id > 0)
    query.bindValue(":crate_id", crate_id);

  if (!query.exec()) return {};
  QList<dbModule*> result;
  // Построчно читаем результаты
  while (query.next()) {
    auto p = new dbModule(&query);
    p->init();
    result.append(p);
  }

  return result;
}

