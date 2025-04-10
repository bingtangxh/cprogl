#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 114514
#define elemType int

typedef struct seqList{
    elemType data[MAXSIZE];
    int rear;
}
SeqList;

typedef struct node{
    elemType data;
    struct node * next;
       
}
Node,*Linklist;

Linklist reverseSeqList2Linklist(SeqList s)
{
    Linklist head=(Linklist) malloc(sizeof(Node));
    if (head==NULL) return NULL;
    Linklist current=head->next;
    for(int i=s.rear;i>=0;i--)
    {
        current=(Linklist) malloc(sizeof(Node));
        current->data=s.data[i];
        current->next=NULL;
        current=current->next;
    }
    return head;
}

void reverseSeqList(SeqList *s)
{
    int exchangeLimit=s->rear/2;
    elemType temp;
    if(exchangeLimit%2==1) exchangeLimit--;
    for(int i=0;i<exchangeLimit;i++)
    {
        temp=s->data[i];
        s->data[i]=s->data[s->rear-i];
        s->data[s->rear-i]=temp;
    }
}