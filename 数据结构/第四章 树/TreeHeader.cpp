//
//  Tree.cpp
//  数据结构
//
//  Created by 黄人煌 on 2017/10/18.
//  Copyright © 2017年 黄人煌. All rights reserved.
//

#include "TreeHeader.h"
#include "StackHeader.h"

void CreatBitTree(BiTree &T){
    Elemtype data; cin >> data;
    if(data == -1) T = NULL;
    else{
        T = new BiTNode;
        T -> data = data;
        CreatBitTree(T -> lchild);
        CreatBitTree(T -> rchild);
    }
}

void PreOrder(BiTree T){
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void InOrder(BiTree T){
    if(T != NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
void PostOrder(BiTree T){
    if(T != NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}


void PreOrderWithStack(BiTree T){
    BiTNode* s[50]; int top = -1;
    s[++top] = T;
    while(top != -1){
        T = s[top];
        cout<<s[top--]->data<<"->";
        if(T -> rchild != NULL){
            s[++top] = T -> rchild;
        }
        if(T -> lchild != NULL){
            s[++top] = T -> lchild;
        }
    }
}

void InOrderWithStack(BiTree T){
    BiTNode* s[50]; int top = -1;
    BiTNode *root = T;
    while(root || top != -1){
        if(root){  //加入所有左子树
            s[++top] = root;
            root = root -> lchild;
        }else{ //左子树加完了 输出左子树父节点 加右子树
            root = s[top] -> rchild;
            cout<<s[top--]->data<<"->";
        }
    }
}

void PostOrderWithStack(BiTree T){
    BiTNode* s[50]; int top = -1;
    BiTNode *root = T,*pre = NULL;
    while(root || top != -1){
        if(root){
            s[++top] = root;
            root = root -> lchild;
        }else {
            if(s[top] -> rchild && s[top] -> rchild != pre) //如果没被输出过 往右走
                root = s[top] -> rchild;
            else{
                pre = s[top];
                cout<<s[top--]->data<<"->";
            }
        }
    }
}

void ReverseBFS(BiTree T){
    BiTNode* s[50]; int top = -1;
    BiTNode* q[50]; int rear = 0,front = 0;
    BiTNode *root = T;
    q[rear++] = root;
    while(rear != front){
        root =  q[front++];
        s[++top] = root;
        if(root -> lchild){
            q[rear++] = root -> lchild;
        }
        if(root -> rchild){
            q[rear++] = root -> rchild;
        }
    }
    while(top != -1){
        visit(s[top--]);
    }
}

int BtDepth(BiTree T){
    if(T == NULL) return 0;
    int front = -1,rear = -1;
    int last = 0,level = 0;
    BiTree Q[MaxSize],root = NULL;
    Q[++rear] = T;
    while(front < rear){
        root = Q[++front];
        if(root -> lchild){
            Q[++rear] = root -> lchild;
        }
        if(root -> rchild){
            Q[++rear] = root -> rchild;
        }
        if(front == last) {
            level++;
            last = rear;
        }
    }
    return level;
}

void visit(BiTNode *node){
    cout<<node->data<<"->";
}
