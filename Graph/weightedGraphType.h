//
// Created by marwan on 6/16/20.
//

#ifndef GRAPH_WEIGHTEDGRAPHTYPE_H
#define GRAPH_WEIGHTEDGRAPHTYPE_H

#include <iostream>
#include "graphType.h"
#include<bits/stdc++.h>


using namespace std;

class weightedGraphType : public graphType {
protected:
    vector<vector<int>> weight;
    vector<int> smallestWeight;
public:
    void createWeightedGraph();

    void shortestPath(int vertex);

    void printShortestDistance(int vertex);

    explicit weightedGraphType(int size = 0);

    // ~weightedGraphType();
};


#endif //GRAPH_WEIGHTEDGRAPHTYPE_H