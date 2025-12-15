#include <conio.h>
#include "gipool.h"

int main()
{
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);
    charCount=sizeof(CharMap)==0?0:(int)(sizeof(CharMap)/sizeof(CharMap[0]));
    poolCount=sizeof(WishPool)==0?0:(int)(sizeof(WishPool)/sizeof(WishPool[0]));
    localizedNames=(char**)malloc(charCount*sizeof(char*));
    longestIndex=findLongest(CharMap);
    localizeNames(CharMap,localizedNames);
    getDaysPassedSinceLastUp();
    for (int i=0;i<poolCount;i++){
        putPool(WishPool[i]);
    }
    for(int i=0;i<charCount;i++){
        if(daysPassedSinceLastUP[i]>0){
            printf("%12s\t%d\n",localizedNames[i],daysPassedSinceLastUP[i]);
        }
    }
    putchar('\n');
    printf("Compiled at %s %s\n",__DATE__,__TIME__);
    _getch();
    return 0;
}