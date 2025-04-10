#include <stdio.h>
struct structure
{
    //如无说明，下面所有用短横线表示的区间都是闭区间，且从1开始数
    //每个就是4个字节
    int foo;//1494217276，占用的是第1个
    
    union
    {
        int integer;//1668048215 占用第3个，第二个应该用来记录union了,union占用4个
        char string[11];//{'W','e','l','c','o','m','e',' ','t','o',' ','X'}
        //实际上把显示的下标调大能接着出来后面的字母 占用3-6
        void *pointer;//64位系统上占用的是2个，因为union所有成员都从同一个地方开始，应该是第3-4个
    } node;
    short bar;//8236，这个只占用半个，第7个
    long long baz;//1869881445，占用8-9
    int array[7];//占用10-18，10是头节点的指针
    /*
    {1277195631,2020961897,1869760288,1528852597,
     858927154,2015690845,1668048215,1694330141}
    */
};
int main(void)
{
    int arr[] = {0x590ff23c, 0x2fbc5a4d, 0x636c6557, 0x20656d6f,
                 0x58206f74, 0x20545055, 0x6577202c, 0x6d6f636c,
                 0x6f742065, 0x79695820, 0x4c20756f, 0x78756e69,
                 0x6f724720, 0x5b207075, 0x33323032, 0x7825005d,
                 0x636c6557, 0x64fd6d1d};
    //每个元素是4个字节
    //for(int i=0;i<114;i++){printf("%c",arr[i]);}
    //printf("%p\n", ((struct structure *)arr)->node.pointer);
    putchar('\n');
    puts(((struct structure *)arr)->node.string);
    /*
    这两行效果一样。把arr的内存空间按一种名叫structure的结构体去分析，找到string字符数组并输出到\0为止。
    输出的字符串有54个字符
    数了数应该是在第16个元素的从右往左第2个字节那里停下了，而0x7825005d的从右往左第2个字节恰好就是00，也就是\0。
    你看你看，明年出题人再把0x33323032从左往右第2个3改成4，2023就成2024了，简单高效。
    */
    //printf("%d",printf("%s\n", ((struct structure *)arr)->node.string));
    //printf("%c",arr[]);
}
