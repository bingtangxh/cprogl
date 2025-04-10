#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	scanf("%d",&N);
    N++;
	char string[80],maxstring[80];
	int length=0,maxlength=0;
	for (int i=0;i<N;i++)
	{
		gets(string);
		length=strlen(string);
		if (length>maxlength)
		{
			maxlength=length;
			strcpy(maxstring,string);
		}
	}
	printf("The longest is: %s",maxstring);
	return 0;
}
