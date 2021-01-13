//
// Created by marwan on 1/14/21.
//

#ifndef DATA_STRUCTURES_BTREE_H
#define DATA_STRUCTURES_BTREE_H

template<class type, int order>
class BTree {
    struct node {
        int n;
        int values[order - 1];
        struct node *childs[order];
    };

    node *root = nullptr;

    int getPosition(int info, int *arr, int filled);

    bool splitting(node *temp, type info, type *strNode, node **newnode);

    void utilityPrint(node *temp, int tabs);

public:

    void Insert(type info);

    void Print();
};


#endif //DATA_STRUCTURES_BTREE_H