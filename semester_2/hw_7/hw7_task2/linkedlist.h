#pragma once
#include "list.h"
#include <cstdlib>

class LinkedList : public List 
{
public:
    LinkedList() :
        mLength(0),
        mHead(new Node())
    {}
    ~LinkedList();
    int length() { return mLength; }
    bool isEmpty() { return mLength == 0; }
    int find(int value);
    bool hasValue(int value) { return find(value) >= 0; }
    void insert(int value, int pos);
    void removeAt(int pos);
    void remove(int value);
    void print();
    
protected:
    struct Node
    {
        int value;
        Node * next;

        Node() :
            value(0),
            next(NULL)
        {}
        
        Node(Node * nextNode, int x = 0) :
            value(x),
            next(nextNode)
        {}
    };

    int mLength;
    Node * mHead;
};
