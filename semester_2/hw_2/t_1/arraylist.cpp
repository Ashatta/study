#include <iostream>
#include "arraylist.h"

int ArrayList::find(int value)
{
    for (int i = 0; i < mLength; i++)
        if (mData[i] == value)
            return i;
    return -1;
}

void ArrayList::insert(int value, int pos)
{
    if (mLength == mCapacity)
        ensureCapacity();
    if (pos >= mLength)
    {
        mData[mLength++] = value;
        return;
    }
    mLength++;
    for (int i = mLength - 1; i > pos; i--)
        mData[i] = mData[i - 1];
    mData[pos] = value;
    return;
}

void ArrayList::removeAt(int pos)
{
    if (pos >= mLength)
        return;
    for (int i = pos; i < mLength - 1; i++)
        mData[i] = mData[i + 1];
    mLength--;
    return;
}

void ArrayList::remove(int value)
{
    int i = 0;
    while (i < mLength && mData[i] != value)
       i++;
    if (i == mLength)
       return;
    while (i < mLength - 1)
    {
       mData[i] = mData[i + 1]; 
       i++;
    }
    mLength--;
    return;
}

void ArrayList::print(std::ostream &out)
{
    for (int i = 0; i < mLength; i++)
       out << mData[i] << ' ';
//    out << std::endl;
    out << '\n';
    return;
} 

void ArrayList::ensureCapacity()
{
    mCapacity *= 2;
    int * newData = new int[mCapacity];
    for (int i = 0; i < mCapacity / 2; i++)
        newData[i] = mData[i];
    delete[] mData;
    mData = newData;
    return;
}

