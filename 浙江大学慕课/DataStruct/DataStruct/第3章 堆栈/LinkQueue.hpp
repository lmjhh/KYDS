//
//  LinkQueue.h
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/5.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef LinkQueue_hpp
#define LinkQueue_hpp

#include "CommonHeader.hpp"
#ifndef ElementType
#define ElementType int
#define MAXSIZE 100
#endif

struct Node{  /*链表的节点结构*/
    ElementType Data;
    struct Node *Next;
};
struct QNode{  /*链队列结构*/
    struct Node *rear;  /*指向队尾结点*/
    struct Node *front; /*指向队头结点*/
};
typedef struct QNode *Queue;

ElementType DeleteQ(Queue PtrQ){
    struct Node *FrontCell;
    ElementType FrontElem;
    
    if (PtrQ->front==NULL){
        printf("队列空"); return ERROR;
    }
    FrontCell = PtrQ->front;  /*找到队列的头个元素*/
    if (PtrQ->front == PtrQ->rear)  /*若队列只有一个元素*/
        PtrQ->front = PtrQ->rear = NULL;
    else
        PtrQ->front = PtrQ->front->Next; /*如果不止一个元素时，改变front指针的指向*/
    FrontElem = FrontCell->Data;
    free(FrontCell);   /*释放被删除结点空间*/
    return FrontElem;
}

#endif /* LinkQueue_h */
