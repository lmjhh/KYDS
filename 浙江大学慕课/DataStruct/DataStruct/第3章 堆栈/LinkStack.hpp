//
//  LinkStack.h
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/4.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef LinkStack_hpp
#define LinkStack_hpp
#include "CommonHeader.hpp"
#ifndef ElementType
#define ElementType int
#define MAXSIZE 100
#endif

typedef struct LinkSNode *Stack;
struct LinkSNode{
    ElementType Data;
    struct LinkSNode *Next;
};

Stack CreateStack(){
    /*构建一个堆栈的头结点，返回指针*/
    Stack S;
    S = (Stack)malloc(sizeof(struct LinkSNode));
    S->Next = NULL;
    return S;
}

int IsEmpty(Stack S){
    /*判断堆栈S是否为空，若为空函数返回整数1，否则返回0*/
    return (S->Next == NULL);
}

void Push(ElementType item, Stack S){
    /*将元素item压入堆栈S*/
    struct LinkSNode *TmpCell;
    TmpCell = (struct LinkSNode *)malloc(sizeof(struct LinkSNode));
    TmpCell -> Element = item;
    TmpCell -> Next = S -> Next;
    S->Next = TmpCell;
}

ElementType Pop(Stack S){
    /*删除并返回堆栈S的栈顶元素*/
    FirstCell = S->Next;
    S->Next = FirstCell->Next;
    TopElem = FirstCell->Element;
    free(FirstCell);
    return TopElem;
}

#endif /* LinkStack_h */
