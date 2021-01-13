//
// Created by marwan on 1/14/21.
//

#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H

#include "TrieNode.h"

class Node {
    TrieNode *data;
    Node *next;

    friend class list;

    friend class TrieNode;

    friend class suffixTrie;
};


#endif //DATA_STRUCTURES_NODE_H
