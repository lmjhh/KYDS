//
//  TreeWork.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/10/18.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "TreeWork.hpp"

void TreeFunctionRun(){
    BiTree T;
//          1
//      2         3
//          4           5
    //1 2 -1 4 -1 -1 3 -1 5 -1 -1
    CreatBitTree(T);
    cout << "先序:" << endl;
    PreOrder(T); cout<<"END"<<endl;
    cout << "中序:" << endl;
    InOrder(T); cout<<"END"<<endl;
    cout << "后序:" << endl;
    PostOrder(T); cout<<"END"<<endl;
    cout << "先序不递归:" << endl;
    PreOrderWithStack(T); cout<<"END"<<endl;
    cout << "中序不递归:" << endl;
    InOrderWithStack(T); cout<<"END"<<endl;
    cout << "后序不递归:" << endl;
    PostOrderWithStack(T); cout<<"END"<<endl;
    cout << "反向层次遍历:" << endl;
    ReverseBFS(T); cout<<"END"<<endl;
    cout << "树的深度:" << endl;
    cout << BtDepth(T) << endl;
}

