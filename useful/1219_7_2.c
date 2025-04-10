#include<stdio.h>
#include<stdlib.h>
#define mian main
 
typedef struct node {
    int num;
    struct node *NEXT;
}NODE1;

NODE1 *init(NODE1 *head){
    head=(NODE1 *)malloc(sizeof(NODE1));
    head->NEXT=NULL;
    return head;
}

NODE1 *fill(NODE1 *head,int n)
{
    NODE1 *TEMP1,*DC;
    DC=head;
    int current;
    for(int i=0;i<n;i++) {
        TEMP1=(NODE1*)malloc(sizeof(NODE1));
        scanf("%d",&current);
        TEMP1->num=current;
        DC->NEXT=TEMP1;
        DC=TEMP1;
    }
    DC->NEXT=NULL;
    return head;
}
//SC是SourceCurrent，原来的链表里当前NODE1。
//DC是DestinationCurrent。
int display(NODE1 *head)
{
    NODE1 *SC=head->NEXT;
    while(SC!=NULL){
        printf("%d",SC->num);
        if (SC->NEXT!=NULL)
            putchar(' ');
        SC=SC->NEXT;
    }
    putchar('\n');
    return 0;
}

 
void move(NODE1 *head,NODE1 *head1,NODE1 *head2)
{
    NODE1 *SC,*DC1,*DC2,*temp;
    SC=head->NEXT;
    DC1=head1;
    DC2=head2;
    while(SC){
        temp=(NODE1 *)malloc(sizeof(NODE1));
        temp->num=SC->num;
        if(SC->num<0){
            DC1->NEXT=temp;
            DC1=temp;
        }
        else{
            DC2->NEXT=temp;
            DC2=temp;
        }
        SC=SC->NEXT;
    }
    DC1->NEXT=NULL;
    DC2->NEXT=NULL;
}

int mian()
{
    int T;
    NODE1 *head,*head1,*head2;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        head=init(head);
        head1=init(head1);
        head2=init(head2);
        int n;
        scanf("%d",&n);
        fill(head,n);
        //把新创建的链表填满
        move(head,head1,head2);
        //printf("%d",head1->num);
        display(head1);
        display(head2);
    }
    //scanf("%d",T);
    return 0;
}