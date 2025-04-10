#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int greatestCommonDivisor(int a,int b)
{
    int GCD=1;
    for(int i=2,i1=0;1;i++,i1++)
    {
        if(a%i==0&&b%i==0)
        {
            a/=i;
            b/=i;
            GCD*=i;
            i=1;
        }
        else
        {
            if(i>a||i>b)
            {
                i=1;
                break;
            }
        }
        if(0)
        {
            break;
        } 
    }
    return GCD;
}
int leastCommonMultiple(int a,int b)
{
    int LCM=1;
    for(int i=2,i1=0;1;i++,i1++)
    {
        if(a%i==0&&b%i==0)
        {
            a/=i;
            b/=i;
            LCM*=i;
            i=1;
        }
        else
        {
            if(i>a||i>b)
            {
                i=1;
                break;
            }
        }
        if(0)
        {
            break;
        }
    }
    LCM*=a;
    LCM*=b;
    return LCM;
}
int main()
{
    int a,b,lessThanZero;
    scanf("%d,%d",&a,&b);
    if(a*b<0)
    {
        a=abs(a);
        b=abs(b);
        lessThanZero=1;
    }
    else lessThanZero=0;
    //printf("%d\n",lessThanZero);
    int GCD1=greatestCommonDivisor(a,b);
    int LCM1=leastCommonMultiple(a,b);
    //printf("%d\n",lessThanZero);
    if(lessThanZero==1)
    {
        LCM1*=-1;
        //printf("%d\n",lessThanZero);
    }
    printf("%d,%d",GCD1,LCM1);
}