#include <stdio.h>
#include <string.h>
char *welcome()
{
    static char name[13];
    //也可以用malloc实现退出函数后字符串还在
    strcpy(name,"Deng Kairong");
    //也可以用sprintf
    return name;
}
int main(void)
{
    char *a=welcome();
    printf("Hi, i believe %s can be succeed!\n ",a);
    return 0;
}
