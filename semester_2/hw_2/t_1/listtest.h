#pragma once

#include <QtTest/QtTest>
#include "arraylist.h"
#include "linkedlist.h"
#include <sstream>
#include <iostream>

class ListTest : public QObject
{
    Q_OBJECT

protected slots:
    virtual void init() = 0;

    virtual void cleanup()
    {
        delete list;
    }

    virtual void testCreateList()
    {
        QVERIFY(list->isEmpty());
    }

    virtual void testInsertIntoEmptyList()
    {
        list->insert(5, 0);
        QVERIFY(!list->isEmpty());
    }

    virtual void testRemoveFromOneElementList()
    {
        list->insert(5, 0);
        list->remove(3);
        QVERIFY(!list->isEmpty());
        list->remove(5);
        QVERIFY(list->isEmpty());
    }

    virtual void testMultipleInsert()
    {
        list->insert(2, 0);
        list->insert(7, 0);
        list->insert(9, 3);
        QCOMPARE(list->find(9), 2);

        list->insert(6, 1);
        QCOMPARE(list->find(6), 1);
        list->insert(4, 2);
        list->insert(3, 1);
        QCOMPARE(list->find(7), 0);
        QCOMPARE(list->find(6), 2);
        QCOMPARE(list->find(9), 5);
    }

    virtual void testHasValue()
    {
        list->insert(4, 0);
        list->insert(6, 0);
        QVERIFY(!list->hasValue(7));
        list->insert(7, 1);
        QVERIFY(list->hasValue(7));
    }

    virtual void testRemoveAt()
    {
        list->insert(2, 0);
        list->insert(3, 1);
        list->insert(5, 2);
        list->insert(6, 3);
        list->removeAt(2);
        QCOMPARE(list->length(), 3);
        QVERIFY(!list->hasValue(5));
        QCOMPARE(list->find(6), 2);
    }

    virtual void testRemove()
    {
        list->insert(2, 0);
        list->insert(3, 1);
        list->insert(5, 2);
        list->insert(6, 3);
        list->remove(3);
        QVERIFY(!list->hasValue(3));
    }

protected:
    List* list;
};
    
class ArrayListTest: public ListTest
{
    Q_OBJECT
private slots:
    void init()
    {
        list = new ArrayList();
    }
    
    void cleanup() 
    { ListTest::cleanup(); }
    void testCreateList() 
    { ListTest::testCreateList(); }
    void testInsertIntoEmptyList()
    { ListTest::testInsertIntoEmptyList(); }
    void testRemoveFromOneElementList()
    { ListTest::testRemoveFromOneElementList(); }
    void testMultipleInsert()
    { ListTest::testMultipleInsert(); }
    void testRemoveAt()
    { ListTest::testRemoveAt(); }
    void testHasValue()
    { ListTest::testHasValue(); }
    void testRemove()
    { ListTest::testRemove(); }

    void testCapacity()
    {
        for (int i = 0; i < 33; i++)
            list->insert(i, i);
        QCOMPARE(list->length(), 33);
        QCOMPARE(list->find(17), 17);
        QCOMPARE(list->find(32), 32);
    }
};

class LinkedListTest: public ListTest
{
    Q_OBJECT
private slots:
    void init()
    {
        list = new LinkedList();
    }
    void cleanup() 
    { ListTest::cleanup(); }
    void testCreateList() 
    { ListTest::testCreateList(); }
    void testInsertIntoEmptyList()
    { ListTest::testInsertIntoEmptyList(); }
    void testRemoveFromOneElementList()
    { ListTest::testRemoveFromOneElementList(); }
    void testMultipleInsert()
    { ListTest::testMultipleInsert(); }
    void testRemoveAt()
    { ListTest::testRemoveAt(); }
    void testHasValue()
    { ListTest::testHasValue(); }
    void testRemove()
    { ListTest::testRemove(); }
};

