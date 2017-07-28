//
//  main.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/4/13.
//  Copyright © 2017年 黄人煌. All rights reserved.
//
#include "SQListHeader.h"

int main(int argc, const char * argv[]) {
    
    SqList list;
    list.elem = new int[4];
    for(int i = 0; i < 4; i++) list.elem[i] = i;
    list.length = 4;
    cout << deleminElemt(list) << endl;
    printElemt(list);
    
    reverseList(list);
    printElemt(list);
    
    for(int i = 0; i < 4; i++) list.elem[i] = i;
    list.elem[2] = 3;
    list.length = 4;
    deleValueEqualX(list, 3);
    printElemt(list);
    
    return 0;
}
