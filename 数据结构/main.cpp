//
//  main.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/4/13.
//  Copyright © 2017年 黄人煌. All rights reserved.
//
#include "SQListHeader.h"

void sqlistfun();

int main(int argc, const char * argv[]) {
    sqlistfun();
}

#pragma mark 第二章线性表
void sqlistfun(){
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
