#include <stdio.h>
#include <conio.h>
int Search(int a[],int n,int k){
    int i=0;
    for (i=1;i<=n;i++){
        if (a[i]==k) break;
    }
    if (i==n+1) return 0;
    else return i;
}
int main()
{
    int a[50],n,i,k;
    scanf("%d",&n);  //接收数组元素个数
    for(i=1;i<=n;i++)   //依次接收各个元素的值
        scanf("%d",&a[i]);
    scanf("%d",&k);      // 接收待查元素值k
    int x=Search(a,n,k);  
    if(x==0)
        printf("NONE\n");
    else
        printf("%d\n",x);
    _getch();
    return 0;
}

/* 请在这里填写答案 */