#pragma once

template<class T>
class List 
{
    public:
        List() :
            mSize(0),
            guard(new Node)
        {}
        ~List()
        {
            while (!this->isEmpty())
                this->popBack();
            delete guard;
        }
        bool isEmpty()
            { return guard->next == guard; }
        int size()       
            { return mSize; }
        void pushFront(T value);
        void pushBack(T value);
        void insert(int pos, T value);        
        T front();
        T back();
        T& operator[] (int index);
        T popBack();
        T popFront();
        T erase(int pos);
        void print();

    protected:
        struct Node
        {
            T value;
            Node * next;
            Node * prev;

            Node() :
                value(0),
                next(this),
                prev(this)
            {}

            Node(Node * prevNode, Node * nextNode, T x = 0) :
                value(x),
                next(nextNode),
                prev(prevNode)
            {
               this->next->prev = this;
               this->prev->next = this;
            } 
        };
        int mSize; 
        Node * guard;
};

