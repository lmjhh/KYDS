//
//  SQListHeader.h
//  数据结构
//
//  Created by 黄人煌 on 2017/7/27.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#ifndef SQListHeader_h
#define SQListHeader_h

#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

#define MAXSIZE 1000

//顺序表
typedef struct {
    int *elem;
    int length;
}SqList;

//单链表链表
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

#pragma mark 顺序表操作
int deleminElemt(SqList &L);
void reverseList(SqList &L);
void deleValueEqualX(SqList &L,int x);
void deleFromSToTinSortArray(SqList &L,int s,int t);
void deleSToTFormArray(SqList &L,int s,int t);
void deleRepeatElemFromSortArray(SqList &L);
SqList composeTwoArray(SqList &L,SqList &M);
void swapSqlistAandB(SqList &L,int n,int m);
void searchXFromSortArray(SqList &L,int x);
void leftLoopPindex(SqList &L,int p);
int searchMidNumFromTwoEqualArray(SqList &L,SqList &M);
int searchMainEleminArray(SqList &L);

#pragma mark 单链表操作
void recursionDeleteValueEqualX(LinkList &L,int x);
void DeleteEqualX(LinkList &L,int x);
void reversePrintElemt(LinkList &L);
void deleteMinElemt(LinkList &L);
void reverseList(LinkList &L);
void sortList(LinkList &L);
void deleteFromXToY(LinkList &L,int x,int y);
void serchEqualElemt(LinkList &L,LinkList &M);
void ascendingInputList(LinkList &L);
void resolvedList(LinkList &L);
void resolvedListByDesc(LinkList &L);

#pragma mark 通用实现
void printElemt(SqList &L);
void printElemt(LinkList &L, bool isHeadNode);
void initLinkList(LinkList &L,bool isHeadNode);
void insertElemtIntoLinkList(LinkList &L,int data,bool isHeadNode);
void insertArrayIntoList(vector<int> array,LinkList &L,bool isHeadNode);
#endif /* SQListHeader_h */
