#include "dbexperiment.h"

dbExperiment::dbExperiment(QSqlQuery *query)
  : dbCore{query} {}

void dbExperiment::load() {
}
