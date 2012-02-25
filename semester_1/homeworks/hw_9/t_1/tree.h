#include <cstring>
#pragma once

struct TreeNode 
{
    TreeNode(char * x) :
        leftChild(NULL),
        rightChild(NULL)
    {
        key = new char[strlen(x) + 1];
        strcpy(key, x);
    }
    ~TreeNode();

    char * key;
    TreeNode * leftChild;
    TreeNode * rightChild;
};

class Tree
{
    public:
        Tree() :
            mRoot(NULL)
        {}
        ~Tree() { delete mRoot; }
        bool isEmpty() { return mRoot == NULL; }
        bool hasString(char * key) { return hasString(key, mRoot); }
        void add(char * key);
        void print();

    private:
        TreeNode * mRoot;
        bool hasString(char * key, TreeNode * node);
        void print(TreeNode * node);
};
