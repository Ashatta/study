#pragma once
#include <iostream>

/// Template class Tree is a binary search tree
template<class T>
class Tree
{
public:
    Tree() : root(NULL) {}
    ~Tree() { delete root; }

    /// Method add inserts key into a tree
    void add(const T &key);
    /// Method isEmpty returns true if a tree contains no element
    bool isEmpty() const { return root == NULL; }
    /// Method hasKey return true if key is in a tree
    bool hasKey(const T &key) const;
    /// Method remove deletes key from the tree
    void remove(const T &key) { remove(root, key); }
    /// Method print prints tree in increasing order
    void print(std::ostream &out) const
    { print(root, out); out << std::endl; }

protected:
    struct TreeNode
    {
        T key;
        TreeNode* leftChild;
        TreeNode* rightChild;

        TreeNode(T value = 0)
            : key(value)
            , leftChild(NULL)
            , rightChild(NULL)
        {}
        ~TreeNode() { delete leftChild; delete rightChild; }
    };
    TreeNode* root;

    /// Protected method remove deletes key from a subtree node
    void remove(TreeNode* &node, const T &key);
    /// Protected method print prints a subtree node
    void print(TreeNode* node, std::ostream &out) const;
};

template<class T>
void Tree<T>::add(const T &key)
{
    if (isEmpty())
    {
        root = new TreeNode(key);
        return;
    }

    TreeNode* curr = root;
    TreeNode* parent = 0;
    while (curr)
    {
        if (curr->key == key)
            return;
        parent = curr;
        if (curr->key < key)
            curr = curr->rightChild;
        else if (curr->key > key)
            curr = curr->leftChild;
    }
    if (key > parent->key)
        parent->rightChild = new TreeNode(key);
    else
        parent->leftChild = new TreeNode(key);
}

template<class T>
bool Tree<T>::hasKey(const T &key) const
{
    if (isEmpty())
        return false;

    TreeNode* curr = root;
    while (curr && curr->key != key)
        if (key > curr->key)
            curr = curr->rightChild;
        else
            curr = curr->leftChild;
    if (curr)
        return true;

    return false;
}

template<class T>
void Tree<T>::remove(TreeNode* &node, const T &key)
{
    if (node == 0)
        return;

    if (key < node->key)
    {
        remove(node->leftChild, key);
        return;
    }

    if (key > node->key)
    {
        remove(node->rightChild, key);
        return;
    }

    if (node->leftChild == 0)
    {
        TreeNode* tmp = node;
        node = tmp->rightChild;
        tmp->rightChild = 0;
        delete tmp;
    }
    else if (node->rightChild == 0)
    {
        TreeNode* tmp = node;
        node = tmp->leftChild;
        tmp->leftChild = 0;
        delete tmp;
    }
    else
    {
        TreeNode* succ = node->rightChild;
        while (succ->leftChild)
            succ = succ->leftChild;
        node->key = succ->key;
        remove(node->rightChild, succ->key);
    }
}

template<class T>
void Tree<T>::print(TreeNode* node, std::ostream &out) const
{
    if (node)
    {
        print(node->leftChild, out);
        out << node->key << ' ';
        print(node->rightChild, out);
    }
}
