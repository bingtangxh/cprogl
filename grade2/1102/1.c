#include <stdio.h>
#define MAXSIZE 15
/*这个main函数就是算法，需要用户在stdin中输入这个二维数组的边长和数据*/
int main()
{
    int square[MAXSIZE][MAXSIZE]={0},M,N,min[MAXSIZE]={0},max[MAXSIZE]={0},minc=2147438647,maxc=-2147438648,amount=0,lenc=0;
    char result[1145],*resultc;
    resultc=result;
    scanf("%d %d\n",&M,&N);
    for(int iM=0;iM<M;iM++)
    {
        for(int iN=0;iN<N;iN++)
        {
            scanf("%d",&square[iM][iN]);
            getchar();
        }
    }
    for(int iM=0;iM<M;iM++,minc=2147438647)
    {
        for(int iN=0;iN<N;iN++)
        {
            if(minc>square[iM][iN])
            {
                minc=square[iM][iN];
                min[iM]=square[iM][iN];
            }
        }
    }
    for(int iN=0;iN<N;iN++,maxc=-2147438648)
    {
        for(int iM=0;iM<M;iM++)
        {
            if(maxc<square[iM][iN])
            {
                maxc=square[iM][iN];
                max[iN]=square[iM][iN];
            }
        }
    }
    for(int iM=0;iM<M;iM++)
    {
        for(int iN=0;iN<N;iN++)
        {
            if(square[iM][iN]==min[iM]&&square[iM][iN]==max[iN]){
                amount++;
                lenc=sprintf(resultc,"(%d,%d,%d)",iM+1,iN+1,square[iM][iN]);
                resultc+=lenc;
            }
        }
    }
    if(amount==0)puts("NONE");
    else puts(result);
    return 0;
}