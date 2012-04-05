#pragma once
#include "tree.h"

template<class T>
class Set : public Tree<T>
{
public:
    Set() {}
    ~Set() {}

    void add(T value) { Tree<T>::add(value); }
    bool hasKey(T value) { return Tree<T>::hasKey(value); }
    void remove(T value) { Tree<T>::remove(value); }
    void add(Set<T> &second) { add(second, second.root); }

    Set<T> setIntersection(Set<T> &second) { setIntersection(this->root, second); }
    Set<T> setUnion(Set<T> &second);

protected:
    Set<T> setIntersection(typename Tree<T>::TreeNode* node, Set<T> &second);
    void add(Set<T> &second, typename Tree<T>::TreeNode* node);
};

template<class T>
Set<T> Set<T>::setIntersection(typename Tree<T>::TreeNode* node, Set<T> &second)
{
    if (node == 0)
        return;
    static Set<T> result;
    if (second.hasKey(node->key))
        result.add(node->key);
    setIntersection(node->leftChild, second);
    setIntersection(node->rightChild, second);
}

template<class T>
Set<T> Set<T>::setUnion(Set<T> &second)
{
    Set<T> result;
    result.add(*this);
    result.add(second);
    return result;
}

template<class T>
void Set<T>::add(Set<T> &second, typename Tree<T>::TreeNode* node)
{
    if (node == 0)
        return;
    add(second.root);
    add(second.root->leftChild);
    add(second.root->rightChild);
}
