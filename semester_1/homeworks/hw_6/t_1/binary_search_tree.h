#pragma once

struct TreeNode 
{
    TreeNode(int x) :
        key(x),
        leftChild(NULL),
        rightChild(NULL)
    {}
    ~TreeNode();

    int key;
    TreeNode * leftChild;
    TreeNode * rightChild;
};

class Tree
{
    public:
        Tree() :
            mRoot(NULL) {}
        ~Tree() { delete mRoot; }
        bool isEmpty() { return mRoot == NULL; }
        void insert(int key);
        void remove(int key);
        TreeNode * search(int key);
        bool hasKey(int key) { return search(key) != NULL; }
        void incPrint();
        void decPrint();

    private:
        TreeNode * mRoot;
        void incPrint(TreeNode * node);
        void decPrint(TreeNode * node);
        void remove(TreeNode * &node, int key);
};
