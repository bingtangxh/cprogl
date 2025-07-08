#include <stdio.h>

int main(void)
{
    int x[5001]={0},y[5001]={0},n=0,s=0,a=0,b=0,apple_available=0;
    scanf("%d %d\n%d %d",&n,&s,&a,&b);
    if(n==0)
    {
        puts("0");
        return 0;   
    }
    //printf("%d-%d-%d-%d",n,s,a,b);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    // printf("%d %d",x[1],y[1]);
    
    for(int i=n;i>0;i--)
    {
        for(int i1=0;i1<i;i1++)
        {
            //printf("%d",i1);
            if(y[i1]>y[i1+1])
            {
                x[i1]+=x[i1+1];
                x[i1+1]=x[i1]-x[i1+1];
                x[i1]-=x[i1+1];
                y[i1]+=y[i1+1];
                y[i1+1]=y[i1]-y[i1+1];
                y[i1]-=y[i1+1];

            }
        }
        //putchar('\n');
    }

    // for(int i=0;i<n;i++)
    // {
    //     //printf("%d %d\n",x[i],y[i]);
    // }
    for(int i=0;i<n;i++)
    {
        if(x[i]>a+b) continue;
        s-=y[i];
        apple_available++;
        if(s<0)
        {
            s+=y[i];
            apple_available--;
            continue;
        }
    }
    apple_available--;
    //putchar('\n');
    printf("%d",apple_available);
    
    
    
    
    
    
    
    
    
    return 0;
}