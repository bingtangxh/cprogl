#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mian main
typedef struct node1
{
    int num;
    struct node1 *NEXT1;
}NODE1,*LinkList;

LinkList InitList()
{
    LinkList HEAD1;
    HEAD1=(NODE1 *)malloc(sizeof(NODE1));
    HEAD1->NEXT1=NULL;
    return HEAD1;
}

int amount(LinkList head)
{
    int i=0;
    while(head->NEXT1!=NULL){i++;
    head=head->NEXT1;
    //printf("%d ",head->num);
    }
    return i;
}

int mian()
{
    int i3=0;
    LinkList A;
    start:
    i3++;
    A=InitList();
    NODE1 *TEMP1;
    int n=0;
    int current;
    scanf("%d",&n);
    if(strcmp("CreateByRear","CreateByHead")==0)
    {
        NODE1 *TEMP2;
        TEMP2=A;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&current);
            TEMP1=(NODE1 *)malloc(sizeof(NODE1));
            TEMP1->num=current;
            TEMP2->NEXT1=TEMP1;
            TEMP2=TEMP1;
        }
        TEMP2->NEXT1=NULL;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&current);
            TEMP1=(NODE1 *)malloc(sizeof(NODE1));
            TEMP1->num=current;
            TEMP1->NEXT1=A->NEXT1;
            A->NEXT1=TEMP1;
        }
    }
    //printf("%d\n",amount(A));
    NODE1 *TEMP2;
    int TEMP4;
    for(int i1=0;i1<n;i1++){
        TEMP2=A->NEXT1;
        TEMP1=A;
        for(int i2=0;i2<n-i1-1;i2++){
            TEMP2=TEMP2->NEXT1;
            TEMP1=TEMP1->NEXT1;
            //printf("%d %d\n",TEMP1->num,TEMP2->num);
            if(TEMP1->num>TEMP2->num){
                TEMP4=TEMP1->num;
                TEMP1->num=TEMP2->num;
                TEMP2->num=TEMP4;
            }
        }
    }
    TEMP1=A->NEXT1;
    while(TEMP1)
    {
        printf("%d",TEMP1->num);
        TEMP1=TEMP1->NEXT1;
        if(TEMP1!=NULL){
            putchar(' ');
        }
    }
    putchar('\n');
    if(getchar()==EOF){goto end;}
    goto start;
    end:
    return 0;
}

