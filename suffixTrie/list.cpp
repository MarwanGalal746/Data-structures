//
// Created by marwan on 1/14/21.
//

#include "Node.cpp"
#include "Node.h"
#include "TrieNode.h"
#include "TrieNode.cpp"
#include "list.h"
list::list() {
    root = nullptr;
}

Node *list::begin() {
    return root;
}

Node *list::last() {
    Node *temp = root;
    while (temp->next != nullptr)
        temp = temp->next;
    return temp;
}

void list::push(TrieNode *c) {
    if (root == nullptr) {
        root = new Node;
        root->next = nullptr;
        root->data = c;
        return;
    }
    Node *newNode = new Node;
    newNode->data = c;
    newNode->next = nullptr;
    Node *temp = root;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}