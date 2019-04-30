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
    void testRemoveNextCycleTrue();
    void testRemoveNextCycleFalse();
    void testRemoveNextCycleValues();

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

void RainflowTests::testRemoveNextCycleTrue()
{
    std::vector<double> values{2,5,3,6,2,4,1,6,1,4,1,5,3,6,3,6,1,5,2};
    QVERIFY(rfCounter.RemoveNextCycle(values) == true);
}

void RainflowTests::testRemoveNextCycleFalse()
{
    std::vector<double> values{2,6,1,5,2};
    QVERIFY(rfCounter.RemoveNextCycle(values) == false);
}

void RainflowTests::testRemoveNextCycleValues()
{
    std::vector<double> values{2,5,3,6,2,4,1,6,1,4,1,5,3,6,3,6,1,5,2};
    std::vector<double> valuesCycleRemoved{2,6,2,4,1,6,1,4,1,5,3,6,3,6,1,5,2};
    rfCounter.RemoveNextCycle(values);
    QCOMPARE(values,valuesCycleRemoved);
}
QTEST_MAIN(RainflowTests)
#include "tst_rainflowtests.moc"
