#pragma once

class EmptyStack {};

template<class T>
class Stack {
public:
    Stack() {}
    virtual int length() = 0;
    virtual bool isEmpty() = 0;
    virtual T top() = 0;
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual ~Stack() {}
};
