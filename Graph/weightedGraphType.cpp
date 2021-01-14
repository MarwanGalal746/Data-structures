//
// Created by marwan on 6/16/20.
//

#include "weightedGraphType.h"

void weightedGraphType::createWeightedGraph() {
    cout << "enter size of the graph: ";
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "enter number of a node and its weight: ";
        int vertex;
        cin >> vertex;
        int node = -1;
        cin >> node;
        while (node != -999) {
            int w;
            cin >> w;
            weight[vertex][node] = w;
            cin >> node;
        }
    }
}

weightedGraphType::weightedGraphType(int size) : graphType(size) {
    vector<int> temp(size, INT_MAX);
    for (int i = 0; i < size; ++i)
        weight.push_back(temp);
    smallestWeight=temp;
}

void weightedGraphType::shortestPath(int vertex) {
    for (int i = 0; i < weight.size(); i++)
        smallestWeight[i] = weight[vertex][i];
    smallestWeight[vertex] = 0;
    vector<bool> visited(weight.size(), 0);
    visited[vertex]=1;
    int Min = INT_MAX-1;
    for(int i = 0 ; i< weight.size()-1 ; i++){
        int v;
        int Min = INT_MAX-1;
        for(int r=0 ; r<weight.size() ; r++){
            if(!visited[r]){
                if(smallestWeight[r]<Min)
                    v=r,Min=smallestWeight[r];
            }
        }
        visited[v]=1;
        for(int r=0 ; r<weight.size();r++){
            if(!visited[r] && weight[v][r]<INT_MAX){
                if(Min + weight[v][r] < smallestWeight[r])
                    smallestWeight[r]=Min + weight[v][r];
            }
        }
    }
}

void weightedGraphType::printShortestDistance(int vertex) {
    cout << "Source Vertex: " << vertex << endl;
    cout << "Shortest distance from source to each vertex."
         << endl;
    cout << "Vertex Shortest_Distance" << endl;
    for (int j = 0; j < weight.size(); j++)
        cout << setw(4) << j << setw(12) << smallestWeight[j]
             << endl;
    cout << endl;
}

