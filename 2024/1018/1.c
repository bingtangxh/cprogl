#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAXSIZE 572

int isInArray(int current,int array[],int length)
{
    for(int i=0;i<length;i++)
    {
        if(current==array[i]) return 1;
    }
    return 0;
}

void printSet(int array[],short length)
{
    if(length>0)
    {
        putchar('{');
        for(int i=0;i<length;i++)
        {
            printf("%d",array[i]);
            if(i<length-1) putchar(',');
        }
        putchar('}');
    }
    else fputs("空集",stdout);    
    putchar('\n');
}

void resetSet(int array[],short length) {for(int i=0;i<length;i++) array[i]=0;}

void resetShortSet(short array[],short length) {for(int i=0;i<length;i++) array[i]=0;}

short char2num(char a)
{
    switch(a)
    {
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case '0': return 0;
        default: return -1;
    }
}

short num2BinaryArray(int a,short array[],int length)
{
    if(pow(2,length)<a) return -1;
    for(int i=0;i<length&&a>0;i++)
    {
        array[i]=a%2;
        a/=2;
    }
    return 0;
}

int main()
{
    int array1[MAXSIZE]={0},array2[MAXSIZE]={0},array3[MAXSIZE*2+1]={0},array4[MAXSIZE*2+1]={0},current;
    short length[5]={0},slt,isToBeTransfered[MAXSIZE];
    get2Sets:
    length[1]=0,length[2]=0;
    system("cls");
    puts("请输入第一个合集的所有元素");
    puts("只能是-2147438648~2147438647之间的值");
    printf("用空格、逗号或换行隔开，最多输入%d个，输入其他字符则转入下一个合集。\n",MAXSIZE);
    printf("如果一行就输入了超过%d个内容，则超出部分会被丢弃。\n",MAXSIZE);
    for(int i=0;i<MAXSIZE&&scanf("%d",&current);i++)
    {
        if(isInArray(current,array1,length[1])) 
        {
            i--;
            puts("您输入的这个元素已经存在，不能重复，请重新输入。");
            continue;
        }
        array1[i]=current;
        length[1]++;
        if(i==MAXSIZE-1) 
        {
            puts("已经不能再输入，任意键开始计算结果");
            getch();
        }
    }
    scanf("%*[^\n]");
    system("cls");
    puts("请输入第二个合集的所有元素");
    puts("只能是-2147438648~2147438647之间的值");
    printf("用空格、逗号或换行隔开，最多输入%d个，输入其他字符则转入下一个合集。\n",MAXSIZE);
    printf("如果一行就输入了超过%d个内容，则超出部分会被丢弃。\n",MAXSIZE);
    for(int i=0;i<MAXSIZE&&scanf("%d",&current);i++)
    {
        if(isInArray(current,array2,length[2])) 
        {
            i--;
            puts("您输入的这个元素已经存在，不能重复，请重新输入。");
            continue;
        }
        array2[i]=current;
        length[2]++;
        if(i==MAXSIZE-1) 
        {
            puts("已经不能再输入，任意键开始计算结果");
            getch();
        }
    }
    scanf("%*[^\n]");
    mainMenu:
    system("cls");
    puts("╔════════════════════════════════════╗");
    puts("║              集合的运算            ║");
    puts("╟─────────┬──────────────────────────╢");
    puts("║   [1]   │    计算并集              ║");
    puts("║   [2]   │    计算交集              ║");
    puts("║   [3]   │    计算差集(A-B)         ║");
    puts("║   [4]   │    计算差集(B-A)         ║");
    puts("║   [5]   │    计算对称差            ║");
    puts("║   [6]   │    计算补集（需输入全集）║");
    puts("║   [7]   │    计算幂集              ║");
    puts("║   [8]   │    重新输入两个集合      ║");
    puts("║   [0]   │    退出                  ║");
    puts("╚═════════╧══════════════════════════╝");
    putchar('\n');
    fputs("请输入您的选择：",stdout);
    slt=char2num(getche());
    putchar('\n');
    switch (slt)
    {
    case 1:
        puts("请稍候……");
        length[3]=0;
        for(int i=0;i<length[1];i++)
        {
            array3[i]=array1[i];
            length[3]++;
        }
        for(int i=0;i<length[2];i++)
        {
            if(isInArray(array2[i],array1,length[1])) continue;
            else array3[length[3]++]=array2[i];
        }
        system("cls");
        puts("以下是两个集合的并集：");
        printSet(array3,length[3]);
        puts("输出完毕，任意键回到菜单。");
        getch();
        goto mainMenu;
    
    case 2:
        puts("请稍候……");
        length[3]=0;
        for(int i=0;i<length[1];i++) if(isInArray(array1[i],array2,length[2])) array3[length[3]++]=array1[i];
        system("cls");
        puts("以下是两个集合的交集：");
        printSet(array3,length[3]);
        puts("输出完毕，任意键回到菜单。");
        getch();
        goto mainMenu;

    case 3:
        puts("请稍候……");
        length[3]=0;
        for(int i=0;i<length[1];i++) if(!isInArray(array1[i],array2,length[2])) array3[length[3]++]=array1[i];
        system("cls");
        puts("以下是差集A-B：");
        printSet(array3,length[3]);
        puts("输出完毕，任意键回到菜单。");
        getch();
        goto mainMenu;

    case 4:
        puts("请稍候……");
        length[3]=0;
        for(int i=0;i<length[2];i++) if(!isInArray(array2[i],array1,length[1])) array3[length[3]++]=array2[i];
        system("cls");
        puts("以下是差集B-A：");
        printSet(array3,length[3]);
        puts("输出完毕，任意键回到菜单。");
        getch();
        goto mainMenu;
        
    case 5:
        puts("请稍候……");
        length[3]=0;
        for(int i=0;i<length[1];i++) if(!isInArray(array1[i],array2,length[2])) array3[length[3]++]=array1[i];
        for(int i=0;i<length[2];i++) if(!isInArray(array2[i],array1,length[1])) array3[length[3]++]=array2[i];
        system("cls");
        puts("以下是对称差集的元素：");
        printSet(array3,length[3]);
        puts("输出完毕，任意键回到菜单。");
        getch();
        goto mainMenu;

    case 6:
        system("cls");
        length[4]=0;
        puts("请输入全集的所有元素");
        puts("只能是-2147438648~2147438647之间的值");
        printf("用空格、逗号或换行隔开，最多输入%d个，输入其他字符则开始计算结果。\n",MAXSIZE*2+1);
        printf("如果一行就输入了超过%d个内容，则超出部分会被丢弃。\n",MAXSIZE*2+1);
        for(int i=0;i<MAXSIZE*2+1&&scanf("%d",&current);i++)
        {
            if(isInArray(current,array4,length[4])) 
            {
                i--;
                puts("您输入的这个元素已经存在，不能重复，请重新输入。");
                continue;
            }
            array4[i]=current;
            length[4]++;
            if(i==MAXSIZE*2) 
            {
                puts("已经不能再输入，任意键开始计算结果");
                getch();
            }
        }
        scanf("%*[^\n]");
        system("cls");
        puts("请稍候……");
        length[3]=0;
        for(int i=0;i<length[4];i++) if(!isInArray(array4[i],array1,length[1])) array3[length[3]++]=array4[i];
        system("cls");
        puts("以下是集合A的补集：");
        printSet(array3,length[3]);
        puts("输出完毕，按任意键再查看集合B的补集……");
        getch();
        puts("请稍候……");
        length[3]=0;
        for(int i=0;i<length[4];i++) if(!isInArray(array4[i],array2,length[2])) array3[length[3]++]=array4[i];
        system("cls");
        puts("以下是集合B的补集：");
        printSet(array3,length[3]);
        puts("输出完毕，任意键回到菜单。");
        getch();
        goto mainMenu;

    case 7:
        system("cls");
        resetShortSet(isToBeTransfered,MAXSIZE);
        puts("以下是集合A的幂集：");
        puts("{");
        for(int i1=0;i1<(int)pow(2.0,(double)length[1]);i1++)
        {
            num2BinaryArray(i1,isToBeTransfered,MAXSIZE);
            length[3]=0;
            for(int i2=0;i2<length[1];i2++) if(isToBeTransfered[i2]) array3[length[3]++]=array1[i2];
            printSet(array3,length[3]);
            putchar(',');
        }
        putchar('\b');
        puts("}");
        resetShortSet(isToBeTransfered,MAXSIZE);
        puts("以下是集合B的幂集：");
        puts("{");
        for(int i1=0;i1<(int)pow(2.0,(double)length[2]);i1++)
        {
            num2BinaryArray(i1,isToBeTransfered,MAXSIZE);
            length[3]=0;
            for(int i2=0;i2<length[2];i2++) if(isToBeTransfered[i2]) array3[length[3]++]=array2[i2];
            printSet(array3,length[3]);
            putchar(',');
        }
        putchar('\b');
        puts("}");
        puts("输出完毕，任意键回到菜单。");
        getch();
        goto mainMenu;

    case 8:
        goto get2Sets;

    case 0:
        return 0;

    default:
        puts("您的输入有误，请重新输入。");
        getch();
        goto mainMenu;
    }
}