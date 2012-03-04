#pragma once
#include "stack.h"

class ArrayStack : public Stack {
public:
    ArrayStack() :
        mLength(0),
        mCapacity(32),
        mData(new int[mCapacity])
    {}
    ~ArrayStack() { delete[] mData; }
    int length() { return mLength; }
    bool isEmpty() { return mLength == 0; }
    int top();
    void push(int value);
    int pop();

private:
    int mLength;
    int mCapacity;
    int * mData;

    void ensureCapacity();
};
