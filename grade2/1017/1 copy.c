#include <stdio.h>
#define MAXSIZE 15

int max(int a,int b) {return a>b?a:b;}

int main()
{
    short int square1[MAXSIZE][MAXSIZE]={0},square2[MAXSIZE][MAXSIZE]={0},value_current;
    unsigned short int a1,b1,a2,b2,a_max,b_max,len,a_current,b_current,a_maxr=0,b_maxr=0,slen_current;
    char result[1145],*result_current;
    result_current=result;
    scanf("%hu %hu %hd\n",&a1,&b1,&len);
    for(int i=0;i<len;i++)
    {
        getchar();
        scanf("%hu,%hu,%hd",&a_current,&b_current,&value_current);
        getchar();
        square1[a_current][b_current]=value_current;
    }
    scanf("%hu %hu %hd\n",&a2,&b2,&len);
    for(int i=0;i<len;i++)
    {
        getchar();
        scanf("%hu,%hu,%hd",&a_current,&b_current,&value_current);
        getchar();
        square2[a_current][b_current]=value_current;
    }
    a_max=max(a1,a2);
    b_max=max(b1,b2);
    len=0;
    for(int ia=0;ia<=a_max;ia++)
    {
        for(int ib=0;ib<=b_max;ib++)
        {
            square1[ia][ib]+=square2[ia][ib];
            if(square1[ia][ib]!=0)
            {
                len++;
                if(a_maxr<ia) a_maxr=ia;
                if(b_maxr<ib) b_maxr=ib;
                slen_current=sprintf(result_current,"(%hu,%hu,%hd)",ia,ib,square1[ia][ib]);
                result_current+=slen_current;
            }
        }
    }
    printf("%hu %hu %hd\n",a_max,b_max,len);
    for(int ia=0;ia<=a_max;ia++)
    {
        for(int ib=0;ib<=b_max;ib++)
        {
            if(square1[ia][ib]!=0)
            {
                printf("(%hu,%hu,%hd)",ia,ib,square1[ia][ib]);
            }
        }
    }
    putchar('\n');
    result_current=result;
    a_maxr=0,b_maxr=0,len=0;
    for(int ia=0;ia<=a_max;ia++)
    {
        for(int ib=0;ib<=b_max;ib++)
        {
            square1[ia][ib]-=square2[ia][ib]*2;
            if(square1[ia][ib]!=0)
            {
                len++;
                if(a_maxr<ia) a_maxr=ia;
                if(b_maxr<ib) b_maxr=ib;
                slen_current=sprintf(result_current,"(%hu,%hu,%hd)",ia,ib,square1[ia][ib]);
                result_current+=slen_current;
            }
        }
    }
    printf("%hu %hu %hd\n",a_max,b_max,len);
    for(int ia=0;ia<=a_max;ia++)
    {
        for(int ib=0;ib<=b_max;ib++)
        {
            if(square1[ia][ib]!=0)
            {
                printf("(%hu,%hu,%hd)",ia,ib,square1[ia][ib]);
            }
        }
    }
    putchar('\n');
    return 0;
}