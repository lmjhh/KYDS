//
//  excise2.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/8/4.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "SQListHeader.h"

#pragma mark 1
//设计一个递归算法删除不带头结点的链表中值为X的元素
void recursionDeleteValueEqualX(LinkList &L,int x){
    if(L->next == NULL) return;
    if(L->data == x) {
      L = L->next;
      recursionDeleteValueEqualX(L, x);
    }else recursionDeleteValueEqualX(L->next, x);
}

#pragma mark 2
//删除带头结点的链表中值为X的元素并释放空间
void DeleteEqualX(LinkList &L,int x){
    LNode *q = L;
    while(q->next != NULL){
        if(q->next->data == x){
            LNode *p = q->next;
            q->next = p->next;
            L->data --;
            free(p);
        }else q = q->next;
    }
}
#pragma mark 3
//带头结点的链表反向输出值
void reversePrintElemt(LinkList &L){
    if(L->next == NULL) {
        cout<<L->data<<"->";
        return;
    }else{
        reversePrintElemt(L->next);
        cout<<L->data<<"->";
    }
}

#pragma mark 4
//带头结点的链表删除最小值
void deleteMinElemt(LinkList &L){
    LNode *cur = L->next,*curPre = L,*min = L->next,*minPre = L;
    while(cur != NULL){
        if(cur->data < min->data){
            min = cur;
            minPre = curPre;
        }
        curPre = cur;
        cur = cur->next;
    }
    L->data--;
    minPre->next = min->next;
    free(min);
}
#pragma mark 5
//翻转链表 O(1)
void reverseList(LinkList &L){
    LNode *q = L->next->next;
    int count = 0;
    while(q != NULL){
        LNode *cur = q,*headNext = L->next,*curNext = cur->next;
        L->next = cur;
        cur->next = headNext;
        for(int i = 0; i < count; i++) headNext = headNext -> next;
        headNext->next = curNext;
        q = curNext;
        count++;
    }
}
#pragma mark 6
//链表排升序
void sortList(LinkList &L){
    LNode *p = L->next,*q = p->next;
    while(p->next != NULL){
        q = p;
        while(q->next != NULL){
            if(q->next->data < p ->data){
                int temp = q->next->data;
                q->next->data = p->data;
                p->data = temp;
            }
            q=q->next;
        }
        p = p->next;
    }
}
#pragma mark 7
//带头结点的无序链表删除一个范围的结点
void deleteFromXToY(LinkList &L,int x,int y){
    LNode *q = L;
    while(q->next != NULL){
        if(q->next->data> x && q->next->data < y){
            LNode *p = q->next;
            q->next = p->next;
            L->data--;
            free(p);
        }else q=q->next;
    }
}
#pragma mark 8
//两个链表的公共结点
void serchEqualElemt(LinkList &L,LinkList &M){
    LNode *q = L->next,*p = M->next;
    cout<<"公共结点:";
    while(q != NULL){
        while (p != NULL) {
            if(q->data == p->data) cout<<q->data<<"->";
            p = p -> next;
        }
        q = q ->next;
        p = M->next;
    }
    cout<<"end"<<endl;
}

#pragma mark 9
//递增输出并释放
void ascendingInputList(LinkList &L){
    LNode *p = L->next,*min = L->next,*minPre = L;
    while (L->next != NULL) {
        while (p->next != NULL) {
            if(p->next->data < min->data){
                min = p->next;
                minPre = p;
            }
            p = p->next;
        }
        minPre -> next = min -> next;
        cout<<min->data<<"->";
        free(min);
        min = L->next; minPre = L;
        p = L->next;
    }
    cout<<"end"<<endl;
}
#pragma mark 10
//把一个带头结点的链表 按奇偶序号分成两个
void resolvedList(LinkList &L){
    LinkList sub1,sub2;
    LNode *p = L->next;
    int count = 1;
    initLinkList(sub1, true);
    initLinkList(sub2, true);
    while(p!=NULL){
        if(count%2){
            insertElemtIntoLinkList(sub1, p->data, true);
        }else{
            insertElemtIntoLinkList(sub2, p->data, true);
        }
        p = p->next;
        count++;
    }
    printElemt(sub1, true);
    printElemt(sub2, true);
}
#pragma mark 11
//把{a1,b1,a2,b2....an,bn}拆成{a1,a2...an} {bn,bn-1....b1}
void resolvedListByDesc(LinkList &L){
    LinkList sub1,sub2;
    LNode *p = L->next;
    int count = 1;
    initLinkList(sub1, true);
    initLinkList(sub2, true);
    while(p!=NULL){
        if(count%2){
            insertElemtIntoLinkList(sub1, p->data, true);
        }else{
            //头插
            LNode *q = sub2->next;
            LNode *newNode = (LNode *)malloc(sizeof(LNode));
            newNode->data = p->data;
            sub2->next = newNode;
            newNode->next = q;
            sub2->data++;
        }
        p = p->next;
        count++;
    }
    printElemt(sub1, true);
    printElemt(sub2, true);
}
