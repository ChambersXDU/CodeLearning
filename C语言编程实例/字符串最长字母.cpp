#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	gets(str);
	int max=0,i=0,count=0;
	
	while(str[i]!='.')
	{
		while(str[i]!=' ')
		{
			i++;
			count++;
		}
		if(count>max) max=count;
		count=0;
		i++;
	 } 
	printf("%d",max);
}


