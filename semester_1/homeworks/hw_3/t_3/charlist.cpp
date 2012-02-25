#include <iostream>
#include <cstdlib>
#include "charlist.h"

using namespace std;

ListNode * createNode(char value)
{
    ListNode * newNode = new ListNode;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void deleteList(ListNode * list)
{
    if (list->next)
        deleteList(list->next);
    delete list;
}

void insert(ListNode * list, int pos, char value)
{
    int i = 0;
    ListNode * tmp = list;
    while (i < pos && tmp)
    {
        ++i;
        tmp = tmp->next;
    }
    ListNode * newNode = createNode(value);
    newNode->next = tmp->next;
    tmp->next = newNode;
}

int getLength(ListNode * list)
{
    int len = 0;
    ListNode * tmp = list;
    while (tmp->next)
    {
        ++len;
        tmp = tmp->next;
    }
    return len;
}

void outList(ListNode * list)
{
    ListNode * tmp = list->next;
    while (tmp)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void deleteNode(ListNode * list, int pos)
{
    int i = 0;
    ListNode * tmp = list;
    while (i < pos && tmp->next)
    {
        ++i;
        tmp = tmp->next;
    }
    if (tmp->next)
    {
        ListNode * del = tmp->next;
        tmp->next = tmp->next->next;
        delete del;
    }
}

bool isEmpty(ListNode * list)
{
    return list->next == NULL;
}

char top(ListNode * list)
{
    return list->next->value;
}

char pop(ListNode * list)
{
    char ret = top(list);
    deleteNode(list, 0);
    return ret;
}

void push(ListNode * list, char value)
{
    insert(list, 0, value);
}

void append(ListNode * list, char value)
{
    ListNode * tmp = list;
    while (tmp->next)
        tmp = tmp->next;
    ListNode * newNode = createNode(value);
    tmp->next = newNode;
}

