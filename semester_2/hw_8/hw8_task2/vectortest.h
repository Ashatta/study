#pragma once

#include <QtTest/QtTest>
#include <sstream>
#include <string>
#include "vector.h"

class VectorTest : public QObject
{
    Q_OBJECT
private slots:
    void testDefaultConstructor()
    {
        Vector<int, 10> v;
        QVERIFY(v.isNull());
    }

    void testInitializingWithScalar()
    {
        Vector<int, 10> v(7);
        std::stringstream out;
        std::string vec("7 0 0 0 0 0 0 0 0 0 \n");
        v.print(out);
        QCOMPARE(out.str(), vec);
    }

    void testIsNull()
    {
        Vector<int, 10> v(9);
        QVERIFY(!v.isNull());
    }

    void testInitializingWithArrayOfSameSize()
    {
        int array[10];
        for (int i = 0; i < 10; i++)
            array[i] = i;
        Vector<int, 10> v(array, 10);
        std::stringstream out;
        std::string vec("0 1 2 3 4 5 6 7 8 9 \n");
        v.print(out);
        QCOMPARE(out.str(), vec);
    }

    void testInitializingWithArrayOfLesserSize()
    {
        int array[10];
        for (int i = 0; i < 10; i++)
            array[i] = i;
        Vector<int, 10> v(array, 6);
        std::stringstream out;
        std::string vec("0 1 2 3 4 5 0 0 0 0 \n");
        v.print(out);
        QCOMPARE(out.str(), vec);
    }

    void testINitializingWithArrayOfGreaterSize()
    {
        int array[20];
        for (int i = 0; i < 20; i++)
            array[20 - i - 1] = i;
        Vector<int, 10> v(array, 20);
        std::stringstream out;
        std::string vec("19 18 17 16 15 14 13 12 11 10 \n");
        v.print(out);
        QCOMPARE(out.str(), vec);
    }

    void testAdd()
    {
        int ar1[10];
        int ar2[10];
        for (int i = 0; i < 10; i++)
        {
            ar1[i] = i;
            ar2[i] = 10 - i;
        }
        Vector<int, 10> v(ar1, 10);
        Vector<int, 10> u(ar2, 10);
        Vector<int, 10> w = v.add(u);
        std::stringstream out;
        std::string vec("10 10 10 10 10 10 10 10 10 10 \n");
        w.print(out);
        QCOMPARE(out.str(), vec);
    }        

    void testSubtract()
    {
        int ar1[10];
        int ar2[10];
        for (int i = 0; i < 10; i++)
        {
            ar1[i] = i;
            ar2[i] = 20 + i;
        }
        Vector<int, 10> v(ar1, 10);
        Vector<int, 10> u(ar2, 10);
        Vector<int, 10> w = u.subtract(v);
        std::stringstream out;
        std::string vec("20 20 20 20 20 20 20 20 20 20 \n");
        w.print(out);
        QCOMPARE(out.str(), vec);
    }        

    void testScalarMultiply()
    {
        const int v1[] = { 3, 1, -2};
        const int v2[] = { -13, 21, 7};
        Vector<int, 3> v(v1, 3);
        Vector<int, 3> u(v2, 3);
        QCOMPARE(v.scalarMultiply(u), -32);
    }        

    void testMultiplyOnScalar()
    {
        const int v1[] = { 8, 28, -4, 0, 15 };
        Vector<int, 5> v(v1, 5);
        Vector<int, 5> doubled = v.multiply(2);
        std::stringstream out;
        std::string vec("16 56 -8 0 30 \n");
        doubled.print(out);
        QCOMPARE(out.str(), vec);
    }
};
