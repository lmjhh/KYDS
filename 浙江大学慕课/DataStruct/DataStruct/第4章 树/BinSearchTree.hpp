//
//  BinSearchTree.hpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/24.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef BinSearchTree_hpp
#define BinSearchTree_hpp
#include "BinTree.hpp"

Position Find(ElementType X, BinTree BST){
    while(BST){
        if(X > BST->Data)
            BST = BST->Right;  /*向右子树中移动，继续查找*/
        else if(X < BST->Data)
            BST = BST->Left;  /*向左子树中移动，继续查找*/
        else  /*X == BST->Data */
            return BST;  /*查找成功，返回结点的找到结点的地址*/
    }
    return NULL;  /*查找失败*/
}

Position FindMin(BinTree BST){
    if (!BST) return NULL;  /*空的二叉搜索树，返回NULL*/
    else if(!BST -> Left)
        return BST;  /*找到最左叶结点并返回*/
    else
        return FindMin(BST->Left);  /*沿左分支继续查找*/
}

Position FindMax(BinTree BST){
    if (BST)
        while(BST->Right)   BST = BST->Right;
    /*沿右分支继续查找，直到最右叶结点*/
    return BST;
}

BinTree Insert(ElementType X, BinTree BST){
    if (!BST){
        /*若原树为空，生成并返回一个结点的二叉搜索树*/
        BST = (TreeNode *)malloc(sizeof(TreeNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }else  /*开始找要插入元素的位置*/
        if(X < BST->Data)
            BST->Left = Insert(X, BST->Left);  /*递归插入左子树*/
        else if(X > BST->Data)
            BST->Right = Insert(X, BST->Right);  /*递归插入右子树*/
    /*else X已经存在，什么都不做*/
    return BST;
}

BinTree Delete(ElementType X, BinTree BST){
    Position Tmp;
    if(!BST) printf("要删除的树未找到");
    else if(X < BST->Data) BST->Left = Delete(X, BST->Left);
    else if(X > BST->Data) BST->Right = Delete(X, BST->Right);
    else //找到被删除的结点
        if(BST->Left && BST->Right){ //被删除结点有左右子结点
            Tmp = FindMin(BST->Right);
            BST->Data = Tmp->Data;
            BST->Right = Delete(BST->Data, BST->Right);
        }else{ //被删除的结点有一个或没有子结点
            Tmp = BST;
            if(!BST->Left) BST = BST->Right;
            else if(!BST->Right) BST = BST->Left;
            free(Tmp);
        }
    return BST;
}
    
#endif /* BinSearchTree_hpp */
    
    
    
    
    
    
    
    
    
    
    
