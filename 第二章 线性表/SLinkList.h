//
// Created by 黄人煌 on 2018/4/24.
//

#ifndef KYDS_SLINKLIST_H
#define KYDS_SLINKLIST_H

#include "../CommonDefine.h"

#define MAXSIZE 1000
typedef struct {
    ElemType data;
    int cur;
} component, SLinkList[MAXSIZE];

void InitList(SLinkList &space);

Status Malloc(SLinkList &space);

void Free(SLinkList &space, int k);

int LocateElem(SLinkList S, ElemType e);

Status ListTraverse(SLinkList s);

#endif //KYDS_SLINKLIST_H
