//
//  MGraph.h
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/25.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef MGraph_hpp
#define MGraph_hpp
#include "CommonHeader.hpp"
#define WeightType int
#define Vertex int
#define VertexNum 100
typedef struct GNode *PtrToGNode;
struct GNode {
    int Ne;
    int Nv;
    WeightType G[VertexNum][VertexNum];
};
typedef PtrToGNode MGraph;

typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

MGraph CreateMGraph(){
    MGraph Graph;
    Graph = (GNode *)malloc(sizeof(GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    memset(Graph->G, 0, sizeof(WeightType) * VertexNum * VertexNum);
    return Graph;
}

void InsertEdge(MGraph Graph,Edge E){
    Graph->G[E->V1][E->V2] = E->Weight;
    //若是无向图
    Graph->Ne++;
}

void DijkstraMGraph(MGraph Graph,Vertex V){
    bool visit[VertexNum] = {false};
    Vertex path[VertexNum];
    WeightType dis[VertexNum];
    memset(dis, 0, sizeof(WeightType) * VertexNum);
    memset(dis, -1, sizeof(Vertex) * VertexNum);
    visit[V] = true;
    for(int i = 1;i < VertexNum;i++){
        dis[i] = Graph->G[V][i];
        path[i] = V;
    }
    for(int i = 1;i < VertexNum;i++){
        int temp = INT32_MAX;
        int u = V;
        for(int j = 1;j <= VertexNum;j++)
            if(!visit[j] && dis[j] < temp){
                u = j;
                temp = dis[j];
            }
        visit[u] = true;
        for(int j = 1;j <= VertexNum;j++)
            if(!visit[j] && Graph->G[u][j] < INT32_MAX && (Graph->G[u][j] + dis[u]) < dis[j]){
                dis[j] = Graph->G[u][j] + dis[u];
                path[j] = u;
            }
    }
}

void FloydMGraph(MGraph Graph){
    WeightType dis[VertexNum][VertexNum];
    Vertex path[VertexNum][VertexNum];
    for(int i = 0; i < VertexNum; i++)
        for(int j = 0; j < VertexNum; j++){
            dis[i][j] = Graph->G[i][j];
            path[i][j] = -1;
        }
    for(int k = 0; k < VertexNum; k++)
        for(int i = 0; i < VertexNum; i++)
            for(int j = 0; j < VertexNum; j++){
                if(dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                    path[i][j] = k;
                }
            }
}

#endif /* MGraph_hpp */
