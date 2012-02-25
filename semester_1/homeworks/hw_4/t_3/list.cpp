#include <iostream>
#include "list.h"

using namespace std;

Node * create()
{
    Node * guard = new Node;
    return guard;
}

bool isEmpty(Node * guard)
{
    return guard == guard->next;
}

int length(Node * guard)
{
    int len = 0;
    Node * tmp = guard->next;
    while (tmp != guard)
    {
        ++len;
        tmp = tmp->next;
    }
    return len;
}

void pushFront(Node * guard, int value)
{
    Node * newNode = new Node(guard, guard->next, value);
}

void pushBack(Node * guard, int value)
{
    Node * newNode = new Node(guard->prev, guard, value);
}

Node * insert(Node * guard, int pos, int value)
{
    if (isEmpty(guard))
    {
        Node * newNode = new Node(guard, guard, value);
        return newNode;
    }
    else
    {
        int len = length(guard);
        pos %= len;
        Node * tmp = guard;
        for (int i = 0; i < pos; ++i)
            tmp = tmp->next;
        Node * newNode = new Node(tmp, tmp->next, value);
        return newNode;
    }
}

int front(Node * guard)
{
    return guard->next->value;
}

int back(Node * guard)
{
    return guard->prev->value;
}

int getElement(Node * guard, int pos)
{
    if (isEmpty(guard))
        return guard->value;
    int len = length(guard);
    pos %= len;
    Node * tmp = guard->next;
    for (int i = 0; i < pos; ++i)
        tmp = tmp->next;
    return tmp->value;
} 

int popBack(Node * guard)
{
    if (!isEmpty(guard))
    {
        Node * tmp = guard->prev;
        int x = tmp->value;
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete tmp;
        return x;
    }
    return -1;
}

int popFront(Node * guard)
{
    if (!isEmpty(guard))
    {
        Node * tmp = guard->next;
        int x = tmp->value;
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete tmp;
        return x;
    }
    return -1;
}

int erase(Node * guard, int pos)
{
    if (!isEmpty(guard))
    {
        int len = length(guard);
        pos %= len;
        Node * tmp = guard->next;
        for (int i = 0; i < pos; ++i)
            tmp = tmp->next;
        int x = tmp->value;
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete tmp;
        return x;
    }
    return -1;
}

void remove(Node * guard)
{
    while (!isEmpty(guard))
        popBack(guard);
    delete guard;
}

void print(Node * guard)
{
    Node * tmp = guard->next;
    while (tmp != guard)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

