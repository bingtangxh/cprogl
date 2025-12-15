#include "chouka.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
char** localizedNames;
int charCount,poolCount,longestIndex;
int* daysPassedSinceLastUP,arrangedInOrderOfDays;
void printW(const wchar_t* wstr);
void putPool(Wish_Pool WishPool1);
int findLongest(Char_Map CharMap1[]);
int localizeNames(Char_Map CharMap1[],char* localizedNames[]);
void getDaysPassedSinceLastUp();
void arrangeByDaysPassedSinceLastUp();
int daysSincePoolEnds(const Wish_Pool* pool);
static time_t make_time_from_ymd(uint16_t y, uint8_t m, uint8_t d);


void printW(const wchar_t* wstr) {
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD written;
    WriteConsoleW(hConsole,wstr,(DWORD)wcslen(wstr),&written,NULL);
}

void putPool(Wish_Pool WishPool1)
{
    int fiveCount=sizeof(WishPool1.up5)==0?0:(int)(sizeof(WishPool1.up5)/sizeof(WishPool1.up5[0]));
    int fourCount=sizeof(WishPool1.up4)==0?0:(int)(sizeof(WishPool1.up4)/sizeof(WishPool1.up4[0]));
    printf("%hu.%hu.%hu\t%u.%hu.%hu\t%u.%hu.%hu\t",WishPool1.major,WishPool1.minor,WishPool1.half,WishPool1.startY,WishPool1.startM,WishPool1.startD,WishPool1.endY,WishPool1.endM,WishPool1.endD);
    for(int i=0;i<fiveCount&&WishPool1.up5[i]!=0;i++)
    {
        //printW(CharMap[WishPool1.up5[i]].name_cn);
        printf("%s ",localizedNames[WishPool1.up5[i]]);
    }
    for(int i=0;i<fourCount&&WishPool1.up4[i]!=0;i++)
    {
        //printW(CharMap[WishPool1.up4[i]].name_cn);
        printf("%s ",localizedNames[WishPool1.up4[i]]);
    }
    putchar('\n');
}

int findLongest(Char_Map CharMap1[]){
    size_t currentLen=0,maxLen=0;
    int maxIndex=-1;
    for(int i=0;i<charCount;i++){
        currentLen=wcslen(CharMap1[i].name_cn);
        if(currentLen>maxLen)
        {
            maxIndex=i;
            maxLen=currentLen;
        }
    }
    return maxIndex;
}

int localizeNames(Char_Map CharMap1[],char* localizedNames[]){
    int result=0;
    for(int i=0,conved=0;i<charCount;i++){
        int destSize=WideCharToMultiByte(CP_ACP,0,CharMap1[i].name_cn,-1,NULL,0,NULL,NULL);
        localizedNames[i]=(char*)malloc(sizeof(char)*(destSize+0));
        conved=WideCharToMultiByte(CP_ACP,0,CharMap1[i].name_cn,-1,localizedNames[i],destSize,NULL,NULL);
        if(conved==0) result=1;
    }
    return result;
}

void getDaysPassedSinceLastUp(){
    daysPassedSinceLastUP=(int*)malloc(sizeof(int)*charCount);
    for (int c=0;c<charCount;c++)
    {
        int lastPoolIndex=-1;
        // 从后往前找，最近一次包含该角色的池
        for(int p=poolCount-1;p>=0;p--)
        {
            for(int i=0;i<24&&(CharMap[c].attrib==4?WishPool[p].up4[i]:WishPool[p].up5[i])!=0;i++)
            {
                if((CharMap[c].attrib==4?WishPool[p].up4[i]:WishPool[p].up5[i])==CharMap[c].id)
                {
                    lastPoolIndex=p;
                    goto FOUND;
                }
            }
        }
    FOUND:
        if (lastPoolIndex>=0)daysPassedSinceLastUP[c]=daysSincePoolEnds(&WishPool[lastPoolIndex]);
        // 从未 UP 过（常驻 / 联动 / 特殊）
        else daysPassedSinceLastUP[c]=-1;
    }
}

time_t makeTimeFromYMD(uint16_t y,uint8_t m,uint8_t d){
    struct tm t={0};
    t.tm_year = y-1900;
    t.tm_mon  = m-1;
    t.tm_mday = d;
    t.tm_hour = 0;
    t.tm_min  = 0;
    t.tm_sec  = 0;
    // 此处暂时硬编码一个 00:00:00 ，以后再看要不要细化到时间
    t.tm_isdst=-1;
    return mktime(&t);
}

int daysSincePoolEnds(const Wish_Pool* pool)
{
    time_t now=time(NULL);
    time_t end=makeTimeFromYMD(pool->endY,pool->endM,pool->endD);
    double diff=difftime(now,end);
    return (int)(diff/86400);
}

void arrangeByDaysPassedSinceLastUp(){

}