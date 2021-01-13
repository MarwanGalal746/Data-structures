//
// Created by marwan on 1/14/21.
//

#ifndef DATA_STRUCTURES_SUFFIXTRIE_H
#define DATA_STRUCTURES_SUFFIXTRIE_H


#include "list.h"
#include "list.cpp"
class suffixTrie {
    TrieNode *root;
    int len;
    char *str;

    int size(char arr[]);

    TrieNode *utilInsert(char info, TrieNode *temp);

    void insert(char arr[], int ind);

public:

    suffixTrie(char arr[]);

    void Search(char arr[]);


};



#endif //DATA_STRUCTURES_SUFFIXTRIE_H
