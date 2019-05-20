//
//  BinTree.hpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/21.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef BinTree_hpp
#define BinTree_hpp
#include "CommonHeader.hpp"
#include <stack>
#include <queue>
#define ElementType int


typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreOrderTraversal(BinTree BT){
    BinTree T = BT;
    stack<TreeNode *> S = stack<TreeNode *>();  /*创建并初始化堆栈S*/
    while(T || !S.empty()){
        while(T){  /*一直向左并将沿途结点压入堆栈*/
            S.push(T);  // 第一次
            printf("%5d", T->Data);  /*（访问）打印结点*/
            T = T->Left;
        }
        if (!S.empty()){
            T = S.top();  /*结点弹出堆栈*/  // 第二次
            T = T->Right;  /*转向右子树*/
            S.pop();
        }
    }
}


void InOrderTraversal(BinTree BT){
    BinTree T = BT;
    stack<TreeNode *> S = stack<TreeNode *>();  /*创建并初始化堆栈S*/
    while(T || !S.empty()){
        while(T){  /*一直向左并将沿途结点压入堆栈*/
            S.push(T);  // 第一次
            T = T->Left;
        }
        if (!S.empty()){
            T = S.top();  /*结点弹出堆栈*/  // 第二次
            printf("%5d", T->Data);  /*（访问）打印结点*/
            T = T->Right;  /*转向右子树*/
            S.pop();
        }
    }
}

/*
对于节点p可以分情况讨论
1. p如果是叶子节点，直接输出
2. p如果有孩子，且孩子没有被访问过，则按照右孩子，左孩子的顺序依次入栈
3. p如果有孩子，而且孩子都已经访问过，则访问p节点

如何来表示出p的孩是否都已经访问过了呢？
最暴力的方法就是对每个节点的状态进行保存，这么做显然是可以的，但是空间复杂度太大了。
我们可以保存最后一个访问的节点last，如果满足 (p->right==NULL && last ==p->left) || last=p->right，那么显然p的孩子都访问过了，接下来可以访问p
*/
 
void PostOrderTraversal(BinTree BT){
    vector<int> res;
    TreeNode *p = BT;
    TreeNode *last = BT;
    stack<TreeNode *> S = stack<TreeNode *>();
    S.push(p);
    while (!S.empty()){
        p = S.top();
        if( (p->Left == NULL && p->Right == NULL) || (p->Right == NULL && last == p->Left) || (last == p->Right) ){
            res.push_back(p->Data);
            last = p;
            S.pop();
        }else {
            if(p->Right){
                S.push(p->Right);
            }
            if(p->Left){
                S.push(p->Left);
            }
        }
    }
}

void LevelOrderTraversal(BinTree BT){
    queue<TreeNode *> Q; BinTree T;
    if (!BT) return;  /*若是空树则直接返回*/
    Q = queue<TreeNode *>();  /*创建并初始化队列Q*/
    Q.push(T);
    while (!Q.empty()){
        T = Q.front();
        Q.pop();
        printf("%d\n", T->Data);  /*访问取出队列的结点*/
        if (T->Left) Q.push(T->Left);
        if (T->Right) Q.push(T->Right);
    }
}


//非递归算出二叉树深度
int Btdepth(BinTree BT){
    queue<TreeNode *>Q;
    if(!BT) return 0;
    int level = 0;
    Q.push(BT);
    TreeNode *last = BT; //记录每层最后一个结点
    while(!Q.empty()){
        TreeNode *p = Q.front();
        Q.pop();
        if(p->Left){
            Q.push(p->Left);
        }
        if(p->Right){
            Q.push(p->Right);
        }
        if(p == last){
            level++;
            last = Q.back(); //指向下一层最后一个
        }
    }
    return level;
}

//先序和中序构建二叉树
BinTree PreInCreat(ElementType A[],ElementType B[],int l1,int h1,int l2,int h2){
    //l1 h1,l2 h2分别为先序中序第一个和最后一个结点下标
    BinTree root = (TreeNode *)malloc(sizeof(TreeNode));
    root->Data = A[l1];
    int i;
    for(i = l2; B[i] != root->Data; i++);
    int leftLen = i - l2;
    int rightLen = h2 - i;
    if(leftLen){
        root->Left = PreInCreat(A, B, l1 + 1, l1 + leftLen, l2, l2 + leftLen - 1);
    }else{
        root->Left = NULL;
    }
    if(rightLen){
        root->Right = PreInCreat(A, B, h1 - rightLen + 1, h1, h2 - rightLen + 1, h2);
    }else{
        root->Right = NULL;
    }
    return root;
}
#endif /* BinTree_hpp */
