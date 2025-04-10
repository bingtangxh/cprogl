#include <stdio.h>
#define EXIT_SUCCESS 0
int main(int argc, char *argv[])
{
    printf("[%d]\n", argc);
    while (argc)
    {
        ++argc;
        //break;
    }
    int i = -1, j = argc, k = 1;
    i++ &&j++ || k++;
    printf("i = %d, j = %d, k = %d\n", i, j, k);
    return EXIT_SUCCESS;
    /*
    这个程序不确定是不是不完整，还是我不应该不用GNU/Linux跑这个。
    最后EXIT_SUCCESS没定义，编译不了，我把它用define定义成0然后跑。
    首先int argc的话argc>=1肯定是成立的，那么while(argc)这里
    argc最开始肯定是一个大于0的数，从而能进入循环，但是
    循环只是让argc递增，又没个break或者goto跳出去，显然会死循环。
    于是只执行输出argc的printf，永远都跑不到第二个printf。（不排除溢出又回到0的可能）
    */
}