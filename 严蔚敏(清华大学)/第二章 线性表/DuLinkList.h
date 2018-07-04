//
// Created by 黄人煌 on 2018/4/25.
//

#ifndef KYDS_DULINKLIST_H
#define KYDS_DULINKLIST_H

#include "../CommonDefine.h"
typedef struct DuLNode{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode, *DuLinkList;

Status GetElemP(DuLinkList L, int i, DuLNode *e);

Status ListInsert(DuLinkList &L, ElemType &e, int i);

Status ListDelete(DuLinkList &L, ElemType &e, int i);

#endif //KYDS_DULINKLIST_H
