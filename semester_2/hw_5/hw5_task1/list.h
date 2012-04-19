#pragma once

template<class T>
class List {
public:
    List() {}
    virtual int length() = 0;
    virtual bool isEmpty() = 0;
    virtual bool hasValue(T value) = 0;
    virtual int find(T value) = 0;
    virtual void insert(T value, int pos) = 0;
    virtual T at(int pos) = 0;
    virtual void removeAt(int pos) = 0;
    virtual void remove(T value) = 0;
    virtual void print(std::ostream &out = std::cout) = 0;
    virtual ~List() {}
};

