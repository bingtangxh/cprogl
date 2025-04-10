#include<stdio.h>
#include<stdlib.h>
int main(){
    //ж╩дцак╟к╥ж
    int N,K,i,a[1000];
    for(int i=0;i<1000;i++){a[i]=0;}
    scanf("%d",&N);
    for(int N1=0;N1<N;N1++){
        scanf("%d",&K);
        for(int K1=0;K1<K;K1++){
            scanf("%d",&i);
            a[i]++;
        }
    }
    int max=0;
    for(int i=0;i<1000;i++){if(max<=a[i])max=a[i];}
    //printf("%d\n",max);
    for(int i=1000;i>0;i--){
        if(max==a[i]){
            printf("%d %d",i,a[i]);
            break;
        }
    }
}