#pragma once

#include <QtTest/QtTest>
#include "stackmachine.h"
#include <sstream>

class StackMachineTest : public QObject
{
    Q_OBJECT
private slots:
    void testNumber()
    {
        std::stringstream src("8");
        QCOMPARE(machine.calculate(src), 8.0);
    }

    void testSimpleIntExpression()
    {
        std::stringstream src("9 8 *");
        QCOMPARE(machine.calculate(src), 72.0);
    }

    void testSimpleDoubleExpression()
    {
        std::stringstream src("9.5 1 -");
        QCOMPARE(machine.calculate(src), 8.5);
    }

    void testComplexExpression()
    {
        std::stringstream src("3.3 9 10 * 2.7 + - 30.2 * 20 4 + /");
        QCOMPARE(machine.calculate(src), -112.495);
    }

    void testDivizionByZero()
    {
        std::stringstream src("4 0 /");
        try
        {
            machine.calculate(src);
            QFAIL("Division by zero");
        }
        catch (DivisionByZeroException) 
        {}
    }

    void testNotEnoughOperations()
    {
        std::stringstream src("8 3");
        try
        {
            machine.calculate(src);
            QFAIL("Incorrect input");
        }
        catch (IncorrectInputException)
        {}
    }

    void testTooManyOperations()
    {
        std::stringstream src("9 3 + 4 - / 3");
        try
        {
            machine.calculate(src);
            QFAIL("Incorrect input");
        }
        catch (IncorrectInputException)
        {}
    }
private:
    StackMachine machine;
};
