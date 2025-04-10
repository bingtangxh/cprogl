#include <stdio.h>
#include <math.h>

// 6;
// 20;
// 31415926535;
// 2006628868244228;

unsigned long long umaMusume(unsigned long long a);

int isUma(unsigned long long a);

int main(void)
{
    unsigned long long a;
    scanf("%llu",&a);
    for (unsigned long long a_temp=a;a_temp<=a;a_temp++)
    {
        printf("%llu",umaMusume(a_temp));
        putchar('\t');
    }

    return 0;
}

unsigned long long umaMusume(unsigned long long a)
{
    if(a<=0) return 0;
    a--;
    short five[19]={0};
    unsigned long long uma=0;

    for (short index=18;index>=0;)
    {
        // printf("%llu ",a);
        if((unsigned long long)pow(5.0,(double)index)>a)
        {
            index--;
            continue;
        }
        else
        {
            a-=(unsigned long long)pow(5.0,(double)index);
            five[index]++;
            continue;
        }
    }
    // putchar('\n');
    for (short current=18;current>=0;current--)
    {
        // printf("%d ",five[current]);
    }


    
    for (short current=0;current<=18;current++)
    {
        uma+=five[current]*2*(unsigned long long)pow(10.0,(double)current);
    }



    



    return uma;
    

    while (a && 0)
    {
        
        a--;
        uma+=2;
        if(uma%10==0)
        {
            if(isUma(uma))
            {
                continue;
            }
            else
            {
                for(unsigned long long delta=10;1;delta*=10)
                {
                    uma+=delta;
                    if(isUma(uma))
                    {
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
    }
    putchar('\n');
    return uma;
}

int isUma(unsigned long long a)
{
    while(a!=0)
    {
        if(a%2==0)
        {
            a/=10;
            continue;
        }
        else 
        {
            return 0;
        }
    }
    return 1;
}