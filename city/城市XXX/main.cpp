//
//  main.cpp
//  城市XXX
//
//  Created by Mac on 2018/10/30.
//  Copyright © 2018年 Mac. All rights reserved.
//

#include <iostream>
#include <string.h>
typedef struct Node
{
    int num;
    char name[100];
    struct Node *pNext;
}NODE,*PNODE;
PNODE create_list()
{
    int val=0;
    char name[100];
    PNODE pHead =(PNODE)malloc(sizeof(NODE));
    PNODE pCurrent = pHead;
    pCurrent->pNext = NULL;
    if(NULL == pHead)
    {
        printf("pHead malloc failed!");
        exit(-1);
    }
    printf("Input first data(q to quit):");
    while(1)
    {
        scanf("%d",&val);
        if(val==0)
            break;
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        scanf("%s",name);
        if(NULL == pNew)
        {
            printf("pNew malloc failed!");
            exit(-1);
        }
        pNew->num = val;
        strcpy(pNew->name,name);
        pCurrent->pNext = pNew;
        pNew->pNext = NULL;
        pCurrent = pNew;
        printf("Input next data(q to quit):");
    }
    
    return pHead;
}
bool insert_list(PNODE pHead,int pos,int val,char name[])
{
    int i = 0;
    PNODE p = pHead;
    
    //i为0时，p指向第0个节点（这里指没有实际数据的头节点，不计入链表节点总数），
    //i为1时，p指向第1个节点，i为几，p就指向第几个节点
    while(p!=NULL && i<pos)
    {
        p = p->pNext;
        i++;
    }
    
    //当pos的值大于链表长度时，便会出现这种情况
    if(i>pos || p==NULL)
        return false;
    
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(NULL == pNew)
    {
        printf("pNew malloc failed!");
        exit(-1);
    }
    pNew->num = val;
    strcpy(pNew->name,name);
    pNew->pNext = p->pNext;
    p->pNext = pNew;
    
    return true;
}
bool delete_list(PNODE pHead,int pos,int *pData,char name[])
{
    int i = 0;
    PNODE p = pHead;
    
    //p最终指向第pos个节点前面的节点
    //如果下面两句分别改为while(p!=NULL && i<pos)和if(i>pos || p==NULL)，则p最终指向第pos个节点，
    //这样因为得不到第pos个节点前面的那个节点，因此无法将pos前后两个节点连结起来
    while(p->pNext!=NULL && i<pos-1)
    {
        p = p->pNext;
        i++;
    }
    
    //当pos的值大于链表长度时，便会出现这种情况
    if(i>pos-1 || p->pNext==NULL)
        return false;
    
    PNODE q = p->pNext;
    *pData = q->num;
    strcpy(name, q->name);
    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;
    return true;
}
void traverse_list(PNODE pHead)
{
    PNODE pCurrent = pHead->pNext;
    printf("now dataes in the list are:\n");
    while(pCurrent != NULL)
    {
        printf("%d ",pCurrent->num);
        puts(pCurrent->name);
        pCurrent = pCurrent->pNext;
    }
    printf("\n");
    return ;
}
void find_people(PNODE pHead)
{
    printf("请输入查询人口的城市名");
    char c[100];
    fflush(stdin);
    //gets(c, 100, stdin);
    scanf("%s",c);
    PNODE pCurrent = pHead->pNext;
//    printf("now dataes in the list are:\n");
    while(pCurrent != NULL)
    {
        if (!strcmp(pCurrent->name,c)) {
            printf("城市的人口为%d",pCurrent->num);
        }
//        printf("%d ",pCurrent->num);
//        puts(pCurrent->name);
        pCurrent = pCurrent->pNext;
    }
    printf("\n");
    return ;
}
void sum_people(PNODE pHead)
{
    int a=0;
    PNODE pCurrent = pHead->pNext;
    //printf("城市人口总和\n");
    while(pCurrent != NULL)
    {
        //printf("%d ",pCurrent->num);
        a+=pCurrent->num;
        pCurrent = pCurrent->pNext;
    }
    printf("城市人口总和为:%d\n",a);
    printf("\n");
    return ;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!"<<std::endl;
    PNODE a;
    a=create_list();
    traverse_list(a);
    sum_people(a);
    //printf("请输入查询人口的城市名");
    //scanf("%s",c);
    system("pause");
    find_people(a);
    return 0;
}
