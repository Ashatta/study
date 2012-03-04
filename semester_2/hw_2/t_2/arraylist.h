#pragma once
#include "list.h"

class ArrayList : public List {
public:
    ArrayList() :
        mLength(0),
        mCapacity(32),
        mData(new int[mCapacity])
    {}
    ~ArrayList() { delete[] mData; }

    int length() { return mLength; }
    bool isEmpty() { return mLength == 0; }
    int find(int value);
    bool hasValue(int value) { return find(value) >= 0; }
    void insert(int value, int pos);
    void removeAt(int pos);
    void remove(int value);
    void print();

private:
    int mLength;
    int mCapacity;
    int * mData;

    void ensureCapacity();
};

