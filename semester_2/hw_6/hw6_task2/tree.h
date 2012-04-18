#pragma once
#include <iostream>

/** Template class Tree is a binary search tree. Elements of type T must
 *  have implemented operator< and operator==.
 */
template<class T>
class Tree
{
public:
    Tree() : root(NULL) {}
    ~Tree() { delete root; }

    /// Method add(const T&) inserts key into a tree
    void add(const T &key);
    /// Method isEmpty returns true if a tree contains no element
    bool isEmpty() const { return root == NULL; }
    /// Method hasKey return true if key is in a tree
    bool hasKey(const T &key) const;
    /// Method remove deletes key from the tree
    void remove(const T &key) { remove(root, key); }
    /** Method print writes keys of the tree to the stream out 
     *  in increasing order
     */
    void print(std::ostream &out = std::cout) const
    { Printer p(out); symmorder(p); out << std::endl; }
    /** Method preorder proceeds preorder traversal of the tree and runs
     *  action over every node. Action must be a callable object 
     *  (with implemented operator())
     */
    template<class A> void preorder(A &action) const
    { preorder(root, action); }
    /** Method postorder proceeds postorder traversal of the tree and runs
     *  action over every node. Action must be a callable object 
     *  (with implemented operator())
     */
    template<class A> void postorder(A &action) const
    { postorder(root, action); }
    /** Method symmorder proceeds symmorder traversal of the tree and runs
     *  action over every node. Action must be a callable object 
     *  (with implemented operator())
     */
    template<class A> void symmorder(A &action) const 
    { symmorder(root, action); }

protected:
    struct TreeNode
    {
        T key;
        TreeNode* leftChild;
        TreeNode* rightChild;

        TreeNode(T value)
            : key(value)
            , leftChild(NULL)
            , rightChild(NULL)
        {}
        ~TreeNode() { delete leftChild; delete rightChild; }
    };

    TreeNode* root;

    /// Class Printer is a functor that writes a value into a stream
    class Printer
    {
    public:
        Printer(std::ostream &out) : strm(out) {}
        void operator()(const T &key)
        { strm << key << ' '; }
    private:
        std::ostream &strm;
    };

    /// Protected method remove deletes key from a subtree node
    void remove(TreeNode* &node, const T &key);
    /** Protected method preorder proceeds an preodrer traversal of the
     *  subtree node and runs action over every node in this subtree
     */
    template<class A> void preorder(TreeNode* node, A &action) const;
    /** Protected method postorder proceeds an postodrer traversal of the
     *  subtree node and runs action over every node in this subtree
     */
    template<class A> void postorder(TreeNode* node, A &action) const;
    /** Protected method symmorder proceeds an symmodrer traversal of the
     *  subtree node and runs action over every node in this subtree
     */
    template<class A> void symmorder(TreeNode* node, A &action) const;
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
    TreeNode* parent = NULL;
    while (curr)
    {
        if (curr->key == key)
            return;
        parent = curr;
        if (curr->key < key)
            curr = curr->rightChild;
        else if (key < curr->key)
            curr = curr->leftChild;
    }
    if (parent->key < key)
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
    while (curr && !(curr->key == key))
        if (curr->key < key)
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
    if (node == NULL)
        return;

    if (key < node->key)
    {
        remove(node->leftChild, key);
        return;
    }

    if (node->key < key)
    {
        remove(node->rightChild, key);
        return;
    }

    if (node->leftChild == NULL)
    {
        TreeNode* tmp = node;
        node = tmp->rightChild;
        tmp->rightChild = 0;
        delete tmp;
    }
    else if (node->rightChild == NULL)
    {
        TreeNode* tmp = node;
        node = tmp->leftChild;
        tmp->leftChild = 0;
        delete tmp;
    }
    else
    {
        TreeNode* succ = node->rightChild; while (succ->leftChild)
            succ = succ->leftChild;
        node->key = succ->key;
        remove(node->rightChild, succ->key);
    }
}

template<class T>
template<class A>
void Tree<T>::preorder(TreeNode* node, A &action) const
{
    if (node != NULL)
    {
        action(node->key);
        preorder(node->leftChild, action);
        preorder(node->rightChild, action);
    }
}

template<class T>
template<class A>
void Tree<T>::postorder(TreeNode* node, A &action) const
{
    if (node != NULL)
    {
        postorder(node->leftChild, action);
        postorder(node->rightChild, action);
        action(node->key);
    }
}

template<class T>
template<class A>
void Tree<T>::symmorder(TreeNode* node, A &action) const
{
    if (node != NULL)
    {
        symmorder(node->leftChild, action);
        action(node->key);
        symmorder(node->rightChild, action);
    }
}

