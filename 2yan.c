#include <stdio.h>
#include <conio.h>
#include <string.h>
int main(void){
    char a[50]="2GRAVEHUIGAS 2YAN\0";
    for(int i=0;i<strlen(a);i++){
        printf("%c",a[i]);
        putchar(' ');
        putchar(' ');
    }
    putchar('\n');
    for(int i=0;i<strlen(a);i++){
        printf("%d",(short) a[i]+2);
        putchar(' ');
    }
    
}