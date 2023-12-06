//
// Created by break on 2023/11/16.
//

#include "Grapg.h"
#include <iostream>

Graph::Graph(int num) {
    this->vertices_Num = num;
    adjlist = new list<node*>[num];
}

//添加一条从 current 到 next的边
void Graph::addEdge(int current, int next) {
    auto newNode = new node(next);
    adjlist[current].push_back(newNode);
}

void Graph::DFS(int u , unordered_map<int , bool>& vis){
    if(vis[u]){
        return;
    }
    vis[u] = true;
    std::cout<< u << ' ';
    for(auto t : adjlist[u]){
        DFS(t->next , vis);
    }
}


