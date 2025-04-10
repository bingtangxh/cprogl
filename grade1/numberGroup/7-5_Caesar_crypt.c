#include <stdio.h>
#include <math.h>
int main(){
    //char a[80];
    unsigned char a[80];
    int x=0,y,offset;
    while((a[x]=getchar())!='\n'){x++;}
    scanf("%d",&offset);
    if(offset>0)
    {
        y=offset%26;
        for(int i1=0;i1<x;i1++){if(a[i1]>='A'&&a[i1]<='Z')
            {
                a[i1]+=y;
                if(a[i1]>'Z'){a[i1]-=26;}
            }
            else if(a[i1]>='a'&&a[i1]<='z')
            {
                a[i1]+=y;
                if(a[i1]>'z'){a[i1]-=26;}
            }
            printf("%c",a[i1]);
        }
    }
    else if(offset<0)
    {
        offset=fabs(offset);
        y=offset%26;
        for(int i2=0;i2<x;i2++)
        {
            if(a[i2]>='A'&&a[i2]<='Z')
            {
                a[i2]-=y;
                if(a[i2]<'A'){a[i2]+=26;}
            }
            else if(a[i2]>='a'&&a[i2]<='z')
            {
                a[i2]-=y;
                if(a[i2]<'a'){a[i2]+=26;}
            } 
            printf("%c",a[i2]);
        }
    }
    else{for(int i3=0;i3<x;i3++){printf("%c",a[i3]);}}
    return 0;
}