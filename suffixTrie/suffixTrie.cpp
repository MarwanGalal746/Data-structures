//
// Created by marwan on 1/14/21.
//

#include "suffixTrie.h"
#include <iostream>
using namespace std;
int suffixTrie::size(char *arr) {
    int res = 0;
    for (int i = 0; arr[i] != '\0'; i++)
        res++;
    return res;
}

TrieNode *suffixTrie::utilInsert(char info, TrieNode *temp) {
    char x = temp->c;
    Node *loopNode = temp->l.begin();
    while (loopNode != nullptr) {
        if (loopNode->data->c == info) {
            return loopNode->data;
        }
        loopNode = loopNode->next;
    }
    TrieNode *newTrieNode = new TrieNode;
    newTrieNode->c = info;
    temp->l.push(newTrieNode);
    temp = temp->l.last()->data;
    return temp;
}

void suffixTrie::insert(char *arr, int ind) {
    TrieNode *temp = root;
    for (int i = ind; i < len; i++) {
        if (ind == len - 1) {
            TrieNode *newNode = new TrieNode;
            newNode->c = arr[i];
            root->l.push(newNode);
            break;
        } else
            temp = utilInsert(arr[i], temp);
    }
}

suffixTrie::suffixTrie(char *arr) {
    str = arr;
    root = new TrieNode;
    root->c = '.';
    len = size(arr);
    for (int i = len - 1; i >= 0; i--)
        insert(arr, i);
}

void suffixTrie::Search(char *arr) {
    TrieNode *tempTemp;
    int subLen = size(arr);
    int nodeCounter = 0;
    TrieNode *temp = root;
    for (int i = 0; i < len; i++) {
        char x = str[i];
        Node *loopNode = temp->l.begin();
        while (loopNode != nullptr) {
            tempTemp=temp;
            char y = loopNode->data->c;
            if (loopNode->data->c == str[i]) {
                temp = loopNode->data;
                if (loopNode->data->c == arr[nodeCounter]) {
                    if (subLen > 1) {
                        if (nodeCounter == 1)
                            tempTemp = temp;
                    }
                    nodeCounter++;
                } else{
                    if(nodeCounter>1){
                        temp=tempTemp;
                        i--;
                    }
                    nodeCounter = 0;
                }
                break;
            }
            loopNode = loopNode->next;
        }
        if (nodeCounter == subLen) {
            cout << i - nodeCounter + 1 << " ";
            i = i - nodeCounter + 1;
            nodeCounter = 0;
            temp = tempTemp;
        }
    }
    cout << endl;
}
