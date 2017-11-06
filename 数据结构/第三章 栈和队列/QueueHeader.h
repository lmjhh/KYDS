//
//  QueueHeader.hpp
//  数据结构
//
//  Created by 黄人煌 on 2017/10/13.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#ifndef QueueHeader_h
#define QueueHeader_h

#include "CommonHeader.h"
//循环队列
typedef struct {
    Elemtype data[MaxSize];
    int front,rear;
}SqQueue;

int InitQueue(SqQueue &s);
int QueueEmpty(SqQueue &s);
int EnQueue(SqQueue &s,Elemtype x);
int DeQueue(SqQueue &s,Elemtype &x);
int GetHead(SqQueue &s,Elemtype &x);

typedef struct {
    Elemtype data[MaxSize];
    int front,rear;
    int tag;
}SqTagQueue;

int EnQueue(SqTagQueue &s,Elemtype x);
int DeQueue(SqTagQueue &s,Elemtype &x);

#endif /* QueueHeader_hpp */
