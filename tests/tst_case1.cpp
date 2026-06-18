#include <QTest>
#include <QCoreApplication>
#include <QSqlDatabase>
#include "db.h"

class case1 : public QObject
{
  Q_OBJECT

public:
  case1();
  ~case1() override;

private slots:
  void test_case1();
};

case1::case1() {}

case1::~case1() = default;

void case1::test_case1() {
  int argc;
  QCoreApplication app(argc, nullptr);
  qDebug() << "Available drivers:" << QSqlDatabase::drivers();

  DB db;
  if (db.open()) {
    auto l1 = db.crates();
    auto id = l1.at(0)->id;
    auto name = db.crate(id)->name;
    qDebug() << name;
    auto modules = db.modules(id);
    qDebug() << modules;
  } else {
    qDebug() << db.lastError();
  }
}

QTEST_APPLESS_MAIN(case1)

#include "tst_case1.moc"
