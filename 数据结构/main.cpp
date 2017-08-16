//
//  main.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/4/13.
//  Copyright © 2017年 黄人煌. All rights reserved.
//
#include "SQListHeader.h"

void sqlistFun();
void linkListFun();

int main(int argc, const char * argv[]) {
//    sqlistFun();
    linkListFun();
}

#pragma mark 第二章线性表
void sqlistFun(){
    SqList list;
    list.elem = new int[4];
    for(int i = 0; i < 4; i++) list.elem[i] = i;
    list.length = 4;
    cout << "1.1-----------------" <<endl;
    cout << deleminElemt(list) << endl;
    printElemt(list);
    
    cout << "1.2-----------------" <<endl;
    reverseList(list);
    printElemt(list);
    
    cout << "1.3-----------------" <<endl;
    for(int i = 0; i < 4; i++) list.elem[i] = i;
    list.elem[2] = 3;
    list.length = 4;
    deleValueEqualX(list, 3);
    printElemt(list);
    
    cout << "1.4-----------------" <<endl;
    for(int i = 0; i < 4; i++) list.elem[i] = i;
    list.length = 4;
    deleFromSToTinSortArray(list, 1, 3);
    printElemt(list);
    
    cout << "1.5-----------------" <<endl;
    list.elem = new int[6];
    list.elem[0] = 3;list.elem[1] = 1; list.elem[2] = 2;
    list.elem[3] = 6;list.elem[4] = 4; list.elem[5] = 9;
    list.length = 6;
    deleSToTFormArray(list, 2, 6);
    printElemt(list);
    
    cout << "1.6-----------------" <<endl;
    for(int i = 0; i < 4; i++) list.elem[i] = i;
    list.elem[0] = 1;list.elem[1] = 2; list.elem[2] = 2;
    list.elem[3] = 3;list.elem[4] = 4; list.elem[5] = 9;
    list.length = 6;
    deleRepeatElemFromSortArray(list);
    printElemt(list);
    
    cout << "1.7-----------------" <<endl;
    SqList L,M;
    L.elem = new int[5];
    L.length = 5;
    M.elem = new int[3];
    M.length = 3;
    L.elem[0] = 1;L.elem[1] = 3; L.elem[2] = 6;
    L.elem[3] = 7;L.elem[4] = 9;
    M.elem[0] = 2;M.elem[1] = 3; M.elem[2] = 5;
    SqList composList = composeTwoArray(L, M);
    printElemt(composList);
    
    cout << "1.8-----------------" <<endl;
    L.elem = new int(8);
    L.length = 8;
    for(int i = 0; i < 8; i++) L.elem[i] = i+1;
    cout<<"第一组n = 3 < m = 5:"<<endl;
    swapSqlistAandB(L, 3, 5);
    printElemt(L);
    cout<<"第二组n = m = 4:"<<endl;
    for(int i = 0; i < 8; i++) L.elem[i] = i+1;
    swapSqlistAandB(L, 4, 4);
    printElemt(L);
    cout<<"第三组n = 5 > m = 3:"<<endl;
    for(int i = 0; i < 8; i++) L.elem[i] = i+1;
    swapSqlistAandB(L, 5, 3);
    printElemt(L);
    
    cout << "1.9-----------------" <<endl;
    cout<<"第一组存在X:"<<endl;
    L.length = 5;
    for(int i = 0; i < 5; i++) L.elem[i] = i+1;
    searchXFromSortArray(L, 3);
    printElemt(L);
    cout<<"第二组不存在存在X:"<<endl;
    L.elem[0] = 1;L.elem[1] = 3; L.elem[2] = 6;
    L.elem[3] = 7;L.elem[4] = 9;
    searchXFromSortArray(L, 5);
    printElemt(L);
    
    cout << "1.10-----------------" <<endl;
    L.length = 5;
    for(int i = 0; i < 5; i++) L.elem[i] = i+1;
    leftLoopPindex(L, 3);
    printElemt(L);
    
    cout << "1.11-----------------" <<endl;
    L.elem = new int[5];
    L.length = 5;
    for(int i = 0; i < 5; i++) L.elem[i] = 11 + 2*i;
    M.elem = new int[5];
    M.length = 5;
    for(int i = 0; i < 4; i++) M.elem[i] = 2 * (i + 1);
    M.elem[4] = 20;
    cout << searchMidNumFromTwoEqualArray(L, M) << endl;
    
    cout << "1.12-----------------" <<endl;
    L.elem = new int[8];
    L.length = 8;
    L.elem[0] = 0;L.elem[1] = 5; L.elem[2] = 5;
    L.elem[3] = 3;L.elem[4] = 5;
    L.elem[5] = 1;L.elem[6] = 5; L.elem[7] = 7;
    cout<<searchMainEleminArray(L) <<endl;
}

void linkListFun(){
    LinkList L;
    cout << "2.1-----------------" <<endl;
    initLinkList(L, false);
    vector<int> array = {1,2,2,3,2,4,5};
    insertArrayIntoList(array, L, false);
    printElemt(L,false);
    recursionDeleteValueEqualX(L, 2);
    printElemt(L,false);
    cout << "2.2-----------------" <<endl;
    array = {1,2,2,3,2,4,5};
    initLinkList(L, true);
    insertArrayIntoList(array, L, true);
    printElemt(L, true);
    DeleteEqualX(L, 2);
    printElemt(L, true);
    cout << "2.3-----------------" <<endl;
    array = {1,2,3,4,5,6,7};
    initLinkList(L, true);
    insertArrayIntoList(array, L, true);
    printElemt(L, true);
    reversePrintElemt(L->next);
    cout<<"end"<<endl;
    cout << "2.4-----------------" <<endl;
    array = {1,2,2,3,2,4,5};
    initLinkList(L, true);
    insertArrayIntoList(array, L, true);
    printElemt(L, true);
    deleteMinElemt(L);
    printElemt(L, true);
    cout << "2.5-----------------" <<endl;
    array = {1,2,3,4,5};
    initLinkList(L, true);
    insertArrayIntoList(array, L, true);
    printElemt(L, true);
    reverseList(L);
    printElemt(L, true);
    cout << "2.6-----------------" <<endl;
    array = {5,4,3,2,1};
    initLinkList(L, true);
    insertArrayIntoList(array, L, true);
    printElemt(L, true);
    sortList(L);
    printElemt(L, true);
    cout << "2.7-----------------" <<endl;
    array = {2,4,3,7,5};
    initLinkList(L, true);
    insertArrayIntoList(array, L, true);
    printElemt(L, true);
    deleteFromXToY(L, 2, 5);
    printElemt(L, true);
    cout << "2.8-----------------" <<endl;
    array = {2,4,3,7,5};
    vector<int> array2 = {1,3,5,7,9,11,13};
    initLinkList(L, true);
    LinkList M;
    initLinkList(M, true);
    insertArrayIntoList(array, L, true);
    insertArrayIntoList(array2, M, true);
    printElemt(L, true);
    printElemt(M, true);
    serchEqualElemt(L, M);
    cout << "2.9-----------------" <<endl;
    array = {2,4,3,7,5};
    initLinkList(L, true);
    insertArrayIntoList(array, L, true);
    printElemt(L, true);
    ascendingInputList(L);
    cout << "2.10-----------------" <<endl;
    array = {2,4,3,7,5};
    initLinkList(L, true);
    insertArrayIntoList(array, L, true);
    printElemt(L, true);
    resolvedList(L);
    cout << "2.11-----------------" <<endl;
    array = {2,4,3,7,5};
    initLinkList(L, true);
    insertArrayIntoList(array, L, true);
    printElemt(L, true);
    resolvedListByDesc(L);
}
