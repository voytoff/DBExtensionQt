#include "dbcore.h"

dbCore::dbCore(QSqlQuery *query)
  : query(query) {}

void dbCore::init() {
  if (query) {
    id = query->value("id").toInt();
    name = query->value("name").toString();
    load();
  }
}

