#include<stdio.h>
#include<stdlib.h>
int main(){
    //别看这个，会超时
    int M,N;
    scanf("%d %d",&M,&N);
    char a[20][20];
    for(int M1=0;M1<M;M++)
    {
        for(int N1=0;N1<N;N++)
        {
            scanf("\n%c",&a[M1][N1]);}}
    int k,x,y;
    scanf("%d",&k);
    //int shootDead[400];
    //for(int k1=0;k1<k;k1++){
        //shootDead[k1]=0;
    //}
    for(int k1=0;k1<k;k1++){
        int kill=0;
        scanf("%d %d",&x,&y);
        for(int i1=0;i1<M;i1++){
            for(int i2=0;i2<N;i2++){
                if(i1==x&&i2==y){
            //这个复合语句是射击
            kill=0;
            if(a[i1][i2]!='I'){a[i1][i2]!='I';kill++;}
            if(i1>=1){if(a[i1-1][i2]='H'){a[i1-1][i2]='I';kill++;}};
            if(i1<M-1){if(a[i1+1][i2]='H'){a[i1+1][i2]='I';kill++;}};
            if(i2>=1){if(a[i1][i2-1]='H'){a[i1][i2-1]='I';kill++;}};
            if(i2<N-1){if(a[i1][i2+1]='H'){a[i1][i2+1]='I';kill++;}};
            if(i1>=1){if(a[i1-1][i2]='#'){a[i1-1][i2]='H';}};
            if(i1<M-1){if(a[i1+1][i2]='#'){a[i1+1][i2]='H';}};
            if(i2>=1){if(a[i1][i2-1]='#'){a[i1][i2-1]='H';}};
            if(i2<N-1){if(a[i1][i2+1]='#'){a[i1][i2+1]='H';}};
            printf("%d\n",kill);
            }}}}
    return 0;
}