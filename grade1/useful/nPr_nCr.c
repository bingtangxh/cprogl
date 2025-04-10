#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define mian main
double combinations(char type,int n,int m)
{
    double combinations=1;
    for(int i=0;i<m;i++) {combinations*=(n-i);}
    switch(type)
    {
        case 'C':
        for(int i=0;i<m;i++) {combinations/=(i+1);}
        break;
        case 'A':
        case 'P':
        break;
        default:
        break;
    }
    return combinations;
}
int mian()
{
    int m,n;
    scanf("%d,%d",&m,&n);
    printf("%.0f",combinations('C',n,m));
}