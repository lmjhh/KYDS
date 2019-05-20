#include "CommonHeader.hpp"
#define ElementType int
#define MAXSIZE 100
typedef int Position;

typedef struct LNode{
    ElementType Data[MAXSIZE];
    Position Last;  // 代表线性表的最后一个元素
}*List;

List MakeEmpty(){
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL -> Last = -1;
    return PtrL;
}

Position Find(ElementType X, List PtrL){
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != X)
        i++;
    if (i > PtrL->Last)  return -1;  // 如果没找到，返回-1
    else return i;  //找到后返回的是存储位置
}

bool Insert(ElementType X, int i, List PtrL){
    int j;
    if (PtrL->Last == MAXSIZE - 1){  /*表空间已满，不能插入*/
        printf("表满");
        return false;}
    if (i < 1 || i > PtrL -> Last + 2){ /*检查插入位置的合法性*/
        printf("位置不合法");
        return false;}
    if(PtrL->Last >= 0)
    for (j = PtrL->Last; j >= i - 1; j--)
        PtrL->Data[j+1] = PtrL->Data[j];  /*将ai~an倒序向后移动*/
    PtrL->Data[i-1] = X;  /*新元素插入*/
    PtrL->Last++;         /*Last仍指向最后元素*/
    return true;
}

bool Delete(int i, List PtrL){
    int j;
    if (i < 1 || i > PtrL -> Last + 1){  /*检查空表及删除位置的合法性*/
        printf("不存在第%d个元素", i);
        return false;}
    for(j = i; j <= PtrL->Last; j++)
        PtrL->Data[j-1] = PtrL->Data[j];  /*将ai+1~an顺序向前移动*/
    PtrL->Last--;  /*Last仍指向最后元素*/
    return true;
}

void ReverseList(List PtrL, int left, int right){
    if(left >= right || right >= PtrL->Last)
        return;
    int mid = (right + left)/2;
    for(int i = 0; i < mid - left; i++){
        ElementType temp = PtrL->Data[left+i];
        PtrL->Data[left+i] = PtrL->Data[right-i];
        PtrL->Data[right-i] = temp;
    }
}
