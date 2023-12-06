//
// Created by break on 2023/11/17.
//

#include "BinarySearchTree.h"
#include <iostream>

template<typename T>
BinarySearchTree<T>::BinarySearchTree(){
    this->root = nullptr;
    node_num = 0;
}

template<typename T>
void BinarySearchTree<T>::insert(T val) {
    root = insert_help(root , val);
}
template<typename T>
node<T>* BinarySearchTree<T>::insert_help(node<T> *t, T val) {
    if(t == nullptr){
        node_num ++;
        return new node(val);
    }
    else{

        //std::cerr<<val<<' '<<t->val<<'\n';

        if(val < t->val){
            t->l_Child = insert_help(t->l_Child , val);
        }
        else{
            t->r_Child = insert_help(t->r_Child , val);
        }
    }

    return t;
}
template<typename T>
node<T>* BinarySearchTree<T>::find(T val) {
    return find_help(root , val);
}
template<typename T>
node<T>* BinarySearchTree<T>::find_help(node<T> *t, T val) {
    //std::cerr<<t->val<<'\n';
    if(t == nullptr || t->val == val){
        return t;
    }
    else{
        if(val < t->val){
            return find_help(t->l_Child , val);
        }
        else{
            return find_help(t->r_Child , val);
        }
    }
}

template<typename T>
node<T> *BinarySearchTree<T>::get_Root() {
    return this->root;
}

template<typename T>
void BinarySearchTree<T>::inOrder(node<T> *root) {
    if(root == nullptr) return;
    inOrder(root->l_Child);
    std::cout << root->val << ' ';
    inOrder(root->r_Child);
}

template<typename T>
int BinarySearchTree<T>::size() {
    return this->node_num;
}