//
//  LGraph.hpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/25.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef LGraph_hpp
#define LGraph_hpp
#include "CommonHeader.hpp"
#define WeightType int
#define Vertex int
#define VertexNum 100

typedef struct AdjVode *PtrToAdjVNode;
typedef struct GNode *PtrToGNode;
typedef struct Vnode {
    PtrToAdjVNode FirstEdge;
    //DataType Data; //存顶点的数据
}AdjList[VertexNum];

struct AdjVode {
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};


struct GNode {
    int Ne;
    int Nv;
    AdjList G;
};
typedef PtrToGNode LGraph;

typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

LGraph CreateLGraph(){
    LGraph Graph;
    Graph = (GNode *)malloc(sizeof(GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    for (Vertex V = 0; Graph->Nv - 1; V++) {
        Graph->G[V].FirstEdge = NULL;
    }
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E){
    PtrToAdjVNode NewNode;
    NewNode = (PtrToAdjVNode) malloc(sizeof(AdjVode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;
    
    //若是无向图 还应插入v2 v1
}

#endif /* LGraph_hpp */
