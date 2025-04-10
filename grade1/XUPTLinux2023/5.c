#include <stdio.h>
int func(int a,int b)
{
    if (!a) return b;
    return func((a&b)<<1,a^b);
}
int main(void)
{
    int a=4,b=9,c=-7;
    printf("%d\n",func(a,func(b,c)));
}
/*
首先main函数中func(9,-7)
十进制  二进制补码
9       0000 1001
-7      1111 1001

18      0001 0010
-16     1111 0000

32      0001 0000
-30     1110 0010
脑子快炸了，什么时候形参a才能是0啊
*/