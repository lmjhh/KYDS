//
//  ArrayQueue.hpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/5.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef ArrayQueue_h
#define ArrayQueue_h

#include "CommonHeader.hpp"
#ifndef ElementType
#define ElementType int
#define MAXSIZE 100
#endif

struct QNode{
    ElementType Data[MAXSIZE];
    int rear;
    int front;
};
typedef struct QNode *Queue;

void AddQ(Queue PtrQ, ElementType item){
    if ((PtrQ->rear + 1) % MAXSIZE==PtrQ->front){
        printf("队列满");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%MAXSIZE;
    PtrQ->Data[PtrQ->rear]=item;
}

ElementType DeleteQ(Queue PtrQ){
    if (PtrQ->front == PtrQ->rear){
        printf("队列空");
        return ERROR;
    }else{
        PtrQ->front = (PtrQ->front+1)%MAXSIZE;
        return PtrQ->Data[PtrQ->front];
    }
}
#endif /* ArrayQueue_h */
