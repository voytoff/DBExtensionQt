#include <QTest>

// add necessary includes here

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

}

QTEST_APPLESS_MAIN(case1)

#include "tst_case1.moc"
