#include<stdio.h>
#include<string.h>
int main()
{
    int N,M,count=0;
    char str1[600],str2[600];
    scanf("%d %d",&N,&M); 
    getchar();
    for(int i=1;i<=N;i++)
    {
        gets(str1);
        if(strstr(str1,"qiaNdao")==NULL&&strstr(str1,"easy")==NULL)
        {
            count++;
            if(count>M){strcpy(str2,str1);}
        }
    } 
    if(count>M){printf("%s",str2);}
    else{printf("Wo AK le");}
    return 0;
}
