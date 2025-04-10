#include <stdio.h>
#include <stdlib.h>
typedef int (*Predicate)(int);
//这里是指定Predicate是返回int的函数
int *filter(int *array,int length,Predicate predicate,int *resultLength)
{
    int* resultArray=(int*) malloc(sizeof(array)),destCount=0;
    /*
    这里用malloc在内存里开辟一个和原来array数组一样大的空间。
    因为resultlength已经可以表明转存了多少个数，
    而且最后main结束之前还要free一下呢，所以这里开辟的空间里没用上的可以继续空着。
    网上查了一下也可以用realloc重新调整resultArray指向空间的大小。
    上面这个语句里resultArray是指向整型的指针，而destCount只是整型不是指针。
    */
    for(int sourceCount=0;sourceCount<length;sourceCount++)
    {
        if(predicate(array[sourceCount]))
        {
            resultArray[destCount]=array[sourceCount];
            //printf("%d %d %d %d\n",sourceCount,destCount,array[sourceCount],resultArray[destCount]);
            destCount++;
        }
    }
    *resultLength=destCount;
    return resultArray;
}
int isPositive(int num) {return num>0;}
int main(void)
{
    int array[]={-3,-2,-1,0,1,2,3,4,5,6};
    int length=sizeof(array)/sizeof(array[0]);
    int resultLength;
    int *filteredNumbers=filter(array,length,isPositive,&resultLength);
    for (int i=0;i<resultLength;i++)
    {
        //printf("%d\n",i);
        printf("%d ",filteredNumbers[i]);}
    printf("\n");
    free(filteredNumbers);
    return 0;
}
