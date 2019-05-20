//
//  Problem_4.cpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/21.
//  Copyright © 2018年 nd. All rights reserved.
//

#include "Problem_4.hpp"
#include "BinSearchTree.hpp"
#include "MaxHeap.hpp"

//输出二叉树中的叶子结点
void PreOrderPrintLeaves(BinTree BT){
    if (BT){
        if(!BT->Left && !BT->Right)
            printf("%d", BT->Data);
        PreOrderPrintLeaves(BT->Left);
        PreOrderPrintLeaves(BT->Right);
    }
}

//求二叉树的高度
int PostOrderGetHeight(BinTree BT){
    int HL, HR, MaxH;
    if(BT){
        HL = PostOrderGetHeight(BT->Left);  /*求左子树的深度*/
        HR = PostOrderGetHeight(BT->Right); /*求右子树的深度*/
        MaxH = (HL > HR) ? HL : HR;  /*取左右子树较大的深度*/
        return (MaxH + 1);  /*返回树的深度*/
    }
    else return 0;  /*空树深度为0*/
}

void problem_4(){
    
}


