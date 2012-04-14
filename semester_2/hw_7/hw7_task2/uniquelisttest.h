#pragma once

#include <QtTest/QtTest>
#include "uniquelist.h"

class UniqueListTest : public QObject
{
    Q_OBJECT
private slots:
    void init()
    {
        list = new UniqueList();
    }
    
    void cleanup()
    {
        delete list;
    }

    void testInsertExistent()
    {
        list->insert(6, 0);
        try
        {
            list->insert(6, 2);
            QFAIL("Insertion of existent element");
        }
        catch (ExsistentElementAddException)
        {}
    }

    void testRemove()
    {
        list->insert(4, 0);
        list->insert(6, 2);
        list->insert(3, 2);
        QVERIFY(list->hasValue(6));
        list->remove(6);
        QVERIFY(!list->hasValue(6));
    }

    void testRemoveNonExistent()
    {
        list->insert(5, 0);
        list->insert(2, 0);
        list->insert(6, 0);
        try
        {
            list->remove(4);
            QFAIL("Non-existent element removal");
        }
        catch (NonExsistentElementRemoveException)
        {}
    }

    void testRemoveAtNonExistentPosition()
    {
        list->insert(4, 3);
        list->insert(3, 0);
        try
        {
            list->removeAt(2);
            QFAIL("Removal at non-existent position");
        }
        catch (NonExsistentElementRemoveException)
        {}
    }
private:
    UniqueList* list;
};
