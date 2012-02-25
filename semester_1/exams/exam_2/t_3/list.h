#pragma once

struct Node {
    int value;
    Node * next;
    Node * prev;

    Node(int x = 0) :
        value(x),
        next(this),
        prev(this)
    {}

    Node(Node * prevNode, Node * nextNode, int x = 0) :
        value(x),
        next(nextNode),
        prev(prevNode)
    {
        this->next->prev = this;
        this->prev->next = this;
    }
};

Node * create();
bool isEmpty(Node * guard);
int length(Node * guard);

void pushFront(Node * guard, int value);
void pushBack(Node * guard, int value);
Node * insert(Node * guard, int pos, int value);

int front(Node * guard);
int back(Node * guard);
int getElement(Node * guard, int pos);

int popFront(Node * guard);
int popBack(Node * guard);
int erase(Node * guard, int pos);

void print(Node * guard, std::ofstream &out);
void remove(Node * guard);

