//
// Created by marwan on 6/15/20.
//

#include "graphType.h"

bool graphType::isEmpty() const {
    return !gSize;
}

graphType::graphType(int size) {
    gSize = 0;
    maxSize = size;
    vector<int>temp;
    for(int i=0 ; i<size;i++)
        graph.push_back(temp);
}

void graphType::createGraph() {
    cout << "Enter number of vertices: ";
    cin >> gSize;
    for (int i = 0; i < gSize; i++) {
        cout << "enter number of a node: ";
        int vertex;
        cin >> vertex;
        int node = -1;
        cin >> node;
        vector<int> temp;
        while (node != -999) {
            temp.push_back(node);
            cin >> node;
        }
        graph[vertex]=temp;
    }

}

void graphType::clearGraph() {
    for (int i = 0; i < gSize; i++) {
        graph[i].clear();
    }
    gSize = 0;
}

void graphType::printGraph() const {
    //cout << gSize << " " << graph.size();
    for (int i = 0; i < gSize; ++i) {
        cout << "index " << i << " : ";
        for (int r = 0; r < graph[i].size(); r++) {
            cout << graph[i][r] << " ";
        }
        cout << endl;
    }
}

graphType::~graphType() {
    clearGraph();
}

void graphType::dft(int ind, bool *visited) {
    cout << ind << " ";
    visited[ind] = true;
    for (int r = 0; r < graph[ind].size(); r++) {
        int w = graph[ind][r];
        if (!visited[w])
            dft(w, visited);
    }
}

void graphType::depthFirstTraversal() {
    bool *visited;
    visited = new bool[gSize];
    for (int i = 0; i < gSize; i++)
        visited[i] = false;
    for (int i = 0; i < gSize; i++) {
        if (!visited[i])
            dft(i, visited);
    }
    cout << endl;
    delete[] visited;
}

void graphType::dftAtVertex(int vertex) {
    bool *visited;
    visited = new bool[gSize];
    for (int i = 0; i < gSize; i++)
        visited[i] = 0;
    dft(vertex, visited);
    delete[] visited;
}

void graphType::breadthFirstTraversal() {
    bool *visited;
    visited = new bool[gSize];
    for (int i = 0; i < gSize; i++)
        visited[i] = 0;
    queue<int> q;
    for (int i = 0; i < gSize; i++) {
        if (!visited[i]) {
            cout << i << " ";
            visited[i]=true;
            q.push(i);
            while (!q.empty()) {
                for (int r = 0; r < graph[q.front()].size(); r++) {
                    if (!visited[graph[q.front()][r]]) {
                        cout << graph[q.front()][r] << " ";
                        q.push(graph[q.front()][r]);
                        visited[graph[q.front()][r]] = true;
                    }
                }
                q.pop();
            }
        }
    }
    cout << endl;
}



