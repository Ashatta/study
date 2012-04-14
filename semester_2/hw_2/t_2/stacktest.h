#pragma once

#include <QtTest/QtTest>
#include "arraystack.h"
#include "linkedstack.h"

class StackTest : public QObject
{
    Q_OBJECT
protected slots:
    virtual void init() = 0;

    virtual void cleanup()
    {
        delete stack;
    }

    virtual void testCreateEmptyStack()
    {
        QVERIFY(stack->isEmpty());
    }

    virtual void testNotEmpty()
    { 
        stack->push(4);
        QVERIFY(!stack->isEmpty());
    }

    virtual void testPush()
    {
        stack->push(8);
        QCOMPARE(stack->top(), 8);
    }

    virtual void testPop()
    {
        stack->push(4);
        QCOMPARE(stack->pop(), 4);
        QVERIFY(stack->isEmpty());
    }

    virtual void testLength()
    {
        QCOMPARE(stack->length(), 0);
        stack->push(4);
        QCOMPARE(stack->length(), 1);
        stack->pop();
        QCOMPARE(stack->length(), 0);
    }

    virtual void testStackUnderflow()
    {
        try
        {
            stack->pop();
            QFAIL("Stack underflow");
        }
        catch (EmptyStack)
        {}
    }
protected:
    Stack<int>* stack;
};

class ArrayStackTest : public StackTest
{
    Q_OBJECT
private slots:
    void init()
    {
        stack = new ArrayStack<int>();
    }

    void cleanup()
    { StackTest::cleanup(); }
    void testCreateEmptyStack()
    { StackTest::testCreateEmptyStack(); }
    void testNotEmpty()
    { StackTest::testNotEmpty(); }
    void testPush()
    { StackTest::testPush(); }
    void testPop()
    { StackTest::testPop(); }
    void testLength()
    { StackTest::testLength(); }
    void testStackUnderflow()
    { StackTest::testStackUnderflow(); }

    void testCapacity()
    {
        for (int i = 0; i < 33; i++)
            stack->push(i);
        QCOMPARE(stack->length(), 33);
        QCOMPARE(stack->pop(), 32);
        QCOMPARE(stack->pop(), 31);
    }
};

class LinkedStackTest : public StackTest
{
    Q_OBJECT
private slots:
    void init()
    {
        stack = new LinkedStack<int>();
    }

    void cleanup()
    { StackTest::cleanup(); }
    void testCreateEmptyStack()
    { StackTest::testCreateEmptyStack(); }
    void testNotEmpty()
    { StackTest::testNotEmpty(); }
    void testPush()
    { StackTest::testPush(); }
    void testPop()
    { StackTest:: testPop(); }
    void testLength()
    { StackTest::testLength(); }
    void testStackUnderflow()
    { StackTest::testStackUnderflow(); }
};
