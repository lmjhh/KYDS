//
// Created by 黄人煌 on 2018/4/19.
//

#include "../Include/Practice2.h"
#include "../第二章 线性表/SqList.h"
#include "../第二章 线性表/SLinkList.h"

//Test
void test() {
    SqList list, listb, listc;
    InitList(list);
    for (int i = 0; i < 10; i++) ListInsert(list, i, i);
    ListTraverse(list);
    ElemType e;
    ListDelete(list, e, 5);
    ListTraverse(list);
    cout << e << endl;
    InitList(listb);
    for (int i = 0; i < 22; i++) ListInsert(listb, i, i);
    MergeList(list, listb, listc);
    ListTraverse(listc);
}

//用静态链表实现(A - B)U(B - A)
void difference(SLinkList &space, int &S) {
    //依次输入集合A和B的元素，在一维数组space中简历表示集合(A - B)U(B - A)的静态链表，S为其头指针
    //假设备用空间足够大，space[0].cur 为其头指针
    InitList(space);
    S = Malloc(space);
    int r = S, m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        int j = Malloc(space);
        cin >> space[j].data;
        space[r].cur = j;
        r = j;
    }
    space[r].cur = 0;
    for (int i = 1; i <= n; i++) {
        int b, p = S, k = space[S].cur;
        cin >> b;
        while (k != space[r].cur && space[k].data != b) {
            p = k;
            k = space[k].cur;
        }
        if (k == space[r].cur) {
            int j = Malloc(space);
            space[j].data = b;
            space[j].cur = space[r].cur;
            space[r].cur = j;
        } else {
            space[p].cur = space[k].cur;
            Free(space, k);
            if (r == k) r = p;
        }
    }
}

void runPractice2() {
//    test();                //3,2,5,7,6,4    1,2,9,6
// (A - B)U(B - A) 测试数据 A=(c,b,e,g,f,d) B=(a,b,n,f)  结果 (c,e,g,d,n,a)
//    SLinkList space;
//    int s;
//    difference(space,s);
//    ListTraverse(space);


}