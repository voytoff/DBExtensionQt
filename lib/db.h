#ifndef DB_H
#define DB_H

#include "DBExtension_global.h"
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>

class DBEXTENSION_EXPORT DB : public QObject {
  Q_OBJECT
public:
  explicit DB(QObject *parent = nullptr);

private:
  QSqlDatabase db;

public slots:
  bool open();
  QString crate(int id);
  QSqlError lastError() const;

signals:
};

#endif // DB_H
