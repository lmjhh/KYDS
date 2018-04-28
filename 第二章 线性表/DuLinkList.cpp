//
// Created by 黄人煌 on 2018/4/25.
//

#include "DuLinkList.h"

Status GetElemP(DuLinkList L, int i, DuLNode *e) {
    DuLNode *p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    e = p;
    return OK;
}

Status ListInsert(DuLinkList &L, ElemType &e, int i) {
    DuLNode *p, *s;
    if (!(GetElemP(L, i, p)))
        return ERROR;
    if (!(s = (DuLinkList) malloc(sizeof(DuLNode)))) return ERROR;
    s->data = e;
    s->prior = p->prior;    p->prior->next = s;
    s->next = p;            p->prior = s;
    return OK;
}

Status ListDelete(DuLinkList &L, ElemType &e, int i) {
    DuLNode *p, *s;
    if (!(GetElemP(L, i, p))) return ERROR;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}