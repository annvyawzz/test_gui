#include "testchisla.h"
#include "ui_mainwindow.h"

void TestChisla::init()
{
    ui()->num1->clear();
    ui()->num2->clear();
    ui()->answer->clear();
    ui()->options->setCurrentIndex(0);
    ui()->num2->show();
}

void TestChisla::testCalculations_data()
{
    QTest::addColumn<int>("optionIndex");
    QTest::addColumn<QString>("num1");
    QTest::addColumn<QString>("num2");
    QTest::addColumn<QString>("expected");

    QTest::newRow("GCD")  << 0 << "4" << "14" << "2";
    QTest::newRow("GCD1")  << 0 << ""   << "14" << "Error";
    QTest::newRow("GCD2")  << 0 << "4" << ""   << "Error";
    QTest::newRow("GCD3") << 0 << ""   << ""   << "Error";

    QTest::newRow("LCM")   << 1 << "21" << "6" << "42";
    QTest::newRow("LCM1")   << 1 << "21" << ""  << "Error";

    QTest::newRow("IsPrime") << 2 << "13" << "" << "True";
    QTest::newRow("IsPrime1") << 2 << "12" << "" << "False";
    QTest::newRow("IsPrime2")  << 2 << "1"  << "" << "False";

    QTest::newRow("IsArmstrong") << 3 << "153" << "" << "True";
    QTest::newRow("IsArmstrong1")<< 3 << "154" << "" << "False";
    QTest::newRow("IsArmstrong2") << 3 << "0"   << "" << "True";
}

void TestChisla::testCalculations()
{
    QFETCH(int, optionIndex);
    QFETCH(QString, num1);
    QFETCH(QString, num2);
    QFETCH(QString, expected);

    ui()->options->setCurrentIndex(optionIndex);
    ui()->num1->setText(num1);
    ui()->num2->setText(num2);
    QTest::mouseClick(ui()->solve, Qt::LeftButton);

    QTest::qWait(100);
    QCOMPARE(ui()->answer->text(), expected);
}


QTEST_MAIN(TestChisla)
