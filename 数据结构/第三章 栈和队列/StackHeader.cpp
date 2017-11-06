//
//  Stack.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/10/13.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "StackHeader.h"
#pragma 顺序栈
int InitStack(SqStack &s){
    s.top = -1;
    return SUCCESS;
}

int StackEmpty(SqStack &s){
    if(s.top == -1) return SUCCESS;
    return ERROR;
}
int Push(SqStack &s,Elemtype x){
    if(s.top + 1 == MaxSize) return ERROR;
    s.data[++s.top] = x;
    return SUCCESS;
}
int Pop(SqStack &s,Elemtype &x){
    if(s.top == -1) return ERROR;
    x = s.data[s.top--];
    return SUCCESS;
}
int GetTop(SqStack &s,Elemtype &x){
    if(s.top == -1) return ERROR;
    x = s.data[s.top];
    return SUCCESS;
}
int StackOverFlower(SqStack &s){
    if(s.top == MaxSize -1) return SUCCESS;
    return ERROR;
}

#pragma 共享栈
int InitStack(SharingStack &s){
    s.top[0] = -1;
    s.top[1] = MaxSize - 1;
    return SUCCESS;
}
int Push(SharingStack &s,int i,Elemtype x){
    if(i != 0 && i != 1) return ERROR;
    if(s.top[1] - s.top[0] == 1) return ERROR;
    if(i == 0){
        s.data[++s.top[0]] = x;
    }else{
        s.data[--s.top[1]] = x;
    }
    return SUCCESS;
}
int Pop(SharingStack &s,int i,Elemtype &x){
    if(i != 0 && i != 1) return ERROR;
    if(s.top[i] == -1 || s.top[i] == MaxSize - 1) return ERROR;
    if(i == 0){
        x = s.data[s.top[i]--];
    }else{
        x = s.data[s.top[i]++];
    }
    return SUCCESS;
}
