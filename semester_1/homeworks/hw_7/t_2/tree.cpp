#include <iostream>
#include <cstring>
#include "tree.h"

TreeNode::~TreeNode()
{
    delete[] key;
    delete leftChild;
    delete rightChild;
}

void Tree::add(char * key)
{
    if (isEmpty())
    {
        mRoot = new TreeNode(key);
        ++mSize;
        return;
    }

    TreeNode * parent = NULL;
    TreeNode * tmp = mRoot;
    while (tmp)
    {
        parent = tmp;
        if (strcmp(key, tmp->key) == 0)
        {
            ++tmp->num;
            return;
        }
        else if (strcmp(key, tmp->key) < 0)
            tmp = tmp->leftChild;
        else
            tmp = tmp->rightChild;
    }
    if (strcmp(key, parent->key) < 0)
        parent->leftChild = new TreeNode(key);
    else
        parent->rightChild = new TreeNode(key);
    ++mSize;
}

void Tree::print(TreeNode * node)
{
    if (node)
    {
        print(node->leftChild);
        std::cout << node->key << ' ' << node->num << std::endl;
        print(node->rightChild);
    }
}

void Tree::print()
{
    if (!isEmpty())
    {
        print(mRoot);
    }
}
