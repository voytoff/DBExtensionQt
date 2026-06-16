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
    auto name = db.crate(1);
    qDebug() << name;
  } else {
    qDebug() << db.lastError();
  }
}

QTEST_APPLESS_MAIN(case1)

#include "tst_case1.moc"
