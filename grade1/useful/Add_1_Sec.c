#include<stdio.h>
#include<math.h>
#define mian main
int mian(){
    int h,m,s;
    scanf("%d:%d:%d",&h,&m,&s);
    s++;
    if(s==60) m++,s=0;
    if(m==60) h++,m=0;
    if(h==24) h=0;
    if(h<10) printf("0");
    printf("%d:",h);
    if(m<10) printf("0");
    printf("%d:",m);
    if(s<10) printf("0");
    printf("%d",s);
    return 0;
}