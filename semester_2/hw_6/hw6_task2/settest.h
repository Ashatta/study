#pragma once

#include <QtTest/QtTest>
#include <sstream>
#include <string>
#include "set.h"

class SetTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        set = new Set<int>();
    }

    void cleanup()
    {
        delete set;
    }

    void testAddSet()
    {
        set->add(6);
        set->add(8);
        set->add(0);
        set->add(4);
        set->add(2);
        Set<int> second;
        second.add(5);
        second.add(7);
        second.add(9);
        second.add(1);
        second.add(3);

        set->add(second);
        std::stringstream out;
        std::string result("0 1 2 3 4 5 6 7 8 9 \n");
        set->print(out);
        QCOMPARE(out.str(), result);
    }

    void testIntersection()
    {
        set->add(2);
        set->add(4);
        set->add(6);
        Set<int> second;
        second.add(6);
        second.add(3);

        Set<int> intersection = set->setIntersection(second);
        std::stringstream out;
        std::string result("6 \n");
        intersection.print(out);
        QCOMPARE(out.str(), result);
    }

    void testEmptyIntersecton()
    {
        set->add(2);
        set->add(4);

        Set<int> second;
        second.add(5);
        second.add(3);
        Set<int> intersection = set->setIntersection(second);
        std::stringstream out;
        std::string result("\n");
        intersection.print(out);
        QCOMPARE(out.str(), result);
    }

    void testUnion()
    {
        set->add(2);
        set->add(6);
        set->add(5);

        Set<int> second;
        second.add(3);
        second.add(8);
        second.add(6);
        Set<int> setUnion = set->setUnion(second);
        std::stringstream out;
        std::string result("2 3 5 6 8 \n");
        setUnion.print(out);
        QCOMPARE(out.str(), result);
    }
private:
    Set<int>* set;
};
