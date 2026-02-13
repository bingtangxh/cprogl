#include <stdio.h>
int main()
{
    int i;
    char words[10];
    while (fgets(words, 10, stdin) != NULL && words[0] != '\n')
    {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0')
        {
            i++;
        }
        words[i] = '\0';
        puts(words);
    }
    puts("Done.");
    return 0;
}