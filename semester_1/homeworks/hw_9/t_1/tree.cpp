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
        return;
    }

    TreeNode * parent = NULL;
    TreeNode * tmp = mRoot;
    while (tmp)
    {
        parent = tmp;
        if (strcmp(key, tmp->key) < 0)
            tmp = tmp->leftChild;
        else if (strcmp(key, tmp->key) > 0)
            tmp = tmp->rightChild;
    }
    if (strcmp(key, parent->key) < 0)
        parent->leftChild = new TreeNode(key);
    else
        parent->rightChild = new TreeNode(key);
}

bool Tree::hasString(char * key, TreeNode * node)
{
    if (node == NULL)
        return false;
    if (strcmp(key, node->key) == 0)
        return true;
    else if (strcmp(key, node->key) < 0)
        return hasString(key, node->leftChild);
    else
        return hasString(key, node->rightChild);
}

void Tree::print()
{
    print(mRoot);
}

void Tree::print(TreeNode * node)
{
    if (node)
    {
        print(node->leftChild);
        std::cout << node->key << std::endl;
        print(node->rightChild);
    }
}

