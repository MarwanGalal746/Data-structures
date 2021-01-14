#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
template<typename T>
struct Tree {
    Tree(const T &v) : value(v), left(NULL), right(NULL) {}
    T value;
    Tree *left;
    Tree *right;
};
template<typename T>
void insert(Tree<T>*&root,const T &info) {
    Tree <T> *newNode = new Tree<T>(info);
    queue<Tree <T>*>q;
    if(root==NULL){
        root=newNode;
        return;
    }
    q.push(root);
    while(!q.empty()){
        if(q.front()->left == NULL){
            q.front()->left=newNode;
            break;
        }
        else
            q.push(q.front()->left);
        if(q.front()->right == NULL){
            q.front()->right=newNode;
            break;
        }
        else
            q.push(q.front()->right);
        q.pop();
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
template<typename T>
void largestValues(Tree<T>*&root) {
    try {
        string s;
        if (root == NULL)
            throw s;

        queue<pair<Tree<T> *, int>> q;
        vector<int> res;
        vector<int> val;
        q.push(make_pair(root, 1));
        int level = 1;
        while (!q.empty()) {
            if (q.front().second == level)
                val.push_back(q.front().first->value);
            else
                res.push_back(*max_element(val.begin(), val.end())), val.clear(), level++;
            if (q.front().first->left != NULL)
                q.push(make_pair(q.front().first->left, level + 1));
            if (q.front().first->right != NULL)
                q.push(make_pair(q.front().first->right, level + 1));
            q.pop();
        }
        res.push_back(*max_element(val.begin(), val.end())), val.clear(), level++;
        cout<<'[';
        for(int i=0 ; i<res.size();i++){
            if(i!=res.size()-1)
                cout<<res[i]<<", ";
            else
                cout<<res[i]<<']';
        }
    }
    catch (string&s) {
        cout << "TREE IS EMPTY !\n";
    }
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
    cout<<"inorder (Left, Root, Right) : ";
    inorder(t);
    cout<<endl<<"Largest values in the tree: ";
    largestValues(t);
    cout<<endl;
    return 0;
}