#pragma once
#include "linkedlist.h"

/** ExsistentElementAddException is thrown when trying to add an element
 *  that is already in the list
 */
class ExsistentElementAddException {};
/** NonExsistentElementRemoveException is thrown when trying to remove
 *  value which is not in the list or remove value from position that
 *  is greater than the greatest index in the list
 */
class NonExsistentElementRemoveException {};

/// class UniqueList is a LinkedList that cannot store two identical values
class UniqueList : public LinkedList
{
public:
    UniqueList() {}
    ~UniqueList() {}
    int length() { return LinkedList::length(); }
    bool isEmpty() { return LinkedList::isEmpty(); }
    int find(int value) { return LinkedList::find(value); }
    bool hasValue(int value) { return find(value) >= 0; }
    /** Method insert adds value into position pos. Value must be not
     *  in the list
     */
    void insert(int value, int pos);
    /** Method remove delets value from the list. 
     *  Value must be in the list
     */
    void remove(int value);    
    /** Method removeAt delets an element at the position pos. Pos must be
     *  lesser than number of elements in the list
     */
    void removeAt(int pos);
    void print() { LinkedList::print(); }
};
