#pragma once
#include <iostream>
#include "linkedlist.h"

/** HashFunctionIsNotSetException is thrown when trying to add, remove or
 *  find elment in the table with hashFunction == defaultFunction.
 */
class HashFunctionIsNotSetException {};

/** defaultFunction is a default value of hashFunction. Does nothing,
 *  just throws HashFunctionIsNotSetException.
 */
template<class T>
int defaultFunction(const T &value)
{
    throw HashFunctionIsNotSetException();
    std::cout << &value << std::endl;
    return 0;
}

/** Template class HashTable is a hashtable that solves conflicts by chain
 *  method. Uses linked list to store a chain. Objects must have
 *  implemented operator==.
 */
template<class T>
class HashTable
{
public:
    /** Constructor of HashTable takes three optional arguments:
     *  number of cells, maximum load factor of a table and 
     *  pointer to a hash function.
     */
    HashTable(int cap = 64, 
              double lfactor = 0.5, 
              int (*hFunc)(const T &value) = &defaultFunction) 
        : mSize(0)
        , capacity(cap)
        , table(new LinkedList<T>[capacity])
        , hashFunction(hFunc)
        , maxLoadFactor(lfactor)
    {}
    ~HashTable() { delete[] table; }

    /** Method add inserts value into the table. If load factor is over 
     *  maxLoadFactor then rehashes the table to make load factor a half of
     *  maxLoadFactor.
     */
    void add(const T &value);
    void remove(const T &value);
    bool hasValue(const T &value);
    int size() { return mSize; }
    /// Method loadfactor returns a load factor of the table.
    double loadfactor() { return (double) mSize / capacity; }
    /** Method setHashFunction changes a hash function that is already set
     *  to func. Nothing is done then func is the same as hashFunction.
     */
    void setHashFunction(int (*func)(const T &value))
    { 
        if (func != hashFunction) 
        { 
            hashFunction = func; 
            rehash(capacity); 
        } 
    }
    /** Method showStatistics prints to the stream out number of elements
     *  in the table, number of its cells, current load factor, number of 
     *  occupied cells, number of conflicts and the length of 
     *  the longest chain.
     */
    void showStatistics(std::ostream &out = std::cout);

protected:
    int mSize;              ///< Number of elements in the table.
    int capacity;           ///< Number of table cells.
    LinkedList<T>* table;
    int (*hashFunction)(const T &value);
    const double maxLoadFactor;

    /** Method rehash reallocates the table to make its capacity
     *  equal newCapacity.
     */
    void rehash(int newCapacity);
};

template<class T>
void HashTable<T>::add(const T &value)
{
    int index = hashFunction(value); // If hashFunction is 
                // not set then HashFunctionIsNotSetException is thrown

    if ((mSize + 1.0) / capacity > maxLoadFactor) // If adding new
        rehash(2 * (mSize + 1) / maxLoadFactor);  // element is making
                                            // the load factor too big

    index %= capacity;  // Capacity will change if we rehash

    if (!table[index].hasValue(value)) // Table contains unique values
    {
        mSize++;
        table[index].insert(value, 0);
    }
}

template<class T>
void HashTable<T>::remove(const T &value)
{
    int index = hashFunction(value) % capacity; // If hashFunction is
                // not set then HashFunctionIsNotSetException is thrown

    int chainLength = table[index].length();
    table[index].remove(value);
    
    if (chainLength > table[index].length()) // If length of the chain
        mSize--;                             // got lesser
}

template<class T>
bool HashTable<T>::hasValue(const T &value)
{
    int index = hashFunction(value) % capacity; // If hashFunction is
                // not set then HashFunctionIsNotSetException is thrown

    if (table[index].hasValue(value))
        return true;
    return false;
}

template<class T>
void HashTable<T>::showStatistics(std::ostream &out) 
{
    int conflicts = 0;
    int occupiedCells = 0;
    int chainSize = 0;
    for (int i = 0; i < capacity; i++)
        if (!table[i].isEmpty())
        {
            occupiedCells++;
            conflicts += table[i].length() - 1;
            if (table[i].length() > chainSize)
                chainSize = table[i].length();
        }
    
    out << "Number of elements: " << mSize
        << "\nSize of the table: " << capacity
        << "\nLoad factor: " << (double) mSize / capacity
        << "\nNumber of occupied cells: " << occupiedCells
        << "\nNumber of conflicts: " << conflicts
        << "\nMax chain size: " << chainSize << std::endl;
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
            int index = hashFunction(value) % newCapacity;
            newTable[index].insert(value, 0);
        }
    delete[] table;
    table = newTable;
    capacity = newCapacity;
}

