#pragma once

#include <QtTest/QtTest>
#include <sstream>
#include <string>
#include "expression.h"

class ExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void testSimpleExpression()
    {
        std::string expr("(+ 2 3)");
        std::stringstream in("(+ 2 3)");
        std::stringstream out;

        Expression expression(in);
        expression.print(out);

        QCOMPARE(out.str(), expr);
        QCOMPARE(expression.calculate(), 5);
    }

    void testWhiteSpacesSkip()
    {
        std::string expr("(+ 2 3)");
        std::stringstream in("(   +\t 2\n\t3      )   \n\t");
        std::stringstream out;
        Expression expression(in);
        expression.print(out);
        QCOMPARE(out.str(), expr);
        QCOMPARE(expression.calculate(), 5);
    }

    void testComplexExpression()
    {
        std::string expr("(+ (* (- 2 3) (/ 8 3)) (- 38 (+ 5 6)))");
        std::stringstream in("(+ (* (- 2 3) (/ 8 3)) (- 38 (+ 5 6)))");
        std::stringstream out;
        Expression expression(in);
        expression.print(out);
        QCOMPARE(out.str(), expr);
        QCOMPARE(expression.calculate(), 25);
    }

    void testDivisionByZero()
    {
        std::string expr("(/ 9 0)");
        std::stringstream in("( / 9 0 )");
        std::stringstream out;
        Expression expression(in);
        try
        {
            expression.calculate();
            QFAIL("Division by zero");
        }
        catch (DivisionByZeroException)
        {}
    }

    void testInvalidOperation()
    {
        std::stringstream in("(& 9 0)");
        std::stringstream out;
        try
        {
            Expression expression(in);
            QFAIL("Invalid operation");
        }
        catch (InvalidOperationException)
        {}
    } 

    void testInvalidArgument()
    {
        std::stringstream in("(+ 9 abdf)");
        std::stringstream out;
        try
        {
            Expression expression(in);
            QFAIL("Invalid argument");
        }
        catch (InvalidArgumentException)
        {}
    } 
};

