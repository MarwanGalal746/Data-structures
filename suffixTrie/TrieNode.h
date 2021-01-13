//
// Created by marwan on 1/14/21.
//

#ifndef DATA_STRUCTURES_TRIENODE_H
#define DATA_STRUCTURES_TRIENODE_H


//#include "list.h"

#include "Node.cpp"
#include "Node.h"
#include "TrieNode.h"
#include "TrieNode.cpp"
#include "list.cpp"
#include "list.h"
class TrieNode {
    char c;
    list l;

    friend class suffixTrie;
};



#endif //DATA_STRUCTURES_TRIENODE_H
