//
// Created by marwan on 6/14/20.
//

#include "binaryTree.h"

template<class type>
bool binaryTree<type>::isEmpty() const {
    return root = nullptr;
}

template<class type>
void binaryTree<type>::inorder(node<type> *newNode) const {
    if (newNode != nullptr) {
        inorder(newNode->left);
        cout << newNode->info << " ";
        inorder(newNode->right);
    }
}

template<class type>
void binaryTree<type>::inorderTraversal() const {
    inorder(root);
    cout << endl;
}

template<class type>
void binaryTree<type>::preorder(node<type> *newNode) const {
    if (newNode != nullptr) {
        cout << newNode->info << " ";
        preorder(newNode->left);
        preorder(newNode->right);
    }
}

template<class type>
void binaryTree<type>::preorderTraversal() const {
    preorder(root);
    cout << endl;
}

template<class type>
void binaryTree<type>::postorder(node<type> *newNode) const {
    if (newNode != nullptr) {
        postorder(newNode->left);
        postorder(newNode->right);
        cout << newNode->info << " ";
    }
}

template<class type>
void binaryTree<type>::postorderTraversal() const {
    postorder(root);
    cout << endl;
}

template<class type>
int binaryTree<type>::height(const node<type> *&newNode) const {
    if (newNode == nullptr)
        return 0;
    return 1 + max(height(newNode->left), height(newNode->right));
}

template<class type>
int binaryTree<type>::treeHeight() const {
    height(root);
}

template<class type>
int binaryTree<type>::NodeCount(const node<type> *&newNode) const {
    if (newNode == nullptr)
        return 0;
    return 1 + NodeCount(newNode->left) + NodeCount(newNode->right);
}

template<class type>
int binaryTree<type>::treeNodeCount() const {
    NodeCount(root);
}

template<class type>
int binaryTree<type>::LeavesCount(const node<type> *&newNode) const {
    if (newNode == nullptr)
        return 1;
    return 0 + LeavesCount(newNode->left) + LeavesCount(newNode->right);
}

template<class type>
int binaryTree<type>::treeLeavesCount() const {
    LeavesCount(root);
}

template<class type>
void binaryTree<type>::destroy(node<type> *&newNode) {
    if (newNode != nullptr) {
        destroy(newNode->left);
        destroy(newNode->right);
        delete newNode;
        newNode = nullptr;
    }
}

template<class type>
void binaryTree<type>::destroyTree() {
    destroy(root);
}

template<class type>
binaryTree<type>::~binaryTree<type>() {
    destroyTree();
}

template<class type>
binaryTree<type>::binaryTree() {
    root = nullptr;
}

template<class type>
void binaryTree<type>::copy(node<type> *&rootTree, const node<type> *&otherTree) {
    if (otherTree == nullptr)
        rootTree = nullptr;
    else {
        rootTree = new node<type>;
        rootTree->info = otherTree->info;
        copy(rootTree->left, otherTree->left);
        copy(rootTree->right, otherTree->right);
    }
}

template<class type>
binaryTree<type>::binaryTree(const binaryTree<type> &otherTree) {
    copy(root, otherTree);
}

template<class type>
const binaryTree<type> &binaryTree<type>::operator=(const binaryTree<type> &otherTree) {
    if (this != &otherTree) {
        if (root != nullptr)
            destroy(root);
        else if (otherTree.root == nullptr)
            root = nullptr;
        else
            copy(root, otherTree);
    }
    return *this;
}

template<class type>
void binaryTree<type>::itrInorder(node<type> *newNode) const {
    stack<node<type> *> nodes;
    node<type> *current = newNode;
    while (current != nullptr || !nodes.empty()) {
        if (current != nullptr) {
            nodes.push(current);
            current = current->left;
        } else {
            current = nodes.top();
            nodes.pop();
            cout << current->info << " ";
            current = current->right;
        }
    }
    cout << endl;
}

template<class type>
void binaryTree<type>::inorderiteration() const {
    itrInorder(root);
}

template<class type>
void binaryTree<type>::itrPreorder(node<type> *newNode) const {
    stack<node<type> *> nodes;
    node<type> *current = newNode;
    while (current != nullptr || !nodes.empty()) {
        if (current != nullptr) {
            cout << current->info << " ";
            nodes.push(current);
            current = current->left;
        } else {
            current = nodes.top();
            nodes.pop();
            current = current->right;
        }
    }
    cout << endl;
}

template<class type>
void binaryTree<type>::preorderiteration() const {
    itrPreorder(root);
}

template<class type>
void binaryTree<type>::itrPostorder(node<type> *newNode) {
    stack<node<type> *> nodes1;
    stack<node<type> *> nodes2;
    nodes1.push(newNode);
    while (!nodes1.empty()) {
        node<type> *temp = nodes1.top();
        nodes1.pop();
        nodes2.push(temp);
        if (temp->right != nullptr)
            nodes1.push(temp->right);
        if (temp->left != nullptr)
            nodes1.push(temp->left);
    }
    while (!nodes2.empty())
        cout << nodes2.top() << " ", nodes2.pop();
    cout << endl;
}

template<class type>
void binaryTree<type>::postorderiteration() const {
    itrpostrder(root);
}