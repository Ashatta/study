#pragma once

struct ListNode {
    char value;
    ListNode * next;
};

ListNode * createNode(char value);

void deleteList(ListNode * list);

void insert(ListNode * list, int pos, char value);

void deleteNode(ListNode * list, int pos);

int getLength(ListNode * list);

bool isEmpty(ListNode * list);

char top(ListNode * list);

char pop(ListNode * list);

void push(ListNode * list, char value);

void outList(ListNode * list);

void append(ListNode * list, char value);

