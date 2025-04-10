#include<stdio.h>
int bubble_sort(int array[],int length) {
    int i,j,temp;
    for(i=0;i<length-1;i++)
        for(j=0;j<length-1-i;j++)
            if(array[j]<array[j+1]) {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
}
int main() {
    int n,n1;
    scanf("%d",&n);
    int array[114514];
    for(n1=0;n1<n;n1++) scanf("%d,",&array[n1]);
    //int length=(int) sizeof(array)/sizeof(*array);
    int length=n;
    printf("%d\n",length);
    bubble_sort(array,length);
    int i;
    for(i=0;i<n;i++) {
        printf("%d",array[i]);
        if(i!=n-1) printf(",");
    }
    return 0;
}