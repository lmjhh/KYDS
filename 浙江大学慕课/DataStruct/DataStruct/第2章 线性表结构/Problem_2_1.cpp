//
//  Problem_2.cpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/7/14.
//  Copyright © 2018年 nd. All rights reserved.
//

#include "Problem_2_1.hpp"

#include "LinearList.hpp"

//顺序表中删除最小值的元素，并用最后一个替代，返回最小值
bool problem_1(List list, ElementType &value);
//逆置顺序表
void problem_2(List L);
//删除值为X
void problem_3(List L, ElementType x);
//有序顺序表 删除值在(s,t)之间的元素
bool problem_4(List L, ElementType s, ElementType t);
//已知A[m+n]中存放了[a1,a2...an,b1,b2...bn]逆置为[b1,b2...bn,a1,a2...an]
void problem_5(List L, int n, int m);
//已知A,B为升序数列，位于L/2位置的数为中位数，求两个数组的中位数
ElementType problem_6(List A, List B);
//一个数组中一个元素出现次数大于L/2那这个元素就是主元素，求数组的主元素
ElementType problem_6(List A);

void problem_2(){
    
}

#pragma mark - 值得收藏的题目
bool problem_1(List list, ElementType &value){
    //查找最小值
    if(list->Last == 0) return false;
    value = list->Data[0];
    int pos = 0;
    for(int i = 1; i < list->Last; i++){
        if(list->Data[i] < value){
            value = list->Data[i];
            pos = i;
        }
    }
    list->Data[pos] = list->Data[list->Last - 1];
    list->Last--;
    return true;
}

void problem_2(List L){
    ElementType temp;
    for (int i = 0; i < L->Last / 2; i++) {
        temp = L->Data[i];
        L->Data[i] = L->Data[L->Last - i - 1];
        L->Data[L->Last - i - 1] = temp;
    }
}

//删除值为X
void problem_3(List L, ElementType x){
    int k = 0;
    for (int i = 0; i < L->Last; i++) {
        if(L->Data[i] != x){
            L->Data[k] = L->Data[i];
            k++;
        }
    }
    L->Last = k;
}

//删除[s,t]之间的元素
bool problem_4(List L, ElementType s, ElementType t){
    int i,j;
    if(s >= t || L->Last == 0) return false;
    for(i = 0; i < L->Last && L->Data[i] < s; i++);
    if(i >= L->Last) return false;
    for(j = i; j < L->Last && L->Data[j] < t; j++);
    for(;j < L->Last; i++,j++)
        L->Data[i] = L->Data[j];
    L->Last = i;
    return true;
}

//解题思路，分别做 a逆 b逆 再做ab逆
//[a3,a2,a1,b3,b2,b1] -> [b1,b2,b3,a1,a2,a3]
//同理若是想把数组循环左移也可以用同样方法，切割点在左移位数上
void problem_5(List L, int n, int m){
    ReverseList(L, 0, n-1);
    ReverseList(L, n, m+n-1);
    ReverseList(L, 0, m+n-1);
}

//分别求出A的中位数 a,B的中位数 b
//若a=b 那么a或b就是所求结果
//若a<b 那么抛弃A中较小的一半，同时舍弃b中较大的一半，要求两次舍弃的长度相同
//若a>b 同理
//不断重复 直到两个序列中只含一个元素，较小的就是中位数
ElementType problem_6(List A, List B){
    int n = A->Last;
    int s1 = 0, d1 = n-1, s2 = 0, d2 = n-1;
    while(s1 != d1){
        int m1 = (s1 + d1)/2;
        int m2 = (s2 + d2)/2;
        if(A->Data[m1] == B->Data[m2]){
            return A->Data[m1];
        }
        if(A->Data[m1] < B->Data[m2]){
            if((s1+s2) % 2 == 0){
                s1 = m1;
                d2 = m2;
            }else{
                s1 = m1 + 1;
                d2 = m2;
            }
        }else{
            if((s2+d2)%2 == 0){
                d1 = m1;
                s2 = m2;
            }else{
                d1 = m1;
                s2 = m2 + 1;
            }
        }
    }
    return A->Data[s1] < B->Data[s2]? A->Data[s1] : B->Data[s2];
}

//因为出现次数大于L/2, 每次遇到不同的计数器减一，最后还至少会留下一个。
ElementType problem_6(List A){
    ElementType major=A->Data[0], count = 1;
    
    for(int i=1; i<A->Last; i++){
        if(count==0){
            count++;
            major = A->Data[i];
        }else if(major==A->Data[i]){
            count++;
        }else count--;
    }
    return major;
}

