#include<stdio.h>
#include<string.h>
#define mian main
char delchar(char *s,char ch){
    int i,a,b;
    for(i=0;i<strlen(s);i++){if(s[i]!=ch){printf("%c",s[i]);}}}
int mian(){
    char a[80],b;
    scanf("%c",&b);
    gets(a);
    delchar(a,b);
    return 0;
}