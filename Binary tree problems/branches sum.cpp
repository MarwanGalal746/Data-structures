#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>
using namespace std;
template<typename T>
struct Tree {
    Tree(const T &v) : value(v), left(NULL), right(NULL) {}
    T value;
    Tree *left;
    Tree *right;
};

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
void sum(Tree<T>*&first ,vector<pair<int,string>>&st ,string s="" ){

    if(first!=NULL){
        stringstream ss;
        ss << first->value;
        string str = ss.str();
        s+=str;
        sum(first->left , st , s);
        sum(first->right , st , s);
    }
    st.emplace_back(s.length() , s);

}
template<typename T>
long digitSum(Tree<T>*&root){
    vector<pair<int , string>>st;
    sum(root , st);
    vector<pair<int , string>>::iterator itr;
    sort(st.begin() , st.end());
    reverse(st.begin() , st.end());
    string temp="";
    vector<int>num;
    for(int i=0 ; i<st.size() ; i++){
        if(temp.find(st[i].second)==-1){
            temp+=st[i].second;
            stringstream convert(st[i].second);
            int x=0;
            convert >>x;
            num.push_back(x);
        }
    }
    return accumulate(num.begin() , num.end() , 0);
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
    cout<<endl<<"Branches sum: ";
    cout<<digitSum(t);
    cout<<endl;
    return 0;
}