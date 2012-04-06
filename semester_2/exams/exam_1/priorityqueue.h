#pragma once

class DeleteFromEmptyQueueException {};

template<class T>
class PriorityQueue
{
public:
    PriorityQueue() : first(0) {}
    ~PriorityQueue();
    bool isEmpty() { return first == 0; }
    void enqueue(T value, int priority);
    T dequeue();

protected:
    struct Element
    {
        T value;
        int priority;
        Element* next;

        Element(T val, int prior, Element* n = 0)
            : value(val)
            , priority(prior)
            , next(n)
        {}
    };

    Element* first;
};

template<class T>
void PriorityQueue<T>::enqueue(T value, int priority)
{
    if (isEmpty())
    {
        first = new Element(value, priority);
        return;
    }
    Element* tmp = first;
    while (tmp->next != 0 && tmp->next->priority >= priority)
        tmp = tmp->next;
    tmp->next = new Element(value, priority, tmp->next);
}

template<class T>
T PriorityQueue<T>::dequeue()
{
    if (isEmpty())
        throw DeleteFromEmptyQueueException();
    Element* deleted = first;
    T x = deleted->value;
    first = first->next;
    delete deleted;
    return x;
}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{
    while (!isEmpty())
        dequeue();
}
