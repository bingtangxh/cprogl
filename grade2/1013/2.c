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

void migration(Linklist a,Linklist b,int i,int len,int j)
{
    Linklist a1=a,b1=b,a2,b2;
    for(int i1=0;i1<i;i++)
    {
        a1=a1->next;
    }
    a2=a1;
    for(int i1=0;i1<len;i++)
    {
        a2=a2->next;
    }
    for(int i1=0;i1<j;i++)
    {
        b1=b1->next;
    }
    b2=b1;
    b1->next=a1->next;
    a1->next=a2->next;
    a2->next=b2->next;
}