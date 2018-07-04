//
// Created by 黄人煌 on 2018/4/19.
//

#include "../Include/Practice2.h"
#include "../第二章 线性表/SqList.h"
#include "../第二章 线性表/SLinkList.h"
#include "../第二章 线性表/LinkList.h"

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

/*
 * 2.10 指出以下算法中的错误和低效之处，并将它改写为一个既正确又高效的算法。
 * Status DeleteK(SqList &a,int i,int k){
    //本过程从顺序存储结构的线性表 a 中删除第 i 个元素起的 k 个元素
    if(i<1||k<0||i+k>a.length) return INFEASIBLE;//参数不合法
    else {
        for(count=1;count<k;count++){ //删除第一个元素
             for(j=a.length;j>=i+1;j--) a.elem[j-i]=a.elem[j];
                   a.length--;
    }
    return OK;
 }*/

//解：这个算法每删除一个元素，就要操作一次后面所有数据往前移动，可以优化直接前移k个元素
Status DeleteK(SqList &a, int i, int k) {
    //本过程从顺序存储结构的线性表 a 中删除第 i 个元素起的 k 个元素
    if (i < 1 || k < 0 || i + k > a.length) return INFEASIBLE;//参数不合法
    else {
        for (int j = 0; j < k; j++)
            a.elem[j + i] = a.elem[j + i + k];
        a.length -= k;
    }
    return OK;
}

//2.11 设顺序表 va 中的数据元素递增有序。试写一算法，将 x 插入到顺序表的适当位置上，以保持该表的 有序性。
Status InsertOrderList(SqList &va, ElemType x) {
    int i;
    if (va.length == va.listsize)return (OVERFLOW);
    for (i = va.length; i > 0, x < va.elem[i - 1]; i--)
        va.elem[i] = va.elem[i - 1];
    va.elem[i] = x;
    va.length++;
    return OK;
}

/*2.12 设 A 和 B 均为顺序表,A'和B'分别为A和B中除去最大共同前
 * 缀后的子表。若A'=B'=空表，则A=B;若A'=空表，而B'!= 空表，或者两者均不为空表，且A' 的首元小于B'的首元，
 * 则A<B;否则A>B。试写一个比较A，B大小的算法。
 */
Status CompareOrderList(SqList &A, SqList &B) {
    int i, j;
    while (A.elem[i] == B.elem[i] && i < A.length && i < B.length) {
        i++;
    }
    if (A.length == i && A.elem[i] < B.elem[i]) j = -1;
    else if (B.length == i && A.elem[i] > A.elem[i]) j = 1;
    else if (A.length == B.length == i) j = 0;
    return j;

}

//2.13 试写一算法在带头结点的单链表结构上实现线性表操作 Locate(L,x);
int LocateElem_L(LinkList &L, ElemType x) {
    int i = 0;
    Link p = L.head;
    while (p && p->data != x) {
        p = p->next;
        i++;
    }
    if (!p) return 0;
    else return i;
}

//2.14 试写一算法在带头结点的单链表结构上实现线性表操作 Length(L)
int ListLength_L(LinkList &L) {
    int i = 0;
    Link p = L.head;
    while (p && p->next) {
        p = p->next;
        i++;
    }
    return i;
}

/*
 * 2.15 已知指针 ha 和 hb 分别指向两个单链表的头结点，并且已知两个链表的长度分别为 m 和 n。
 * 试写一算 法将这两个链表连接在一起，假设指针 hc 指向连接后的链表的头结点，并要求算法以尽可能短的时间完 成连接运算。
 * 请分析你的算法的时间复杂度。
 */
void MergeList_L(LinkList &ha, LinkList &hb, LinkList &hc) {
    Link pa = ha.head, pb = hb.head;
    while (pa->next && pb->next) {
        pa = pa->next;
        pb = pb->next;
    }
    if (!pa->next) {
        hc = hb;
        while (pb->next) pb = pb->next;
        pb->next = ha.head;
    } else {
        hc = ha;
        while (pa->next) pa = pa->next;
        pa->next = hb.head;
    }
}

/*
 * 2.16 已知指针 la 和 lb 分别指向两个无头结点单链表中的首元结点。
 * 下列算法是从表 la 中删除自第 i 个 元素起共 len 个元素后，将它们插入到表 lb 中第 i 个元素之前。
 * 试问此算法是否正确?若有错，请改正 之。
 *  Status DeleteAndInsertSub(LinkedList la,LinkedList lb,int i,int j,int len）{
        if(i<0||j<0||len<0) return INFEASIBLE;
        p=la; k=1;
            while(k<i){
            p=p->next; q=p;
            while(k<=len){
            q=q->next; s=lb; k=1;
                k++;
            } k++;
            } k++;
        }
         while(k<j){ s=s->next; s->next=p; q->next=s->next; return OK;
    }
 * */
Status DeleteAndInsertSub(LinkList &la, LinkList &lb, int i, int j, int len) {
    Link q, p, s, prev = NULL;
    int k = 1;
    if (i < 0 || j < 0 || len < 0) return INFEASIBLE; // 在la表中查找第i个结点
    p = la.head;
    while (p && k < i) {
        prev = p;
        p = p->next;
        k++;
    }
    if (!p)return INFEASIBLE;
    // 在 la 表中查找第 i+len-1 个结点
    q = p;
    k = 1;
    while (q && k < len) {
        q = p->next;
        k++;
    }
    if (!q)return INFEASIBLE;
    // 完成删除，注意，i=1 的情况需要特殊处理
    if (!prev) la.head = q->next;
    else prev->next = q->next;
    // 将从 la 中删除的结点插入到 lb 中
    if (j = 1) {
        q->next = lb.head;
        lb.head = p;
    } else {
        s = lb.head;
        k = 1;
        while (s && k < j - 1) {
            s = s->next;
            k++;
        }
        if (!s)return INFEASIBLE;
        q->next = s->next;
        s->next = p; //完成插入
    }
    return OK;
}

void runPractice2() {
//    test();                //3,2,5,7,6,4    1,2,9,6
// (A - B)U(B - A) 测试数据 A=(c,b,e,g,f,d) B=(a,b,n,f)  结果 (c,e,g,d,n,a)
//    SLinkList space;
//    int s;
//    difference(space,s);
//    ListTraverse(space);


}