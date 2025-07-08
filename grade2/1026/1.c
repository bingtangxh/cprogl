#include <stdio.h>
#include <string.h>

int repl(char *str,char find,char repl)
{
    int amountReplaced=0;
    for (int i=0;i<strlen(str);i++)
    {
        if(*(str+i)==find)
        {
            *(str+i)=repl;
            amountReplaced++;
        }
        else continue;
    }
    return amountReplaced;
    /*返回的是成功替换的个数*/
}

int remv(char *str,char find)
{
    char temp[114514];
    int amountRemoved=0;
    if(strlen(str)>114514) return -1;
    /*最多容纳114514个字符，否则返回-1表示字符串过长*/
    else
    {
        strncpy(temp,str,114514);
        for(int is=0,id=0;is<strlen(temp);is++)
        {
            if(temp[is]!=find)
            {
                *(str+id)=temp[is];
                id++;
            }
            else
            {
                continue;
                amountRemoved++;
            }
        }
        return amountRemoved;
    }
}

int findLocation(char *str,int index)
{
    for(int i=index+1;i<strlen(str);i++)
    {
        if(*(str+i)==*(str+index)) return i;
        else continue;
    }
    return -1;
    /*找不到就返回-1*/
}

int StrReplace(char *S,char *T,char *V)
{
    char target[114514];
    int amountReplaced=0;
    for(int is=0,id=0;is<strlen(S);is++)
    {
        if(*(S+is)!=*T||strstr(S+is,T)-S!=is)
        {
            if(strlen(target)>=114513) return -1;
            else 
            {
                target[id]=*(S+is);
                id++;
                continue;
            }
        }
        else /*警撅*/
        {
            amountReplaced++;
            strncat(target,V,114514);
            id+=strlen(V);
            is+=strlen(T)-1;
            continue;
        }
    }
    strncpy(S,target,114514);
    return amountReplaced;
}