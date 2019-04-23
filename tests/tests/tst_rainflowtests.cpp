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
    void testBoundedByExtremetiesTrue();
    void testBoundedByExtremetiesFalse();
    void testIsCycle4PointsMethodFalse();
    void testIsCycle4PointsMethodTrue();

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

void RainflowTests::testBoundedByExtremetiesTrue()
{
    QVERIFY(rfCounter.BoundedByExtremeties(1,4,6,9) == true);
}

void RainflowTests::testBoundedByExtremetiesFalse()
{
    QVERIFY(rfCounter.BoundedByExtremeties(5,4,6,9) == false);
}

void RainflowTests::testIsCycle4PointsMethodTrue()
{
    QVERIFY(rfCounter.IsCycle4PointsMethod(2,5,3,6) == true);
}

void RainflowTests::testIsCycle4PointsMethodFalse()
{
    QVERIFY(rfCounter.IsCycle4PointsMethod(2,5,0,6) == false);
}
QTEST_MAIN(RainflowTests)
#include "tst_rainflowtests.moc"
