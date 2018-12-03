#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -2
#define OK 0

void  inittriplet(int *&p)
{
        p=(int*)malloc(3*sizeof(int));
        if(!p) exit(1);
        printf("请输入要输入的三个数：");
       scanf("%d%d%d",&p[0],&p[1],&p[2]);
}
void max(int a[3],int *k)
{
    if(a[0]>a[1])
        ;
    else a[0]=a[1];
    if(a[0]>a[2])
        ;
    else{ a[0]=a[2];}
    *k=a[0];
}
int destorytriplet(int *p)
{
       free(p);
       return 0;
}
 int  Average(int a[3])
{
        int d;
        d=(a[0]+a[1]+a[2])/3;
        return d;
}
void isdescending(int a[])
{   int x,y,z;
    if(a[0]<a[1])
       {
        x=a[0];
        a[0]=a[1];
        a[1]=x;}
     if(a[0]<a[2])
        {y=a[0];
        a[0]=a[2];
        a[2]=y;}
    if(a[1]<a[2])
      { z=a[1];
        a[1]=a[2];
        a[2]=z;}
}
main()
{
        int *k;
        inittriplet(k);
        int l,d;
        d=Average(k);
        isdescending(k);
        max(k,&l);
        printf("三个数中的最大值是:%d\n",l);
        printf("平均数:%d\n",d);
        printf("降序排序：%d,%d,%d",k[0],k[1],k[2]);
}
