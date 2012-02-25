#pragma once
#include "list.h"
#include "list_impl.h"

template<class T>
class Stack : public List<T>
{
    public:
//        bool isEmpty();
 //       int size();
  //      void pushBack(T value);
   //     T popBack();
        T top() { return this->back(); }
    //    void print();
};
