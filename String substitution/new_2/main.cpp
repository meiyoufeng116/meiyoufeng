//
//  Index.cpp
//  debug1
//
//  Created by Mac on 2018/10/9.
//  Copyright 漏 2018骞? Mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSTRLEN 100                               //字符串最长100

typedef char SString[MAXSTRLEN+1];                  /* 0号单元存放串的长度 */

  int Index(SString S,SString T,int pos)            //bp算法
  { 
   int i,j;
   if(1<=pos&&pos<=S[0])                            //判断输入位置是否合理
   {
     i=pos;
     j=1;
     while(i<=S[0]&&j<=T[0])                        //i,j的长度小于两个字符串的长度
       if(S[i]==T[j])                               /* 继续比较后继字符，如果相等，i，j向后走一格 */
       {
         ++i;                       
         ++j;
       }
       else                                         /* 指针后退重新开始匹配 */
       {
         i=i-j+2;                                   //匹配不正确，j回到1，i退一位
         j=1;
       }
     if(j>T[0])                                     //匹配完全
       return i-T[0];                               //返回第一个匹配到的位置
     else
       return 0;
   }
   else
     return 0;
 }

 int StrInsert(SString S,int pos,SString T)          //插入字符串函数，从s串中的pos个字符之前插入t串
 { 
   int i;
   if(pos<1||pos>S[0]+1)                             //判断输入pos位置是否合法
     return -1;
   if(S[0]+T[0]<=MAXSTRLEN)                          //判断s串和t串长度没有越界
   { /* 完全插入 */
     for(i=S[0];i>=pos;i--)                          //将s串中需要替换位置的字符向后移T串长度
       S[i+T[0]]=S[i];
     for(i=pos;i<pos+T[0];i++)                       //将s串中空出来的位置替换成t串 
       S[i]=T[i-pos+1];
     S[0]=S[0]+T[0];
     return 1;
   }
   else
   { /* 部分插入 */
     for(i=MAXSTRLEN;i<=pos;i--)                     //将从pos+t串长度的位置向后移，空出空间给t串
       S[i]=S[i-T[0]];
     for(i=pos;i<pos+T[0];i++)                       //将空出的位置给t串放上
       S[i]=T[i-pos+1];
     S[0]=MAXSTRLEN;
     return 0;
   }
 }
 int StrDelete(SString S,int pos,int len)
 { /* 初始条件: 串S存在,1≤pos≤StrLength(S)-len+1 */
   /* 操作结果: 从串S中删除第pos个字符起长度为len的子串 */
   int i;
   if(pos<1||pos>S[0]-len+1||len<0)
     return -1;
   for(i=pos+len;i<=S[0];i++)
     S[i-len]=S[i];
   S[0]-=len;
   return 1;
 }
int Replace(SString S,SString T,SString V)
 { /* 初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关） */
   /* 操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串 */
   int i=1; /* 从串S的第一个字符起查找串T */
   if(!T) /* T是空串 */
     return -1;
   do
   {
     i=Index(S,T,i); /* 结果i为从上一个i之后找到的子串T的位置 */
     if(i) /* 串S中存在串T */
     {
       StrDelete(S,i,T[0]); /* 删除该串T */
       StrInsert(S,i,V); /* 在原串T的位置插入串V */
       i+=V[0]; /* 在插入的串V后面继续查找串T */
     }
   }while(i);
   return 1;
 }


int StrAssign(SString T,char *chars)
 { /* 生成一个其值等于chars的串T */
   int i;
   if(strlen(chars)>MAXSTRLEN)
     return 0;
   else
   {
     T[0]=strlen(chars);
     for(i=1;i<=T[0];i++)
       T[i]=*(chars+i-1);
     return 1;
   }
 }
 void StrPrint(SString T)
 { /* 输出字符串T。另加 */
   int i;
   for(i=1;i<=T[0];i++)
     printf("%c",T[i]);
   printf("\n");
 }

int main()
{
    SString a,b,c;
    char e[101],f[101],g[101];
    printf("请输入源字符串");
    scanf("%s",e);
    printf("请输入模式串");
    scanf("%s",f);
    printf("请输入替换串");
    scanf("%s",g);
    StrAssign(a,e);
    StrAssign(b,f);
    StrAssign(c,g);
    Replace(a,b,c);
    StrPrint(a);
    system("pause");
}

