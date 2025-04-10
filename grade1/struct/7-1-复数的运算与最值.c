#include<stdio.h>
#include<math.h>

int answer(int a,int b){
    if(b==0)printf("{%d}",a);
    else{
        if(a==0) printf("{%di}",b);
        else {
            if(b>0) printf("{%d+%di}",a,b);
            else printf("{%d%di}",a,b);
        }
    }
    printf("\n");
    return 0;
}

int main(){
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    answer(a,b);
    answer(c,d);
    int ar[4],ai[4];
    ar[0]=a+c,ai[0]=b+d,ar[1]=a-c,ai[1]=b-d,ar[2]=a*c-b*d,ai[2]=a*d+b*c,ar[3]=(a*c+b*d)/(pow(c,2)+pow(d,2)),ai[3]=(b*c-a*d)/(pow(c,2)+pow(d,2));
    answer(ar[0],ai[0]);
    answer(ar[1],ai[1]);
    answer(ar[2],ai[2]);
    answer(ar[3],ai[3]);
    int max_r=-32768;
    for(int i=0;i<4;i++){if(ar[i]>max_r)max_r=ar[i];}
    int equalMax=0;
    for(int i=0;i<4;i++){if(ar[i]==max_r)equalMax++;}
    if(equalMax==1){
        for(int i=0;i<4;i++){
            if(ar[i]==max_r)answer(ar[i],ai[i]);
            else i=i;}
    }
    else{
        int max_i=-32768;
            for(int i=0;i<4;i++){if(ar[i]==max_r&&ai[i]>max_i)max_i=ai[i];}
            for(int i=0;i<4;i++){if(ar[i]==max_r&&ai[i]==max_i)answer(ar[i],ai[i]);}
        }
}
