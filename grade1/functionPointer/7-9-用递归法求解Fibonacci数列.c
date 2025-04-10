#include<stdio.h>
#include<math.h>
#define mian main
int Fibonacci(int x){
    if(x==0||x==1) return x;
    else return (Fibonacci(x-1)+Fibonacci(x-2));
}
int mian(){
    int n;
    scanf("%d",&n);
    if(!(1<=n&&n<=50)){printf("Wrong Input!");}
    else{printf("F(%d)=%d",n,Fibonacci(n));}
}