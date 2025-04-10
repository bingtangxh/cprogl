#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct NODE{
    int num;
    char name[10];
    int age;
    struct NODE *NEXT;
}node;
void display(node *HEAD)
{
    node *Source=HEAD->NEXT;
    while(Source!=NULL)
    {
        printf("%d %s %d\n",Source->num,Source->name,Source->age);
        Source=Source->NEXT;
    }
}
int main()
{
    node *new1,*new2,*newIns,*newInsPrev,*HEAD,*Dest,*deletingNode1,*deletingNode2;
    int T;
    while(scanf("%d",&T)!=1){continue;}
    for(int iT=0,Tnum,ins,del;iT<T;iT++)
    {
        while(scanf("%d",&Tnum)!=1){continue;}
        for(int iTnum=0;iTnum<Tnum;iTnum++)
        {
            new2=(node*)malloc(sizeof(node));
            while(scanf("%d %10s %d",&new2->num,&new2->name,&new2->age)!=3){continue;}
            if(iTnum==0){new2->NEXT=NULL;}
            else{new2->NEXT=new1;}
            new1=new2;
        }
        HEAD=(node*)malloc(sizeof(node));
        HEAD->NEXT=new2;
        display(HEAD);
        newIns=(node*)malloc(sizeof(node));
        while(scanf("%d %d %10s %d",&ins,&newIns->num,&newIns->name,&newIns->age)!=4){continue;}
        newInsPrev=HEAD;
        for(int iins=0;iins<ins;iins++){newInsPrev=newInsPrev->NEXT;}
        newIns->NEXT=newInsPrev->NEXT;
        newInsPrev->NEXT=newIns;
        display(HEAD);
        while(scanf("%d",&del)!=1){continue;}
        //putchar('~');
        Dest=HEAD;
        while(Dest->NEXT!=NULL)
        {
            //putchar('1');
            if(Dest->NEXT->num==del)
            {
                //putchar('~');
                deletingNode1=Dest->NEXT;
                Dest->NEXT=Dest->NEXT->NEXT;
                free(deletingNode1);
            }
            Dest=Dest->NEXT;
        }
        display(HEAD);
        if(iT<T-1){putchar('\n');}
        deletingNode1=HEAD;
        do
        {
            deletingNode2=deletingNode1->NEXT;
            free(deletingNode1);
            deletingNode1=deletingNode2;
        }while(deletingNode2!=NULL);
    }
    return 0;
}