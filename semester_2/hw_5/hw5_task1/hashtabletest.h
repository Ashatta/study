#pragma once

#include <QtTest/QtTest>
#include "hashtable.h"

class HashTableTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        table = new HashTable<int>();
    }

    void cleanup()
    {
        delete table;
    }

    void testCreate()
    {
        QVERIFY(table->getSize() == 0);
        try
        {
            table->add(8);
            QFAIL("Hash function is not set");
        }
        catch (HashFunctionIsNotSetException)
        {}
    }

    void testSetHashFunction()
    {
    } 
private:
    HashTable<int>* table;
};
