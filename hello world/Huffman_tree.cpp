#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
typedef struct{
    char c;
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char **huffmancode;
void select(HuffmanTree &HT, int n,int &s1,int &s2)
{   
    int i, j;   
    for(i = 1;i <= n;i++)       
        if(!HT[i].parent)            
        {            
            s1 = i;   
            break;
        }
    for(j = i+1;j <= n;j++)
        if(!HT[j].parent)
        {
            s2 = j;   
            break;
        }
    for(i = 1;i <= n;i++)
        if((HT[i].weight < HT[s1].weight) && (!HT[i].parent) && (s2 != i))
            s1 = i;
    for(j = 1;j <= n;j++)
        if((HT[j].weight < HT[s2].weight) && (!HT[j].parent) && (s1 != j))
            s2 = j;
    // 保证s1的weight比s2的小
    if(HT[s1].weight > HT[s2].weight)
    {
        int tmp = s1;   
        s1 = s2;
        s2 = tmp;
    }
}
HuffmanTree creatHuffmanTree(int *wet,int n)
{
    if(n<=1)
    printf("no need to creat Huffman tree!");
    int total = 2*n-1;
	HuffmanTree HT = (HuffmanTree)malloc(total*sizeof(HTNode));
	if(!HT)
	{
		printf("HuffmanTree malloc faild!");
		exit(-1);
	}
	int i;
    for(i=1;i<n;i++)
    {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
        HT[i].weight=wet[i];//没有使用wet[0]!
        wet++;
    }
    for(;i<=total;i++)
    {
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
        HT[i].weight=0;
    }
    int min1,min2; 
	for(i=n;i<total;i++)
	{
		select(HT,i,min1,min2);
		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight =HT[min1].weight + HT[min2].weight;
	}
	return HT;
}
void Huffmancoding(HuffmanTree HT,huffmancode &HC,int n)
{
    HC=(huffmancode)malloc((n+1)*sizeof(char*));
    char *cd;
    cd=(char*)malloc(n*sizeof(char));
    if(!cd)
	{
		printf("code malloc faild!");
		exit(-1);
	}
    cd[n-1]='\0';
    int i;
    int current;
    int father;
    int start;
    for(i=0;i<n;i++)
    {
        current = i;           
		father = HT[i].parent; 
		start = n-1;           
		while(father != 0)
		{
			if(HT[father].lchild == current)   //如果是左孩子，则编码为0
				cd[--start] = '0';    
			else                              //如果是右孩子，则编码为1       
				cd[--start] = '1';
			current = father;
			father = HT[father].parent;
		}
        HC[i]=(char*)malloc((n-start)*sizeof(char));  //有用到0
        strcpy(HC[i],cd+start);
    }
    
    free(cd);
}
void DispHuffman(huffmancode HC,int n)
{
    int i;
    for(i=0;i<n;i++)  //从零开始
	{
		puts(HC[i]);
	}
}
int main(int argc, char const *argv[])
{
    printf("请输入叶子数量\n");
    int n;
    char zifu[9]="abcdefhi";
    scanf("%d",&n);
    printf("请输入8位权重");
    int i,wet[9];
    float tmpwet[9];
    for(i=0;i<n;i++)
    {
        scanf("%f",&tmpwet[i]);
        tmpwet[i]=tmpwet[i]*100;
        wet[i]=(int)tmpwet[i];
    }
    HuffmanTree HT;
    huffmancode HC;
    creatHuffmanTree(wet,n);
    for(i=0;i<n;i++)
    {
        HT[i].c=zifu[i];
    }
    Huffmancoding(HT,HC,n);
    DispHuffman(HC,n);
    return 0;
}
