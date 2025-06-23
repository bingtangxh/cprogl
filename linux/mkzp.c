#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int i=0;
    pid_t pid=fork();
    if(pid==-1) return 0;
    else if(pid==0)
    {
        printf("My son's pid is %d\n",getpid());
        while(1)
        {
            printf("son---i=%d\n",i);
            i++;
            sleep(1);
            if(i==5) break;
        }
        puts("Son is over!");
    } else if (pid>0)
    {
        printf("Parent pid is %n",getpid());
    }
    return 0;
}