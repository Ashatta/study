#include "arraystack.h"

int ArrayStack::top()
{
    if (isEmpty())
        throw EmptyStack();
    return mData[mLength - 1];
}

int ArrayStack::pop()
{
    if (isEmpty())
        throw EmptyStack();
    return mData[--mLength];
}

void ArrayStack::push(int value)
{
    if (mLength == mCapacity)
        ensureCapacity();
    mData[mLength++] = value;
    return;
}

void ArrayStack::ensureCapacity()
{
    mCapacity *= 2;
    int * newData = new int[mCapacity];
    for (int i = 0; i < mLength; i++)
        newData[i] = mData[i];
    delete[] mData;
    mData = newData;
    return;
}

