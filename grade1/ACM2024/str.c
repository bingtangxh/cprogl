#include <stdio.h>
#include <string.h>

void eraseLFTail(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n' && str[i + 1] == '\0')
            str[i] = '\0';
    }
}

int main()
{
    char str1[1001],str2[1001];
    puts("请输入 str2 ，回车键结束，最多 1000 个 ASCII 字符：");
    fgets(str2,1000,stdin);
    eraseLFTail(str2);
    strncpy_s(str1,1001,str2,1000);
    puts("复制后的 str1 为：");
    puts(str1);
    return 0;
}