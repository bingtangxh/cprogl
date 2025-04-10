#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int total_numbers(int year)
{
    int total_number=0;
    int total_number1;
    int n[4];
    n[0]=(year/1000)%10;
    n[1]=(year/100)%10;
    n[2]=(year/10)%10;
    n[3]=(year/1)%10;
    //printf("%d %d %d %d\n",n[0],n[1],n[2],n[3]);
    for(int i1=0;i1<4;i1++){
        total_number1=1;
        for(int i2=0;i2<i1;i2++){
            //printf("%d %d\n",i1,i2);
            if(n[i1]==n[i2]){total_number1=0;}
            }
        total_number+=total_number1;
        }
    //printf("%d\n",total_number);
    return total_number;
}

int main()
{
    int year,total_numbers_request,year_delta=0;
    scanf("%d %d",&year,&total_numbers_request);
    for(;total_numbers(year+year_delta)!=total_numbers_request;year_delta++)
    {
        //printf("%d %d\n",year_delta,year+year_delta);
    }
    printf("%d %04d\n",year_delta,year+year_delta);
    return 0;
}