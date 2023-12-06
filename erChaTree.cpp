//
// Created by break on 2023/11/15.
//

#include "erChaTree.h"
#include <algorithm>

node::node(int x) {
    val = x;
    l_Child = nullptr;
    r_Child = nullptr;
}

erChaTree::erChaTree() {
    MAX_Node_Num = 0;
    root = nullptr;
}

erChaTree::erChaTree(std::vector<int> idx) {
    this->MAX_Node_Num = idx.size();
    this->tree_IDX = idx;
    //std::cerr<<idx.size()<<std::endl;
    build_Tree(idx);
}

//以下标0元素为根开始建树
void erChaTree::build_Tree(std::vector<int> idx) {
    if (idx.empty()) {
        std::cerr << "error: input vector empty" << std::endl;
        return;
    }

    auto rt = new node(idx[0]);
    this->root = rt;

    // 递归建树
    root->l_Child = build(1);
    root->r_Child = build(2);

}

node* erChaTree::build(int idx) {
    if (idx < 0 || idx >= tree_IDX.size() || tree_IDX[idx] == -1) {
        //std::cerr<<"uncommon error";
        return nullptr;
    }

    auto tmp_Node = new node(tree_IDX[idx]);

    tmp_Node->l_Child = build(idx * 2 + 1);
    tmp_Node->r_Child = build(idx * 2 + 2);

    return tmp_Node;
}

//广搜，用于验证树结构以及统计节点数 用一个bool值表示是否输出遍历顺序
int erChaTree::bfs(node* root , bool if_debug){
    int tot_node_num = 0;
    std::queue<node*> q;
    q.push(root);

    while(!q.empty()){
        auto t = q.front();
        tot_node_num ++;
        q.pop();
        if(if_debug){
            std::cout << t->val << ' ';
        }
        if(t->l_Child != nullptr){
            q.push(t->l_Child);
        }
        if(t->r_Child != nullptr){
            q.push(t->r_Child);
        }

    }
    return tot_node_num;
}

int erChaTree::size() {
    return this->bfs(this->get_Root() , false);
}

node* erChaTree::get_Root() {
    return this->root;
}

erChaTree::erChaTree(const std::vector<int> &pre, const std::vector<int> &in) {
    this->root = build_Help(pre , in , 0 , 0 , in.size()-1);
}

node* erChaTree::build_Help(const std::vector<int> &pre, const std::vector<int> &in, int preIndex,
                            int inStart, int inEnd) {
    if(preIndex >= pre.size() || inStart > inEnd){
        return nullptr;
    }
    int rootVal = pre[preIndex];
    auto newNode = new node(rootVal);
    //找到根节点对应下标
    int rootIndex = std::find(in.begin() + inStart , in.begin() + inEnd + 1 , rootVal) - in.begin();

    newNode->l_Child = build_Help(pre , in , preIndex + 1 , inStart , rootIndex - 1);
    newNode->r_Child = build_Help(pre , in , preIndex + (rootIndex - inStart) + 1 , rootIndex + 1 , inEnd);
    return newNode;
}

void erChaTree::preorder(node* root) {
    if(root != nullptr){
        std::cout<< root->val<<' ';
        preorder(root->l_Child);
        preorder(root->r_Child);
    }
}
