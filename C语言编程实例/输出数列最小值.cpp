#include<stdio.h>
int main()
{
	int min,i,a[5];
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	min=a[0];
	for(i=1;i<5;i++)
	{
		if(a[i]<min)
		min=a[i];
	}
	printf("%d",min);
}
