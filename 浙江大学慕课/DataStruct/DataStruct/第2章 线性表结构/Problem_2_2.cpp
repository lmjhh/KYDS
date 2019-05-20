//
//  Problem_2_2.cpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/11/8.
//  Copyright © 2018 nd. All rights reserved.
//

#include "Problem_2_2.hpp"
#include "LinkList.hpp"

//带头结点的单链表L就地逆置（头插）
void problem_1(LinkList L);
//找到两个链表的公共结点
LinkLNode* problem_2(LinkList LA,LinkList LB);


void problem_2_2(){
    LinkList L = Insert(1, 1, NULL);
    L = Insert(2, 2, L);
    L = Insert(3, 3, L);
    L = Insert(4, 4, L);
    L = Insert(5, 5, L);
    
    //    problem_5(L);
    
    LinkLNode *p = L;
    while(p->Next != NULL){
        cout<<p->Data<<"->";
        p=p->Next;
    }
    cout<<p->Data<<endl;
    
}


//带头结点的单链表L就地逆置（头插,这段代码是依次反转）
void problem_1(LinkList L){
    LinkLNode *p = L->Next, *q = p->Next, *pre;
    p->Next = NULL;
    while(q != NULL){
        pre = p;
        p = q;
        q = q->Next;
        p->Next = pre;
    }
    L->Next = p;
}

//找到两个链表的公共结点
//  111222333
//    1342333
//末尾对齐查找
LinkLNode* problem_2(LinkList LA,LinkList LB){
    int lenA = Length(LA),lenB = Length(LB);
    int dist;
    LinkList longList,shortList;
    if(lenA > lenB){
        longList = LA;
        shortList = LB;
        dist = lenA - lenB;
    }else{
        longList = LB;
        shortList = LA;
        dist = lenB - lenA;
    }
    while (dist--)
        longList = longList->Next;
    while (longList != NULL) {
        if(longList == shortList){
            return longList;
        }else{
            longList = longList->Next;
            shortList = shortList->Next;
        }
    }
    return NULL;
}
