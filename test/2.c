#include <stdio.h>
int main(int argc,char* argv[])
{
    int i,to,*fp,sum=0;
    to=atoi(argv[1]);
    for(i=1;i<=to;i++)
    {
        sum+=i;
        fprintf(fp,"%d",sum);
    }
    return 0;
}