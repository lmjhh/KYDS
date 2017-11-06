//
//  SortHeader.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/10/26.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "SortHeader.hpp"

//直接插入排序
void InsertSort(Elemtype e[],int n){
    int temp = 0;
    for(int i = 2; i < n; i++){
        if(e[i] < e[i - 1]){
            temp = e[i];
            for(int j = i - 1; j >= 0; j--) {
               if(e[j > temp]) e[j + 1] = e[j];
               else e[j] = temp;
            }
        }
    }
    
    
}
