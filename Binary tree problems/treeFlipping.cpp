#include <iostream>
#include <queue>
using namespace std;
template<typename T>
struct Tree {
    Tree(const T &v) : value(v), left(NULL), right(NULL) {}
    T value;
    Tree *left;
    Tree *right;
};
template<typename T>
void flip(Tree<T>*&temp){
    if(temp!=NULL){
        swap(temp->left , temp->right);
        flip(temp->left);
        flip(temp->right);
    }
}
template<typename T>
void inorder(Tree<T>*&root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->value<<" ";
        inorder(root->right);
    } else
        return;
}
int main() {
    Tree<int>* t = new Tree<int>(1);
    Tree<int>* _1_left = new Tree<int>(2);
    Tree<int>* _1_right = new Tree<int>(3);
    t->left = _1_left;
    t->right = _1_right;
    Tree<int>* _2_left = new Tree<int>(4);
    Tree<int>* _2_right = new Tree<int>(5);
    _1_left->left = _2_left; _1_left->right =
                                     _2_right;
    cout<<"Before flipping: \n";
    /*
     *          1
     *         / \
     *        2   3
     *       / \
     *      4   5
     * */
    cout<<"inorder (Left, Root, Right) : ";
    inorder(t);
    flip(t);
    cout<<endl<<endl<<"After flipping: \n";
    /*
     *          1
     *         / \
     *        3   2
     *           / \
     *          5   4
     * */
    cout<<"inorder (Left, Root, Right) : ";
    inorder(t);
    return 0;
}