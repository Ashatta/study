#pragma once
#include "stack.h"

class LinkedStack : public Stack {
public:
    LinkedStack() :
        mLength(0),
        mHead(new Node())
    {}
    ~LinkedStack();
    int length() { return mLength; }
    bool isEmpty() { return mLength == 0; }
    int top();
    void push(int value);
    int pop();

private:
    struct Node
    {
        int value;
        Node * next;

        Node(Node * nextNode = NULL, int x = 0) :
            value(x),
            next(nextNode)
        {}
    }

    int mLength;
    Node * mHead;
};
