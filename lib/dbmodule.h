#ifndef DBMODULE_H
#define DBMODULE_H

#include "DBExtension_global.h"
#include "dbcore.h"

class DBEXTENSION_EXPORT dbModule : public dbCore {
public:
  dbModule(QSqlQuery *query = nullptr);

protected:
  void load() override;

};

#endif // DBMODULE_H
