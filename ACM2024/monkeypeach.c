#include <stdio.h>

int peach(int day);

int main(void)
{
    int day;
    scanf("%d",&day);
    printf("%d",peach(day));
    return 0;
}

int peach(int day)
{
    if(day<=0) return -1;
    int peach_=1;
    day--;
    for (;day>0;day--)
    {
        peach_+=1;
        peach_*=2;
    }
    return peach_;
}