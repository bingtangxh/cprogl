#include<stdio.h>
int isprime(int a) {
    //printf("\n%d\n",a);
    int i1,isprime_result=1;
    if(a>2) for(i1=2;i1<a;i1++)
    {
        //printf("%d ",i1);
        if(a%i1==0)
        {
            isprime_result=0;
            break;
        }
    }
    else if(a==2) isprime_result=1;
    else if(a==1) isprime_result=0; 
    return isprime_result;
}

int main()
{
    int T,n,sum=0;
    scanf("%d",&T);
    for(;T>0;T--,sum=0)
    {
        scanf("%d",&n);
        for(int i1=2;i1<=n/2;i1++) if(isprime(i1)&&isprime(n-i1)) sum++;
        printf("%d\n",sum);
    }
}