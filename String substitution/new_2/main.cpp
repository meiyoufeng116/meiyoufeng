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
void get_nextval(SString T,int nextval[])          //求模式串T的next函数修正值并存入数组nextval
 { 
   int i=1,j=0;
   nextval[1]=0;                                  //初始化
   while(i<T[0])                                  //匹配没有完成时
     if(j==0||T[i]==T[j])                         //如果j等于0或者大家相等，i,j都向后移动一位
     {
       ++i;
       ++j;
       if(T[i]!=T[j])                             //如果移动后不相等，找到了一个i位置上的nextval的数值
	 nextval[i]=j;
       else
	 nextval[i]=nextval[j];                         //如果移动后相等，nextval上的位置就是j的位置上的值
     }
     else                                         //直接回到上一个符合位置开始找，从而避免了一个个找，提高了效率
       j=nextval[j];
 }

 int Index_KMP(SString S,SString T,int pos,int next[])      /* 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法。 */
 { 
   int i=pos,j=1;
   while(i<=S[0]&&j<=T[0])
     if(j==0||S[i]==T[j])                             /* 继续比较后继字符 */
     {
       ++i;
       ++j;
     }
     else                                             /* 模式串向右移动 */
       j=next[j];
   if(j>T[0])                                         /* 匹配成功 */
     return i-T[0];
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
 int StrDelete(SString S,int pos,int len)            //从串S中删除第pos个字符起长度为len的子串
 { 
   int i;
   if(pos<1||pos>S[0]-len+1||len<0)									 //判断pos输入是否合理
     return -1;
   for(i=pos+len;i<=S[0];i++)												 //将删除位数后的主串向前复写
     S[i-len]=S[i];
   S[0]-=len;
   return 1;
 }
int Replace(SString S,SString T,SString V)					//用V替换主串S中出现的所有与T相等的不重叠的子串
 { 
   int i=1; 																				/* 从串S的第一个字符起查找串T,这是鉴于该串特殊的存储结构导致的，如果从0开始会很严重 */
   if(!T)                                           /* T是空串 */
     return -1;
   do
   {
     i=Index(S,T,i); 																/* 结果i为从上一个i之后找到的子串T的位置 */
     if(i) 																					/* 串S中存在串T */
     {
       StrDelete(S,i,T[0]); 												/* 删除该串T */
       StrInsert(S,i,V); 														/* 在原串T的位置插入串V */
       i+=V[0]; 																		/* 在插入的串V后面继续查找串T */
     }
   }while(i);
   return 1;
 }


int StrAssign(SString T,char *chars)
 { 																									/* 生成一个其值等于chars的串T，由于字符串的第一位需要放它的长度 */
   int i;
   if(strlen(chars)>MAXSTRLEN)											/* 输入字符串超长 */
     return 0;
   else
   {
     T[0]=strlen(chars);														// 给字符串的第一个地址赋上字符串的长度
     for(i=1;i<=T[0];i++)
       T[i]=*(chars+i-1);														// 将输入字符串数组赋给存储
     return 1;
   }
 }
 void StrPrint(SString T)
 { 																									/* 输出字符串T。另加 */
   int i;
   for(i=1;i<=T[0];i++)
     printf("%c",T[i]);
   printf("\n");
 }

int main()
{
    SString a,b,c;
    char e[101],f[101],g[101];
    printf("please input main strings");
    scanf("%s",e);
    printf("please input key strings");
    scanf("%s",f);
    printf("please input sub strings");
    scanf("%s",g);
    StrAssign(a,e);
    StrAssign(b,f);
    StrAssign(c,g);
    Replace(a,b,c);
    StrPrint(a);
    system("pause");
}

