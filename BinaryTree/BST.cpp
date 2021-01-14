//
// Created by marwan on 6/14/20.
//

#include "BST.h"

template<class type>
bool BST<type>::search(const type &ele, node<type> *&newNode) const {
    node<type> *current = newNode;
    while (current != nullptr) {
        if (current->info == ele)
            return true;
        if (current->info > ele)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

template<class type>
bool BST<type>::bstSearch(const type &ele) {
    search(ele, this->root);
}

template<class type>
void BST<type>::insert(const type &ele, node<type> *&newNode) {
    if (newNode == nullptr) {
        newNode = new node<type>;
        newNode->info = ele;
    } else {
        if (newNode->info > ele)
            insert(ele, newNode->left);
        else
            insert(ele, newNode->right);
    }
}

template<class type>
void BST<type>::bstInsert(const type &ele) {
    insert(ele, this->root);
}

template<class type>
node<type> *BST<type>::deleteSpecialNode(node<type> *victim, node<type> *current, const type &ele) {
    if (current->right == nullptr) {
        swap(victim->info, current->info);
        if (current->left == nullptr) {
            node<type> *temp = current->right;
            delete current;
            return temp;
        } else if (current->right == nullptr) {
            node<type> *temp = current->left;
            delete current;
            return temp;
        }
    }
    current->right = deleteSpecialNode(victim, current->right, ele);
    return current;
}

template<class type>
node<type> *BST<type>::deleting(node<type> *current, const type &ele) {
    if (current == nullptr) {
        cout << "not found\n";
        return nullptr;
    }

    if (current->info > ele) {
        current->left = deleting(current->left, ele);
        return current;
    } else if (current->info < ele) {
        current->right = deleting(current->right, ele);
        return current;
    } else {
        if (current->left == nullptr) {
            node<type> *temp = current->right;
            delete current;
            return temp;
        } else if (current->right == nullptr) {
            node<type> *temp = current->left;
            delete current;
            return temp;
        } else {
            current->left = deleteSpecialNode(current, current->left, ele);
            return current;
        }
    }
}

template<class type>
void BST<type>::bstDelete(const type &ele) {
    this->root = deleting(this->root, ele);
}