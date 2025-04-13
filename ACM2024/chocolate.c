#include <stdio.h>

int main()
{
    int n,k,h[100000]={0},w[100000]={0},hmin=100001,wmin=100001,total=0,totalmax=0,lmax=1;
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%d %d",&h[i],&w[i]);
        if(h[i]<hmin) hmin=h[i];
        if(w[i]<wmin) wmin=w[i];
    }
    for(int l=1;l<=hmin&&l<=wmin;l++)
    {
        
        total=0;
        for(int i=0;i<n;i++)
        {
            total+=(h[i]/l)*(w[i]/l);
        }
        // printf("%d %d\n",l,total);
        if(total>=k) lmax=l;
    }
    printf("%d",lmax);
    return 0;
}