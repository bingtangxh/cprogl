#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
    int data;
    struct NODE *NEXT; 
}node;
//'\n'-48=-38;
int main(){
    int T;
    char num;
    node *odd1,*even1,*odd2,*even2;
    scanf("%d",&T);
    getchar();
    for(int iT=0;iT<T;iT++){
        odd2=NULL;
        even1=(node *)malloc(sizeof(node));
        even1->NEXT=NULL;
        even2=even1;
        for(int i=1;1;i++){
            num=getchar();
            if(num=='\n'){break;}
            if(i%2==1){
                odd1=(node *)malloc(sizeof(node));
                odd1->data=(int) num-48;
                odd1->NEXT=odd2;
                odd2=odd1;
            }
            else{
                even2->data=(int) num-48;
                even2->NEXT=(node *)malloc(sizeof(node));
                even2=even2->NEXT;
            }
        }
        even2->NEXT=NULL;
        for(odd2=odd1;odd2!=NULL;odd2=odd2->NEXT){
            printf("%d",odd2->data);
            if(odd2->NEXT!=NULL){putchar(' ');}
        }
        putchar('\n');
        for(even2=even1;even2->NEXT!=NULL;even2=even2->NEXT){
            printf("%d",even2->data);
            if(even2->NEXT!=NULL){putchar(' ');}
        }
    }
    return 0;
}