#include <stdio.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS 1

void choice_sort(int array[],int length,int mode){
    
    for(int current1=0,current2=0,extreme,extremePosition;current1<length;current1++){
        for(current2=current1+1;current2<=length;current2++){
            extremePosition=current1;
            if(((mode==1)&&(array[current2]<array[extremePosition]))||((mode==2)&&(array[current2]>array[extremePosition]))){
                extremePosition=current2;
            }
            if(current1!=extremePosition){
                array[current1]+=array[extremePosition];
                array[extremePosition]=array[current1]-array[extremePosition];
                array[current1]-=array[extremePosition];
            }
        }
    }
}

int main(void){
    int array[]={33,453,232,5343,21321,45,21,54,2424,645};
    int length=sizeof(array)/sizeof(int);
    int mode=getche();
    putchar('\n');
    mode-=48;
    choice_sort(array,length,mode);
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    getch();
    return 0;
}