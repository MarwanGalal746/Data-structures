#ifndef BINARY_TREE_AVL_H
#define BINARY_TREE_AVL_H

#include <iostream>

using namespace std;

template<class type>
struct node {
    node *left;
    node *right;
    type info;
};

template<class type>
class AVL {
private:
    node<type> *root;

    void insert(const type &ele, node<type> *&newNode);

    void inorder(node<type> *newNode) const;

    node<type> *deleteSpecialNode(node<type> *victim, node<type> *current, const type &ele);

    node<type> *deleting(node<type> *current, const type &ele);

public:
    AVL();

    node<type> *rightRight(node<type> *newNode);

    node<type> *leftLeft(node<type> *newNode);

    node<type> *leftRight(node<type> *newNode);

    node<type> *rightLeft(node<type> *newNode);

    int height(node<type> *newNode) const;

    int balanceFactor(node<type> *newNode) const;

    node<type> *balancing(node<type> *newNode);

    void insertAVL(const type &ele);

    void deleteAVL(const type &ele);

    void print2DUtil(node<type> *root, int space);

    void print2D();

    void inorderTraversal() const;

    void pp() {
        cout << root->info << " " << root->left->info << " " << root->right->info << endl;
    }
};


#endif //BINARY_TREE_AVL_H