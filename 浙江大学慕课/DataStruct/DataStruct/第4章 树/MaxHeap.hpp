//
//  MaxHeap.hpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/24.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef MaxHeap_hpp
#define MaxHeap_hpp
#ifndef ElementType
#define ElementType int
#endif
#define MAXSIZE 100
typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType *Elements;
    int Size;
    int Capacity; //堆的最大容量
};

MaxHeap CreateMaxHeap(){
    MaxHeap H = (HeapStruct *)malloc(sizeof(HeapStruct));
    H->Elements = (ElementType *)malloc(sizeof(ElementType) * (MAXSIZE + 1));
    H->Size = 0;
    H->Capacity = MAXSIZE;
    H->Elements[0] = INT_MAX;
    return H;
}

void Insert(MaxHeap H, ElementType item){
    int i;
    if(H->Size == H->Capacity){
        printf("最大堆已满\n");
        return;
    }
    i = ++H->Size;
    for(;H->Elements[i/2] < item; i/=2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = item;
}

ElementType DeleteMax(MaxHeap H){
    int Parent,Child;
    ElementType MaxItem,temp;
    if(H->Size == 0){
        printf("最大堆已空\n");
        return -1;
    }
    MaxItem = H->Elements[1];
    temp = H->Elements[H->Size--];
    for(Parent = 1;Parent * 2 < H->Size; Parent = Child){
        Child = Parent * 2;
        if((Child != H->Size)&&(H->Elements[Child] < H->Elements[Child+1]))
            Child++;
        if(temp > H->Elements[Child]) break;
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}
#endif /* MaxHeap_h */
