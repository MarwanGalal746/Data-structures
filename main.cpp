#include <iostream>
#include "suffixTrie/suffixTrie.h"
#include "suffixTrie/suffixTrie.cpp"
#include "suffixTrie/suffixTrie.h"
#include "suffixTrie/suffixTrie.cpp"
#include "BTree/BTree.h"
#include "BTree/BTree.cpp"

int main() {
    //BTree test
    cout<<"BTree test: \n\n";
    BTree<int, 3> t;
    t.Insert(1);
    t.Insert(5);
    t.Insert(0);
    t.Insert(4);
    t.Insert(3);
    t.Insert(2);
    t.Print();
    cout<<endl<<endl;
    return 0;
}
