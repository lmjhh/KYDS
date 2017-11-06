//
//  StackHeader.h
//  数据结构
//
//  Created by 黄人煌 on 2017/10/13.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#ifndef StackHeader_h
#define StackHeader_h
#include "CommonHeader.h"
//顺序栈
typedef struct {
    Elemtype data[MaxSize];
    int top;
}SqStack;

int InitStack(SqStack &s);
int StackEmpty(SqStack &s);
int Push(SqStack &s,Elemtype x);
int Pop(SqStack &s,Elemtype &x);
int GetTop(SqStack &s,Elemtype &x);
int StackOverFlower(SqStack &s);

//共享栈
typedef struct {
    Elemtype data[MaxSize];
    int top[2];
}SharingStack;

int InitStack(SharingStack &s);
int Push(SharingStack &s,int i,Elemtype x);
int Pop(SharingStack &s,int i,Elemtype &x);

#endif /* StackHeader_h */
