//
// Created by 黄人煌 on 2018/3/28.
//

#ifndef KYDS_LISTBASE_H
#define KYDS_LISTBASE_H

#include "../CommonDefine.h"


class ListBase {

public:
    ListBase();
    Status ClearList();
    Status ListEmpty();
    Status ListLength();
    ElemType GetElem(int i);
    Status LocateElem(ElemType e);
    ElemType PriorElem(ElemType cur_e);
    ElemType NextElem(ElemType cur_e);
    Status  ListInsert(ElemType e,int i);
    Status  ListDelete(ElemType e,int i);
    Status  ListTraverse();
private:
    int Length = 0;
    Status  DestroyList();
};


#endif //KYDS_LISTBASE_H
