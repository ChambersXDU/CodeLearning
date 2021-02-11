#include<stdio.h>
int main()
{
	int n,i,a[30];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		a[i]=n*n-n+1+2*i;
		printf("%d ",a[i]);
	}
	
 } 
