#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sort(int *q,int N){
    int i1,i2,temp;
    for(i1=0;i1<N-1;i1++){
        for(i2=0;i2<N-1-i1;i2++){
            if(*(q+i2)>=*(q+i2+1)){
                temp=*(q+i2);
                *(q+i2)=*(q+i2+1);
                *(q+i2+1)=temp;
            }
        }
    }
}
 
int main(){
    int M,N,nums[100][100],i1,i2;
    scanf("%d %d",&M,&N);
    for(i1=0;i1<M;i1++){
        for(i2=0;i2<N;i2++){
            scanf("%d",&nums[i1][i2]);
            }
        }
    for(i1=0;i1<M;i1++){sort(nums[i1],N);}
    for(i1=0;i1<M;i1++){
        for(i2=0;i2<N;i2++){
            printf("%d", nums[i1][i2]);
            if(i2==N-1){printf("\n");}
            else{printf(" ");}
        }
    }
    return 0;
}
