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
	//˳λ����n��Ԫ�ص�ֵ������������L
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;           //����һ������
	int i;
	LinkList p,q;
	for(i=1;i<=n;i++){
		p=(LinkList)malloc(sizeof(LNode));
		printf("\n�������������:");
		scanf("%s",&p->data1);
		getchar();
		printf("����������˿ڣ�");
		scanf("%d",&p->data2);
		p->next=L->next;
		L->next=p;
	}
}
int TjZrkList_L(LinkList &L)
{
    //ͳ�����г����˿�
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
{//����һ������������������˿�
    char a[100];
    int b;
    LinkList p;
    //p=L->next;
    //Print(p);
    printf("%d",p->data2);
    printf("�������������:");
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
    printf("�ó����˿�Ϊ%d\n",b);
    return b;
}
void ListInsert_L(LinkList &L){
//����һ������
    LinkList s;
    char a;
    int b;
    s=(LinkList)malloc(sizeof(LNode));
    printf("����������������:");
    scanf("%s",&s->data1);
    getchar();
    printf("���������������˿�:");
    scanf("%d",&s->data2);
    getchar();
    s->next=L->next;
    s=L->next;
    /*while(L->next!=NULL)
    {
        printf("������:%s ",L->data1);
        printf("�����˿�:%d\n",L->data2);
    }*/
}
void ListDelete_L(LinkList &L){
     char a[100];
     printf("������ɾ��������:");
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
    printf("�����뽫Ҫ����ĳ���������");
    scanf("%d",&a);
    LinkList L;
    CreateList_L(L,a);
    b=TjZrkList_L(L);//printf("1");
    printf("���˿�Ϊ%d\n",b);
    CsRkList_L(L);
    ListInsert_L(L);
    ListDelete_L(L);
    system("pause");
}
