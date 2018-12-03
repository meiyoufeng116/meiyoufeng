//
//  main.cpp
//  mat-1
//
//  Created by Mac on 2018/10/23.
//  Copyright © 2018年 Mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>
typedef struct a{
    int i;
    int j;
    int e;
}triple;
typedef   struct{
    triple data[10000+1];
    int mu,nu,tu;
}tsmat,TSMatrix;
int CreateSMatrix(TSMatrix *M)
{ /* 创建稀疏矩阵M */
    int i,m,n;
    int e;
    int k;
    printf("请输入矩阵的行数,列数,非零元素数：");
    scanf("%d,%d,%d",&(*M).mu,&(*M).nu,&(*M).tu);
    (*M).data[0].i=0; /* 为以下比较顺序做准备 */
    for(i=1;i<=(*M).tu;i++)
    {
        do
        {
            printf("请按行序顺序输入第%d个非零元素所在的行(1～%d),列(1～%d),元素值：",i,(*M).mu,(*M).nu);
            scanf("%d,%d,%d",&m,&n,&e);
            k=0;
            if(m<1||m>(*M).mu||n<1||n>(*M).nu) /* 行或列超出范围 */
                k=1;
            if(m<(*M).data[i-1].i||(m==(*M).data[i-1].i&&n<=(*M).data[i-1].j)) /* 行或列的顺序有错 */
                k=1;
        }while(k);
        (*M).data[i].i=m;
        (*M).data[i].j=n;
        (*M).data[i].e=e;
    }
    return 1;
}
int transposematrix(tsmat m,tsmat &t){
    int q,col,p;
    t.mu=m.nu;
    t.nu=m.mu;
    t.tu=m.tu;
    if (t.tu){
        q=1;
        for(col=1;col<=m.nu;++col){
            for (p=1; p<=m.tu; ++p) {
                if (m.data[p].j==col) {
                    t.data[q].i=m.data[p].j;t.data[q].j=m.data[p].i;
                    t.data[q].e=m.data[p].e;
                    ++q;
                }
            }
    }
}return 1;
}
void TransposeSMatrix_T(TSMatrix M, TSMatrix *T)
{
        int p, q, col;
        
        T->mu = M.nu;
        T->nu = M.mu;
        T->tu = M.tu;
        
        if(T->tu)
        {
            q = 1;                                    //q用于T中非零元计数
            for(col=1; col<=M.nu; ++col)            //col代表M的列，T的行
            {
                for(p=1; p<=M.tu; ++p)                //p用于M中非零元计数
                {
                    if(M.data[p].j==col)
                    {
                        T->data[q].i = M.data[p].j;    //M的列变为T的行
                        T->data[q].j = M.data[p].i;    //M的行变为T的列
                        T->data[q].e = M.data[p].e;    //每个三元组值不变
                        ++q;
                    }
                }
            }
        }
}
void FastTransposeSMatrix_T(TSMatrix M, TSMatrix *T)
    {
        int col, t, p, q;
        int num[100];                            //num[col]表示M第col列中非零元的个数
        int copt[100];                            //copt[col]表示M第col列第一个非零元在T->data中恰当的位置
        
        T->mu = M.nu;
        T->nu = M.mu;
        T->tu = M.tu;
        
        if(T->tu)
        {
            for(col=1; col<=M.nu; ++col)
                num[col] = 0;                    //初始化数组num
            
            for(t=1; t<=M.tu; ++t)                //t遍历M中三元组
                num[M.data[t].j]++;                //统计M中每列非零元个数
            
            copt[1] = 1;
            for(col=2; col<=M.nu; ++col)
                copt[col] = copt[col-1] + num[col-1];
            
            for(p=1; p<=M.tu; ++p)                //依次扫描M中的三元组
            {
                col = M.data[p].j;                //col为M中第p个三元组中元素的列
                q = copt[col];                    //q为当前三元组元素在T中应放置的位置
                T->data[q].i = M.data[p].j;
                T->data[q].j = M.data[p].i;
                T->data[q].e = M.data[p].e;
                ++copt[col];                    //再遇到此列元素时位置增一
            }
        }
    }
void PrintSMatrix_T(TSMatrix M)
{
    int r, c;
    int k = 1;
    
    for(r=1; r<=M.mu; r++)
    {
        for(c=1; c<=M.nu; c++)
        {
            if(r==M.data[k].i && c==M.data[k].j)
            {
                printf("%3d ", M.data[k].e);
                k++;
            }
            else
                printf("  0 ");
        }
        printf("\n");
    }
}
void PrintTriple(TSMatrix M)
{
    int i;
    for (i=0; i<=M.tu; i++) {
        printf("%3d%3d%3d\n",M.data[i].i,M.data[i].j,M.data[i].e);
    }
}
int main(int argc, const char * argv[]) {
    tsmat s,t;
    CreateSMatrix(&s);
    TransposeSMatrix_T(s,&t);
    PrintSMatrix_T(t);
    PrintTriple(s);
    return 0;
}
