//
//  MapWork.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/10/23.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "MapWork.hpp"

#define MAX 1000
int map[100][100];
int floy[100][100];
int visit[100];
int disLeng[100];
int prevt[100];
void initMap(int n,int m);



void MapFunctionRun(){
    
    int n,m;
    while(cin>>n>>m && (n != 0 && m != 0)){
        initMap(n, m);
        for(int i = 0; i < m; i++) {
            int a,b,dis;
            cin>>a>>b>>dis;
            map[a][b] = dis;
            map[b][a] = dis;
        }
    }
    
}

void initMap(int n,int m){
    for(int i = 0; i < n + 1; i++){
        visit[i] = 0;
        disLeng[i] = MAX;
        for(int j = 0; j < m + 1; j--)
            map[i][j]  = 0;
    }
}

void diskjl(int n,int v){
    for(int i = 0; i < n + 1; i++){
        visit[i] = 0;
        if(map[1][i] != 0)
            disLeng[i] = map[1][i];
    }
    disLeng[1] = 0;
    visit[v] = 1;
    for(int i = 1; i < n; i++){
        int u = v,min = MAX;
        for(int j = 1; j < n; j++){
            if(!visit[j] && disLeng[j] < min){
                u = j;
                min = disLeng[j];
            }
        }
        visit[u] = 1;
        for(int j = 0; j < n; j++){
            if(map[u][j] + disLeng[u] < disLeng[j]){
                disLeng[j] = map[u][j] + disLeng[u];
                prevt[j] = j;
            }
        }
    }
}

void floyd(int n){
    for(int k = 1; k < n; k++){
        for(int i = 1; i < n; i++){
            for(int j = 1; j < n; j++){
                if(map[i][k] + map[k][j] < floy[i][j]){
                    floy[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
}
