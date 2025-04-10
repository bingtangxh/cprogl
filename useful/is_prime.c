#include<stdio.h>
int isprime(int a) {
    //printf("\n\n%d\n",a);
    int i1,isprime_result=1;
    if(a>2) for(i1=2;i1<a;i1++)
    {
        //printf("%d ",i1);
        if(a%i1==0)
        {
            isprime_result=0;
            break;
        }
    }
    else if(a==2) isprime_result=1;
    else if(a==1) isprime_result=0; 
    return isprime_result;
}

int bubble_sort(int array[],int length) {
    int i,j,temp;
    for(i=0;i<length-1;i++)
        for(j=0;j<length-1-i;j++)
            if(array[j]>array[j+1]) {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
}
int main() {
    int i,ip,ip1,array[10];
    int array_prime[10];
    for(i=0;i<10;i++) scanf("%d,",&array[i]);
    ip=0;
    for(i=0;i<10;i++) {
        if(isprime(array[i])==1) {
            array_prime[ip]=array[i];
            //printf("%d",array[i]);
            ip++;
        }
    }
    if(ip==0) printf("Not found!");
    else {
        bubble_sort(array_prime,ip);
        for(ip1=0;ip1<ip;ip1++) {
            printf("%d",array_prime[ip1]);
            if(ip1!=ip-1) printf(",");
        }
    }
    //printf("\n%d",isprime(91));
    return 0;
}