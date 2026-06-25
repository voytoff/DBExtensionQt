#ifndef DBEXPERIMENT_H
#define DBEXPERIMENT_H

#include "DBExtension_global.h"
#include "dbcore.h"

class DBEXTENSION_EXPORT dbExperiment : public dbCore {
public:
  dbExperiment(QSqlQuery *query = nullptr);

protected:
  void load() override;
};

#endif // DBEXPERIMENT_H
