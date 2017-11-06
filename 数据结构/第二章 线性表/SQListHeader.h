//
//  SQListHeader.h
//  数据结构
//
//  Created by 黄人煌 on 2017/7/27.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#ifndef SQListHeader_h
#define SQListHeader_h

#include "CommonHeader.h"

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
}LNode,*LinkList,*LoopLinkList;

//双链表
typedef struct DuLNode{
    int data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*DuLinkList;

//双链表带频度
typedef struct DuLFNode{
    int data;
    int fre;
    struct DuLFNode *prior;
    struct DuLFNode *next;
}DuLFNode,*DuFLinkList;

//带头结点的循环双链表
typedef struct {
    DuLNode *head;
    int len;
}LoopDuLinkList;

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
void deleEqualElemt(LinkList &L);
LinkList mergeListAandB(LinkList &L,LinkList &M);
LinkList serchElemtMergeToC(LinkList &L,LinkList &M);
void serchElemtMergeToA(LinkList &L,LinkList &M);
bool BisSubListOfA(LinkList &L,LinkList &M);

#pragma mark 双链表操作
void initDuFLinkList(DuFLinkList &L);
void insertInfoDuFLinkList(DuFLinkList &L, int data);
void sortByFreInDuFLinkList(DuFLinkList &L,DuLFNode *newFre);
void printElemt(DuFLinkList &L);
DuLFNode* locateDuFLinkList(DuFLinkList &L,int data);

#pragma mark 循环单链表
void initLoopLinkList(LoopLinkList &L);
void insertElemtIntoLoopLinkList(LoopLinkList &L,int data);
void insertArrayIntoLoopLinkList(vector<int> array,LoopLinkList &L);
void printElemt(LoopLinkList &L);
void mergeLoopLinkListBToA(LoopLinkList &L,LoopLinkList &M);
void loopDeleMinElemtInLoopLinkLkst(LoopLinkList &L);

#pragma mark 双向循环链表
void initLoopDuLinkList(LoopDuLinkList &L);
void insertArrayIntoDuLinkList(vector<int> array,LoopDuLinkList &L);
void insertElemtIntoDuLinkList(LoopDuLinkList &L,int data);
void printElemt(LoopDuLinkList &L);
bool LoopDuLinkListIsSymmetry(LoopDuLinkList &L);


#pragma mark 通用实现
void printElemt(SqList &L);
void printElemt(LinkList &L, bool isHeadNode);
void initLinkList(LinkList &L,bool isHeadNode);
void insertElemtIntoLinkList(LinkList &L,int data,bool isHeadNode);
void insertArrayIntoList(vector<int> array,LinkList &L,bool isHeadNode);
#endif /* SQListHeader_h */
