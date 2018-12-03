//
//  Index.cpp
//  debug1
//
//  Created by Mac on 2018/10/9.
//  Copyright © 2018�? Mac. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSTRLEN 100                               //�ַ����100

typedef char SString[MAXSTRLEN+1];                  /* 0�ŵ�Ԫ��Ŵ��ĳ��� */

  int Index(SString S,SString T,int pos)            //bp�㷨
  { 
   int i,j;
   if(1<=pos&&pos<=S[0])                            //�ж�����λ���Ƿ����
   {
     i=pos;
     j=1;
     while(i<=S[0]&&j<=T[0])                        //i,j�ĳ���С�������ַ����ĳ���
       if(S[i]==T[j])                               /* �����ȽϺ���ַ��������ȣ�i��j�����һ�� */
       {
         ++i;                       
         ++j;
       }
       else                                         /* ָ��������¿�ʼƥ�� */
       {
         i=i-j+2;                                   //ƥ�䲻��ȷ��j�ص�1��i��һλ
         j=1;
       }
     if(j>T[0])                                     //ƥ����ȫ
       return i-T[0];                               //���ص�һ��ƥ�䵽��λ��
     else
       return 0;
   }
   else
     return 0;
 }

 int StrInsert(SString S,int pos,SString T)          //�����ַ�����������s���е�pos���ַ�֮ǰ����t��
 { 
   int i;
   if(pos<1||pos>S[0]+1)                             //�ж�����posλ���Ƿ�Ϸ�
     return -1;
   if(S[0]+T[0]<=MAXSTRLEN)                          //�ж�s����t������û��Խ��
   { /* ��ȫ���� */
     for(i=S[0];i>=pos;i--)                          //��s������Ҫ�滻λ�õ��ַ������T������
       S[i+T[0]]=S[i];
     for(i=pos;i<pos+T[0];i++)                       //��s���пճ�����λ���滻��t�� 
       S[i]=T[i-pos+1];
     S[0]=S[0]+T[0];
     return 1;
   }
   else
   { /* ���ֲ��� */
     for(i=MAXSTRLEN;i<=pos;i--)                     //����pos+t�����ȵ�λ������ƣ��ճ��ռ��t��
       S[i]=S[i-T[0]];
     for(i=pos;i<pos+T[0];i++)                       //���ճ���λ�ø�t������
       S[i]=T[i-pos+1];
     S[0]=MAXSTRLEN;
     return 0;
   }
 }
 int StrDelete(SString S,int pos,int len)
 { /* ��ʼ����: ��S����,1��pos��StrLength(S)-len+1 */
   /* �������: �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ� */
   int i;
   if(pos<1||pos>S[0]-len+1||len<0)
     return -1;
   for(i=pos+len;i<=S[0];i++)
     S[i-len]=S[i];
   S[0]-=len;
   return 1;
 }
int Replace(SString S,SString T,SString V)
 { /* ��ʼ����: ��S,T��V����,T�Ƿǿմ����˺����봮�Ĵ洢�ṹ�޹أ� */
   /* �������: ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ� */
   int i=1; /* �Ӵ�S�ĵ�һ���ַ�����Ҵ�T */
   if(!T) /* T�ǿմ� */
     return -1;
   do
   {
     i=Index(S,T,i); /* ���iΪ����һ��i֮���ҵ����Ӵ�T��λ�� */
     if(i) /* ��S�д��ڴ�T */
     {
       StrDelete(S,i,T[0]); /* ɾ���ô�T */
       StrInsert(S,i,V); /* ��ԭ��T��λ�ò��봮V */
       i+=V[0]; /* �ڲ���Ĵ�V����������Ҵ�T */
     }
   }while(i);
   return 1;
 }


int StrAssign(SString T,char *chars)
 { /* ����һ����ֵ����chars�Ĵ�T */
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
 { /* ����ַ���T����� */
   int i;
   for(i=1;i<=T[0];i++)
     printf("%c",T[i]);
   printf("\n");
 }

int main()
{
    SString a,b,c;
    char e[101],f[101],g[101];
    printf("������Դ�ַ���");
    scanf("%s",e);
    printf("������ģʽ��");
    scanf("%s",f);
    printf("�������滻��");
    scanf("%s",g);
    StrAssign(a,e);
    StrAssign(b,f);
    StrAssign(c,g);
    Replace(a,b,c);
    StrPrint(a);
    system("pause");
}

