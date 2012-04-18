#pragma once
#include "tree.h"

/** Template class Set is based on a binary search tree. It can contain
 *  elements with implemented operator< and operator==.
 */
template<class T>
class Set
{
public:
    Set() {}
    ~Set() {}

    /// Method add(T&) inserts value into the set
    void add(const T &value) { set.add(value); }
    /// Method add(Set<T>&) inserts elements of set second into the set
    void add(const Set<T> &second);
    bool hasKey(const T &value) const { return set.hasKey(value); }
    void remove(const T &value) { set.remove(value); }
    /** Method print writes elements of the set to the stream out
     *  in increasing order
     */
    void print(std::ostream &out = std::cout) const { set.print(out); }

    /** Method setIntersection returns set that is an intersection
     *  with set second
     */
    Set<T> setIntersection(const Set<T> &second) const;
    /// Method setUnion returns a set that is an union with set second
    Set<T> setUnion(const Set<T> &second) const;

protected:
    Tree<T> set;

    class Adder
    {
    public:
        Adder(Set<T> &addTo) : tree(addTo.set) {}
        void operator()(const T &toAdd)
        { tree.add(toAdd); }
    private:
        Tree<T> &tree;
    };

    /** Class Intersector is a functor that adds a key to intersection
     *  if tree contains it
     */
    class Intersector
    {
    public:
        Intersector(const Set<T> &t, Set<T> &i)
            : tree(t.set)
            , intersection(i.set)
        {}
        void operator()(const T &key)
        {
            if (tree.hasKey(key))
                intersection.add(key);
        }
    private:
        const Tree<T> &tree;
        Tree<T> &intersection;
    };
};

template<class T>
void Set<T>::add(const Set<T> &second)
{
    Adder adder(*this);
    second.set.preorder(adder);    
}

template<class T>
Set<T> Set<T>::setUnion(const Set<T> &second) const
{
    Set<T> result; 
    result.add(*this);
    result.add(second);
    return result;
}

template<class T>
Set<T> Set<T>::setIntersection(const Set<T> &second) const
{
    Set<T> result;
    Intersector intersector(*this, result);
    second.set.preorder(intersector);
    return result;
}
