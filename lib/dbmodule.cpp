#include "dbmodule.h"

dbModule::dbModule(QSqlQuery *query)
  : dbCore{query} {}

void dbModule::load() {
}
