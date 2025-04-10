#include <stdio.h>
#define CAL(a) a * a * a
#define MAGIC_CAL(a, b) CAL(a) + CAL(b)
int main(void)
{
    int nums=1;
    if(16/CAL(2)==2){printf("I'm TWO,Shaking hands\n");}
    else
    {
        int nums=MAGIC_CAL(++nums,2);
        //printf("%d\n",nums);
    }
    printf("%d\n",nums);
}
/*
define只是简单粗暴的替换，所以if的条件语句里16/CAL(2)应该就是：
16/2*2*2
而不是
16/(2*2*2)
要让if的条件成立，应该把宏定义改成下面
#define CAL(a) (a * a * a)
话题回到给好的代码本身，if的条件语句实际上是32==2，不是2==2，所以不执行if复合语句里的printf。
然后else的语句里
MAGIC_CAL(++nums,2)
应该是CAL(++nums)+CAL(2)
++nums*++nums*++nums+2*2*2
我试着把三个++nums的递增运算符删掉一个，发现前两个nums的值总是相等的。
开头已经定义了int nums=1，那么
++nums*nums*++nums==12
nums*++nums*++nums==12
++nums*++nums*nums==27
++nums*++nums*++nums==36
都成立
但是else语句里重新定义了一个nums，那么else里对nums值的改动在离开复合语句之后就失效了
最后printf出来nums还是1。
我试了下把else里的int nums改成int nums1，然后最后printf出来nums就是4了。
但是我还试了在else里把int nums1改回去，
然后printf一下nums，发现值似乎未定义，每次运行输出的都是不同的很大的负整数。
*/