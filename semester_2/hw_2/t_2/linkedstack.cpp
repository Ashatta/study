#include "linkedstack.h"

int LinkedStack::top()
{
    if (isEmpty())
        throw emptyStack;
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
        throw emptyStack;
    Node * popped = mHead->next;
    int x = popped->value;
    mHead->next = popped->next;
    delete popped;
    mLength--;
    return x;
}


