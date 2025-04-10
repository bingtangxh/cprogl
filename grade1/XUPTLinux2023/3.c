#include <stdio.h>
#include <string.h>
int main(void)
{
    char arr[]={'L','i','n','u','x','\0','!'},str[20];
    short num=520;
    int num2=1314;
    printf("%zu\t%zu\t%zu\n",
        sizeof(*&arr),
        sizeof(arr+0),
        sizeof(num=num2+4)
    );
           /*
           %zu其中u是没符号的十进制整数，z网上没查到，是解除长度限制？
           \t就是水平制表符。
           上面的*&arr就是arr数组名。
           在char定义的时候输入了7个字符，所以字符数组arr的长度就是7，那个\0转义字符不重要。
           剩下两个sizeof看不出来，那个arr+0我试了把0改成多少结果都是8，num2+4的4改成多少都是2
           */
    printf("%d\n",sprintf(str,"0x%x",num)==num);
    /*
    sprintf和printf差不多一样，但是开头多一个字符数组名的参数，把打印的内容写到字符数组里，再加一个\0。
    返回值就是打印了多少个字符呗。
    经试探，上面num是520，转换成hex就是0x208，那么sprintf函数的返回值就是5
    5==520值当然是0了，所以上一行会输出0
    */
    printf("%zu\t%zu\n",strlen(&str[0]+1),strlen(arr+0));
    /*
    上面第一个strlen应该就是从给的地址开始往后找\0，&str[0]和直接写str是一样的效果。
    把+1改成0，那么值会由4变成5。
    上面第二个strlen，我试了改那个0，值越大，输出的5就会减小，再大会出错。
    */
   int a=114514;
   int* p=&a;
   int** p2=&p;
   printf("%d %d %d %d %d %d %d %d\n",p,(p+10),sizeof(p),sizeof(p+10),*p,*p+1,*p2,**p2);
}