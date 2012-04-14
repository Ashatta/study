#pragma once
#include "tree.h"

/// Template class Set is based on a binary search tree
template<class T>
class Set : public Tree<T>
{
public:
    Set() {}
    ~Set() {}

    /// Method add(T&) inserts value into the set
    void add(const T &value) { Tree<T>::add(value); }
    /// Method add(Set<T>&) inserts elements of set second into the set
    void add(const Set<T> &second) { add(second.root); }
    bool hasKey(const T &value) const { return Tree<T>::hasKey(value); }
    void remove(const T &value) { Tree<T>::remove(value); }
    void print(std::ostream &out) const { Tree<T>::print(out); }

    /** Method setIntersection returns set that is an intersection
     *  with set second
     */
    Set<T> setIntersection(const Set<T> &second) 
    { return setIntersection(this->root, second); }
    /// Method setUnion returns a set that is an union with set second
    Set<T> setUnion(const Set<T> &second);

protected:
    /** Protected method setIntersection returns set that is an intersection
     *  of subset node and set second
     */
    Set<T> setIntersection(typename Tree<T>::TreeNode* node, const Set<T> &second);
    /** Protected method add inserts elements of set second into the 
     *  subset node
     */
    void add(typename Tree<T>::TreeNode* node);
};

template<class T>
Set<T> Set<T>::setIntersection(typename Tree<T>::TreeNode* node, const Set<T> &second)
{
    Set<T> result;
    if (node == NULL)
        return result;

    if (second.hasKey(node->key))
        result.add(node->key);

    result.add(setIntersection(node->leftChild, second));
    result.add(setIntersection(node->rightChild, second));
    return result;
}

template<class T>
Set<T> Set<T>::setUnion(const Set<T> &second)
{
    Set<T> result;
    result.add(*this);
    result.add(second);
    return result;
}

template<class T>
void Set<T>::add(typename Tree<T>::TreeNode* node)
{
    if (node == NULL)
        return;
    add(node->key);
    add(node->leftChild);
    add(node->rightChild);
}
