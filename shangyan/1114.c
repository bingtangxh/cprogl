#include <stdio.h>
#include <stdlib.h>
#define ElemType char
#define MAXSIZE 114514                           
typedef struct stack{
    ElemType d[MAXSIZE];
    int top;
} Stack,*S;

void cover(char exp[]){
    int type;
    for(int i=0;exp[i]!='\0';i++){
        if('0'<=exp[i]&&exp[i]<='9'){
            type=-1;
        }else if(exp[i]=='*'||exp[i]=='/'){
            type=2;
        }else if(exp[i]=='+'||exp[i]=='-'){
            type=1;
        }else if(exp[i]=='\n'||exp[i]=='\0'){
            return;
        }
        switch(type){
            case -1:{
                break;
            }
            case 2:
            {
                break;
            }
            case 1:
            {
                break;
            }
            default:
            {
                break;
            }
        }
        
    }
    return;
}

int push(S s,ElemType d){
    if(s->top>=MAXSIZE-1){

    }
}

int pop(S s,ElemType *d){

}

int top(S s,ElemType *d){

}

int main(void){
    printf("%d %d",'0','9');
    return 0;
}