//
// Created by break on 2023/11/15.
//

#ifndef UNTITLED1_ERCHATREE_H
#define UNTITLED1_ERCHATREE_H
#include <iostream>
#include <vector>
#include <queue>

struct node{
    int val;
    node* l_Child;
    node* r_Child;
    node(int x);
};

class erChaTree {
private:
    int MAX_Node_Num;
    int total_NodeNum;
    std:: vector<int> tree_IDX;
    node* root{};
public:
    erChaTree();
    erChaTree( std::vector<int> idx);
    erChaTree(const std::vector<int>& pre,const std::vector<int>& in);
    //计算个数
    int size();
    node* get_Root();
    //根据先序 中序 建树
    static int bfs(node* root , bool if_debug);
    node* build_Help(const std::vector<int>& preorder, const std::vector<int>& inorder, int preIndex, int inStart, int inEnd);
    //根据层序遍历建树
    void build_Tree(std::vector<int> idx);
    node* build(int idx);
    //先序遍历
    static void preorder(node* root);



};



#endif //UNTITLED1_ERCHATREE_H
