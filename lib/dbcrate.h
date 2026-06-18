#ifndef DBCRATE_H
#define DBCRATE_H

#include <QObject>
#include <QString>
#include "DBExtension_global.h"
#include "dbcore.h"

class DBEXTENSION_EXPORT dbCrate : public dbCore {
public:
  dbCrate(QSqlQuery *query = nullptr);

protected:
  void load() override;

};

#endif // DBCRATE_H
