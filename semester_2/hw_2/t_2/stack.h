#pragma once

class emptyStack {};

class Stack {
public:
    Stack() {}
    virtual int length() = 0;
    virtual bool isEmpty() = 0;
    virtual int top() = 0;
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual ~Stack() {}
};
