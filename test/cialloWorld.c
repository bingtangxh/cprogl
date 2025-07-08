#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996) //让它不要警告我们改用难用的scanf_s

int find2Max (int array[], int length, int * max, int * submax)
{
    *max=-2147483648,*submax=-2147483648;
    for(int i=0;i<length;i++)
    {
        if (*max<array[i])
        {
            *max=array[i];
        }
    }
    for(int i=0;i<length;i++)
    {
        if (*submax<array[i]&&array[i]!=*max)
        {
            *submax=array[i];
        }
    }
    return 0;
}

int main()
{
    char arr[] = { 'o','n','a','n','i','i','\0' };
    char arrr[] = { "onanii" };
    int array[5]={0};
    printf("%s\n",arr);
    printf("%s\n", arrr);
    printf("\\\\0\n");
    printf("%d\n", 0x2^12);
    int a = 0;
    scanf("%d", &a);
    if (a == 721)
    {
        printf("您真是0721高手");
    }
    else if (a == 6)
    {
        printf("您比0721高手还糕手");
    }
    
    if(114==514) return 1;

    if(strcmp("Ciallo~","ciallo!"))
    {
        putchar('\n');
        return 2;
    }

    
    return 0;
}


