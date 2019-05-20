//
//  HashTable.hpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/28.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include "CommonHeader.hpp"
#define ElementType int
#define Position int
#define MinTableSize 10
enum CellInfo{
    Empty = 0,Legitimate,Delete
};

struct Cell{
    CellInfo Info;
    ElementType Element;
};

typedef struct HashTbl *HashTable;
struct HashTbl{
    int TableSize;
    Cell *TheCells;
}H;

HashTable InitializeTable(int TableSize){
    HashTable H;
    int i;
    if(TableSize < MinTableSize){
        return NULL;
    }
    H = (HashTable)malloc(sizeof(HashTbl));
    if(H != NULL){
//        H->TableSize = NextPrime(TableSize);
        H->TheCells = (Cell *)malloc(sizeof(H->TableSize));
        if(H->TheCells !=NULL){
            for(i = 0; i < H->TableSize; i++)
                H->TheCells[i].Info = Empty;
        }
    }
    return H;
}

Position Hash(ElementType Key,int HashTableSize){
    return HashTableSize % Key;
}

Position Find(ElementType Key,HashTable H){
    Position CurrentPos,NewPos;
    int CNum = 0; //冲突次数
    NewPos = CurrentPos = Hash(Key,H->TableSize);
    while(H->TheCells[NewPos].Info != Empty && H->TheCells[NewPos].Element != Key){
        if(++CNum %= 2){
            NewPos = CurrentPos + (CNum + 1)/2 *(CNum + 1)/2;
            while (NewPos >= H->TableSize) {
                NewPos -= H->TableSize;
            }
        }else{
            NewPos = CurrentPos - CNum/2 * CNum/2;
            while (NewPos < 0) {
                NewPos += H->TableSize;
            }
        }
    }
    return NewPos;
}

void Insert(ElementType Key,HashTable H){
    Position Pos = Find(Key, H);
    if(H->TheCells[Pos].Info != Legitimate){
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}

#endif /* HashTable_hpp */
