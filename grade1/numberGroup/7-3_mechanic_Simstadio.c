#include<stdio.h>
#include<stdlib.h>
int main(){
    int N,M,Q,i1,i2,Ti,Ci,sum=0;
    scanf("%d%d%d",&N,&M,&Q);
    int aa[N+1][M+1];
    for(i1=1;i1<N+1;i1++){for(i2=1;i2<M+1;i2++){aa[i1][i2]=1;}}
    while(Q--){
        scanf("%d%d",&Ti,&Ci);
        if(Ti==0){for(i1=1;i1<M+1;i1++){aa[Ci][i1]=0;}}
        else{for(i1=0;i1<N+1;i1++){aa[i1][Ci]=0;}}    
    }
    for(i1=1;i1<N+1;i1++){for(i2=1;i2<M+1;i2++){if(aa[i1][i2]){sum++;}}}
    printf("%d",sum);
}