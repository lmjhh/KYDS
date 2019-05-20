//
//  Problem_3.cpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/11/9.
//  Copyright © 2018 nd. All rights reserved.
//

#include "Problem_3.hpp"

//利用一个栈实现一下递归函数的计算
/*        1   n = 0
pn(x) = { 2x  n = 1
          2xPn-1(x) - 2(n-1)Pn-2(x) n > 1
*/
double problem3_1(int n, double x);

//递归计算最大最小值
void problem3_2(int A[], int n, int &max, int &min);

//GCD
int problem3_3(int m, int n);

//非递归
/*             n+1                  m = 0
 ACK(m,n) =  { ACK(m-1,1)           n = 0, m != 0
               ACK(m-1,ACK(m,n-1))  m != 0, n != 0
*/
int problem3_4(int m, int n);

void problem_3(){
    
}


double problem3_1(int n, double x){
    struct Stack{
        int n;
        double val;
    }st[30];
    int top = -1;
    double fv1 = 1,fv2 = 2*x;
    for(int i = n; i >=2; i--){
        top++;
        st[top].n = i;
    }
    while(top >= 0){
        st[top].val = 2 * x * fv2 - 2 * (st[top].n-1) * fv1;
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    if(n == 0) return fv1;
    return fv2;
}


void problem3_2(int A[], int n, int &max, int &min){
    if(n >= 0){
        if(max < A[n]) max = A[n];
        if(min > A[n]) min = A[n];
        problem3_2(A,n-1,max,min);
    }
}

int problem3_3(int m, int n){
    if(m < n) return problem3_3(n,m);
    if(n == 0) return m;
    else return problem3_3(n, m%n);
}

int problem3_4(int m, int n){
    int akm[50][50],i,j;
    for(j = 0; j < 50; j++) akm[0][j] = j + 1;
    for(i = 0; i < m; i++){
        akm[i][0] = akm[i - 1][1];
        for(j = 1; j < n; j++)
            akm[i][j] = akm[i - 1][akm[i][j - 1]];
    }
    return akm[m][n];
}
