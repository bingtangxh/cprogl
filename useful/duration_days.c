#include<stdio.h>
#include<math.h>
#define mian main
int isLeapYear(int y){
    if(y%400==0||(y%4==0&&y%100!=0)) return 1;
    else return 0;
}

int duration(int y1,int m1,int d1,int y2,int m2,int d2){
    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int sum1=0;
    if(isLeapYear(y1)) days[2]=29;
    else days[2]=28;
    for(int i1=1;i1<m1;i1++){sum1+=days[i1];}
    sum1+=d1;
    //printf("%d\n",sum1);
    int sum2=0;
    if(isLeapYear(y2)) days[2]=29;
    else days[2]=28;
    for(int i2=1;i2<m2;i2++){sum2+=days[i2];}
    sum2+=d2;
    int sum3=0;
    if(y1<y2){for(int i3=y2;i3>y1;i3--){
        if(isLeapYear(i3-1)) sum3+=366;
        else sum3+=365;
    }}
    sum3+=sum2;
    sum3-=sum1;
    return sum3;
}

int mian(){
    while(1){
        int y,m,d;
        scanf("%d-%d-%d",&y,&m,&d);
        printf("%d\n",duration(1990,1,1,y,m,d));
        break;
    }
}