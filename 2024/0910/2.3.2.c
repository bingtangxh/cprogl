#include <stdio.h>
#include <stdlib.h>
#define mian main

typedef struct node1
{
    int factor;
    int index;
    struct node1 *next;
} NODE1,*LinkList;



int mian()
{
    int n1;
    scanf("%d\n",&n1);
    LinkList HEAD1=(NODE1*) malloc(sizeof(NODE1));
    HEAD1->next=NULL;
    NODE1 *TEMP1,*TEMP2=HEAD1,*TEMP3,*TEMP4,*TEMP5,current;
    for (int i3=0;i3<n1;i3++)
    {
        current.next=NULL;
        if (1)       
        //尾插法                                                           
        {
            scanf("(%d,%d)",&(current.factor),&(current.index));
            TEMP1=(NODE1*) malloc(sizeof(NODE1));
            TEMP1->factor=(current.factor);
            TEMP1->index=(current.index);
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
    
    for (int i1=0;i1<n1;i1++)
    {
        TEMP2=HEAD1->next;
        TEMP1=HEAD1;
        for (int i2=0;i2<n1-i1-1;i2++)
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

    int n2;
    scanf("%d\n",&n2);
    LinkList HEAD2=(NODE1*) malloc(sizeof(NODE1));
    HEAD2->next=NULL;
    //NODE1 *TEMP1,*TEMP2=HEAD2,current;
    TEMP2=HEAD2;
    for (int i3=0;i3<n2;i3++)
    {
        current.next=NULL;
        if (1)       
        //尾插法                                                           
        {
            scanf("(%d,%d)",&(current.factor),&(current.index));
            TEMP1=(NODE1*) malloc(sizeof(NODE1));
            TEMP1->factor=(current.factor);
            TEMP1->index=(current.index);
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
            TEMP1->next=HEAD2->next;
            HEAD2->next=TEMP1;
        }
        // printf("%d\n",amount(A));
    }
    
    for (int i1=0;i1<n2;i1++)
    {
        TEMP2=HEAD2->next;
        TEMP1=HEAD2;
        for (int i2=0;i2<n2-i1-1;i2++)
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
    TEMP1=HEAD2->next;

    int n3=0;
    LinkList HEAD3=(NODE1*) malloc(sizeof(NODE1));
    HEAD3->next=NULL;
    TEMP1=HEAD1;
    TEMP2=HEAD2;
    TEMP3=HEAD3;
    NODE1* alreadyExists=NULL;
    while(1){
        if(TEMP1->next!=NULL)
        {
            TEMP1=TEMP1->next;
            TEMP5=HEAD3;
            alreadyExists=NULL;
            do{
                if(TEMP1->index==TEMP5->index){
                    alreadyExists=TEMP5;
                }
                TEMP5=TEMP5->next;
            }while(TEMP5!=NULL);
            if(alreadyExists){
                (alreadyExists->factor)+=TEMP1->factor;
            }
            else {
                n3++;
                TEMP3=TEMP3->next=(NODE1*) malloc(sizeof(NODE1));
                TEMP3->next=NULL;
                TEMP3->factor=TEMP1->factor;
                TEMP3->index=TEMP1->index;
            }
        }

        if(TEMP2->next!=NULL)
        {
            TEMP2=TEMP2->next;
            TEMP5=HEAD3;
            alreadyExists=NULL;
            do{
                if(TEMP2->index==TEMP5->index){
                    alreadyExists=TEMP5;
                }
                TEMP5=TEMP5->next;
            }while(TEMP5!=NULL);
            if(alreadyExists){
                (alreadyExists->factor)+=TEMP2->factor;
            }
            else {
                n3++;
                TEMP3=TEMP3->next=(NODE1*) malloc(sizeof(NODE1));
                TEMP3->next=NULL;
                TEMP3->factor=TEMP2->factor;
                TEMP3->index=TEMP2->index;
            }
        }
        if((TEMP1->next==NULL)&&(TEMP2->next==NULL)) break;
    }
    TEMP3=HEAD3->next;
    for (int i1=0;i1<n3;i1++)
    {
        TEMP2=HEAD3->next;
        TEMP1=HEAD3;
        for (int i2=0;i2<n3-i1-1;i2++)
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



    while (1)
    {
        if(TEMP3==NULL) break;
        if(TEMP3->index==0) TEMP3->factor=0;
        else {
            (TEMP3->factor)*=TEMP3->index;
            TEMP3->index--;
        }
        if(TEMP3->factor!=0){
            if(TEMP3->factor!=1) printf("%d",TEMP3->factor);
            if(TEMP3->index!=0) {
                if(TEMP3->index==1) putchar('X');
                else printf("X^%d",TEMP3->index);
            }
            if(TEMP3->factor==1&&TEMP3->index==0) putchar('1');
        }
        TEMP4=TEMP3;
        TEMP3=TEMP3->next;
        if (TEMP3!=NULL)
        {
            if(TEMP3->factor>0&&TEMP4->factor!=0) putchar('+');
            //else putchar('-');
        }
    }

    return 0;

}
