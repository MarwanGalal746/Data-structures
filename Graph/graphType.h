//
// Created by marwan on 6/15/20.
//

#ifndef GRAPH_GRAPHTYPE_H
#define GRAPH_GRAPHTYPE_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class graphType {
    void dft(int ind, bool visited[]);

protected:
    int maxSize;
    int gSize;
    vector<vector<int>> graph;
public:
    bool isEmpty() const;

    void createGraph();

    void clearGraph();

    void printGraph() const;

    void depthFirstTraversal();

    void dftAtVertex(int vertex);

    void breadthFirstTraversal();

    explicit graphType(int size = 0);

    ~graphType();
};


#endif //GRAPH_GRAPHTYPE_H