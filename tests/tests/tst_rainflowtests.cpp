#include <QString>
#include <QtTest>
#include "../../src/rainflowcounter.h"
class RainflowTests : public QObject
{
    Q_OBJECT

public:
    RainflowTests();

private Q_SLOTS:
    void testKeepPeaksAndValleys();

private:
    RainflowCounter rfCounter;
};

RainflowTests::RainflowTests()
{
}

void RainflowTests::testKeepPeaksAndValleys()
{
    std::vector<double> testValues{1,2,3,4,3,2,1};
    std::vector<double> expectedValues{1,4,1};
    rfCounter.KeepPeaksAndValleys(testValues);

    QVERIFY(testValues==expectedValues);
}

QTEST_MAIN(RainflowTests)
#include "tst_rainflowtests.moc"
