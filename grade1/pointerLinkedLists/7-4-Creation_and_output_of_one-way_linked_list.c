#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int data;
    struct link *next;
}*Link;

Link AppendNode(Link head,int data){
    printf("Appended\n");
    head=(Link *)malloc(sizeof(Link));
    head->data=data;
    head->next=NULL;
    return (head->next);
}
void DisplyNode(Link head){
    if(head==NULL){puts("NULL");}
    else{
        for(int i=0;head!=NULL;i++){
            if(i>0) {putchar(',');}
            printf("%d",head->data);
            head=head->next;
        }
    }
}

int main()
{
    int data;
    Link head=NULL;
    while(1)
    {
        scanf("%d",&data);
        if (data==-1) break;
        head=AppendNode(head,data);
    }
    DisplyNode(head);
    return 0;
}

