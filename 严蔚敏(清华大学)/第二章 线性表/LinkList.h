//
// Created by 黄人煌 on 2018/4/20.
//

#ifndef KYDS_LINKLIST_H
#define KYDS_LINKLIST_H

#include "../CommonDefine.h"

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} *Link, *Position;

typedef struct {
    Link head, tail;
    int len;
} LinkList;

//分配由p指向的值为e的结点，并返回OK
Status MakeNode(Link &p, ElemType e);

void FreeNode(Link &p);

Status InitList(LinkList &L);

//销毁链表
Status DestroyList(LinkList &L);

//将线性链表L重置为空表，并释放链表空间结点
Status ClearList(LinkList &L);

//已知h指向链表的头结点，将s指向结点插入在第一个结点之前
Status InsFirst(Link h, Link s);

//已知h指向链表的头结点，删除链表中第一个结点并以q返回
Status DelFirst(Link h, Link &q);

/*将指针s所指的一串结点连接在线性表L的最后一个结点之后，并改变链表L的尾指针指向新的尾结点*/
Status Append(LinkList &L, Link s);

//删除线性表的尾结点并以q返回
Status Remove(LinkList &L, Link &q);

//已知p指向线性表中的一个结点，将s所指结点插入在p结点之前，并修改指针p指向新插入的结点
Status InsBefore(LinkList &L, Link &p, Link &s);

//已知p指向线性表中的一个结点，将s所指结点插入在p结点之后，并修改指针p指向新插入的结点
Status InsAfter(LinkList &L, Link &p, Link &s);

//用e更新p所指的数据
Status SetCurElem(Link &p, ElemType e);

ElemType GetCurElem(Link p);

Status ListEmpty(LinkList L);

int ListLength(LinkList L);

Position GetHead(LinkList L);

Position GetLast(LinkList L);

Position PriorPos(LinkList L, Link p);

Position NextPos(LinkList L, Link p);

Status LocatePos(LinkList L, int i, Link &p);

Position LocateElem(LinkList L, ElemType e);

Status ListInsert(LinkList &L, ElemType &e, int i);

Status ListDelete(LinkList &L, ElemType &e, int i);

Status ListTraverse(LinkList L);

void MergeList(LinkList La, LinkList Lb, LinkList &Lc);

#endif //KYDS_LINKLIST_H
