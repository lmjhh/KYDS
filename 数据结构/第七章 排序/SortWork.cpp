//
//  SortWork.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/10/26.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "SortWork.hpp"
#include "SortHeader.hpp"

void coutNum(int Num[],int n){
    for(int i = 0; i < n; i++) cout <<Num[i]<<" ";
    cout<<endl;
}

void SortFunctionRun(){
    int num[20] =  {1,3,2,5,6,7,3,10,8,20};
    InsertSort(num, 10);
    coutNum(num, 10);
    
}
