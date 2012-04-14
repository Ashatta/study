#pragma once

class List 
{
public:
    List() {}
    virtual int length() = 0;
    virtual bool isEmpty() = 0;
    virtual bool hasValue(int value) = 0;
    virtual int find(int value) = 0;
    virtual void insert(int value, int pos) = 0;
    virtual void removeAt(int pos) = 0;
    virtual void remove(int value) = 0;
    virtual void print() = 0;
    virtual ~List() {}
};

