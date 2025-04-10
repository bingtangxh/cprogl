#include<stdio.h>
int main(){
    int N;
    scanf("%d",&N);
    int a[10];
    int sum=0;
    //int i;
    for(int N1=0;N1<N;N1++){scanf("%d",&a[N1]);}
    for(int N1=0;N1<N;N1++){for(int N2=0;N2<N;N2++){
        if(N1!=N2){
        //i=a[N1]*10+a[N2];
        //printf("%d\n",i);
        sum+=(a[N1]*10+a[N2]);
    }}}
    printf("%d\n",sum);
}