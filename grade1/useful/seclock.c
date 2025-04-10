#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
struct clock
{
    int hours;
    int minutes;
    int seconds;
};

int display(struct clock t)
{
    printf("\r%02d:",t.hours);
    printf("%02d:",t.minutes);
    printf("%02d",t.seconds);
    return 0;
}

struct clock update(struct clock t)
{
    t.seconds++;
    if(t.seconds==60)
    {
        t.seconds=0;
        t.minutes++;
    }
    //else t=t;
    if(t.minutes==60)
    {
        t.minutes=0;
        t.hours++;
    }
    //else t=t;
    Sleep(1000);
    return t;
}

int main()
{
    struct clock cl={0,0,0};
    char ch;
    //printf("请按\"s\"开始，按\"e\"结束");
    display(cl);
    ch=getch();
    while(1)
    {
        if(ch=='s'||ch=='S')
        {
            cl=update(cl);
            display(cl);
            if(kbhit())
            {
                ch=getch();
                if(ch=='e'||ch=='E') break;
            }
        }
        else if(ch=='e'||ch=='E') break;
        else ch=getch();
    }
    printf("\n");
    return 0;
}