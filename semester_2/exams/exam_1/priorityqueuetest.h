#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "priorityqueue.h"

class PriorityQueueTest : public QObject
{
    Q_OBJECT
public:
    explicit PriorityQueueTest(QObject* parent = 0) : QObject(parent) {}

private slots:
    void init()
    {
        queue = new PriorityQueue<int>();
    }

    void cleanup()
    {
        delete queue;
    }

    void testCreateQueue()
    {
        QVERIFY(queue->isEmpty());
    }

    void testEnqueue()
    {
        queue->enqueue(5, 1);
        QVERIFY(!queue->isEmpty());
    }

    void testDequeue()
    {
        queue->enqueue(5, 1);
        QVERIFY(queue->dequeue() == 5);
    }

    void testPriorities()
    {
        queue->enqueue(20, 5);
        queue->enqueue(4, 4);
        queue->enqueue(7, 5);
        QCOMPARE(queue->dequeue(), 20);
        QCOMPARE(queue->dequeue(), 7);
    }

private:
    PriorityQueue<int>* queue;
};

