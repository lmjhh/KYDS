//
//  Tree.hpp
//  数据结构
//
//  Created by 黄人煌 on 2017/10/18.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include "CommonHeader.h"

typedef struct BiTNode{
    Elemtype data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreatBitTree(BiTree &T);

void PreOrder(BiTree T);
void PreOrderWithStack(BiTree T);

void InOrder(BiTree T);
void InOrderWithStack(BiTree T);

void PostOrder(BiTree T);
void PostOrderWithStack(BiTree T);

void ReverseBFS(BiTree T);

int BtDepth(BiTree T);

void visit(BiTNode *node);

#endif /* Tree_hpp */
