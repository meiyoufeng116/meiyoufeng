//
//  main.cpp
//  二叉树的递归
//
//  Created by Mac on 2018/10/27.
//  Copyright © 2018年 Mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    char data;
    struct tree *Lchild;
    struct tree *Rchild;
}tree,*Btree;
Btree creat_tree()
{
    Btree A=(Btree)malloc(sizeof(Btree));
    Btree B=(Btree)malloc(sizeof(Btree));
    Btree C=(Btree)malloc(sizeof(Btree));
    Btree D=(Btree)malloc(sizeof(Btree));
    Btree E=(Btree)malloc(sizeof(Btree));
    A->data='A';
    B->data='B';
    C->data='C';
    D->data='D';
    E->data='E';
    A->Lchild=B;
    A->Rchild=C;
    B->Lchild=D;
    B->Rchild=E;
    C->Lchild=C->Rchild=NULL;
    D->Lchild=D->Rchild=NULL;
    E->Lchild=E->Rchild=NULL;
    return A;
}
void pre_traverse(Btree pTree)
{
    if(pTree)
    {
        printf("%c ",pTree->data);
        if(pTree->Lchild)
            pre_traverse(pTree->Lchild);
        if(pTree->Rchild)
            pre_traverse(pTree->Rchild);
    }
}
void in_traverse(Btree pTree)
{
    if(pTree)
    {
        if(pTree->Lchild)
            in_traverse(pTree->Lchild);
        printf("%c ",pTree->data);
        if(pTree->Rchild)
            in_traverse(pTree->Rchild);
    }
}
void beh_traverse(Btree pTree)
{
    if(pTree)
    {
        if(pTree->Lchild)
            beh_traverse(pTree->Lchild);
        if(pTree->Rchild)
            beh_traverse(pTree->Rchild);
        printf("%c ",pTree->data);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Btree A;
    A=creat_tree();
    printf("前序遍历结果:");
    pre_traverse(A);
    printf("\n");
    printf("中序遍历结果:");
    in_traverse(A);
    printf("\n");
    printf("后序遍历结果:");
    beh_traverse(A);
    return 0;
}
