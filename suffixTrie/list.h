//
// Created by marwan on 1/14/21.
//

#ifndef DATA_STRUCTURES_LIST_H
#define DATA_STRUCTURES_LIST_H

#include "Node.cpp"
#include "Node.h"
#include "TrieNode.h"
#include "TrieNode.cpp"
#include "list.cpp"
class list {
    Node *root;
public:
    list();

    Node *begin();

    Node *last();

    void push(TrieNode *c);

    friend class TrieNode;

    friend class suffixTrie;;
};


#endif //DATA_STRUCTURES_LIST_H