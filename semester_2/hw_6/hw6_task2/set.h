#pragma once
#include "tree.h"

template<class T>
class Set : public Tree<T>
{
public:
    Set() {}
    ~Set() {}

    Set<T> setIntersection(Set<T> &second) { setIntersection(this->root, second); }
    Set<T> setUnion(Set<T> &second);
    Set<T> add(Set<T> &second) { add(second, second.root); }

protected:
    Set<T> setIntersection(typename TreeNode* node, Set<T> &second);
    Set<T> add(Set<T> &second, typename TreeNode* node);
};

template<class T>
Set<T> Set<T>::setIntersection(typename TreeNode* node, Set<T> &second)
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
}

template<class T>
Set<T> Set<T>::add(Set<T> &second, typename TreeNode* node)
{
    if (node == 0)
        return;
    add(second.root);
    add(second.root->leftChild);
    add(second.root->rightChild);
}
