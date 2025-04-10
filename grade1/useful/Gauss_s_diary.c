#include<stdio.h> 
#include<math.h>
#define mian main
int isLeapYear(int year){
      if((year%4==0&&year%100!=0)||year%400==0){return 1;} 
      else{return 0;}
   } 
int mian() {
    int input;
    scanf("%d",&input);
    input++;
    int year=1777,month=4,day=30,t=0,d=day,i;
    int dayNumInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=month-1;t<=input;i++)
    { 
      if(i>=12)
      { 
            i=0; 
          year++; 
      } 
      if(isLeapYear(year)){dayNumInMonth[1]=29;}
      else{dayNumInMonth[1]=28;}
        d=input-t;
        t+=dayNumInMonth[i]; 
        month=i+1;
        //printf("%d/%d/%d\n",year,month,d+day);
    }
    printf("%d\n",i);
    if((d+day)>dayNumInMonth[i-1]){
        d-=dayNumInMonth[i];
        month++;
    }
    if(d+day==0){d+=dayNumInMonth[i-1];month--;}
    if(month==13){month=1;year++;}
    if(month==0){month=12;year--;}
    
    printf("%d/%d/%d\n",year,month,d+day);
    return 0; 
}