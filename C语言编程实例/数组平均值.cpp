#include<stdio.h>
int main()
{
	int i,n,sum=0,a[100];
	float x;
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
    sum=sum+a[i];
	}	
	x=sum/n;
	printf("%.2f",x);
	
}	


