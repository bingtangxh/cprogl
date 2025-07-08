#include <stdio.h>

int main(void)
{
    unsigned int storage[100];
    int current=0;
    while(1)
    {
        scanf("%u",&storage[current++]);
        if(storage[current-1]==0)
        {
            current-=2;
            break;
        }
        else
        {
            continue;
        }
    }
    while(1)
    {
        printf("%u",storage[current--]);
        putchar(' ');
        if(current==-1) break;
    }
    return 0;
}