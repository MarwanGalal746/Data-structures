
#include "AVL.h"

template<class type>
AVL<type>::AVL() {
    root = nullptr;
}

template<class type>
node<type> *AVL<type>::rightRight(node<type> *newNode) {
    node<type> *temp;
    temp = newNode->right;
    newNode->right = temp->left;
    temp->left = newNode;
    return temp;
}

template<class type>
node<type> *AVL<type>::leftLeft(node<type> *newNode) {
    node<type> *temp;
    temp = newNode->left;
    newNode->left = temp->right;
    temp->right = newNode;
    int x, y, z;
    x = temp->info;
    y = temp->left->info;
    z = temp->right->info;
    return temp;
}

template<class type>
node<type> *AVL<type>::leftRight(node<type> *newNode) {
    node<type> *temp;
    temp = newNode->left->right;
    newNode->left->right = temp->left;
    temp->left = newNode->left;
    newNode->left = temp;
    newNode = leftLeft(newNode);
    return newNode;
}

template<class type>
node<type> *AVL<type>::rightLeft(node<type> *newNode) {
    node<type> *temp;
    temp = newNode->right->left;
    newNode->right->left = temp->right;
    temp->right = newNode->right;
    newNode->right = temp;
    newNode = rightRight(newNode);
    return newNode;
}

template<class type>
int AVL<type>::height(node<type> *newNode) const {
    if (newNode == nullptr)
        return 0;
    return 1 + max(height(newNode->left), height(newNode->right));
}

template<class type>
int AVL<type>::balanceFactor(node<type> *newNode) const {
    return height(newNode->left) - height(newNode->right);
}

template<class type>
node<type> *AVL<type>::balancing(node<type> *newNode) {
    if (balanceFactor(newNode) > 1) {
        if (balanceFactor(newNode->left) > 0)
            newNode = leftLeft(newNode);
        else
            newNode = leftRight(newNode);
    } else if (balanceFactor(newNode) < -1) {
        if (balanceFactor(newNode->right) > 0)
            newNode = rightLeft(newNode);
        else
            newNode = rightRight(newNode);
    }
    return newNode;
}

template<class type>
void AVL<type>::insert(const type &ele, node<type> *&newNode) {
    if (newNode == nullptr) {
        node<type> *temp = new node<type>;
        temp->info = ele;
        temp->left = temp->right = nullptr;
        newNode = temp;
    }
    if (ele < newNode->info) {
        insert(ele, newNode->left);
        newNode = balancing(newNode);
    } else if (ele > newNode->info) {
        insert(ele, newNode->right);
        newNode = balancing(newNode);
    }
}

template<class type>
void AVL<type>::insertAVL(const type &ele) {
    if (root == nullptr) {
        root = new node<type>;
        root->info = ele;
        root->right = root->left = nullptr;
    } else {
        insert(ele, root);
    }

}

template<class type>
void AVL<type>::print2DUtil(node<type> *newNode, int space) {
    if (newNode == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(newNode->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    cout << newNode->info << "\n";

    // Process left child
    print2DUtil(newNode->left, space);
}

template<class type>
void AVL<type>::print2D() {
    print2DUtil(root, 0);
}

template<class type>
void AVL<type>::inorderTraversal() const {
    inorder(root);
    cout << endl;
}

template<class type>
void AVL<type>::inorder(node<type> *newNode) const {
    if (newNode != nullptr) {
        inorder(newNode->left);
        cout << newNode->info << " ";
        inorder(newNode->right);
    }
}

template<class type>
node<type> *AVL<type>::deleteSpecialNode(node<type> *victim, node<type> *current, const type &ele) {
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
    current = balancing(current);
    return current;
}

template<class type>
node<type> *AVL<type>::deleting(node<type> *current, const type &ele) {
    if (current == nullptr) {
        cout << "not found\n";
        return nullptr;
    }

    if (current->info > ele) {
        current->left = deleting(current->left, ele);
        current = balancing(current);
        return current;
    } else if (current->info < ele) {
        current->right = deleting(current->right, ele);
        current = balancing(current);
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
void AVL<type>::deleteAVL(const type &ele) {
    root = deleting(root, ele);
}