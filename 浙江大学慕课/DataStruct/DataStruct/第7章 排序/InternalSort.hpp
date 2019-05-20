//
//  InternalSort.hpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/26.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef InternalSort_hpp
#define InternalSort_hpp

#include "CommonHeader.hpp"
#include "MathCalcTool.hpp"
#include "MaxHeap.hpp"
#define ElementType int
#define Cutoff 1000 //快速排序阀值
#define MAXSIZE 100
//空间复杂度
//时间复杂度
//最好情况:
//最坏情况:
//稳定性:
//适用性:
#pragma mark 冒泡排序
//空间复杂度 O(1)
//时间复杂度 O(n^2)
//最好情况:初始序列为有序第一重循环结束完成 O(n)
//最坏情况:初始序列为逆序要循环n-1次比较次数 n(n-1)/2 O(n^2) 移动次数 3n(n-1)/2
//稳定性:稳定 A[j-1]严格大于A[j]时才会发生交换
//适用性:顺序表和链表
void Bubble_Sort(ElementType A[],int N){
    for (int i = 0; i < N-1; i++) {
        bool flag = false;
        for(int j = i; j < N-1; j++){
            if(A[j-1] > A[j]){
                Swap(A[j],A[j-1]);
                flag = true;
            }
        }
        if(flag) return;
    }
}

#pragma mark 插入排序
//空间复杂度 O(1)
//时间复杂度 O(n^2)
//最好情况:初始序列有序每次循环只比较一次 O(n)
//最坏情况:初始序列为逆序 比较次数∑(i=2->n) i 移动次数 ∑(i=2->n) i+1
//稳定性:稳定 A[i-1]严格大于tmp
//适用性:顺序表和链表
void Insertion_Sort(ElementType A[],int N){
    int i;
    for(int p = 1; p < N; p++){
        ElementType tmp = A[p]; //摸下一张牌
        for(i = p; i > 0 && A[i-1] > tmp; i--)
            A[i] = A[i - 1]; //移出空位
        A[i] = tmp; //新牌落位
    }
}

#pragma mark 希尔排序
//空间复杂度 O(1)
//时间复杂度 猜想:O(n^1.3)
//最好情况:
//最坏情况: 当除1以外的间隔都不起作用时 O(n^2)
//稳定性: 不稳定 当相同两个元素被划分到不同间隔，可能会改变它们的相对次序
//适用性: 仅适用于顺序表
void Shell_Sort(ElementType A[],int N){
    int i;
    for(int D = N/2; D>0; D/=2){
        for(int p = D; p<N; p++){
            ElementType tmp = A[p]; //摸下一张牌
            for(i = p; i >= D && A[i-D] > tmp; i-=D)
                A[i] = A[i - D]; //移出空位
            A[i] = tmp; //新牌落位
        }
    }
}

#pragma mark 选择排序
//空间复杂度 O(1)
//时间复杂度 O(n^2)
//最好情况: n(n-1)/2
//最坏情况: n(n-1)/2
//稳定性: 不稳定 在第i趟找到最小元素后，和第i个交换，可能会导致第i个元素与其含有相同关键字元素的相对位置发生改变
//适用性: 顺序表和链表
void Selection_Sort(ElementType A[],int N){
    for (int i = 0; i < N; i++) {
        ElementType min = i;
        for(int j = i + 1; j < N - 1; j++)
            if(A[j] < A[min]) min = j;
        if(min != i) swap(A[i], A[min]);
    }
}

#pragma mark 堆排序
//空间复杂度 O(1)
//时间复杂度 O(nlogn)
//最好情况: O(nlogn)
//最坏情况: O(nlogn)
//稳定性: 不稳定
//适用性: 顺序表
void PercDown(ElementType A[],int k,int N);
void Heap_Sort(ElementType A[],int N){
    for(int i = N/2; i>=0; i--) /* 建堆 */
        PercDown(A, i, N);
    for(int i = N-1; i>0; i--){
        swap(A[0], A[i]);
        PercDown(A, 0, i);
    }
}
void PercDown(ElementType A[],int k,int N){
    A[0] = A[k];
    for(int i = 2*k; i < N; i*=2){
        if(i < N && A[i] < A[i + 1]) i++;
        if(A[0] >= A[i]) break;
        else{
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

#pragma mark 归并排序
//空间复杂度 O(n)
//时间复杂度 O(nlogn)
//最好情况: O(nlogn)
//最坏情况: O(nlogn)
//稳定性: 稳定
//适用性: 顺序表
void MSort(ElementType A[],ElementType TmpA[],int L,int RightEnd);
// L = 左边起始位置,R=右边起始位置,RightEnd = 右边终点位置
void Merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd);
void Merge_Sort(ElementType A[],int N){
    ElementType *TmpA;
    TmpA = (ElementType *)malloc(N * sizeof(ElementType));
    if(TmpA != NULL){
        MSort(A,TmpA,0,N-1);
        free(TmpA);
    }
}
void MSort(ElementType A[],ElementType TmpA[],int L,int RightEnd){
    int Center;
    if(L < RightEnd){
        Center = (L + RightEnd) / 2;
        MSort(A, TmpA, L, Center);
        MSort(A, TmpA, Center+1, RightEnd);
        Merge(A,TmpA,L,Center+1,RightEnd);
    }
}
void Merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd){
    int LeftEnd = R - 1; //左边结束位置
    int Tmp = L; //存放结果的数组的初始位置
    int NumElements = RightEnd - L + 1;
    while(L <= LeftEnd && R <= RightEnd){
        if(A[L] <= A[R]) TmpA[Tmp++] = A[L++];
        else             TmpA[Tmp++] = A[R++];
    }
    while (L <= LeftEnd) {
        TmpA[Tmp++] = A[L++];
    }
    while (R <= RightEnd) {
        TmpA[Tmp++] = A[R++];
    }
    for(int i = 0; i < NumElements; i++,RightEnd--)
        A[RightEnd] = TmpA[RightEnd];
}

//非递归写法
void Merge_pass(ElementType A[],ElementType TmpA[],int N,int length){
    int i;//length 当前有序子列的长度
    for (i = 0; i <= N - 2*length; i += 2*length) {
        Merge(A, TmpA, i, i+length, i+2*length-1);
    }
    if(i + length < N) //归并最后有两个子列
        Merge(A, TmpA, i, i+length, N-1);
    else
        for(int j = i; j < N; j++) TmpA[j] = A[j];
}

void Merge_Sort2(ElementType A[],int N){
    ElementType *TmpA;
    int length = 1;
    TmpA = (ElementType *)malloc(N * sizeof(ElementType));
    if(TmpA != NULL){
        while (length < N) {
            Merge_pass(A, TmpA, N, length);
            length *= 2;
            Merge_pass(TmpA, A, N, length);
            length *= 2;}
        free(TmpA);
    }
}

#pragma mark 快速排序
//空间复杂度 最坏O(n) 平均O(logn)
//时间复杂度 O(nlogn)
//最好情况: O(nlogn)
//最坏情况: O(n^2) 每次划分成 0和n-1
//稳定性: 不稳定
//适用性: 顺序表
ElementType Median3(ElementType A[],int Left,int Right);
void Quicksort(ElementType A[],int Left,int Right);
void Quick_Sort(ElementType A[],int N){
    Quicksort(A, 0, N-1);
}

ElementType Median3(ElementType A[],int Left,int Right){
    int Center = (Left + Right) / 2;
    if(A[Left] > A[Center])
        swap(A[Left], A[Center]);
    if(A[Left] > A[Right])
        swap(A[Left], A[Right]);
    if(A[Center] > A[Right])
        swap(A[Center], A[Right]);
    swap(A[Center], A[Right - 1]); //将pivot藏到右边
    return A[Right - 1];
}

void Quicksort(ElementType A[],int Left,int Right){
    if(Cutoff <= Right - Left){
        ElementType Pivot = Median3(A, Left, Right); //这里严蔚敏默认取第一个，可以用中位数优化
        int i = Left, j = Right - 1;
        while(i < j){
            while (A[++i] < Pivot) {}
            while (A[--j] > Pivot) {}
            if(i < j)
                swap(A[i], A[j]);
            else break;
            swap(A[i], A[Right - 1]);
            Quicksort(A, Left, i - 1);
            Quicksort(A, i + 1, Right);
        }
    }else
        Insertion_Sort(A+Left, Right-Left+1);
}
#endif /* InternalSort_hpp */
