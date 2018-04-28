//
// Created by 黄人煌 on 2018/4/19.
//
#include "../第二章 线性表/LinkList.h"
#include "LinkList.h"

Status InitList(LinkList &L) {
    L.head = NULL;
    L.tail = NULL;
    L.len = 0;
}

Status MakeNode(Link &p, ElemType e){
    p = (Link)malloc(sizeof(LNode));
    p->data = e;
    p->next = NULL;
}

void FreeNode(Link &p){

}

Status GetElem(LinkList L, int i, ElemType &e) {
    LNode *p = L.head;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}

Status ListInsert(LinkList &L, ElemType &e, int i) {
    LNode *p = L.head;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    LNode *s = (Link) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

Status ListDelete(LinkList &L, ElemType &e, int i) {
    LNode *p = L.head;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) return ERROR;
    LNode *q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return OK;
}

void MergeList(LinkList La, LinkList Lb, LinkList &Lc) {
    LNode *pa = La.head, *pb = Lb.head, *pc = Lc.head = La.head;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
}

Status LocatePos(LinkList L, int i, Link &p) {
    return 0;
}
