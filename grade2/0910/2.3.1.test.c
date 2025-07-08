#include <stdio.h>
#include <conio.h>
typedef struct node{
    int factor;
    int index;
}Node;

int main(void)
{
    Node a;
    scanf("%d %d",&a.factor,&a.index);
    printf("%d %d",a.factor,a.index);
    _getch();
    return 0;
}