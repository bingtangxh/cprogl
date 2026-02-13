#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mian main
int main()
{
    int elementsFound, choice;
    while ((elementsFound = scanf("%d", &choice)) != 1 ||
           (choice < 1 || choice > 5))
    {
        if (elementsFound != 1)
        {
            scanf("%*s");
        }
        puts("Incorrect Input!");
    }
    switch (choice)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        puts("Correctly!");
        break;

    default:
        break;
    }
    return 0;
}