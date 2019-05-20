//
//  ArrayStack.hpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/4.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef ArrayStack_hpp
#define ArrayStack_hpp

#include "CommonHeader.hpp"
#ifndef ElementType
#define ElementType int
#define MAXSIZE 100
#endif
typedef struct ArraySNode *Stack;
struct ArraySNode{
    ElementType Data[MAXSIZE];
    int Top;
};

Stack CreateStack(){
    Stack stack = (Stack)malloc(sizeof(ArraySNode));
    stack->Top = -1;
    return stack;
}

bool IsEmpty(ArraySNode PtrS){
    if (PtrS.Top == -1){
        return true;
    }
    return false;
}

void Push(Stack PtrS, ElementType item){
    if (PtrS->Top == MAXSIZE - 1){
        printf("堆栈满");
        return;
    }else{
        PtrS->Data[++(PtrS->Top)] = item;  // item应该放top上面的一个位置
        return;
    }
}

ElementType Pop(ArraySNode PtrS){
    if (PtrS.Top == -1){
        printf("堆栈空");
        return ERROR;  /*ERROR是ElementType的特殊值，标志错误*/
    }else
        return (PtrS.Data[(PtrS.Top)--]);
}

#endif /* ArrayStack_hpp */
