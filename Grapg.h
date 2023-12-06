//
// Created by break on 2023/11/16.
//

#ifndef UNTITLED1_GRAPG_H
#define UNTITLED1_GRAPG_H

#include <list>
#include <unordered_map>
using std::list;
using std::unordered_map;


struct node{
    int next;
    node(int next):next(next){}
};

class Graph {
private:
    int vertices_Num;

public:
    list<node*>* adjlist;
    Graph(int num);
    void addEdge(int current , int next);
    void DFS(int u , unordered_map<int , bool>& vis);

};


#endif //UNTITLED1_GRAPG_H
