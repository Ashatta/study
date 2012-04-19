#pragma once
#include "list.h"

class NonExistentElementException {};

template<class T>
class LinkedList : public List<T> 
{
public:
    LinkedList() 
        : mLength(0)
        , mHead(new Node())
    {}
    LinkedList(const LinkedList<T> &list);
    ~LinkedList();
    int length() { return mLength; }
    bool isEmpty() { return mLength == 0; }
    int find(T value);
    bool hasValue(T value) { return find(value) >= 0; }
    void insert(T value, int pos);
    void removeAt(int pos);
    void remove(T value);
    T at(int pos);
    void print(std::ostream &out = std::cout);
    
private:
    struct Node
    {
        T value;
        Node * next;

        Node() :
            value(),
            next(NULL)
        {}
        
        Node(T x, Node * nextNode = NULL) :
            value(x),
            next(nextNode)
        {}
    };

    int mLength;
    Node * mHead;
};

template<class T>
int LinkedList<T>::find(T value)
{
    if (!isEmpty())
    {
        Node * tmp = mHead->next;
        int pos = 0;
        while (tmp != NULL)
        {
            if (tmp->value == value)
                return pos;
            pos++;
            tmp = tmp->next;
        }
    }
    return -1;
}

template<class T>
void LinkedList<T>::insert(T value, int pos)
{
    if (isEmpty())
    {
        mHead->next = new Node(value);
        mLength++;
        return;
    }
    int i = 0;
    Node * tmp = mHead;
    while (i < pos && tmp->next != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    tmp->next = new Node(value, tmp->next);
    mLength++;
    return;
}

template<class T>
void LinkedList<T>::removeAt(int pos)
{
    if (pos >= mLength)
        return;
    int i = 0;
    Node * tmp = mHead;
    while (i < pos)
    {
        i++;
        tmp = tmp->next;
    }
    Node * dead = tmp->next;
    tmp->next = tmp->next->next;
    delete dead;
    mLength--;
    return;
}

template<class T>
void LinkedList<T>::remove(T value)
{
    if (isEmpty())
        return;
    Node * tmp = mHead;
    while (tmp->next != NULL && tmp->next->value != value)
        tmp = tmp->next;
    if (tmp->next != NULL)
    {
        Node * dead = tmp->next;
        tmp->next = tmp->next->next;
        delete dead;
        mLength--;
    }
    return;
}

template<class T>
T LinkedList<T>::at(int pos)
{
    if (isEmpty() || pos >= mLength)
        throw NonExistentElementException();
    int i = 0;
    Node* tmp = mHead->next;
    while (i < pos)
    {
        i++;
        tmp = tmp->next;
    }
    return tmp->value;
}

template<class T>
void LinkedList<T>::print(std::ostream &out)
{
    Node * tmp = mHead->next;
    while (tmp != NULL)
    {
        out << tmp->value << ' ';
        tmp = tmp->next;
    }
    out << std::endl;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node * tmp = mHead->next;
    while (tmp != NULL)
    {
        delete mHead;
        mHead = tmp;
        tmp = tmp->next;
    }
    delete mHead;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    Node* p1 = mHead;
    Node* p2 = list.mHead;
    while (p2->next)
    {
        p1->next = new Node(p2->next->value, NULL);
        mLength++;
        p2 = p2->next;
    }
}

