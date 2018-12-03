#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
typedef struct{
    char c;
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;
typedef char **huffmancode;
int min(HuffmanTree HT,int k)
{
    int i = 0;
    int min;        //用来存放weight最小且parent为0的元素的序号
    int min_weight; //用来存放weight最小且parent为0的元素的weight值
    
    //先将第一个parent为0的元素的weight值赋给min_weight,留作以后比较用。
    //注意，这里不能按照一般的做法，先直接将HT[0].weight赋给min_weight，
    //因为如果HT[0].weight的值比较小，那么在第一次构造二叉树时就会被选走，
    //而后续的每一轮选择最小权值构造二叉树的比较还是先用HT[0].weight的值来进行判断，
    //这样又会再次将其选走，从而产生逻辑上的错误。
    while(HT[i].parent != 0)
        i++;
    min_weight = HT[i].weight;
    min = i;
    
    //选出weight最小且parent为-1的元素，并将其序号赋给min
    for(;i<k;i++)
    {
        if(HT[i].weight<min_weight && HT[i].parent==0)
        {
            min_weight = HT[i].weight;
            min = i;
        }
    }
    
    //选出weight最小的元素后，将其parent置1，使得下一次比较时将其排除在外。
    HT[min].parent = 1;
    
    return min;
}
void select_minium(HuffmanTree HT,int k,int &min1,int &min2)
{
    min1 = min(HT,k);
    min2 = min(HT,k);
}HuffmanTree create_HuffmanTree(int wet[],int n)
{
    int i;
    int total = 2*n-1;
    HuffmanTree HT = (HuffmanTree)malloc(total*sizeof(HTNode));
    if(!HT)
    {
        printf("HuffmanTree malloc faild!");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].weight = wet[i];
        //wet++;
    }
    
    for(;i<total;i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
        HT[i].weight = 0;
    }
    int min1,min2; //用来保存每一轮选出的两个weight最小且parent为0的节点
    //每一轮比较后选择出min1和min2构成一课二叉树,最后构成一棵赫夫曼树
    for(i=n;i<total;i++)
    {
        select_minium(HT,i,min1,min2);
        HT[min1].parent = i;
        HT[min2].parent = i;
        //这里左孩子和右孩子可以反过来，构成的也是一棵赫夫曼树，只是所得的编码不同
        HT[i].lchild = min1;
        HT[i].rchild = min2;
        HT[i].weight =HT[min1].weight + HT[min2].weight;
    }
    for (i=0; i<total; i++) {
        printf("%d\t  %d\t  %d\t  %d\t \n",HT[i].parent,HT[i].lchild,HT[i].rchild,HT[i].weight);
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
void DispHuffman(huffmancode HC,HuffmanTree HT,int n)
{
    int i;
    for(i=0;i<n;i++)  //从零开始
    {
        printf("%c",HT[i].c);
        puts(HC[i]);
    }
}
int WPL(HuffmanTree HT,huffmancode HC,int n)
{
    int i;
    int num[1000];
    int wpl = 0;
    for(i=0;i<n;i++){
        num[i]=strlen(HC[i]);
    }
    for(i=0;i<n;i++)
    {
        num[i]=num[i]*HT[i].weight;
    }
    for(i=0;i<n;i++)
    {
        wpl=wpl+num[i];
    }
    printf("%d",wpl);
    return wpl;
}
int main(int argc, char const *argv[])
{
    printf("请输入叶子数量\n");
    int n;
    char zifu[9]="abcdefhi";
    scanf("%d",&n);
    printf("请输入%d位权重\n",n);
    int i;
    int wet[1000];
    float tmpwet[1000];
    for(i=0;i<n;i++)
    {
        printf("请输入第%d位元素:",i+1);
        scanf("%f",&tmpwet[i]);
        printf("\n");
        tmpwet[i]=tmpwet[i]*100;
        wet[i]=(int)tmpwet[i];
    }
    HuffmanTree HT = nullptr;
    huffmancode HC;
    HT=create_HuffmanTree(wet,n);
    for(i=0;i<n;i++)
    {
        HT[i].c=zifu[i];
    }
    Huffmancoding(HT,HC,n);
    DispHuffman(HC,HT,n);
    WPL(HT, HC, n);
    return 0;
}

