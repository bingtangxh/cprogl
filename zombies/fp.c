#include<stdio.h>
#include<stdlib.h>
#define mian main
int main(int argc,char *argv[])
{
    FILE* fp;
    char sentences[200];
    fp=fopen("0110.txt","w");
    while (fgets(sentences,10,stdin)!=NULL&&sentences[0]!='\n'){
        fprintf(fp,"%s",sentences);
    }
    for(long i=0;i<1919810;i++){putchar('\a');}
    return 0;
}