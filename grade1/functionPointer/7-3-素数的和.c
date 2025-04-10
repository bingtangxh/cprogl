#include<stdio.h>
#include<math.h>
int isprime(int a) {
    //printf("\n\n%d\n",a);
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
    int input,sum=0;
    do{
        scanf("%d",&input);
        if(isprime(input)){sum+=input;}
    }while(input!=1);
    printf("%d",sum);
    return 0;
}