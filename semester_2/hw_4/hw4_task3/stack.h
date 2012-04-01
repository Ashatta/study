#pragma once

/** Exception that is thrown when trying to pop or look at the top element
  * of an empty stack
  */
class EmptyStack {};

/** Abstract template class Stack. */
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
