#include<stdio.h>
float max(float d1,float d2,float d3)
{
    float max=0;
    if(max<d1) max=d1;
    if(max<d2) max=d2;
    if(max<d3) max=d3;
    return max;
}

int main()
{
    int N;
    float max1[114514];
    float max2=0;
    int max3;
    scanf("%d",&N);
    float d1,d2,d3;
    for(int i=0;i<N;i++)
    {
        scanf("%f %f %f",&d1,&d2,&d3);
        max1[i]=max(d1,d2,d3);
        //printf("%.2f\n",max(d1,d2,d3));
    }
    for(int i=0;i<N;i++)
    {
        //printf("%.2f\n",max1[i]);
        if(max2<max1[i])
        {
            max2=max1[i];
            max3=i;
        }
    }
    max3+=1;
    printf("%d %.2f",max3,max2);
}