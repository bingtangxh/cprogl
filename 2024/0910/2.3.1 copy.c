#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define mian main

typedef struct node1
{
    int factor;
    int index;
    struct node1 *next;
} NODE1,*LinkList;

int amount(LinkList head)
{
    int i=0;
    while (head->next!=NULL)
    {
        i++;
        head=head->next;
        // printf("%d ",head->index);
    }
    return i;
}

int mian()
{
    int n;
    scanf("%d\n",&n);
    LinkList HEAD1=(NODE1*) malloc(sizeof(NODE1));
    HEAD1->next=NULL;
    NODE1 *TEMP1,*TEMP2=HEAD1,current;
    for (int i3=0;i3<n;i3++)
    {
        current.next=NULL;
        if (1)       
        //尾插法                                                           
        {
            scanf("(%d,%d)",&(current.factor),&(current.index));
            TEMP1=(NODE1*) malloc(sizeof(NODE1));
            if(0) TEMP1->factor=TEMP1->index=0;
            else
            {
                TEMP1->factor=(current.factor);
                TEMP1->index=(current.index);
            }
            TEMP2->next=TEMP1;
            TEMP2=TEMP1;
            TEMP2->next=NULL;
        }
        else
        //头插法
        {
            scanf("(%d,%d)",&current.factor,&current.index);
            TEMP1=(NODE1*) malloc(sizeof(NODE1));
            TEMP1->factor=current.factor;
            TEMP1->index=current.index;
            TEMP1->next=HEAD1->next;
            HEAD1->next=TEMP1;
        }
        // printf("%d\n",amount(A));
    }
    
    for (int i1=0;i1<n;i1++)
    {
        TEMP2=HEAD1->next;
        TEMP1=HEAD1;
        for (int i2=0;i2<n-i1-1;i2++)
        {
            TEMP2=TEMP2->next;
            TEMP1=TEMP1->next;
            // printf("%d %d\n",TEMP1->index,TEMP2->index);
            if (TEMP1->index>TEMP2->index)
            {
                (TEMP1->factor)+=TEMP2->factor;
                TEMP2->factor=TEMP1->factor-TEMP2->factor;
                (TEMP1->factor)-=TEMP2->factor;

                (TEMP1->index)+=TEMP2->index;
                TEMP2->index=TEMP1->index-TEMP2->index;
                (TEMP1->index)-=TEMP2->index;
                
            }
        }
    }
    TEMP1=HEAD1->next;
    long result=0;
    int x;
    scanf("%d",&x);
    while (TEMP1)
    {
        result+=(TEMP1->factor)*(int)pow((double)x,(double)(TEMP1->index));
        TEMP1=TEMP1->next;
    }
    printf("%ld",result);
    return 0;
    //肯定得return啊，要不然的话就相当于void了

}