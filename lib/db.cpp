#include "db.h"
#include "DBExtension_global.h"
#include <QSqlQuery>

DB::DB(QObject *parent)
  : QObject{parent} {
  db = QSqlDatabase::addDatabase(Plugin);
  db.setHostName(HostName);
  db.setPort(HostPort);
  db.setDatabaseName(DatabaseName);
  db.setUserName(UserName);
  db.setPassword(Password);
}

DB::DB(const QString &hostName, const int &hostPort, const QString &databaseName, const QString &userName, const QString &password, QObject *parent) {
  db = QSqlDatabase::addDatabase(Plugin);
  db.setHostName(hostName);
  db.setPort(hostPort);
  db.setDatabaseName(databaseName);
  db.setUserName(userName);
  db.setPassword(password);
}

bool DB::open() {
  return db.open();
}

QString DB::crate(int id) {
  QSqlQuery query;
  // Подготавливаем запрос
  query.prepare("SELECT id,name FROM crate WHERE id=:id");
  query.bindValue(":id", id);

  if (!query.exec()) return nullptr;

  // Построчно читаем результаты
  if (query.next()) return query.value("name").toString();
  return nullptr;
}

QSqlError DB::lastError() const {
  return db.lastError();
}
