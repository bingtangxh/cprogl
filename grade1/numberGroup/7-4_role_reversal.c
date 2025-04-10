#include<stdio.h>
#include<stdlib.h>
void Swap(int *x,int *y)
{
    int Swap1=*x;
    *x=*y;
    *y=Swap1;
}
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
    Swap(&x,&y);
    printf("%d %d",x,y);
    return 0;
}