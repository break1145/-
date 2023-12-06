//
// Created by break on 2023/11/17.
//

#ifndef UNTITLED1_BINARYSEARCHTREE_H
#define UNTITLED1_BINARYSEARCHTREE_H

template<typename T>
struct node{
    T val;
    node* l_Child;
    node* r_Child;
    node(T v):val (v){
        l_Child = nullptr;
        r_Child = nullptr;
    };
};


template<typename T>
class BinarySearchTree {
private:
    node<T>* root;
    int node_num;
public:
    BinarySearchTree();
    void insert(T val);
    node<T>* insert_help(node<T>* t , T val);
    node<T>* find_help(node<T>* t , T val);
    node<T>* find(T val);
    node<T>* get_Root();
    void inOrder(node<T>* root);
    int size();

};




#include "BinarySearchTree.tpp"

#endif //UNTITLED1_BINARYSEARCHTREE_H
