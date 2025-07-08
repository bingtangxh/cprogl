#include <Windows.h>
#include <conio.h>
#include <stdio.h>

int main(){
    int i,j=1;
    while(1)
    {
        printf("%d",i=ShellExecute(0,"print",stdin,0,0,1));
        

    }
    
    return 0;
}