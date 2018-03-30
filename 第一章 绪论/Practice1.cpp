//
// Created by 黄人煌 on 2018/3/22.
//
#include "Practice1.h"

/*
 * 试写一算法，自大至小依次输出顺序读入的三个整数 X，Y 和 Z 的值
 */
void practice1_16(int x,int y,int z){
    if(x < y) swap(x,y);
    if(x < z) swap(x,z);
    if(y < z) swap(y,z);
    cout<<x<<">"<<y<<">"<<z<<endl;
}

/*
 * f(0) = 0,f(1) = 0....f(k-1) = 1;
 * f(n) = f(n-1) + .... + f(n-k), n = k,k+1.....
 * 试编写求 k 阶斐波那契序列的第 m 项值的函数算法，k 和 m 均以值调用的形式在函数参数表中出现。
 */

int practice1_17(int k,int m){
    if(m < k - 1) {
        return 0;
    }else if(m == k - 1){
        return 1;
    }else {
        int value = practice1_17(k,m-k);
        for(int i = 1; i < k; i++) value += practice1_17(k,m - i);
        return value;
    }
    //标答
//    int Fibonacci(int k,int n)
//    {
//        if(k<1) exit(OVERFLOW);
//        int *p,x;
//        p=new int[k+1];
//        if(!p) exit(OVERFLOW);
//        int i,j;
//        for(i=0;i<k+1;i++){
//            if(i<k-1) p[i]=0;
//            else p[i]=1;
//        }
//        for(i=k+1;i<n+1;i++){
//            x=p[0];
//            for(j=0;j<k;j++) p[j]=p[j+1];
//            p[k]=2*p[k-1]-x;
//        }
//        return p[k];
//    }
}

/*
 * 假设有 A，B，C，D，E 五个高等院校进行田径对抗赛，各院校的单项成绩均已存入计算机，并构成 一张表，表中每一行的形式为
 * 项目名称 性别 校名 成绩 得分
 */

typedef enum {A,B,C,D,E} SchoolName;
typedef enum {Female,Male} SexType;
typedef struct {
    char event[3]; //项目
    SexType sex;
    SchoolName school;
    int score;
} Component;
typedef struct{
    int MaleSum;  //男团总分
    int FemaleSum;//女团总分
    int TotalSum; //团体总分
} Sum;

Sum SumScore(SchoolName sn,Component a[],int n) {
    Sum temp;
    temp.MaleSum=0;
    temp.FemaleSum=0;
    temp.TotalSum=0;
    int i;
    for(i=0;i<n;i++){
        if(a[i].school==sn){
            if(a[i].sex==Male) temp.MaleSum+=a[i].score;
            if(a[i].sex==Female) temp.FemaleSum+=a[i].score;
        } }
    temp.TotalSum=temp.MaleSum+temp.FemaleSum;
    return temp;
}

/*
 * 试编写算法，计算 i!*2^i 的值并存入数组 a[0..arrsize-1]的第 i-1 个分量中(i=1,2,...,n)。
 * 假设计 算机中允许的整数最大值为maxint，则当n>arrsize或对某个k(1<= k <= n)，使k! * 2^k > maxint时，
 * 应按出错处理。注意选择你认为较好的出错处理方法。
 */
int arraySize = 100;
int maxInt = 65535;
Status practice1_19(int array[],int n){
    if(n > arraySize) return OVERFLOW;
    for(int i = 1; i < arraySize; i++){
        int value = i;
        for(int j = 1; j < i; j++) value*=i;
        value *= pow(2,i);
        if(value > maxInt) return OVERFLOW;
        else array[i] = value;
    }
    return OK;
}

/*
 *  试编写算法求一元多项式的值 Pn(x)= sum(ai * x^i)的值 Pn(x)，并确定算法中每一语句的执行次数
 *  整个算法的时间复杂度。注意选择你认为较好的输入和输出方法。
 *  本题的输入为ai(i = 0,1...n),x0和n,输出为 Pn(x0) 。
 */
int practice1_20(int array[],int x,int n){
    int value = 0;
    for(int i = 0; i < n; i++){
        value += array[i] * pow(x,i);
    }
    return value;

    //时间复杂度O(n)
}

void runPractice1(){
    practice1_16(2,1,3);
    cout<<practice1_17(2,4)<<endl;
}
