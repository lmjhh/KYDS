//
//  QueueHeader.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/10/13.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "QueueHeader.h"

#pragma mark - 不带tag
int InitQueue(SqQueue &s){
    s.front = 0;
    s.rear = 0;
    return SUCCESS;
}
int QueueEmpty(SqQueue &s){
    if(s.front == s.rear) return SUCCESS;
    return ERROR;
}
int EnQueue(SqQueue &s,Elemtype x){
    if((s.rear + 1) % MaxSize == s.front) return ERROR;
    s.data[s.rear++] = x;
    s.rear %= MaxSize;
    cout<<s.rear<<"队尾"<<endl;
    return SUCCESS;
}
int DeQueue(SqQueue &s,Elemtype &x){
    if(s.front == s.rear) return ERROR;
    x = s.data[s.front++];
    s.front %= MaxSize;
    return SUCCESS;
}
int GetHead(SqQueue &s,Elemtype &x){
    if(s.front == s.rear) return ERROR;
    x = s.data[s.front];
    return SUCCESS;
}

#pragma mark - 带tag的入队出队
int EnQueue(SqTagQueue &s,Elemtype x){
    if(s.rear == s.front && s.tag == 1) return ERROR;
    s.data[s.rear++] = x;
    s.rear %= MaxSize;
    s.tag = 1;
    return SUCCESS;
}
int DeQueue(SqTagQueue &s,Elemtype &x){
    if(s.rear == s.front && s.tag == 0) return ERROR;
    x = s.data[s.front++];
    s.front %= MaxSize;
    s.tag = 0;
    return SUCCESS;
}
