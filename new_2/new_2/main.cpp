//
//  Index.cpp
//  debug1
//
//  Created by Mac on 2018/10/9.
//  Copyright © 2018年 Mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int Index(char s[],char t[],int pos)
{
    int i,j,g,k;
    i=pos;
    j=0;
    g=strlen(s);
    k=strlen(t);
    while (i<=g&&j<=k) {
        if (s[i]==t[j]) {
            ++i;++j;
        } else {
            i=i-j+2;
            j=1;
        }
    }
    if (j>k) {
        return i-k;
    }
    else return 0;
}
void Repstr1(char s[],int i,int j,char t[])
{
    int a;
    for (a=i; a<=j+i; a++) {
        s[a]=t[a];
    }
    
}
void Repstr2(char s[],char t[],char i[])
{
    int a,b;
    a=Index(s,t,0);
    b=strlen(t);
    Repstr1(s, a, b, i);
}
int main()
{
    char a[100],b[100],c[100];
    printf("请输入源字符串");
    scanf("%s",a);
    printf("请输入替换字符串");
    scanf("%s",b);
    printf("请输入插入字符串");
    scanf("%s",c);
    Repstr2(a,b,c);
    puts(a);
}

