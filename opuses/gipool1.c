#include <conio.h>
#include "gipool.h"

int main()
{
    // SetConsoleOutputCP(CP_UTF8);
    // SetConsoleCP(CP_UTF8);

    initDynamicThings();
    for (int i=0;i<poolCount;i++){
        putPool(WishPool[i]);
    }
    for(int i=0;i<charCount;i++){
        if((1||daysPassedSinceLastUP[arrangedInOrderOfDays[i]])&&((CharMap[arrangedInOrderOfDays[i]].attrib==9)||(CharMap[arrangedInOrderOfDays[i]].attrib==5))){
            printf("%12s\t%d\n",localizedNames[arrangedInOrderOfDays[i]],daysPassedSinceLastUP[arrangedInOrderOfDays[i]]);
        } else {
            // printf("%12s\t%u\n",localizedNames[arrangedInOrderOfDays[i]],CharMap[arrangedInOrderOfDays[i]].attrib);
        }
    }
    putchar('\n');
    printf("Compiled at %s %s\n\n",__DATE__,__TIME__);
    freeDynamicThings();
    printf("Count of characters and pool info with errors: %d\n",checkIntegrity());
    putchar('\n');
    puts("Press any key to exit...");
#ifdef _MSC_VER
    _getch();
#else
    getch();
#endif
    return 0;
}