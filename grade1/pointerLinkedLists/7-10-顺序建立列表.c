#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define mian main
int mian(){
    int N;
    scanf("%d",&N);
    int nums[1000];
    for(int i=0;i<N;i++){
        scanf("%d",&nums[i]);
        printf("%d",nums[i]);
        if(i<N-1){putchar(' ');}
    }
    return 0;
}