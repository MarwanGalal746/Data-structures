//
// Created by marwan on 6/14/20.
//

#ifndef BINARY_TREE_BST_H
#define BINARY_TREE_BST_H

#include "binaryTree.h"
#include "binaryTree.cpp"

template<class type>
class BST : public binaryTree<type> {
private:
    bool search(const type &ele,node<type> *&newNode) const ;

    void insert(const type &ele, node<type> *&newNode);

    node<type> *deleteSpecialNode(node<type> *victim, node<type> *current, const type &ele);

    node<type> *deleting(node<type> *current, const type &ele);


public:
    bool bstSearch(const type &ele);

    void bstInsert(const type &ele);

    void bstDelete(const type &ele);
};


#endif //BINARY_TREE_BST_H