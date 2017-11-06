//
//  SQList.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/7/27.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "SQListHeader.h"


#pragma mark 顺序表操作
void printElemt(SqList &L){
    for(int i = 0; i < L.length; i++) cout << L.elem[i] << ' ';
    cout << endl;
}

#pragma mark 单链表操作
void initLinkList(LinkList &L,bool isHeadNode){
    if(isHeadNode){
        L = (LNode *)malloc(sizeof(LNode));
        L->data = 0;
        L->next = NULL;
    }else{
        L = NULL;
    }
}

void insertElemtIntoLinkList(LinkList &L,int data,bool isHeadNode){
    if(isHeadNode){
        LNode *p = L,*head = L;
        head->data++;
        while(p->next!=NULL) p = p->next;
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        newNode->data = data;
        newNode->next = NULL;
        p->next = newNode;
        
    }else{
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        newNode->data = data;
        newNode->next = NULL;
        if(L != NULL){
            LNode *p = L;
            while(p->next!=NULL) p = p->next;
            p->next = newNode;
        }else{
            L = newNode;
        }
    }
}

//插入一个数组
void insertArrayIntoList(vector<int> array,LinkList &L,bool isHeadNode){
    for(int i = 0; i < array.size(); i++){
        insertElemtIntoLinkList(L, array[i], isHeadNode);
    }
}

void printElemt(LinkList &L, bool isHeadNode){
    if(isHeadNode){
        LNode *p = L,*head = L;
        cout<<"链表长度="<<head->data<<endl;
        while (p -> next != NULL) {
            p=p->next;
            cout<<p->data<<"->";
        }
        cout<<"end"<<endl;
    }else{
        if(L != NULL){
            cout<<L->data<<"->";
            LNode *p = L;
            while (p -> next != NULL) {
                p=p->next;
                cout<<p->data<<"->";
            }
            cout<<"end"<<endl;
        }
    }
}

#pragma mark 双链表操作
void initDuFLinkList(DuFLinkList &L){
    L = (DuLFNode *)malloc(sizeof(DuLFNode));
    L->next = NULL;
    L->prior = NULL;
    L->data = 0;
    L->fre = 0;
}
void insertInfoDuFLinkList(DuFLinkList &L, int data){
    DuLFNode *newNode = (DuLFNode *)malloc(sizeof(DuLFNode));
    newNode ->next = NULL;
    newNode ->fre = 0;
    newNode ->data = data;
    DuLFNode *p = L;
    while (p ->next!= NULL) {
        p = p -> next;
    }
    p->next = newNode;
    newNode->prior = p;
    L->data++;
}

void printElemt(DuFLinkList &L){
    DuLFNode *p = L->next;
    cout<<"链表长度="<<L->data<<endl;
    while (p != NULL) {
        cout<<p->data<<"("<<p->fre<<")"<<"->";
        p = p->next;
    }
    cout<<"end"<<endl;
}

#pragma mark 循环单链表
void initLoopLinkList(LoopLinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    L->data = 0;
    L->next = L;
}
void insertElemtIntoLoopLinkList(LoopLinkList &L,int data){
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = data;
    newNode->next = L;
    LNode *p = L;
    while (p->next != L) {
        p = p->next;
    }
    p->next = newNode;
    L->data++;
}
void insertArrayIntoLoopLinkList(vector<int> array,LoopLinkList &L){
    for(int i = 0; i<array.size(); i++){
        insertElemtIntoLoopLinkList(L, array[i]);
    }
}
void printElemt(LoopLinkList &L){
    LNode *p = L->next;
    cout<<"链表长度="<<L->data<<endl;
    while (p != L) {
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<"end"<<endl;
}

#pragma mark 带头结点的循环双链表
void initLoopDuLinkList(LoopDuLinkList &L){
    L.head = (DuLNode *)malloc(sizeof(DuLNode));
    L.len = 0;
    L.head->next = L.head;
    L.head->prior = NULL;
}
void insertArrayIntoDuLinkList(vector<int> array,LoopDuLinkList &L){
    for(int i = 0; i<array.size(); i++){
        insertElemtIntoDuLinkList(L, array[i]);
    }
}
void insertElemtIntoDuLinkList(LoopDuLinkList &L,int data){
    DuLNode *newNode = (DuLNode *)malloc(sizeof(DuLNode));
    newNode->data = data;
    newNode->next = L.head;
    DuLNode *p = L.head;
    while (p->next != L.head) {
        p = p->next;
    }
    p->next = newNode;
    newNode->prior = p;
    L.len++;
}
void printElemt(LoopDuLinkList &L){
    DuLNode *p = L.head->next;
    cout<<"链表长度="<<L.len<<endl;
    while (p != L.head) {
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<"end"<<endl;
}
