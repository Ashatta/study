#pragma once
#include <iostream>

template<class T>
class Tree
{
public:
    Tree() : root(0) {}
    ~Tree() { delete root; }

    void add(T key);
    bool isEmpty() { return root == 0; }
    bool hasKey(T key);
    void remove(T key) { remove(root, key); }
    void print() { print(root); std::cout << std::endl; }

protected:
    struct TreeNode
    {
        T key;
        TreeNode* leftChild;
        TreeNode* rightChild;

        TreeNode(T value = 0)
            : key(value)
            , leftChild(0)
            , rightChild(0)
        {}
        ~TreeNode() { delete leftChild; delete rightChild; }
    };
    TreeNode* root;

    void remove(TreeNode* &node, T key);
    void print(TreeNode* node);
};

template<class T>
void Tree<T>::add(T key)
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
bool Tree<T>::hasKey(T key)
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
void Tree<T>::remove(TreeNode* &node, T key)
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
void Tree<T>::print(TreeNode* node)
{
    if (node)
    {
        print(node->leftChild);
        std::cout << node->key << ' ';
        print(node->rightChild);
    }
}