#include <stdio.h>
#include <string.h>
static int choice(void)//网上查了下函数或者函数外的变量名定义加static就只有当前文件能用
{
    puts("[Retry,Abort,Exit]?");
    int i;
    static char selection='R';
    //如果上面这个不用static，那么每次selection都会全新初始化成R。
    //用了static，那么第一次是R，往后这个语句不再生效，但是selection也不会被销毁。
    //如果是指针变量用static，那么指针变量指向的数值不被销毁，地址仍然会被销毁。
    switch(selection)
    {
        case 'R':
        case 'r':
        puts("I will try again.");
        i=1;
        break;
        case 'A':
        case 'a':
        puts("Well, you told me to ignore them.");
        i=2;
        break;
        case 'E':
        case 'e':
        puts("Never gonna see you again!");
        i=3;
        break;
        default:
        i=4;
        break;
    }
    switch(selection)
    {
        case 'R':
        case 'r':
        selection='A';
        break;
        case 'A':
        case 'a':
        selection='E';
        break;
        case 'E':
        case 'e':
        break;
        default:
        break;
    }
    return i;
}

int main()
{
    char selection='a';
    char i[12];
    sprintf(i,"EOTDFTR");
    puts("Now i will try to access a non-exist object.");
    for(int i=0;i<3;i++){choice();}
    putchar(selection);
    printf("\n%s\n",i);

    return 0;
}