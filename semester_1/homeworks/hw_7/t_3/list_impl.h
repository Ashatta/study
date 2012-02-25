#pragma once
#include <iostream>

class emptyList 
{
    public:
        emptyList(const char * message) :
            mess(message)
        {}
        ~emptyList() {}
        const char * what() const { return mess; }
    private:
        const char * mess;
};

template<class T>
void List<T>::pushFront(T value)
{
    Node * newNode = new Node(guard, guard->next, value);
    ++mSize;
}

template<class T>
void List<T>::pushBack(T value)
{
    Node * newNode = new Node(guard->prev, guard, value);
    ++mSize;
}

template<class T>
void List<T>::insert(int pos, T value)
{
    if (!this->isEmpty())
    {
        pos %= mSize;
        Node * tmp = guard;
        for (int i = 0; i < pos; ++i)
            tmp = tmp->next;
        Node * newNode = new Node(tmp, tmp->next, value);
    }
    else
        this->pushBack(value);
    ++mSize;
}

template<class T>
T List<T>::front()
{
    if (!this->isEmpty())
        return guard->next->value;
    throw emptyList("Trying to read from an empty list");
}

template<class T>
T List<T>::back()
{
    if (!this->isEmpty())
        return guard->prev->value;
    throw emptyList("Trying to read from an empty list");
}

template<class T>
T& List<T>::operator[] (int index)
{
    if (!this->isEmpty())
    {
        index %= mSize;
        Node * tmp = guard->next;
        for (int i = 0; i < index; ++i)
            tmp = tmp->next;
        return tmp->value;
    }
    throw emptyList("Trying to read from an empty list");
}

template<class T>
T List<T>::popFront()
{
    if (!this->isEmpty())
    {
        Node * tmp = guard->next;
        T x = tmp->value;
        tmp->next->prev = guard;
        guard->next = tmp->next;
        delete tmp;
        --mSize;
        return x;
    }
    throw emptyList("Trying to erase non-existent element");
}

template<class T>
T List<T>::popBack()
{
    if (!this->isEmpty())
    {
        Node * tmp = guard->prev;
        T x = tmp->value;
        guard->prev = tmp->prev;
        tmp->prev->next = guard;
        delete tmp;
        --mSize;
        return x;
    }
    throw emptyList("Trying to erase non-existent element");
}

template<class T>
T List<T>::erase(int pos)
{
    if (!this->isEmpty())
    {
        pos %= mSize;
        Node * tmp = guard->next;
        for (int i = 0; i < pos; ++i)
            tmp = tmp->next;
        Node * del = tmp;
        T x = del->value;
        tmp->next->prev = tmp->prev;
        tmp->prev->next = tmp->next;
        delete del;
        --mSize;
        return x;
    }
    throw emptyList("Trying to erase non-existent element");
}

template<class T>
void List<T>::print()
{
    if (!this->isEmpty())
    {
        Node * it = guard->next;
        while (it != guard)
        {
            std::cout << it->value << ' ';
            it = it->next;
        }
        std::cout << std::endl;
    }
}

