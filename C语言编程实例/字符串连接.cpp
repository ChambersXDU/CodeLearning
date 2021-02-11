#include<stdio.h>
#include<string.h>
char link(char a,char b); 
int main()
{
	char a[100],b[100];
	gets(a);
	gets(b);
	puts(link(a,b));
}
char link(char a,char b)
{
	char c[100];
	int i=0,j=0,len=strlen(a);
	while(a[i]!=0)
	{
		c[i]=a[i];
		i++;
	}
	while(b[j]!=0)
	{
		c[i]=b[j];	
		j++;
		i++;
	}	
	return c;
}


