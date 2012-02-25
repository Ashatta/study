#include <iostream>
#include "binary_search_tree.h"

TreeNode::~TreeNode()
{
    delete leftChild;
    delete rightChild;
}

void Tree::insert(int key)
{
    if (isEmpty())
    {
        mRoot = new TreeNode(key);
        return;
    }

    TreeNode * parent = NULL;
    TreeNode * tmp = mRoot;
    while (tmp)
    {
        parent = tmp;
        if (key < tmp->key)
            tmp = tmp->leftChild;
        else if (key > tmp->key)
            tmp = tmp->rightChild;
        else 
        {
            ++tmp->repeats;
            return;
        }
    }
    if (key < parent->key)
        parent->leftChild = new TreeNode(key);
    else
        parent->rightChild = new TreeNode(key);
}

void Tree::remove(TreeNode * &node, int key)
{
    if (!node)
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

    if (node->leftChild == NULL)
    {
        TreeNode * tmp = node;
        node = tmp->rightChild;
        tmp->rightChild = NULL;
        delete tmp;
    }
    else if (node->rightChild == NULL)
    {
        TreeNode * tmp = node;
        node = tmp->leftChild;
        tmp->leftChild = NULL;
        delete tmp;
    }
    else
    {
        TreeNode * succ = node->rightChild;
        while (succ->leftChild)
            succ = succ->leftChild;
        node->key = succ->key;
        remove(node->rightChild, succ->key);
    }
}

void Tree::remove(int key)
{
    remove(mRoot, key);
}
        
TreeNode * Tree::search(int key)
{
    if (isEmpty())
       return NULL;
    TreeNode * tmp = mRoot;
    while (tmp && tmp->key != key)
        if (key < tmp->key) 
            tmp = tmp->leftChild;
        else
            tmp = tmp->rightChild;
    return tmp;
}

void Tree::incPrint(TreeNode * node)
{
    if (node)
    {
        incPrint(node->leftChild);
        std::cout << node->key << ' ' << node->repeats << std::endl;
        incPrint(node->rightChild);
    }
}

void Tree::incPrint()
{
    incPrint(mRoot);
}

void Tree::decPrint(TreeNode * node)
{
    if (node)
    {
        decPrint(node->rightChild);
        std::cout << node->key << ' ' << node->repeats << std::endl;
        decPrint(node->leftChild);
    }
}

void Tree::decPrint()
{
    decPrint(mRoot);
}

