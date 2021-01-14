//
// Created by marwan on 6/18/20.
//

#ifndef GRAPH_TOPLOGICAL_H
#define GRAPH_TOPLOGICAL_H
#include "graphType.h"
#include <queue>
#include <stack>
#include<bits/stdc++.h>

class toplogical : public graphType {
protected:
    vector<int>predcessors;
    vector<int>suc;
    queue<int>q;
    vector<int>order;
    //   vector<vector<int>>graph;
public:
    explicit toplogical(int size=0);
    void createTopo();
    void BFT();
    void print();
    void DFT();
    void depth(stack<int>&s , vector<bool>&visited, const int &ind);
};


#endif //GRAPH_TOPLOGICAL_H