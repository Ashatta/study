#pragma once

#include <QtTest/QtTest>
#include <string>
#include <sstream>
#include "hashtable.h"
#include "functions.h"

class HashTableTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        table = new HashTable<std::string>(10);
    }

    void cleanup()
    {
        delete table;
    }

    void testHashFunctionNotSet()
    {
        try
        {
            table->add("la");
            QFAIL("Hash function is not set");
        }
        catch (HashFunctionIsNotSetException)
        {}
    }

    void testSetHashFunction()
    {
        table->setHashFunction(&hFunc1);
        table->add("la");
    } 

    void testAdd()
    {
        table->setHashFunction(&hFunc1);
        QCOMPARE(table->size(), 0);
        table->add("la");
        table->add("alal");
        table->add("go-go");
        QCOMPARE(table->size(), 3);
        QVERIFY(table->hasValue("la"));
        QVERIFY(table->hasValue("alal"));
        QVERIFY(table->hasValue("go-go"));
        QVERIFY(!table->hasValue("ARRRRRR"));
    }

    void testRemove()
    {
        table->setHashFunction(&hFunc1);
        table->add("la");
        table->add("alal");
        table->add("gooo");
        table->remove("goo");
        QCOMPARE(table->size(), 3);
        QVERIFY(table->hasValue("gooo"));
        table->remove("gooo");
        QCOMPARE(table->size(), 2);
        QVERIFY(!table->hasValue("gooo"));
    }

    void testChangeFunction()
    {
        table->setHashFunction(&hFunc2);
        table->add("bralala");
        table->add("orange");
        table->add("LOL");
        table->add("ice cream");
        table->setHashFunction(&hFunc1);
        QCOMPARE(table->size(), 4);
        QVERIFY(table->hasValue("LOL"));
        QVERIFY(table->hasValue("ice cream"));
        QVERIFY(table->hasValue("bralala"));
        QVERIFY(table->hasValue("orange"));
    }

    void testRehashOverwhelming()
    {
        table->setHashFunction(&hFunc1);
        const std::string nums[] = { "one", "two", "three", 
                                     "four", "five" };
        for (int i = 0; i < 5; i++)
            table->add(nums[i]);
        QCOMPARE(table->size(), 5);
        QCOMPARE(table->loadfactor(), 0.5);
        table->add("six");
        QCOMPARE(table->size(), 6);
        QCOMPARE(table->loadfactor(), 0.25);
        for (int i = 0; i < 5; i++)
            QVERIFY(table->hasValue(nums[i]));
        QVERIFY(table->hasValue("six"));
    }

    void testShowStatistics()
    {
        table->setHashFunction(&hFunc1);
        table->add("log");
        table->add("goo");
        table->add("purple");
        table->add("leg");
        std::stringstream out1;
        table->showStatistics(out1);
        std::string result1("Number of elements: 4\nSize of the table: 10\nLoad factor: 0.4\nNumber of occupied cells: 3\nNumber of conflicts: 1\nMax chain size: 2\n");
        table->add("lug");
        table->add("goooo");
        std::stringstream out2;
        table->showStatistics(out2);
        std::string result2("Number of elements: 6\nSize of the table: 24\nLoad factor: 0.25\nNumber of occupied cells: 3\nNumber of conflicts: 3\nMax chain size: 3\n");
        table->setHashFunction(&hFunc2);
        std::stringstream out3;
        table->showStatistics(out3);
        std::string result3("Number of elements: 6\nSize of the table: 24\nLoad factor: 0.25\nNumber of occupied cells: 6\nNumber of conflicts: 0\nMax chain size: 1\n");
        QCOMPARE(out1.str(), result1);
        QCOMPARE(out2.str(), result2);
        QCOMPARE(out3.str(), result3);
    }
private:
    HashTable<std::string>* table;
};
