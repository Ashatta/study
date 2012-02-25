#pragma once

struct TreeNode 
{
    TreeNode(char * x) :
        num(1),
        leftChild(NULL),
        rightChild(NULL)
    {
        key = new char[strlen(x) + 1];
        strcpy(key, x);
    }
    ~TreeNode();

    char * key;
    int num;
    TreeNode * leftChild;
    TreeNode * rightChild;
};

class Tree
{
    public:
        Tree() :
            mRoot(NULL),
            mSize(0)
        {}
        ~Tree() { delete mRoot; }
        bool isEmpty() { return mRoot == NULL; }
        int size() {return mSize; }
        void add(char * key);
        void print();

    private:
        TreeNode * mRoot;
        int mSize;
        void print(TreeNode * node);
};
