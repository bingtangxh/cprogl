#include<stdio.h>
#include<math.h>
int main(){
    int n0,n1,n;
    scanf("%d %d %d",&n0,&n1,&n);
    int gap,min1=n,min2=1,found=0;
    for(int i=1;i<n;i++){
        if((n0%i!=0)||(n1%(n-i)!=0)){continue;}
        else if((n0/i==1)||(n1/(n-i)==1)){continue;}
        else{
            found++;
            if((n0/i)>(n1/(n-i))){gap=(n0/i)-(n1/(n-i));}
            else{gap=((n1/(n-i))-(n0/i));}
            //printf("%d %d %d %d %d\n",n0/i,i,n1/(n-i),n-i,gap);
            if(gap<=min1){
                min1=gap;
                min2=i;
            }
            else{continue;}
        }
    }
    if(found==0){printf("No Solution");}
    else{printf("%d %d",min2,n-min2);}
    return 0;
}