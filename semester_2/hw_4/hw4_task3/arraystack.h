#pragma once
#include "stack.h"

/** Template class ArrayStack implements a Stack and is based on an array. */
template<class T>
class ArrayStack : public Stack<T>
{
    public:
        ArrayStack() :
            mLength(0),
            mCapacity(32),
            mData(new T[mCapacity])
        {}
        ~ArrayStack() { delete[] mData; }
        int length() { return mLength; }
        bool isEmpty() { return mLength == 0; }
        T top();
        void push(T value);
        T pop();

    private:
        int mLength;
        int mCapacity;
        T * mData; ///< Array of stack elements.

        /** Method ensureCapacity expands ArrayStack to avoid overflows
         *  by relocating it.
         */
        void ensureCapacity();
};

template<class T>
T ArrayStack<T>::top()
{
    if (isEmpty())
        throw EmptyStack();
    return mData[mLength - 1];
}

template<class T>
T ArrayStack<T>::pop()
{
    if (isEmpty())
        throw EmptyStack();
    return mData[--mLength];
}

template<class T>
void ArrayStack<T>::push(T value)
{
    if (mLength == mCapacity)
        ensureCapacity();
    mData[mLength++] = value;
    return;
}

template<class T>
void ArrayStack<T>::ensureCapacity()
{
    mCapacity *= 2;
    T * newData = new T[mCapacity];
    for (int i = 0; i < mLength; i++)
        newData[i] = mData[i];
    delete[] mData;
    mData = newData;
    return;
}

