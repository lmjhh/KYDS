//
//  Set.hpp
//  DataStruct
//
//  Created by 黄人煌 on 2018/8/24.
//  Copyright © 2018年 nd. All rights reserved.
//

#ifndef Set_hpp
#define Set_hpp
#ifndef ElementType
#define ElementType int
#endif

void init(int n) {
    for (int i = 0; i <= n; fa[i] = i) fa[i] = i;
}
void unin(int u, int v) {
    fa[find(v)] = find(u);
}
int find(int u) {
    return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

#endif /* Set_h */
