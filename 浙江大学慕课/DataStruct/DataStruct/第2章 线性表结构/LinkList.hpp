#include "CommonHeader.hpp"
#ifndef ElementType
#define ElementType int
#define MAXSIZE 100
#endif

typedef struct LinkLNode{
    ElementType Data;
    LinkLNode *Next;
}*LinkList;

int Length(LinkList PtrL){
    LinkList p = PtrL;  /*p指向表的第一个结点*/
    int j = 0;
    while (p){
        p = p->Next;  
        j++;  /*当前p指向的是第j个结点*/
    }
    return j;
}

LinkList FindKth(int K, LinkList PtrL){
    LinkList p = PtrL;
    int i = 1;
    while (p != NULL && i < K){
        p = p -> Next;
        i++;
    }
    /*退出循环的两种条件，p==NULL或者i==K*/
    if (i == K) return p;  /*找到第K个，返回指针*/
    else return NULL;  /*否则返回空*/
}

LinkList Find(ElementType X, LinkList PtrL){
    LinkList p = PtrL;
    while (p != NULL && p->Data != X)
        p = p->Next;
    return p;
}

LinkList Insert(ElementType X, int i, LinkList PtrL){
    LinkList p, s;
    if (i == 1){    /*新结点插入在表头*/
        s = (LinkList)malloc(sizeof(struct LinkLNode));  /*申请，填装结点*/
        s->Data = X;
        s->Next = PtrL;
        return s;  /*返回新表头指针*/
    }
    p = FindKth(i-1, PtrL);   /*查找第i-1个结点*/
    if (p == NULL){  /*第i-1个不存在，不能插入*/
        printf("参数i错");
        return NULL;
    }else{
        s = (LinkList)malloc(sizeof(struct LinkLNode));  /*申请，填装结点*/
        s->Data = X;
        s->Next=p->Next;/*新结点插入在第i-1个结点的后面*/
        p->Next = s;
        return PtrL;
    } 
}

LinkList Delete(int i, LinkList PtrL){
    LinkList p, s;
    if (i == 1){    /*若要删除的是表的第一个结点，删除头结点有两种可能*/
        s = PtrL;   /*s指向第1个结点*/
        if(PtrL != NULL) PtrL = PtrL->Next;  /*从链表中删除,链表本身不空，把链表头结点挪到下一个位置*/
        else return NULL;  /*PtrL本身就是空的，这个时候就是删除不成功，直接return NULL*/
        free(s);  /*释放被删除结点*/
        return PtrL;
    }
    p = FindKth(i-1, PtrL);  /*查找第i-1个结点*/
    if (p == NULL){
        printf("第%d个结点不存在",i-1);  return NULL;
    }else if(p->Next == NULL){
        printf("第%d个结点不存在", i);  return NULL;
    }else{
        s = p->Next;   /*s指向第i个结点*/
        p -> Next = s->Next;  /*从链表中删除*/
        free(s);  /*释放被删除结点*/
        return PtrL;
    }
}
