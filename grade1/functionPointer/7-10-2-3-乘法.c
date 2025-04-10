#include<stdio.h>
#include<math.h>
#define mian main
int mian(){
    long int n,m;
    int i,times=0;
    scanf("%ld %ld",&n,&m);
    if(m%n!=0){printf("-1");}
    else{
        i=m/n;
        if(i%2!=0&&i%3!=0){printf("-1");}
        else{
            do{
                
                if(i%3==0){i/=3;times++;}
                if(i%2==0){i/=2;times++;}
            }while(!(i%2!=0&&i%3!=0));
            printf("%d",times);
        }
    }
}