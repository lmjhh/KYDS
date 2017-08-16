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
