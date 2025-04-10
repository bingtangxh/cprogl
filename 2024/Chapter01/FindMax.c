#include <conio.h>
#include <stdio.h>
void FindMax(int a[],int n,int *pmax1,int *pmax2){
    for (int i1=1;i1<=n-1;i1++){
        for (int i2=1;i2<=n-i1;i2++){
            if (a[i2]<a[i2+1]){
                a[i2]+=a[i2+1];
                a[i2+1]=a[i2]-a[i2+1];
                a[i2]-=a[i2+1];
            }
        }
    }
    *pmax1=a[1];
    *pmax2=a[2];
}
int main()
{
    int a[50],n,i;
    int max1,max2;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    FindMax(a,n,&max1,&max2);
    printf("%d %d\n",max1,max2);
    _getch();
    return 0;
}
