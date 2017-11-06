//
//  Stack.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/10/11.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "StackWork.hpp"
bool isLegitimateStackOut(char *str);
bool kuohaopipei(char *str);

void StackFunctionRun(){
    
    
}

//判断是否合法出栈序列
bool isLegitimateStackOut(char *str){
    int count = 0,index = 0;
    while(str[index++]){
        if(str[index - 1] == 'I'){
            count++;
        }else{
            count--;
        }
        if(count < 0) return false;
    }
    if(count != 0) return false;
    return true;
}

//判断链表是否对称
//两个栈实现队列 入队 出队 队空
SqStack s1,s2;
void enQueueWithStack(Elemtype x){
    if(!StackOverFlower(s1))
        Push(s1, x);
    else if(StackOverFlower(s1) && !StackEmpty(s2)) printf("满\n");
    else {
        while (StackEmpty(s1)) {
            Elemtype temp;
            Pop(s1, temp);
            Push(s2, temp);
        }
        Push(s1, x);
    }
}

void deQueueWithStack(Elemtype &x){
    if(!StackEmpty(s2)){
        Push(s2, x);
    }
    else if(StackEmpty(s1)) printf("空\n");
    else {
        while(!StackEmpty(s2)){
            Elemtype temp;
            Pop(s1, temp);
            Push(s2, temp);
        }
        Push(s2, x);
    }
}

//括号匹配
bool kuohaopipei(char *str){
    char s[50];
    int top = -1;
    for(int i = 0; str[i]; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            s[++top] = str[i];
        }else if(str[i] == ')'){
            if(s[top] != '(') return false;
            top--;
        }else if(str[i] == ']'){
            if(s[top] != '[') return false;
            top--;
        }else if(str[i] == '}'){
            if(s[top] != '{') return false;
            top--;
        }
    }
    return true;
}
