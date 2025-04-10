#include<stdio.h>
#include<string.h>
int main()
{
    char str[1005];
    int count=0,i1,i2;
    gets(str);
    for (i1=0;i1<=strlen(str);i1++)
    {
        if (str[i1]=='6'){count++;}
        else
        {
            if(count>9){printf("27");}
            else if(count>3){printf("9");}
            else for(i2=0;i2<count;i2++){printf("6");}
            printf("%c",str[i1]);
            count=0;
        }
    }
    return 0;
}
