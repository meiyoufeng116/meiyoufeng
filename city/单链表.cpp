#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct LNode{
	char data1[100];
	int data2;
	struct LNode *next;
}LNode,*LinkList;
void Print(LinkList a);
void CreateList_L(LinkList &L,int n) {
	//顺位输入n个元素的值，建立单链表L
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;           //建立一个链表
	int i;
	LinkList p,q;
	for(i=1;i<=n;i++){
		p=(LinkList)malloc(sizeof(LNode));
		printf("\n请输入城市名称:");
		scanf("%s",&p->data1);
		getchar();
		printf("请输入城市人口：");
		scanf("%d",&p->data2);
		p->next=L->next;
		L->next=p;
	}
}
int TjZrkList_L(LinkList &L)
{
    //统计所有城市人口
    int a=0;
    LinkList p=L->next;
    /*for(a=0;;){
        a=p->data2+a;
        p=p->next;
        if(p->next==NULL)break;}*/
        while(p){
           a=p->data2+a;
           p=p->next;
           // printf("%d\n",a);
        }
        return a;
}
int CsRkList_L(LinkList L)
{//输入一个城市名，输出城市人口
    char a[100];
    int b;
    LinkList p;
    //p=L->next;
    //Print(p);
    printf("%d",p->data2);
    printf("请输入城市名称:");
    scanf("%s",&a[100]);
    getchar();
    p=L->next;
    /*for(;;){
        if(strcmp(p->data1,a))
            {
                b=p->data2;printf("%d",b);break;
            }
        //printf("1");
        else{p=p->next;}
        //printf("%d",b);
        if(p->next==NULL){printf("EORROR");}

    }*/
    while(p->next!=NULL)
    {
        if(strcmp(p->data1,a))
            {
                b=p->data2;
                printf("%d",b);
            }
            p=p->next;
    }
    printf("该城市人口为%d\n",b);
    return b;
}
void ListInsert_L(LinkList &L){
//新增一个城市
    LinkList s;
    char a;
    int b;
    s=(LinkList)malloc(sizeof(LNode));
    printf("请输入新增城市名:");
    scanf("%s",&s->data1);
    getchar();
    printf("请输入新增城市人口:");
    scanf("%d",&s->data2);
    getchar();
    s->next=L->next;
    s=L->next;
    /*while(L->next!=NULL)
    {
        printf("城市名:%s ",L->data1);
        printf("城市人口:%d\n",L->data2);
    }*/
}
void ListDelete_L(LinkList &L){
     char a[100];
     printf("请输入删除城市名:");
     scanf("%s",&a);
     LinkList p,s;
     p=L;
     getchar();
     for(;;){
        if(strcmp(p->next->data1,a)){p->next=p->next->next;break;}
        p=p->next;
     }
     }
void Print(LinkList list)
{
    LinkList a,b;
    a = list;
    while(a != NULL)
    {
        printf("%s\n", a->data1) ;
        printf("%d\n",a->data2);
        b = a;
        a = a->next;
        free(b);
    }
}
int main()
{
    int a,b;
    printf("请输入将要输入的城市数量：");
    scanf("%d",&a);
    LinkList L;
    CreateList_L(L,a);
    b=TjZrkList_L(L);//printf("1");
    printf("总人口为%d\n",b);
    CsRkList_L(L);
    ListInsert_L(L);
    ListDelete_L(L);
    system("pause");
}
