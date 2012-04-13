#include <iostream>
#include "linkedlist.h"

int LinkedList::find(int value)
{
    if (!isEmpty())
    {
        Node * tmp = mHead->next;
        int pos = 0;
        while (tmp != NULL)
        {
            if (tmp->value == value)
                return pos;
            pos++;
            tmp = tmp->next;
        }
    }
    return -1;
}

void LinkedList::insert(int value, int pos)
{
    if (isEmpty())
    {
        mHead->next = new Node(NULL, value);
        mLength++;
        return;
    }
    int i = 0;
    Node * tmp = mHead;
    while (i < pos && tmp->next != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    tmp->next = new Node(tmp->next, value);
    mLength++;
    return;
}

void LinkedList::removeAt(int pos)
{
    if (pos >= mLength)
        return;
    int i = 0;
    Node * tmp = mHead;
    while (i < pos)
    {
        i++;
        tmp = tmp->next;
    }
    Node * dead = tmp->next;
    tmp->next = tmp->next->next;
    delete dead;
    mLength--;
    return;
}

void LinkedList::remove(int value)
{
    if (isEmpty())
        return;
    Node * tmp = mHead;
    while (tmp->next != NULL && tmp->next->value != value)
        tmp = tmp->next;
    if (tmp->next != NULL)
    {
        Node * dead = tmp->next;
        tmp->next = tmp->next->next;
        delete dead;
        mLength--;
    }
    return;
}

void LinkedList::print(std::ostream &out)
{
    Node * tmp = mHead->next;
    while (tmp != NULL)
    {
        out << tmp->value << ' ';
        tmp = tmp->next;
    }
    out << std::endl;
}

LinkedList::~LinkedList()
{
    Node * tmp = mHead->next;
    while (tmp != NULL)
    {
        delete mHead;
        mHead = tmp;
        tmp = tmp->next;
    }
    delete mHead;
}

