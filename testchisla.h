#ifndef TESTCHISLA_H
#define TESTCHISLA_H

#include "mainwindow.h"
#include <QObject>
#include <QtTest>

class TestChisla : public QObject
{
    Q_OBJECT

public:
    TestChisla() = default;
    ~TestChisla() = default;

private slots:
    void init();
    void testCalculations_data();
    void testCalculations();

private:
    MainWindow mw;
    Ui::MainWindow* ui() { return mw.ui; }
};

#endif // TESTCHISLA_H
