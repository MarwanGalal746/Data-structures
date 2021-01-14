

#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H

#include <iostream>
#include <stack>

using namespace std;
template<class type>
struct node {
    node *right;
    node *left;
    type info;
};

template<class type>
class binaryTree {
private:
    void inorder(node<type> *newNode) const;

    void preorder(node<type> *newNode) const;

    void postorder(node<type> *newNode) const;

    void itrInorder(node<type> *newNode) const;

    void itrPreorder(node<type> *newNode) const;

    void itrPostorder(node<type> *newNode);

    int height(const node<type> *&newNode) const;

    int NodeCount(const node<type> *&newNode) const;

    int LeavesCount(const node<type> *&newNode) const;

    void destroy(node<type> *&newNode);

    void copy(node<type> *&rootTree, const node<type> *&otherTree);

protected:
    node<type> *root;
public:
    bool isEmpty() const;

    void inorderTraversal() const;

    void inorderiteration() const;

    void preorderTraversal() const;

    void preorderiteration() const;

    void postorderTraversal() const;

    void postorderiteration() const;

    int treeNodeCount() const;

    int treeHeight() const;

    int treeLeavesCount() const;

    void destroyTree();

    binaryTree(const binaryTree<type> &otherTree);

    binaryTree();

    ~binaryTree();

    const binaryTree<type> &operator=(const binaryTree<type> &);
};


#endif //BINARY_TREE_BINARYTREE_H