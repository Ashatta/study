#pragma once
#include <iostream>
#include "linkedlist.h"

class HashFunctionIsNotSetException {};

template<class T>
int defaultFunction(const T &value)
{
    throw HashFunctionIsNotSetException();
    std::cout << &value << std::endl;
    return 0;
}

template<class T>
class HashTable
{
public:
    HashTable(int (*hFunc)(const T &value) = &defaultFunction, double lfactor = 0.5) 
        : size(0)
        , capacity(64)
        , table(new LinkedList<T>[capacity])
        , hashFunction(hFunc)
        , maxLoadFactor(lfactor)
    {}
    ~HashTable() { delete[] table; }

    void add(const T &value);
    void remove(const T &value);
    bool hasValue(const T &value);
    int getSize() { return size; }
    double loadfactor() { return (double) size / capacity; }
    void setHashFunction(int (*func)(const T &value))
    { hashFunction = func; rehash(capacity); } 
    void showStatistics(std::ostream &out = std::cout);

protected:
    int size;
    int capacity;
    LinkedList<T>* table;
    int (*hashFunction)(const T &value);
    const double maxLoadFactor;

    void rehash(int newCapacity);
};

template<class T>
void HashTable<T>::add(const T &value)
{
    int index = (*hashFunction)(value) % capacity;

    if ((size + 1.0) / capacity > maxLoadFactor)
        rehash(2 * (size + 1) / maxLoadFactor);

    if (!table[index].hasValue(value))
    {
        size++;
        table[index].insert(value, 0);
    }
}

template<class T>
void HashTable<T>::remove(const T &value)
{
    int index = (*hashFunction)(value) % capacity;
    int chainLength = table[index].length();
    table[index].remove(value);
    
    if (chainLength < table[index].length())
        size--;
}

template<class T>
bool HashTable<T>::hasValue(const T &value)
{
    int index = (*hashFunction)(value) % capacity;
    if (table[index].hasValue(value))
        return true;
    return false;
}

template<class T>
void HashTable<T>::showStatistics(std::ostream &out) 
{
    int conflicts = 0;
    int chainSize = 0;
    for (int i = 0; i < capacity; i++)
        if (!table[i].isEmpty())
        {
            conflicts += table[i].length() - 1;
            if (table[i].length() > chainSize)
                chainSize = table[i].length();
        }
    
    out << "Number of elements: " << size
        << "Size of the table: " << capacity
        << "Load factor: " << (double) size / capacity
        << "Number of conflicts: " << conflicts
        << "Max chain size: " << chainSize << std::endl;
}

template<class T>
void HashTable<T>::rehash(int newCapacity)
{
    LinkedList<T>* newTable = new LinkedList<T>[newCapacity];
    for (int i = 0; i < capacity; i++)
        while (!table[i].isEmpty())
        {
            T value = table[i].at(0);
            table[i].removeAt(0);
            int index = (*hashFunction)(value) % newCapacity;
            newTable[index].insert(value, 0);
        }
    delete[] table;
    table = newTable;
    capacity = newCapacity;
}

