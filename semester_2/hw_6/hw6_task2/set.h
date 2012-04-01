#pragma once
#include "tree.h"

template<class T>
class Set : public Tree<T*>
{
public:
    void add(T key) { Tree<T*>::add(&key); }
    void remove(T key) { Tree<T*>::remove(&key); }
    bool hasKey(T key) { return Tree<T*>::hasKey(&key); }
