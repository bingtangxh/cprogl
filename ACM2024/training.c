#include <stdio.h>

int main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    int p[100001],c[100001],cmin=1000001;
    unsigned long long total=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&p[i],&c[i]);
        if(c[i]<cmin) cmin=c[i];
    }
    total+=s*cmin;
    for(int i=0;i<n;i++)
    {
        c[i]-=cmin;
        total+=(p[i]<s?p[i]:s)*c[i];
    }
    printf("%llu",total);
    return 0;

}