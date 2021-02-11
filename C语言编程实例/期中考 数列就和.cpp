#include<stdio.h>
int main()
{
	int n,i;
	double sum;
	scanf("%d",&n);
	sum=1;
	for(i=1;i<=n;i++)
	{
	
		sum=sum+2*(i-1)/(i+1.0);
	}
	printf("%.2f",sum);
 } 
