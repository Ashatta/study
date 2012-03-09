#include "linkedstack.h"

int LinkedStack::top()
{
    if (isEmpty())
        throw EmptyStack();
    return mHead->next->value;
}

void LinkedStack::push(int value)
{
    mHead->next = new Node(mHead->next, value);
    mLength++;
    return;
} 

int LinkedStack::pop()
{
    if (isEmpty())
        throw EmptyStack();
    Node * popped = mHead->next;
    int x = popped->value;
    mHead->next = popped->next;
    delete popped;
    mLength--;
    return x;
}

LinkedStack::~LinkedStack()
{
    Node * removed = mHead->next;
    while (removed != NULL)
    {
        mHead->next = removed->next;
        delete removed;
        removed = mHead->next;
    }
    delete mHead;
}

