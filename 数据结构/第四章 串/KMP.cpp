//
//  KMP.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/4/13.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "KMP.h"


void getNext(char N[],int next[]){
    int n = (int)strlen(N);
    int j = 1,i;
    for (;j < n;j++) {
        i = next[j - 1];
        while(N[i + 1] != N[j] && i >= 0) i = next[i];
        if(N[i + 1] == N[j]) next[j] = i + 1;
        else next[j] = -1;
    }
}

int KMP(char M[],char N[]){
    int n = (int)strlen(N);
    int next[n];
    memset(next, -1, sizeof(next));
    getNext(N, next);
    int m = (int)strlen(M);
    int j = 0, i = -1;
    for(;j < m; j++){
        while(N[i + 1] != M[j] && i >= 0) i = next[i];
        if(N[i + 1] == M[j]) i++;
        if(i == n - 1) return j - i;
    }
    return -1;
}
