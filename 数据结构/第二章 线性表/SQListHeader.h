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
#include <iostream>
using namespace std;

#define MAXSIZE 1000

//顺序表
typedef struct {
    int *elem;
    int length;
}SqList;

int deleminElemt(SqList &L);
void reverseList(SqList &L);
void deleValueEqualX(SqList &L,int x);
void deleFromSToTinSortArray(SqList &L,int s,int t);

//通用实现
void printElemt(SqList &L);

#endif /* SQListHeader_h */
