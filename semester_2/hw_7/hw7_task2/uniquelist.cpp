#include "uniquelist.h"

void UniqueList::insert(int value, int pos)
{
    if (hasValue(value))
        throw ExsistentElementAddException();
    LinkedList::insert(value, pos);
}

void UniqueList::remove(int value)
{
    if (isEmpty())
        throw NonExsistentElementRemoveException();

    LinkedList::Node* tmp = LinkedList::mHead;
    while (tmp->next && tmp->next->value != value)
        tmp = tmp->next;

    if (!tmp->next)
        throw NonExsistentElementRemoveException();
    LinkedList::Node* removed = tmp->next;
    tmp->next = tmp->next->next;
    LinkedList::mLength--;

    delete removed;
}

void UniqueList::removeAt(int pos)
{
    if (pos >= length())
        throw NonExsistentElementRemoveException();

    LinkedList::removeAt(pos);
}

