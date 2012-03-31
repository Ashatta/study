#pragma once
#include <cstdlib>
#include "stack.h"

template<class T>
class LinkedStack : public Stack<T> {
public:
    LinkedStack() :
        mLength(0),
        mHead(new Node())
    {}
    ~LinkedStack();
    int length() { return mLength; }
    bool isEmpty() { return mLength == 0; }
    T top();
    void push(T value);
    T pop();

private:
    struct Node
    {
        T value;
        Node * next;

        Node(Node * nextNode = NULL, T x = 0) :
            value(x),
            next(nextNode)
        {}
    };

    int mLength;
    Node * mHead;
};

T LinkedStack<T>::top()
{
    if (isEmpty())
        throw EmptyStack();
    return mHead->next->value;
}

void LinkedStack<T>::push(T value)
{
    mHead->next = new Node(mHead->next, value);
    mLength++;
    return;
} 

T LinkedStack<T>::pop()
{
    if (isEmpty())
        throw EmptyStack();
    Node * popped = mHead->next;
    T x = popped->value;
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

