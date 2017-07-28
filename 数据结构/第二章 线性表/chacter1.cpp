//
//  exp1.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/7/27.
//  Copyright © 2017年 黄人煌. All rights reserved.

#include "SQListHeader.h"

//  从顺序表中删除最小元素，并返回删除的元素，空出的位置由后一个元素填补，若顺序表为空则打印错误并返回
int deleminElemt(SqList &L){
    if(L.length == 0) {
        cout<<"error"<<endl;
        return 0;
    }
    int min = INT_MAX, minIndex = 0;
    for(int i = 0; i < L.length; i++){
        if(L.elem[i] < min) {
            min = L.elem[i];
            minIndex = i;
        }
    }
    for(int i = minIndex; i + 1 < L.length; i++)
        L.elem[i] = L.elem[i + 1];
    L.length --;
    return min;
}

//  让顺序表所有元素逆置，额外空间复杂度O(1)
void reverseList(SqList &L){
    int temp = 0;
    int mid = L.length/2;
    for(int i = 0; i < mid; i++){
        temp = L.elem[i];
        L.elem[i] = L.elem[L.length - i - 1];
        L.elem[L.length - i - 1] = temp;
    }
}

// 长度为n 的顺序表，删除值等于X的元素，时间复杂度O(n) 空间复杂度 O(1)
void deleValueEqualX(SqList &L,int x){
    int index = 0;
    for(int i = 0; i < L.length; i++){
        if(L.elem[i] != x){
            L.elem[index] = L.elem[i];
            index++;
        }
    }
    L.length = index;
}

// 从有序顺序表中删除，s-t的数 若s,t不合理，表为空 退出
void deleFromSToTinSortArray(SqList &L,int s,int t){
    int startIndex = 0, endIndex = 0;
    if(L.elem[0] >= t || L.elem[L.length - 1] <= s) return;
    for(int i = 0; i < L.length; i++){
        if(L.elem[i] > s) {
            startIndex = i;
            break;
        }
    }
    if(L.elem[L.length - 1] < t){
        for(int i = 0; i < L.length; i++){
            if(L.elem[i] >= t) {
                endIndex = i;
                break;
            }
        }
    }else if(L.elem[L.length - 1] >= t){
      endIndex = L.length - 1;
    }
    for(int i = startIndex,j = endIndex; j < L.length; j++) L.elem[i] = L.elem[j];
    L.length = L.length - (endIndex - startIndex);
}

