//
// Created by 黄人煌 on 2018/4/24.
//

#include "SLinkList.h"

void InitList(SLinkList &space) {
    for (int i = 0; i < MAXSIZE - 1; i++) space[i].cur = i + 1;
    space[MAXSIZE - 1].cur = 0;
}

/*
 * 备用空间链表
 */
Status Malloc(SLinkList &space) {
    int i = space[0].cur;
    if (space[0].cur) space[0].cur = space[i].cur;
    return i;
}

void Free(SLinkList &space, int k) {
    //将下标为K的空间结点回收到备用链表
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

int LocateElem(SLinkList S, ElemType e) {
    int i = S[0].cur;
    while (i && S[i].data != e) i = S[i].cur;
    return i;
}

Status ListTraverse(SLinkList s) {
    int i = s[1].cur;
    cout << s[i].data;
    while (i) {
        cout << "," << s[i].data;
        i = s[i].cur;
    }
    cout << endl;
}