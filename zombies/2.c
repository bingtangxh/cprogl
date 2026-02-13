#include <stdio.h>
int main()
{
    wchar_t str[] = L"你是一个一个一个啊";
    printf("1. %lls\n", str);
    wprintf(L"2. %ls\n", str);
    printf("3. ");
    _putws(str);
    printf("4. %ls\n", str);
    return 0;
}