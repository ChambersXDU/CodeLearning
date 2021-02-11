#include<stdio.h>
#include<string.h>
int main()
{
	char string[255]={'\0'},str[100][100]={'\0'},temp[100]={'\0'};
	int i,j=0,n=0,e;
	gets(string);
	for(i=0;string[i]!='\0'||(i!=0&&string[i-1]!='\0');i++)
	{
		if(string[i]=='-')
		{
			for(i,j,e=0;string[i]!=' '&&string[i]!='\0';i++,e++)
				str[j][e]=string[i];
			j++;
		}
	}
	n=j;
	if(n==0)
		printf("no\n");
	else
		for(i=0;i<n-1;i++)
			for(j=0;j<n-1-i;j++)
				if(strcmp(str[j],str[j+1])>0)
				{
					strcpy(temp,str[j]);
					strcpy(str[j],str[j+1]);
					strcpy(str[j+1],temp);
				}
		for(j=0;j<n;j++)
			if(j==0||strcmp(str[j],str[j-1])!=0)
				printf("%s ",str[j]);
	return 0;
}

