#pragma once

#include <QtTest/QtTest>
#include <sstream>
#include <string>
#include "tree.h"


class TreeTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        tree = new Tree<int>;
    }

    void cleanup()
    {
        delete tree;
    }

    void testCreateTree()
    {
        QVERIFY(tree != NULL && tree->isEmpty());
    }

    void testAddToEmptyTree()
    {
        tree->add(3);
        QVERIFY(!tree->isEmpty());
    }

    void testHasKey()
    {
        QVERIFY(!tree->hasKey(0));
        tree->add(0);
        QVERIFY(tree->hasKey(0));
    }

    void testAddToNonEmptyTree()
    {
        tree->add(5);
        tree->add(7);
        QVERIFY(tree->hasKey(7));
    }

    void testRemoveOneElementTree()
    {
        tree->add(8);
        tree->remove(8);
        QVERIFY(tree->isEmpty());
    }

    void testMultipleAdd()
    {
        tree->add(4);
        tree->add(2);
        tree->add(6);
        tree->add(0);
        QVERIFY(tree->hasKey(2));
        QVERIFY(tree->hasKey(0));
        QVERIFY(!tree->hasKey(5));
    }

    void testRemoveFromComplexTree()
    {
        tree->add(3);
        tree->add(2);
        tree->add(0);
        tree->add(5);
        tree->remove(2);
        QVERIFY(!tree->hasKey(2));
        QVERIFY(!tree->hasKey(4));
        QVERIFY(tree->hasKey(0));
        QVERIFY(tree->hasKey(3));
    }

    void testPrint()
    {
        int const values[] = { 3, 8, 2, 4, 1, 0, 34, 28, 47, 5 };
        for (int i = 0; i < 10; i++)
            tree->add(values[i]);
        std::stringstream out;
        std::string result("0 1 2 3 4 5 8 28 34 47 \n");
        tree->print(out);
        QCOMPARE(out.str(), result);
    }

private:
    Tree<int>* tree;
};

