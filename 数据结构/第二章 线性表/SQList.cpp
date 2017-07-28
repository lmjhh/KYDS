//
//  SQList.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/7/27.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "SQListHeader.h"

void printElemt(SqList &L){
    for(int i = 0; i < L.length; i++) cout << L.elem[i] << ' ';
    cout << endl;
}
