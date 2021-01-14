//
// Created by marwan on 6/18/20.
//

#include "toplogical.h"

toplogical::toplogical(int size) {
    vector<int> temp;
    for (int i = 0; i < size; i++) {
        temp.push_back(-1);
        predcessors.push_back(0);
        suc.push_back(0);
    }
    for (int i = 0; i < size; i++)
        graph.push_back(temp);
}

void toplogical::createTopo() {
    cout << "enter size of the graph: ";
    cin >> gSize;
    for (int i = 0; i < gSize; i++) {
        cout << "enter number of a node: ";
        int vertex;
        cin >> vertex;
        int node = -1;
        cin >> node;
        while (node != -999) {
            graph[vertex][node] = 1;
            suc[vertex]++;
            predcessors[node]++;
            cin >> node;
        }
    }
    for (int i = 0; i < gSize; i++) {
        if (predcessors[i] == 0)
            q.push(i);
    }
}

void toplogical::BFT() {
    while (!q.empty()) {
        order.push_back(q.front());
        for (int i = 0; i < gSize; i++) {
            if (graph[q.front()][i] != -1 && predcessors[i] != 0) {
                predcessors[i]--;
                if (predcessors[i] == 0)
                    q.push(i);
            }
        }
        q.pop();
    }
}

void toplogical::print() {
    for (int i = 0; i < gSize; i++)
        cout << order[i] << " ";
    cout << endl;
}

void toplogical::DFT() {
    stack<int> s;
    vector<bool> visited(gSize, false);
    while (s.size() < gSize) {
        int Min = INT_MAX, ind;
        for (int i = 0; i < gSize; i++) {
            if (suc[i] < Min && !visited[i])
                Min = suc[i], ind = i;
        }
        depth(s,visited,ind);
        visited[ind]=true;
        s.push(ind);
    }
    while (s.size()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

void toplogical::depth(stack<int> &s, vector<bool> &visited, const int &ind) {
    for(int i=0;i<gSize;i++){
        int x=graph[2][3] , y=visited[3];
        if( graph[ind][i]!=-1&& !visited[i]){
            visited[i]=true;
            depth(s,visited,ind);
            s.push(i);
        }
    }
}