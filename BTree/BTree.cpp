//
// Created by marwan on 1/14/21.
//

#include "BTree.h"
#include <iostream>

using namespace std;

template<class type, int order>
int BTree<type, order>::getPosition(int info, int *arr, int filled) {
    return 0;
}

template<class type, int order>
bool BTree<type, order>::splitting(BTree::node *temp, type info, type *strNode, BTree::node **newnode) {
    node *newNode, *endNode;
    int pos, i, n, splittingIndex;
    type newKey, endKey;
    bool cond;
    if (temp == nullptr) {
        *newnode = nullptr;
        *strNode = info;
        return false;
    }
    n = temp->n;
    pos = getPosition(info, temp->values, n);
    cond = splitting(temp->childs[pos], info, &newKey, &newNode);
    if (cond)
        return cond;
    if (n < order - 1) {
        pos = getPosition(newKey, temp->values, n);
        for (i = n; i > pos; i--) {
            temp->values[i] = temp->values[i - 1];
            temp->childs[i + 1] = temp->childs[i];
        }
        temp->values[pos] = newKey;
        temp->childs[pos + 1] = newNode;
        ++temp->n;
        return true;
    }
    if (pos == order - 1) {
        endKey = newKey;
        endNode = newNode;
    } else {
        endKey = temp->values[order - 2];
        endNode = temp->childs[order - 1];
        for (i = order - 2; i > pos; i--) {
            temp->values[i] = temp->values[i - 1];
            temp->childs[i + 1] = temp->childs[i];
        }
        temp->values[pos] = newKey;
        temp->childs[pos + 1] = newNode;
    }
    splittingIndex = (order - 1) / 2;
    *strNode = temp->values[splittingIndex];
    *newnode = new node[order];
    temp->n = splittingIndex;
    (*newnode)->n = order - 1 - splittingIndex;
    for (i = 0; i < (*newnode)->n; i++) {
        (*newnode)->childs[i] = temp->childs[i + splittingIndex + 1];
        if (i < (*newnode)->n - 1)
            (*newnode)->values[i] = temp->values[i + splittingIndex + 1];
        else
            (*newnode)->values[i] = endKey;
    }
    (*newnode)->childs[(*newnode)->n] = endNode;
    return false;
}

template<class type, int order>
void BTree<type, order>::utilityPrint(BTree::node *temp, int tabs) {
    if (temp) {
        int i;
        for (i = 1; i <= tabs; i++)
            cout << " ";
        for (i = 0; i < temp->n; i++)
            cout << (type) temp->values[i] << " ";
        cout << endl;
        for (i = 0; i <= temp->n; i++)
            utilityPrint(temp->childs[i], tabs + 1);
    }
}

template<class type, int order>
void BTree<type, order>::Insert(type info) {
    node *tempNode;
    type strNode;
    bool value;
    value = splitting(root, info, &strNode, &tempNode);
    if (!value) {
        node *utiNode = root;
        root = new node;
        root->n = 1;
        root->values[0] = strNode;
        root->childs[0] = utiNode;
        root->childs[1] = tempNode;
    }
}

template<class type, int order>
void BTree<type, order>::Print() {
    utilityPrint(root, 0);
}