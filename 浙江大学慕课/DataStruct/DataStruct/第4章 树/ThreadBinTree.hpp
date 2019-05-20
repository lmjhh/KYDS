//
//  ThreadBinTree.hpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/11/10.
//  Copyright © 2018 nd. All rights reserved.
//

#ifndef ThreadBinTree_hpp
#define ThreadBinTree_hpp

#include "CommonHeader.hpp"
#include <stack>
#include <queue>
#define ElementType int


typedef struct TreeNode *ThreadBinTree;
typedef ThreadBinTree Position;
struct ThreadNode{
    ElementType Data;
    ThreadBinTree Left;
    ThreadBinTree Right;
    int ltag,rtag;
};



//中序遍历对二叉树线索化
void CreateThread(ThreadBinTree T){
    ThreadBinTree pre = NULL;
    if(T != NULL){
        InThread(T, pre);
        pre->Right = NULL; //处理最后一个结点
        pre->rtag = 1;
    }
}

void InThread(ThreadTree &p, ThreadTree &pre){
    if(p != NULL){
        InThread(p->Left,pre); //递归线索化左子树
        if(p->left == NULL){
            p->Left = pre;
            p->ltag = 1;
        }
        if(pre != NULL && pre->Right == NULL){
            pre->Right = p; //建立前驱结点的后继线索
            pre->rtag = 1;
        }
        pre = p;
        InThread(p->Right, pre);
    }
}

//  求线索二叉树中序第一个结点
ThreadNode *Firstnodde(ThreadNode *p){
    while (p->ltag == 0) {
        p = p->Left;
    }
    return p;
}

ThreadNode *Nextnode(ThreadNode *p){
    if(p->rtag == 0) return Firstnode(p->Right);
    else return p->Right;
}

void Inorder(ThreadTree *T){
    for(ThreadNode *p = Firstnode(T); p != NULL; p = Nextnode(p))
        printf("%d",T->Data);
}

#endif /* ThreadBinTree_hpp */
