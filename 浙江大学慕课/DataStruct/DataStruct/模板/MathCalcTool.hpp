//
//  MathCalcTool.h
//  DataStruct
//
//  Created by 黄人煌 on 2018/7/14.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef MathCalcTool_h
#define MathCalcTool_h
#include "CommonHeader.hpp"

template<typename T>

T Max3(const T& A ,const T& B, const T& C){
    T Max = A;
    if(Max < B) Max = B;
    if(Max < C) Max = C;
    return Max;
}

template<typename T>

void Swap(T& A ,T& B){
    T C = A;
    A = B;
    B = C;
    /*  整形优化
    a^=b;
    b^=a;       //相当于b=a
    a^=b;       //相当于a=b
    */
}

//T BinarySearch(List Tbl,  K){
//    /*在表Tbl中查找关键字为K的数据元素*/
//    int left, right, mid, NoFound=-1;
//
//    left = 1;  /*初始左边界*/
//    right = Tbl->Length;  /*初始右边界*/
//    while (left <= right){
//        mid = (left + right)/2;  /*计算中间元素的坐标*/
//        if(K < Tbl->Element[mid]) right = mid - 1;  /*调整右边界*/
//        else if(K > Tbl->Element[mid])  left = mid + 1;  /*调整左边界*/
//        else  return mid;  /*查找成功，返回数据元素的下标*/
//    }
//    return NotFound;  /*查找不成功，返回-1*/
//}

#endif /* MathCalcTool_h */
