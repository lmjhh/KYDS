//
// Created by 黄人煌 on 2018/3/28.
//

#ifndef KYDS_LISTBASE_H
#define KYDS_LISTBASE_H

#include "../CommonDefine.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status InitList(SqList &L);

Status DestroyList(SqList &L);

Status ClearList(SqList &L);

Status ListEmpty(SqList L);

Status ListLength(SqList L);

ElemType GetElem(SqList L, int i);

int LocateElem(SqList L, ElemType e);

ElemType PriorElem(SqList L, ElemType cur_e);

ElemType NextElem(SqList L, ElemType cur_e);

Status ListInsert(SqList &L, ElemType &e, int i);

Status ListDelete(SqList &L, ElemType &e, int i);

Status ListTraverse(SqList L);

Status MergeList(SqList La,SqList Lb,SqList &Lc);

#endif //KYDS_LISTBASE_H
