#include<stdio.h>
#include<string.h>
#define MAXSIZE 114514

int isCharNum(char a){
    switch (a)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return 1;
    default:
        return 0;
    }
}

int char2Num(char a){
    switch (a)
    {
        case '0':
        return 0;
        case '1':
        return 1;
        case '2':
        return 2;
        case '3':
        return 3;
        case '4':
        return 4;
        case '5':
        return 5;
        case '6':
        return 6;
        case '7':
        return 7;
        case '8':
        return 8;
        case '9':
        return 9;
        default:
        return -1;
    }
}

int itsPriority(char a){
    switch(a)
    {
        case '*':
        case '/':
        return 2;
        case '+':
        case '-':
        return 1;
        case '#':
        return 0;
        default:
        return -1;
    }
}

int calc1Step(int a,char opType,int b){
    switch(opType)
    {
        case '+':
        return a+b;
        case '-':
        return a-b;
        case '*':
        return a*b;
        case '/':
        return a/b;
        case '#':
        default:
        return 2147483647;
    }
}

typedef struct stack1{
    int elem[MAXSIZE];
    int top;
} Stack1;

typedef struct stack2{
    char elem[MAXSIZE];
    int top;
} Stack2;


int main()
{
    char expression[114514],current;
    fgets(expression,114514,stdin);
    Stack1 numStc;
    Stack2 opStc;
    //将数字栈和运算栈都初始化
    for(int i=0;i<MAXSIZE;i++) {
        numStc.elem[i]=0;
        opStc.elem[i]=-1;
    }
    numStc.top=-1;
    opStc.top=-1;
    unsigned short currentNum=0,pushRqd=0;
    int temp1=0,temp2=0;
    //printf("%d",strlen(expression));
    //遍历一遍字符串
    for(int i=0;i<strlen(expression)-1;i++) {
        //current是当前处理的字符
        current=expression[i];
        if(isCharNum(current)) {
        //如果当前处理的字符是一个数字
            if(currentNum==0) {currentNum=char2Num(current);} else {
                //将现在的数值乘10并加上新的数字
                currentNum*=10;
                currentNum+=char2Num(current);
            }
            pushRqd=1;
        } else {
            //如果当前处理的字符不是一个数字
            if(pushRqd) {
                numStc.top++;
                numStc.elem[numStc.top]=currentNum;
                currentNum=0;
                pushRqd=0;
            } else i=i;
            if(itsPriority(current)>itsPriority(opStc.elem[opStc.top])) {
                //如果现在处理的运算优先级高，那么先入栈
                i=i;
                opStc.top++;
                opStc.elem[opStc.top]=current;
            } else {
                temp1=numStc.elem[numStc.top];
                numStc.top--;
                temp2=numStc.elem[numStc.top];

                numStc.elem[numStc.top]=calc1Step(temp2,opStc.elem[opStc.top--],temp1);

                if(current=='#'&&opStc.top==-1) break;
                //如果是运算并且现在处理的优先级低，就应该先把上一个算出来并把结果放进数栈，然后重新处理这个运算符，所以i--
                else {
                    i--;
                    continue;
                }
            }
        }
    }
    fprintf(stdout,"%d",numStc.elem[numStc.top]);
    return 0;
}