#ifndef DBCORE_H
#define DBCORE_H

#include "DBExtension_global.h"
#include <QSqlQuery>
#include <QObject>

class DBEXTENSION_EXPORT dbCore {
public:
  // Общие ресурсы
  int id;
  QString name;

protected:
  dbCore(QSqlQuery *query = nullptr);
  QSqlQuery *query;
  virtual void load() = 0;

public :
  void init();
  template<typename T, typename... Args>
  static std::unique_ptr<T> create(Args&&... args) {
    auto instance = std::make_unique<T>(std::forward<Args>(args)...);
    instance->init();
    return instance;
  }

};

#endif // DBCORE_H
