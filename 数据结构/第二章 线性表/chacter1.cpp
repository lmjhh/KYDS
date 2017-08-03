//
//  exp1.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/7/27.
//  Copyright © 2017年 黄人煌. All rights reserved.

#include "SQListHeader.h"

#pragma mark 1
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

#pragma mark 2
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

#pragma mark 3
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

#pragma mark 4
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

#pragma mark 5
// 从顺序表中删除,s-t的数
void deleSToTFormArray(SqList &L,int s,int t){
    if(t < s || L.length == 0) return;
    for(int i = 0; i < L.length; i++){
        if(L.elem[i] >= s && L.elem[i] <= t){
            for(int j = i; j + 1 < L.length; j++) L.elem[j] = L.elem[j+1];
            L.length --;
            i--;
        }
    }
}

#pragma mark 6
// 从有序顺序表中删除重复的元素
void deleRepeatElemFromSortArray(SqList &L){
    if(L.length == 0) return;
    for(int i = 0; i + 1 < L.length; i++){
        if(L.elem[i] == L.elem[i+1]){
            for(int j = i; j < L.length; j++) L.elem[j] = L.elem[j+1];
            L.length--;
        }
    }
}

#pragma mark 7
// 两个有序表合成一个新的有序表并由函数返回
SqList composeTwoArray(SqList &L,SqList &M){
    SqList newList;
    newList.elem = new int[L.length + M.length];
    newList.length = 0;
    for(int i = 0, j = 0; i < L.length || j < M.length;){
        if(L.elem[i] < M.elem[j] && i < L.length && j < M.length)
            newList.elem[newList.length++] = L.elem[i++];
        else if(L.elem[i] >= M.elem[j] && i < L.length && j < M.length)
            newList.elem[newList.length++] = M.elem[j++];
        else if(i >= L.length && j < M.length)
            newList.elem[newList.length++] = M.elem[j++];
        else if(i < L.length && j >= M.length)
            newList.elem[newList.length++] = L.elem[i++];;
    }
    return newList;
}

#pragma mark 8
//A[n+m] 表示两个线性表 a1...an b1...bm 互换这两个
void swapSqlistAandB(SqList &L,int n,int m){
    int flag = 0;
    if(n > m){
        int temp = n; n = m; m = temp;
        flag = 1;
    }
    for(int i = 0; i < n; i++){
        int temp = L.elem[i];
        L.elem[i] = L.elem[m + i];
        L.elem[m + i] = temp;
    }
    if(n != m){
         if(!flag){
             for(int i = 0; i < n; i++){
                for(int j = 0; j + 1 < m; j++){
                    int temp = L.elem[j]; L.elem[j] = L.elem[j + 1]; L.elem[j + 1] = temp;
                }
            }
         }
         else {
            for(int i = n; i < m; i++){
                for(int j = n; j + 1 < L.length; j++){
                    int temp = L.elem[j]; L.elem[j] = L.elem[j + 1]; L.elem[j + 1] = temp;
                }
            }
        }
    }
}

#pragma mark 9
//有序的顺序表中找到 X 找到了与后继替换 没有插入 并保持有序
void searchXFromSortArray(SqList &L,int x){
    for(int i = 0; i < L.length; i++){
        if(L.elem[i] == x) {L.elem[i] = L.elem[i+1]; L.elem[i+1] = x; break;}
        if(L.elem[i] > x) {
            for(int j = L.length - 1; j >= i; j--) L.elem[j + 1] = L.elem[j];
            L.elem[i] = x;
            L.length++;
            break;
        }
    }
    
//    int max = L.length;
//    int min = 0;
//    int mid = (max + min)/2;
//    int index = -1;
//    while (min < max) {
//        mid = (max + min)/2;
//        if(L.elem[mid] < x){
//            min = mid + 1;
//        }else if(L.elem[mid] < x){
//            max = mid - 1;
//        }else {
//            index = mid;
//        }
//    }
    
}

#pragma mark 10
//把顺序表循环左移动p个
void leftLoopPindex(SqList &L,int p){
    int n = p % L.length;
    int m = L.length - n;
    swapSqlistAandB(L, m, n);
}

#pragma mark 11
//找出两个等长序列的共同中位数
int searchMidNumFromTwoEqualArray(SqList &L,SqList &M){
    int index = 0, flag = 0, count = 0;
    for(int i = 0,j = 0; i < L.length && j < M.length;){
        if(L.elem[i] < M.elem[j]) {
            index = i++;
            count++;
            flag = 0;
        }else {
            index = j++;
            count++;
            flag = 1;
        }
        if(count == L.length) break;
    }
    if(!flag) return L.elem[index];
    else return M.elem[index];
}

//找出顺序表A中的主元素
int searchMainEleminArray(SqList &L){
    int major = L.elem[0], count = 0;
    for(int i = 0; i < L.length; i++){
        if(count == 0){
            count++;
            major = L.elem[i];
        }else if(L.elem[i] == major) count++;
        else count--;
    }
    return major;
}
