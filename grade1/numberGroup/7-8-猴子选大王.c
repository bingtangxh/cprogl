#include<stdio.h>
#include<stdlib.h>
int main()
{   
   int temp,m[1000],N;
   scanf("%d",&N);
   for(int i1=0;i1<N;i1++)   
   {       
       m[i1]=i1+1;
   }   
   for(int i1=N-1;i1>=0;i1--)
   {       
     for(int i3=1;i3<=3;i3++)
        {           
          temp=m[0];           
        for(int i2=0;i2<i1;i2++)
           {               
              m[i2]=m[i2+1];           
           }           
           m[i1]=temp;   
        }   
    }   
    printf("%d",m[0]);   
    return 0;
}

int mian(){
    int N;
    scanf("%d",&N);
    int N1=N/3;
    N-=N1;
    N-=1;
    printf("%d",N);
    return 0;
}
